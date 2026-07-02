#!/bin/bash
# Re-run splat split for the main EE ELF.
#
# As of the `generate_asm_macros_files: False` option in config/SLUS_215.03.yaml,
# splat no longer regenerates the customized include/ asm-macro surfaces
# (include/labels.inc, include/include_asm.h, include/macro.inc), so the split
# is now non-destructive to the source tree. The `git checkout` below is a
# defensive no-op kept in case the option is ever lost; if it ever restores a
# real change, the yaml option has regressed.
set -euo pipefail
cd "$(dirname "$0")/.."
.venv/bin/python -m splat split config/SLUS_215.03.yaml
git checkout -- include/labels.inc include/include_asm.h include/macro.inc
# Re-apply raw-word jump-table entries for extern_jtbl dispatchers (splat
# re-emits `.word .L<addr>` labels for them on every split).
.venv/bin/python scripts/apply_jtbl_extern_words.py
echo "resplat: done (include/ macros are now generation-disabled; checkout was a no-op)"
