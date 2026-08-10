#!/usr/bin/env python3
"""scripts/carver.py — shared carving primitives for on-demand carving.

Two seams:

- **CarveSchema**: pure data types + parse/split/size functions. No
  file I/O, no mutation. The schema-side contract that
  `compile.py::maybe_carve` consumes at build time.
- **CarveSession**: stateful single-function carve + atomic rollback.
  Lands in Phase 2 (this file is Phase 1: the schema half).

Phase 1 moves the schema-side surface here from `compile.py` while
preserving behaviour exactly. `compile.py` re-exports the moved
symbols so existing call sites and tests continue to work without
import changes. Phase 3 drops the re-export shim after callers
migrate to importing from `scripts.carver` directly.

`BuildError` was moved from `compile.py` to here because the moved
helpers raise it. `compile.py` re-exports it; existing
`pytest.raises(cm.BuildError, ...)` assertions continue to match.
The name is preserved (not renamed to `CarveError`) to keep the
behaviour-preserving Phase 1 cut clean — a separate naming-pass can
rename it later if a future review wants. Other `compile.py` raises
of `BuildError` (e.g. unknown compiler, malformed part lists) work
unchanged via the re-export.

Schema reference:
- `CarveEntry` — frozen dataclass for one `compile_config.json::carved_funcs[]`
  entry.
- `CarveState` — frozen dataclass for the post-split build-time state
  (fragments + carve files + lcf).
- `CarveSchema.parse_entries(cfg)` — JSON-dict-array → list[CarveEntry].
- `CarveSchema.split_monolithic(text, names)` — pure text split: monolithic
  .s text + carve-target names → (fragments, carved, ranges).
- `CarveSchema.carve_unit_size_bytes(carved_text)` — carve unit byte size
  for LCF location-counter advance.
"""
from __future__ import annotations

import contextlib
import dataclasses
import json
import os
import re
from pathlib import Path
from typing import Iterator, Optional, TYPE_CHECKING

if TYPE_CHECKING:
    # compile.Config is forward-referenced in `CarveSchema.parse_entries`
    # for type-only purposes; runtime imports use duck typing on the
    # `.carved_funcs` attribute to avoid a circular import.
    from compile import Config  # noqa: F401

# `ROOT` matches the project-root convention used by the other
# `scripts/` tools (`Path(__file__).resolve().parent.parent`).
# `compile.py` uses `Path(__file__).resolve().parent` because it sits
# at the repo root.
ROOT = Path(__file__).resolve().parent.parent


# --------------------------------------------------------------------------- #
# BuildError — moved from compile.py
# --------------------------------------------------------------------------- #


class BuildError(RuntimeError):
    """Raised for build-pipeline configuration or carving errors.

    Moved from `compile.py` to `scripts/carver.py` in Phase 1 of the
    carver-module split because the schema-side carve helpers
    (`_index_functions`, `_preamble_end_index`, `_split_monolithic`,
    `CarveState.entry_by_name`) raise it. `compile.py` re-exports it so
    existing call sites and `pytest.raises(cm.BuildError, ...)`
    assertions continue to work.

    The name `BuildError` (rather than a carver-specific
    `CarveError`) is preserved for Phase 1 to keep the cut clean
    behaviour-preserving; renaming is a separate later concern if
    a future review wants it.
    """


class CarveError(Exception):
    """Raised by the session-half carve primitives
    (`_capture_auto_carve_snapshot`, `_revert_auto_carve`,
    `_atomic_auto_carve`, `_auto_carve_uncarved`, `CarveSession`).

    An earlier refactor moved these primitives here into
    `scripts/carver.py`. The original raises used the caller's error
    type; the moved code uses `CarveError` instead. The caller's
    wrap-sites around `_atomic_auto_carve` / `_auto_carve_uncarved` were
    updated to catch both error types; `scripts/auto_carve_func.py`
    catches `CarveError` directly.

    A sibling error type, not a subclass: each module owns its own error
    vocabulary (a module owning its own schema error).
    """


# --------------------------------------------------------------------------- #
# Carving asm regex constants — moved from compile.py
# --------------------------------------------------------------------------- #


_GLABEL_RE = re.compile(r"^\s*glabel\s+(\S+)")
_ENDLABEL_RE = re.compile(r"^\s*endlabel\s+(\S+)")
_NONMATCHING_RE = re.compile(r"^\s*nonmatching\s+(\S+),")
_ALIGN3_RE = re.compile(r"^\s*\.align\s+3\s*$")
_ALABEL_LIKE_RE = re.compile(r"^\s*(alabel|jlabel|ehlabel)\s+(\S+)")
# Instruction line in a splat-disassembled carve fragment:
#   ``    /* FILE_OFF HEX_VRAM HEX_BYTES */  insn ...``
# Each match contributes 4 bytes to the carve unit's .text size.
# Used by ``CarveSchema.carve_unit_size_bytes`` /
# ``_carve_unit_size_bytes`` — the LCF location-counter fix needs to
# know each carve's effective byte size so the trailing-pad nop bytes
# don't get lost when a C TU integrates a body smaller than the full
# carve unit.
_INSN_LINE_RE = re.compile(
    r"^\s*/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s*\*/"
)


