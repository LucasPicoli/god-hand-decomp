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
# GH_SN_GCCLIB selects a sibling SN build's gcc-lib dir (e.g. 2.95.3-sn-114,
# 2.95.2-sn-273a) — set by ee-cc-wrap.py's variant dispatch; the default
# stays the primary 2.95.3-sn-136 so all existing entry points are unchanged.
SN_GCCLIB = ROOT / "compiler" / "windows" / "ee" / "gcc" / "lib" / "gcc-lib" / "ee" / os.environ.get(
    "GH_SN_GCCLIB", "2.95.3-sn-136")
SN_CC1 = SN_GCCLIB / "cc1.exe"
SN_CC1PLUS = SN_GCCLIB / "cc1plus.exe"

WIBO = ROOT / "tools" / "wibo"

# SN Systems' PS2 EE assembler, reached only by `--assembler sn`.  Pinned to
# the same build ee-cc-wrap.py pins (2.95.3-sn-114/ps2eeas.exe is behaviourally
# identical on every probe run against it, notes/110), and deliberately NOT keyed off
# GH_SN_GCCLIB: the cc1 build and the assembler build are independent choices,
# and only one assembler answer has ever been measured.
PS2EEAS = (ROOT / "compiler" / "windows" / "ee" / "gcc" / "lib" / "gcc-lib" /
           "ee" / "2.95.2-sn-273a" / "ps2eeas.exe")

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
# The `libm` rule's two halves (see _FP_RULE_LIBM).  An `mfc1` naming the FPR
# an FP->integer convert just wrote is the only producer/consumer pair retail's
# libm objects pad; `mfc1` after an FP *arithmetic* op is NOT padded there.
_HAZARD_MFC1_RE = re.compile(r"^\s*d?mfc1\s+\$\w+\s*,\s*(\$f\d+)\b")
_HAZARD_FTOI_RE = re.compile(
    r"^\s*(?:cvt|trunc|round|ceil|floor)\.w\.[sd]\s+(\$f\d+)\b")


def _is_ee_fp_hazard_producer(line: str) -> bool:
    """True if *line* is an EE FP op a following op must stall on (mtc1/ctc1
    GPR->COP1 move, or an FP compare feeding bc1*).  See ee-cc-wrap.py."""
    op = line.strip()
    return op.startswith(("mtc1", "ctc1", "li.s", "li.d")) or bool(_HAZARD_FP_CMP_RE.match(line))


_HAZARD_BC1_RE = re.compile(r"^\s*bc1[tf]l?\b")


def _libm_compare_slot_is_empty(lines, i) -> bool:
    """True if the `bc1*` consuming this compare has an EMPTY delay slot.

    Retail's libm objects pad a `c.<cond>.s` -> `bc1*` pair only when the branch
    delay slot holds real work. With an EMPTY slot they carry the nop IN the slot
    and none before the branch: `c.eq.s / bc1t / nop` is three words, and
    `c.eq.s / nop / bc1t / nop` is four.

    SCOPE, and it is the whole point of the `libm` gate. A full decode of all
    3,212 `c.<cond>.[sd]` sites in retail says this predicate holds 27 of 27
    inside 0x3A0000-0x3B0000 and FAILS 388 times outside it -- 368 game-code
    sites are padded with an empty slot, across 172 functions. Applied globally
    it fabricates a missing word at every one. A predicate measured inside one
    vendor object is a per-object rule until a whole-binary decode says
    otherwise.
    """
    nxt = []
    for ln in lines[i + 1:]:
        s = ln.strip()
        if not s or s.startswith((".", "#")) or s.endswith(":"):
            continue
        nxt.append(s)
        if len(nxt) == 2:
            break
    return len(nxt) == 2 and bool(_HAZARD_BC1_RE.match(nxt[0])) and nxt[1] == "nop"


def _compare_slot_is_full(lines, i) -> bool:
    """True if the `bc1*` consuming this compare has a NON-empty delay slot.

    The complement of :func:`_libm_compare_slot_is_empty`, and NOT its negation:
    this one also requires that a `bc1*` actually follows.  A `c.<cond>.s` whose
    next instruction is something else returns False from both.

    SCOPE. A whole-binary decode of all 3,066 `c.<cond>.[sd]` -> `bc1*` pairs in
    retail says the pad is the rule and its absence is the exception: 2,673 of
    2,693 full-slot pairs ARE padded. Applied globally this would delete a real
    word at every one of them. It is a PER-TU opt-in for the same reason `libm`
    is, and the twenty sites it describes sit in EIGHT functions, none of which
    mixes the two forms:

        func_0032A1B0 2  func_0032DD70 1  func_0033E6B8 3  func_00343C18 1
        func_0035B6F8 1  func_0035B8C0 4  func_00366110 4  func_00366368 4

    Census: `.scratch/decomp-velocity/findings/wave-2026-08-31/cmpfull_census.py`.
    """
    nxt = []
    for ln in lines[i + 1:]:
        s = ln.strip()
        if not s or s.startswith((".", "#")) or s.endswith(":"):
            continue
        nxt.append(s)
        if len(nxt) == 2:
            break
    return len(nxt) == 2 and bool(_HAZARD_BC1_RE.match(nxt[0])) and nxt[1] != "nop"


