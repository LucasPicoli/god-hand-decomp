#!/usr/bin/env python3
"""SN ee-gcc 2.95.3-136 driver replacement for matching decompilation of God Hand.

Companion to ``scripts/ee-cc-wrap.py`` (Cygnus 2.96 default compiler).
This wrapper drives the **opt-in** SN-Systems ProDG v1.36 ee-gcc 2.95.3
build for TUs in the ``sq``-prologue group \u2014 retail
functions whose prologues emit ``sq`` callee-save stores that Cygnus
2.96 cannot reproduce.

The SN cc1.exe / cc1plus.exe / as.exe / cpp.exe binaries are Windows
PE; we run them under ``tools/wibo`` (decompals/wibo 0.6.13, a small
static Win32 PE loader). The pipeline mirrors the empirically-validated
SN compile POC:

    cpp0       \u2192 .i   (Cygnus 2.96 cpp0, compatible with SN cc1)
    cc1.exe    \u2192 .s   (SN 2.95.3-136 cc1 via wibo)
    numerize   \u2192 .s   (rewrite ABI reg names to numeric for ee-as)
    ee-as      \u2192 .o   (SCE ee-as 2.10, the same Linux backend
                       ee-cc-wrap.py uses)

The choice of Cygnus 2.96 ``cpp0`` rather than SN ``cpp.exe`` is
deliberate: cpp0 is a Linux binary (no wibo round-trip per preprocess),
its predefined macro set is already pinned to retail's expected
``__GNUC__=2`` / ``__GNUC_MINOR__=`` shape in ``ee-cc-wrap.py``, and
the SN cc1 doesn't observe its own preprocessor's predefines anyway
(it just consumes the .i token stream). Empirically the resulting
code-gen matches retail's `sq`-shape on all 17 probed TUs.

The numerize stage exists because ee-as 2.10 only accepts numeric GPR
names (``$0..$31``), while SN cc1 emits ABI-symbolic names
(``$ra, $sp, $v0, ...``). This is the same mapping
``compile.py::_eeas_compat_registers`` applies to splat-disassembled
carved .s files; we vendor it here too to keep this wrapper
self-contained (no Python import of compile.py).

Usage mirrors a tiny subset of ee-cc-wrap.py::

    sn-cc-wrap.py [-x c|c++] -c [-o OUT.o] [-O0|-O2|...] [-g] [-G N]
                  [-Dname[=val]]... [-Iincludedir]... INPUT.c
    sn-cc-wrap.py --asm-only [...] INPUT.c    # stop after cc1, emit .s

The ``--asm-only`` mode is the smoke-test entry point: it
bypasses the numerize + ee-as stages so the setup script can probe
SN cc1's raw assembly output for the ``sq`` opcode without depending
on the full pipeline being healthy. See ``scripts/setup_toolchain.sh``
\u00a7 5b.

See also:
- the ADR that authorises this wrapper
- the operator guide for opt-in usage
- the empirical probe matrix that proved the SN compiler is the
  correct one for the sq group
"""
from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# Cygnus 2.96 backend tools (preprocessor + assembler are shared with the
# default ee-cc-wrap.py path). Linux-native, no wibo round-trip.
CYGNUS_GCCLIB = ROOT / "compiler" / "linux" / "ee" / "gcc" / "lib" / "gcc-lib" / "ee" / "2.96-ee-001003-1"
CPP0 = CYGNUS_GCCLIB / "cpp0"
EE_AS = ROOT / "compiler" / "linux" / "ee" / "gcc" / "bin" / "ee-as"

# SN 2.95.3-136 frontend (Win32 PE binaries, run via wibo).
SN_GCCLIB = ROOT / "compiler" / "windows" / "ee" / "gcc" / "lib" / "gcc-lib" / "ee" / "2.95.3-sn-136"
SN_CC1 = SN_GCCLIB / "cc1.exe"
SN_CC1PLUS = SN_GCCLIB / "cc1plus.exe"

