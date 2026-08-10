#!/usr/bin/env bash
# units sub-check.
#
# Verifies that the active linker script's input ``.o`` list and
# ``compile.py``'s ``discover()`` output describe the same set of
# objects, in both directions.  Catches the class of bug where a
# source glob misses a new fragment after carving, or the lcf keeps
# a stale entry, before the linker emits a confusing
# "undefined reference" or before the build silently links a stale
# tree.
#
# Active lcf: ``build/SLUS_215.03.lcf`` if present (carving has run),
# else ``config/SLUS_215.03.lcf``.  This mirrors compile.py and
# ``scripts/checks/verify_expected_vs_retail.py``.
#
# Skip semantics (exit 77):
#   - ``config/SLUS_215.03.lcf`` missing (fresh clone, pre-splat).
#   - ``asm/cod/000000.s`` missing (splat has never been run; the
#     ``maybe_carve()`` step that discover() calls would raise).
#
# Void verdict (exit 2): the lcf and discover() BOTH produced 0 objects.  Two
# empty sets agree trivially, so exit 0 there would report a pass over an input
# set that was never determined.
#
# See the session-check notes.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

if [[ ! -f "$ROOT/config/SLUS_215.03.lcf" ]]; then
    echo "config/SLUS_215.03.lcf missing — run splat first."
    exit 77
fi
if [[ ! -f "$ROOT/asm/cod/000000.s" ]]; then
    echo "asm/cod/000000.s missing — run splat first."
    exit 77
fi

exec python3 - <<'PY'
import sys
from pathlib import Path

ROOT = Path.cwd()
sys.path.insert(0, str(ROOT))

# Silence compile.py's Logger so the sub-check output is just the
# verdict line(s).  Logger writes "[info] discovered N units …" on
# import-free codepaths too, so we route it to a black-hole sink.
import compile as C  # noqa: E402

class _NullLog(C.Logger):
    def info(self, *a, **kw): pass
    def warn(self, *a, **kw): pass

log = _NullLog(verbose=False)

try:
    cfg = C.Config.load(C.DEFAULT_CONFIG)
    carve = C.maybe_carve(cfg, log)
    units = C.discover(cfg, carve)
    lcf_objs = C._ld_script_objects(cfg, carve)
except C.BuildError as exc:
    print(f"units: compile.py preflight failed: {exc}")
    sys.exit(1)
except Exception as exc:  # noqa: BLE001
    print(f"units: unexpected error: {exc!r}")
    sys.exit(1)

def _rel(p: Path) -> str:
    try:
        return str(p.resolve().relative_to(ROOT))
    except ValueError:
        return str(p)

discovered = {_rel(u.obj) for u in units}
lcf_set = {_rel(p) for p in lcf_objs}

# Source of the active lcf (for the diagnostic).
build_lcf = ROOT / "build" / "SLUS_215.03.lcf"
active_lcf = build_lcf if build_lcf.exists() else ROOT / "config" / "SLUS_215.03.lcf"
active_rel = _rel(active_lcf)

# Two empty sets agree trivially. That is not a pass: it means neither the lcf
# nor discover() produced an object list, so the comparison examined nothing.
if not discovered and not lcf_set:
    print(f"units: both {active_rel} and compile.py::discover() produced "
          f"0 units.")
    print("units: nothing was compared — verdict VOID, not a pass.")
    sys.exit(2)

lcf_only = sorted(lcf_set - discovered)
disc_only = sorted(discovered - lcf_set)

# REL .o entries are owned by build_rel(), not the main-ELF discover()
# unit list, and the main-ELF lcf does not reference them.  They're
# captured in discover() via cfg.rels and rejected from the main-ELF
# unit list via _rel_asm_part_paths(), so neither side should mention
# them.  No filtering needed today; documented here in case the lcf
# shape grows REL entries in the future.

errors = []
if lcf_only:
    errors.append(
        f"lcf references {len(lcf_only)} unit(s) discover() does not produce:"
    )
    for o in lcf_only:
        errors.append(f"  lcf references unknown unit: {o}")
if disc_only:
    errors.append(
        f"discover() produces {len(disc_only)} unit(s) the lcf does not reference:"
    )
    for o in disc_only:
        errors.append(f"  discover() does not cover lcf input: {o}")

if errors:
    print(f"units: drift between {active_rel} and compile.py::discover():")
    for line in errors:
        print(line)
    sys.exit(1)

print(
    f"units: {len(discovered)} unit(s) consistent "
    f"({active_rel} ↔ compile.py::discover())."
)
sys.exit(0)
PY