def _materialize_hazard_nops(text: str, rules=None) -> str:
    """Turn cc1's commented ``#nop`` EE FP hazard hints into real nops.

    SN cc1 (like cygnus) emits a bare ``#nop`` comment wherever the pipeline
    needs a stall but leaves materialisation to a reorder-capable assembler;
    ee-as does not reorder, so the nop is otherwise lost.  Only the ``#nop``
    whose preceding instruction is an mtc1->FPU or FP-compare->branch hazard
    producer is converted — keeping every already-matched function byte
    identical.  Twin of the helper in ee-cc-wrap.py.

    ``rules`` is the parsed ``--fp-hazard-rules`` set, or ``None`` for a TU
    that did not opt in.  Only ``libm`` changes this pass; see _FP_RULE_LIBM.
    """
    if "#nop" not in text:
        return text
    libm = rules is not None and _FP_RULE_LIBM in rules
    cmpfull = rules is not None and _FP_RULE_CMPFULL in rules
    lines = text.split("\n")
    out = []
    last_instr = None
    mfc1_pend = False
    for _i, line in enumerate(lines):
        stripped = line.strip()
        if stripped == "#nop" and last_instr is not None:
            if _is_ee_fp_hazard_producer(last_instr):
                if (libm and _HAZARD_FP_CMP_RE.match(last_instr)
                        and _libm_compare_slot_is_empty(lines, _i)):
                    # libm, empty slot: retail carries the nop IN the slot.
                    last_instr = None
                    continue
                if (cmpfull and _HAZARD_FP_CMP_RE.match(last_instr)
                        and _compare_slot_is_full(lines, _i)):
                    # cmpfull: retail does NOT pad a compare whose branch slot
                    # holds real work. Eight functions, twenty sites, none mixed.
                    last_instr = None
                    continue
                if libm and not _HAZARD_FP_CMP_RE.match(last_instr):
                    # libm: drop the FIRST nop after the mtc1 family.  Setting
                    # last_instr to None keeps a following nop -- the div.s
                    # template pad -- which retail carries.
                    last_instr = None
                    continue
                out.append("\tnop")
                continue
            if mfc1_pend:
                out.append("\tnop")
                mfc1_pend = False
                continue
        out.append(line)
        if stripped and not stripped.startswith((".", "#")) \
                and not stripped.endswith(":"):
            m = _HAZARD_MFC1_RE.match(line)
            p = _HAZARD_FTOI_RE.match(last_instr) if (libm and last_instr) else None
            mfc1_pend = bool(m and p and m.group(1) == p.group(1))
            last_instr = line
    return "\n".join(out)


# --- Opt-in EE FP hazard-nop INSERTER (--fp-hazard-nops) ---------------------
# Twin of the helper in ee-cc-wrap.py; the two must agree byte-for-byte so the
# same source matches under either cc1 frontend.  Unlike _materialize_hazard_nops
# (which only uncomments a #nop cc1 already placed), this pass INSERTS the nops
# our cc1 frontends omit entirely, for a TU that opted in.  See
# .private/tests/test_fp_hazard_insert.py for the full spec.
_FPR_RE = re.compile(r"\$f\d+")
_MTC1_DEST_RE = re.compile(r"^\s*d?mtc1\s+\$\w+\s*,\s*(\$f\d+)\b")
_CVT_DEST_RE = re.compile(r"^\s*cvt\.[a-z0-9.]+\s+(\$f\d+)\b")
_DIV_SRC_RE = re.compile(r"^\s*div\.[sd]\s+\$f\d+\s*,\s*(\$f\d+)\s*,\s*(\$f\d+)")
# The whole divide class the vendor EE cc1 pads.  The template lives in the cc1
# binary as `%(nop / nop / div.s %0,%1,%2%)`, with the same pair for `sqrt.s`,
# `rsqrt.s %0,%2` and `rsqrt.s %0,%1,%2` (`%(`/`%)` are gcc's MIPS operand codes
# for `.set noreorder`/`.set reorder`).  Single precision ONLY: retail holds 966
# `div.s` and 155 `sqrt.s` sites and ZERO `div.d`/`sqrt.d`, because the R5900
# FPU has no double unit.
_FDIV_CLASS_RE = re.compile(r"^\s*(?:div|sqrt|rsqrt)\.s\b")
# `div`: the same pad, but on `div.s` ALONE. Four functions in 0x156794-0x15A954
# carry a PADDED `div.s` and a BARE `sqrt.s` in one body (5 of the binary's 155
# `sqrt.s` sites), which `fdiv` cannot express. Measured by worker F3 of wave
# 2026-08-18 across 9 installed builds: every one pads both or neither.
_DIV_ONLY_CLASS_RE = re.compile(r"^\s*div\.s\b")
# `sqrt`: the mirror of `div` — the same pad on `sqrt.s`/`rsqrt.s` ALONE, for a
# TU whose square roots are padded and whose divides are bare.  Neither `fdiv`
# (over-pads the divide) nor `div` (under-pads the root) can express that body.
# Measured by the batch-7 orchestrator over all 1,121 divide-class sites in
# retail; see issue 77 section 3.
_SQRT_ONLY_CLASS_RE = re.compile(r"^\s*(?:sqrt|rsqrt)\.s\b")
_FP_CONSUMER_RE = re.compile(
    r"^\s*(abs|neg|sqrt|rsqrt|mov|cvt|trunc|round|ceil|floor"
    r"|add|sub|mul|div|madd|msub|max|min|rint|c)\.[a-z0-9.]*\b(.*)$")
# Every FP-*writing* form our cc1 frontends emit, all of which name the written
# FPR as their first FPR operand (`mtc1 $r,$fN` included).  Deliberately
# conservative — a mnemonic missing here only ever costs Rule B a firing, while
# a wrong entry would fabricate nops, which is the failure this exists to stop.
# Two families are excluded on purpose: `c.<cond>.s` writes only the condition
# flag, and the R5900 accumulator forms (`adda.s`, `suba.s`, `mula.s`,
# `madda.s`, `msuba.s`) take a *source* first — neither carries the literal `.`
# immediately after the mnemonic stem that this pattern demands, so neither can
# match by accident.
_FP_DEST_RE = re.compile(
    r"^\s*(?:"
    r"(?:abs|neg|sqrt|rsqrt|mov|cvt|trunc|round|ceil|floor|add|sub|mul|div"
    r"|madd|msub|nmadd|nmsub|max|min|rint)\.[a-z0-9.]+"
    r"|li?\.[sd]|lwc1|ldc1|lwxc1|ldxc1|d?mtc1"
    r")\s+[^#]*?(\$f\d+)")

