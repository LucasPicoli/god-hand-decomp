#!/usr/bin/env python3
"""compile.py — build entry point for the God Hand matching-decomp.

Pipeline:

    1. For each ``.c`` / ``.cc`` source: ``scripts/ee-cc-wrap.py`` -> ``.o``
    2. For each ``.s`` source:           ``mipsel-linux-gnu-as``   -> ``.o``
    3. For each ``.vsm`` (VU0) source:   ``ee-dvp-as``             -> ``.o``
    4. Link all ``.o`` (+ raw ``.bin`` data segments) via
       ``mipsel-linux-gnu-ld -T config/SLUS_215.03.ld``            -> ``.elf``

Config lives in ``compile_config.json`` (see that file for the schema).

CLI:

    python compile.py                # full build
    python compile.py --setup        # write objdiff.json from linker entries
    python compile.py --clean        # wipe owned build artifacts
    python compile.py --single-file PATH
                                     # compile/assemble one TU only (no link)
    python compile.py --verbose      # serial, full command echo

This is the build skeleton.  The build it produces is not yet
byte-identical to the retail ELF; this skeleton only needs the build to
complete and be deterministic.
"""
from __future__ import annotations

import argparse
import concurrent.futures
import dataclasses
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path
from typing import Iterable, Optional

ROOT = Path(__file__).resolve().parent

# The schema-side carving surface lives in `scripts/carver.py`. The
# `BuildError`, `CarveEntry`, `CarveState`, `CarveSchema` re-exports
# below keep existing call sites + `tests/test_compile.py`'s
# `pytest.raises(cm.BuildError, ...)` assertions working without
# import changes; the shim is dropped after callers migrate. The
# two-seam rationale splits `CarveSchema` from `CarveSession`.
from scripts.carver import (
    BuildError,
    CarveEntry,
    CarveSchema,
    CarveState,
    _carve_unit_size_bytes,
    _eeas_compat_registers,
    _EEAS_GPR_NAME_MAP,
    _EEAS_GPR_RE,
    _index_functions,
    _parse_carved_entries,
    _preamble_end_index,
    _split_monolithic,
    _ALABEL_LIKE_RE,
    _ALIGN3_RE,
    _ENDLABEL_RE,
    _GLABEL_RE,
    _INSN_LINE_RE,
    _NONMATCHING_RE,
)
DEFAULT_CONFIG = ROOT / "compile_config.json"
DEFAULT_PARALLELISM = 8

# Version registry. `config/versions.json` maps a short version key to its
# build metadata, including which compile_config.json holds that version's
# carve schema + output paths. `us` resolves to the repo-root
# `compile_config.json`, so omitting --version reproduces the original US
# build byte-for-byte.
DEFAULT_VERSIONS = ROOT / "config" / "versions.json"


def _load_versions() -> dict:
    """Return the parsed versions registry, or {} if it is absent."""
    try:
        with DEFAULT_VERSIONS.open() as fh:
            return json.load(fh)
    except FileNotFoundError:
        return {}


def resolve_config_path(version: Optional[str], explicit: Optional[Path]) -> Path:
    """Resolve which compile_config.json to load.

    Precedence: an explicit ``--config`` wins (back-compat / overrides); else
    the ``--version`` key is looked up in ``config/versions.json``; else the
    registry's ``default`` version is used. Falls back to the repo-root
    ``compile_config.json`` when the registry is missing entirely.
    """
    if explicit is not None:
        return explicit
    reg = _load_versions()
    versions = reg.get("versions", {})
    key = version or reg.get("default", "us")
    if key not in versions:
        if not versions:
            return DEFAULT_CONFIG  # registry absent → legacy single-version
        raise BuildError(
            f"--version: {key!r} is not in config/versions.json "
            f"(known: {', '.join(sorted(versions))})"
        )
    rel = versions[key].get("compile_config")
    if not rel:
        raise BuildError(
            f"--version: {key!r} has no 'compile_config' in config/versions.json"
        )
    path = ROOT / rel
    if not path.exists():
        raise BuildError(
            f"--version {key}: compile config {rel} does not exist yet "
            f"(this version has not been bootstrapped — see Phase 2)."
        )
    return path


# --------------------------------------------------------------------------- #
# Config
# --------------------------------------------------------------------------- #
@dataclasses.dataclass(frozen=True)
class Config:
    raw: dict

    @classmethod
    def load(cls, path: Path) -> "Config":
        with path.open() as fh:
            return cls(raw=json.load(fh))

    # Tools -----------------------------------------------------------------
    def tool(self, key: str) -> str:
        val = self.raw["tools"][key]
        p = (ROOT / val) if not Path(val).is_absolute() else Path(val)
        # Treat as a literal path if it exists; otherwise rely on $PATH lookup.
        return str(p) if p.exists() else val

    # Lists / dicts ---------------------------------------------------------
    @property
    def include_dirs(self) -> list[str]:
        return list(self.raw["include_dirs"])

    @property
    def defines(self) -> list[str]:
        return list(self.raw["defines"])

    @property
    def c_flags(self) -> list[str]:
        return list(self.raw["c_flags"])

    @property
    def as_flags(self) -> list[str]:
        return list(self.raw["as_flags"])

    @property
    def dvp_as_flags(self) -> list[str]:
        return list(self.raw["dvp_as_flags"])

    @property
    def linker_scripts(self) -> list[str]:
        return list(self.raw["linker_scripts"])

    @property
    def linker_flags(self) -> list[str]:
        return list(self.raw["linker_flags"])

    @property
    def asm_globs(self) -> list[str]:
        return list(self.raw["asm_sources_glob"])

    @property
    def c_globs(self) -> list[str]:
        return list(self.raw["c_sources_glob"])

    @property
    def vsm_globs(self) -> list[str]:
        return list(self.raw["vsm_sources_glob"])

    @property
    def sdata_overrides(self) -> dict:
        # Filter out documentation keys (those starting with '_').
        return {
            k: v
            for k, v in self.raw["sdata_overrides"].items()
            if not k.startswith("_")
        }

    @property
    def build_dir(self) -> Path:
        return ROOT / self.raw["build_dir"]

    @property
    def output_elf(self) -> Path:
        return ROOT / self.raw["output_elf"]

    @property
    def output_map(self) -> Path:
        return ROOT / self.raw["output_map"]

    @property
    def preserve_in_build(self) -> list[str]:
        return list(self.raw["preserve_in_build"])

    @property
    def objdiff_cfg(self) -> dict:
        return dict(self.raw["objdiff"])

    @property
    def section_flag_overrides(self) -> dict:
        return dict(self.raw.get("section_flag_overrides", {}))

    @property
    def compile_units(self) -> dict[str, dict]:
        """Per-TU compile-time options keyed by source path (string,
        relative to repo root).

        Schema: each entry in ``compile_config.json::compile_units`` is
        ``{"path": <src-rel-to-repo>, "compiler"?: <name>}`` per the
        ``_compile_units_doc`` block.  Documentation entries (``path``
        starting with ``_``) are dropped.  Unknown ``compiler`` values
        raise :class:`BuildError` here so the misconfiguration is
        caught at config-load time, not deep inside the build.

        Returns a dict ``{path -> entry-dict}`` (not just the compiler
        string) so future per-TU options (e.g. extra cflags) can extend
        the entry shape without changing the call sites.
        """
        out: dict[str, dict] = {}
        for raw in self.raw.get("compile_units", []):
            if not isinstance(raw, dict):
                continue
            path = str(raw.get("path", ""))
            if not path or path.startswith("_"):
                continue
            compiler = raw.get("compiler", DEFAULT_COMPILER)
            if compiler not in SUPPORTED_COMPILERS:
                raise BuildError(
                    f"compile_units[{path!r}]: unknown compiler {compiler!r}; "
                    f"expected one of {sorted(SUPPORTED_COMPILERS)}"
                )
            entry = dict(raw)
            entry["compiler"] = compiler
            # Per-TU c_flags filter.
            # `c_flags_drop` lists exact-match flags to remove from the
            # global cfg.c_flags for this TU.  Used to disable
            # `-f=-freorder-blocks` for one-off near-miss TUs where the
            # global flag flips ee-gcc 2.96's branch-likely heuristic
            # away from retail.  Keep narrow: filter-by-exact-match
            # only; no add-flags, no per-function granularity.
            drop = raw.get("c_flags_drop", [])
            if not isinstance(drop, list) or not all(isinstance(f, str) for f in drop):
                raise BuildError(
                    f"compile_units[{path!r}]: c_flags_drop must be a list "
                    f"of strings; got {drop!r}"
                )
            entry["c_flags_drop"] = tuple(drop)
            # Per-TU opt-in: strip the unconditional C++ DWARF frame .data block
            # (provided instead by the data splat for a carved C++ function).
            strip = raw.get("strip_cxx_frame", False)
            if not isinstance(strip, bool):
                raise BuildError(
                    f"compile_units[{path!r}]: strip_cxx_frame must be a bool; "
                    f"got {strip!r}"
                )
            entry["strip_cxx_frame"] = strip
            # Per-TU opt-in: externalize compiler-emitted switch jump tables
            # to the retail rodata blob's symbols (in table-emission order).
            # The wrapper deletes each emitted .rdata table block and
            # redirects its %hi/%lo($Ln) references to the given symbol, so
            # the dispatcher's table bytes keep coming from the split blob
            # (whose .word entries are raw retail addresses) instead of a
            # duplicate TU copy that would shift .rodata.
            jtbl = raw.get("extern_jtbl", [])
            if not isinstance(jtbl, list) or not all(isinstance(s, str) for s in jtbl):
                raise BuildError(
                    f"compile_units[{path!r}]: extern_jtbl must be a list "
                    f"of symbol names; got {jtbl!r}"
                )
            entry["extern_jtbl"] = tuple(jtbl)
            out[path] = entry
        return out

    @property
    def carved_funcs(self) -> list[dict]:
        """Per-function carves out of the monolithic asm baseline.

        Each entry is a dict {name, unit, vaddr, size} per the
        ``_carved_funcs_doc`` block in compile_config.json.  Documentation
        keys (``_*``) and entries whose ``name`` starts with ``_`` are
        filtered out so the doc block can live next to the array.
        """
        out = []
        for raw in self.raw.get("carved_funcs", []):
            if not isinstance(raw, dict):
                continue
            name = str(raw.get("name", ""))
            if not name or (name.startswith("_") and not raw.get("tu")):
                continue
            out.append(raw)
        return out

    @property
    def rels(self) -> list["RelDescriptor"]:
        """Per-REL build descriptors.

        Returns a list of :class:`RelDescriptor` parsed from
        ``compile_config.json::rels``.  Documentation keys (``_*``) and
        entries with no ``name`` are filtered out so the doc block can
        live next to the array.  Empty list when no REL is configured
        (the baseline) — every REL-aware code path is a no-op in that
        case.
        """
        out: list[RelDescriptor] = []
        for raw in self.raw.get("rels", []):
            if not isinstance(raw, dict):
                continue
            name = str(raw.get("name", ""))
            if not name or (name.startswith("_") and not raw.get("tu")):
                continue
            parts: list[RelPart] = []
            for praw in raw.get("parts", []):
                if not isinstance(praw, dict):
                    continue
                kind = str(praw.get("kind", ""))
                if kind not in ("bin", "asm"):
                    raise BuildError(
                        f"rel {name!r}: invalid part kind {kind!r}; "
                        f"expected 'bin' or 'asm'"
                    )
                path = ROOT / str(praw["path"])
                size = int(praw["size"])
                parts.append(RelPart(kind=kind, path=path, size=size))
            if not parts:
                raise BuildError(f"rel {name!r}: parts list is empty")
            out.append(
                RelDescriptor(
                    name=name,
                    lcf=ROOT / str(raw["lcf"]),
                    sha256_expected=str(raw["sha256_expected"]).lower(),
                    size_expected=int(raw["size_expected"]),
                    build_path=ROOT / str(raw["build_path"]),
                    parts=parts,
                )
            )
        return out


