#!/usr/bin/env python3
"""ee-gcc 2.96 driver replacement for matching decompilation of God Hand.

The SCE PS2 SDK 3.0.20 ``ee-gcc`` driver shipped in
``decompme/compilers / ee-gcc2.96.tar.xz`` segfaults on this host's kernel
during its fork+exec to ``cc1``.  The crash happens inside the forked child
*before* ``execve("cc1", …)`` is called, so the parent driver mis-reports it
as "Internal error: Segmentation fault (program cc1)".

The fix is to invoke the sub-binaries directly:

    cpp0  → preprocesses .c/.cc into .i  (preserves comments and #line info)
    cc1   → compiles .i into .s          (cc1 for C, cc1plus for C++)
    ee-as → assembles .s into .o         (SCE EE assembler, produces eabi64)

This script mirrors a small subset of the ``gcc`` command-line interface,
sufficient for the matching-decomp build:

    ee-cc-wrap.py [-x c|c++] -c [-o OUT.o] [-O0|-O2|...] [-g] [-G N]
                  [-Dname[=val]]... [-Iincludedir]... [--print-stage]...
                  [--compiler {cygnus-2.96,sn-2.95.3-136}]
                  INPUT.c

If ``--print-stage`` is given, prints the intermediate file paths instead of
deleting them — handy when diffing assembly during matching work.

``--compiler`` selects which cc1 frontend is invoked.
Default = ``cygnus-2.96`` (this wrapper's native path, back-compat with
every existing TU).  ``sn-2.95.3-136`` re-execs ``scripts/sn-cc-wrap.py``
with equivalent arguments — the SN ee-gcc cc1 (Win32 PE, runs under
wibo) emits the ``sq`` callee-save shape retail needs for the
``sq``-prologue group.  Both wrappers share
the Cygnus 2.96 cpp0 preprocessor and the Cygnus ee-as 2.10 assembler so
the resulting .o ELF flags (0x20924001, eabi64) match retail regardless
of which cc1 produced the intermediate .s.
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
COMPILER = ROOT / "compiler" / "linux" / "ee" / "gcc"
GCCLIB_PREFIX = COMPILER / "lib" / "gcc-lib" / "ee" / "2.96-ee-001003-1"

CPP0 = GCCLIB_PREFIX / "cpp0"
CC1 = GCCLIB_PREFIX / "cc1"
CC1PLUS = GCCLIB_PREFIX / "cc1plus"
# Older Sony/Cygnus ee-gcc 2.9-991111-01 cc1 (Linux native).  This is the
# compiler the PS2 SDK used to build its statically-linked newlib: it emits
# 64-bit `sd` callee-saves in 16-byte (quadword) stack slots, the prologue
# shape retail's mprec/dtoa functions need — which neither cygnus-2.96 (sd /
# 8-byte slots) nor SN 2.95.3-136 (sq / 16-byte slots) reproduces.  Shares
# this wrapper's cpp0 + ee-as backends; emits cygnus-style numeric register
# names, so no numerize stage is required (unlike sn-cc-wrap.py).
CC1_991111 = COMPILER / "lib" / "gcc-lib" / "ee" / "2.9-ee-991111-01" / "cc1"
# C++ sibling of CC1_991111 (same archive).  The retail C++ iostream/streambuf/
# filebuf runtime carries the same sd-in-16-byte-slot prologue as the newlib C
# group, so its cc1plus is the correct-lineage C++ compiler (cygnus-2.96 cc1plus
# emits sd/8-byte slots, SN cc1plus emits sq/16-byte — both wrong shape).
CC1PLUS_991111 = COMPILER / "lib" / "gcc-lib" / "ee" / "2.9-ee-991111-01" / "cc1plus"
# Sibling-lineage variant cc1s (decompme/compilers release bucket). Same
# cpp0 + ee-as backends as the three primary compilers; only the cc1 stage
# differs. Used to screen scheduler/reg-alloc near-miss ties that resist
# all three primaries — the retail build may have used a sibling SN BUILD
# or ee-2.9 snapshot. Keys map to a gcc-lib dir holding cc1/cc1plus.
# (2.9-ee-991111-dtls13010's cc1 is a shell shim exec'ing cc1.bin through
# its bundled ld-2.3.6.so; the loader + libc live in gcc/lib/.)
_GCCLIB_EE = COMPILER / "lib" / "gcc-lib" / "ee"
CC1_VARIANT_DIRS = {
    "ee-2.9-990721": _GCCLIB_EE / "2.9-ee-990721",
    "ee-2.9-991111-plain": _GCCLIB_EE / "2.9-ee-991111",
    "ee-2.9-991111a": _GCCLIB_EE / "2.9-ee-991111a",
    "ee-2.9-991111-dtls": _GCCLIB_EE / "2.9-ee-991111-dtls13010",
    "ee-3.2-030926": _GCCLIB_EE / "3.2-ee-030926",
    "ee-3.2-040921": _GCCLIB_EE / "3.2-ee-040921",
}
# SN sibling builds (Win32 PE, run via wibo like sn-2.95.3-136). Values are
# the gcc-lib dir names under compiler/windows/ee/gcc/lib/gcc-lib/ee/;
# forwarded to sn-cc-wrap.py via the GH_SN_GCCLIB environment variable.
SN_VARIANT_DIRS = {
    "sn-2.95.3-114": "2.95.3-sn-114",
    "sn-2.95.3-107": "2.95.3-sn-107",
    "sn-2.95.2-273a": "2.95.2-sn-273a",
    "sn-2.95.2-274": "2.95.2-sn-274",
}
# gcc 2.9-lineage cc1s all predate -freorder-blocks (exit 33 "Invalid
# option"); the flag must be dropped for every member, exactly as the
# primary ee-2.9-991111 path already does. gcc 3.2 accepts the flag.
_NO_FREORDER_COMPILERS = frozenset(
    {"ee-2.9-991111"} | {k for k in CC1_VARIANT_DIRS if k.startswith("ee-2.9-")}
)
EE_AS = COMPILER / "bin" / "ee-as"
EE_DVP_AS = COMPILER / "bin" / "ee-dvp-as"

# Capture the cwd at import time.  compile.py invokes us with cwd=repo root,
# which is splat's `base_path` — the directory that splat's auto-generated
# `.include "include/<file>.inc"` paths in `include/include_asm.h` are
# resolved relative to.  We pass this as an -I to ee-as below so its
# `.include` resolver finds those files even though we run ee-as from a
# tempdir (for `.mdebug` determinism).  Doing it here, before any tempdir
# chdir, keeps the value stable regardless of subprocess plumbing.
LAUNCH_CWD = Path.cwd().resolve()

# Match the predefined macros the original SCE ee-gcc driver passes to cc1.
# Sourced from `ee-gcc -v -c trivial.c` on this very host before the driver
# crashed; verified with `cpp0 -dM -E /dev/null`.
SCE_EE_PREDEFINES = [
    "-D__GNUC__=2",
    "-D__GNUC_MINOR__=96",
    "-D__GNUC_PATCHLEVEL__=0",
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
    "-D__mips",
    "-D__MIPSEL",
    "-D__R5900",
    "-D__LANGUAGE_C",
    "-D_LANGUAGE_C",
    "-DLANGUAGE_C",
    "-D__SIZE_TYPE__= unsigned int",
    "-D__PTRDIFF_TYPE__= int",
    "-D__LONG_MAX__=9223372036854775807L",
    "-U__mips",
    "-D__mips=3",
    "-D__mips64",
    "-D__mips_eabi",
    "-D__mips_single_float",
]


def die(msg: str, code: int = 1) -> None:
    print(f"ee-cc-wrap: {msg}", file=sys.stderr)
    sys.exit(code)


_HAZARD_FP_CMP_RE = re.compile(r"^\s*c\.[a-z]+\.[sd]\b")


def _is_ee_fp_hazard_producer(line: str) -> bool:
    """True if *line* is an EE FP op whose result a following op stalls on.

    Two R5900 hazards need a nop that cc1 only emits as a commented ``#nop``:
    a GPR->COP1 move (``mtc1``/``ctc1``) feeding an FP op, and an FP compare
    (``c.<cond>.s``) feeding a ``bc1*`` branch.  FP *loads* (lwc1/l.s) and
    integer loads interlock on the R5900, so their ``#nop`` hints are NOT
    materialised (retail didn't) — restricting to these two producers keeps
    every already-matched function byte-identical.
    """
    op = line.strip()
    return op.startswith(("mtc1", "ctc1", "li.s", "li.d")) or bool(_HAZARD_FP_CMP_RE.match(line))


def _materialize_hazard_nops(s_path: Path) -> None:
    """Turn cc1's commented ``#nop`` EE FP hazard hints into real nops.

    The EE cc1 (cygnus-2.96, sn-2.95.3-136, 2.9-991111) emits a bare ``#nop``
    comment wherever the pipeline needs a stall but defers materialisation to a
    reorder-capable assembler.  Our ee-as does not reorder, so the nop is lost
    — fine for everything except functions with a real mtc1->FPU or
    FP-compare->branch hazard (currently left as INCLUDE_ASM).  We uncomment
    only the ``#nop`` whose *preceding* instruction is one of those two EE FP
    hazard producers, reproducing retail's nops without touching anything else.
    """
    text = s_path.read_text()
    if "#nop" not in text:
        return
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
    s_path.write_text("\n".join(out))


# --- Opt-in EE FP hazard-nop INSERTER (--fp-hazard-nops) ---------------------
# Twin of the helper in sn-cc-wrap.py; the two must agree byte-for-byte so the
# same source matches under either cc1 frontend.  Unlike _materialize_hazard_nops
# (which only uncomments a #nop cc1 already placed), this pass INSERTS the nops
# our cc1 frontends omit entirely, for a TU that opted in.  See
# .private/tests/test_fp_hazard_insert.py for the full spec.
_FPR_RE = re.compile(r"\$f\d+")
_MTC1_DEST_RE = re.compile(r"^\s*d?mtc1\s+\$\w+\s*,\s*(\$f\d+)\b")
_CVT_DEST_RE = re.compile(r"^\s*cvt\.[a-z0-9.]+\s+(\$f\d+)\b")
_DIV_SRC_RE = re.compile(r"^\s*div\.[sd]\s+\$f\d+\s*,\s*(\$f\d+)\s*,\s*(\$f\d+)")
_FP_CONSUMER_RE = re.compile(
    r"^\s*(abs|neg|sqrt|rsqrt|mov|cvt|trunc|round|ceil|floor"
    r"|add|sub|mul|div|madd|msub|max|min|rint|c)\.[a-z0-9.]*\b(.*)$")


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


def _block_has_cvt_producing(lines: list[str], div_idx: int, srcs: set[str]) -> bool:
    """Scan backward from *div_idx* within the same straight-line block for a
    ``cvt.*`` writing one of *srcs*.  Stop at a label, branch/jump, or ``.set
    noreorder`` — any basic-block / hand-scheduled boundary.  Retail's
    ``(float)a / (float)b`` divide feeds the div from a cvt in the same block.
    """
    for j in range(div_idx - 1, -1, -1):
        s = lines[j].strip()
        if s.endswith(":"):            # label = block start
            return False
        if s.startswith(".set"):
            if "noreorder" in s:
                return False           # left the reorder region
            continue
        if not _is_asm_instr(s):
            continue
        if _is_branch_or_jump(s):      # control edge = block boundary
            return False
        cm = _CVT_DEST_RE.match(lines[j])
        if cm and cm.group(1) in srcs:
            return True
    return False


def _insert_ee_fp_hazard_nops(text: str) -> str:
    """Insert the R5900 FP hazard nops cc1 omits, for a --fp-hazard-nops TU.

    Rule A (mtc1->cvt): after ``mtc1``/``dmtc1 $r,$fN`` whose *immediately
    following* real instruction is an FP op reading ``$fN`` as a source, emit
    one nop (GPR->COP1 move latency).

    Rule B (cvt->div): before a ``div.s``/``div.d`` whose FP source operand was
    produced by a ``cvt.*`` earlier in the same straight-line block, emit two
    nops (the FDIV operand-setup latency cygnus-2.96/ee-2.9 schedule but sn
    omits).

    Delay-slot (``.set noreorder``) regions are left untouched.  Idempotent.
    """
    lines = text.split("\n")
    insert_before = [0] * len(lines)
    reorder = True
    prev_mtc1_dest: str | None = None
    for i, line in enumerate(lines):
        s = line.strip()
        if s.startswith(".set"):
            if "noreorder" in s:
                reorder = False
            elif "reorder" in s:
                reorder = True
            prev_mtc1_dest = None
            continue
        if not _is_asm_instr(s):
            if s.endswith(":"):  # label = basic-block boundary, breaks adjacency
                prev_mtc1_dest = None
            continue
        if reorder:
            if prev_mtc1_dest is not None and _fp_op_reads(line, prev_mtc1_dest):
                insert_before[i] += 1  # Rule A
            dm = _DIV_SRC_RE.match(line)
            if dm:
                srcs = {dm.group(1), dm.group(2)}
                # Idempotency guard: if the two slots before the div are already
                # nops, Rule B has already run — don't stack more.
                already = (i >= 2 and lines[i - 1].strip() == "nop"
                           and lines[i - 2].strip() == "nop")
                if not already and _block_has_cvt_producing(lines, i, srcs):
                    insert_before[i] += 2  # Rule B
        m = _MTC1_DEST_RE.match(line)
        prev_mtc1_dest = m.group(1) if (m and reorder) else None

    out: list[str] = []
    for i, line in enumerate(lines):
        out.extend(["\tnop"] * insert_before[i])
        out.append(line)
    return "\n".join(out)


def _insert_ee_fp_hazard_nops_file(s_path: Path) -> None:
    """In-place application of :func:`_insert_ee_fp_hazard_nops` to ``s_path``."""
    s_path.write_text(_insert_ee_fp_hazard_nops(s_path.read_text()))


# --- Opt-in R5900 call-loop errata-pad INSERTER (--call-loop-pad) ------------
# Twin of the helper in sn-cc-wrap.py; the two must agree byte-for-byte (a
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


def _insert_call_loop_pads_file(s_path: Path) -> None:
    """In-place application of :func:`_insert_call_loop_pads` to ``s_path``."""
    s_path.write_text(_insert_call_loop_pads(s_path.read_text()))


def _strip_cxx_frame_block(text: str) -> str:
    """Remove ee-gcc 2.9's per-TU DWARF frame block from a cc1plus ``.s``.

    ee-gcc 2.9 cc1plus emits, as the *last* thing in the assembly, an
    unconditional EH/unwind frame block.  Its shape is always::

        .data                       # its own section re-entry
        .align 2
        .globl _GLOBAL_$F$<sym>
    _GLOBAL_$F$<sym>:
    __FRAME_BEGIN__:
        ...CIE + one FDE per function...
        .4byte 0x0                  # frame-table terminator
        .align 0

    The block is identified by its ``__FRAME_BEGIN__`` anchor and is the
    final emission of the TU (all real program ``.data`` — initialized
    globals, vtables, typeinfo, string literals — is emitted *earlier*).
    We cut from the block's introducing ``.data`` (the section-switch that
    immediately precedes the ``_GLOBAL_$F$``/``__FRAME_BEGIN__`` labels)
    through end-of-file, preserving every earlier line.  This is surgical:
    unlike ``objcopy --remove-section .data`` it keeps real program ``.data``.

    Returns the input unchanged if no frame block is present (no-op for any
    ``.s`` without ``__FRAME_BEGIN__``).
    """
    lines = text.split("\n")
    begin = next(
        (i for i, ln in enumerate(lines) if ln.strip() == "__FRAME_BEGIN__:"),
        None,
    )
    if begin is None:
        return text  # no frame block to strip
    # Walk backwards from __FRAME_BEGIN__ over the frame's preamble to the
    # section-switch directive that introduces it, so we don't leave a
    # dangling `.globl`/label or an empty `.data` re-entry behind.
    start = begin
    j = begin - 1
    while j >= 0:
        s = lines[j].strip()
        if s == "":
            j -= 1
            continue
        if s == ".data" or (s.startswith(".section") and ".data" in s):
            start = j  # the frame block's introducing section directive
            break
        if (
            (s.startswith("_GLOBAL_$F$") and s.endswith(":"))
            or (s.startswith(".globl") and "_GLOBAL_$F$" in s)
            or s.startswith(".align")
        ):
            start = j
            j -= 1
            continue
        break  # hit real content — stop; don't over-consume program data
    del lines[start:]  # the frame block is always last → cut to EOF
    return "\n".join(lines).rstrip("\n") + "\n"


# One cc1-emitted switch jump table: a `.rdata` block holding the table
# label and its `.word $Ln` case entries, closed by the switch-back to the
# text section — plain `.text`, or `.section .text.<fn>,...` when the
# function carries a section attribute (every carved TU does). gcc 2.9x
# (cygnus and SN alike) emits exactly this shape on MIPS.
_JTBL_BLOCK_RE = re.compile(
    r"\n\t\.rdata\n\t\.align\t\d+\n(\$L\d+):\n(?:\t\.word\t\$L\d+\n)+"
    r"\t\.(?:text\n|section \.text[^\n]*\n)")


def _externalize_jump_tables(s_path: Path, syms: list[str]) -> None:
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
    Twin of the helper in sn-cc-wrap.py.
    """
    text = s_path.read_text()
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
        # cygnus cc1 references the table as a bare macro operand
        # (`lw $3,$L12($2)`) instead of a %hi/%lo pair; ee-as expands that
        # macro into the lui+lw pair itself. Redirect the bare token too
        # (the table block is already deleted, so any surviving reference
        # is a table ref; the lookahead keeps $L120 etc. intact).
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
    s_path.write_text(text)