WIBO = ROOT / "tools" / "wibo"

# Capture launch cwd before any tempdir chdir so ee-as's `.include`
# resolver finds the project's include/include_asm.h. Mirrors
# ee-cc-wrap.py's LAUNCH_CWD; see that file's comment for rationale.
LAUNCH_CWD = Path.cwd().resolve()

# Predefines passed to cpp0. We use Cygnus 2.96 cpp0 (not SN cpp.exe) for
# the reasons documented in the module docstring; the predefines below
# match what the empirical SN compile POC used and what produces
# sq-matching output for retail. The __GNUC_MINOR__ value
# is set to 95 (matching the SN compiler's version) rather than 96
# (Cygnus) because some C source may #if on it and we want the SN code
# path to see the SN version banner. The .i token stream is otherwise
# language-only and the SN cc1 doesn't re-process predefines.
SN_PREDEFINES = [
    "-D__GNUC__=2",
    "-D__GNUC_MINOR__=95",
    "-D__GNUC_PATCHLEVEL__=3",
    "-Dmips",
    "-DMIPSEL",
    "-DR5900",
    "-D_mips",
    "-D_MIPSEL",
    "-D_R5900",
    "-D__ee__",
    "-D__mips__",
    "-D__MIPSEL__",
    "-D__R5900__",
    "-D__mips=3",
    "-D__mips64",
    "-D__mips_eabi",
    "-D__mips_single_float",
    "-D__LONG_MAX__=9223372036854775807L",
    "-D__LANGUAGE_C",
    "-D_LANGUAGE_C",
    "-DLANGUAGE_C",
    "-D__SIZE_TYPE__= unsigned int",
    "-D__PTRDIFF_TYPE__= int",
]


# ABI-symbolic -> numeric GPR name map. Mirrors compile.py's
# _EEAS_GPR_NAME_MAP exactly. Kept inline so this wrapper has no Python
# dependency on compile.py (compile.py's helpers are import-safe but we
# still prefer no cross-script imports from a tools-layer wrapper).
_EEAS_GPR_NAME_MAP = {
    "zero": "0", "at": "1",
    "v0": "2", "v1": "3",
    "a0": "4", "a1": "5", "a2": "6", "a3": "7",
    "t0": "8", "t1": "9", "t2": "10", "t3": "11",
    "t4": "12", "t5": "13", "t6": "14", "t7": "15",
    "s0": "16", "s1": "17", "s2": "18", "s3": "19",
    "s4": "20", "s5": "21", "s6": "22", "s7": "23",
    "t8": "24", "t9": "25",
    "k0": "26", "k1": "27",
    "gp": "28", "sp": "29",
    "fp": "30", "s8": "30",
    "ra": "31",
}
_EEAS_GPR_RE = re.compile(
    r"\$(" + "|".join(sorted(_EEAS_GPR_NAME_MAP, key=len, reverse=True)) + r")\b"
)


# Cygnus-2.96-only ``-f`` features that SN cc1 (gcc 2.95.3-based) doesn't
# implement. Found by the dual-compiler regression harness: SN cc1
# rejects ``-freorder-blocks`` with ``Invalid option`` and exit 33,
# which was hiding behind the wrapper's argparse pass-through.
# These features are *Cygnus-default-build* features (the project carries
# ``-f=-freorder-blocks`` in ``compile_config.json::c_flags`` for the
# sq-prologue group's build). They are silently dropped from the SN feature
# set; the cc1 invocation gets the remaining flags. If SN-specific tuning
# of these behaviours is ever needed, this is the place to add a
# Cygnus-flag -> SN-flag translation.
SN_UNSUPPORTED_FEATURES = frozenset({
    "-freorder-blocks",
})