# --------------------------------------------------------------------------- #
# Logging / process helpers
# --------------------------------------------------------------------------- #
class Logger:
    def __init__(self, verbose: bool):
        self.verbose = verbose

    def info(self, msg: str) -> None:
        print(msg, flush=True)

    def cmd(self, argv: list[str]) -> None:
        if self.verbose:
            print("$ " + " ".join(_quote(a) for a in argv), flush=True)

    def warn(self, msg: str) -> None:
        print(f"warning: {msg}", file=sys.stderr, flush=True)

    def error(self, msg: str) -> None:
        print(f"error: {msg}", file=sys.stderr, flush=True)


def _quote(s: str) -> str:
    if not s or any(c in s for c in " \t\n'\"\\$`"):
        return "'" + s.replace("'", "'\\''") + "'"
    return s


def run(
    argv: list[str],
    log: Logger,
    *,
    stage: str,
    capture: bool = False,
) -> subprocess.CompletedProcess:
    log.cmd(argv)
    try:
        result = subprocess.run(
            argv,
            check=False,
            stdout=subprocess.PIPE if capture else None,
            stderr=subprocess.PIPE if capture else None,
            text=True,
        )
    except FileNotFoundError as exc:
        raise BuildError(f"{stage}: missing binary {exc.filename!r}") from exc
    if result.returncode != 0:
        out = (result.stdout or "") + (result.stderr or "")
        raise BuildError(
            f"{stage} failed (exit {result.returncode}): "
            + " ".join(_quote(a) for a in argv)
            + (f"\n--- output ---\n{out}" if out else "")
        )
    return result


# `BuildError` lives in `scripts/carver.py` and is re-exported at the top
# of this file.


# --------------------------------------------------------------------------- #
# REL build types
# --------------------------------------------------------------------------- #
# Per-REL build (SNR2-format overlay) is conceptually a sibling of the main-
# ELF build: assemble the splat-emitted asm, full-link with the per-REL lcf,
# extract the linked .text bytes, and concat with verbatim bin parts (the
# SNR2 header + tail) to reproduce the on-disc bytes.  This uses a full link
# (not ``ld -r``).  Each part of the REL is either:
#
#   * ``bin`` — read verbatim from disk; this is the SNR2 header at the
#     start of the file and the (name strings + reloc table + func table +
#     zero pad) tail at the end.
#   * ``asm`` — produced by splat from disassembling the code region; built
#     into a relocatable .o, full-linked, and the .text bytes extracted via
#     ``objcopy -O binary --only-section=.text``.  For r207 there is exactly
#     one asm part covering all 1100 B of code/early-data.
# --------------------------------------------------------------------------- #
@dataclasses.dataclass(frozen=True)
class RelPart:
    kind: str       # "bin" | "asm"
    path: Path      # absolute (under ROOT)
    size: int       # expected byte length (validated post-build)


@dataclasses.dataclass(frozen=True)
class RelDescriptor:
    name: str                       # e.g. "r207"
    lcf: Path                       # absolute path to the per-REL .lcf
    sha256_expected: str            # 64-hex; from disc_extract/rel/manifest.json
    size_expected: int              # bytes
    build_path: Path                # absolute, e.g. ROOT/"build/rel/r207"
    parts: list[RelPart]            # ordered subsegments

    @property
    def output_rel(self) -> Path:
        """Final SNR2 byte stream, e.g. ``build/rel/r207.rel``."""
        return self.build_path.parent / f"{self.name}.rel"

    @property
    def linked_elf(self) -> Path:
        """Intermediate full-link output, discarded after .text extraction."""
        return self.build_path / f"{self.name}.elf"

    @property
    def text_bin(self) -> Path:
        """Extracted .text bytes (input to the final concat)."""
        return self.build_path / f"{self.name}.text.bin"

    @property
    def asm_parts(self) -> list[RelPart]:
        return [p for p in self.parts if p.kind == "asm"]

    @property
    def bin_parts(self) -> list[RelPart]:
        return [p for p in self.parts if p.kind == "bin"]

    def asm_obj_path(self, part: RelPart) -> Path:
        """Per-asm-part .o path under build_path.

        Mirrors the splat-generated linker reference: the asm source at
        ``asm/rel/r207/00003C.s`` lands at
        ``build/rel/r207/asm/rel/r207/00003C.o``.  The lcf hard-codes
        this path so the build cwd MUST be ROOT.
        """
        if part.kind != "asm":
            raise BuildError(f"asm_obj_path: part {part.path} is not asm")
        rel = part.path.relative_to(ROOT)
        return self.build_path / rel.with_suffix(".o")

    @property
    def all_objs(self) -> list[Path]:
        """Every .o the REL build produces, in part order. ``--setup`` and
        ``--reseed-expected`` use this list verbatim."""
        return [self.asm_obj_path(p) for p in self.asm_parts]


# --------------------------------------------------------------------------- #
# Carving
# --------------------------------------------------------------------------- #
# Per-function carving lives here as a pre-build step.  Reads
# ``carved_funcs`` from compile_config.json; if empty, the entire path is
# a no-op and discover()/link() see the baseline tree unchanged.  When
# non-empty, the monolithic asm/cod/000000.s is split into N+1
# fragments around the carve points and one per-function .s is emitted
# per carve, all under build/ (gitignored).  A build-time copy of the
# linker script lists the new units in retail order; ld picks them up
# transparently.
#
# Carve unit boundary (refined against real bytes):
#
#     .align 3                            <-- start (inclusive)
#     [/* Handwritten function */]         (optional comment)
#     nonmatching <name>, <size>           (shadow marker)
#     [blank line(s)]
#     glabel <name>
#       ... function body ...
#     endlabel <name>
#     [inter-function pad nop(s) + blank lines]   <-- still part of
#                                                     this function's carve
#     ----                                        <-- end (exclusive boundary
#                                                     is the *next* function's
#                                                     `.align 3` line, or EOF)
#
# Why the carve range extends through inter-function padding to the next
# function's `.align 3`: in the monolithic, each `.align 3` directive
# always finds the assembly cursor already 8-aligned (the trailing pad
# nop after the previous function makes it so).  In a *fragment* whose
# `.text` starts mid-function-stream, `.align 3` for the first function
# in the fragment finds the cursor at a non-8-aligned offset (because
# the carved function's bytes have been removed from the byte stream the
# fragment continues), so it emits padding bytes — breaking retail byte
# equality.  Including the trailing pad in the *previous* (carved)
# function's unit means the next fragment begins exactly on a function
# boundary where `.align 3` is a no-op.  Verified empirically on
# `func_00100000` (size 4) where the naive `endlabel`-bounded carve
# inflated `.text` by 4 bytes per such carve.
#
# Interior `.align 2` directives (jump-target alignment) stay inside the
# glabel/endlabel span and are extracted by construction.  Interior
# `.align 3` directives are absent in `asm/cod/000000.s` (verified: 0 of
# 11,139 outer-only); if they appear in a future re-splat, this rule
# must be widened to walk to the next *outer-only* `.align 3`.
#
# Why deletion + fragmentation, not `.skip`: a hole filled with `.skip`
# in the monolithic .o cannot be transparently overlaid by a per-function
# .o at link time; retail byte-equality breaks the moment two functions
# move into separate .o files.  This is why `.skip` was rejected.
# --------------------------------------------------------------------------- #
# Carving asm regex constants and `_INSN_LINE_RE` live in
# `scripts/carver.py` and are re-exported at the top of this file.

# Base VMA of the ``.text`` output section in config/SLUS_215.03.lcf
# (line ``.text 0x00100000 : ALIGN(64)``).  Used to translate absolute
# carve-unit end VMAs into section-relative offsets for the LCF
# ``. = cod_TEXT_START + 0x<rel>;`` form.  See ``_emit_build_lcf`` for
# why section-relative is required.
_COD_TEXT_START_VADDR = 0x00100000
# Structural note (carve audit):
# `asm/cod/000000.s` does contain `alabel`/`jlabel`/`ehlabel` directives
# (7864 occurrences with leading whitespace; an earlier grep missed them by
# anchoring to column 0).  However, every one of them lives either
# *inside* a `glabel`/`endlabel` span (where the carve extractor includes
# them naturally) or *outside* any function as section-trailing data-
# style padding labels (which stay in the monolithic fragment because
# no carve targets them).  The extractor's invariant is simply: a carve
# target must name a `glabel`-defined symbol.  alabel/jlabel/ehlabel
# names are not eligible carve roots and will be rejected by
# ``_split_monolithic`` with "function not present in monolithic".
# See the carving notes for the verification procedure.


# `CarveEntry`, `CarveState`, the EEAS GPR map / regex / helper, and
# the pure carving functions (`_parse_carved_entries`,
# `_index_functions`, `_preamble_end_index`, `_split_monolithic`,
# `_carve_unit_size_bytes`) live in `scripts/carver.py`. The imports
# at the top of this file re-export every name unchanged so call sites,
# tests, and downstream consumers (`scripts/checks/units.sh`,
# `scripts/checks/dual_compiler_regress.py`) keep working without
# edits. The re-export shim is dropped after callers migrate to
# importing from `scripts.carver` directly.


