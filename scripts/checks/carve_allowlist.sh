#!/usr/bin/env bash
# Carve allowlist gate — thin wrapper.
#
# Fails when a tracked src/cod carve has no `!<path>` line in .gitignore. Such a
# carve is tracked in the index that force-added it but INVISIBLE to every other
# index over this work tree, where `git add` skips it silently. Logic lives in
# scripts/checks/carve_allowlist.py.
set -uo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
exec python3 "$ROOT/scripts/checks/carve_allowlist.py"
