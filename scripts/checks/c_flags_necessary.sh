#!/usr/bin/env bash
# per-TU compiler-flag necessity gate — thin shell dispatcher over the Python
# implementation.
#
# `compile_units[].c_flags_drop` and `compile_units[].c_flags_add` each change
# the flag set of ONE translation unit.  The ELF byte gate cannot see a key
# that is invisible on its own TU: the key claims something about retail's
# build while `cmp build/SLUS_215.03.elf disc_extract/SLUS_215.03` stays at
# rc 0.  This gate compiles every such TU with and without the key and fails
# when the two objects are byte-identical.
#
# Exit semantics (forwarded from the Python implementation):
#   0   every per-TU flag key changes its object.  Also 0 when the unit set
#       was determined and no unit carries a key — a vacuous truth.
#   1   at least one key is inert or unreachable.
#   2   void verdict — the config is invalid, no C unit was discovered, or a
#       compile failed while the compiler tree is installed.
#   77  skipped — the compiler tree is not installed.
#
# `exec` is deliberate: it forwards the Python status exactly, so a trailing
# statement can never launder a failure into an implicit 0.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

exec python3 "$ROOT/scripts/checks/c_flags_necessary.py" "$@"