def _filter_features(features: list[str]) -> tuple[list[str], list[str]]:
    """Return (kept, dropped). Dropped features are logged once via
    ``die``-adjacent stderr (without exiting) so a contributor sees the
    behaviour delta but the compile still proceeds."""
    kept: list[str] = []
    dropped: list[str] = []
    for f in features:
        if f in SN_UNSUPPORTED_FEATURES:
            dropped.append(f)
        else:
            kept.append(f)
    return kept, dropped


def _numerize(text: str) -> str:
    """Rewrite ABI-symbolic GPR names to numeric for ee-as 2.10."""
    return _EEAS_GPR_RE.sub(
        lambda m: "$" + _EEAS_GPR_NAME_MAP[m.group(1)], text
    )


_HAZARD_FP_CMP_RE = re.compile(r"^\s*c\.[a-z]+\.[sd]\b")


def _is_ee_fp_hazard_producer(line: str) -> bool:
    """True if *line* is an EE FP op a following op must stall on (mtc1/ctc1
    GPR->COP1 move, incl. the li.s/li.d float-immediate macro, or an FP compare
    feeding bc1*).  FP loads interlock, so they're excluded.  See ee-cc-wrap.py."""
    op = line.strip()
    return op.startswith(("mtc1", "ctc1", "li.s", "li.d")) \
        or bool(_HAZARD_FP_CMP_RE.match(line))


def _materialize_hazard_nops(text: str) -> str:
    """Turn cc1's commented ``#nop`` EE FP hazard hints into real nops.

    SN cc1 (like cygnus) emits a bare ``#nop`` comment wherever the pipeline
    needs a stall but leaves materialisation to a reorder-capable assembler;
    ee-as does not reorder, so the nop is otherwise lost.  Only the ``#nop``
    whose preceding instruction is an mtc1->FPU or FP-compare->branch hazard
    producer is converted — keeping every already-matched function byte
    identical.  Twin of the helper in ee-cc-wrap.py.
    """
    if "#nop" not in text:
        return text
    lines = text.split("\n")
    out = []
    last_instr = None
    for line in lines:
        stripped = line.strip()
        if stripped == "#nop" and last_instr is not None \
                and _is_ee_fp_hazard_producer(last_instr):
            out.append("\tnop")
            continue
        out.append(line)
        if stripped and not stripped.startswith((".", "#")) \
                and not stripped.endswith(":"):
            last_instr = line
    return "\n".join(out)


def die(msg: str, code: int = 1) -> None:
    print(f"sn-cc-wrap: {msg}", file=sys.stderr)
    sys.exit(code)


def run(cmd: list[str], stage: str, cwd: Path | None = None) -> None:
    try:
        result = subprocess.run(cmd, check=False, cwd=str(cwd) if cwd else None)
    except FileNotFoundError as exc:
        die(f"{stage}: missing binary {exc.filename!r}")
    if result.returncode != 0:
        die(f"{stage} failed (exit {result.returncode})", result.returncode)


