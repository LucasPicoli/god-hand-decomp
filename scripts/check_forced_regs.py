#!/usr/bin/env python3
"""check_forced_regs.py — ratchet gate on forced-register variables.

A "forced register" is a GCC explicit-register local variable used to
pin a value to a specific hardware register, e.g.:

    register int *vtable __asm__("$3");

In a *matching* decompile these are an anti-pattern: the original
source did not contain them, they reproduce the symptom (a
register-field bit) without recovering the C structure that caused it,
and they are fragile under any nearby change.  A pin is NOT a real C
match: a function that only matches with one stays
``INCLUDE_ASM("nonmatching", ...)``.  The allowlist
(``config/forced_regs_allowlist.txt``) is therefore kept EMPTY and the
ratchet enforces zero pins.

This script is the mechanical ratchet.  It scans ``src/`` + ``include/``
for forced-register declarations and fails if a file has MORE than its
allowlisted count, or has any while not being allowlisted at all.
Counts may only ratchet DOWN.

Usage:
    python3 scripts/check_forced_regs.py           # check; exit 1 on violation
    python3 scripts/check_forced_regs.py --list     # print current inventory
    python3 scripts/check_forced_regs.py --update    # rewrite the allowlist to
                                                     # the current counts (use
                                                     # ONLY when intentionally
                                                     # removing pins)

Exit codes: 0 = clean, 1 = violation, 77 = skip (no src/ tree).
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ALLOWLIST = ROOT / "config" / "forced_regs_allowlist.txt"
SCAN_DIRS = ("src", "include")
SCAN_EXTS = (".c", ".cc", ".cpp", ".cxx", ".c++", ".h", ".hpp", ".hh")

# The forced-register pin pattern lives in the central registry.
# It matches `register <stuff> {__asm__|__asm|asm}("$N")` anywhere on a line
# (NOT anchored) so a mid-line pin cannot evade the gate, in any of GCC's three
# interchangeable binding spellings; comments are stripped first (see
# ``strip_comments``) so prose mentions of the idiom never count.
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))
from scripts.denylist import FORCED_REG_RE as PIN_RE

_BLOCK_COMMENT = re.compile(r"/\*.*?\*/", re.DOTALL)
_LINE_COMMENT = re.compile(r"//[^\n]*")


def strip_comments(text: str) -> str:
    """Remove C block + line comments so prose that mentions the pin
    idiom (common in this repo's matched-function headers) never counts
    as a real declaration."""
    text = _BLOCK_COMMENT.sub(" ", text)
    text = _LINE_COMMENT.sub("", text)
    return text


def iter_source_files() -> list[Path]:
    files: list[Path] = []
    for d in SCAN_DIRS:
        base = ROOT / d
        if not base.is_dir():
            continue
        for p in sorted(base.rglob("*")):
            if p.is_file() and p.suffix.lower() in SCAN_EXTS:
                files.append(p)
    return files


def count_pins(path: Path) -> int:
    try:
        text = path.read_text(errors="replace")
    except OSError:
        return 0
    return len(PIN_RE.findall(strip_comments(text)))


def current_inventory() -> dict[str, int]:
    """{repo-relative-path: pin-count} for every file with >=1 pin."""
    inv: dict[str, int] = {}
    for p in iter_source_files():
        n = count_pins(p)
        if n:
            inv[p.relative_to(ROOT).as_posix()] = n
    return inv


def load_allowlist() -> dict[str, int]:
    allowed: dict[str, int] = {}
    if not ALLOWLIST.is_file():
        return allowed
    for raw in ALLOWLIST.read_text().splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split()
        if len(parts) < 2 or not parts[-1].isdigit():
            print(f"check_forced_regs: malformed allowlist line: {raw!r}",
                  file=sys.stderr)
            continue
        allowed[" ".join(parts[:-1])] = int(parts[-1])
    return allowed


HEADER = """\
# config/forced_regs_allowlist.txt
#
# Allowlist of files permitted to contain forced-register variables
# (`register T x __asm__("$N");`).
#
# THIS FILE SHOULD STAY EMPTY.  Policy: a forced-register pin is NOT a
# real C match.  If a function only matches with a pin, it stays
# `INCLUDE_ASM("nonmatching", ...)` until an authentic (pin-free) match
# is found.  The 9 originally-grandfathered constructors were regressed
# to nonmatching; the allowlist is intentionally empty and the ratchet
# now enforces ZERO pins.
#
# Format:  <path>  <max-allowed-count>
# The ratchet (scripts/check_forced_regs.py) FAILS if any file has pins
# while absent from this list.  Adding an entry resurrects a banned
# pattern — don't, unless a future policy amendment explicitly reopens
# the exception.
"""


def write_allowlist(inv: dict[str, int]) -> None:
    lines = [HEADER]
    for path in sorted(inv):
        lines.append(f"{path} {inv[path]}")
    ALLOWLIST.parent.mkdir(parents=True, exist_ok=True)
    ALLOWLIST.write_text("\n".join(lines) + "\n")


def main(argv: list[str]) -> int:
    if not (ROOT / "src").is_dir():
        print("src/ missing — nothing to check.")
        return 77

    inv = current_inventory()

    if "--list" in argv:
        if not inv:
            print("No forced-register variables in src/ or include/. 🎉")
            return 0
        total = sum(inv.values())
        print(f"Forced-register inventory ({total} pins in {len(inv)} files):")
        for path in sorted(inv):
            print(f"  {inv[path]:>2}  {path}")
        return 0

    if "--update" in argv:
        write_allowlist(inv)
        print(f"Wrote {ALLOWLIST.relative_to(ROOT)} "
              f"({sum(inv.values())} pins in {len(inv)} files).")
        return 0

    allowed = load_allowlist()
    new_files: list[str] = []
    increases: list[tuple[str, int, int]] = []
    for path, n in sorted(inv.items()):
        cap = allowed.get(path)
        if cap is None:
            new_files.append(path)
        elif n > cap:
            increases.append((path, n, cap))

    if not new_files and not increases:
        total = sum(inv.values())
        reductions = [p for p, cap in allowed.items() if inv.get(p, 0) < cap]
        msg = f"forced-register ratchet OK ({total} pins, all allowlisted)."
        if reductions:
            msg += (f"  {len(reductions)} file(s) below cap — run "
                    f"`python3 scripts/check_forced_regs.py --update` to lock in.")
        print(msg)
        return 0

    print("FORCED-REGISTER RATCHET VIOLATION", file=sys.stderr)
    print("", file=sys.stderr)
    if new_files:
        print("New file(s) with forced-register pins not in the allowlist:",
              file=sys.stderr)
        for path in new_files:
            print(f"    {path}  ({inv[path]} pin(s))", file=sys.stderr)
    if increases:
        print("File(s) with MORE pins than allowed:", file=sys.stderr)
        for path, n, cap in increases:
            print(f"    {path}  has {n}, allowed {cap}", file=sys.stderr)
    print("", file=sys.stderr)
    print("A `register ... __asm__(\"$N\")` pin is the LAST resort, not the "
          "first.", file=sys.stderr)
    print("A register-only diff means the C *structure* is wrong. Before "
          "pinning, try:", file=sys.stderr)
    print("  1. restructure the C (decl order, store the address directly, "
          "add/drop a temp, fix return-value liveness);", file=sys.stderr)
    print("  2. run decomp-permuter (permuter_settings.toml);", file=sys.stderr)
    print("  3. ship `INCLUDE_ASM(\"nonmatching\", ...)` — an honest nonmatch "
          "beats a pinned pseudo-match.", file=sys.stderr)
    print("If a pin is genuinely the only option, record the "
          "justification in the file header and add the file to",
          file=sys.stderr)
    print(f"  {ALLOWLIST.relative_to(ROOT)}  (then re-run with --update).",
          file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
