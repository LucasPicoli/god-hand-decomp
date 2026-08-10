#!/usr/bin/env python3
"""scripts/check_tu_complete.py — TU-level completion check.

Answers the question: is the C translation unit at ``<tu-path>``
"complete"?  A TU is complete iff:

  1. **No** ``INCLUDE_ASM("nonmatching", <name>);`` lines remain in
     the TU source.  Any **other** FOLDER string (e.g.
     ``"matching"``, ``"permanent"``) is allowed.  The
     ``"permanent"`` flavour is the project's convention for
     functions that cannot be decomp'd today — MMI / ``bnel`` /
     FP / SN-runtime — and counts as TU-matched.
  2. Every function listed in ``progress/report.json`` for the
     TU's ``.o`` unit reports ``fuzzy_match_percent == 100.0``.

A third possible sub-criterion ("no
``nonmatching <name>, <hex>`` markers in ``asm/cod/<TU>.s``") is
**deliberately omitted**: those markers are emitted by the
``nonmatching`` macro from ``include/labels.inc`` and are
load-bearing — ``compile.py``'s carve splitter
(``split_monolithic``) uses them to find function boundaries in
the monolithic asm.  Removing them would break the build.

CLI
---

    scripts/check_tu_complete.py <tu-path>
        Check the named TU (path relative to repo root, e.g.
        ``src/cod/000000.c``).  Exit 0 if complete, 1 with a
        clear diagnostic if not.

    scripts/check_tu_complete.py
        No-arg / marker mode.  Reads ``progress/in_progress_tu.txt``
        (one relative-path-per-line, ``#`` comments and blank lines
        ignored).  If absent or empty, exit 0 as a no-op (no TU
        is in-progress, nothing to check).  Otherwise check each
        listed TU and exit 0 only if all are complete.

    --json
        Emit a JSON report on stdout (one object per TU) instead
        of pretty text.

    --config PATH / --report PATH / --marker PATH
        Override the default config / report / marker paths (used
        by the offline test suite).

The marker file ``progress/in_progress_tu.txt`` is set when a TU is
picked up and cleared once the TU is complete.

Pure Python; no third-party deps.  Offline-tested by
``tests/test_check_tu_complete.py``.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path
from typing import Iterable, Optional

ROOT = Path(__file__).resolve().parent.parent

# Run as `python3 scripts/check_tu_complete.py` the repo root is not on
# `sys.path`; add it so the shared carve-schema predicate imports.
if str(ROOT) not in sys.path:
    sys.path.insert(0, str(ROOT))

from scripts.carver import CarveSchema  # noqa: E402

DEFAULT_CONFIG = ROOT / "compile_config.json"
DEFAULT_REPORT = ROOT / "progress" / "report.json"
DEFAULT_MARKER = ROOT / "progress" / "in_progress_tu.txt"

# Matches `INCLUDE_ASM("<folder>", <name>);` (semicolon optional,
# leading whitespace allowed).  Captures (folder, name).
INCLUDE_ASM_RE = re.compile(
    r"""^[ \t]*INCLUDE_ASM
        \s*\(\s*
        "([^"]+)"           # folder string
        \s*,\s*
        ([A-Za-z_][A-Za-z0-9_]*)  # function name
        \s*\)\s*;?\s*$
    """,
    re.MULTILINE | re.VERBOSE,
)


class CheckError(Exception):
    """Raised for script-level errors (missing report, bad marker, …).

    Distinguished from "TU is incomplete" — that case returns a
    populated TuReport with ``ok = False`` rather than raising.
    """


# --------------------------------------------------------------------------- #
# Data
# --------------------------------------------------------------------------- #


class TuReport:
    """Result of one TU's check.  ``ok = all sub-criteria pass``."""

    def __init__(self, tu: str) -> None:
        self.tu: str = tu
        self.nonmatching_includes: list[str] = []  # function names
        self.unmatched_functions: list[tuple[str, str]] = []  # (unit, fn)
        self.unit_name: Optional[str] = None
        self.report_unit_present: bool = False
        self.notes: list[str] = []

    @property
    def ok(self) -> bool:
        return (
            not self.nonmatching_includes
            and not self.unmatched_functions
        )

    def to_dict(self) -> dict:
        return {
            "tu": self.tu,
            "ok": self.ok,
            "unit": self.unit_name,
            "report_unit_present": self.report_unit_present,
            "nonmatching_includes": list(self.nonmatching_includes),
            "unmatched_functions": [
                {"unit": u, "function": f}
                for u, f in self.unmatched_functions
            ],
            "notes": list(self.notes),
        }

    def pretty(self) -> str:
        lines: list[str] = []
        status = "COMPLETE" if self.ok else "INCOMPLETE"
        lines.append(f"{self.tu}: {status}")
        if self.unit_name is None:
            lines.append(
                "  (no carved_funcs entries reference this TU — "
                "trivially complete)"
            )
        elif not self.report_unit_present:
            lines.append(
                f"  unit {self.unit_name!r} not present in report.json "
                f"(unbuilt or pre-objdiff)"
            )
        if self.nonmatching_includes:
            lines.append(
                f"  {len(self.nonmatching_includes)} "
                "INCLUDE_ASM(\"nonmatching\", …) line(s) remain:"
            )
            for name in self.nonmatching_includes:
                lines.append(f"    - {name}")
        if self.unmatched_functions:
            lines.append(
                f"  {len(self.unmatched_functions)} unmatched function(s) "
                "per progress/report.json:"
            )
            for unit, fn in self.unmatched_functions:
                lines.append(f"    - {fn}  (unit: {unit})")
        for note in self.notes:
            lines.append(f"  note: {note}")
        return "\n".join(lines)