def maybe_carve(cfg: "Config", log: Logger) -> Optional[CarveState]:
    """Pre-build carve step.  Returns ``None`` when ``carved_funcs`` is
    empty (no-op path; original tree is the baseline).  Otherwise emits
    the build-time fragments, per-function carves, and lcf, and returns
    a ``CarveState`` describing them.

    The monolithic source path is currently hardcoded to
    ``asm/cod/000000.s`` (the only unit carving currently targets).
    Multi-unit carving is explicitly out of scope until a real decomp
    PR needs it.
    """
    # Use the public `CarveSchema.parse_entries` surface; the
    # underscored alias `_parse_carved_entries` stays imported at the
    # top of this file as a back-compat shim for `tests/test_compile.py`'s
    # ~12 `cm._parse_carved_entries(...)` assertions.
    entries = CarveSchema.parse_entries(cfg)
    if not entries:
        return None

    # Wall-time instrumentation: the carve step is a candidate bottleneck
    # against the 2-second revisit trigger.  Verified empirically that
    # 100 carves complete in <100 ms; the log here surfaces the number
    # under --verbose so future regressions are observable without
    # recompile.py instrumentation.
    _carve_t0 = time.monotonic()

    # All entries must target one monolithic unit; that unit is the carve
    # source.  us carves out of "asm/cod/000000".  Multi-unit carving in one
    # build is still out of scope.
    units = {e.unit for e in entries}
    if len(units) != 1:
        raise BuildError(
            f"carve: all carved_funcs must target a single monolithic unit; "
            f"got units = {sorted(units)}"
        )
    carve_unit = next(iter(units))            # e.g. "asm/cod/000000"
    original_rel = Path(carve_unit + ".s")
    original_abs = ROOT / original_rel
    if not original_abs.exists():
        raise BuildError(f"carve: monolithic source missing: {original_rel}")

    monolithic_text = original_abs.read_text()
    names = [e.name for e in entries]
    # Use the public surface.
    fragments, carved, ranges = CarveSchema.split_monolithic(monolithic_text, names)

    # Validate `size` agreement against the `nonmatching` marker (defence
    # against stale config drift after asm/ re-splat).
    name_to_size = {e.name: e.size for e in entries}
    by_name = {n: (s, e) for (n, s, e) in ranges}
    mono_lines = monolithic_text.splitlines()
    for n in names:
        _start, _end = by_name[n]
        # Find the `nonmatching <n>, <size>` line within the carve unit.
        for li in range(_start, _end + 1):
            mm = _NONMATCHING_RE.match(mono_lines[li])
            if not mm or mm.group(1) != n:
                continue
            # Parse the size after the comma.
            tail = mono_lines[li].split(",", 1)[1].strip()
            try:
                actual = int(tail, 0)
            except ValueError:
                continue
            if actual != name_to_size[n]:
                raise BuildError(
                    f"carve: size mismatch for {n!r}: config says {name_to_size[n]}, "
                    f"monolithic marker says {actual} (line {li + 1})"
                )
            break

    # Write fragments alongside the carve unit (build/<unit-dir>/<name>.partN.s).
    build_root = cfg.build_dir
    unit_rel = Path(carve_unit)               # asm/cod/000000 | asm/<ver>/cod/000000
    frag_dir = build_root / unit_rel.parent
    frag_dir.mkdir(parents=True, exist_ok=True)
    fragment_sources: list[Path] = []
    for idx, frag_text in enumerate(fragments):
        fp = frag_dir / f"{unit_rel.name}.part{idx}.s"
        fp.write_text(frag_text)
        fragment_sources.append(fp)

    # Write carved files under build/asm/nonmatching/.
    carve_dir = build_root / "asm" / "nonmatching"
    carve_dir.mkdir(parents=True, exist_ok=True)
    carved_sources: dict[str, Path] = {}
    for n, ctext in carved.items():
        cp = carve_dir / f"{n}.s"
        cp.write_text(ctext)
        carved_sources[n] = cp

    # Mirror build/asm/nonmatching → build/asm/permanent so the
    # INCLUDE_ASM("permanent", <name>) flavour resolves (`ee-as` does
    # `-I build/asm` and the macro expands to `.include "permanent/..."`).
    # The asm content is byte-identical to the nonmatching carve; the
    # FOLDER string is purely a human/check_tu_complete.py marker.
    # Symlink is idempotent + cheap.
    permanent_link = build_root / "asm" / "permanent"
    try:
        if permanent_link.is_symlink() or permanent_link.exists():
            if not (permanent_link.is_symlink() and
                    permanent_link.resolve() == carve_dir.resolve()):
                if permanent_link.is_symlink() or permanent_link.is_file():
                    permanent_link.unlink()
                else:
                    import shutil as _sh
                    _sh.rmtree(permanent_link)
                permanent_link.symlink_to(carve_dir.name)
        else:
            permanent_link.symlink_to(carve_dir.name)
    except OSError:
        # Filesystem doesn't support symlinks (Windows-on-FAT, …).
        # Fall back to a regular directory mirror.
        permanent_link.mkdir(parents=True, exist_ok=True)
        for n, ctext in carved.items():
            (permanent_link / f"{n}.s").write_text(ctext)

    # Generate the build-time linker script.  Pass per-carve unit sizes
    # so the LCF advances its location counter past each carve's full
    # span (body + trailing nop pad), not just to the next 8-byte
    # boundary.  See the _carve_unit_size_bytes docstring.
    # Use the public surface.
    carve_unit_sizes = {n: CarveSchema.carve_unit_size_bytes(ctext) for n, ctext in carved.items()}
    lcf_path = _emit_build_lcf(
        cfg, fragment_sources, carved_sources, ranges, carve_unit_sizes,
        carve_unit=carve_unit,
    )

    _carve_t1 = time.monotonic()
    log.info(
        f"carve: {len(entries)} function(s) carved out of {original_rel} "
        f"-> {len(fragment_sources)} fragments + {len(carved_sources)} carved .s "
        f"[{(_carve_t1 - _carve_t0) * 1000:.1f} ms]"
    )
    return CarveState(
        original_unit_src=original_abs,
        original_unit_rel=original_rel,
        fragment_sources=fragment_sources,
        carved_sources=carved_sources,
        entries=entries,
        lcf=lcf_path,
    )


def _emit_build_lcf(
    cfg: "Config",
    fragments: list[Path],
    carved: dict[str, Path],
    ranges: list[tuple[str, int, int]],
    carve_unit_sizes: dict[str, int],
    carve_unit: str = "asm/cod/000000",
) -> Path:
    """Write a build-time copy of the committed lcf with the monolithic
    .o reference (``build/asm/cod/000000.o(.text*)``) expanded into a
    source-ordered list of fragment .o + carved .o references.  Other
    sections (``.data``, ``.sndata``, ``.rodata``, ``.gcc_except_table``,
    ``.sbss``, ``.bss``) continue to reference the monolithic .o for
    their respective input sections — only ``.text`` is carved and the
    data/bss subsections of the monolithic .o stay intact because
    fragmenting only mutates ``.text`` content (every fragment also
    contains the file's preamble but no ``.data`` directives).

    Wait — that's wrong.  Each fragment also assembles to an .o that has
    no .data/.rodata/.sndata/.gcc_except_table/.sbss/.bss content, so
    the existing lcf lines referencing ``build/asm/cod/000000.o(.data*)``
    etc.  would dangle.  Fix: replace those references with fragment 0's
    .o (it inherits the preamble and is the canonical "000000" .o for
    non-.text data inputs even though those inputs are empty in our case).

    Actually — and this is the subtlety that bit me writing this docstring
    — the monolithic asm/cod/000000.s contains *only* ``.section .text``
    today (confirmed by a grep above).  No .data/.sndata/.rodata/etc.
    live in 000000.s — they live in asm/data/cod/*.s.  So the existing
    ``build/asm/cod/000000.o(.data*)``/``(.rodata*)``/``(.sndata*)``/
    ``(.gcc_except_table*)``/``(.sbss .scommon)``/``(.bss COMMON)`` lines
    in the lcf are no-ops at link time (the input sections are empty).
    We can safely leave them dangling at the build-time .o path of
    fragment 0 — ld will not complain about empty input sections.

    For robustness, point those lines at fragment 0's .o anyway: that
    file genuinely exists, it has the preamble, and any future appearance
    of non-.text content in 000000.s would still land there (it's the
    fragment that owns the file's preamble).
    """
    src_lcf = ROOT / cfg.linker_scripts[0]
    if not src_lcf.exists():
        raise BuildError(f"carve: linker script missing: {src_lcf.relative_to(ROOT)}")
    src_text = src_lcf.read_text()

    # Build the .text replacement: each fragment, with carve .o inserted
    # between fragments in source order.
    #
    # For TU-owned carves (entry.tu is set), the carve slot references the
    # C TU's .o (e.g. build/src/cod/000000.o) instead of the standalone
    # build/asm/nonmatching/<name>.o.  The C TU's `INCLUDE_ASM` macro pulls
    # the same carved .s into its own .text, so the bytes land at the carve
    # slot via the TU's .o without double-inclusion.
    text_lines: list[str] = []
    frag_objs = [p.with_suffix(".o").relative_to(ROOT).as_posix() for p in fragments]
    # ``ranges`` is in source order; the entries list is the canonical list.
    # Build a name->entry map so we can look up `tu` per carve.
    # Use the public surface.
    entries_by_name = {e.name: e for e in CarveSchema.parse_entries(cfg)}
    def _carve_obj_and_section(name: str) -> tuple[str, str]:
        """Return ``(object_path, section_pattern)`` for a carve slot.

        TU-owned carves reference the C TU's .o and pull just the
        per-function ``.text.<NAME>`` section so multiple carves from
        one TU can land at distinct VMAs (a single ``.o(.text*)``
        match only consumes the section once, collapsing all carves).
        Standalone carves keep ``(.text*)`` since the .o has exactly
        one ``.text.<NAME>`` section anyway.
        """
        e = entries_by_name[name]
        if e.tu:
            tu_rel = Path(e.tu)
            return (
                (Path("build") / tu_rel.with_suffix(".o")).as_posix(),
                f"(.text.{name})",
            )
        return (
            carved[name].with_suffix(".o").relative_to(ROOT).as_posix(),
            "(.text*)",
        )
    carve_slots = [_carve_obj_and_section(n) for (n, _s, _e) in ranges]
    # After every carve slot, advance the LCF location counter to the
    # carve unit's true end VRAM
    # (``entry.vaddr + carve_unit_size_bytes``).
    #
    # Why not just ``. = ALIGN(8);``?  The carve-unit boundary widens
    # to the next .align 3 in monolithic asm (see the carving notes), so the
    # inter-function nop pad is part of the carved fragment.  But a
    # C-TU carve only contributes the function body (no trailing pad).
    # For 12-B 3-insn functions with a 4-B trailing nop, ALIGN(8) is
    # enough to round up.  For 8-B 2-insn functions whose carve unit
    # extends to e.g. 40 B (8 B body + 8 trailing nops at
    # ``func_00138BB8``), ALIGN(8) is a no-op and the trailing 32 B
    # are silently lost — every subsequent function in .text shifts
    # 32 B earlier, drifting the ELF sha256.  An early carve batch hit
    # this 20 / 20 times.
    #
    # Implementation note: GNU ld treats ``. = N;`` inside a section
    # description as RELATIVE to the section's start VMA when N is a
    # raw integer literal (empirically verified).  To avoid the
    # surprise, we use ``cod_TEXT_START + 0x<rel_off>;``
    # which ld evaluates correctly as an absolute address (the symbol
    # ``cod_TEXT_START`` is defined at the section's start a few
    # lines above).
    #
    # Idempotent for non-TU carves whose standalone .o already
    # contributes the full carve unit bytes; in that case ``.`` is
    # already at the directive's target and the gap is zero bytes.
    # The zero-fill matches MIPS LE ``nop`` (0x00000000), so
    # byte-equality with retail is preserved.
    #
    # The post-fragment ALIGN(8) is kept as belt-and-suspenders
    # insurance — fragments always start 8-aligned in the monolithic
    # so the directive is a no-op there too, but the cost is zero.
    text_lines.append(f"        {frag_objs[0]}(.text*)")
    text_lines.append(f"        . = ALIGN(8);")
    for i, (obj, section) in enumerate(carve_slots):
        name = ranges[i][0]
        entry = entries_by_name[name]
        size_bytes = carve_unit_sizes[name]
        end_vaddr = entry.vaddr + size_bytes
        # Section-relative offset (cod_TEXT_START is the .text base).
        rel_off = end_vaddr - _COD_TEXT_START_VADDR
        text_lines.append(f"        {obj}{section}")
        text_lines.append(
            f"        . = cod_TEXT_START + 0x{rel_off:X};"
        )
        text_lines.append(f"        {frag_objs[i + 1]}(.text*)")
        text_lines.append(f"        . = ALIGN(8);")
    text_block = "\n".join(text_lines)

    mono_obj = f"build/{carve_unit}.o"           # build/asm/cod/000000.o | build/asm/<ver>/cod/000000.o
    new_text = src_text.replace(
        f"        {mono_obj}(.text*)",
        text_block,
    )
    if new_text == src_text:
        raise BuildError(
            f"carve: failed to find `{mono_obj}(.text*)` in "
            "the committed lcf; carving requires the carve-aware lcf shape."
        )

    # Boundary-safe carving: force every input `.text*` in the carved output
    # section to 8-byte alignment.  Carve units end on function (`.align 3`,
    # 8-byte) boundaries, but a split fragment's standalone `.text` section
    # inherits gas's *default* 16-byte (2**4) alignment for the canonical
    # `.text` name (a per-function `.text.<NAME>` carve section only gets the
    # 2**3 its body's `.align 3` requests).  When a carved function's end VRAM
    # is 8-but-not-16-aligned, ld bumps the following 16-aligned fragment up
    # by 8 bytes — every subsequent function shifts and the next carve's
    # `. = cod_TEXT_START + 0x<end>;` directive then moves the location
    # counter *backwards* ("cannot move location counter backwards").  The us
    # carves were hand-curated onto 16-aligned boundaries to dodge this.
    # SUBALIGN(8) overrides the input alignment *downward* so fragments land
    # exactly at the carve directive's 8-aligned target with no fill.
    # Byte-neutral for an already-16-aligned layout (the us build verifies
    # byte-identical), so it is applied to the build-time lcf.  Verified
    # downward-override empirically against mipsel-linux-gnu-ld 2.42.
    subalign_anchor = "    .text 0x00100000 : ALIGN(64)"
    if subalign_anchor in new_text:
        new_text = new_text.replace(
            subalign_anchor, subalign_anchor + " SUBALIGN(8)", 1,
        )
    else:
        raise BuildError(
            "carve: failed to find the `.text ... : ALIGN(64)` output-section "
            "header in the committed lcf; boundary-safe SUBALIGN(8) cannot be "
            "applied (carving requires the carve-aware lcf shape)."
        )

    # Repoint the .data/.rodata/.sndata/.gcc_except_table/.sbss/.bss
    # references that currently target the monolithic .o to fragment 0
    # (see docstring above for rationale).
    frag0 = frag_objs[0]
    for section_pat in (
        "(.data*)", "(.rodata*)", "(.sndata*)",
        "(.gcc_except_table*)", "(.sbss .scommon)", "(.bss COMMON)",
    ):
        old = f"        {mono_obj}{section_pat}"
        new = f"        {frag0}{section_pat}"
        new_text = new_text.replace(old, new)

    out = cfg.build_dir / src_lcf.name
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(new_text)
    return out


