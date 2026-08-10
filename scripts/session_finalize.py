#!/usr/bin/env python3
"""session_finalize.py — the ONE canonical end-of-session repair (Fix 1).

The session-end ratchet (scripts/session_check.sh) *checks* that the derived
artifacts a matching session produces are fresh; it does not *fix* them. The fix
used to live scattered across each integrate path, so whenever a path forgot a
regen the ratchet caught the drift at session end and a human ran the repair by
hand — the recurring friction behind a long tail of one-off script patches.

This module is the single place that repair lives now. Run it directly, or via
``scripts/session_check.sh --fix``; the integrate pipeline delegates its
end-of-batch regen to it. It performs, in dependency order:

  1. build_matches_retail  — SAFETY GATE. Never reseed a mirror from a build that
     no longer byte-matches retail: that would pin a regression as the baseline.
  2. reseed_stale          — refresh exactly the ``expected/build/<u>.o`` mirrors
     that ``expected_staleness.find_stale()`` flags (the #1 manual friction; the
     mirrors are pinned copy-if-missing and untracked, so a grown TU silently
     under-counts until reseeded). All of them in ONE build, via
     ``compile.py --reseed-paths``; the singular ``--reseed-path`` costs a full
     build per mirror.
  3. regen_report          — objdiff ``progress/report.json`` to its byte-stable
     fixed point (objdiff-cli's generate-before-flag ordering needs 2 passes).
  4. regen_struct_atlas    — the private STRUCTS.md / struct_atlas.json artifacts.

The reseed + struct-atlas steps depend on optional local tooling. When that
tooling is not installed they degrade to graceful no-ops, exactly like the
wrappers scripts/checks/{expected_stale,atlas}.sh, which are optional for the
same reason. Both steps test for the tool's FILE rather than catching a failure
from running it, so "not installed" and "installed and broken" stay distinct.
"""
from __future__ import annotations

import argparse
import filecmp
import json
import subprocess
import sys
from pathlib import Path

_HERE = Path(__file__).resolve().parent          # <root>/scripts
ROOT = _HERE.parent
MAIN_ELF = "SLUS_215.03"

# The staleness detector + its helpers are local-only tooling. Import them when
# that tooling is installed; otherwise reseed_stale is a no-op (plain checkout).
#
# The absence test is the FILE, not a caught exception. A blanket
# ``except Exception`` around the import cannot tell "the tool is not installed"
# from "the tool is installed and broken", and it answers both with a silent
# no-op — the exact shape of a gate that reports a pass for work it never did.
# An installed-but-broken detector now raises at import, loudly.
_OPTIONAL_SCRIPTS_REL = Path(".private") / "scripts"
_OPTIONAL_SCRIPTS = ROOT / _OPTIONAL_SCRIPTS_REL
_STALENESS_MODULE = _OPTIONAL_SCRIPTS / "expected_staleness.py"
if _STALENESS_MODULE.exists():
    if str(_OPTIONAL_SCRIPTS) not in sys.path:
        sys.path.insert(0, str(_OPTIONAL_SCRIPTS))
    from expected_staleness import (            # type: ignore  # noqa: E402
        find_stale,
        DEFAULT_SECTION_PREFIXES,
        _load_units,
    )
    _HAVE_STALENESS = True
else:                                            # pragma: no cover
    _HAVE_STALENESS = False
    find_stale = None                            # type: ignore
    _load_units = None                           # type: ignore
    DEFAULT_SECTION_PREFIXES = (".text", ".rodata", ".data", ".sdata", ".sndata")


class FinalizeError(Exception):
    """Raised to ABORT finalize on an unsafe state (e.g. build != retail)."""


# --------------------------------------------------------------------------- #
# 1. Safety gate
# --------------------------------------------------------------------------- #
def build_matches_retail(root=ROOT):
    """True/False if the linked ELF byte-matches retail; None if either file is
    absent (a public / no-game-data or not-yet-built tree — can't verify, so the
    caller must not reseed)."""
    build_elf = Path(root) / "build" / f"{MAIN_ELF}.elf"
    retail = Path(root) / "disc_extract" / MAIN_ELF
    if not build_elf.exists() or not retail.exists():
        return None
    return filecmp.cmp(str(build_elf), str(retail), shallow=False)