# --------------------------------------------------------------------------- #
# ee-as GPR compatibility — moved from compile.py
# --------------------------------------------------------------------------- #
#
# Map symbolic MIPS GPR names → numeric. ee-as 2.10 (the SCE PS2 SDK's
# 2000-vintage GNU `as`) only accepts numeric GPR names ($0..$31); the
# splat-emitted asm uses ABI symbolic names ($ra, $sp, $v0, ...). Modern
# `mipsel-linux-gnu-as` (used on the monolithic fragments) accepts both,
# so this translation is applied ONLY to carved per-function .s files
# (which feed ee-as via INCLUDE_ASM from a C TU).
#
# FP registers ($f0..$f31) and integer-register numerics already work in
# both assemblers and are untouched. Coprocessor / control registers
# ($lo, $hi, $fcc0, ...) appear only as implicit operands of mflo/mfhi/etc.,
# not as written-out tokens, so no mapping needed.

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


def _eeas_compat_registers(text: str) -> str:
    """Rewrite ABI-symbolic GPR names to numeric for ee-as compatibility.

    See ``_EEAS_GPR_NAME_MAP`` above for rationale. Pure function;
    operates on a single .s file's text.
    """
    return _EEAS_GPR_RE.sub(
        lambda m: "$" + _EEAS_GPR_NAME_MAP[m.group(1)], text
    )


# --------------------------------------------------------------------------- #
# Value types — moved from compile.py
# --------------------------------------------------------------------------- #
#
# `compile_config.json::carved_funcs[]` schema (every entry one
# function carved out of the monolithic asm/cod/000000.s):
#
#     {"name": "func_00100000", "unit": "asm/cod/000000",
#      "vaddr": "0x00100000", "size": 8, "tu": "src/cod/000000.c"}
#
# `_comment`-only entries are pure documentation: they record
# functions that deliberately stay in the monolithic asm — e.g.
# PERMANENT carves whose local labels are referenced by rodata jump
# tables, which carving would orphan. They are skipped by
# `CarveSchema.parse_entries`.
#
# target must name a `glabel`-defined symbol. alabel/jlabel/ehlabel
# names are not eligible carve roots and will be rejected by
# `_split_monolithic` with "function not present in monolithic".


@dataclasses.dataclass(frozen=True)
class CarveEntry:
    name: str       # symbol name, e.g. "func_00100000"
    unit: str       # source-tree path without suffix, e.g. "asm/cod/000000"
    vaddr: int      # retail virtual address (informational)
    size: int       # function size in bytes (must equal `nonmatching` marker)
    tu: Optional[str] = None  # owning C TU, e.g. "src/cod/000000.c".  When
                              # set, the standalone build/asm/nonmatching/
                              # <name>.o is NOT assembled or linked; the C
                              # TU's .o contains the function bytes via
                              # INCLUDE_ASM, and the lcf-replacement uses
                              # the TU's .o path at the carve slot.
                              # When None, the standalone .o is linked
                              # directly (useful for asm-only carves with
                              # no C wrapper yet).
    lib: bool = False         # True => library/middleware/CRT carve; the
                              # standalone asm/nonmatching/<name> unit is
                              # tagged progress_categories=["library"].


@dataclasses.dataclass(frozen=True)
class CarveState:
    """Output of the carve pre-build step when carved_funcs is non-empty.

    Empty carved_funcs returns ``None`` instead of a CarveState; callers
    must treat the original asm/cod/000000.s as the baseline unit.
    """
    # Original-unit handle: which source-tree .s was carved.
    original_unit_src: Path             # absolute path to asm/cod/000000.s
    original_unit_rel: Path             # repo-relative
    # Build-time files produced by carving.
    fragment_sources: list[Path]        # build/asm/cod/000000.partN.s, in order
    carved_sources: dict[str, Path]     # {name: build/asm/nonmatching/<name>.s}
    entries: list[CarveEntry]
    # Build-time linker script (a copy of the committed lcf with the
    # monolithic .o reference replaced by the fragment+carve list).
    lcf: Path

    @property
    def all_monolithic_objs(self) -> list[Path]:
        """All .o files produced from the monolithic (= every fragment).
        ``--reseed-expected`` reseeds all of these atomically per ADR.
        """
        return [p.with_suffix(".o").resolve() for p in self.fragment_sources]

    def carve_link_obj_rel(self, name: str) -> str:
        """Return the carve's link-time .o as a repo-relative POSIX path.

        When the carve has a ``tu``, this is the C TU's .o under ``build/``
        (``src/cod/000000.c`` -> ``build/src/cod/000000.o``); otherwise the
        standalone ``build/asm/nonmatching/<name>.o``.

        This is the path the lcf-replacement places at the carve slot and
        the path ``--reseed-expected`` mirrors into ``expected/build/``.
        """
        entry = self.entry_by_name(name)
        if entry.tu:
            tu_rel = Path(entry.tu)
            return (Path("build") / tu_rel.with_suffix(".o")).as_posix()
        return (
            self.carved_sources[name]
            .with_suffix(".o")
            .relative_to(ROOT)
            .as_posix()
        )

    def entry_by_name(self, name: str) -> CarveEntry:
        for e in self.entries:
            if e.name == name:
                return e
        raise BuildError(f"carve: no entry for {name!r}")

    def is_tu_owned(self, name: str) -> bool:
        return bool(self.entry_by_name(name).tu)


# --------------------------------------------------------------------------- #
# Pure helpers — moved from compile.py
# --------------------------------------------------------------------------- #