# --------------------------------------------------------------------------- #
# Source discovery
# --------------------------------------------------------------------------- #
# Per-TU compiler choice.  The default (cygnus-2.96) is today's
# behaviour for all 735 currently-matched TUs; the alternatives are
# (sn-2.95.3-136) the opt-in SN ee-gcc for the `sq`-prologue group, and
# (ee-2.9-991111) the older Sony/Cygnus ee-gcc for the newlib mprec/dtoa
# group whose retail prologue uses 64-bit `sd` callee-saves in 16-byte
# slots.  Anything not in this set is a config error — see
# Config.compile_units.
DEFAULT_COMPILER = "cygnus-2.96"
SUPPORTED_COMPILERS = frozenset({"cygnus-2.96", "sn-2.95.3-136", "ee-2.9-991111"})


@dataclasses.dataclass(frozen=True)
class CompileUnit:
    src: Path                      # absolute
    obj: Path                      # absolute (build/<rel>.o)
    kind: str                      # "c" | "asm" | "vsm"
    rel: Path                      # relative to ROOT (for log/UI)
    compiler: str = DEFAULT_COMPILER  # per-TU cc1 dispatch
    # Exact-match flags to filter out of cfg.c_flags for this TU.
    # Empty tuple = no-op (today's behaviour for all TUs except those
    # listed in compile_config.json::compile_units with c_flags_drop set).
    c_flags_drop: tuple = ()
    # Strip the unconditional C++ DWARF frame .data block from this TU's .o
    # (the frame data is provided by the data splat instead). C++ TUs only.
    strip_cxx_frame: bool = False
    # Symbols to substitute for compiler-emitted switch jump tables, in
    # emission order (--extern-jtbl per entry). Empty = no-op.
    extern_jtbl: tuple = ()


def _glob_all(patterns: Iterable[str]) -> list[Path]:
    found: list[Path] = []
    for pat in patterns:
        for p in sorted(ROOT.glob(pat)):
            if p.is_file():
                found.append(p)
    return found


def _foreign_version_roots(cfg: Config) -> set[Path]:
    """Source roots (``src/<ver>`` / ``asm/<ver>``) of OTHER registered versions
    that this config's own globs do not explicitly target.

    The US (default) config uses recursive globs (``src/**/*.c``, ``asm/**/*.s``)
    that would otherwise sweep any per-version source root into the US unit
    list. Those belong to the per-version builds (whose configs use scoped
    ``src/<ver>/**`` globs and link their own ELF); the US main-ELF lcf never
    references them, so discovering them would produce a ``units`` ratchet
    drift *and* make every US build wastefully recompile foreign objects into
    colliding ``build/src/<ver>/*.o`` paths.

    A version's root is pruned only when NONE of this config's glob patterns
    start with it (a scoped ``src/<ver>/**`` keeps its own root but still
    prunes the others). This mirrors the REL-part skip in :func:`discover`.
    """
    own_globs = list(cfg.asm_globs) + list(cfg.c_globs) + list(cfg.vsm_globs)
    roots: set[Path] = set()
    for key in _load_versions().get("versions", {}):
        for sub in (f"src/{key}", f"asm/{key}"):
            root = ROOT / sub
            if not root.is_dir():
                continue
            if not any(g.startswith(sub + "/") for g in own_globs):
                roots.add(root.resolve())
    return roots


def discover(cfg: Config, carve: Optional[CarveState] = None) -> list[CompileUnit]:
    """Return the full list of compile units the build owns.

    Object paths mirror the splat-generated linker script's expectations:
    ``asm/cod/000000.s`` -> ``build/asm/cod/000000.o`` (splat ``o_as_suffix:
    True`` keeps the ``.data.s`` -> ``.data.o`` mapping).

    When *carve* is not ``None``, the original monolithic
    asm/cod/000000.s is removed from the unit list and the build-time
    fragments + per-function carved .s files take its place.  The build-
    time files live under ``build/asm/...`` (gitignored).
    """
    units: list[CompileUnit] = []
    skip_src: set[Path] = set()
    if carve is not None:
        skip_src.add(carve.original_unit_src.resolve())
    # REL asm parts are assembled separately by build_rel() against a
    # per-REL build_path; keep them out of the main-ELF unit list so
    # they don't double-build to ``build/asm/rel/...`` (which the main-
    # ELF lcf doesn't reference) on every full build.
    skip_src |= _rel_asm_part_paths(cfg)

    # Per-version source trees (``src/<ver>/``, ``asm/<ver>/`` …) that this
    # config's globs don't target — owned by the per-version builds, never
    # by this lcf. Pruned here (not in the units check) so the recursive US
    # globs neither drift the units ratchet nor wastefully recompile them.
    foreign_roots = _foreign_version_roots(cfg)

    def _is_foreign(src: Path) -> bool:
        rp = src.resolve()
        return any(root in rp.parents for root in foreign_roots)

    for src in _glob_all(cfg.asm_globs):
        if src.resolve() in skip_src or _is_foreign(src):
            continue
        rel = src.relative_to(ROOT)
        obj = cfg.build_dir / rel.with_suffix(".o")
        units.append(CompileUnit(src=src, obj=obj, kind="asm", rel=rel))

    if carve is not None:
        for fp in carve.fragment_sources:
            rel = fp.relative_to(ROOT)
            obj = fp.with_suffix(".o")
            units.append(CompileUnit(src=fp, obj=obj, kind="asm", rel=rel))
        for _name, cp in carve.carved_sources.items():
            # Skip TU-owned carves: the C TU's .o (discovered below from
            # cfg.c_globs) carries the bytes via INCLUDE_ASM, and assembling
            # the standalone .o too would double-include at link time (and
            # break retail byte equality via the lcf catch-all).  The
            # carved .s still exists on disk so the C TU's `.include` can
            # find it.
            if carve.is_tu_owned(_name):
                continue
            rel = cp.relative_to(ROOT)
            obj = cp.with_suffix(".o")
            units.append(CompileUnit(src=cp, obj=obj, kind="asm", rel=rel))

    compile_units_map = cfg.compile_units
    for src in _glob_all(cfg.c_globs):
        if _is_foreign(src):
            continue
        rel = src.relative_to(ROOT)
        obj = cfg.build_dir / rel.with_suffix(".o")
        entry = compile_units_map.get(str(rel), {})
        compiler = entry.get("compiler", DEFAULT_COMPILER)
        c_flags_drop = entry.get("c_flags_drop", ())
        units.append(CompileUnit(
            src=src, obj=obj, kind="c", rel=rel, compiler=compiler,
            c_flags_drop=tuple(c_flags_drop),
            strip_cxx_frame=bool(entry.get("strip_cxx_frame", False)),
            extern_jtbl=tuple(entry.get("extern_jtbl", ())),
        ))

    for src in _glob_all(cfg.vsm_globs):
        if _is_foreign(src):
            continue
        rel = src.relative_to(ROOT)
        obj = cfg.build_dir / rel.with_suffix(".o")
        units.append(CompileUnit(src=src, obj=obj, kind="vsm", rel=rel))

    return units


# --------------------------------------------------------------------------- #
# Build steps
# --------------------------------------------------------------------------- #
def compile_unit(unit: CompileUnit, cfg: Config, log: Logger) -> None:
    unit.obj.parent.mkdir(parents=True, exist_ok=True)
    if unit.kind == "asm":
        _assemble(unit, cfg, log)
    elif unit.kind == "c":
        _cc(unit, cfg, log)
    elif unit.kind == "vsm":
        _dvp(unit, cfg, log)
    else:
        raise BuildError(f"unknown unit kind {unit.kind!r} for {unit.rel}")


def _includes(cfg: Config) -> list[str]:
    return [f"-I{ROOT / inc}" for inc in cfg.include_dirs]


def _g_flag(unit: CompileUnit, cfg: Config) -> Optional[str]:
    """Return a -G<n> override for *unit* if compile_config.sdata_overrides
    lists this source, else ``None``."""
    override = cfg.sdata_overrides.get(str(unit.rel))
    if override is None:
        return None
    return f"-G{int(override)}"


def _assemble(unit: CompileUnit, cfg: Config, log: Logger) -> None:
    argv = [cfg.tool("mipsel_as"), *cfg.as_flags, *_includes(cfg)]
    g = _g_flag(unit, cfg)
    if g is not None:
        # Replace the default -G0 (or whatever) with the override.
        argv = [a for a in argv if not a.startswith("-G")] + [g]
    argv += [str(unit.src), "-o", str(unit.obj)]
    run(argv, log, stage=f"as[{unit.rel}]")
    _fix_section_flags(unit, cfg, log)
    _fix_carve_alignment(unit, cfg, log)


def _fix_carve_alignment(unit: CompileUnit, cfg: Config, log: Logger) -> None:
    """Force `.text` ``sh_addralign`` to 1 on carve-related .o files.

    Background: GNU `as` assigns ``sh_addralign = 16`` to ``.text`` by
    default on this target, regardless of `.s` content (no `as` command-
    line option lowers it; even `.balign 4` inside the source can only
    *raise* the section alignment, never lower it).  When the linker
    concatenates fragments + carves into the output ``.text``, every
    over-aligned input pads the cursor up to a 16-byte boundary,
    inflating the section size and shifting downstream LMAs (ld emits
    the diagnostic "section .data lma X adjusted to Y").

    The monolithic ``asm/cod/000000.o`` is safe with its natural
    alignment because its content size (0x2BBF80) is already a multiple
    of 16; carved/fragmented .o files generally are not.  Forcing
    ``sh_addralign = 1`` is the minimum-surgery fix: per-instruction
    alignment is still guaranteed by the ``.align`` directives baked
    into the content (every function in `asm/cod/000000.s` starts with
    ``.align 3`` which the assembler honours inline), and the output
    ``.text`` section's own alignment (64, per the lcf) still places the
    very first byte at a retail-correct VMA.

    Applies only to ``build/asm/cod/000000.part*.s`` and
    ``build/asm/nonmatching/*.s``; all other .o files keep their
    natural alignment.
    """
    rel_str = unit.rel.as_posix()
    if not (
        rel_str.startswith("build/asm/cod/000000.part")
        or rel_str.startswith("build/asm/nonmatching/")
    ):
        return
    run(
        [
            cfg.tool("mipsel_objcopy"),
            "--set-section-alignment", ".text=1",
            str(unit.obj),
        ],
        log,
        stage=f"objcopy-align[{unit.rel}]",
    )


