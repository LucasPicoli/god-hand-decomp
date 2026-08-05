#!/usr/bin/env bash
# session_check.sh — end-of-session ratchet harness.
#
# Run this before finishing up.  It fails loudly if the project's
# invariants have regressed: splat round-trip, build succeeds, final
# ELF still byte-matches the retail copy, objdiff matched_code percent
# did not drop, and the progress report's headline metrics still agree.
#
# The harness is a thin dispatcher over scripts/checks/<name>.sh.  Each
# sub-check is independently runnable:
#
#     scripts/session_check.sh                 # everything
#     scripts/session_check.sh splat           # splat round-trip only
#     scripts/session_check.sh rel-splat       # per-REL splat round-trip
#     scripts/session_check.sh metadata        # bin/elf_metadata/ manifest sha256s
#     scripts/session_check.sh build           # compile.py + ELF sha256
#     scripts/session_check.sh rel             # per-REL build sha256 ratchet
#     scripts/session_check.sh expected        # expected/build baseline ≡ retail
#     scripts/session_check.sh expected_stale  # expected/build mirror not drifted from build/
#     scripts/session_check.sh dual_compiler_regress  # per-section dual-compiler
#     scripts/session_check.sh score           # objdiff ratchet
#     scripts/session_check.sh data_decls      # data .s sync with include/ extern decls
#     scripts/session_check.sh forced_regs     # forced-register pin ratchet
#     scripts/session_check.sh naming_debt     # carved func_XXXX count must not grow
#     scripts/session_check.sh naming_sync     # carve name agrees across symbol_addrs + C TU
#     scripts/session_check.sh tu_complete     # in-progress TU is complete
#     scripts/session_check.sh state           # local state-doc consistency
#     scripts/session_check.sh social          # advisory checks (never fails)
#
# Sub-check exit-code convention:
#     0    pass
#     77   skipped (missing prerequisite, e.g. a downstream artifact not
#          yet built); always non-fatal and reported with a yellow `∼`
#     78   pass-with-warnings (only meaningful for `social`); output is
#          shown verbatim
#     *    failure
#
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT"

CHECKS_DIR="$ROOT/scripts/checks"
DEFAULT_CHECKS=(splat rel-splat metadata build rel expected expected_stale dual_compiler_regress units score diff data_decls forced_regs naming_debt naming_sync monolith_sync jtbl_words carve_allowlist tu_complete atlas social)

# Optional checks read local-only working files (running notes, the in-progress
# struct atlas, naming bookkeeping) that aren't tracked in the repo, so their
# scripts aren't shipped either. A fresh clone won't have them: a *missing*
# optional check is skipped, not failed. A missing NON-optional check is still a
# hard error — that catches a typo in DEFAULT_CHECKS or an accidentally-deleted
# tracked check.
OPTIONAL_CHECKS=(naming_debt naming_sync atlas expected_stale monolith_sync jtbl_words)

usage() {
    cat <<EOF
Usage: scripts/session_check.sh [CHECK]

Run end-of-session ratchet checks.  No argument runs the full suite:
${DEFAULT_CHECKS[*]}.

CHECK may be any single sub-check name, or a comma-separated list
(e.g. "splat,state").

Each sub-check is also independently runnable as scripts/checks/<name>.sh.

  scripts/session_check.sh --fix   repair the derived artifacts the ratchet
                                   checks (reseed stale expected mirrors, regen
                                   report.json to its fixed point, regen the
                                   struct atlas), then re-run the gate to verify.
                                   Wraps scripts/session_finalize.py.

Exit codes:
  0   all selected checks passed (warnings ok)
  1   at least one check failed
  2   usage error
EOF
}

selected=("${DEFAULT_CHECKS[@]}")
if [[ $# -gt 1 ]]; then
    usage >&2
    exit 2
fi
if [[ $# -eq 1 ]]; then
    case "$1" in
        -h|--help) usage; exit 0 ;;
        --fix)
            # Repair the derived artifacts the ratchet checks (reseed stale
            # expected mirrors, regen report.json to its fixed point, regen the
            # struct atlas) instead of just reporting the drift. Leaves the
            # regenerated report uncommitted for review; re-run the gate to verify.
            exec python3 "$ROOT/scripts/session_finalize.py"
            ;;
        *)
            IFS=',' read -r -a selected <<<"$1"
            ;;
    esac
fi

if [[ -t 1 ]]; then
    G="\033[1;32m"; R="\033[1;31m"; Y="\033[1;33m"; N="\033[0m"
else
    G=""; R=""; Y=""; N=""
fi
OK_MARK="${G}✓${N}"
FAIL_MARK="${R}✗${N}"
SKIP_MARK="${Y}∼${N}"
WARN_MARK="${Y}!${N}"

START_TS=$SECONDS
declare -i FAILED=0 SKIPPED=0 PASSED=0 WARNED=0

printf "session_check: running %d sub-check(s) [%s]\n" \
    "${#selected[@]}" "${selected[*]}"

for c in "${selected[@]}"; do
    SCRIPT="$CHECKS_DIR/$c.sh"
    if [[ ! -x "$SCRIPT" ]]; then
        if [[ " ${OPTIONAL_CHECKS[*]} " == *" $c "* ]]; then
            SKIPPED+=1
            printf "%b %-7s   0s  skipped (check not present in this checkout)\n" "$SKIP_MARK" "$c"
        else
            printf "%b %-7s  no such check (%s)\n" "$FAIL_MARK" "$c" "$SCRIPT"
            FAILED+=1
        fi
        continue
    fi
    sub_start=$SECONDS
    out=$("$SCRIPT" 2>&1)
    rc=$?
    elapsed=$((SECONDS - sub_start))
    case $rc in
        0)
            PASSED+=1
            printf "%b %-7s  %2ds  pass\n" "$OK_MARK" "$c" "$elapsed"
            ;;
        77)
            SKIPPED+=1
            printf "%b %-7s  %2ds  skipped\n" "$SKIP_MARK" "$c" "$elapsed"
            printf "%s\n" "$out" | sed 's/^/        /'
            ;;
        78)
            WARNED+=1
            printf "%b %-7s  %2ds  pass-with-warnings\n" "$WARN_MARK" "$c" "$elapsed"
            printf "%s\n" "$out" | sed 's/^/        /'
            ;;
        *)
            FAILED+=1
            printf "%b %-7s  %2ds  FAILED (rc=%d)\n" "$FAIL_MARK" "$c" "$elapsed" "$rc"
            printf "%s\n" "$out" | sed 's/^/        /'
            ;;
    esac
done

TOTAL=$((SECONDS - START_TS))
printf "\nsession_check: %d passed, %d warned, %d skipped, %d failed in %ds\n" \
    "$PASSED" "$WARNED" "$SKIPPED" "$FAILED" "$TOTAL"

if (( FAILED > 0 )); then
    echo "session_check: RATCHET BROKEN — do not commit until resolved." >&2
    exit 1
fi
exit 0
