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
    # Strip --compiler=... / --compiler X tokens before forwarding.
    forwarded: list[str] = []
    skip = False
    for tok in argv:
        if skip:
            skip = False
            continue
        if tok == "--compiler":
            skip = True
            continue
        if tok.startswith("--compiler="):
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
            _materialize_hazard_nops(s_path)
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
        as_cmd = [
            str(EE_AS),
            "-EL",
            "-mips3",
            "-mcpu=5900",
            # -mabi=eabi makes ee-as emit ELF flag 0x4000 (eabi64), matching the
            # original SLUS_215.03 main ELF header flags (0x20924001).  Without
            # this we get 0x20920001 (no eabi64 bit) and objdiff scoring drifts.
            "-mabi=eabi",
            f"-G{args.sdata_thresh}",
        ]
        # Forward -I include search paths to ee-as too.  INCLUDE_ASM(folder,
        # name) expands to `.include "folder/name.s"`; ee-as resolves that
        # through its own -I list (same as cpp0's -I list for #include).
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
        run(as_cmd, "ee-as", cwd=td_path)

        # Optional: side-export intermediates for diff sessions
        if "i" in args.print_stage and not is_assembly:
            shutil.copy2(i_path, output.with_suffix(".i"))
        if "s" in args.print_stage and not is_assembly:
            shutil.copy2(s_path, output.with_suffix(".s"))

    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