# One cc1-emitted `li.d` double-immediate load.  In this toolchain doubles
# live in GPRs (the EE soft-float ABI), so ee-as expands `li.d $rt,<val>`
# into a TU-local `.rodata` copy of the 8-byte constant plus
# `lui $at,%hi(.rodata); ld $rt,%lo(.rodata)($at)`.  cc1 (cygnus and SN
# alike) emits the pseudo-op as a single `\tli.d\t$rt,<value>` line.
_LID_RE = re.compile(r"^\tli\.d\t(\$\w+),[^\n]*$", re.M)


def _externalize_fp_literals(s_path: Path, syms: list[str]) -> None:
    """Redirect each cc1-emitted ``li.d`` double-immediate load to a symbol
    in the split rodata blob (``--extern-double``, in emission order).

    The data analogue of ``_externalize_jump_tables``.  Retail loads a
    double constant from a fixed address inside the contiguous 31B580
    rodata blob (e.g. ``D_00458140`` = the ``0.8`` at vaddr 0x458140) via
    ``lui $at,%hi(D_..); ld $rt,%lo(D_..)($at)``.  A compiled TU that
    writes the same constant with ``li.d`` instead gets its OWN
    ``.rodata`` copy, which (a) duplicates the bytes and (b) — living in
    the linker's ``*(.rodata .rodata.*)`` catch-all AFTER the blob — can
    never land at the blob-interior address retail used, so the emitted
    %hi/%lo never match.  We delete the pseudo-op and re-emit the SAME
    ``$at``-form load pointed at the blob symbol: no TU ``.rodata`` is
    produced (the pseudo-op was its only source) and the %hi/%lo resolve
    to the blob's copy — byte-identical to retail.

    The explicit ``$at`` (wrapped in ``.set noat``/``.set at``) reproduces
    ee-as's own ``li.d`` expansion register choice.  A bare-symbol macro
    load (``ld $rt, SYM``) would instead pick ``$rt`` as the address temp
    (``lui $rt``) — wrong bytes.  Symbols are applied in ``li.d`` emission
    order, one per load (order-sensitive, like ``--extern-jtbl``).
    """
    text = s_path.read_text()
    matches = list(_LID_RE.finditer(text))
    if len(matches) != len(syms):
        die(f"--extern-double: {len(syms)} symbol(s) given but cc1 emitted "
            f"{len(matches)} `li.d` double-immediate load(s) — give exactly "
            f"one blob symbol per li.d, in emission order")
    # Splice right-to-left so earlier match spans stay valid as we edit.
    for m, sym in reversed(list(zip(matches, syms))):
        reg = m.group(1)
        repl = (f"\t.set\tnoat\n"
                f"\tlui\t$at,%hi({sym})\n"
                f"\tld\t{reg},%lo({sym})($at)\n"
                f"\t.set\tat")
        text = text[:m.start()] + repl + text[m.end():]
    s_path.write_text(text)