# --------------------------------------------------------------------------- #
# Helpers
# --------------------------------------------------------------------------- #


def load_carved_funcs(config_path: Path) -> list[dict]:
    """Return ``carved_funcs`` from ``compile_config.json`` (or [])."""
    if not config_path.exists():
        raise CheckError(f"config not found: {config_path}")
    raw = json.loads(config_path.read_text())
    out: list[dict] = []
    for entry in raw.get("carved_funcs", []):
        # Documentation records only.  A `_`-prefix test lived here as a
        # third copy of compile.py's; ticket 36 replaced all of them with
        # the shared predicate, so a `_IO_*` carve bound to a TU is now
        # visible to the TU-completion cross-reference.
        if CarveSchema.is_doc_record(entry):
            continue
        if not isinstance(entry.get("name"), str):
            continue
        out.append(entry)
    return out


def tu_unit_name(tu: str) -> str:
    """Return the ``progress/report.json`` unit name for a TU path.

    objdiff names units by their build basename minus the suffix —
    ``src/cod/000000.c`` -> ``src/cod/000000``.  Mirrors compile.py's
    ``_objdiff_units`` naming.
    """
    p = Path(tu)
    stem = p.with_suffix("")
    return stem.as_posix()


def find_includes(tu_text: str) -> list[tuple[str, str]]:
    """Return ``[(folder, name), ...]`` for every ``INCLUDE_ASM(...)``.

    Pure function — no I/O.  Order-preserving.
    """
    return [(m.group(1), m.group(2)) for m in INCLUDE_ASM_RE.finditer(tu_text)]


def nonmatching_includes(tu_text: str) -> list[str]:
    """Return the function names in ``INCLUDE_ASM("nonmatching", …)`` lines."""
    return [name for folder, name in find_includes(tu_text)
            if folder == "nonmatching"]


def unit_unmatched_functions(unit: dict) -> list[str]:
    """Return names of functions in ``unit`` that aren't 100 % matched.

    A function counts as matched iff its
    ``fuzzy_match_percent == 100.0``.  Missing key -> not matched.
    """
    out: list[str] = []
    for fn in unit.get("functions", []) or []:
        if not isinstance(fn, dict):
            continue
        pct = fn.get("fuzzy_match_percent")
        if pct is None or float(pct) < 100.0:
            out.append(str(fn.get("name", "<unnamed>")))
    return out


def load_report(report_path: Path) -> dict:
    if not report_path.exists():
        raise CheckError(
            f"progress/report.json not found at {report_path}; "
            f"run `python compile.py --setup` then `scripts/progress.sh`."
        )
    return json.loads(report_path.read_text())


def find_report_unit(report: dict, unit_name: str) -> Optional[dict]:
    for unit in report.get("units", []):
        if unit.get("name") == unit_name:
            return unit
    return None


# --------------------------------------------------------------------------- #
# Core
# --------------------------------------------------------------------------- #