def _fix_section_flags(unit: CompileUnit, cfg: Config, log: Logger) -> None:
    """Apply ``compile_config.section_flag_overrides`` to ``unit.obj``.

    Splat's spim_disasm output declares ``.text`` as ``"ax"`` and ``.data``
    as ``"wa"``, but the retail PS2 ELF has ``SHF_WRITE`` set on both (the
    overlay loader patches over `.text` at runtime).  Output section flags
    inherit from input sections, so the W bit must be on the ``.o`` before
    ld merges.  We use ``objcopy --set-section-flags`` to set the right
    flags on each touched section in place; if a section is absent in this
    ``.o``, objcopy silently no-ops, which is what we want.
    """
    overrides = cfg.section_flag_overrides
    if not overrides:
        return
    # Probe which sections are present in this .o; --set-section-flags for an
    # absent section is a hard error in objcopy, so we filter beforehand.
    probe = subprocess.run(
        ["mipsel-linux-gnu-readelf", "-SW", str(unit.obj)],
        check=False, capture_output=True, text=True,
    )
    present = set()
    for line in probe.stdout.splitlines():
        line = line.lstrip()
        if not line.startswith("["):
            continue
        try:
            name = line.split("]", 1)[1].split()[0]
        except IndexError:
            continue
        present.add(name)
    argv = [cfg.tool("mipsel_objcopy")]
    touched = []
    for sec, flags in overrides.items():
        if sec in present:
            argv += ["--set-section-flags", f"{sec}={flags}"]
            touched.append(sec)
    if not touched:
        return
    argv += [str(unit.obj)]
    run(argv, log, stage=f"objcopy-flags[{unit.rel}]")


def _cc(unit: CompileUnit, cfg: Config, log: Logger) -> None:
    lang = "c++" if unit.src.suffix.lower() in (".cc", ".cpp", ".cxx", ".c++") else "c"
    # ee-cc-wrap.py dispatches cc1 based on --compiler.  Default
    # = cygnus-2.96 (today's behaviour, zero regression for the 735
    # currently-matched TUs); sn-2.95.3-136 is the opt-in SN path for
    # the `sq`-prologue group.  Both paths share cpp0 + ee-as so ELF
    # flags (0x20924001, eabi64) match retail regardless.
    # Per-TU c_flags filter: drop exact-match flags from the global
    # cfg.c_flags before forwarding to ee-cc-wrap.py.  Default empty
    # tuple = no-op (zero regression).
    effective_c_flags = [f for f in cfg.c_flags if f not in unit.c_flags_drop]
    argv = [
        sys.executable,
        cfg.tool("ee_cc_wrap"),
        "-c",
        f"--compiler={unit.compiler}",
        "-x",
        lang,
        *effective_c_flags,
        *(f"-D{d}" for d in cfg.defines),
        *_includes(cfg),
        # Carved nonmatching asm lives under build/asm/nonmatching/<name>.s
        # (gitignored, regenerated by maybe_carve()).  INCLUDE_ASM("nonmatching",
        # name) expands to `.include "nonmatching/name.s"`, which ee-as
        # resolves via its -I search list (forwarded by ee-cc-wrap.py).
        f"-I{ROOT / 'build' / 'asm'}",
        str(unit.src),
        "-o",
        str(unit.obj),
    ]
    if unit.strip_cxx_frame:
        argv.append("--strip-cxx-frame")
    for sym in unit.extern_jtbl:
        argv += ["--extern-jtbl", sym]
    g = _g_flag(unit, cfg)
    if g is not None:
        argv = [a for a in argv if not a.startswith("-G")] + [g]
    run(argv, log, stage=f"cc[{unit.rel}]")
    # Apply section flag overrides to the C TU's .o too.  When INCLUDE_ASM
    # pulls a carved function into the TU's .text, that .text needs the
    # SHF_WRITE bit (PS2 retail flag W|A|X) just like the asm .o files;
    # otherwise ld merges with inconsistent input flags and the output
    # .text drops the W bit, breaking byte-equality with retail's ELF
    # section table.  _fix_section_flags is defensive (probes for
    # section presence) and a no-op when no overrides match.
    _fix_section_flags(unit, cfg, log)


def _dvp(unit: CompileUnit, cfg: Config, log: Logger) -> None:
    argv = [
        cfg.tool("ee_dvp_as"),
        *cfg.dvp_as_flags,
        str(unit.src),
        "-o",
        str(unit.obj),
    ]
    run(argv, log, stage=f"dvp-as[{unit.rel}]")


# --------------------------------------------------------------------------- #
# Link
# --------------------------------------------------------------------------- #
def link(
    units: list[CompileUnit],
    cfg: Config,
    log: Logger,
    carve: Optional[CarveState] = None,
) -> Path:
    cfg.output_elf.parent.mkdir(parents=True, exist_ok=True)
    argv = [cfg.tool("mipsel_ld")]
    if carve is not None:
        # Use the carving-aware build-time copy of the linker script.
        argv += ["-T", str(carve.lcf)]
        for ls in cfg.linker_scripts[1:]:
            argv += ["-T", str(ROOT / ls)]
    else:
        for ls in cfg.linker_scripts:
            argv += ["-T", str(ROOT / ls)]
    argv += list(cfg.linker_flags)
    argv += ["-Map", str(cfg.output_map)]
    argv += ["-o", str(cfg.output_elf)]
    # Object inputs are referenced *inside* the hand-written linker script
    # (``build/asm/<...>.o(.text*)`` etc.), so we don't add them to argv —
    # ld will pick them up via the script directly.  We still want ld to
    # error if those files are missing, so the link will fail fast.
    # External symbol bindings (previously config/undefined_*_auto.txt
    # plus a ``--defsym`` synthesis) now live directly in the .lcf;
    # see config/SLUS_215.03.lcf.
    run(argv, log, stage="ld")
    _postprocess_elf(cfg, log)
    return cfg.output_elf


def _postprocess_elf(cfg: Config, log: Logger) -> None:
    """Run ``scripts/elf_postprocess.py`` against the linked ELF in place.

    Patches the SHT entries for ``.text`` / ``.data`` / ``.sndata`` /
    ``.rodata`` / ``.gcc_except_table`` / ``.sbss`` / ``.bss`` so sh_size
    and sh_flags match retail.  ld inherits sh_size from input
    sections and has no scriptable way to declare a smaller sh_size while
    keeping the trailing bytes in the file; this is the cleanest fix.
    """
    # The post-link patch (section-header + PT_LOAD fixups in elf_postprocess.py)
    # is currently US-specific. A version whose full-ELF metadata reconstruction
    # is not yet wired sets "postprocess_elf": false; its loaded image is already
    # byte-exact via the hand-written .lcf, only the non-loaded section headers
    # remain. Default true preserves the US path unchanged.
    if not cfg.raw.get("postprocess_elf", True):
        log.info(
            "elf_postprocess disabled for this version (loaded image is "
            "byte-exact; full-ELF metadata reconstruction deferred)"
        )
        return
    script = ROOT / "scripts" / "elf_postprocess.py"
    if not script.exists():
        log.warn(f"missing {script.relative_to(ROOT)}; skipping post-link patch")
        return
    # Per-version metadata dir (retail invariants + non-loaded payloads).
    # US omits the key and falls back to the flat bin/elf_metadata; a version
    # may nest under bin/elf_metadata/<key>. See scripts/extract_elf_metadata.py.
    metadata_dir = ROOT / cfg.raw.get("metadata_dir", "bin/elf_metadata")
    run(
        [sys.executable, str(script), str(cfg.output_elf),
         "--metadata-dir", str(metadata_dir)],
        log,
        stage="elf-postprocess",
    )


# --------------------------------------------------------------------------- #
# REL build
# --------------------------------------------------------------------------- #
def _assemble_rel_part(
    rel: RelDescriptor, part: RelPart, cfg: Config, log: Logger
) -> Path:
    """Assemble one REL asm part to its per-REL .o under ``rel.build_path``.

    Uses the same ``as_flags`` as the main-ELF asm path (R5900 / EABI /
    G0 / --no-pad-sections) so per-section padding stays consistent.
    The .text section flag override (W bit forced on) is applied so the
    output .o looks identical to main-ELF asm .o files — useful when
    objdiff scores the REL's per-`.o` units against the
    ``expected/build/rel/...`` mirror.
    """
    obj = rel.asm_obj_path(part)
    obj.parent.mkdir(parents=True, exist_ok=True)
    argv = [cfg.tool("mipsel_as"), *cfg.as_flags, *_includes(cfg),
            str(part.path), "-o", str(obj)]
    src_rel = part.path.relative_to(ROOT)
    run(argv, log, stage=f"as[rel:{rel.name}:{src_rel}]")
    # Apply section flag overrides (e.g. W bit on .text) so per-`.o`
    # objdiff scoring is symmetric with the main-ELF asm path.  This
    # does not change the bytes objcopy extracts from the linked ELF
    # (those bytes are the .text content, not the section flags).
    rel_unit = CompileUnit(src=part.path, obj=obj, kind="asm",
                           rel=src_rel)
    _fix_section_flags(rel_unit, cfg, log)
    return obj


def _link_rel(rel: RelDescriptor, cfg: Config, log: Logger) -> Path:
    """Full-link the REL .o(s) via ``mipsel-linux-gnu-ld``.

    NOT ``ld -r``: a partial link would leave internal R_MIPS_26 / HI16 /
    LO16 relocations unresolved (in-place value = 0), whereas the on-disc
    REL byte stream has those internals pre-resolved by the original
    snarl/dlltool.  A full link with .text at REL-local VMA 0x3C
    reproduces the on-disc bytes byte-for-byte; the only externals
    (e.g. ``_MemoryAlloc__FUiUiR5cHeap``) stay at in-place value 0
    because ``--unresolved-symbols=ignore-all`` silently leaves them as
    undefined — which matches the on-disc bytes, since the SNR2 loader
    patches those at runtime via the externs encoded in ``tail.bin``.
    """
    rel.linked_elf.parent.mkdir(parents=True, exist_ok=True)
    argv = [cfg.tool("mipsel_ld"), "-EL",
            "-T", str(rel.lcf),
            "--unresolved-symbols=ignore-all",
            "-o", str(rel.linked_elf)]
    # Object inputs are referenced INSIDE the per-REL lcf (e.g.
    # ``build/rel/r207/asm/rel/r207/00003C.o(.text*)``), so we don't add
    # them to argv — ld picks them up via the script.  The lcf paths are
    # repo-rooted so this command MUST be run with cwd=ROOT (which
    # subprocess.run inherits from our process).
    run(argv, log, stage=f"ld[rel:{rel.name}]")
    return rel.linked_elf


def _extract_rel_text(rel: RelDescriptor, cfg: Config, log: Logger) -> Path:
    """Extract .text bytes from the linked REL ELF via objcopy.

    The resulting blob is the byte sequence that goes between the SNR2
    header (header.bin) and the SNR2 tail (tail.bin) in the final .rel
    file.  Size is asserted against the asm part's declared size.
    """
    rel.text_bin.parent.mkdir(parents=True, exist_ok=True)
    argv = [cfg.tool("mipsel_objcopy"), "-O", "binary",
            "--only-section=.text",
            str(rel.linked_elf), str(rel.text_bin)]
    run(argv, log, stage=f"objcopy[rel:{rel.name}]")
    return rel.text_bin


