#!/usr/bin/env python3
"""dual-compiler regression harness.

For every ``src/cod/*.c`` translation unit, compile twice — once with
the default compiler (``cygnus-2.96``) and once with the SN opt-in
(``sn-2.95.3-136``) — and report per-section byte-match against the
canonical ``expected/build/<rel>.o`` reference.

Exit semantics
--------------
* The **default-compiler** path is the load-bearing back-compat
  contract: every section of every ``src/cod/*.c`` TU MUST
  byte-match the expected/build/ baseline.  Any mismatch fails the
  check.
* The **sn-2.95.3-136** path is informational: it surfaces today's
  per-section diffs without blocking.  Trampoline TUs in particular
  are expected to drift; once TU migration starts the
  per-section table here will be the empirical record of what
  changes.

Output
------
Per TU, the harness prints a 1-line summary

    cyg: OK (N/N sections)    sn: WORKING (K/N sections)
        ^- "OK" only when every section is byte-equal.
                                          ^- "WORKING" when at least
                                             one section matches; per-
                                             section table also dumped
                                             in -v mode.

Final exit code:
    0  default-compiler path clean (SN may have misses)
    1  default-compiler path drifted on at least one section
    2  setup error (missing tools, missing expected/build, etc.)
"""

from __future__ import annotations

import argparse
import concurrent.futures
import hashlib
import os
import struct
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))

import compile as cpy  # noqa: E402

EXPECTED_ROOT = ROOT / "expected" / "build"
COMPILERS = ("cygnus-2.96", "sn-2.95.3-136", "ee-2.9-991111")


# --------------------------------------------------------------------------- #
# ELF32-LE section reader
# --------------------------------------------------------------------------- #
SHT_NULL = 0
SHT_NOBITS = 8


@dataclass(frozen=True)
class Section:
    name: str
    sh_type: int
    sh_size: int
    sh_off: int


def _read_sections(obj: Path) -> tuple[bytes, list[Section]]:
    """Return (raw file bytes, list of Section)."""
    data = obj.read_bytes()
    if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 1:
        raise SystemExit(f"{obj}: not an ELF32-LE file")
    e_shoff, = struct.unpack_from("<I", data, 0x20)
    e_shentsize, = struct.unpack_from("<H", data, 0x2e)
    e_shnum, = struct.unpack_from("<H", data, 0x30)
    e_shstrndx, = struct.unpack_from("<H", data, 0x32)
    sh = data[e_shoff + e_shstrndx * e_shentsize:][:e_shentsize]
    _, _, _, _, str_off, str_size, *_ = struct.unpack_from("<IIIIIIIIII", sh, 0)
    shstr = data[str_off:str_off + str_size]

    def _name(idx: int) -> str:
        end = shstr.index(b"\x00", idx)
        return shstr[idx:end].decode("ascii", errors="replace")

    out: list[Section] = []
    for i in range(e_shnum):
        h = data[e_shoff + i * e_shentsize:][:e_shentsize]
        (sh_name, sh_type, _sh_flags, _sh_addr,
         sh_off, sh_size, *_) = struct.unpack_from("<IIIIIIIIII", h, 0)
        out.append(Section(
            name=_name(sh_name),
            sh_type=sh_type,
            sh_size=sh_size,
            sh_off=sh_off,
        ))
    return data, out


# Sections whose bytes are intentionally not part of the byte-equality
# contract.  Section header bookkeeping (.symtab/.strtab/.shstrtab) is
# checked structurally via per-section bytes already; we exclude them
# here only to keep the report focused on the bytes that affect link
# output.  ``.mdebug`` carries debug-info offsets that depend on
# filesystem ordering / scratch paths (the well-known floating-point
# reproducibility caveat) so it's surfaced as
# informational rather than a hard miss.
DEFAULT_INTEREST = {"text_data_rel"}  # see SECTION_KIND


def _classify(sec: Section) -> str:
    n = sec.name
    if n.startswith(".text"):
        return "text"
    if n.startswith(".rel.text"):
        return "rel.text"
    if n.startswith(".rodata") or n.startswith(".sdata") or n == ".data":
        return "data"
    if n.startswith(".rel.data") or n.startswith(".rel.rodata"):
        return "rel.data"
    if n == ".bss" or n == ".sbss":
        return "bss"
    if n == ".mdebug" or n == ".mdebug.eabi64":
        return "mdebug"
    if n in (".symtab", ".strtab", ".shstrtab"):
        return "symtab"
    if n == ".reginfo":
        return "reginfo"
    return "other"