def is_doc_record(raw) -> bool:
    """True when a ``compile_config.json`` array element is documentation.

    The convention across every documented array in ``compile_config.json``
    (``carved_funcs``, ``rels``, ``compile_units``) is that a documentation
    record carries **no** ``name`` key. The prose block sits at top level
    (``_carved_funcs_doc``, ``_rels_doc``); the in-array markers are
    ``{"_comment": "..."}`` — 13 of them in ``carved_funcs`` today, each
    recording why a function deliberately stays in the monolithic asm.

    A non-dict element is documentation-shaped too: it carries no data this
    schema can read, so it is skipped here rather than crashing a caller.

    **Do not test ``name.startswith("_")``.** That prefix test is the
    defect ticket 36 removes. It silently discarded 50 real library carves
    (8,548 B) whose C identifier legitimately begins with an underscore —
    ``_IO_adjust_column``, ``__rtti_class``, ``__7filebuf``, ``_InitAlarm``,
    the C++ operator mangles ``__ls__7ostreamc`` … Those entries parsed,
    passed every validation, and then produced no LCF slot, no carve unit
    and no objdiff unit. `_parse_carved_entries` below has always used the
    ``name``-key test and never had the defect.

    One caller-visible consequence: an entry that **has** a ``name`` key
    whose value is empty is no longer silently dropped. It is data, it is
    malformed, and the caller raises.
    """
    if not isinstance(raw, dict):
        return True
    return "name" not in raw


def _parse_carved_entries(cfg) -> list[CarveEntry]:
    """JSON-dict-array → list[CarveEntry].

    Internal name preserved for the Phase 1 re-export shim in
    `compile.py`. Public surface is `CarveSchema.parse_entries`.

    Duck-typed on `cfg.carved_funcs` to avoid a circular import on
    `compile.Config`.
    """
    raw_entries = cfg.carved_funcs
    out: list[CarveEntry] = []
    for raw in raw_entries:
        # Skip pure-documentation entries: _comment-only markers record
        # that a function deliberately stays in the monolithic asm —
        # e.g. PERMANENT carves whose local labels are referenced by
        # rodata jump tables, which carving would orphan.
        if is_doc_record(raw):
            continue
        name = raw["name"]
        unit = raw["unit"]
        vaddr_raw = raw["vaddr"]
        size = int(raw["size"])
        tu_raw = raw.get("tu")
        tu = str(tu_raw) if tu_raw else None
        lib = bool(raw.get("lib", False))
        if isinstance(vaddr_raw, str):
            vaddr = int(vaddr_raw, 16) if vaddr_raw.lower().startswith("0x") else int(vaddr_raw, 0)
        else:
            vaddr = int(vaddr_raw)
        out.append(CarveEntry(name=name, unit=unit, vaddr=vaddr, size=size, tu=tu, lib=lib))
    return out


def _index_functions(lines: list[str]) -> dict[str, tuple[int, int, int]]:
    """Return ``{name: (block_start, glabel_line, block_end_inclusive)}``
    indexed by 0-based line numbers.

    * ``block_start`` is the line index of the leading ``.align 3``
      directive (the upper boundary of the carve unit), or the line
      index of the ``glabel`` itself if no ``.align 3`` immediately
      precedes it.
    * ``glabel_line`` is the index of the ``glabel <name>`` line.
    * ``block_end_inclusive`` is the line index immediately *before*
      the next function's ``block_start`` (or ``len(lines) - 1`` for the
      last function).  This swallows the inter-function pad nop(s) +
      trailing blanks into the previous function's carve unit so
      fragments start cleanly on a function-aligned boundary; see the
      header comment above for the alignment rationale.

    The upward-walker for ``block_start`` skips blank lines,
    ``nonmatching`` markers, ``/* ... */`` line-comments, and
    ``alabel``/``jlabel``/``ehlabel`` directives (none of which are
    eligible carve roots), and stops at the first ``.align 3`` directive
    or anything else.
    """
    # First, walk forward once to collect (name, block_start, glabel) tuples.
    n = len(lines)
    func_pos: list[tuple[str, int, int, int]] = []  # name, block_start, glabel, endlabel
    for i, line in enumerate(lines):
        m = _GLABEL_RE.match(line)
        if not m:
            continue
        name = m.group(1)
        # Upward walk: find the leading `.align 3`.
        block_start = i
        for j in range(i - 1, -1, -1):
            s = lines[j]
            stripped = s.strip()
            if stripped == "":
                continue
            if _ALIGN3_RE.match(s):
                block_start = j
                break
            if (_NONMATCHING_RE.match(s)
                or stripped.startswith("/*")
                or _ALABEL_LIKE_RE.match(s)):
                continue
            # Hit something else (e.g. previous endlabel, raw instruction
            # comment, or another glabel-less directive) — fall back to
            # the glabel line as the carve unit start.
            block_start = i
            break
        # Forward walk: find the matching endlabel (informational only;
        # block_end is derived from the next function's block_start).
        endlabel = i
        for k in range(i + 1, n):
            em = _ENDLABEL_RE.match(lines[k])
            if em and em.group(1) == name:
                endlabel = k
                break
        else:
            raise BuildError(
                f"carve indexer: no endlabel for {name!r} starting at line {i + 1}"
            )
        func_pos.append((name, block_start, i, endlabel))

    # Now derive block_end_inclusive = (next function's block_start) - 1,
    # or len(lines) - 1 for the last function.
    out: dict[str, tuple[int, int, int]] = {}
    for idx, (name, block_start, glabel, _endlabel) in enumerate(func_pos):
        if idx + 1 < len(func_pos):
            next_block_start = func_pos[idx + 1][1]
        else:
            next_block_start = n
        block_end_inclusive = next_block_start - 1
        if block_end_inclusive < block_start:
            # Should never happen (function order is monotonic), but flag loudly.
            raise BuildError(
                f"carve indexer: function {name!r} has block_end < block_start "
                f"({block_end_inclusive} < {block_start}); source order broken?"
            )
        out[name] = (block_start, glabel, block_end_inclusive)
    return out