def _concat_rel(rel: RelDescriptor, log: Logger) -> Path:
    """Concatenate the REL's parts in declaration order.

    For ``kind == 'bin'`` parts the bytes come from the splat-emitted
    ``bin/rel/<name>/*.bin`` files verbatim; for ``kind == 'asm'`` parts
    the bytes come from the linked ELF's extracted ``.text.bin``.

    Asserts each part's byte count matches its declared ``size`` so a
    schema drift (e.g. someone forgets to update ``parts[].size`` after
    re-splatting) fails loudly here rather than silently producing a
    byte-mismatched .rel.

    Returns the path to the assembled output (``build/rel/<name>.rel``).
    """
    if not rel.asm_parts:
        raise BuildError(f"rel {rel.name!r}: no asm parts; cannot build")
    # For r207 there is exactly one asm part covering all of .text. The
    # current implementation assumes a single asm part per REL; multi-
    # section RELs (mcport.rel, event.rel) will need a per-section
    # objcopy when they get wired up. Fail loudly today rather than
    # silently producing wrong bytes.
    if len(rel.asm_parts) != 1:
        raise BuildError(
            f"rel {rel.name!r}: multi-asm-part RELs not supported yet "
            f"({len(rel.asm_parts)} asm parts); the multi-part REL "
            f"extension is not yet implemented."
        )
    asm_part_bytes = rel.text_bin.read_bytes()
    asm_part = rel.asm_parts[0]
    if len(asm_part_bytes) != asm_part.size:
        raise BuildError(
            f"rel {rel.name!r}: .text extract is {len(asm_part_bytes)} B "
            f"but parts[asm].size declares {asm_part.size} B; either the"
            f" asm file changed and parts[].size needs an update, or the"
            f" lcf is emitting unexpected bytes."
        )
    rel.output_rel.parent.mkdir(parents=True, exist_ok=True)
    out = bytearray()
    for part in rel.parts:
        if part.kind == "bin":
            if not part.path.is_file():
                raise BuildError(
                    f"rel {rel.name!r}: bin part {part.path.relative_to(ROOT)}"
                    f" missing; run splat first"
                )
            chunk = part.path.read_bytes()
        elif part.kind == "asm":
            chunk = asm_part_bytes
        else:
            raise BuildError(
                f"rel {rel.name!r}: unknown part kind {part.kind!r}")
        if len(chunk) != part.size:
            raise BuildError(
                f"rel {rel.name!r}: part {part.path.relative_to(ROOT)} "
                f"size {len(chunk)} != declared {part.size}"
            )
        out.extend(chunk)
    if len(out) != rel.size_expected:
        raise BuildError(
            f"rel {rel.name!r}: concat size {len(out)} != size_expected "
            f"{rel.size_expected}; check parts[].size totals."
        )
    rel.output_rel.write_bytes(bytes(out))
    log.info(f"  concat {rel.output_rel.relative_to(ROOT)} ({len(out)} B)")
    return rel.output_rel


def _verify_rel_sha256(rel: RelDescriptor, log: Logger) -> None:
    """Assert the built REL's sha256 matches the on-disc retail bytes.

    The expected sha256 lives in ``compile_config.json::rels[].sha256_expected``
    and must equal the value in ``disc_extract/rel/manifest.json`` for the
    same name (the manifest is the source of truth; the config value
    is a build-time copy so a fresh clone can verify without the AFS).

    Raises ``BuildError`` on mismatch with the first differing byte's
    offset so the failure is debuggable.
    """
    data = rel.output_rel.read_bytes()
    got = hashlib.sha256(data).hexdigest()
    if got == rel.sha256_expected:
        log.info(
            f"  rel {rel.name}: sha256 {got[:16]}… matches retail"
        )
        return
    # Mismatch: try to find the first byte that differs, comparing
    # against the AFS-extracted reference if it's available.
    ref_path = ROOT / "disc_extract" / "rel" / f"{rel.name}.rel"
    diag = ""
    if ref_path.is_file():
        ref = ref_path.read_bytes()
        if len(ref) != len(data):
            diag = (
                f" size mismatch built={len(data)} ref={len(ref)};"
            )
        for i, (a, b) in enumerate(zip(data, ref)):
            if a != b:
                ctx_lo = max(0, i - 8)
                ctx_hi = min(len(data), i + 8)
                diag += (
                    f" first diff at off=0x{i:x}: built={a:#04x} "
                    f"ref={b:#04x}; context built="
                    f"{data[ctx_lo:ctx_hi].hex()} "
                    f"ref={ref[ctx_lo:ctx_hi].hex()}"
                )
                break
    raise BuildError(
        f"rel {rel.name!r}: sha256 mismatch\n  built : {got}\n  expect: "
        f"{rel.sha256_expected}{diag}"
    )


def build_rel(rel: RelDescriptor, cfg: Config, log: Logger) -> Path:
    """Build one REL end-to-end: assemble → link → extract → concat → verify.

    Returns the absolute path of ``build/rel/<name>.rel`` on success.
    Raises ``BuildError`` on any step failure (assembler, linker,
    objcopy, schema mismatch, sha256 mismatch).
    """
    log.info(f"rel {rel.name}: building")
    for part in rel.asm_parts:
        _assemble_rel_part(rel, part, cfg, log)
    _link_rel(rel, cfg, log)
    _extract_rel_text(rel, cfg, log)
    _concat_rel(rel, log)
    _verify_rel_sha256(rel, log)
    return rel.output_rel


def _rel_asm_part_paths(cfg: Config) -> set[Path]:
    """Resolved absolute paths of every REL asm part.

    discover() uses this to keep ``asm/rel/...`` sources out of the
    main-ELF unit list (they get assembled separately by
    build_rel() against a per-REL build_path).
    """
    out: set[Path] = set()
    for rel in cfg.rels:
        for part in rel.asm_parts:
            out.add(part.path.resolve())
    return out


# --------------------------------------------------------------------------- #
# objdiff setup
# --------------------------------------------------------------------------- #
_LD_OBJ_RE = re.compile(r"^\s*(build/[A-Za-z0-9_./-]+\.o)\s*\(", re.MULTILINE)


def _ld_script_objects(
    cfg: Config, carve: Optional[CarveState] = None
) -> list[Path]:
    """Parse the linker script(s) for ``build/<...>.o(<...>)`` entries,
    in declaration order, deduped.  This is the splat-linker-entries-of-
    record.

    When *carve* is not ``None``, the build-time lcf is parsed in place
    of the first entry in ``cfg.linker_scripts`` — the build-time copy
    is the authoritative listing of fragments + carved .o references.
    """
    seen: set[str] = set()
    out: list[Path] = []
    scripts: list[Path] = []
    if carve is not None:
        scripts.append(carve.lcf)
        for ls in cfg.linker_scripts[1:]:
            scripts.append(ROOT / ls)
    else:
        for ls in cfg.linker_scripts:
            scripts.append(ROOT / ls)
    for p in scripts:
        if not p.exists():
            continue
        for match in _LD_OBJ_RE.finditer(p.read_text()):
            obj = match.group(1)
            if obj in seen:
                continue
            seen.add(obj)
            out.append(ROOT / obj)
    return out


def _load_category_map(path: Path) -> dict[int, str]:
    """Reverse `function_categories.json` into {vaddr:int -> category:str}.

    Addresses are stored as upper-hex strings like "0X0017F5D0". Only the
    library subcategories are mapped; everything unlisted is engine.
    """
    if not path.exists():
        return {}
    data = json.loads(path.read_text())
    out: dict[int, str] = {}
    for category, addrs in data.get("categories", {}).items():
        for a in addrs:
            out[int(a, 16)] = category
    return out


# Engine subsystems that earn their own decomp.dev subcategory
# (``engine.<id>``), rendered as a drill-down bar under "Game engine".
# decomp.dev builds the parent/child hierarchy from the dotted id, so a unit
# tagged ``engine.casino`` shows under both the Engine total and a Casino bar.
# Only subsystem folders with enough decompiled TUs to deserve their own bar
# are listed; the smaller folders (camera/gfx/battle/id/ui/sound/player/
# physics) stay bare ``engine`` until they grow. Keep in sync with public.
_ENGINE_SUBSYSTEMS = frozenset({"casino", "enemy", "event", "object", "system"})


def _unit_categories(name: str, lib_categories: dict[str, str]) -> list[str]:
    """Map an objdiff unit name to its objdiff progress category.

    Library / middleware / CRT functions are carved into standalone
    ``asm/nonmatching/<func>`` units (one function each); a unit whose
    carved function is keyed in *lib_categories* gets that function's
    real subcategory (``cri-middleware`` / ``sce-runtime`` / ``crt``).
    A decomp TU under ``src/cod/<subsys>/`` whose subsystem is in
    ``_ENGINE_SUBSYSTEMS`` is tagged both ``engine`` (so it still rolls up to
    the parent) and ``engine.<subsys>`` (its drill-down bar). Every other unit
    (fragments, flat decomp TUs, data, RELs) is ``engine``.
    """
    if name.startswith("asm/nonmatching/"):
        func = name.rsplit("/", 1)[-1]
        cat = lib_categories.get(func)
        if cat:
            return [cat]
    parts = name.split("/")
    if (
        len(parts) >= 4
        and parts[0] == "src"
        and parts[1] == "cod"
        and parts[2] in _ENGINE_SUBSYSTEMS
    ):
        return ["engine", f"engine.{parts[2]}"]
    return ["engine"]


def _objdiff_units(cfg: Config, carve: Optional[CarveState] = None) -> list[dict]:
    """Build the per-unit list for ``objdiff.json`` from splat's linker entries.

    Each unit names one ``build/<...>.o``; the unit's ``base_path`` (our
    build output) lives under ``build/``, the ``target_path`` (the reference
    object we score against) under ``expected/build/``.  Both are written as
    repo-relative POSIX paths.  ``metadata.auto_generated = True`` keeps each
    auto-emitted unit out of the GUI sidebar but in the totals — they exist
    so the objdiff report can see *all* of `.text`, not so a human navigates
    them.  When a unit transitions to a hand-decompiled C TU, that
    unit gets a real entry written by hand and the auto-emitted asm entry
    is dropped from this list at the same time.

    Per-REL units are appended in declaration order after the
    main-ELF units.  Each REL's asm parts contribute one unit each
    (currently 1/REL while only r207 is wired).  REL units carry an
    extra ``metadata.rel = <name>`` tag so later tooling can distinguish
    them from main-ELF units when navigating the units list.
    """
    objdiff_cfg = cfg.objdiff_cfg
    target_root = Path(objdiff_cfg["target_dir"])  # repo-relative
    base_root = Path(objdiff_cfg["base_dir"])      # repo-relative
    build_root = Path(cfg.raw["build_dir"])        # repo-relative
    units: list[dict] = []
    cat_map = _load_category_map(ROOT / "progress" / "function_categories.json")
    lib_categories = {
        e.name: cat_map.get(e.vaddr, "engine")
        for e in (carve.entries if carve else [])
        if e.lib
    }
    for obj in _ld_script_objects(cfg, carve):
        rel = obj.relative_to(ROOT / build_root)
        name = str(rel.with_suffix("")).replace(os.sep, "/")
        units.append(
            {
                "name": name,
                "target_path": (target_root / rel).as_posix(),
                "base_path": (base_root / rel).as_posix(),
                "metadata": {
                    "auto_generated": True,
                    "progress_categories": _unit_categories(name, lib_categories),
                },
            }
        )
    # Per-REL units: one per asm part. The REL .o lives under
    # build/rel/<name>/asm/rel/<name>/<src>.o (rel.build_path is the
    # build-root prefix, and rel.asm_obj_path() emits the full path).
    # base_path / target_path are derived by re-rooting under the
    # objdiff base/target dirs the same way as main-ELF units.
    for rel_desc in cfg.rels:
        for part in rel_desc.asm_parts:
            obj = rel_desc.asm_obj_path(part)
            # The REL's build_path is a subdir of the main build root
            # (build/rel/<name>); rel-to-build-root preserves the
            # ``rel/<name>/asm/rel/<name>/<src>`` suffix so target/base
            # mirror cleanly.
            obj_rel = obj.relative_to(ROOT / build_root)
            rel_name = str(obj_rel.with_suffix("")).replace(os.sep, "/")
            units.append(
                {
                    "name": rel_name,
                    "target_path": (target_root / obj_rel).as_posix(),
                    "base_path": (base_root / obj_rel).as_posix(),
                    "metadata": {
                        "auto_generated": True,
                        "rel": rel_desc.name,
                        "progress_categories": _unit_categories(rel_name, lib_categories),
                    },
                }
            )
    return units