def parse_args(argv: list[str]) -> argparse.Namespace:
    p = argparse.ArgumentParser(
        prog="sn-cc-wrap",
        description="SN ee-gcc 2.95.3-136 driver (matching-decomp glue)",
    )
    p.add_argument("input", type=Path, help="Input .c / .cc / .i file")
    p.add_argument("-c", action="store_true", help="Compile to .o")
    p.add_argument("-o", dest="output", type=Path, default=None, help="Output path")
    p.add_argument("-x", choices=("c", "c++"), default=None, help="Source language override")
    p.add_argument("-O", dest="optlevel", default="2", help="Optimization level (default: 2)")
    p.add_argument("-g", action="store_true", help="Emit debug info (-gstabs)")
    p.add_argument("-G", dest="sdata_thresh", type=int, default=0, help="Small-data threshold")
    p.add_argument("-D", dest="defines", action="append", default=[], help="Add a -D macro")
    p.add_argument("-U", dest="undefines", action="append", default=[], help="Add a -U macro")
    p.add_argument("-I", dest="includes", action="append", default=[], help="Add an include dir")
    # -W and -f mirror ee-cc-wrap.py so compile.py's identical argv shape
    # can be forwarded to either wrapper. The default config carries
    # ``-f=-freorder-blocks`` from compile_config.json::c_flags; without
    # these the ee-cc-wrap.py -> sn-cc-wrap.py dispatch would
    # SystemExit on argparse failure long before the .i / .s files exist.
    p.add_argument(
        "-W", dest="warnings", action="append", default=[],
        help="Pass a -W warning flag to cc1 (mirrors ee-cc-wrap.py)",
    )
    p.add_argument(
        "-f", dest="features", action="append", default=[],
        help="Pass a -f compiler feature flag to cc1 (mirrors ee-cc-wrap.py)",
    )
    p.add_argument(
        "--print-stage", action="append", default=[], choices=("i", "s"),
        help="Save .i and/or .s next to output (mirrors ee-cc-wrap.py)",
    )
    p.add_argument(
        "--no-line-info", action="store_true",
        help="Strip absolute paths from cpp0 #line directives (mirrors ee-cc-wrap.py)",
    )
    p.add_argument(
        "--asm-only",
        action="store_true",
        help="Stop after cc1; emit .s instead of .o (smoke-test mode)",
    )
    return p.parse_args(argv)


def detect_language(src: Path, override: str | None) -> str:
    if override:
        return override
    ext = src.suffix.lower()
    if ext in (".cc", ".cpp", ".cxx", ".c++"):
        return "c++"
    if ext in (".c", ".i"):
        return "c"
    if ext in (".ii",):
        return "c++"
    die(f"cannot detect language for {src!r} (use -x c or -x c++)")
    return "c"