# --- rule selection ----------------------------------------------------------
# The two halves of this pass are not the same kind of thing, so they are
# selected separately (`--fp-hazard-rules`):
#
#   mtc1    Rule A.  One nop after `mtc1`/`dmtc1 $r,$fN` whose next real
#           instruction reads $fN.  MECHANICAL, and `ps2eeas.exe` emits exactly
#           this nop by itself — a TU on the `as: "sn"` route may not need it.
#   fdiv    The divide-class pad.  Two nops before EVERY `div.s`, `sqrt.s` and
#           `rsqrt.s`, unconditionally.  This is NOT a hazard predicate: it
#           reproduces a fixed cc1 OUTPUT TEMPLATE that the vendor EE gcc line
#           carries behind the target switch `-mhandle-ee-div-pipeline-bug`
#           (on by default).  The template reads no operand and no producer.
#   div1    The one-nop mirror of `fdiv`: exactly ONE nop before every
#           `div.s`, `sqrt.s` and `rsqrt.s`, on the same instruction class.
#           Retail holds 62 divide-class sites at pad depth 1, and 10 unmatched
#           functions (8,536 B) carry that depth at EVERY one of their sites.
#           A two-nop rule wins on any site it also claims.
#   libm    The retail libm objects' policy, and ONLY theirs.  Two changes to
#           _materialize_hazard_nops: DELETE the first nop after the
#           `mtc1`/`ctc1`/`li.s`/`li.d` family (the later nops of the run are
#           the div.s template pad and must survive), and MATERIALIZE the nop
#           after an `mfc1` reading the FPR an FP->integer convert just wrote.
#           The `c.<cond>.s` -> `bc1*` nop is untouched: retail pads 3,041 of
#           3,066 such sites.  Per-TU because the two edits invert the binary's
#           own base rates -- `mtc1` is padded at 22.0% (3,074/13,945) and
#           `mfc1` after an FP op at 0.7% (3/432).
#   cvtdiv  The legacy Rule B (cvt -> div, two nops).  Kept ONLY so the bare
#           `--fp-hazard-nops` flag keeps the meaning the four TUs carrying
#           `fp_hazard_nops: true` were byte-verified under.  Its own trigger is
#           the LEAST padded producer in retail — 31.6% of `cvt.s.w` sites carry
#           a pad against a 69.3% base rate — so it is inverted, not merely
#           inaccurate.  Do not select it for new work.
#
# Every rule stays per-TU opt-in and byte-verified.  `fdiv` agrees with retail
# at 772 of the 1,121 sites; the 344 over-insertions are translation units
# compiled with the switch OFF, and no predicate can see a compile flag.
_FP_RULE_MTC1 = "mtc1"
_FP_RULE_FDIV = "fdiv"
_FP_RULE_DIV = "div"
_FP_RULE_DIV1 = "div1"
_FP_RULE_SQRT = "sqrt"
_FP_RULE_CVTDIV = "cvtdiv"
_FP_RULE_LIBM = "libm"
_FP_RULE_CMPFULL = "cmpfull"
_FP_RULES_KNOWN = (_FP_RULE_MTC1, _FP_RULE_FDIV, _FP_RULE_DIV,
                   _FP_RULE_DIV1, _FP_RULE_SQRT, _FP_RULE_CVTDIV,
                   _FP_RULE_LIBM,
                   _FP_RULE_CMPFULL)
# What the bare `--fp-hazard-nops` flag has always meant.  Do not change it.
_FP_RULES_DEFAULT = frozenset((_FP_RULE_MTC1, _FP_RULE_CVTDIV))


def _parse_fp_hazard_rules(spec: str | None) -> frozenset[str]:
    """Parse a ``--fp-hazard-rules`` value; ``None`` gives the bare flag's set.

    Raises ``ValueError`` on an unknown name, so a typo cannot silently disable
    a rule the caller asked for.
    """
    if spec is None:
        return _FP_RULES_DEFAULT
    names = [t.strip() for t in spec.replace("+", ",").split(",") if t.strip()]
    if not names:
        raise ValueError("--fp-hazard-rules needs at least one rule name; "
                         "known rules: " + ", ".join(_FP_RULES_KNOWN))
    unknown = [n for n in names if n not in _FP_RULES_KNOWN]
    if unknown:
        raise ValueError("unknown FP hazard rule(s): %s; known rules: %s"
                         % (", ".join(unknown), ", ".join(_FP_RULES_KNOWN)))
    return frozenset(names)


def _fp_dest(line: str) -> str | None:
    """The FPR *written* by *line*, or ``None`` if it writes no FPR."""
    m = _FP_DEST_RE.match(line)
    return m.group(1) if m else None


def _fp_op_reads(line: str, fpr: str) -> bool:
    """True if FP op *line* reads *fpr* as a SOURCE operand.

    For a compare (``c.<cond>.s $fs,$ft``) every FPR operand is a source; for
    every other FP op the first FPR is the destination and the rest are
    sources.  ``cvt.s.w $f0,$f0`` reads $f0; ``mov.s $f0,$f12`` does not.
    """
    m = _FP_CONSUMER_RE.match(line)
    if not m:
        return False
    mnem, rest = m.group(1), m.group(2)
    regs = _FPR_RE.findall(rest)
    if not regs:
        return False
    sources = regs if mnem == "c" else regs[1:]
    return fpr in sources


def _is_asm_instr(stripped: str) -> bool:
    return (bool(stripped) and not stripped.startswith((".", "#"))
            and not stripped.endswith(":"))


def _is_branch_or_jump(stripped: str) -> bool:
    """True if the instruction is a control transfer (basic-block boundary).

    Any MIPS branch (``b``/``beq``/``beqz``/``bc1t``/``bnel`` …) or jump
    (``j``/``jr``/``jal``/``jalr``) — every such mnemonic starts with ``b`` or
    ``j``.  ``break`` is the one ``b*`` mnemonic that is not a branch.
    """
    mnem = stripped.split(None, 1)[0]
    return mnem[:1] in ("b", "j") and mnem != "break"


_SET_DIRECTIVE_RE = re.compile(r"^\.set\b\s*(.*)$")


def _set_directive_tokens(stripped: str) -> list[str] | None:
    """The operand tokens of a ``.set`` directive, or ``None`` for other lines.

    Exact tokens, on purpose.  ``"noreorder" in line`` is substring-fragile: it
    is only ever correct because the negative form happens to be tested first,
    and it answers *nothing* for ``.set push`` / ``.set pop``.  A ``.set``
    assignment (``.set sym, expr``) yields tokens that match no state name, so
    it changes nothing.
    """
    m = _SET_DIRECTIVE_RE.match(stripped)
    if m is None:
        return None
    body = m.group(1).split("#", 1)[0]
    return [t.strip() for t in body.split(",") if t.strip()]


