#!/usr/bin/env bash
# rel sub-check.
#
# Per-REL build ratchet: for every REL configured in
# compile_config.json::rels, build/rel/<name>.rel must exist on disk
# and its sha256 must equal the on-disc retail bytes' sha256
# (compile_config.json::rels[].sha256_expected, also pinned in
# disc_extract/rel/manifest.json).  This is the byte-match gate
# expressed as a session_check sub-check: the build path itself
# (compile.py) already runs sha256_expected through
# scripts/checks/build.sh, but this sub-check decouples that
# verification from the build so a regression that lands without
# breaking the main-ELF sha256 still fails the ratchet.
#
# Skip semantics (per session_check.sh exit-77 convention):
#   - if compile.py is missing, exit 77 (compile path not landed)
#   - if compile_config.json::rels is empty, exit 77 (no RELs declared
#     yet, e.g. on an early commit)
#   - if build/rel/<name>.rel is missing, exit 77 (the build hasn't
#     been run yet; the build sub-check will run it)
#   - otherwise, every present .rel's sha256 must match the
#     declared expected value, else exit 1.
#
# Void verdict (exit 2): compile_config.json could not be parsed, so the REL
# list is undeterminable.  That is NOT the same as "rels is empty" and must
# not be reported as a skip.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

if [[ ! -f "$ROOT/compile.py" ]]; then
    echo "compile.py missing — not yet landed."
    exit 77
fi

# Pull the (name, sha256_expected) pairs out of compile_config.json so
# this sub-check doesn't depend on a separate manifest/state file.
# Python is already a hard dependency of compile.py.
# The reader's exit status is captured separately: a parse failure must not be
# read as "no RELs declared".  `mapfile < <(...)` discards the producer's
# status, so run the reader first and test it.
entries_text=$(
    python3 - <<'PY'
import json, sys
try:
    with open("compile_config.json") as fh:
        cfg = json.load(fh)
except Exception as exc:
    print(f"#error reading compile_config.json: {exc}", file=sys.stderr)
    sys.exit(2)
for r in cfg.get("rels", []):
    if not isinstance(r, dict):
        continue
    name = r.get("name", "")
    if not name or name.startswith("_"):
        continue
    sha = r.get("sha256_expected", "")
    size = r.get("size_expected", 0)
    print(f"{name}\t{sha}\t{size}")
PY
)
reader_rc=$?
if (( reader_rc != 0 )); then
    echo "rel: could not read compile_config.json::rels (reader rc=$reader_rc)."
    echo "  The REL list is UNDETERMINABLE — verdict void, not a skip."
    exit 2
fi

declare -a entries=()
if [[ -n "$entries_text" ]]; then
    mapfile -t entries <<<"$entries_text"
fi

if (( ${#entries[@]} == 0 )); then
    echo "compile_config.json::rels is empty — no RELs declared yet."
    exit 77
fi

declared=0
present=0
failed=0
missing=()
for line in "${entries[@]}"; do
    IFS=$'\t' read -r name want size <<<"$line"
    declared=$((declared + 1))
    rel_path="$ROOT/build/rel/${name}.rel"
    if [[ ! -f "$rel_path" ]]; then
        missing+=("$name")
        continue
    fi
    present=$((present + 1))
    got=$(sha256sum "$rel_path" | awk '{print $1}')
    got_size=$(stat -c%s "$rel_path")
    if [[ "$got" != "$want" ]]; then
        echo "rel $name: sha256 mismatch"
        echo "  build : $got"
        echo "  expect: $want"
        failed=$((failed + 1))
        continue
    fi
    if [[ "$got_size" != "$size" ]]; then
        echo "rel $name: size mismatch built=$got_size expected=$size"
        failed=$((failed + 1))
        continue
    fi
    echo "rel $name: ${got:0:12}… matches retail (${got_size} B)"
done

if (( present == 0 )); then
    echo "no built .rel files found (build hasn't been run yet)."
    exit 77
fi

if (( failed > 0 )); then
    exit 1
fi

if (( ${#missing[@]} > 0 )); then
    # Some RELs declared but not built — partial state. Treat as a
    # skip so a partial build doesn't fail the ratchet, but list
    # them for the operator.
    echo "rel: $declared declared / $present matched / ${#missing[@]} not yet built (${missing[*]})."
    exit 77
fi

echo "rel: $declared declared / $present matched, all byte-equal to retail."
exit 0