# --------------------------------------------------------------------------- #
# 2. Reseed the drifted expected mirrors (gated on the safety check)
# --------------------------------------------------------------------------- #
def reseed_stale(root=ROOT):
    """Reseed exactly the expected/build/<u>.o mirrors that drifted from the
    current build, in ONE build. Returns the list of reseeded unit names.

    Refuses (raises FinalizeError) when the build no longer byte-matches retail —
    reseeding then would freeze a regression as the objdiff baseline. Skips (returns
    []) when the ELF/retail pair is absent (can't verify) or the staleness
    detector is not installed (plain checkout).

    ONE BUILD, NOT N (2026-08-10, ticket 49). A reseed is one carve + discover
    + compile pass plus a file copy per mirror, so the build is shared and the
    copies are free. This used to run ``compile.py --reseed-path`` once per
    mirror, at ~15 s each: ticket 36's 1,073 drifted mirrors would have cost
    over four hours for work that costs one build. ``--reseed-paths`` takes the
    whole list."""
    root = Path(root)
    match = build_matches_retail(root)
    if match is None:
        return []                                # unverifiable — do not reseed
    if match is False:
        raise FinalizeError(
            f"build/{MAIN_ELF}.elf does not byte-match retail — refusing to reseed "
            "(that would pin a regression as the objdiff baseline). Investigate the "
            "build first.")
    if not _HAVE_STALENESS:
        return []                                # no detector installed here
    units = _load_units(root / "objdiff.json")
    stale, _unbuilt, _targets = find_stale(units, root, DEFAULT_SECTION_PREFIXES)
    reseeded = sorted(stale)
    if not reseeded:
        return []
    subprocess.run([sys.executable, "compile.py", "--reseed-paths", *reseeded],
                   cwd=root, check=True, capture_output=True, text=True)
    shown = ", ".join(reseeded[:8])
    if len(reseeded) > 8:
        shown += f", … (+{len(reseeded) - 8} more)"
    print(f"session_finalize: reseeded {len(reseeded)} stale expected mirror(s) "
          f"in one build: {shown}")
    return reseeded


# --------------------------------------------------------------------------- #
# 3. Regenerate progress/report.json to its byte-stable fixed point
# --------------------------------------------------------------------------- #
def report_is_canonical(root=ROOT) -> bool:
    """A canonical report carries the ``complete_units`` measure — objdiff-cli only
    emits it when objdiff.json is flagged AT GENERATE TIME (mark_complete.py writes
    it). A freshly-integrated objdiff.json yields a lean report on pass 1 that trips
    the pre-push atlas/progress gate; this predicate is the tripwire."""
    try:
        rep = json.loads((Path(root) / "progress" / "report.json").read_text())
        return "complete_units" in rep.get("measures", {})
    except Exception:
        return False


def regen_report(root=ROOT, commit=True, revert_on_noncanonical=True) -> bool:
    """Regenerate report.json to the regen fixed point (see report_is_canonical).

    progress.sh runs ``objdiff-cli report generate`` BEFORE ``mark_complete`` flags
    objdiff.json, and objdiff-cli only emits the per-unit complete_* fields when the
    config is flagged at generate time. So a single pass over a freshly-integrated
    objdiff.json is NOT byte-identical to what a later regen produces — iterate to
    the byte-stable fixed point (converges in 2; cap at 4) or session_check's own
    regen dirties the tree and breaks the ratchet.

    commit=True  → commit report.json + objdiff.json (batch-integrate end).
    commit=False → leave the regenerated report on disk for the human to review
                   (``session_check --fix``).
    revert_on_noncanonical=True  → a lean report reverts BOTH report.json and
                   objdiff.json to HEAD (today's default safety net).
    revert_on_noncanonical=False → a lean report is left as-is (the caller may
                   have just legitimately regenerated objdiff.json for a new
                   unit); the caller decides what to do with it instead.
    Returns True iff the regenerated report is canonical.
    Best-effort: a regen/commit failure must NEVER be fatal — log and move on."""
    root = Path(root)
    rj = root / "progress" / "report.json"

    def _progress():
        subprocess.run(["bash", "scripts/progress.sh"], cwd=root, check=True,
                       capture_output=True, text=True)
    try:
        prev = None
        for _ in range(4):
            _progress()
            cur = rj.read_text()
            if cur == prev:                      # this pass changed nothing → fixed point
                break
            prev = cur
        if not report_is_canonical(root):
            print("session_finalize: report.json still lean after regen (no "
                  "complete_units) — refusing to commit", file=sys.stderr)
            if revert_on_noncanonical:
                subprocess.run(["git", "checkout", "--", "progress/report.json",
                                "objdiff.json"], cwd=root)
                print("session_finalize: reverted report.json + objdiff.json for "
                      "a clean tree", file=sys.stderr)
            return False
        if not commit:
            print("session_finalize: report.json regenerated (fixed point); left "
                  "uncommitted for review.")
            return True
        st = subprocess.run(["git", "status", "--short", "progress/report.json",
                             "objdiff.json"], cwd=root, capture_output=True, text=True)
        if st.stdout.strip():
            subprocess.run(["git", "add", "progress/report.json", "objdiff.json"],
                           cwd=root, check=True)
            subprocess.run(["git", "commit", "-q", "-m", "chore: regen report.json"],
                           cwd=root, check=True)
            print("session_finalize: regen + committed progress/report.json (fixed point)")
        else:
            print("session_finalize: report.json already current")
        return True
    except subprocess.CalledProcessError as e:
        print(f"session_finalize: report.json regen skipped (non-fatal): {e}",
              file=sys.stderr)
        return False


