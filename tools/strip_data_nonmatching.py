#!/usr/bin/env python3
"""
strip_data_nonmatching.py — apply the data-section nonmatching policy.

Background
----------
splat's `nonmatching <SYM>` macro emits a `<SYM>.NON_MATCHING` shadow
`STT_OBJECT` symbol at the same address as the real `dlabel <SYM>`.
objdiff's convention: presence of `<SYM>.NON_MATCHING` makes the real
symbol score 0 % regardless of byte-equality.

For functions this is the right default — every undecompiled function
*is* not-yet-matching even when its bytes are byte-equal (the bytes
came from `INCLUDE_ASM`, not C).  For *data* symbols there is no
"before/after decomp" duality: bytes are pinned by the splat round-trip.
The meaningful decomp question for a data symbol
is "do we have a typed C extern declaration that lets C code reference
it correctly?".  Until that decl exists, the bytes are byte-equal but
not yet *consumed*; once the decl exists, the symbol is genuinely
"matched" in the decomp-progress sense the metric is meant to track.

This script enforces the policy:

    nonmatching <SYM>  is emitted in asm/data/cod/<file>.s
    iff  no `extern <type> <SYM>;` declaration exists under include/.

It is a post-`splat split` pass.  Today zero data symbols
have C decls, so this pass is a no-op and `matched_data_percent` stays
at the 83 % floor.  As decomp lands typed externs in `include/`, those
symbols' shadows drop and they begin scoring by byte-equality —
`matched_data_percent` ratchets continuously toward 100 %.

What this pass does NOT touch
-----------------------------
- `.text` shadows (functions): correct as-is.
- `.bss` / `.sbss` shadows: nobits sections score at the section level,
  not per-symbol; shadows are inert there.
- `glabel` / `jlabel` / `alabel` / `ehlabel` / function-side macros.

Workflow
--------
After every `splat split` (re-running the splat disassembly), run::

    python tools/strip_data_nonmatching.py

…to apply the policy.  `--check` mode exits 1 if the asm tree is out of
sync with `include/` (used by `scripts/checks/data_nonmatching.sh`).

CLI
---
    python tools/strip_data_nonmatching.py [--check] [--verbose]

Implementation notes
--------------------
- The `extern` decl detector is intentionally simple regex parsing.  It
  recognises the canonical forms emitted by typical decomp.me / sly1 /
  Xenosaga-I-style headers (one decl per line, no funky preprocessor
  conditionals).  See `_extract_decls()` for the supported shapes; if
  a header uses something exotic, list the symbol in
  `config/data_decls_extra.txt` (one name per line, comments OK).
- Designed to be fast (`asm/data/cod/*.s` is ~3.5 MB after resplat;
  full pass is < 1 s).
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent

# The four pure-data sections we apply the policy to.  .bss / .sbss
# have nobits scoring and are not touched.
DATA_SECTION_FILES = [
    "asm/data/cod/2BBF80.data.s",
    "asm/data/cod/30A400.sndata.s",
    "asm/data/cod/31B580.rodata.s",
    "asm/data/cod/360C00.gcc_except_table.s",
]

INCLUDE_ROOT = REPO_ROOT / "include"
EXTRA_DECLS_FILE = REPO_ROOT / "config" / "data_decls_extra.txt"

# Headers whose externs do not count as typing a data symbol.
# include/godhand/globals.h declares every global that C units read but no
# unit owns yet, mostly as address-only `char D_X[]`; a symbol counts once
# a class or module header declares it with its real type.
UNTYPED_DECL_HEADERS = frozenset({"godhand/globals.h"})


# Regex for `extern <type> <name>(\[...\])?(\s*=\s*...)?;`.  Captures
# the name.  Deliberately simple:
#   - One statement per logical line (semicolon-terminated).
#   - <type> may include `*`, `const`, `volatile`, `unsigned`, `struct`,
#     `enum`, identifier chars, whitespace.
#   - <name> is a C identifier.
#   - Optional `[...]`-style array suffix(es).
#   - No function decls (those carry `(...)` before the semicolon).
#
# The regex deliberately *requires* the `extern` keyword.  Forward
# declarations of types, macros, typedefs etc. are not data decls.
_EXTERN_RE = re.compile(
    r"""
    ^\s*extern\s+                         # 'extern '
    (?:                                   # type spec (one or more tokens)
        (?:const|volatile|signed|unsigned|struct|enum|union)\s+
        |
        [A-Za-z_][A-Za-z0-9_]*\s+
        |
        \*\s*
    )+
    (?P<name>[A-Za-z_][A-Za-z0-9_]*)      # the symbol name
    (?:\s*\[[^\]]*\])*                    # optional array suffix(es)
    \s*;                                  # statement terminator (no '(' allowed)
    """,
    re.VERBOSE | re.MULTILINE,
)


@dataclass
class StripStats:
    files_examined: int = 0
    files_changed: int = 0
    decls_total: int = 0
    decls_from_includes: int = 0
    decls_from_extra: int = 0
    nonmatching_lines_seen: int = 0
    nonmatching_lines_stripped: int = 0
    decls_unused: list[str] | None = None  # names in decls but no matching shadow


def _strip_block_comments(src: str) -> str:
    """Drop /* ... */ block comments so we don't pick up commented-out externs."""
    return re.sub(r"/\*.*?\*/", "", src, flags=re.DOTALL)


def _strip_line_comments(src: str) -> str:
    """Drop // ... line comments."""
    return re.sub(r"//[^\n]*", "", src)