def _preamble_end_index(lines: list[str]) -> int:
    """Return the index *one past* the last line of the file preamble.

    Preamble = everything up to and including the first ``.section .text``
    directive.  Subsequent fragment/carved files inherit this preamble
    verbatim so they assemble standalone with the right initial section
    and ``.set noat``/``.set noreorder`` state.
    """
    for i, line in enumerate(lines):
        if line.lstrip().startswith(".section .text"):
            return i + 1
    raise BuildError(
        "carve indexer: monolithic .s has no `.section .text` directive"
    )


def _split_monolithic(
    text: str, names: list[str]
) -> tuple[list[str], dict[str, str], list[tuple[str, int, int]]]:
    """Pure function: given the monolithic .s text and a list of carved
    function names, return:

      * ``fragments[i]`` — the .s text of fragment ``i`` (``len(names)+1`` of them)
      * ``carved[name]`` — the .s text of the per-function carved unit
      * ``ranges`` — ``(name, start_line, end_line)`` per carve in source order

    The first fragment inherits the original file preamble naturally;
    later fragments and carved files have the preamble re-prepended so
    they assemble standalone.

    The function is order-insensitive in its inputs: names are
    re-sorted by their first-line-of-carve-unit position so the output
    fragments are guaranteed in source order, which is retail VMA order
    for spim-disasm output.
    """
    lines = text.splitlines(keepends=True)
    index = _index_functions(lines)
    missing = [n for n in names if n not in index]
    if missing:
        raise BuildError(
            f"carve: function(s) not present in monolithic: {missing}"
        )
    preamble_end = _preamble_end_index(lines)
    preamble = "".join(lines[:preamble_end])
    if not preamble.endswith("\n"):
        preamble += "\n"
    # Carved files may be `.include`'d from C TUs via ee-as, which
    # is the older SCE PS2 assembler.  The committed splat preamble pulls in
    # `include/macro.inc` whose macro definitions use modern gas-only quoted
    # escape syntax (`.\visibility "\label"`); ee-as rejects them.  Swap
    # the include to `labels.inc` for carve files only — labels.inc uses the
    # older-style `.\visibility \label` form that BOTH ee-as AND modern gas
    # (mipsel-as, used for standalone-assembly when a carve has no `tu`)
    # accept.  Fragments keep `macro.inc` because they only ever go through
    # mipsel-as.  Verified against both assembler paths.
    carve_preamble = preamble.replace(
        '.include "macro.inc"', '.include "labels.inc"'
    )
    # Each carved function lives in its own `.text.<NAME>` section so the
    # build-time lcf can place multiple carves from the same C TU at
    # distinct VMAs (see `INCLUDE_ASM` in include/include_asm.h and the
    # lcf emitter below).  Rewrite the generic `.section .text, "ax"` in
    # the preamble to a per-carve `.section .text.<NAME>, "ax"`; the
    # standalone-assembly path (`tu: null`) gets the same section name,
    # and the INCLUDE_ASM-from-C-TU path is wrapped in
    # `.pushsection .text.<NAME>` so the directive is consistent with the
    # outer context.  Pure-text replacement.
    _SECTION_TEXT_LINE = '.section .text, "ax"'

    # Sort by carve start line (= VMA order).
    ranges = sorted(
        ((n, *index[n]) for n in names), key=lambda t: t[1]
    )

    # Sanity: carve units must not overlap.
    last_end = -1
    for n, start, _glabel, end in ranges:
        if start <= last_end:
            raise BuildError(
                f"carve: overlap detected at {n!r} (start line {start + 1} "
                f"<= previous end line {last_end + 1})"
            )
        last_end = end

    fragments: list[str] = []
    carved: dict[str, str] = {}
    cursor = 0
    for n, start, _glabel, end in ranges:
        frag_lines = lines[cursor:start]
        if cursor == 0:
            frag_text = "".join(frag_lines)
        else:
            frag_text = preamble + "".join(frag_lines)
        # Ensure each fragment ends with a newline so concatenations
        # downstream don't merge directives.
        if frag_text and not frag_text.endswith("\n"):
            frag_text += "\n"
        fragments.append(frag_text)
        carve_body = "".join(lines[start:end + 1])
        per_func_preamble = carve_preamble.replace(
            _SECTION_TEXT_LINE,
            f'.section .text.{n}, "ax"',
        )
        carve_text = per_func_preamble + carve_body
        if not carve_text.endswith("\n"):
            carve_text += "\n"
        # ee-as 2.10 only accepts numeric GPRs; rewrite $ra/$sp/$v0/...
        # in the carved file (which feeds ee-as via INCLUDE_ASM).
        carve_text = _eeas_compat_registers(carve_text)
        carved[n] = carve_text
        cursor = end + 1

    # Trailing fragment.
    tail = lines[cursor:]
    if cursor == 0:
        tail_text = "".join(tail)
    else:
        tail_text = preamble + "".join(tail)
    if tail_text and not tail_text.endswith("\n"):
        tail_text += "\n"
    fragments.append(tail_text)

    return fragments, carved, [(n, s, e) for (n, s, _g, e) in ranges]


def _carve_unit_size_bytes(carved_text: str) -> int:
    """Return the .text byte size of a carved-fragment .s file.

    Each MIPS instruction line in the carved .s contributes 4 bytes
    (the disassembled comment-prefixed form
    ``/* FILE_OFF VRAM HEX_BYTES */ insn ...``).  Directives,
    labels, ``nonmatching`` markers, and blank lines contribute zero.

    Used by `compile.py::_emit_build_lcf` to determine the carve unit's
    true byte span — the LCF location counter must advance past the full
    span (body + trailing nop pad) so a C TU integration that produces a
    body shorter than the carve unit doesn't shift every subsequent
    function earlier in .text.

    An earlier version of the post-carve LCF emitted ``. = ALIGN(8);``
    which is sufficient ONLY for the case where the body is 4-aligned and
    the trailing pad is ≤4 bytes (e.g. ``func_002930B8`` 12-B body +
    1-nop pad → 16-B carve unit, ALIGN(8) pads C-body 12→16).  It
    does NOT scale to 8-byte 2-insn functions whose carve unit can
    extend to 40 B (8 B body + 8 trailing nops; ``func_00138BB8``).
    """
    count = 0
    for line in carved_text.splitlines():
        if _INSN_LINE_RE.match(line):
            count += 1
    return count * 4