def _apply_set_directive(tokens: list[str], reorder: bool,
                         stack: list[bool]) -> bool:
    """Fold one ``.set`` directive into the reorder state; return the new state.

    ``.set push`` saves the reorder state and ``.set pop`` restores it, and
    ``stack`` is mutated in place.  ``godhand/vu0.h`` brackets EVERY COP2 macro
    that way — ``.set push / .set noreorder / <op> / .set pop`` — so a tracker
    that reads only the ``reorder``/``noreorder`` pair latches noreorder at the
    first macro and never leaves it.  Every later insertion in the function is
    then dropped in silence, until cc1 happens to emit an explicit
    ``.set reorder``, which it does after some branches.  That made the failure
    intermittent.  ``findings/23_setpop_defect.py`` reproduces it.
    """
    for tok in tokens:
        if tok == "push":
            stack.append(reorder)
        elif tok == "pop":
            if stack:
                reorder = stack.pop()
        elif tok == "reorder":
            reorder = True
        elif tok == "noreorder":
            reorder = False
    return reorder


def _prev_nop_run(lines: list[str], i: int, limit: int) -> int:
    """How many bare ``nop`` sit directly above *i*, counted up to *limit*."""
    n = 0
    while n < limit and i - n - 1 >= 0 and lines[i - n - 1].strip() == "nop":
        n += 1
    return n


def _block_has_cvt_producing(lines: list[str], div_idx: int, srcs: set[str]) -> bool:
    """Scan backward from *div_idx* within the same straight-line block for a
    ``cvt.*`` writing one of *srcs*.  Stop at a label, branch/jump, or ``.set
    noreorder`` — any basic-block / hand-scheduled boundary.  Retail's
    ``(float)a / (float)b`` divide feeds the div from a cvt in the same block.

    The scan stops tracing a register at its **producer**: the first instruction
    writing it ends that register's search, whatever that instruction is.  Only
    a ``cvt.*`` may answer True; any other writer merely drops the register, and
    the scan gives up once every source is accounted for.  Walking *past* a
    redefinition would credit the div to a cvt whose value it never reads —
    ``cvt.s.w $f0,$f0`` … ``sub.s $f0,$f1,$f0`` … ``div.s $f2,$f0,$f1``, the
    func_001D4258 shape, where retail carries one nop and not the FDIV pair.

    This serves the legacy ``cvtdiv`` rule only.  ``.set push``/``.set pop`` are
    NOT unwound here: a ``vu0.h`` macro always carries a ``.set noreorder``
    inside its push/pop bracket, so the scan stops on that line anyway.
    """
    srcs = set(srcs)
    for j in range(div_idx - 1, -1, -1):
        s = lines[j].strip()
        if s.endswith(":"):            # label = block start
            return False
        toks = _set_directive_tokens(s)
        if toks is not None:
            if "noreorder" in toks:
                return False           # left the reorder region
            continue
        if not _is_asm_instr(s):
            continue
        if _is_branch_or_jump(s):      # control edge = block boundary
            return False
        dest = _fp_dest(lines[j])
        if dest is None or dest not in srcs:
            continue                   # writes no FPR we are tracing
        if _CVT_DEST_RE.match(lines[j]):
            return True                # the producer IS a cvt → Rule B applies
        srcs.discard(dest)             # producer found, and it is not a cvt
        if not srcs:
            return False
    return False


def _fence_divide_before_branch(lines, i) -> bool:
    """True if the divide-class op at *i* is IMMEDIATELY followed by a branch.

    Twin of the ee-cc-wrap.py helper; the two must agree byte-for-byte. The pad
    this pass inserts is a bare ``nop`` inside a ``.set reorder`` region, but the
    vendor cc1 template it reproduces is fenced. So where retail reads
    ``<div.s|sqrt.s|rsqrt.s> ; <branch> ; nop``, ee-as is free to hoist the
    divide-class op into the branch delay slot and the body comes out ONE WORD
    SHORT. 38 such sites sit in 27 unmatched functions.

    The fence is narrow ON PURPOSE. It fires only where a branch follows the op,
    so every already-matched TU that carries the pad in straight-line code is
    untouched.
    """
    for ln in lines[i + 1:]:
        s = ln.strip()
        if not s or s.startswith((".", "#")) or s.endswith(":"):
            continue
        return _is_branch_or_jump(s)
    return False


