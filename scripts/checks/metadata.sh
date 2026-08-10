#!/usr/bin/env bash
# Gap D: bin/elf_metadata/ manifest enforcement.
#
# The 42 non-loaded payloads + shstrtab.bin + sht.bin under
# bin/elf_metadata/ are checksummed in bin/elf_metadata/manifest.json
# (the extractor's output of record).  Nothing in the
# build path currently re-verifies these per-session.  This sub-check
# re-hashes every file referenced from the manifest and fails loudly
# on any mismatch.
#
# Skip semantics: if manifest.json is missing (fresh clone before
# scripts/extract_elf_metadata.py has been run), exit 77.  Otherwise
# every payload_sha256 listed there must match the current bytes on
# disk, and no file referenced from the manifest may be missing.
#
# (The task originally referenced "bin/elf_metadata/manifest.sha256";
#  the canonical manifest is JSON.  This sub-check follows the JSON.)
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

MANIFEST="$ROOT/bin/elf_metadata/manifest.json"
if [[ ! -f "$MANIFEST" ]]; then
    echo "bin/elf_metadata/manifest.json missing — run scripts/extract_elf_metadata.py first."
    exit 77
fi

exec python3 - <<'PY'
import hashlib
import json
import pathlib
import sys

ROOT = pathlib.Path(__file__).resolve().parent if False else pathlib.Path.cwd()
MANIFEST = ROOT / "bin" / "elf_metadata" / "manifest.json"

def sha256(p: pathlib.Path) -> str:
    h = hashlib.sha256()
    with p.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 16), b""):
            h.update(chunk)
    return h.hexdigest()

manifest = json.loads(MANIFEST.read_text())
problems: list[str] = []
checked = 0

# Per-section payloads.
for sec in manifest.get("sections", []):
    payload_rel = sec.get("payload")
    payload_sha = sec.get("payload_sha256")
    if not payload_rel or not payload_sha:
        # No payload (e.g. NOBITS) — skip.
        continue
    p = ROOT / payload_rel
    if not p.exists():
        problems.append(f"missing: {payload_rel}")
        continue
    got = sha256(p)
    if got != payload_sha:
        problems.append(
            f"sha mismatch: {payload_rel}\n"
            f"      manifest: {payload_sha}\n"
            f"      on disk:  {got}"
        )
    else:
        checked += 1

# Top-level extras (shstrtab, sht).
for key in ("shstrtab", "sht"):
    entry = manifest.get(key)
    if not entry:
        continue
    payload_rel = entry.get("payload")
    payload_sha = entry.get("payload_sha256")
    if not payload_rel or not payload_sha:
        continue
    p = ROOT / payload_rel
    if not p.exists():
        problems.append(f"missing: {payload_rel} ({key})")
        continue
    got = sha256(p)
    if got != payload_sha:
        problems.append(
            f"sha mismatch: {payload_rel} ({key})\n"
            f"      manifest: {payload_sha}\n"
            f"      on disk:  {got}"
        )
    else:
        checked += 1

if problems:
    print(f"metadata: {len(problems)} payload integrity failure(s):")
    for line in problems:
        print(f"   - {line}")
    sys.exit(1)

# A manifest that referenced no payload at all leaves nothing hashed. Exit 0
# there would report a pass over an input set that was never determined.
if checked == 0:
    print("metadata: bin/elf_metadata/manifest.json references 0 payload(s);")
    print("   nothing was hashed, so this verdict is VOID — not a pass.")
    print("   Re-run scripts/extract_elf_metadata.py.")
    sys.exit(2)

print(f"metadata: {checked} payload(s) match bin/elf_metadata/manifest.json")
PY