# --------------------------------------------------------------------------- #
# Public schema seam
# --------------------------------------------------------------------------- #


class CarveSchema:
    """Schema-only carving surface: parse, validate, split, size.

    Pure functions; no file I/O; no mutation. The two-seam shape: this
    class owns the data-shape contract; `CarveSession` (Phase 2) owns
    mutation + atomic rollback.

    All methods are `@staticmethod` because the schema has no
    instance state — the class is a namespace for discoverability, not
    a stateful object. Callers can use the module-level private
    aliases (`_parse_carved_entries`, `_split_monolithic`,
    `_carve_unit_size_bytes`) instead if they prefer; both surfaces
    point at the same implementations.

    Example::

        from scripts.carver import CarveSchema, CarveEntry

        entries: list[CarveEntry] = CarveSchema.parse_entries(cfg)
        fragments, carved, ranges = CarveSchema.split_monolithic(
            monolithic_text, [e.name for e in entries]
        )
        sizes = {n: CarveSchema.carve_unit_size_bytes(carved[n]) for n in carved}
    """

    @staticmethod
    def is_doc_record(raw) -> bool:
        """True when a config array element is documentation, not data.

        The one predicate every reader of `compile_config.json`'s
        documented arrays must use. See `is_doc_record` for why a
        `name`-prefix test is forbidden here (ticket 36).
        """
        return is_doc_record(raw)

    @staticmethod
    def parse_entries(cfg) -> list[CarveEntry]:
        """JSON-dict-array → list[CarveEntry].

        `cfg` is duck-typed on `.carved_funcs` to avoid a circular
        import on `compile.Config`. Skips pure-documentation
        `_comment`-only entries.
        """
        return _parse_carved_entries(cfg)

    @staticmethod
    def split_monolithic(
        text: str, names: list[str]
    ) -> tuple[list[str], dict[str, str], list[tuple[str, int, int]]]:
        """Pure text split: monolithic .s text + carve names →
        (fragments, carved, ranges).

        See `_split_monolithic` for the detailed contract. Returns
        ``len(names) + 1`` fragments plus a per-name carved-text dict
        plus the source-order range tuples for LCF emission.
        """
        return _split_monolithic(text, names)

    @staticmethod
    def carve_unit_size_bytes(carved_text: str) -> int:
        """Carve unit byte size: 4 × instruction-line count.

        Used by `compile.py::_emit_build_lcf` to advance the LCF
        location counter past the full carve span (body + trailing nop
        pad), not just to the next 8-byte boundary.
        """
        return _carve_unit_size_bytes(carved_text)


# =========================================================================== #
# PHASE 2 — Session half (mutation + atomic rollback)
#
# Moved here in the carver-module split. The primitives preserve their
# pre-move names (private leading underscore) so the original module's
# re-export shim and
# its tests' `ar._auto_carve_uncarved` / `ar._atomic_auto_carve` accesses
# keep working unchanged. The public surface for new callers is
# `class CarveSession` below.
#
# Raised exceptions changed from the caller's error type to `CarveError`
# at the move; the caller's 3 wrap-sites were updated to catch both error
# types; `auto_carve_func.py` updated to catch `CarveError` directly.
# =========================================================================== #


_DEFAULT_ASM_MODULE = "asm/cod/000000.s"
_DEFAULT_TU = "src/cod/000000.c"


# Match the spimdisasm ``nonmatching <name>, 0x<size>`` directive that
# declares each function's authoritative size in bytes. Used by
# :func:`_corrected_size_bytes` to defend against stale
# ``progress/decomp_targets.json`` entries that include trailing-nop
# alignment padding in ``size_bytes``.
_NONMATCHING_DIRECTIVE_RE = re.compile(
    r"^\s*nonmatching\s+(?P<name>[A-Za-z_][A-Za-z0-9_]*)\s*,\s*"
    r"0[xX](?P<hex>[0-9a-fA-F]+)\s*$",
    re.MULTILINE,
)


def _corrected_size_bytes(
    name: str,
    declared_size: int,
    *,
    asm_module_path: str,
    root: Path = ROOT,
) -> int:
    """Return the corrected ``size`` value for ``name``'s carve entry.

    Cross-checks ``declared_size`` (typically from
    ``progress/decomp_targets.json::candidates[*].size_bytes``) against
    the ``nonmatching <name>, 0x<size>`` directive in the asm source.
    Returns whichever is smaller; falls back to ``declared_size`` on any
    I/O / parse error so the carve entry still lands (the size mismatch
    is cosmetic in that case — ``check_tu_complete.py`` warns but does
    not gate).

    Why both layers: the upstream target list was fixed at the source
    (use ``body_opcodes`` instead of unbounded ``insn_count``), but the
    corpus file is regenerated only at tranche boundaries, so this
    helper protects in-flight batches that read a stale corpus.

    Pure-Python; no subprocess calls.
    """
    if not asm_module_path:
        return declared_size
    asm_path = root / asm_module_path
    if not asm_path.exists():
        return declared_size
    try:
        asm_text = asm_path.read_text()
    except OSError:
        return declared_size
    for m in _NONMATCHING_DIRECTIVE_RE.finditer(asm_text):
        if m.group("name") != name:
            continue
        try:
            directive_size = int(m.group("hex"), 16)
        except ValueError:
            return declared_size
        # Prefer the smaller value: the directive's hex size is the
        # span between glabel/endlabel; declared_size may include
        # alignment padding.
        return min(declared_size, directive_size)
    return declared_size


