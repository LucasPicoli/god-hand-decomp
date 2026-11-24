#!/usr/bin/env bash
# tu_complete sub-check.
#
# Wraps `python scripts/check_tu_complete.py` in marker mode:
#
#   - PASS if `progress/in_progress_tu.txt` is absent / empty (no
#     TU is in-progress, nothing to check).
#   - PASS if the marker is present and every listed TU passes
#     both sub-criteria (no `INCLUDE_ASM("nonmatching", …)` lines
#     remain AND every function in the TU's `.o` is matched per
#     progress/report.json).
#   - FAIL otherwise, with the script's diagnostic surfaced.
#
# Skip semantics (exit 77): the marker references a TU that needs
# progress/report.json, but the file is missing (fresh clone, or
# `compile.py --setup` + `scripts/progress.sh` hasn't run yet).
# In that state we can't decide either way — defer to the next
# session_check run.
#
# Documented in the session-check notes.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

MARKER="$ROOT/progress/in_progress_tu.txt"
REPORT="$ROOT/progress/report.json"

# No marker → trivial pass.  Avoid invoking python at all so the
# fresh-clone path is wholly skipless.
if [[ ! -s "$MARKER" ]]; then
    echo "no in-progress TU marker — nothing to check."
    exit 0
fi

# Marker present but report missing → skip (can't decide).
if [[ ! -f "$REPORT" ]]; then
    echo "progress/in_progress_tu.txt set but progress/report.json missing;"
    echo 'run "python compile.py --setup" then "scripts/progress.sh".'
    exit 77
fi

exec python3 "$ROOT/scripts/check_tu_complete.py"