def _insert_ee_fp_hazard_nops(text: str, rules=None) -> str:
    """Insert the R5900 FP nops cc1 omits, for a --fp-hazard-nops TU.

    *rules* is an iterable of rule names (see ``_FP_RULES_KNOWN``); ``None``
    means ``_FP_RULES_DEFAULT``, which is exactly what the bare
    ``--fp-hazard-nops`` flag has always done.

    ``mtc1`` (Rule A): after ``mtc1``/``dmtc1 $r,$fN`` whose *immediately
    following* real instruction is an FP op reading ``$fN`` as a source, emit
    one nop (GPR->COP1 move latency).

    ``fdiv``: two nops before every ``div.s``, ``sqrt.s`` and ``rsqrt.s``.
    Unconditional, because the cc1 template it reproduces is unconditional.
    When it fires, Rule A is suppressed on the same instruction — the pair
    already separates the ``mtc1`` from its reader, so a third nop would be
    fabricated length.

    ``div1``: one nop before every ``div.s``, ``sqrt.s`` and ``rsqrt.s`` -
    the same instruction class as ``fdiv``, at pad depth 1.  ``fdiv``,
    ``div`` and ``sqrt`` win on any site they also claim.

    ``cvtdiv`` (legacy Rule B): two nops before a ``div.s``/``div.d`` whose FP
    source operand was produced by a ``cvt.*`` earlier in the same straight-line
    block.  ``fdiv`` subsumes it: when both are selected the site takes one
    pair, never two.

    Delay-slot (``.set noreorder``) regions are left untouched, and ``.set
    push``/``.set pop`` are tracked as a stack.  Idempotent.
    """
    rules = _FP_RULES_DEFAULT if rules is None else frozenset(rules)
    want_mtc1 = _FP_RULE_MTC1 in rules
    want_fdiv = _FP_RULE_FDIV in rules
    want_div1 = _FP_RULE_DIV1 in rules
    want_div = _FP_RULE_DIV in rules
    want_sqrt = _FP_RULE_SQRT in rules
    want_cvtdiv = _FP_RULE_CVTDIV in rules
    lines = text.split("\n")
    insert_before = [0] * len(lines)
    fence_site = [False] * len(lines)
    reorder = True
    set_stack: list[bool] = []
    prev_mtc1_dest: str | None = None
    for i, line in enumerate(lines):
        s = line.strip()
        toks = _set_directive_tokens(s)
        if toks is not None:
            reorder = _apply_set_directive(toks, reorder, set_stack)
            prev_mtc1_dest = None
            continue
        if not _is_asm_instr(s):
            if s.endswith(":"):  # label = basic-block boundary, breaks adjacency
                prev_mtc1_dest = None
            continue
        if reorder:
            pad = 0
            two_nop_site = ((want_fdiv and bool(_FDIV_CLASS_RE.match(line)))
                            or (want_div
                                and bool(_DIV_ONLY_CLASS_RE.match(line)))
                            or (want_sqrt
                                and bool(_SQRT_ONLY_CLASS_RE.match(line))))
            # `div1` is the one-nop mirror of `fdiv` over the same class.
            # A two-nop rule wins on any site it also claims, so this stays
            # inert unless the TU names `div1`.
            one_nop_site = (want_div1
                            and bool(_FDIV_CLASS_RE.match(line)))
            is_fdiv_site = two_nop_site or one_nop_site
            if two_nop_site:
                pad = 2
            elif one_nop_site:
                pad = 1
            elif want_cvtdiv:
                dm = _DIV_SRC_RE.match(line)
                if dm and _block_has_cvt_producing(
                        lines, i, {dm.group(1), dm.group(2)}):
                    pad = 2
            # Idempotency guard: pad UP TO the required count, never BY it.
            # SN cc1 emits one of retail's two fdiv nops itself. The old
            # all-or-nothing test asked "are BOTH slots already nops", found
            # one, added two, and the site got THREE — a shape no rule
            # combination could reach (measured on func_0020F3C0). Subtract
            # what is already there instead.
            # Both endpoints are unchanged: 0 existing nops -> full pad,
            # 2 existing nops -> no pad.
            pad -= _prev_nop_run(lines, i, pad)
            if (want_mtc1 and not is_fdiv_site and prev_mtc1_dest is not None
                    and _fp_op_reads(line, prev_mtc1_dest)):
                insert_before[i] += 1  # Rule A
            insert_before[i] += pad
            if pad > 0 and is_fdiv_site:
                fence_site[i] = True
        m = _MTC1_DEST_RE.match(line)
        prev_mtc1_dest = m.group(1) if (m and reorder) else None

    out: list[str] = []
    for i, line in enumerate(lines):
        fence = (insert_before[i] and fence_site[i]
                 and _fence_divide_before_branch(lines, i))
        if fence:
            out.append("\t.set\tpush")
            out.append("\t.set\tnoreorder")
        out.extend(["\tnop"] * insert_before[i])
        out.append(line)
        if fence:
            out.append("\t.set\tpop")
    return "\n".join(out)


# --- Opt-in R5900 call-loop errata-pad INSERTER (--call-loop-pad) ------------
# Twin of the helper in ee-cc-wrap.py; the two must agree byte-for-byte (a
# parity test in .private/tests/test_call_loop_pad.py enforces it).
#
# ee-as pads a single-block backward-conditional loop until it holds at least
# _SHORT_LOOP_MIN_PRE instructions before the branch (the R5900 short-loop
# errata; patches/ee-as/02 pins the minimum to retail's 4).  But it SKIPS that
# pad whenever the loop body contains a call -- proven with .set noreorder
# probes: a call-free body pads, a body holding a %hi relocation pads, a body
# holding jal or jalr does not.  Retail's assembler padded them in game code,
# so those functions are unmatchable no matter what C we write.
#
# This pass inserts the missing pad for a TU that opted in.  ee-as still sees
# the call and still declines to pad, so there is no double-pad: it merely fixes
# up the branch displacement around our nops.  Verified end-to-end against real
# ee-as output (see the spec).
_SHORT_LOOP_MIN_PRE = 4

_CALL_MNEMONICS = frozenset({"jal", "jalr"})

# Conditional branches only.  An unconditional `b` backward is not the
# single-block conditional loop the errata concerns.  The branch-and-link forms
# (bltzal/bgezal) are deliberately absent from BOTH this set and
# _CALL_MNEMONICS: a body containing one falls through to _is_branch_or_jump and
# the loop is rejected as multi-block.  That is conservative (we decline to pad
# rather than risk mis-padding), and cc1 never emits them.
_COND_BRANCHES = frozenset({
    "beq", "bne", "beqz", "bnez", "bgez", "bgtz", "blez", "bltz",
    "beql", "bnel", "beqzl", "bnezl", "bgezl", "bgtzl", "blezl", "bltzl",
    "bc1t", "bc1f", "bc1tl", "bc1fl",
})

_LOCAL_LABEL_RE = re.compile(r"^(\$L\w+|\.L\w+):")
# `0($4)`, `-8($sp)`, `0x10($3)` -> one word.  A symbol (`glob`, `glob+4($3)`)
# makes the op a .set macro expansion (lui + op) -> two words.
_REG_OFFSET_RE = re.compile(r"^[-+]?(?:0[xX][0-9a-fA-F]+|\d+)?\(\$\w+\)$")
_MEM_OPS = frozenset({
    "lb", "lbu", "lh", "lhu", "lw", "lwu", "lwl", "lwr", "ld", "ldl", "ldr",
    "lq", "sb", "sh", "sw", "swl", "swr", "sd", "sdl", "sdr", "sq",
    "lwc1", "swc1", "ldc1", "sdc1",
})


def _strip_comment(line: str) -> str:
    """Drop cc1's trailing `# 0x4`-style comment and surrounding whitespace."""
    return line.split("#", 1)[0].strip()