def _derive_tu_from_asm_path(asm_module_path: str) -> tuple[str, str]:
    """Return ``(unit, tu)`` from an ``asm_module_path`` field.

    TU selection policy:

    - Strip leading ``asm/`` and trailing ``.s`` to get the bare module
      name (e.g. ``asm/cod/000000.s`` → ``cod/000000``).
    - ``unit`` is the canonical path stored in
      ``compile_config.json::carved_funcs[].unit``:  ``asm/cod/000000``.
    - ``tu`` is ``src/<module>.c`` (e.g. ``src/cod/000000.c``).

    All current tier-1 tiny-leaf-no-globals candidates live in
    ``asm/cod/000000.s``, so they map to ``src/cod/000000.c``.  The
    derivation is intentionally generic: any ``asm/<module>.s`` maps
    to ``src/<module>.c``, so future multi-TU campaigns work without
    code changes.  If ``asm_module_path`` is ``None`` / empty / missing
    the ``asm/`` prefix, the function falls back to the defaults
    ``asm/cod/000000`` + ``src/cod/000000.c``.

    Documented in the TU-selection-policy notes.
    """
    path = asm_module_path or _DEFAULT_ASM_MODULE
    # Strip leading "asm/" prefix.
    module = path[4:] if path.startswith("asm/") else path
    # Strip trailing ".s" suffix.
    if module.endswith(".s"):
        module = module[:-2]
    unit = f"asm/{module}"
    tu = f"src/{module}.c"
    return unit, tu


@dataclasses.dataclass(frozen=True)
class CarveSnapshot:
    """Pre-state snapshot for atomic rollback of `_auto_carve_uncarved`.

    Captured BEFORE the carve mutates `compile_config.json` /
    `src/<tu>.c`; restored by `_revert_auto_carve` when the
    subsequent integration fails.

    The rollback bug this guards against: pre-fix, the three
    `_auto_carve_uncarved` + integration call-pairs leaked
    compile_config.json `carved_funcs` entries +
    `INCLUDE_ASM("nonmatching", <name>);` lines + orphan
    `build/asm/nonmatching/<name>.s` fragments whenever integrate
    raised.  One batch compounded this into 20 orphan entries before
    it was caught and cleaned up by hand.

    The expected-rollback bug this guards against: pre-fix, the
    expected/build/asm/cod/*.o files were not snapshotted, so failed
    12-B integrations left stale part files that drifted total_code /
    total_functions metrics.  Now captures the entire
    expected/build/asm/cod/ subtree as a dict of {relative_path: bytes}.
    Coarser but simpler than per-file tracking; ~700 files ×
    ~few-hundred-B = ~few-MB snapshot.

    An earlier refactor moved this dataclass here from the original
    module (where it was `_AutoCarveSnapshot`). That pre-move name is
    preserved as a back-compat alias in the original module.
    """
    name: str
    config_path: Path
    config_pre_text: str          # full compile_config.json text pre-carve
    tu_path: Path
    tu_pre_text: str | None       # None if the TU file didn't exist pre-carve
    fragment_path: Path           # build/asm/nonmatching/<name>.s
    fragment_pre_existed: bool    # False → .s is our orphan, safe to remove
    expected_build_snapshot: dict[str, bytes] | None  # Bug 6: expected/build/asm/cod/*.o


def _capture_auto_carve_snapshot(
    name: str,
    candidate: dict,
    *,
    config_path: Path,
    root: Path = ROOT,
) -> CarveSnapshot:
    """Capture pre-carve state for a potential atomic rollback.

    Pure read; no filesystem mutation.  Paired with
    `_revert_auto_carve` and the `_atomic_auto_carve` context manager.
    Callers that don't care about rollback can use
    `_auto_carve_uncarved` directly.
    """
    asm_module_path = candidate.get("asm_module_path") or _DEFAULT_ASM_MODULE
    unit, tu = _derive_tu_from_asm_path(asm_module_path)
    tu_path = root / tu
    try:
        cfg_pre_text = config_path.read_text()
    except OSError as e:
        raise CarveError(
            f"auto-carve snapshot: failed to read {config_path}: {e}"
        ) from e
    tu_pre_text = tu_path.read_text() if tu_path.exists() else None
    frag_path = root / "build" / "asm" / "nonmatching" / f"{name}.s"

    # Bug 6: capture expected/build/asm/cod/<unit>*.o files.
    # The unit is e.g. "asm/cod/000000", so we capture
    # expected/build/asm/cod/000000.part*.o + expected/build/asm/cod/000000.o.
    expected_dir = root / "expected" / "build" / "asm" / "cod"
    expected_snapshot: dict[str, bytes] | None = None
    if expected_dir.exists():
        # Extract unit basename: "asm/cod/000000" -> "000000"
        unit_base = Path(unit).name  # "000000"
        expected_snapshot = {}
        for o_file in expected_dir.glob(f"{unit_base}*.o"):
            try:
                expected_snapshot[o_file.name] = o_file.read_bytes()
            except OSError:
                pass  # best-effort

    return CarveSnapshot(
        name=name,
        config_path=config_path,
        config_pre_text=cfg_pre_text,
        tu_path=tu_path,
        tu_pre_text=tu_pre_text,
        fragment_path=frag_path,
        fragment_pre_existed=frag_path.exists(),
        expected_build_snapshot=expected_snapshot,
    )