def _mirror_expected(
    units: list[dict], log: Logger, *, force: Optional[set[str]] = None
) -> tuple[int, int, int]:
    """For each unit, copy ``base_path`` -> ``target_path`` if and only if the
    target does not yet exist.  Pinning semantics: once an expected `.o` is
    on disk it represents the splat-disasm baseline taken at hand-off time
    and must never be silently overwritten — progress against it is the
    whole point.

    *force* is an optional set of ``base_path`` strings (matched verbatim
    against ``u["base_path"]``) whose target the caller wants overwritten
    regardless of pinning.  Used by ``--reseed-expected`` to atomically
    refresh the carve pair (fragment .o(s) + the new carved .o).
    Returns ``(copied, skipped, forced)``.

    The base `.o`s must already exist (call after a build).  Missing base
    files raise ``BuildError`` so the caller doesn't silently produce a
    half-populated expected tree.
    """
    force = force or set()
    copied = 0
    skipped = 0
    forced = 0
    for u in units:
        base = ROOT / u["base_path"]
        target = ROOT / u["target_path"]
        if not base.exists():
            raise BuildError(
                f"objdiff setup: base object {u['base_path']} missing; "
                f"run `python compile.py` first"
            )
        if u["base_path"] in force:
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(base, target)
            forced += 1
            continue
        if target.exists():
            skipped += 1
            continue
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(base, target)
        copied += 1
    msg = (
        f"expected/build mirror: {copied} copied, {skipped} preserved "
        f"(never overwriting an existing expected .o)"
    )
    if forced:
        msg += f", {forced} force-reseeded"
    log.info(msg)
    return copied, skipped, forced


def do_objdiff_setup(cfg: Config, log: Logger) -> Path:
    """Write ``objdiff.json`` and ensure ``expected/build/`` is populated.

    Steps, in order:

    1. Build every compile unit so ``build/<unit>.o`` exists.  Cheap
       (~5 s with 8 workers); a no-op if everything is already up to
       date.  We deliberately don't link — objdiff scores `.o`s, not the
       final ELF, so the link step would just slow setup down.
    2. Mirror ``build/<unit>.o`` -> ``expected/build/<unit>.o`` for any
       unit whose expected `.o` is missing (see ``_mirror_expected``).
    3. Write ``objdiff.json`` from the in-config schema settings plus
       the auto-emitted per-unit list.

    Modelled after recvx-decomp's ``compile.py::do_objdiff_setup``,
    adapted to our asm-only baseline: there is no separate
    "compile expected .s" step because the expected `.o` *is* the base
    `.o` for INCLUDE_ASM units — freezing a copy is the contract.
    """
    # 1. Build.
    carve = maybe_carve(cfg, log)
    units = discover(cfg, carve)
    log.info(
        f"objdiff setup: ensuring {len(units)} compile units are built"
    )
    _compile_many(units, cfg, log, jobs=DEFAULT_PARALLELISM)

    # 1b. Build every REL so its per-`.o` files (+ the .rel) exist for
    # the mirror step. Cheap (~1 s/REL today); a no-op if everything is
    # already up to date.
    for rel_desc in cfg.rels:
        build_rel(rel_desc, cfg, log)

    # 2 & 3. Mirror expected, then write objdiff.json.
    objdiff_cfg = cfg.objdiff_cfg
    unit_entries = _objdiff_units(cfg, carve)
    _mirror_expected(unit_entries, log)

    out: dict = {
        "min_version": objdiff_cfg.get("min_version", "2.0.0"),
        "name": objdiff_cfg.get("name", "god-hand-decomp"),
        "custom_make": objdiff_cfg.get("custom_make", "python"),
        "custom_args": list(
            objdiff_cfg.get("custom_args", ["compile.py", "--single-file"])
        ),
        "build_target": bool(objdiff_cfg.get("build_target", True)),
        "watch_patterns": list(objdiff_cfg.get("watch_patterns", [])),
        "progress_categories": list(objdiff_cfg.get("progress_categories", [])),
        "units": unit_entries,
    }
    # Per-version objdiff project: us writes the repo-root objdiff.json (the
    # default); a version may write config/<ver>/objdiff.json so the projects
    # don't clobber each other.  The unit paths are version-namespaced
    # (asm/<ver>/... vs asm/cod/...), so they share one expected/build/ tree.
    #
    # `objdiff-cli report generate -p <dir>` resolves unit paths relative to the
    # project *directory*, so when the project file is not at the repo root we
    # rebase the (repo-relative) unit paths to be relative to that directory.
    # _mirror_expected above already ran against the repo-relative paths.
    path = ROOT / objdiff_cfg.get("objdiff_project", "objdiff.json")
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.parent != ROOT:
        base = path.parent
        for u in out["units"]:
            u["target_path"] = os.path.relpath(ROOT / u["target_path"], base).replace(os.sep, "/")
            u["base_path"] = os.path.relpath(ROOT / u["base_path"], base).replace(os.sep, "/")
    path.write_text(json.dumps(out, indent=2) + "\n")
    log.info(f"wrote {path.relative_to(ROOT)} ({len(unit_entries)} units)")
    return path


# --------------------------------------------------------------------------- #
# Reseed expected (carve pair, atomic)
# --------------------------------------------------------------------------- #
def do_reseed_expected(name: str, cfg: Config, log: Logger) -> None:
    """Atomically refresh the expected/build mirror for the carve pair
    associated with ``name``.

    "Pair" is plural: every monolithic fragment .o plus the
    new per-function carved .o is overwritten in lock-step.  Single-sided
    reseed is rejected by this function — if you want to reseed *only*
    the carved .o you almost certainly have a bug: the fragmentation
    boundary likely just shifted, which means all monolithic fragments
    also changed.

    Preconditions:
      * ``name`` appears in ``compile_config.json::carved_funcs``
        (i.e. the carve has been declared in config).
      * The build succeeds end-to-end (re-run internally; cheap).

    Postconditions:
      * Every ``build/asm/cod/000000.partN.o`` has its
        ``expected/build/...`` mirror overwritten with the current bytes.
      * ``build/asm/nonmatching/<name>.o`` has its mirror overwritten too.
      * ``objdiff.json`` is regenerated (the per-unit list may have grown
        relative to the previous run).
      * No other ``expected/build/*.o`` is touched — pinning is preserved
        for every non-carve-related unit.
    """
    # REL name short-circuit: ``--reseed-expected r207`` means "rebuild
    # r207 and force-mirror every per-`.o` of that REL". REL names are
    # mutually exclusive with carve function names by convention; if a
    # collision ever appears, the REL branch wins and the user must use
    # a different carve name.
    rels_by_name = {r.name: r for r in cfg.rels}
    if name in rels_by_name:
        do_reseed_expected_rel(rels_by_name[name], cfg, log)
        return

    carve = maybe_carve(cfg, log)
    if carve is None:
        raise BuildError(
            "--reseed-expected requires a non-empty carved_funcs (or a "
            "declared REL name) in compile_config.json; nothing to reseed."
        )
    if name not in carve.carved_sources:
        carved_names = sorted(carve.carved_sources)
        rel_names = sorted(rels_by_name)
        raise BuildError(
            f"--reseed-expected: {name!r} is not in carved_funcs nor in "
            f"rels; declared carves are {carved_names}, RELs are {rel_names}."
        )

    # Rebuild end-to-end so the .o files we mirror are fresh.
    units = discover(cfg, carve)
    log.info(f"reseed: rebuilding {len(units)} compile units")
    _compile_many(units, cfg, log, jobs=DEFAULT_PARALLELISM)
    link(units, cfg, log, carve)

    # Identify the carve pair: all fragment .o + this carve's link-time .o
    # (the C TU's .o when the carve has `tu` set, the standalone carved .o
    # otherwise; carve_link_obj_rel encapsulates that selection so the
    # mirror set matches whatever the lcf wires in).
    fragment_base_paths = {
        p.with_suffix(".o").relative_to(ROOT).as_posix()
        for p in carve.fragment_sources
    }
    carved_obj_rel = carve.carve_link_obj_rel(name)
    force = fragment_base_paths | {carved_obj_rel}

    unit_entries = _objdiff_units(cfg, carve)
    _, _, forced = _mirror_expected(unit_entries, log, force=force)
    if forced != len(force):
        # Should never happen because the unit list is derived from the
        # same lcf the carve state generated; flag loudly if it does.
        raise BuildError(
            f"reseed: expected to force {len(force)} units but only {forced} "
            f"matched in objdiff.json; mismatch between lcf and carve state."
        )

    # Regenerate objdiff.json (units list may have grown).
    objdiff_cfg = cfg.objdiff_cfg
    out: dict = {
        "min_version": objdiff_cfg.get("min_version", "2.0.0"),
        "name": objdiff_cfg.get("name", "god-hand-decomp"),
        "custom_make": objdiff_cfg.get("custom_make", "python"),
        "custom_args": list(
            objdiff_cfg.get("custom_args", ["compile.py", "--single-file"])
        ),
        "build_target": bool(objdiff_cfg.get("build_target", True)),
        "watch_patterns": list(objdiff_cfg.get("watch_patterns", [])),
        "progress_categories": list(objdiff_cfg.get("progress_categories", [])),
        "units": unit_entries,
    }
    (ROOT / "objdiff.json").write_text(json.dumps(out, indent=2) + "\n")
    log.info(
        f"reseed: atomic refresh of {len(force)} expected .o(s) complete "
        f"({len(fragment_base_paths)} fragment(s) + 1 carved); "
        f"objdiff.json regenerated."
    )