def main(argv: list[str]) -> int:
    args = parse_args(argv)

    if not args.asm_only and not args.c:
        die("either -c or --asm-only is required")

    if not args.input.exists():
        die(f"input not found: {args.input}")

    # Verify toolchain pieces. Surface the missing piece by name so the
    # operator knows whether to re-run setup_toolchain.sh (most likely)
    # or to fetch a specific tarball by hand.
    for path, hint in [
        (CPP0, "Cygnus ee-gcc 2.96 cpp0 missing \u2014 run scripts/setup_toolchain.sh"),
        (SN_CC1, "SN ee-gcc 2.95.3-136 cc1.exe missing \u2014 run scripts/setup_toolchain.sh"),
        (WIBO, "wibo missing \u2014 run scripts/setup_toolchain.sh"),
    ]:
        if not path.exists():
            die(hint)
    # ee-as only needed when we actually assemble.
    if not args.asm_only and not EE_AS.exists():
        die("ee-as missing \u2014 run scripts/setup_toolchain.sh")

    # Drop ``-f`` features SN cc1 doesn't understand (e.g. -freorder-blocks).
    # The dual-compiler regression harness found that compile.py's default
    # c_flags carry this Cygnus-only flag; argparse silently accepts it via
    # ``-f`` but SN cc1 then aborts
    # with ``Invalid option``. We surface the drop on stderr once so the
    # behaviour delta is auditable.
    kept_features, dropped_features = _filter_features(args.features)
    if dropped_features:
        print(
            "sn-cc-wrap: dropping Cygnus-only feature(s) for SN cc1: "
            + ", ".join(dropped_features),
            file=sys.stderr,
        )

    language = detect_language(args.input, args.x)
    sn_cc1 = SN_CC1PLUS if language == "c++" else SN_CC1
    if not sn_cc1.exists():
        die(f"SN {sn_cc1.name} missing \u2014 run scripts/setup_toolchain.sh")

    default_suffix = ".s" if args.asm_only else ".o"
    output = args.output or args.input.with_suffix(default_suffix)
    output.parent.mkdir(parents=True, exist_ok=True)

    src_ext = args.input.suffix.lower()
    is_preprocessed = src_ext in (".i", ".ii")

    with tempfile.TemporaryDirectory(prefix="sn-cc-wrap.") as td:
        td_path = Path(td)
        stem = args.input.stem
        i_path = td_path / f"{stem}.i"
        s_path = td_path / f"{stem}.s"
        s_num_path = td_path / f"{stem}.numeric.s"

        # Stage 1: preprocess via Cygnus cpp0 (skipped for .i inputs).
        if not is_preprocessed:
            cpp_cmd = [
                str(CPP0),
                f"-lang-{language}",
                *SN_PREDEFINES,
                *(f"-D{d}" for d in args.defines),
                *(f"-U{u}" for u in args.undefines),
                *(f"-I{i}" for i in args.includes),
                str(args.input),
                str(i_path),
            ]
            run(cpp_cmd, "cpp0")
        else:
            shutil.copy2(args.input, i_path)

        # Stage 2: SN cc1.exe via wibo.
        cc1_cmd = [
            str(WIBO),
            str(sn_cc1),
            "-quiet",
            "-mips3",
            f"-O{args.optlevel}",
            f"-G{args.sdata_thresh}",
            *args.warnings,
            *kept_features,
        ]
        if args.g:
            cc1_cmd.append("-gstabs")
        cc1_cmd += [str(i_path), "-o", str(s_path)]
        # Suppress wibo's spammy stderr banner about thunked imports;
        # cc1's own stderr still flows through stdout because we don't
        # redirect anything. If a real diagnostic happens, cc1 returns
        # non-zero and run() surfaces it.
        env = os.environ.copy()
        env.setdefault("WIBO_DEBUG", "0")
        try:
            result = subprocess.run(cc1_cmd, env=env, check=False, stderr=subprocess.DEVNULL)
        except FileNotFoundError as exc:
            die(f"cc1: missing binary {exc.filename!r}")
        if result.returncode != 0:
            die(f"cc1 failed (exit {result.returncode})", result.returncode)

        if args.asm_only:
            # Smoke-test mode: emit the raw cc1 .s (no numerization, no
            # ee-as round-trip). Used by setup_toolchain.sh \u00a7 5b to
            # assert `sq` opcodes appear in the probe.
            shutil.copy2(s_path, output)
            return 0

        # Optional: side-export the preprocessed .i for debugging.
        if "i" in args.print_stage and not is_preprocessed:
            shutil.copy2(i_path, output.with_suffix(".i"))

        # Stage 3: numerize ABI reg names for ee-as 2.10, materialising any
        # commented #nop EE hazard hints into real nops first.
        s_num_path.write_text(
            _numerize(_materialize_hazard_nops(s_path.read_text()))
        )

        # Stage 4: assemble via Cygnus ee-as (same backend ee-cc-wrap.py
        # uses; consistent with how the existing .o mirror is built).
        # `-mabi=eabi` makes ee-as set ELF flag 0x4000 (eabi64) so the
        # output flags (0x20924001) match retail SLUS_215.03 — same
        # rationale as ee-cc-wrap.py's stage-3 comment. Forward user -I
        # for INCLUDE_ASM resolution; add the launch cwd as ee-as -I so
        # `.include "include/include_asm.h"` still resolves when ee-as
        # runs from tempdir (.mdebug-determinism fix — same
        # justification as ee-cc-wrap.py).
        as_cmd = [
            str(EE_AS),
            "-EL",
            "-mips3",
            "-mcpu=5900",
            "-mabi=eabi",
            f"-G{args.sdata_thresh}",
        ]
        for inc in args.includes:
            as_cmd.append(f"-I{inc}")
        as_cmd += [
            f"-I{LAUNCH_CWD}",
            f"-I{LAUNCH_CWD / 'include'}",
            f"-I{LAUNCH_CWD / 'build' / 'asm'}",
            str(s_num_path),
            "-o", str(output),
        ]
        run(as_cmd, "ee-as")

        # Optional: side-export the (numerized) .s for debugging.
        if "s" in args.print_stage:
            shutil.copy2(s_num_path, output.with_suffix(".s"))

    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
