#!/usr/bin/env bash
# ci_no_game_data.sh — fail a PR that adds copyrighted game data, SDK
# binaries, or other derived/binary blobs.
#
# The #1 project rule is "never commit game assets, ripped data, ROMs/ISOs,
# SDK binaries, or any copyrighted material" (CONTRIBUTING.md).  This guard
# enforces it mechanically on every PR.  Two layers:
#
#   1. A precise denylist of game-data / SDK / boot-ELF / derived-artifact
#      paths (anchored so it never trips on the legitimately-tracked
#      config/SLUS_215.03.{lcf,yaml} text files).
#   2. A binary-file backstop: this repo is intentionally 100% text, so any
#      newly-added *binary* file (git treats it as binary) is rejected even
#      if the denylist missed it — catches a renamed ISO, a stray .o, etc.
#
# The single allowed payload under disc_extract/ is rel/manifest.json.
#
# Usage:
#   scripts/checks/ci_no_game_data.sh [FILE ...]   # check exactly these paths
#   scripts/checks/ci_no_game_data.sh              # check files changed vs
#                                                  #   $DIFF_BASE (default
#                                                  #   origin/main)
#
# Exit codes:
#   0   the changed set was determined and holds no game data.  An EMPTY
#       changed set over a real, non-degenerate range is a pass: the predicate
#       "no changed path is game data" is vacuously true.
#   1   a disallowed file is in the change.
#   2   the changed set could NOT be determined — the verdict is VOID.  This
#       is NOT a pass.  It fires when the base ref does not resolve, when the
#       diff command fails, or when the range is degenerate (the merge base
#       equals HEAD, so `git diff BASE...HEAD` is empty by construction and
#       proves nothing).
#   77  a prerequisite is absent: this is not a git repository and no paths
#       were given.  Nothing to run against.
#
# The 2/77 split matters.  77 says "a legitimate state, run the missing step
# first"; 2 says "the caller is wrong and the guard examined nothing".  A push
# event that supplies no base used to land in the 0 branch: `origin/main` is
# the pushed commit, so the range was empty and the #1 project rule was
# enforced over zero files.  That path is now a 2.
set -uo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$ROOT"

ALLOWED_LEAF="disc_extract/rel/manifest.json"

# Game data, SDK toolchain, the carved boot ELF, and derived binaries.
# Matched case-insensitively against each repo-relative path.
DENY_RE='\.(iso|afs|img|irx|fst|elf|o|map|lst|bin)$|^SLUS_[0-9]|(^|/)GODHAND\.|^disc_extract/|^compiler/|^tools/wibo$|^tools/objdiff-cli$|^tools/(m2c|asm-differ|decomp-permuter)/'