def check_one(
    tu: str,
    *,
    root: Path,
    config_path: Path,
    report_path: Path,
) -> TuReport:
    """Compute the TuReport for one TU.  Raises ``CheckError`` for
    script-level errors (missing config, missing TU source); returns
    a populated TuReport with ``ok = False`` for *content* failures."""
    report = TuReport(tu)
    tu_full = (root / tu).resolve()
    if not tu_full.exists():
        raise CheckError(f"TU source not found: {tu}")

    # Sub-criterion 1: scan TU source for INCLUDE_ASM("nonmatching", …).
    tu_text = tu_full.read_text()
    report.nonmatching_includes = nonmatching_includes(tu_text)

    # Sub-criterion 2: cross-reference carved_funcs + report.json.
    carved = load_carved_funcs(config_path)
    tu_carves = [e for e in carved if e.get("tu") == tu]
    if not tu_carves:
        # No carved_funcs reference this TU.  Trivially complete (sub-
        # criterion 2 has no work to do); sub-criterion 1 stands.
        return report

    report.unit_name = tu_unit_name(tu)
    full_report = load_report(report_path)
    unit = find_report_unit(full_report, report.unit_name)
    if unit is None:
        report.notes.append(
            f"unit {report.unit_name!r} not in progress/report.json; "
            f"treating as not-yet-built (sub-criterion 2 skipped)."
        )
        return report
    report.report_unit_present = True

    unmatched_names = set(unit_unmatched_functions(unit))
    carved_names = {e["name"] for e in tu_carves}
    # Universe of functions to check: union of carved + everything
    # objdiff lists for this unit (catches plain-C functions in the
    # same TU that aren't carved-from-asm).
    listed_names = {
        str(fn.get("name"))
        for fn in unit.get("functions", []) or []
        if isinstance(fn, dict)
    }
    for fn in sorted(unmatched_names & (carved_names | listed_names)):
        report.unmatched_functions.append((report.unit_name, fn))
    return report


def read_marker(marker_path: Path) -> list[str]:
    """Return the list of in-progress TUs from the marker file."""
    if not marker_path.exists():
        return []
    out: list[str] = []
    for raw in marker_path.read_text().splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        out.append(line)
    return out


def check_marker(
    *,
    root: Path,
    config_path: Path,
    report_path: Path,
    marker_path: Path,
) -> list[TuReport]:
    """Run check_one for every TU in the marker file (possibly none)."""
    tus = read_marker(marker_path)
    return [
        check_one(tu, root=root, config_path=config_path,
                  report_path=report_path)
        for tu in tus
    ]


# --------------------------------------------------------------------------- #
# CLI
# --------------------------------------------------------------------------- #


def _emit(reports: list[TuReport], *, as_json: bool, marker_used: bool) -> None:
    if as_json:
        json.dump(
            {
                "marker_used": marker_used,
                "tus": [r.to_dict() for r in reports],
            },
            sys.stdout,
            indent=2,
        )
        sys.stdout.write("\n")
        return
    if not reports:
        if marker_used:
            print("check_tu_complete: no TU in marker — no-op pass.")
        else:
            print("check_tu_complete: no TU specified.")
        return
    for r in reports:
        print(r.pretty())


def _cli(argv: list[str]) -> int:
    p = argparse.ArgumentParser(
        description="TU-level completion check.",
    )
    p.add_argument("tu", nargs="?", default=None,
                   help="TU path (e.g. src/cod/000000.c). Omit to use "
                        "the marker file.")
    p.add_argument("--json", action="store_true",
                   help="Emit JSON instead of pretty text.")
    p.add_argument("--config", type=Path, default=DEFAULT_CONFIG)
    p.add_argument("--report", type=Path, default=DEFAULT_REPORT)
    p.add_argument("--marker", type=Path, default=DEFAULT_MARKER)
    p.add_argument("--root", type=Path, default=ROOT,
                   help="Repo root (default: parent of this script).")
    args = p.parse_args(argv)

    try:
        if args.tu is not None:
            reports = [check_one(
                args.tu, root=args.root,
                config_path=args.config, report_path=args.report,
            )]
            marker_used = False
        else:
            reports = check_marker(
                root=args.root,
                config_path=args.config,
                report_path=args.report,
                marker_path=args.marker,
            )
            marker_used = True
    except CheckError as e:
        print(f"check_tu_complete: {e}", file=sys.stderr)
        return 2

    _emit(reports, as_json=args.json, marker_used=marker_used)
    return 0 if all(r.ok for r in reports) else 1


if __name__ == "__main__":
    sys.exit(_cli(sys.argv[1:]))