# Sections whose byte-equality is part of the back-compat contract.
CONTRACT_KINDS = {"text", "rel.text", "data", "rel.data", "bss",
                  "reginfo", "other"}


def _section_bytes(data: bytes, sec: Section) -> bytes:
    if sec.sh_type == SHT_NULL:
        return b""
    if sec.sh_type == SHT_NOBITS:
        return b""  # NOBITS sections have no file bytes
    return data[sec.sh_off:sec.sh_off + sec.sh_size]


def _compare_sections(
    expected_obj: Path,
    actual_obj: Path,
) -> list[tuple[str, str, str]]:
    """Return list of (section_name, kind, status) tuples.

    status ∈ {"OK", "MISS", "MISSING", "EXTRA"}.
    Order follows expected's section header order; sections present in
    actual but not in expected are appended as "EXTRA".
    """
    exp_data, exp_secs = _read_sections(expected_obj)
    act_data, act_secs = _read_sections(actual_obj)
    by_name_act = {s.name: s for s in act_secs}
    rows: list[tuple[str, str, str]] = []
    for s in exp_secs:
        if s.sh_type == SHT_NULL:
            continue
        kind = _classify(s)
        exp_bytes = _section_bytes(exp_data, s)
        if s.name not in by_name_act:
            # NOBITS sections may legitimately be absent on either side;
            # treat size-0 NOBITS as silently equivalent.
            if s.sh_type == SHT_NOBITS and s.sh_size == 0:
                rows.append((s.name, kind, "OK"))
            else:
                rows.append((s.name, kind, "MISSING"))
            continue
        a = by_name_act[s.name]
        if s.sh_type == SHT_NOBITS:
            status = "OK" if s.sh_size == a.sh_size else "MISS"
        else:
            act_bytes = _section_bytes(act_data, a)
            status = "OK" if exp_bytes == act_bytes else "MISS"
        rows.append((s.name, kind, status))
    exp_names = {s.name for s in exp_secs}
    for s in act_secs:
        if s.sh_type == SHT_NULL or s.name in exp_names:
            continue
        rows.append((s.name, _classify(s), "EXTRA"))
    return rows


def _summarise(rows: list[tuple[str, str, str]]) -> tuple[int, int, int, int]:
    """Return (contract_ok, contract_total, info_ok, info_total)."""
    co = ct = io = it = 0
    for name, kind, status in rows:
        if kind in CONTRACT_KINDS:
            ct += 1
            if status == "OK":
                co += 1
        else:
            it += 1
            if status == "OK":
                io += 1
    return co, ct, io, it


