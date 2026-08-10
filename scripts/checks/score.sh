#!/usr/bin/env bash
# objdiff ratchet sub-check.
#
# Regenerates progress/report.json (via scripts/progress.sh) and fails if
# matched_code / matched_data *byte counts* regressed.
#
# Floor (the real ratchet): the matched bytes COMMITTED at HEAD
# (git show HEAD:progress/report.json). That baseline lives in git history, so
# it is identical across clones and cannot be silently lowered. A 2026-06 audit
# found the prior baseline was ONLY the gitignored progress/report.prev.json —
# auto-seeded from the working tree (so a fresh clone, or `rm`, reset it from a
# possibly-regressed state) and never shared across clones. report.prev.json is
# kept as a secondary intra-session high-water mark, but HEAD is the authority.
#
# Why bytes and not percent: byte counts are exact integers; percent carries
# rounding error.  The ratchet must never trip on rounding.
#
# Skip semantics:
#   - if tools/objdiff-cli or objdiff.json is missing → exit 77.
#   - if HEAD has no committed report.json yet, the cross-clone floor is
#     skipped and only the local high-water mark applies.
#   - if NEITHER floor exists (no committed HEAD report AND no
#     report.prev.json) there is no baseline at all, so the ratchet compares
#     nothing.  That is not a pass: exit 77.  Before this guard the script
#     printed "cross-clone floor skipped" and exited 0 having compared zero
#     numbers, which is the no-op-reported-as-pass defect.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

CLI="$ROOT/tools/objdiff-cli"
CONFIG="$ROOT/objdiff.json"
REPORT="$ROOT/progress/report.json"
PREV="$ROOT/progress/report.prev.json"

if [[ ! -x "$CLI" ]]; then
    echo "tools/objdiff-cli missing — run scripts/setup_toolchain.sh."
    exit 77
fi
if [[ ! -f "$CONFIG" ]]; then
    echo "objdiff.json missing — run: python compile.py --setup."
    exit 77
fi

# Regenerate the report (silent unless it fails).
if ! out=$("$ROOT/scripts/progress.sh" --quiet 2>&1); then
    echo "scripts/progress.sh failed:"
    printf "%s\n" "$out"
    exit 1
fi

if [[ ! -f "$REPORT" ]]; then
    echo "$REPORT was not produced."
    exit 1
fi

read_field() {
    # $1 = report path, $2 = field
    python3 - "$1" "$2" <<'PY'
import json, sys
with open(sys.argv[1]) as fh:
    m = json.load(fh).get("measures", {})
v = m.get(sys.argv[2], 0)
# objdiff writes byte counts as strings; coerce to int.
try:
    print(int(v))
except (TypeError, ValueError):
    print(0)
PY
}

cur_code=$(read_field "$REPORT" matched_code)
cur_data=$(read_field "$REPORT" matched_data)
cur_tot_code=$(read_field "$REPORT" total_code)
cur_tot_data=$(read_field "$REPORT" total_data)

# Pretty percent (4dp), for output only.
pct() {
    python3 -c "n,d=$1,$2; print(f'{0.0 if d==0 else 100.0*n/d:.4f}')"
}
cur_code_pct=$(pct "$cur_code" "$cur_tot_code")
cur_data_pct=$(pct "$cur_data" "$cur_tot_data")

# --- Authoritative cross-clone floor: matched bytes committed at HEAD. ---
# Unlike report.prev.json (gitignored, auto-seeded, resettable with `rm`),
# HEAD's report.json is in git history: identical across clones, cannot be
# silently lowered. This is the real ratchet.
floor_code=""
floor_data=""
HEAD_REPORT="$(mktemp)"
trap 'rm -f "$HEAD_REPORT"' EXIT
if git -C "$ROOT" show HEAD:progress/report.json >"$HEAD_REPORT" 2>/dev/null \
   && [[ -s "$HEAD_REPORT" ]]; then
    floor_code=$(read_field "$HEAD_REPORT" matched_code)
    floor_data=$(read_field "$HEAD_REPORT" matched_data)
fi

fail=0
if [[ -n "$floor_code" ]]; then
    if (( cur_code < floor_code )); then
        echo "matched_code REGRESSED vs committed HEAD: $cur_code < $floor_code bytes"
        fail=1
    fi
    if (( cur_data < floor_data )); then
        echo "matched_data REGRESSED vs committed HEAD: $cur_data < $floor_data bytes"
        fail=1
    fi
else
    echo "no committed HEAD report.json — cross-clone floor skipped."
fi

# --- Secondary local high-water mark (intra-session feedback; defeatable). ---
prev_code=-1
prev_data=-1
if [[ -f "$PREV" ]]; then
    prev_code=$(read_field "$PREV" matched_code)
    prev_data=$(read_field "$PREV" matched_data)
    if (( cur_code < prev_code )); then
        echo "matched_code below local high-water mark: $cur_code < $prev_code bytes"
        fail=1
    fi
    if (( cur_data < prev_data )); then
        echo "matched_data below local high-water mark: $cur_data < $prev_data bytes"
        fail=1
    fi
fi

if [[ $fail -ne 0 ]]; then
    exit 1
fi

# No baseline on either side → the ratchet compared nothing. Report a skip so
# the operator sees it, rather than a pass that proves nothing.
if [[ -z "$floor_code" && ! -f "$PREV" ]]; then
    echo "no committed HEAD report.json AND no progress/report.prev.json —"
    echo "  the ratchet has no baseline and compared nothing."
    echo "  Seeding the local high-water mark now; commit a report.json to set"
    echo "  the cross-clone floor."
    cp "$REPORT" "$PREV"
    exit 77
fi

# Refresh the local high-water mark (seed on first run, advance when higher).
if [[ ! -f "$PREV" ]] || (( cur_code > prev_code )) || (( cur_data > prev_data )); then
    cp "$REPORT" "$PREV"
fi

echo "matched_code = $cur_code bytes ($cur_code_pct %)  floor(HEAD)=${floor_code:-n/a}"
echo "matched_data = $cur_data bytes ($cur_data_pct %)  floor(HEAD)=${floor_data:-n/a}"
exit 0
