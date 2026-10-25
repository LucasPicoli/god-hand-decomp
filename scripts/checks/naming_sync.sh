#!/usr/bin/env bash
# naming-sync sub-check (CONTRIBUTING rule 3).
#
# CONTRIBUTING rule 3 requires a function's canonical name to land in three places in the
# SAME commit: compile_config.json::carved_funcs, config/symbol_addrs.txt
# (by address), and the defining C TU (INCLUDE_ASM operand or the matched-C
# `.text.<NAME>` section wrapper).  Nothing verified this, so a rename could
# diverge across surfaces.  This is a DETECTOR — it
# renames nothing; it fails (exit 1) on divergence.
#
# Checks agreement, not only that the carve name EXISTS in symbol_addrs:
#   * a name MISMATCH at a shared address always fails;
#   * a carve whose C TU never mentions its name always fails;
#   * a carve whose vaddr is ABSENT from symbol_addrs fails UNLESS the name
#     is grandfathered in config/naming_sync_allowlist.txt (pre-existing
#     library-transplant + still-in-place carves; see that file's header).
#
# Ghidra is explicitly OUT OF BAND: this check reads only in-tree committed
# text (compile_config.json, symbol_addrs.txt, the C TUs).  See the
# scripts/check_naming_sync.py header.
#
# Wraps `python3 scripts/check_naming_sync.py`.  Skip semantics: if
# compile_config.json is missing (fresh clone), the python checker returns 77
# and we propagate it.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

exec python3 "$ROOT/scripts/check_naming_sync.py"