def _strip_eh_table_from_s(s_path: Path) -> None:
    """Remove cc1plus's emitted ``.gcc_except_table`` block(s) from the .s
    (``--strip-eh-table``). Retail's per-function EH entries already live
    in the split 360C00.gcc_except_table blob; a TU copy would be appended
    by the lcf wildcard and shift the section away from retail. The
    ``$LEHB/$LEHE/$L`` labels the deleted block referenced remain in .text
    as byte-free locals. Blob entries that point INTO a carved function's
    span (``.word $LEH_<addr>``) are separately converted to raw retail
    words via config/jtbl_extern_words.txt (same mechanism as the
    extern_jtbl jump tables)."""
    text = s_path.read_text()
    out: list[str] = []
    skip = False
    for line in text.split("\n"):
        ls = line.strip()
        if ls.startswith(".section") and ".gcc_except_table" in ls:
            skip = True
            continue
        if skip and (ls.startswith(".section") or
                     ls in (".text", ".data", ".rdata", ".sdata")):
            skip = False
        if not skip:
            out.append(line)
    s_path.write_text("\n".join(out))


def _strip_cxx_frame_from_s(s_path: Path) -> None:
    """In-place surgical strip of the C++ DWARF frame block from ``s_path``."""
    s_path.write_text(_strip_cxx_frame_block(s_path.read_text()))


