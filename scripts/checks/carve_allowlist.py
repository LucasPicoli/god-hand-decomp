#!/usr/bin/env python3
"""carve_allowlist — every tracked carve must carry a .gitignore allowlist line.

`.gitignore` opens with a default-deny `*`, so a file is only visible to an index
if an explicit `!<path>` line re-includes it. Tracking and visibility are
DIFFERENT things: `git add -f` tracks a file regardless of ignore rules, so a
carve force-added without its allowlist line looks perfectly healthy in the index
that added it — and is invisible to every other index over this work tree (a
second checkout, a `git worktree`, a fresh clone's staging area). There `git add`
skips it SILENTLY: no error, no untracked entry, nothing in `git status` at all.

That is exactly how a landed carve goes missing. The failure has no symptom until
something else needs the file and it is not there.

The integrate path gets this right (it allowlists before staging). Any path that
force-adds a carved TU without allowlisting it is the bug this gate catches.

Usage:
    carve_allowlist.py           # check; exit 1 if any tracked carve lacks a line
    carve_allowlist.py --fix     # append the missing lines (safe: files are
                                 # already tracked, so this changes nothing about
                                 # what is published — it only restores visibility)
"""
from __future__ import annotations

import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CARVE_DIR = "src/cod/"


def tracked_carves(root: Path) -> list[str]:
    out = subprocess.run(["git", "ls-files", CARVE_DIR],
                         cwd=root, capture_output=True, text=True, check=True).stdout
    return sorted(p for p in out.split("\n") if p.endswith(".c"))


def allowlisted(root: Path) -> set[str]:
    gi = root / ".gitignore"
    if not gi.exists():
        return set()
    return {ln[1:].strip() for ln in gi.read_text().splitlines()
            if ln.startswith("!") and ln[1:].strip().startswith(CARVE_DIR)}


def main(argv: list[str]) -> int:
    fix = "--fix" in argv[1:]
    missing = [p for p in tracked_carves(ROOT) if p not in allowlisted(ROOT)]

    if not missing:
        print(f"carve allowlist OK ({len(tracked_carves(ROOT))} tracked carves, all allowlisted).")
        return 0

    if fix:
        gi = ROOT / ".gitignore"
        text = gi.read_text()
        if text and not text.endswith("\n"):
            text += "\n"
        gi.write_text(text + "\n".join(f"!{p}" for p in missing) + "\n")
        print(f"carve allowlist: appended {len(missing)} missing line(s) to .gitignore")
        return 0

    print(f"TRACKED CARVES WITH NO .gitignore ALLOWLIST LINE: {len(missing)}")
    for p in missing[:20]:
        print(f"  {p}")
    if len(missing) > 20:
        print(f"  ... and {len(missing) - 20} more")
    print("\nThese are tracked here but invisible to any other index over this work tree,")
    print("where `git add` will skip them silently. Repair with:")
    print("  python3 scripts/checks/carve_allowlist.py --fix")
    return 1


if __name__ == "__main__":
    sys.exit(main(sys.argv))
