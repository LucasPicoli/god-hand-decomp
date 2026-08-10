#!/usr/bin/env bash
# Register gate — thin wrapper.
#
# Fails when a `.s` under src/ has no entry in config/retail_authored_asm.txt.
# Such a file scores 100% because it assembles, not because anyone ruled it
# faithful. Also keeps config/permanent_exceptions.txt well formed and INERT:
# no other script may read it, because that register is a statement about the
# destination and must never block a match. Logic lives in
# scripts/checks/registers.py.
set -uo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
exec python3 "$ROOT/scripts/checks/registers.py"
