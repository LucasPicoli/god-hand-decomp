#!/usr/bin/env python3
"""mark_complete.py — derive the "fully linked" (objdiff ``complete``) axis.

objdiff/decomp.dev report three code axes:

  * ``fuzzy_match_percent``  -> decomp.dev "decompiled" (exact + NON_MATCHING
    partials; see scripts/score_nm.sh)
  * ``matched_code_percent`` -> 100%-exact bytes, anywhere (incl. inside a
    still-in-progress TU)
  * ``complete_code_percent``-> decomp.dev "fully linked": bytes in TUs that
    are *built entirely from source and linked* (no INCLUDE_ASM target bytes)

This project never set the third, so decomp.dev showed "fully linked" as 0.
``complete`` is an author assertion in the objdiff project ("this unit is
done"); objdiff then sums each complete unit's code into ``complete_code``.

Completeness here is decidable from SOURCE ALONE, because the default
``python compile.py`` build is byte-identical to retail: a TU with no
``INCLUDE_ASM(`` is 100% real source that necessarily matches. So:

    a unit is complete  iff  it is a real source TU (src/cod/<name>.{c,s})
                             whose source contains no ``INCLUDE_ASM(``

(Empirically this predicate equals the set of 100%-matched src/ units exactly
— verified by tests/test_mark_complete.py against the committed report.)

This script applies that predicate to the two committed artifacts:

  * objdiff.json     -> per-unit ``metadata.complete = true`` (so any
                        objdiff-cli regen reproduces complete_code)
  * progress/report.json -> per-unit ``metadata.complete`` + the headline
                        ``measures.complete_code`` / ``complete_code_percent``
                        (this is the file decomp.dev ingests)

Idempotent. Pure Python, no toolchain. Run it after objdiff-cli regenerates
the report (scripts/progress.sh and scripts/score_nm.sh both call it), or
standalone to refresh the committed artifacts.

    python3 scripts/mark_complete.py            # patch objdiff.json + report.json
    python3 scripts/mark_complete.py --check     # exit 1 if either is out of date
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OBJDIFF = ROOT / "objdiff.json"
REPORT = ROOT / "progress" / "report.json"


def _num(value) -> float:
    """objdiff stores byte counts as strings; coerce to float (0 on junk)."""
    try:
        return float(value)
    except (TypeError, ValueError):
        return 0.0


def is_complete_tu(name: str, root: Path = ROOT) -> bool:
    """True iff ``name`` is a source TU built entirely from source.

    Predicate: the unit name is under ``src/`` and a ``<name>.c`` or
    ``<name>.s`` source exists that contains no ``INCLUDE_ASM(`` line.

    NOTE: kept in sync with compile.py ``_objdiff_units`` (which sets the same
    flag when it regenerates objdiff.json from scratch via ``--setup``).
    """
    if not name.startswith("src/"):
        return False
    for ext in (".c", ".s"):
        src = root / (name + ext)
        if src.is_file():
            return "INCLUDE_ASM(" not in src.read_text(
                encoding="utf-8", errors="replace"
            )
    return False


def complete_units(report: dict, root: Path = ROOT) -> list[str]:
    """Names of report units that satisfy ``is_complete_tu``."""
    return [
        u["name"]
        for u in report.get("units", [])
        if isinstance(u, dict) and is_complete_tu(u.get("name", ""), root)
    ]


def _set_complete(metadata_owner: dict, complete: bool) -> bool:
    """Set/clear ``metadata.complete`` on a unit dict; return True if changed."""
    md = metadata_owner.setdefault("metadata", {})
    if complete:
        if md.get("complete") is True:
            return False
        md["complete"] = True
        return True
    if "complete" in md:
        del md["complete"]
        return True
    return False


def mark_objdiff(complete: set[str]) -> bool:
    """Flag complete units in objdiff.json. Returns True if the file changed."""
    obj = json.loads(OBJDIFF.read_text())
    changed = False
    for u in obj.get("units", []):
        changed |= _set_complete(u, u.get("name") in complete)
    if changed:
        OBJDIFF.write_text(json.dumps(obj, indent=2) + "\n")
    return changed


def mark_report(complete: set[str]) -> bool:
    """Flag complete units in report.json and write the headline complete_code
    / complete_code_percent measures. Returns True if the file changed."""
    rep = json.loads(REPORT.read_text())
    before = json.dumps(rep, sort_keys=True)

    total_code = _num(rep.get("measures", {}).get("total_code"))
    complete_code = 0
    for u in rep.get("units", []):
        is_c = u.get("name") in complete
        _set_complete(u, is_c)
        if is_c:
            complete_code += int(_num(u.get("measures", {}).get("total_code")))

    m = rep.setdefault("measures", {})
    m["complete_code"] = complete_code
    m["complete_code_percent"] = (
        0.0 if total_code == 0 else 100.0 * complete_code / total_code
    )
    # objdiff-cli only emits complete_units when objdiff.json already carries the
    # complete flags at generate time; a fresh objdiff.json (as integrate leaves
    # it) makes the first generate omit it. Write it authoritatively here so a
    # single progress.sh pass is always canonical, regardless of flag ordering.
    m["complete_units"] = len(complete)

    after = json.dumps(rep, sort_keys=True)
    if before != after:
        REPORT.write_text(json.dumps(rep, indent=2) + "\n")
        return True
    return False


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description="Derive the objdiff complete axis.")
    ap.add_argument(
        "--check",
        action="store_true",
        help="exit 1 if objdiff.json / report.json are out of date (no write).",
    )
    args = ap.parse_args(argv)

    if not REPORT.is_file():
        print("mark_complete: progress/report.json missing — nothing to do.")
        return 0
    rep = json.loads(REPORT.read_text())
    complete = set(complete_units(rep))
    code = int(
        sum(
            _num(u.get("measures", {}).get("total_code"))
            for u in rep.get("units", [])
            if u.get("name") in complete
        )
    )
    total = int(_num(rep.get("measures", {}).get("total_code")))
    pct = 0.0 if total == 0 else 100.0 * code / total

    if args.check:
        cur = _num(rep.get("measures", {}).get("complete_code"))
        flagged = {
            u["name"]
            for u in rep.get("units", [])
            if u.get("metadata", {}).get("complete")
        }
        stale = (int(cur) != code) or (flagged != complete)
        print(
            f"mark_complete --check: complete_code want={code} have={int(cur)}; "
            f"{'STALE' if stale else 'ok'}"
        )
        return 1 if stale else 0

    ch_obj = mark_objdiff(complete)
    ch_rep = mark_report(complete)
    print(
        f"mark_complete: {len(complete)} fully-linked TU(s) -> "
        f"complete_code {code} B ({pct:.4f}%)"
        f"  [objdiff.json {'updated' if ch_obj else 'ok'},"
        f" report.json {'updated' if ch_rep else 'ok'}]"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
