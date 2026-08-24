#!/usr/bin/env bash
# Wrapper for the session_check harness. The check itself lives in
# scripts/checks/section_owner.py.
set -euo pipefail
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
exec python3 "$ROOT/scripts/checks/section_owner.py"