# --------------------------------------------------------------------------- #
# Compile-once helper
# --------------------------------------------------------------------------- #
def _compile_one(
    src: Path,
    compiler: str,
    out_obj: Path,
    cfg: cpy.Config,
    log: cpy.Logger,
) -> None:
    rel = src.relative_to(ROOT)
    # Honour per-TU c_flags_drop (the func_00359218 near-miss)
    # so the regress harness compiles each TU with the same flags the
    # main build path uses; otherwise TUs that need a flag-drop to match
    # retail will spuriously FAIL the contract gate here.
    entry = cfg.compile_units.get(str(rel), {})
    c_flags_drop = tuple(entry.get("c_flags_drop", ()))
    unit = cpy.CompileUnit(
        src=src,
        obj=out_obj,
        kind="c",
        rel=rel,
        compiler=compiler,
        c_flags_drop=c_flags_drop,
        # Honour per-TU c_flags_add (the -fno-gcse class) for the same reason:
        # a TU that only matches retail with the flag added would recompile
        # here without it and spuriously report gate drift.
        c_flags_add=tuple(entry.get("c_flags_add", ())),
        strip_cxx_frame=bool(entry.get("strip_cxx_frame", False)),
        strip_eh_table=bool(entry.get("strip_eh_table", False)),
        # Honour extern_jtbl the same way (the jump-table dispatcher class):
        # without it the harness would link the TU's own emitted table and
        # spuriously report gate drift vs the expected baseline.
        extern_jtbl=tuple(entry.get("extern_jtbl", ())),
        # Honour extern_double the same way (the double-math constant class):
        # without it the harness would relink the TU's own li.d .rodata copy
        # and spuriously report gate drift vs the expected baseline.
        extern_double=tuple(entry.get("extern_double", ())),
        # Honour the per-TU assembler route (as == 'gnu'): the gate compile
        # must go through the SAME stage-3 assembler as the real build, or a
        # gnu-as-routed TU (func_00348938) would recompile via ee-as and
        # spuriously MISS the expected baseline. notes/95 #11.
        assembler=entry.get("as", "ee"),
        # Honour fp_hazard_nops (the mtc1->cvt / cvt->div FP hazard class,
        # func_00184A40): without it the harness would compile the TU missing
        # the retail FP hazard nops and spuriously report gate drift.
        fp_hazard_nops=bool(entry.get("fp_hazard_nops", False)),
        # Honour the rule-set sibling key the same way: a TU that names a rule
        # set compiles with a different nop count, so a harness that ignored
        # the key would report false gate drift on it.
        fp_hazard_rules=entry.get("fp_hazard_rules"),
        # Honour call_loop_pad (the R5900 call-loop errata-pad class): without
        # it the harness would compile the TU missing retail's short-loop pads
        # and spuriously report gate drift vs the expected baseline.
        call_loop_pad=bool(entry.get("call_loop_pad", False)),
    )
    out_obj.parent.mkdir(parents=True, exist_ok=True)
    cpy._cc(unit, cfg, log)


import contextlib


@contextlib.contextmanager
def _suppress_fd(fd: int):
    """Redirect a fd to /dev/null for the duration of the with-block.
    Used to quiet cpp0/cc1 stderr noise that the wrapper passes through.

    `run(capture=False)` leaves the compiler's stderr inherited, so silencing
    it means dup2()ing the process-global fd — which is why this wraps the
    whole sweep once instead of each compile: a per-compile dup2 would race
    across the worker threads."""
    saved = os.dup(fd)
    devnull = os.open(os.devnull, os.O_WRONLY)
    try:
        os.dup2(devnull, fd)
        yield
    finally:
        os.dup2(saved, fd)
        os.close(saved)
        os.close(devnull)


def _ensure_carve(cfg: cpy.Config, log: cpy.Logger) -> None:
    """Carved .s files under build/asm/nonmatching/ must exist for the
    C TUs to compile (INCLUDE_ASM expands to .include "nonmatching/<n>.s").
    Idempotent — maybe_carve only rewrites when stale."""
    cpy.maybe_carve(cfg, log)


# --------------------------------------------------------------------------- #
# Per-TU runner
# --------------------------------------------------------------------------- #
@dataclass
class TUReport:
    rel: Path
    rows_by_compiler: dict[str, list[tuple[str, str, str]] | None]
    errors_by_compiler: dict[str, str | None]


def _run_tu(
    src: Path,
    cfg: cpy.Config,
    log: cpy.Logger,
    scratch: Path,
) -> TUReport:
    rel = src.relative_to(ROOT)
    expected = EXPECTED_ROOT / rel.with_suffix(".o")
    if not expected.exists():
        raise SystemExit(f"missing expected baseline: {expected}")
    rows_by_compiler: dict[str, list[tuple[str, str, str]] | None] = {}
    errors_by_compiler: dict[str, str | None] = {}
    for compiler in COMPILERS:
        out_obj = scratch / compiler / rel.with_suffix(".o")
        try:
            _compile_one(src, compiler, out_obj, cfg, log)
        except cpy.BuildError as exc:
            # Don't let a single compiler's TU-level failure abort the
            # whole sweep — surface it per-TU per-compiler.  Cygnus
            # failures still fail the harness at exit time; SN failures
            # are informational (some TUs are known to use idioms SN
            # 2.95 doesn't support, e.g. wide-integer arithmetic).
            rows_by_compiler[compiler] = None
            # Trim to the last 200 chars of the BuildError message.
            errors_by_compiler[compiler] = str(exc).split(":", 1)[0]
            continue
        rows_by_compiler[compiler] = _compare_sections(expected, out_obj)
        errors_by_compiler[compiler] = None
    return TUReport(
        rel=rel,
        rows_by_compiler=rows_by_compiler,
        errors_by_compiler=errors_by_compiler,
    )