def do_reseed_expected_rel(
    rel_desc: RelDescriptor, cfg: Config, log: Logger
) -> None:
    """Atomically refresh ``expected/build/rel/<name>/...`` for one REL.

    Sibling of ``do_reseed_expected`` for the per-REL .o mirror.
    Rebuilds the REL end-to-end (re-asserting the on-disc sha256 along
    the way so a reseed can't silently propagate a byte-mismatched .o
    into the expected mirror), then force-mirrors every per-`.o` output
    the REL produces. ``objdiff.json`` is regenerated so the per-REL
    units list is in sync.

    Preconditions:
      * ``rel_desc.name`` appears in ``compile_config.json::rels``.
      * The REL build succeeds end-to-end and sha256-matches.

    Postconditions:
      * Every ``build/rel/<name>/asm/rel/<name>/<src>.o`` has its
        ``expected/build/...`` mirror overwritten with the current bytes.
      * ``build/rel/<name>.rel`` is on disk and sha256-matches retail.
      * ``objdiff.json`` is regenerated.
      * No main-ELF expected `.o` is touched.
    """
    log.info(f"reseed[rel:{rel_desc.name}]: rebuilding REL")
    build_rel(rel_desc, cfg, log)

    # Force-mirror set: every per-`.o` produced by this REL.
    base_paths = {
        rel_desc.asm_obj_path(p).relative_to(ROOT).as_posix()
        for p in rel_desc.asm_parts
    }

    carve = maybe_carve(cfg, log)
    unit_entries = _objdiff_units(cfg, carve)
    _, _, forced = _mirror_expected(unit_entries, log, force=base_paths)
    if forced != len(base_paths):
        raise BuildError(
            f"reseed[rel:{rel_desc.name}]: expected to force "
            f"{len(base_paths)} units but only {forced} matched in "
            f"objdiff.json; mismatch between rel descriptor and units list."
        )

    # Regenerate objdiff.json (the REL units list lives there too).
    objdiff_cfg = cfg.objdiff_cfg
    out: dict = {
        "min_version": objdiff_cfg.get("min_version", "2.0.0"),
        "name": objdiff_cfg.get("name", "god-hand-decomp"),
        "custom_make": objdiff_cfg.get("custom_make", "python"),
        "custom_args": list(
            objdiff_cfg.get("custom_args", ["compile.py", "--single-file"])
        ),
        "build_target": bool(objdiff_cfg.get("build_target", True)),
        "watch_patterns": list(objdiff_cfg.get("watch_patterns", [])),
        "progress_categories": list(objdiff_cfg.get("progress_categories", [])),
        "units": unit_entries,
    }
    (ROOT / "objdiff.json").write_text(json.dumps(out, indent=2) + "\n")
    log.info(
        f"reseed[rel:{rel_desc.name}]: atomic refresh of "
        f"{len(base_paths)} expected .o(s) complete; objdiff.json regenerated."
    )


# --------------------------------------------------------------------------- #
# Clean
# --------------------------------------------------------------------------- #
def do_clean(cfg: Config, log: Logger) -> None:
    build = cfg.build_dir
    if not build.exists():
        log.info("build/ does not exist, nothing to clean")
        return
    preserve = {build / name for name in cfg.preserve_in_build}
    removed = 0
    for child in list(build.iterdir()):
        if child in preserve:
            continue
        if child.is_dir():
            shutil.rmtree(child)
        else:
            child.unlink()
        removed += 1
    log.info(f"removed {removed} entries from build/ (preserved: "
             f"{', '.join(sorted(p.name for p in preserve)) or '(none)'})")


def _resolve_single_file_targets(
    target: Path,
    carve: Optional[CarveState],
    units: list[CompileUnit],
    log: Logger,
) -> list[CompileUnit]:
    """Map a user-supplied source path to the CompileUnit(s) to rebuild.

    The carved layout introduces three source-tree views the user can
    legitimately name:

    1. **A direct unit source** (e.g. ``src/cod/000000.c``,
       ``asm/data/cod/2BBF80.data.s``, ``build/asm/cod/000000.part0.s``):
       return exactly that unit.  This covers C TUs, non-carved asm,
       and the build-time fragments produced by ``maybe_carve``.
    2. **The carved-out monolithic** (``asm/cod/000000.s`` when a carve
       is active): the monolithic no longer maps to a single .o because
       ``maybe_carve`` shattered it into N+1 fragments under
       ``build/asm/cod/000000.partN.s``.  Build all fragments so the
       user's mental model ("I edited the monolithic, rebuild it")
       keeps working.
    3. **A TU-owned carved .s** (``build/asm/nonmatching/<name>.s`` when
       its carve entry has ``tu``): the bytes are pulled into the C TU
       via ``INCLUDE_ASM`` and the standalone .o is intentionally not
       built.  Remap to the owning C TU so editing the carved asm and
       rebuilding produces the .o that actually goes through the link.

    Anything else is a clear error with a hint at the supported roots.
    """
    by_src = {u.src: u for u in units}
    if target in by_src:
        return [by_src[target]]

    if carve is not None:
        if target == carve.original_unit_src.resolve():
            frag_units = [u for u in units
                          if u.src in {fp.resolve() for fp in carve.fragment_sources}]
            if not frag_units:
                # Should not happen: discover() always emits the fragments
                # when carve is non-None.  Treat as a programming error.
                raise BuildError(
                    f"--single-file: carve is active but no fragments are"
                    f" in the unit list (internal invariant violated)")
            log.info(
                f"--single-file: {target.relative_to(ROOT)} is carved into"
                f" {len(frag_units)} fragment(s); rebuilding all of them"
            )
            return frag_units

        for name, cp in carve.carved_sources.items():
            if target != cp.resolve():
                continue
            if not carve.is_tu_owned(name):
                # Non-TU carve: the standalone .o is in the unit list,
                # so the direct-match branch above already returned it.
                # If we got here something has drifted; fall through to
                # the error.
                break
            entry = carve.entry_by_name(name)
            tu_src = (ROOT / entry.tu).resolve()  # type: ignore[arg-type]
            tu_unit = by_src.get(tu_src)
            if tu_unit is None:
                raise BuildError(
                    f"--single-file: carved {name!r} is owned by TU {entry.tu!r}"
                    f" but that TU is not in the discovered unit list")
            log.info(
                f"--single-file: {target.relative_to(ROOT)} is INCLUDE_ASM'd"
                f" by {entry.tu}; rebuilding the owning TU"
            )
            return [tu_unit]

    rel_hint = target
    try:
        rel_hint = target.relative_to(ROOT)
    except ValueError:
        pass
    raise BuildError(
        f"--single-file: {rel_hint} is not a tracked source. "
        f"Pass a path under src/, asm/, build/asm/cod/000000.partN.s, "
        f"or the carved-out asm/cod/000000.s."
    )


def do_single_file(target_arg: Path, cfg: Config, log: Logger) -> None:
    """Rebuild exactly one source's .o (no link).  Honours the carving
    pre-build step so the unit list is consistent with the full build.
    """
    target = target_arg.resolve()
    if not target.exists():
        raise BuildError(f"--single-file: path does not exist: {target_arg}")
    if target.is_dir():
        raise BuildError(f"--single-file: path is a directory, not a source file: {target_arg}")

    # maybe_carve() rewrites build/asm/cod/000000.partN.s + carved .s
    # files from the current monolithic and returns a CarveState the
    # unit-list builder needs.  Sharing this call with the full-build
    # path (below) guarantees the single-file rebuild sees the same
    # unit topology, so a follow-up full link won't disagree with the
    # standalone .o this run produced.
    carve = maybe_carve(cfg, log)
    units = discover(cfg, carve)
    matches = _resolve_single_file_targets(target, carve, units, log)
    for m in matches:
        compile_unit(m, cfg, log)
        log.info(f"built {m.obj.relative_to(ROOT)}")


# --------------------------------------------------------------------------- #
# Main
# --------------------------------------------------------------------------- #
def parse_args(argv: list[str]) -> argparse.Namespace:
    p = argparse.ArgumentParser(
        prog="compile.py",
        description="Build the God Hand matching-decomp main ELF.",
    )
    p.add_argument(
        "--version",
        type=str,
        default=None,
        metavar="KEY",
        help="which release to build (version key from config/versions.json). "
             "Default: the registry's 'default' version (us).",
    )
    p.add_argument(
        "--config",
        type=Path,
        default=None,
        help="explicit compile_config.json path; overrides --version "
             "(default: resolved from config/versions.json)",
    )
    p.add_argument("--setup", action="store_true",
                   help="write objdiff.json from splat linker entries and exit")
    p.add_argument("--clean", action="store_true",
                   help="remove owned build artifacts and exit")
    p.add_argument("--single-file", type=Path, default=None,
                   help="compile/assemble exactly this one source and exit (no link)")
    p.add_argument("--reseed-expected", type=str, default=None, metavar="NAME",
                   help="atomically reseed expected/build/ for the carve pair "
                        "associated with NAME (a function in carved_funcs) and exit; "
                        "plural — reseeds every monolithic fragment .o "
                        "plus the carved .o in one operation. NAME may also be a "
                        "REL name from compile_config.json::rels, in which case the "
                        "REL's per-`.o` mirror is refreshed instead.")
    p.add_argument("--rel", type=str, default=None, metavar="NAME",
                   help="build only the named REL (a name from "
                        "compile_config.json::rels) and exit; analogous to "
                        "--single-file for the per-REL pipeline. Skips "
                        "the main-ELF build entirely.")
    p.add_argument("--verbose", action="store_true",
                   help="serial build, full command echo")
    p.add_argument("--jobs", "-j", type=int, default=DEFAULT_PARALLELISM,
                   help="parallel compile workers when not --verbose (default: %(default)s)")
    p.add_argument("--no-link", action="store_true",
                   help="compile sources but skip the final link step")
    return p.parse_args(argv)


def _compile_many(units: list[CompileUnit], cfg: Config, log: Logger, jobs: int) -> None:
    if log.verbose or jobs <= 1:
        for u in units:
            compile_unit(u, cfg, log)
        return
    errors: list[BaseException] = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = {pool.submit(compile_unit, u, cfg, log): u for u in units}
        done = 0
        total = len(futures)
        for fut in concurrent.futures.as_completed(futures):
            u = futures[fut]
            try:
                fut.result()
            except BaseException as exc:  # noqa: BLE001
                errors.append(exc)
                log.warn(f"{u.rel}: {exc}")
            done += 1
            if total >= 4 and done % max(1, total // 10) == 0:
                log.info(f"  [{done}/{total}] units done")
    if errors:
        raise BuildError(f"{len(errors)} unit(s) failed to compile")


def main(argv: list[str]) -> int:
    args = parse_args(argv)
    log = Logger(verbose=args.verbose)
    try:
        config_path = resolve_config_path(args.version, args.config)
    except BuildError as exc:
        log.error(str(exc))
        return 2
    cfg = Config.load(config_path)

    try:
        if args.clean:
            do_clean(cfg, log)
            return 0

        if args.setup:
            do_objdiff_setup(cfg, log)
            return 0

        if args.reseed_expected is not None:
            do_reseed_expected(args.reseed_expected, cfg, log)
            return 0

        if args.single_file is not None:
            do_single_file(args.single_file, cfg, log)
            return 0

        if args.rel is not None:
            rels_by_name = {r.name: r for r in cfg.rels}
            if args.rel not in rels_by_name:
                rel_names = sorted(rels_by_name)
                raise BuildError(
                    f"--rel: {args.rel!r} is not in compile_config.json::rels; "
                    f"declared RELs are {rel_names}."
                )
            build_rel(rels_by_name[args.rel], cfg, log)
            return 0

        carve = maybe_carve(cfg, log)
        units = discover(cfg, carve)
        log.info(f"discovered {len(units)} compile units "
                 f"(asm={sum(1 for u in units if u.kind == 'asm')}, "
                 f"c={sum(1 for u in units if u.kind == 'c')}, "
                 f"vsm={sum(1 for u in units if u.kind == 'vsm')})")
        _compile_many(units, cfg, log, args.jobs)

        if args.no_link:
            log.info("skipping link (--no-link)")
            return 0

        out = link(units, cfg, log, carve)
        size = out.stat().st_size
        log.info(f"linked {out.relative_to(ROOT)} ({size} bytes)")

        # Every configured REL is built alongside the main ELF in
        # the default path. RELs are independent of the main link — they
        # produce ``build/rel/<name>.rel`` whose sha256 must equal the
        # AFS-extracted retail bytes (sha256_expected in the schema). A
        # REL build failure raises BuildError just like any other stage,
        # so the ratchet covers REL output the same way it covers main-
        # ELF output (per scripts/checks/rel.sh).
        for rel_desc in cfg.rels:
            build_rel(rel_desc, cfg, log)

        return 0

    except BuildError as exc:
        log.warn(str(exc))
        return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