# Collect the candidate paths.
declare -a FILES=()
EXPLICIT_PATHS=0
if [[ $# -gt 0 ]]; then
    FILES=("$@")
    EXPLICIT_PATHS=1
else
    if ! git rev-parse --git-dir >/dev/null 2>&1; then
        echo "ci_no_game_data: not a git repo and no paths given — skip."
        exit 77
    fi

    # An unset OR empty DIFF_BASE both fall back to origin/main.  A GitHub
    # `push` event expands ${{ github.event.pull_request.base.sha }} to the
    # empty string, which is why the empty case must be handled here.
    BASE="${DIFF_BASE:-origin/main}"
    if [[ -n "${DIFF_BASE:-}" ]]; then
        BASE_SOURCE="DIFF_BASE"
    else
        BASE_SOURCE="the origin/main default (DIFF_BASE was unset or empty)"
    fi

    if ! BASE_SHA=$(git rev-parse --verify -q "${BASE}^{commit}"); then
        echo "ci_no_game_data: base ref '$BASE' (from $BASE_SOURCE) does not"
        echo "  resolve to a commit.  The changed set is UNDETERMINABLE, so"
        echo "  this guard examined nothing.  Verdict void — not a pass."
        echo "  (set DIFF_BASE to a real commit, or pass paths explicitly)"
        exit 2
    fi
    if ! HEAD_SHA=$(git rev-parse --verify -q "HEAD^{commit}"); then
        echo "ci_no_game_data: HEAD does not resolve to a commit — verdict void."
        exit 2
    fi

    # `git diff BASE...HEAD` diffs merge-base(BASE,HEAD) against HEAD.  When
    # that merge base IS HEAD the range is degenerate: the diff is empty for
    # every possible tree content, so an empty result proves nothing.  Report
    # a void verdict instead of a pass.
    if ! MERGE_BASE=$(git merge-base "$BASE_SHA" "$HEAD_SHA" 2>/dev/null); then
        echo "ci_no_game_data: no merge base between '$BASE' and HEAD"
        echo "  (from $BASE_SOURCE).  The changed set is UNDETERMINABLE."
        echo "  Verdict void — not a pass."
        exit 2
    fi
    if [[ "$MERGE_BASE" == "$HEAD_SHA" ]]; then
        echo "ci_no_game_data: degenerate range — merge-base('$BASE', HEAD) IS"
        echo "  HEAD (${HEAD_SHA:0:12}), so 'git diff $BASE...HEAD' is empty by"
        echo "  construction and examines NOTHING."
        echo "  Base came from $BASE_SOURCE."
        echo "  On a push event, pass the push's own base (github.event.before)."
        echo "  Verdict void — not a pass."
        exit 2
    fi

    if ! DIFF_OUT=$(git diff --name-only --diff-filter=ACMR "$BASE_SHA...$HEAD_SHA"); then
        echo "ci_no_game_data: 'git diff $BASE...HEAD' failed — verdict void."
        exit 2
    fi
    if [[ -n "$DIFF_OUT" ]]; then
        mapfile -t FILES <<<"$DIFF_OUT"
    fi
fi

if [[ ${#FILES[@]} -eq 0 ]]; then
    if [[ $EXPLICIT_PATHS -eq 1 ]]; then
        echo "ci_no_game_data: no paths given — verdict void."
        exit 2
    fi
    # A real range that changed no file.  The predicate holds over an empty
    # set: this is a true vacuous pass, not a no-op.
    echo "ci_no_game_data: range ${BASE_SHA:0:12}...${HEAD_SHA:0:12} changed 0"
    echo "  file(s) — nothing to check (vacuous pass)."
    exit 0
fi

# Is a path a binary file on disk?  Uses git's own binary heuristic:
# `git diff --numstat` prints "-\t-\t..." for binary content, real counts
# for text.  (git diff --no-index exits non-zero whenever the files differ,
# so we read its stdout rather than its exit status, which pipefail would
# otherwise turn into a false negative.)
is_binary() {
    local f="$1" stat
    [[ -f "$f" ]] || return 1
    stat=$(git diff --numstat --no-index /dev/null "$f" 2>/dev/null)
    [[ "$stat" == "-"$'\t'"-"* ]]
}

declare -a VIOLATIONS=()
for f in "${FILES[@]}"; do
    [[ "$f" == "$ALLOWED_LEAF" ]] && continue
    if printf '%s\n' "$f" | grep -iqE "$DENY_RE"; then
        VIOLATIONS+=("$f  (game data / SDK / derived artifact)")
        continue
    fi
    if is_binary "$f"; then
        VIOLATIONS+=("$f  (binary file — this repo is text-only)")
    fi
done

if [[ ${#VIOLATIONS[@]} -gt 0 ]]; then
    echo "ci_no_game_data: ${#VIOLATIONS[@]} disallowed file(s) in this change:"
    for v in "${VIOLATIONS[@]}"; do
        echo "   - $v"
    done
    echo
    echo "Never commit game assets, ripped data, ROMs/ISOs, SDK binaries, or"
    echo "any copyrighted material.  Supply your own dumped disc locally."
    exit 1
fi

echo "ci_no_game_data: ${#FILES[@]} changed file(s) checked; no game data."
exit 0