# --------------------------------------------------------------------------- #
# Reporting
# --------------------------------------------------------------------------- #
def _tu_verdict(rows: list[tuple[str, str, str]] | None) -> str:
    if rows is None:
        return "FAIL"
    co, ct, io, it = _summarise(rows)
    if co == ct:
        return "OK"
    if co > 0:
        return "WORKING"
    return "MISS"


def _print_section_table(
    rep: TUReport,
    stream,
) -> None:
    """Dump per-section status side-by-side for the two compilers."""
    cyg_rows = rep.rows_by_compiler["cygnus-2.96"] or []
    sn_rows = rep.rows_by_compiler["sn-2.95.3-136"] or []
    cyg = {r[0]: r for r in cyg_rows}
    sn = {r[0]: r for r in sn_rows}
    names = list(dict.fromkeys(
        [r[0] for r in cyg_rows]
        + [r[0] for r in sn_rows]
    ))
    print(f"    {'section':50s}  {'kind':10s}  {'cyg':6s}  {'sn':6s}",
          file=stream)
    for n in names:
        c = cyg.get(n, (n, "-", "-"))
        s = sn.get(n, (n, "-", "-"))
        kind = c[1] if c[1] != "-" else s[1]
        print(f"    {n:50s}  {kind:10s}  {c[2]:6s}  {s[2]:6s}",
              file=stream)


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument(
        "--config",
        default=str(ROOT / "compile_config.json"),
        help="compile_config.json to use (default: repo root)",
    )
    ap.add_argument(
        "-v", "--verbose",
        action="store_true",
        help="print full per-section table for every TU",
    )
    ap.add_argument(
        "--only",
        action="append",
        default=[],
        help="restrict to TUs whose path contains this substring "
             "(repeatable; default: every src/cod/*.c)",
    )
    ap.add_argument(
        "-j", "--jobs",
        type=int,
        default=max(1, (os.cpu_count() or 4) - 2),
        help="parallel compile workers (default: cpu_count - 2)",
    )
    args = ap.parse_args(argv)
    if args.jobs < 1:
        ap.error("--jobs must be >= 1")

    if not EXPECTED_ROOT.exists():
        sys.stderr.write(
            f"missing {EXPECTED_ROOT}; run `python compile.py --setup` first\n"
        )
        return 2

    cfg = cpy.Config.load(Path(args.config))
    log = cpy.Logger(verbose=False)
    _ensure_carve(cfg, log)

    sources = sorted((ROOT / "src" / "cod").glob("*.c"))
    if args.only:
        sources = [
            s for s in sources
            if any(o in str(s.relative_to(ROOT)) for o in args.only)
        ]
    if not sources:
        sys.stderr.write("no src/cod/*.c sources to check\n")
        return 2

    print(f"dual-compiler regression harness — {len(sources)} TU(s)")
    print(f"  compilers : {', '.join(COMPILERS)}")
    print(f"  baseline  : {EXPECTED_ROOT.relative_to(ROOT)}")
    print()

    # Per-TU effective compiler from compile_config.json::compile_units.
    # TUs without an override use the default (cygnus-2.96); TUs with an
    # override use the named compiler as their gate, and the other
    # compiler becomes informational.  (e.g. src/cod/sq_pilot.c opts
    # into sn-2.95.3-136 so SN is its load-bearing gate.)
    compile_units_map = cfg.compile_units

    def _gate_compiler_for(rel) -> str:
        # rel is a Path; compile_units is keyed by posix-style str.
        entry = compile_units_map.get(str(rel).replace("\\", "/"), {})
        return entry.get("compiler", cpy.DEFAULT_COMPILER)

    with tempfile.TemporaryDirectory(prefix="m8_03_dual_") as td:
        scratch = Path(td)
        any_default_miss = False

        # Compile every TU under both compilers in parallel.  _run_tu is pure
        # per-TU: it writes only scratch/<compiler>/<rel>.o (a path unique to
        # the TU) and reads expected/build/<rel>.o, so scheduling order cannot
        # change any byte the contract compares — .mdebug, the one section
        # whose content depends on filesystem ordering, is already excluded
        # from the gate (see DEFAULT_INTEREST).  Results are collected in
        # source order, so the report below is identical to the serial sweep's.
        with _suppress_fd(2):
            with concurrent.futures.ThreadPoolExecutor(
                max_workers=args.jobs
            ) as pool:
                reports: list[TUReport] = list(
                    pool.map(lambda s: _run_tu(s, cfg, log, scratch), sources)
                )

        for rep in reports:
            cyg_rows = rep.rows_by_compiler["cygnus-2.96"]
            sn_rows = rep.rows_by_compiler["sn-2.95.3-136"]
            cyg_co, cyg_ct, _, _ = _summarise(cyg_rows) if cyg_rows else (0, 0, 0, 0)
            sn_co, sn_ct, _, _ = _summarise(sn_rows) if sn_rows else (0, 0, 0, 0)
            cyg_verdict = _tu_verdict(cyg_rows)
            sn_verdict = _tu_verdict(sn_rows)
            gate_compiler = _gate_compiler_for(rep.rel)
            gate_verdict = _tu_verdict(rep.rows_by_compiler.get(gate_compiler))
            gate_tag = (
                ""
                if gate_compiler == "cygnus-2.96"
                else " [SN-gated]"
                if gate_compiler == "sn-2.95.3-136"
                else f" [{gate_compiler}-gated]"
            )
            marker = "✓" if gate_verdict == "OK" else "✗"
            print(f"{marker} {rep.rel}{gate_tag}")
            cyg_err = rep.errors_by_compiler["cygnus-2.96"]
            sn_err = rep.errors_by_compiler["sn-2.95.3-136"]
            cyg_str = (
                f"FAIL ({cyg_err})" if cyg_err
                else f"{cyg_verdict:7s} ({cyg_co}/{cyg_ct} contract)"
            )
            sn_str = (
                f"FAIL ({sn_err})" if sn_err
                else f"{sn_verdict:7s} ({sn_co}/{sn_ct} contract)"
            )
            print(f"    cyg: {cyg_str}    sn:  {sn_str}")
            if args.verbose or gate_verdict not in ("OK",):
                _print_section_table(rep, sys.stdout)
            if gate_verdict != "OK":
                any_default_miss = True

        print()
        cyg_ok = sum(
            1 for r in reports
            if _tu_verdict(r.rows_by_compiler["cygnus-2.96"]) == "OK"
        )
        sn_ok = sum(
            1 for r in reports
            if _tu_verdict(r.rows_by_compiler["sn-2.95.3-136"]) == "OK"
        )
        sn_working = sum(
            1 for r in reports
            if _tu_verdict(r.rows_by_compiler["sn-2.95.3-136"]) == "WORKING"
        )
        sn_fail = sum(
            1 for r in reports
            if _tu_verdict(r.rows_by_compiler["sn-2.95.3-136"]) == "FAIL"
        )
        sn_gated = [
            r for r in reports
            if _gate_compiler_for(r.rel) == "sn-2.95.3-136"
        ]
        print(f"SUMMARY: cyg OK={cyg_ok}/{len(reports)}, "
              f"sn OK={sn_ok}/{len(reports)} "
              f"(+{sn_working} WORKING, {sn_fail} FAIL)")
        if sn_gated:
            print(
                f"         {len(sn_gated)} SN-gated TU(s): "
                + ", ".join(str(r.rel) for r in sn_gated)
            )

    if any_default_miss:
        print("FAIL: gate compiler drifted from the expected/build/ "
              "baseline on at least one TU.  (For SN-gated TUs declared "
              "in compile_config.json::compile_units the gate compiler "
              "is sn-2.95.3-136; otherwise cygnus-2.96.)", file=sys.stderr)
        return 1
    print("PASS: every TU's gate compiler reproduces every section of "
          "the expected/build/ baseline (cygnus-2.96 for default TUs, "
          "sn-2.95.3-136 for any TU in compile_config.json::compile_units); "
          "non-gate per-section deltas reported above.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