def _extract_decls_from_header(text: str) -> set[str]:
    """Parse one header's text and return the set of extern data-decl names."""
    cleaned = _strip_line_comments(_strip_block_comments(text))
    return {m.group("name") for m in _EXTERN_RE.finditer(cleaned)}


def _load_extra_decls(path: Path) -> set[str]:
    """Read config/data_decls_extra.txt — one symbol per line, # comments."""
    if not path.exists():
        return set()
    out: set[str] = set()
    for raw in path.read_text(encoding="utf-8").splitlines():
        line = raw.split("#", 1)[0].strip()
        if line:
            out.add(line)
    return out


def collect_decls(
    include_root: Path = INCLUDE_ROOT,
    extra_file: Path = EXTRA_DECLS_FILE,
) -> tuple[set[str], int, int]:
    """Walk include/ and config/data_decls_extra.txt; return (set, n_includes, n_extra)."""
    decls: set[str] = set()
    n_inc = 0
    if include_root.exists():
        for hpath in sorted(include_root.rglob("*.h")):
            if hpath.relative_to(include_root).as_posix() in UNTYPED_DECL_HEADERS:
                continue
            try:
                text = hpath.read_text(encoding="utf-8", errors="replace")
            except OSError:
                continue
            found = _extract_decls_from_header(text)
            n_inc += len(found)
            decls |= found
    extra = _load_extra_decls(extra_file)
    n_extra = len(extra)
    decls |= extra
    return decls, n_inc, n_extra


# Match a single `nonmatching <NAME>` line plus its trailing blank line.
# Splat emits exactly:
#     nonmatching D_xxxxxxxx\n
#     \n
#     dlabel D_xxxxxxxx\n
# We strip the `nonmatching` line and the immediately-following blank
# line (if present) to keep the file tidy.
_NONMATCHING_RE = re.compile(
    r"^nonmatching\s+([A-Za-z_][A-Za-z0-9_.]*)\s*(?:,\s*\d+)?\s*\n(\n)?",
    re.MULTILINE,
)


def strip_file(text: str, decls: set[str], stats: StripStats) -> tuple[str, int]:
    """Strip nonmatching lines for symbols in `decls`. Returns (new_text, n_stripped)."""

    n_stripped = 0
    seen_in_file = 0

    def _replace(m: re.Match[str]) -> str:
        nonlocal n_stripped, seen_in_file
        seen_in_file += 1
        name = m.group(1)
        if name in decls:
            n_stripped += 1
            return ""  # drop the line + trailing blank
        return m.group(0)

    new_text = _NONMATCHING_RE.sub(_replace, text)
    stats.nonmatching_lines_seen += seen_in_file
    stats.nonmatching_lines_stripped += n_stripped
    return new_text, n_stripped


def run(*, check: bool, verbose: bool, root: Path = REPO_ROOT) -> int:
    """Apply the policy to all DATA_SECTION_FILES under `root`. Returns exit code."""
    decls, n_inc, n_extra = collect_decls(
        include_root=root / "include",
        extra_file=root / "config" / "data_decls_extra.txt",
    )
    stats = StripStats(
        decls_total=len(decls),
        decls_from_includes=n_inc,
        decls_from_extra=n_extra,
    )

    used_decls: set[str] = set()
    pending_change = False

    for relpath in DATA_SECTION_FILES:
        fpath = root / relpath
        if not fpath.exists():
            if verbose:
                print(f"  skip {relpath}: not present")
            continue
        stats.files_examined += 1
        before = fpath.read_text(encoding="utf-8")
        after, n_stripped = strip_file(before, decls, stats)

        if n_stripped:
            stats.files_changed += 1
            for m in _NONMATCHING_RE.finditer(before):
                if m.group(1) in decls:
                    used_decls.add(m.group(1))

        if before != after:
            pending_change = True
            if check:
                if verbose:
                    print(f"  CHECK: {relpath} would change ({n_stripped} stripped)")
            else:
                fpath.write_text(after, encoding="utf-8")
                if verbose:
                    print(f"  wrote {relpath} ({n_stripped} stripped)")
        elif verbose:
            print(f"  unchanged {relpath}")

    stats.decls_unused = sorted(decls - used_decls)

    # Summary
    print(
        f"data-nonmatching policy: {stats.decls_total} decl(s) "
        f"({stats.decls_from_includes} from include/, "
        f"{stats.decls_from_extra} from data_decls_extra.txt); "
        f"{stats.files_examined} file(s) examined, "
        f"{stats.files_changed} changed; "
        f"{stats.nonmatching_lines_stripped}/"
        f"{stats.nonmatching_lines_seen} nonmatching line(s) stripped."
    )
    if verbose and stats.decls_unused:
        print(
            f"  unused decls (no matching shadow in data .s): "
            f"{len(stats.decls_unused)}"
        )
        for name in stats.decls_unused[:10]:
            print(f"    - {name}")
        if len(stats.decls_unused) > 10:
            print(f"    ... and {len(stats.decls_unused) - 10} more")

    if check and pending_change:
        print(
            "ERROR: asm/data/cod/*.s out of sync with include/ extern decls.\n"
            "       run `python tools/strip_data_nonmatching.py` and recommit.",
            file=sys.stderr,
        )
        return 1
    return 0


def main(argv: list[str] | None = None) -> int:
    p = argparse.ArgumentParser(description=__doc__.split("\n")[1])
    p.add_argument(
        "--check",
        action="store_true",
        help="report-only: exit 1 if data .s files are out of sync with include/.",
    )
    p.add_argument("--verbose", action="store_true")
    ns = p.parse_args(argv)
    return run(check=ns.check, verbose=ns.verbose)


if __name__ == "__main__":
    sys.exit(main())