def run(cmd: list[str], stage: str, cwd: Path | None = None) -> None:
    """Run a subprocess and abort on non-zero exit.

    *cwd*: optional working directory.  Used by the cpp0/cc1/ee-as path
    to invoke each stage with a stable basename input so the .mdebug
    section ee-as writes into the .o doesn't capture the random tempdir
    path (which would break build reproducibility).
    """
    try:
        result = subprocess.run(cmd, check=False, cwd=str(cwd) if cwd else None)
    except FileNotFoundError as exc:
        die(f"{stage}: missing binary {exc.filename!r}")
    if result.returncode != 0:
        die(
            f"{stage} failed (exit {result.returncode}): "
            + " ".join(shlex_safe(arg) for arg in cmd),
            result.returncode,
        )


def shlex_safe(arg: str) -> str:
    """Shell-quote *arg* for diagnostic printing only."""
    if not arg or any(c in arg for c in " \t\n\"'$`\\"):
        return "'" + arg.replace("'", "'\\''") + "'"
    return arg


def parse_args(argv: list[str]) -> argparse.Namespace:
    p = argparse.ArgumentParser(
        prog="ee-cc-wrap",
        description="ee-gcc 2.96 driver replacement (matching-decomp build glue)",
    )
    p.add_argument("input", type=Path, help="Input .c / .cc / .cpp / .i / .s file")
    p.add_argument("-c", action="store_true", help="Compile to .o (the only mode supported)")
    p.add_argument("-o", dest="output", type=Path, default=None, help="Output .o path")
    p.add_argument(
        "-x",
        choices=("c", "c++"),
        default=None,
        help="Source language override (default: from extension)",
    )
    p.add_argument("-O", dest="optlevel", default="2", help="Optimization level (default: 2)")
    p.add_argument("-g", action="store_true", help="Emit debug info (-gstabs)")
    p.add_argument(
        "-G",
        dest="sdata_thresh",
        type=int,
        default=0,
        help="Small-data threshold (default: 0 — matches original SLUS build)",
    )
    p.add_argument("-D", dest="defines", action="append", default=[], help="Add a -D macro")
    p.add_argument("-U", dest="undefines", action="append", default=[], help="Add a -U macro")
    p.add_argument("-I", dest="includes", action="append", default=[], help="Add an include dir")
    p.add_argument(
        "-W",
        dest="warnings",
        action="append",
        default=[],
        help="Pass a -W warning flag to cc1 (e.g. -Wall, -Werror)",
    )
    p.add_argument(
        "-f",
        dest="features",
        action="append",
        default=[],
        help="Pass a -f compiler feature flag to cc1",
    )
    p.add_argument(
        "--print-stage",
        action="append",
        default=[],
        choices=("i", "s"),
        help="Save .i (preprocessed) and/or .s (assembly) next to the output",
    )
    p.add_argument(
        "--no-line-info",
        action="store_true",
        help="Strip absolute paths from cpp0 #line directives (for reproducible builds)",
    )
    p.add_argument(
        "--strip-cxx-frame",
        action="store_true",
        help=(
            "Surgically remove ONLY the DWARF frame block ee-gcc 2.9 appends "
            "unconditionally to a C++ TU's .s (the __FRAME_BEGIN__/_GLOBAL_$F$ "
            "span), preserving any real program .data (globals, vtables, "
            "typeinfo, string literals). Use for a carved C++ TU whose frame "
            "data is already provided by the data splat (otherwise the duplicate "
            "shifts downstream sections). No-op for C TUs and for .s with no "
            "frame block."
        ),
    )
    p.add_argument(
        "--strip-eh-table",
        action="store_true",
        help=(
            "Remove cc1plus's emitted .gcc_except_table block from the .s "
            "(the retail EH entries come from the split blob; a TU copy "
            "would shift the section). C++ TUs only; pair the blob's "
            "$LEH_ refs into the carved span with raw-word entries in "
            "config/jtbl_extern_words.txt."
        ),
    )
    p.add_argument(
        "--fp-hazard-nops", dest="fp_hazard_nops", action="store_true",
        help=(
            "Insert the R5900 FP hazard nops our cc1 frontends omit: one after "
            "an mtc1/dmtc1 whose next FP op reads the moved reg (GPR->COP1 "
            "latency), and two before a div.s/div.d fed by a cvt in the same "
            "block (FDIV operand-setup latency). Non-mechanical across the "
            "binary (the retail scheduler filled the slots with real work "
            "where it could), so opt-in per-TU and byte-verified. Forwarded to "
            "sn-cc-wrap.py for SN TUs. See compile_units[].fp_hazard_nops."
        ),
    )
    p.add_argument(
        "--call-loop-pad", dest="call_loop_pad", action="store_true",
        help=(
            "Insert the R5900 short-loop errata pad ee-as omits for backward "
            "loops whose body contains a call (jal/jalr): pad to 4 instructions "
            "before the branch. Retail's assembler emitted these; ee-as does "
            "not, which makes ~61 functions unmatchable regardless of the C. "
            "Never global -- the prebuilt-library band at 0x32xxxx-0x33xxxx is "
            "genuinely unpadded -- so opt-in per-TU and byte-verified. "
            "Forwarded to sn-cc-wrap.py for SN TUs. "
            "See compile_units[].call_loop_pad."
        ),
    )
    p.add_argument(
        "--extern-jtbl", dest="extern_jtbl", action="append", default=[],
        metavar="SYM",
        help="Externalize the Nth cc1-emitted switch jump table to SYM "
             "(repeatable, applied in table-emission order): delete the "
             ".rdata table block and redirect its %%hi/%%lo references to "
             "SYM. The split rodata blob supplies the retail table bytes; "
             "a duplicate TU copy would shift .rodata. Forwarded to "
             "sn-cc-wrap.py for SN TUs. See compile_config "
             "compile_units[].extern_jtbl.",
    )
    p.add_argument(
        "--extern-double", dest="extern_double", action="append", default=[],
        metavar="SYM",
        help="Externalize the Nth cc1-emitted `li.d` double-immediate load "
             "to SYM (repeatable, in emission order): replace the li.d "
             "pseudo-op with an $at-form `ld` from SYM and drop the TU-local "
             ".rodata copy of the constant. The split rodata blob supplies "
             "the retail bytes at SYM's address; a TU copy would both "
             "duplicate them and link after the blob (never at the "
             "blob-interior address retail used). Data analogue of "
             "--extern-jtbl. See compile_config compile_units[].extern_double.",
    )
    p.add_argument(
        "--assembler",
        dest="assembler",
        choices=("ee", "gnu"),
        default="ee",
        help=(
            "Which assembler runs stage 3. 'ee' (default) uses the SCE "
            "ee-as 2.10 (today's behaviour for every TU). 'gnu' routes the "
            "cc1 .s through scripts/mipsel-as-wrap.py (mipsel-linux-gnu-as, "
            "the same GNU assembler the ASM-splat path uses): GNU as's "
            ".set-reorder scheduler swaps a same-register load into a jr "
            "delay slot where ee-as 2.10 refuses to (e.g. cygnus reorder-mode "
            "getter macros like `lw $2,D_xxx($4); j $31`). Opt-in per-TU via "
            "compile_units[].as == 'gnu'."
        ),
    )
    p.add_argument(
        "--compiler",
        choices=("cygnus-2.96", "sn-2.95.3-136", "ee-2.9-991111",
                 *CC1_VARIANT_DIRS, *SN_VARIANT_DIRS),
        default="cygnus-2.96",
        help=(
            "Which cc1 frontend to invoke. 'cygnus-2.96' "
            "(default) keeps today's behaviour; 'sn-2.95.3-136' dispatches "
            "to scripts/sn-cc-wrap.py for the sq-prologue group; "
            "'ee-2.9-991111' uses the older Sony/Cygnus cc1 for the newlib "
            "sd-in-16-byte-slot group (mprec/dtoa). cpp0 + ee-as stages "
            "stay shared."
        ),
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
    return "c"  # unreachable, satisfies type checker


def _dispatch_sn(argv: list[str]) -> int:
    """Re-exec scripts/sn-cc-wrap.py with the same args (minus our
    ``--compiler`` flag, which sn-cc-wrap.py doesn't understand).

    The per-TU override lives in compile_config.json and is
    forwarded to *this* wrapper by ``compile.py::_cc``.  When the TU
    asks for SN, the cleanest dispatch is to hand the whole invocation
    to sn-cc-wrap.py — it already runs the same Cygnus cpp0 + Cygnus
    ee-as backend this wrapper does, and the cc1 stage is the only
    real difference (SN cc1.exe via wibo vs. Cygnus cc1).  Keeping the
    two wrappers separate (rather than inlining SN here) preserves
    sn-cc-wrap.py as the canonical SN entry point that
    ``scripts/setup_toolchain.sh`` § 5b's smoke test exercises.
    """
    sn_wrap = ROOT / "scripts" / "sn-cc-wrap.py"
    if not sn_wrap.exists():
        die(f"sn-cc-wrap.py missing at {sn_wrap} — run toolchain setup")
    # Strip --compiler=... / --compiler X and --assembler=... / --assembler X
    # tokens before forwarding (sn-cc-wrap.py understands neither; the GNU-as
    # route is a cygnus/ee-2.9 stage-3 option — SN has its own assemble stage).
    forwarded: list[str] = []
    skip = False
    for tok in argv:
        if skip:
            skip = False
            continue
        if tok in ("--compiler", "--assembler"):
            skip = True
            continue
        if tok.startswith("--compiler=") or tok.startswith("--assembler="):
            continue
        forwarded.append(tok)
    try:
        result = subprocess.run(
            [sys.executable, str(sn_wrap), *forwarded], check=False,
        )
    except FileNotFoundError as exc:
        die(f"sn-cc-wrap dispatch: missing binary {exc.filename!r}")
    return result.returncode


def main(argv: list[str]) -> int:
    args = parse_args(argv)

    if args.compiler == "sn-2.95.3-136" or args.compiler in SN_VARIANT_DIRS:
        # Dispatch the SN path before any Cygnus-specific argument
        # validation so a TU opted into SN never trips this wrapper's
        # cygnus-flavoured checks. Variant SN builds forward their
        # gcc-lib dir via GH_SN_GCCLIB (sn-cc-wrap.py reads it; default
        # is 2.95.3-sn-136).
        if args.compiler in SN_VARIANT_DIRS:
            os.environ["GH_SN_GCCLIB"] = SN_VARIANT_DIRS[args.compiler]
        return _dispatch_sn(argv)

    if not args.c:
        die("only -c (compile-only) is supported; linking is handled by compile.py")

    if not args.input.exists():
        die(f"input not found: {args.input}")

    output = args.output or args.input.with_suffix(".o")
    output.parent.mkdir(parents=True, exist_ok=True)

    if not COMPILER.is_dir():
        die(f"toolchain missing: {COMPILER} (run scripts/setup_toolchain.sh)")

    language = detect_language(args.input, args.x)
    if args.compiler == "ee-2.9-991111":
        cc1_bin = CC1PLUS_991111 if language == "c++" else CC1_991111
    elif args.compiler in CC1_VARIANT_DIRS:
        vdir = CC1_VARIANT_DIRS[args.compiler]
        cc1_bin = vdir / ("cc1plus" if language == "c++" else "cc1")
        if not cc1_bin.exists():
            die(f"variant compiler {args.compiler} not installed at {vdir} "
                "(fetch from decompme/compilers releases)")
    else:
        cc1_bin = CC1PLUS if language == "c++" else CC1

    src_ext = args.input.suffix.lower()
    is_assembly = src_ext == ".s"
    is_preprocessed = src_ext in (".i", ".ii")

    with tempfile.TemporaryDirectory(prefix="ee-cc-wrap.") as td:
        td_path = Path(td)
        stem = args.input.stem

        i_name = f"{stem}.i"
        s_name = f"{stem}.s"
        i_path = td_path / i_name
        s_path = td_path / s_name

        # We invoke cc1 and ee-as with cwd=td_path and pass *basenames*
        # (i_name, s_name) instead of absolute paths.  ee-as embeds the
        # .s filename into the .o's `.mdebug` section as a .file directive;
        # any path component (e.g. the random tempdir suffix) becomes part
        # of the .o byte stream and breaks build reproducibility across
        # invocations.  Passing a stable basename keeps `.mdebug` content
        # deterministic so `--reseed-expected` produces a stable baseline.
        # (Discovered when src/cod/000000.o diverged from its
        # expected/build mirror at offset 0x14d on every clean rebuild.)

        # Stage 1: preprocess (skipped for .s and .i inputs)
        if not is_assembly and not is_preprocessed:
            cpp_cmd = [
                str(CPP0),
                f"-lang-{language}",
                *SCE_EE_PREDEFINES,
                *(f"-D{d}" for d in args.defines),
                *(f"-U{u}" for u in args.undefines),
                *(f"-I{i}" for i in args.includes),
            ]
            if args.no_line_info:
                cpp_cmd.append("-P")
            cpp_cmd += [str(args.input), i_name]
            run(cpp_cmd, "cpp0", cwd=td_path)
        elif is_preprocessed:
            shutil.copy2(args.input, i_path)

        # Stage 2: compile (skipped for .s input)
        if not is_assembly:
            features = args.features
            if args.compiler in _NO_FREORDER_COMPILERS:
                # gcc 2.9 cc1 predates -freorder-blocks (exit 33 "Invalid
                # option"); drop it, exactly as sn-cc-wrap.py does for the
                # SN cc1.  The newlib sd-prologue group never needs it.
                features = [f for f in features if f != "-freorder-blocks"]
            cc1_cmd = [
                str(cc1_bin),
                "-quiet",
                f"-lang-{language}",
                "-mips3",
                f"-O{args.optlevel}",
                f"-G{args.sdata_thresh}",
                *args.warnings,
                *features,
            ]
            if args.g:
                cc1_cmd.append("-gstabs")
            cc1_cmd += [i_name, "-o", s_name]
            run(cc1_cmd, "cc1", cwd=td_path)
            if args.extern_jtbl:
                _externalize_jump_tables(s_path, args.extern_jtbl)
            if args.extern_double:
                _externalize_fp_literals(s_path, args.extern_double)
            _materialize_hazard_nops(s_path)
            # Opt-in FP hazard-nop INSERTER, after materialize so an
            # already-materialised nop breaks Rule A's mtc1->consumer adjacency
            # (no double insertion). Per-TU via compile_units fp_hazard_nops.
            if args.fp_hazard_nops:
                _insert_ee_fp_hazard_nops_file(s_path)
            # Opt-in call-loop errata pad, LAST: it counts loop-body
            # instructions, so it must run after every pass that can add one.
            if args.call_loop_pad:
                _insert_call_loop_pads_file(s_path)
            # ee-gcc 2.9 cc1plus appends an unconditional per-TU DWARF frame
            # block to the C++ ``.s``.  For a carved C++ TU whose frame data is
            # already provided by the data splat, that block is a duplicate
            # that shifts downstream sections away from retail.  Strip it at the
            # ``.s`` level (surgically — only the frame block, NOT real program
            # ``.data``) before ee-as assembles, so the splat copy stays the
            # single source.  Opt-in per-TU via compile_units strip_cxx_frame.
            if language == "c++" and args.strip_cxx_frame:
                _strip_cxx_frame_from_s(s_path)
            if language == "c++" and args.strip_eh_table:
                _strip_eh_table_from_s(s_path)
        else:
            shutil.copy2(args.input, s_path)

        # Stage 3: assemble
        if args.assembler == "gnu":
            # Route the cc1 .s through the GNU assembler (mipsel-linux-gnu-as
            # via scripts/mipsel-as-wrap.py) instead of ee-as 2.10.  GNU as's
            # .set-reorder delay-slot scheduler swaps a same-register load into
            # a `jr $31` delay slot where ee-as 2.10 refuses to (cygnus
            # reorder-mode getter macros: `lw $2,D_xxx($4); j $31`).  These are
            # the SAME flags the ASM-splat path assembles the monolithic
            # fragments with (compile_config as_flags), so the .text bytes match
            # retail exactly; mipsel-as-wrap rewrites -mabi=eabi -> -mabi=o64
            # and patches the .o's EF_MIPS_ABI back to eabi64 (0x4000).  Opt-in
            # per-TU only — GNU as would reschedule OTHER TUs that ee-as (and
            # retail) left unscheduled, so the default stays ee-as.
            mipsel_wrap = ROOT / "scripts" / "mipsel-as-wrap.py"
            if not mipsel_wrap.exists():
                die(f"--assembler gnu: mipsel-as-wrap.py missing at {mipsel_wrap}")
            as_cmd = [
                sys.executable,
                str(mipsel_wrap),
                "-EL",
                "-march=r5900",
                "-mabi=eabi",
                f"-G{args.sdata_thresh}",
                "--no-pad-sections",
            ]
            as_stage = "gnu-as"
        else:
            as_cmd = [
                str(EE_AS),
                "-EL",
                "-mips3",
                "-mcpu=5900",
                # -mabi=eabi makes ee-as emit ELF flag 0x4000 (eabi64), matching
                # the original SLUS_215.03 main ELF header flags (0x20924001).
                # Without this we get 0x20920001 (no eabi64 bit) and objdiff
                # scoring drifts.
                "-mabi=eabi",
                f"-G{args.sdata_thresh}",
            ]
            as_stage = "ee-as"
        # Forward -I include search paths to the assembler too.  INCLUDE_ASM(
        # folder, name) expands to `.include "folder/name.s"`; ee-as resolves
        # that through its own -I list (same as cpp0's -I list for #include).
        # Standard gcc-driver behaviour; needed for carving where
        # `.include "nonmatching/<name>.s"` resolves under build/asm/.
        for inc in args.includes:
            as_cmd.append(f"-I{inc}")
        # Additionally pass the *launch cwd* (= compile.py's cwd, i.e. the
        # repo root) as an -I to ee-as only.  splat's auto-generated
        # `include/include_asm.h` emits `.include "include/labels.inc"` and
        # `.include "include/macro.inc"` — paths that assume the assembler
        # runs with cwd=base_path (the splat convention).  We deliberately
        # run ee-as with cwd=tempdir to stabilize `.mdebug`'s `.file`
        # directive, which breaks that cwd-relative resolution.
        # Adding the launch cwd to ee-as's search path restores splat's
        # assumption without polluting cpp0's #include search path, and
        # without requiring a hand-edit of `include/include_asm.h` that
        # splat would stomp on every `splat split`.
        as_cmd.append(f"-I{LAUNCH_CWD}")
        if args.g:
            as_cmd.append("--gstabs")
        as_cmd += [s_name, "-o", str(output)]
        run(as_cmd, as_stage, cwd=td_path)

        # Optional: side-export intermediates for diff sessions
        if "i" in args.print_stage and not is_assembly:
            shutil.copy2(i_path, output.with_suffix(".i"))
        if "s" in args.print_stage and not is_assembly:
            shutil.copy2(s_path, output.with_suffix(".s"))

    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
