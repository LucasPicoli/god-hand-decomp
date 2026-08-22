#!/usr/bin/env python3
"""Every compile_units path must exist on disk AND be tracked by git.

A carved TU is gitignored until the carve allowlist admits it. If a commit
registers the unit in compile_config.json but never adds the file, the file
stays untracked. `git clean` and integrate_batch's rollback both delete an
untracked src/cod/*.c, and the build keeps matching retail from the stale
object, so nothing reports the loss. Wave 14 lost 30 functions this way and
the gap was invisible until a later commit ran the naming-sync scan.

Exit 0 = pass, 1 = a unit is missing or untracked, 2 = examined nothing.
"""
import json
import pathlib
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[2]


def main() -> int:
    cfg = json.loads((ROOT / "compile_config.json").read_text())
    units = [u.get("path") for u in cfg.get("compile_units", [])
             if isinstance(u, dict) and u.get("path")]
    if not units:
        print("compile_units_tracked: NO-OP — compile_config.json lists no units",
              file=sys.stderr)
        return 2

    tracked = set(subprocess.run(
        ["git", "ls-files"], cwd=ROOT, capture_output=True, text=True,
        check=True).stdout.split())

    missing = [p for p in units if not (ROOT / p).exists()]
    untracked = [p for p in units if p not in missing and p not in tracked]

    print(f"compile_units_tracked: {len(units)} unit(s) checked")
    for p in missing:
        print(f"  MISSING from disk: {p}")
    for p in untracked:
        print(f"  UNTRACKED in git:  {p}")
    if missing or untracked:
        print("\nA registered unit must be committed in the SAME commit that "
              "registers it.\n  git add -f <path>   then   "
              "python3 scripts/checks/carve_allowlist.py --fix",
              file=sys.stderr)
        return 1
    print("  all units exist and are tracked")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