def _insn_words(stripped: str, macro_on: bool) -> int:
    """How many machine words *stripped* assembles to.

    ee-as counts emitted instructions, not source lines, when it applies the
    short-loop pad, and cc1 leaves loop bodies in a ``.set macro`` region where
    a few forms expand to two words.  Counting lines would silently mis-pad a
    body holding, say, ``lw $2,glob``.  Unknown mnemonics cost one word.
    """
    if not macro_on:
        return 1  # macros are disabled; every line is one instruction
    parts = stripped.split(None, 1)
    if not parts:
        return 0
    mnem, rest = parts[0], (parts[1] if len(parts) > 1 else "")
    if mnem in ("la", "dla"):
        return 2  # lui + addiu
    if mnem in ("li", "dli"):
        val = rest.split(",")[-1].strip()
        try:
            n = int(val, 0)
        except ValueError:
            return 2  # li of a symbol -> lui + ori
        # one word iff it fits a single addiu (signed 16) or ori (unsigned 16)
        return 1 if -0x8000 <= n <= 0xFFFF else 2
    if mnem in _MEM_OPS:
        addr = rest.split(",", 1)[1].strip() if "," in rest else ""
        return 1 if _REG_OFFSET_RE.match(addr) else 2
    return 1


def _plan_call_loop_pads(lines: list[str]) -> dict[int, int]:
    """Map {index of a branch line -> how many nops to insert before it}.

    A loop qualifies when its body (target label .. branch, exclusive) contains
    a call, contains no other control transfer (multi-block loops are out of
    scope), and assembles to fewer than _SHORT_LOOP_MIN_PRE words.
    """
    labels: dict[str, int] = {}
    macro_at: list[bool] = []
    reorder_at: list[bool] = []
    macro_on = True
    reorder_on = True  # cc1 emits code in .set reorder by default
    for i, line in enumerate(lines):
        s = _strip_comment(line)
        if s.startswith(".set"):
            if "nomacro" in s:
                macro_on = False
            elif "macro" in s:
                macro_on = True
            # "noreorder" contains "reorder"; test the negative form first.
            if "noreorder" in s:
                reorder_on = False
            elif "reorder" in s:
                reorder_on = True
        macro_at.append(macro_on)
        reorder_at.append(reorder_on)
        m = _LOCAL_LABEL_RE.match(s)
        if m:
            labels[m.group(1)] = i

    plan: dict[int, int] = {}
    for i, line in enumerate(lines):
        s = _strip_comment(line)
        if not _is_asm_instr(s):
            continue
        parts = s.split(None, 1)
        if parts[0] not in _COND_BRANCHES or len(parts) < 2:
            continue
        target = parts[1].split(",")[-1].strip()
        start = labels.get(target)
        if start is None or start >= i:
            continue  # forward branch, or a target we cannot see

        words = 0
        has_call = False
        multi_block = False
        for j in range(start + 1, i):
            body = _strip_comment(lines[j])
            if not _is_asm_instr(body):
                continue
            mnem = body.split(None, 1)[0]
            if mnem in _CALL_MNEMONICS:
                has_call = True
            elif _is_branch_or_jump(body):
                multi_block = True
                break
            words += _insn_words(body, macro_at[j])

        # A branch emitted in a `.set reorder` region carries no explicit delay
        # slot: ee-as fills it, and does so by pulling in the nop immediately
        # before the branch — stealing one of our pads. Retail's call-loops of
        # this shape (single-arg list walks `while(p){f(p); p=*p;}`, arg-busy
        # loops `while(f(0)==0)`) still carry the errata pad, so plan one extra
        # nop for ee-as to consume as the delay slot, leaving _SHORT_LOOP_MIN_PRE
        # real words before the branch. The matched noreorder loops (cc1 emits
        # their delay slot explicitly, so nothing is stolen) keep min_pre = 4 and
        # are unaffected — proven by the retail-ELF byte-identity gate.
        min_pre = _SHORT_LOOP_MIN_PRE + (1 if reorder_at[i] else 0)
        if multi_block or not has_call or words >= min_pre:
            continue
        plan[i] = min_pre - words
    return plan


def _insert_call_loop_pads(text: str) -> str:
    """Insert the R5900 short-loop pad ee-as omits for call-bearing loops.

    Idempotent: the nops this adds are themselves counted on a second pass, so
    an already-padded loop is at the minimum and gets nothing more.

    The fixed-point loop is defensive.  Under the current predicate an
    enclosing loop necessarily contains the inner loop's branch, so it is
    multi-block and skipped -- inner padding can never change a loop we would
    pad, and this converges in one sweep.  Keep the loop so the invariant
    survives a future widening of the multi-block rule.
    """
    lines = text.split("\n")
    for _ in range(16):
        plan = _plan_call_loop_pads(lines)
        if not plan:
            break
        out: list[str] = []
        for i, line in enumerate(lines):
            out.extend(["\tnop"] * plan.get(i, 0))
            out.append(line)
        lines = out
    return "\n".join(lines)


# One cc1-emitted switch jump table: a `.rdata` block holding the table
# label and its `.word $Ln` case entries, closed by the switch-back to the
# text section — plain `.text`, or `.section .text.<fn>,...` when the
# function carries a section attribute (every carved TU does). gcc 2.9x
# (SN and cygnus alike) emits exactly this shape on MIPS.
_JTBL_BLOCK_RE = re.compile(
    r"\n\t\.rdata\n\t\.align\t\d+\n(\$L\d+):\n(?:\t\.word\t\$L\d+\n)+"
    r"\t\.(?:text\n|section \.text[^\n]*\n)")