def _revert_auto_carve(snap: CarveSnapshot, *, root: Path = ROOT) -> None:
    """Restore the pre-carve state captured by `_capture_auto_carve_snapshot`.

    Restores:

    1. ``compile_config.json`` to its pre-carve bytes (drops any
       newly-appended ``carved_funcs`` entry).
    2. ``src/<tu>.c`` to its pre-carve text (drops any newly-appended
       ``INCLUDE_ASM("nonmatching", <name>);`` line).
    3. ``build/asm/nonmatching/<name>.s`` — removed iff we created it
       (``fragment_pre_existed=False``).
    4. ``expected/build/asm/cod/<unit>*.o`` — restored from snapshot.

    Idempotent: safe to call repeatedly; tolerates partial-revert
    states (e.g. config already restored, TU already restored). Used
    in tandem with `_atomic_auto_carve`; direct callers should prefer
    the context manager.
    """
    try:
        snap.config_path.write_text(snap.config_pre_text)
    except OSError:
        pass  # best-effort; the caller will surface the integrate error
    if snap.tu_pre_text is None:
        # TU did not exist pre-carve; if it exists now, remove it.
        try:
            if snap.tu_path.exists():
                snap.tu_path.unlink()
        except OSError:
            pass
    else:
        try:
            snap.tu_path.write_text(snap.tu_pre_text)
        except OSError:
            pass
    if not snap.fragment_pre_existed:
        try:
            if snap.fragment_path.exists():
                snap.fragment_path.unlink()
        except OSError:
            pass
    # Bug 6: restore expected/build/asm/cod/<unit>*.o files.
    if snap.expected_build_snapshot:
        expected_dir = root / "expected" / "build" / "asm" / "cod"
        if expected_dir.exists():
            for filename, content in snap.expected_build_snapshot.items():
                try:
                    (expected_dir / filename).write_bytes(content)
                except OSError:
                    pass  # best-effort


@contextlib.contextmanager
def _atomic_auto_carve(
    name: str,
    candidate: dict,
    *,
    config_path: Path,
    root: Path = ROOT,
) -> Iterator[CarveSnapshot]:
    """Context manager: run `_auto_carve_uncarved` with atomic rollback
    if the wrapped block raises.

    Usage::

        try:
            with _atomic_auto_carve(name, cand, config_path=..., root=...):
                integrate(name, c_source, ...)
        except CarveError as exc:
            integrate_failures.append({"name": name, "reason": str(exc)})

    On any exception inside the ``with`` block, the snapshot captured
    pre-carve is restored before the exception propagates. Idempotent
    if `_auto_carve_uncarved` was already a no-op (``"already_carved"``)
    — the restore is a write-back of identical text, so the
    second-of-N candidates in a batch that share a TU don't get
    poisoned by an earlier sibling's failure.

    See the `CarveSnapshot` docstring for the failure mode this fixes.
    """
    snap = _capture_auto_carve_snapshot(
        name, candidate, config_path=config_path, root=root,
    )
    _auto_carve_uncarved(
        name, candidate, config_path=config_path, root=root,
    )
    try:
        yield snap
    except BaseException:
        _revert_auto_carve(snap, root=root)
        raise


def _auto_carve_uncarved(
    name: str,
    candidate: dict,
    *,
    config_path: Path,
    root: Path = ROOT,
) -> str:
    """Ensure ``name`` has a carve entry in ``compile_config.json`` and an
    ``INCLUDE_ASM("nonmatching", <name>);`` line in its TU.  Idempotent.

    Steps:

    1. Read ``compile_config.json``; if ``name`` is already in
       ``carved_funcs``, skip the config write (idempotent).
    2. If not present, append a new entry and atomically replace the
       config file (tmpfile + `os.replace`).
    3. Open the TU file (derived from ``candidate["asm_module_path"]``
       via `_derive_tu_from_asm_path`); if the
       ``INCLUDE_ASM(…, name)`` pattern is already present, skip the
       TU write (idempotent).  If the function is already integrated
       (``__attribute__((section(".text.<name>")))`` pattern present),
       also skip — integration will surface a clean error.
    4. Append ``\nINCLUDE_ASM("nonmatching", <name>);\n`` to the TU.

    Returns ``"carved"`` when at least one write was performed, or
    ``"already_carved"`` when both the config entry and TU line were
    already present (pure no-op).

    Raises `CarveError` on I/O or structural failures.
    """
    asm_module_path = candidate.get("asm_module_path") or _DEFAULT_ASM_MODULE
    unit, tu = _derive_tu_from_asm_path(asm_module_path)
    vaddr = candidate.get("address", "0x00000000")
    declared_size = int(candidate.get("size_bytes", 4))

    # Defensive: when ``progress/decomp_targets.json`` is stale,
    # ``size_bytes`` may include trailing-nop alignment padding emitted
    # by spimdisasm AFTER ``endlabel``.  E.g. ``func_002DB6B0`` (3 insns
    # / 12 B) was reported as ``size_bytes=16``.  Cross-check against the
    # actual asm directive ``nonmatching <name>, 0x<size>`` and prefer
    # the smaller value (the declared shape).
    size = _corrected_size_bytes(
        name, declared_size, asm_module_path=asm_module_path, root=root,
    )

    # ------------------------------------------------------------------ #
    # Step 1+2: ensure carve entry exists in compile_config.json.
    # ------------------------------------------------------------------ #
    try:
        cfg_text = config_path.read_text()
        cfg = json.loads(cfg_text)
    except Exception as e:  # noqa: BLE001
        raise CarveError(
            f"auto-carve: failed to read {config_path}: {e}"
        ) from e

    carved_funcs = cfg.get("carved_funcs", [])
    already_in_config = any(
        isinstance(e, dict) and e.get("name") == name
        for e in carved_funcs
    )
    did_carve = False

    if not already_in_config:
        new_entry: dict = {
            "name": name,
            "unit": unit,
            "vaddr": vaddr,
            "size": size,
            "tu": tu,
        }
        cfg["carved_funcs"] = list(carved_funcs) + [new_entry]
        tmp = config_path.with_suffix(config_path.suffix + ".tmp")
        try:
            tmp.write_text(
                json.dumps(cfg, indent=2, ensure_ascii=False) + "\n"
            )
            os.replace(tmp, config_path)
        except Exception as e:  # noqa: BLE001
            try:
                tmp.unlink(missing_ok=True)
            except OSError:
                pass
            raise CarveError(
                f"auto-carve: failed to write {config_path}: {e}"
            ) from e
        did_carve = True

    # ------------------------------------------------------------------ #
    # Step 3+4: ensure TU has INCLUDE_ASM("nonmatching", name) line.
    # ------------------------------------------------------------------ #
    tu_path = root / tu
    if not tu_path.exists():
        raise CarveError(
            f"auto-carve: TU file not found: {tu_path}"
        )
    tu_text = tu_path.read_text()

    # Idempotent check: INCLUDE_ASM already present (any folder string).
    include_present = bool(re.search(
        r"INCLUDE_ASM\s*\(\s*\"[^\"]*\"\s*,\s*" + re.escape(name) + r"\s*\)",
        tu_text,
    ))
    if not include_present:
        # Skip if already integrated (C body with section attribute present).
        already_integrated = bool(re.search(
            r'__attribute__\s*\(\s*\(\s*section\s*\(\s*"\.text\.'  # noqa
            + re.escape(name) + r'"\s*\)\s*\)\s*\)',
            tu_text,
        ))
        if not already_integrated:
            new_line = f'\nINCLUDE_ASM("nonmatching", {name});\n'
            try:
                tu_path.write_text(tu_text + new_line)
            except Exception as e:  # noqa: BLE001
                raise CarveError(
                    f"auto-carve: failed to write TU {tu_path}: {e}"
                ) from e
            did_carve = True

    return "carved" if did_carve else "already_carved"


