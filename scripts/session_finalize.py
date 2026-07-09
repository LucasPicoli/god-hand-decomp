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
     under-counts until reseeded). Fix per unit: ``compile.py --reseed-path``.
  3. regen_report          — objdiff ``progress/report.json`` to its byte-stable
     fixed point (objdiff-cli's generate-before-flag ordering needs 2 passes).
  4. regen_struct_atlas    — the private STRUCTS.md / struct_atlas.json artifacts.

The reseed + struct-atlas steps depend on private tooling under .private/scripts;
in a public checkout they degrade to graceful no-ops (like the public wrappers
scripts/checks/{expected_stale,atlas}.sh, which already point at those paths).
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

# The staleness detector + its helpers are private tooling. Import them if the
# overlay is present; otherwise reseed_stale becomes a no-op (public checkout).
_PRIV_SCRIPTS = ROOT / ".private" / "scripts"
try:
    if str(_PRIV_SCRIPTS) not in sys.path:
        sys.path.insert(0, str(_PRIV_SCRIPTS))
    from expected_staleness import (            # type: ignore
        find_stale,
        DEFAULT_SECTION_PREFIXES,
        _load_units,
    )
    _HAVE_STALENESS = True
except Exception:                                # pragma: no cover - public checkout
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
    current build. Returns the list of reseeded unit names.

    Refuses (raises FinalizeError) when the build no longer byte-matches retail —
    reseeding then would freeze a regression as the objdiff baseline. Skips (returns
    []) when the ELF/retail pair is absent (can't verify) or the private staleness
    tooling is not present (public checkout)."""
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
        return []                                # public checkout: nothing to reseed
    units = _load_units(root / "objdiff.json")
    stale, _unbuilt, _targets = find_stale(units, root, DEFAULT_SECTION_PREFIXES)
    reseeded = []
    for name in sorted(stale):
        subprocess.run([sys.executable, "compile.py", "--reseed-path", name],
                       cwd=root, check=True, capture_output=True, text=True)
        reseeded.append(name)
    if reseeded:
        print(f"session_finalize: reseeded {len(reseeded)} stale expected mirror(s): "
              + ", ".join(reseeded))
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


def regen_report(root=ROOT, commit=True):
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
                  "complete_units) — refusing to commit; reverting for a clean tree",
                  file=sys.stderr)
            subprocess.run(["git", "checkout", "--", "progress/report.json",
                            "objdiff.json"], cwd=root)
            return
        if not commit:
            print("session_finalize: report.json regenerated (fixed point); left "
                  "uncommitted for review.")
            return
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
    except subprocess.CalledProcessError as e:
        print(f"session_finalize: report.json regen skipped (non-fatal): {e}",
              file=sys.stderr)


# --------------------------------------------------------------------------- #
# 4. Regenerate the private struct atlas (best-effort, degrades in public)
# --------------------------------------------------------------------------- #
def regen_struct_atlas(root=ROOT):
    """Regenerate STRUCTS.md + progress/struct_atlas.json (private-only derived
    artifacts) so the ``atlas`` sub-check passes. Do NOT git-add — they are
    public-ignored and captured by the private overlay's next save. Best-effort:
    a missing generator (public checkout) or a regen failure must never raise."""
    try:
        subprocess.run([sys.executable, ".private/scripts/gen_struct_atlas.py"],
                       cwd=root, check=True, capture_output=True, text=True)
        print("session_finalize: regenerated struct atlas (STRUCTS.md + struct_atlas.json)")
    except (subprocess.CalledProcessError, FileNotFoundError) as e:
        print(f"session_finalize: struct atlas regen skipped (non-fatal): {e}",
              file=sys.stderr)


# --------------------------------------------------------------------------- #
# Orchestrator
# --------------------------------------------------------------------------- #
def finalize(root=ROOT, commit=False, do_reseed=True):
    """Run the full repair set in dependency order and return a summary.

    do_reseed=False skips step 2 (when the caller already reseeded the mirrors
    during the batch and wants only the report + atlas refreshed)."""
    result = {"reseeded": []}
    if do_reseed:
        result["reseeded"] = reseed_stale(root)
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
    print(f"session_finalize: reseeded {len(res['reseeded'])} mirror(s); "
          f"report + struct atlas current.{tail}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