# --------------------------------------------------------------------------- #
# 4. Regenerate the private struct atlas (best-effort, degrades in public)
# --------------------------------------------------------------------------- #
def regen_struct_atlas(root=ROOT):
    """Regenerate STRUCTS.md + progress/struct_atlas.json (local-only derived
    artifacts) so the ``atlas`` sub-check passes. Do NOT git-add — they are
    untracked here and captured by the local overlay's next save. Best-effort:
    an absent generator or a regen failure must never raise.

    The absence test is the FILE. Running an absent generator and reading the
    subprocess failure answers "not installed" and "installed and broken" with
    the same message, which is how a step that did not run reads as a skip."""
    gen = Path(root) / _OPTIONAL_SCRIPTS_REL / "gen_struct_atlas.py"
    if not gen.exists():
        print("session_finalize: no struct-atlas generator installed — "
              "skipping (the atlas sub-check is optional).", file=sys.stderr)
        return
    try:
        subprocess.run([sys.executable, str(gen)],
                       cwd=root, check=True, capture_output=True, text=True)
        print("session_finalize: regenerated struct atlas (STRUCTS.md + struct_atlas.json)")
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        print(f"session_finalize: struct atlas regen FAILED (non-fatal): {e}",
              file=sys.stderr)


# --------------------------------------------------------------------------- #
# Orchestrator
# --------------------------------------------------------------------------- #
def reseed_status(root=ROOT, reseeded=None, ran=True) -> str:
    """One line saying WHICH terminal path the reseed step took.

    "reseeded 0 mirror(s)" is the same sentence for three different outcomes:
    every mirror was fresh (a pass), the ELF/retail pair was absent (did not
    run), and no detector is installed (did not run). Only the first is a
    verdict. The caller prints this instead, so a step that examined nothing
    cannot read as a step that found nothing wrong."""
    if not ran:
        return "reseed skipped by the caller"
    n = len(reseeded or [])
    if n:
        return f"reseeded {n} stale mirror(s) in one build"
    if build_matches_retail(root) is None:
        return ("reseed DID NOT RUN — no build/retail pair to verify against, "
                "so a mirror could not be safely pinned")
    if not _HAVE_STALENESS:
        return "reseed DID NOT RUN — no staleness detector installed"
    return "reseeded 0 mirror(s) — every mirror is fresh"


def finalize(root=ROOT, commit=False, do_reseed=True):
    """Run the full repair set in dependency order and return a summary.

    do_reseed=False skips step 2 (when the caller already reseeded the mirrors
    during the batch and wants only the report + atlas refreshed)."""
    result = {"reseeded": []}
    if do_reseed:
        result["reseeded"] = reseed_stale(root)
    result["reseed_status"] = reseed_status(
        root, result["reseeded"], ran=do_reseed)
    regen_report(root, commit=commit)
    regen_struct_atlas(root)
    return result


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(
        description="Canonical end-of-session artifact repair (reseed stale mirrors, "
                    "regen report.json to its fixed point, regen the struct atlas).")
    ap.add_argument("--commit", action="store_true",
                    help="commit the regenerated report.json (default: leave for review)")
    ap.add_argument("--no-reseed", action="store_true",
                    help="skip the expected-mirror reseed step")
    args = ap.parse_args(argv)
    try:
        res = finalize(commit=args.commit, do_reseed=not args.no_reseed)
    except FinalizeError as e:
        print(f"session_finalize: ABORT — {e}", file=sys.stderr)
        return 1
    tail = "" if args.commit else "  (report left uncommitted — review + commit)"
    print(f"session_finalize: {res['reseed_status']}; "
          f"report + struct atlas current.{tail}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