# Back-compat alias: pre-move name `_AutoCarveSnapshot` (the original
# module's symbol). The original module re-exports it; existing imports
# and tests keep working unchanged through Phase 3.
_AutoCarveSnapshot = CarveSnapshot


# --------------------------------------------------------------------------- #
# Public session seam
# --------------------------------------------------------------------------- #


class CarveSession:
    """Stateful carve mutation + atomic rollback surface.

    The two-seam shape: this class owns mutation + rollback;
    `CarveSchema` (above) owns the data-shape contract.

    Today's behaviour is a thin facade over the private primitives
    `_capture_auto_carve_snapshot`, `_revert_auto_carve`,
    `_atomic_auto_carve`, `_auto_carve_uncarved`. Callers that need
    the existing exact behaviour can also use those primitives
    directly; new callers should prefer this class for discoverability.

    `auto_carve_func.py` consumes `carve_one()` (no internal atomic
    wrap; the caller handles rollback). The atomic wrap is available to
    any caller that wants it via `atomic()` or the
    `_atomic_auto_carve` private alias.

    Example::

        from scripts.carver import CarveSession, CarveError

        session = CarveSession(root=ROOT)
        try:
            result = session.carve_one(
                name, candidate, config_path=Path("compile_config.json")
            )
        except CarveError as exc:
            print(f"carve failed: {exc}")
            sys.exit(3)

    Example (atomic, with downstream rollback)::

        with session.atomic(name, candidate, config_path=cfg_path):
            integrate(name, c_source, ...)
        # If integration raises, the carve is reverted before the
        # exception propagates.
    """

    def __init__(self, *, root: Path = ROOT):
        self.root = root

    def carve_one(
        self,
        name: str,
        candidate: dict,
        *,
        config_path: Path,
    ) -> str:
        """Idempotent single-function carve.

        Returns ``"carved"`` if at least one mutation was applied, or
        ``"already_carved"`` if the candidate was already present in
        both `compile_config.json::carved_funcs[]` and the target TU.

        Raises `CarveError` on I/O or structural failures.
        """
        return _auto_carve_uncarved(
            name, candidate, config_path=config_path, root=self.root,
        )

    def snapshot(
        self,
        name: str,
        candidate: dict,
        *,
        config_path: Path,
    ) -> CarveSnapshot:
        """Capture pre-carve state for atomic rollback. Pure read."""
        return _capture_auto_carve_snapshot(
            name, candidate, config_path=config_path, root=self.root,
        )

    def revert(self, snap: CarveSnapshot) -> None:
        """Restore the pre-carve state captured by `snapshot()`.

        Idempotent: safe to call repeatedly.
        """
        _revert_auto_carve(snap, root=self.root)

    @contextlib.contextmanager
    def atomic(
        self,
        name: str,
        candidate: dict,
        *,
        config_path: Path,
    ) -> Iterator[CarveSnapshot]:
        """Context manager: carve + downstream block; revert on raise.

        See `CarveSnapshot` docstring for the failure mode this fixes.
        """
        with _atomic_auto_carve(
            name, candidate, config_path=config_path, root=self.root,
        ) as snap:
            yield snap


__all__ = [
    "ROOT",
    "BuildError",
    "CarveError",
    "CarveEntry",
    "CarveState",
    "CarveSchema",
    "CarveSnapshot",
    "CarveSession",
]