def _externalize_jump_tables(text: str, syms: list[str]) -> str:
    """Replace cc1-emitted switch jump tables with the split rodata blob's
    retail symbols (``--extern-jtbl``, in table-emission order).

    The split blob already carries every dispatcher's table bytes as raw
    ``.word`` retail addresses; letting the TU link its own copy would
    append 4*N bytes to ``.rodata`` and shift everything behind it. So the
    emitted ``.rdata`` block is deleted and every ``%hi/%lo($Ln)`` of the
    table label in the remaining text is redirected to the blob symbol —
    the dispatcher's lui/addiu then resolve to the retail table address.
    The function's case labels stay local; nothing else changes, so the
    ``.text`` bytes are exactly what the scorer already byte-verified.
    """
    idx = 0
    while True:
        m = _JTBL_BLOCK_RE.search(text)
        if not m:
            break
        if idx >= len(syms):
            die(f"--extern-jtbl: cc1 emitted more jump tables than symbols "
                f"given (table {idx + 1} has no mapping)")
        label = re.escape(m.group(1))
        text = text[:m.start()] + "\n" + text[m.end():]
        text = re.sub(r"(%(?:hi|lo)\()" + label + r"(\))",
                      r"\g<1>" + syms[idx] + r"\g<2>", text)
        # Bare macro-operand table refs (`lw $3,$L12($2)`) — cygnus cc1
        # emits these instead of a %hi/%lo pair; harden the SN twin the
        # same way (the block is deleted, so any surviving reference is
        # a table ref; lookahead keeps $L120 etc. intact).
        text = re.sub(r"(?<![\w$])" + label + r"(?![\d:])", syms[idx], text)
        idx += 1
    if idx < len(syms):
        die(f"--extern-jtbl: {len(syms)} symbol(s) given but cc1 emitted "
            f"only {idx} jump table(s)")
    # Postcondition: no switch-table entry may survive. The count-check above
    # can't catch a table the block regex MISSES while the emitted count still
    # lines up with the symbol list (an extra or differently-formatted table).
    # A residual `.word $L<n>` is exactly that — refuse rather than emit a TU
    # that would link its own table copy and shift .rodata.
    if re.search(r"\n\t\.word\t\$L\d+\n", text):
        die("--extern-jtbl: a `.word $L` jump-table entry survived externalization "
            "(the switch-table regex missed a block — likely a new switch-back / "
            "section format); refusing to emit a TU that would relink its own table")
    return text


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
    p.add_argument(
        "--extern-jtbl", dest="extern_jtbl", action="append", default=[],
        metavar="SYM",
        help="Externalize the Nth cc1-emitted switch jump table to SYM "
             "(repeatable, applied in table-emission order): delete the "
             ".rdata table block and redirect its %%hi/%%lo references to "
             "SYM. The split rodata blob supplies the retail table bytes; "
             "a duplicate TU copy would shift .rodata. See compile_config "
             "compile_units[].extern_jtbl.")
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
        help="REJECTED on this route (see main()); the flag exists only so "
             "this wrapper accepts ee-cc-wrap.py's argv shape",
    )
    p.add_argument(
        "--asm-only",
        action="store_true",
        help="Stop after cc1; emit .s instead of .o (smoke-test mode)",
    )
    p.add_argument(
        "--fp-hazard-nops", dest="fp_hazard_nops", action="store_true",
        help="Insert the R5900 mtc1->cvt and cvt->div FP hazard nops SN cc1 "
             "omits (opt-in per-TU; twin of ee-cc-wrap.py's flag). See "
             "compile_units[].fp_hazard_nops.",
    )
    p.add_argument(
        "--fp-hazard-rules", dest="fp_hazard_rules", default=None,
        metavar="RULES",
        help="Comma-separated rule set for the FP hazard inserter; implies "
             "--fp-hazard-nops. 'mtc1' = one nop after an mtc1/dmtc1 whose "
             "next instruction reads the moved FPR. 'fdiv' = two nops before "
             "EVERY div.s/sqrt.s/rsqrt.s (the vendor cc1 output template "
             "behind -mhandle-ee-div-pipeline-bug). 'div1' = ONE nop "
             "before the same class, for the 62 retail divide sites "
             "at pad depth 1. 'cvtdiv' = the legacy "
             "cvt->div rule, kept only for the TUs already byte-verified "
             "under it. Default (the bare flag): mtc1,cvtdiv. Twin of "
             "ee-cc-wrap.py's flag.",
    )
    p.add_argument(
        "--call-loop-pad", dest="call_loop_pad", action="store_true",
        help="Insert the R5900 short-loop errata pad ee-as omits for backward "
             "loops whose body contains a call (jal/jalr); retail's assembler "
             "padded them. Pads to 4 insns before the branch. Opt-in per-TU "
             "and byte-verified (the prebuilt-library band at 0x32xxxx-0x33xxxx "
             "is genuinely unpadded, so this must never be global). Twin of "
             "ee-cc-wrap.py's flag. See compile_units[].call_loop_pad.",
    )
    p.add_argument(
        "--assembler", dest="assembler", choices=("ee", "sn"), default="ee",
        help="Which assembler runs stage 4. 'ee' (default) uses the Cygnus "
             "ee-as 2.10 backend this wrapper has always used. 'sn' uses SN "
             "Systems' ps2eeas.exe under wibo, whose `dli` expansion is "
             "MSB-first (`ori rX,$zero,hi; dsll rX,n; ori rX,rX,lo`) where "
             "ee-as emits lui/ori + fixed dsll16 steps — retail matches "
             "ps2eeas at all 551 strict-chain sites. ee-cc-wrap.py's 'gnu' "
             "route has no SN implementation and is rejected there rather "
             "than dropped here. Opt-in per-TU via compile_units[].as.",
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

    # --fp-hazard-rules implies --fp-hazard-nops, and a typo must die here
    # rather than silently drop the rule the caller asked for.
    if args.fp_hazard_rules is not None:
        args.fp_hazard_nops = True
    try:
        fp_hazard_rules = _parse_fp_hazard_rules(args.fp_hazard_rules)
    except ValueError as exc:
        die(str(exc))

    if not args.asm_only and not args.c:
        die("either -c or --asm-only is required")

    # ``--no-line-info`` was mirrored from ee-cc-wrap.py in 2026-05-27 so this
    # wrapper would accept the same argv shape. The ``-P`` the flag names was
    # never added to the cpp0 command, so the parser read the flag and then
    # discarded it in silence, and a caller who passed it got unstripped line
    # info while it believed the opposite. Issue 60 measured that.
    #
    # Refuse rather than implement. ``-P`` removes cpp0's line markers, and SN
    # cc1 then names its own INPUT in the ``.file`` directive — an absolute
    # path inside this wrapper's RANDOM tempdir. Both the ``.s`` and the ``.o``
    # then change on every run, which is the opposite of what a flag called
    # "for reproducible builds" must do. ee-cc-wrap.py escapes this because it
    # runs cc1 and ee-as with ``cwd=tempdir`` and a stable BASENAME; this
    # wrapper passes absolute tempdir paths. Give it the same treatment and
    # ``-P`` becomes correct here — measure that change against the object
    # sha256 of every SN TU before you land it.
    #
    # ``compile.py`` never passes this flag, so the refusal moves no build
    # byte. It only turns a silent wrong answer into a named one.
    if args.no_line_info:
        die("--no-line-info is not implemented on the SN route. It was "
            "accepted and silently ignored until issue 60. cpp0 -P would make "
            "SN cc1 stamp this wrapper's random tempdir into the .file "
            "directive, so the .s and the .o would change on every run. Use "
            "--compiler cygnus-2.96 / ee-2.9-991111 for a line-info-free "
            "compile, or drop the flag.")

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
        # wibo checks only whether WIBO_DEBUG is PRESENT, not its value, so the
        # old `env.setdefault("WIBO_DEBUG", "0")` here turned wibo's debug
        # trace ON for every compile (326 lines on stdout) — and the paired
        # `stderr=DEVNULL` then hid the hosted tool's real diagnostic. That
        # combination is exactly why ps2eeas failures had to be grepped out of
        # wibo's stdout trace by hand (notes/110).
        # Inherit the env instead: unset is silent, and a caller who exports
        # WIBO_DEBUG deliberately still gets the trace. Capture stderr and
        # replay it only on failure, so a clean build stays quiet.
        try:
            result = subprocess.run(cc1_cmd, check=False,
                                    stderr=subprocess.PIPE)
        except FileNotFoundError as exc:
            die(f"cc1: missing binary {exc.filename!r}")
        if result.returncode != 0:
            if result.stderr:
                sys.stderr.buffer.write(result.stderr)
                sys.stderr.flush()
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
        # commented #nop EE hazard hints into real nops first. When the TU
        # opted in via --extern-jtbl, first delete cc1's emitted switch
        # jump table(s) and redirect their %hi/%lo references to the split
        # rodata blob's symbols (the blob already carries the retail table
        # bytes as raw words; a duplicate TU copy would shift .rodata).
        s_text = s_path.read_text()
        if args.extern_jtbl:
            s_text = _externalize_jump_tables(s_text, args.extern_jtbl)
        s_text = _materialize_hazard_nops(
            s_text, fp_hazard_rules if args.fp_hazard_nops else None)
        # Opt-in FP hazard-nop INSERTER, after materialize so an already-
        # materialised nop breaks Rule A's mtc1->consumer adjacency (no double
        # insertion). Per-TU via compile_units fp_hazard_nops. Runs on ABI reg
        # names (it only inspects $fN + mnemonics, both numerize-invariant).
        if args.fp_hazard_nops:
            s_text = _insert_ee_fp_hazard_nops(s_text, fp_hazard_rules)
        # Opt-in call-loop errata pad, LAST: it counts loop-body instructions,
        # so it must run after every pass that can add one. Numerize-invariant
        # (it inspects only mnemonics and labels).
        if args.call_loop_pad:
            s_text = _insert_call_loop_pads(s_text)
        s_num_path.write_text(_numerize(s_text))

        # Stage 4: assemble via Cygnus ee-as (same backend ee-cc-wrap.py
        # uses; consistent with how the existing .o mirror is built).
        # `-mabi=eabi` makes ee-as set ELF flag 0x4000 (eabi64) so the
        # output flags (0x20924001) match retail SLUS_215.03 — same
        # rationale as ee-cc-wrap.py's stage-3 comment. Forward user -I
        # for INCLUDE_ASM resolution; add the launch cwd as ee-as -I so
        # `.include "include/include_asm.h"` still resolves when ee-as
        # runs from tempdir (.mdebug-determinism fix — same
        # justification as ee-cc-wrap.py).
        if args.assembler == "sn":
            # Opt-in stage-4 route: SN Systems' ps2eeas.exe under wibo instead
            # of ee-as, for the `dli` MSB-first expansion retail used (issue
            # 10). ee-cc-wrap.py forwards --assembler here rather than dropping
            # it, so an SN-compiler TU carrying as: "sn" cannot silently
            # assemble with ee-as and present the wrong bytes as this route's
            # output. Same guards and same flag set as ee-cc-wrap.py's branch —
            # no -EL, no -mabi= (ps2eeas rejects both with exit 3).
            if not PS2EEAS.exists():
                die(f"--assembler sn: ps2eeas.exe missing at {PS2EEAS} — "
                    f"run scripts/setup_toolchain.sh")
            if not WIBO.exists():
                die(f"--assembler sn: wibo missing at {WIBO} — "
                    f"run scripts/setup_toolchain.sh")
            if ".pushsection" in s_num_path.read_text():
                die("--assembler sn: ps2eeas cannot parse .pushsection; this "
                    "TU still contains INCLUDE_ASM. Carve the function "
                    "standalone, or use as: ee.")
            # Do NOT set WIBO_DEBUG here (see the cc1 stage above: wibo tests
            # for presence, not value, so setting it to "0" enables the
            # trace). Unset, wibo is silent and ps2eeas's own
            # `file.s(N) : Error : ...` reaches the inherited stderr.
            as_cmd = [str(WIBO), str(PS2EEAS), f"-G{args.sdata_thresh}"]
            as_stage = "ps2eeas"
        else:
            as_cmd = [
                str(EE_AS),
                "-EL",
                "-mips3",
                "-mcpu=5900",
                "-mabi=eabi",
                f"-G{args.sdata_thresh}",
            ]
            as_stage = "ee-as"
        for inc in args.includes:
            as_cmd.append(f"-I{inc}")
        as_cmd += [
            f"-I{LAUNCH_CWD}",
            f"-I{LAUNCH_CWD / 'include'}",
            f"-I{LAUNCH_CWD / 'build' / 'asm'}",
            str(s_num_path),
            "-o", str(output),
        ]
        run(as_cmd, as_stage)
        if as_stage == "ps2eeas":
            # See ee-cc-wrap.py's twin call: ps2eeas writes .symtab's sh_info
            # one short of the first global, and GNU ld refuses the object.
            # Lossless header repair — no section byte moves.
            sys.path.insert(0, str(Path(__file__).resolve().parent))
            import ps2eeas_objfix
            try:
                ps2eeas_objfix.repair_symtab_info(output)
            except ps2eeas_objfix.ObjFixError as exc:
                die(f"ps2eeas: {exc}")

        # Optional: side-export the (numerized) .s for debugging.
        if "s" in args.print_stage:
            shutil.copy2(s_num_path, output.with_suffix(".s"))

    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
