"""Unit tests for scripts/checks/report_lint.py (progress report integrity).

Offline; exercises the pure ``lint_report`` consistency checker against
synthetic report dicts, plus a smoke test that the *committed*
``progress/report.json`` is internally consistent.

This lint is the integrity guard for the "upload the committed report"
model: ``report.json`` is produced by objdiff-cli (toolchain-bound) and
can't be regenerated in a toolchain-free CI runner, so a hand-edited
report that inflates the badges/decomp.dev numbers would otherwise slip
through. ``lint_report`` re-derives the headline measures from the
per-unit / per-function detail and flags any disagreement.
"""
from __future__ import annotations

import importlib.util
import json
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent


@pytest.fixture(scope="module")
def lint():
    name = "report_lint"
    spec = importlib.util.spec_from_file_location(
        name, ROOT / "scripts" / "checks" / "report_lint.py"
    )
    mod = importlib.util.module_from_spec(spec)
    sys.modules[name] = mod
    spec.loader.exec_module(mod)
    return mod


def _good_report():
    """A minimal but internally-consistent report.

    Two functions, one fully matched. Byte/percent/count headline
    measures all agree with the per-unit detail.
    """
    return {
        "version": 2,
        "measures": {
            "total_code": "200",
            "matched_code": "100",
            "matched_code_percent": 50.0,
            "total_data": "0",
            "matched_data": "0",
            "matched_data_percent": 0.0,
            "total_functions": 2,
            "matched_functions": 1,
            "matched_functions_percent": 50.0,
            "total_units": 1,
            "fuzzy_match_percent": 50.0,
        },
        "units": [
            {
                "name": "src/cod/000000",
                "measures": {"fuzzy_match_percent": 50.0},
                "functions": [
                    {"name": "f_done", "size": "100", "fuzzy_match_percent": 100.0},
                    {"name": "f_todo", "size": "100", "fuzzy_match_percent": 0.0},
                ],
            }
        ],
        "categories": [],
    }


def test_clean_report_has_no_problems(lint):
    assert lint.lint_report(_good_report()) == []


def test_missing_measures_is_flagged(lint):
    r = _good_report()
    del r["measures"]
    problems = lint.lint_report(r)
    assert any("measures" in p for p in problems)


def test_matched_code_exceeding_total_is_flagged(lint):
    r = _good_report()
    r["measures"]["matched_code"] = "300"  # > total_code (200)
    problems = lint.lint_report(r)
    assert any("matched_code" in p for p in problems)


def test_percent_out_of_range_is_flagged(lint):
    r = _good_report()
    r["measures"]["matched_data_percent"] = 150.0
    problems = lint.lint_report(r)
    assert any("matched_data_percent" in p for p in problems)


def test_total_units_mismatch_is_flagged(lint):
    r = _good_report()
    r["measures"]["total_units"] = 99  # but len(units) == 1
    problems = lint.lint_report(r)
    assert any("total_units" in p for p in problems)


def test_matched_functions_disagreeing_with_detail_is_flagged(lint):
    # The headline claims 2 matched, but only 1 function is at 100% in the
    # per-function detail. This is the core anti-tamper invariant.
    r = _good_report()
    r["measures"]["matched_functions"] = 2
    problems = lint.lint_report(r)
    assert any("matched_functions" in p for p in problems)


def test_function_in_two_units_is_flagged(lint):
    r = _good_report()
    copy = dict(r["units"][0], name="src/cod/000100")
    r["units"].append(copy)
    r["measures"].update(total_units=2, total_functions=4, matched_functions=2)
    problems = lint.lint_report(r)
    assert any("f_done appears in unit src/cod/000000" in p for p in problems)


def test_total_functions_disagreeing_with_detail_is_flagged(lint):
    r = _good_report()
    r["measures"]["total_functions"] = 5  # detail only has 2
    problems = lint.lint_report(r)
    assert any("total_functions" in p for p in problems)


def test_percent_inconsistent_with_byte_counts_is_flagged(lint):
    # matched_code_percent claims 99% but bytes say 100/200 = 50%.
    r = _good_report()
    r["measures"]["matched_code_percent"] = 99.0
    problems = lint.lint_report(r)
    assert any("matched_code_percent" in p for p in problems)


def test_unmatched_function_null_percent_is_valid(lint):
    # objdiff records unmatched functions with fuzzy_match_percent = null.
    # That must count toward total_functions but not be flagged as
    # out-of-range, and must not count as matched.
    r = _good_report()
    r["units"][0]["functions"].append(
        {"name": "f_unmatched", "size": "40", "fuzzy_match_percent": None}
    )
    # 3 functions now, still 1 matched — keep the headline measures consistent
    # so this test isolates the null-percent handling.
    r["measures"]["total_functions"] = 3
    r["measures"]["matched_functions_percent"] = 100.0 / 3
    assert lint.lint_report(r) == []


def test_function_percent_out_of_range_is_flagged(lint):
    r = _good_report()
    r["units"][0]["functions"][0]["fuzzy_match_percent"] = 250.0
    problems = lint.lint_report(r)
    assert problems  # some problem reported


def _report_with_complete():
    """A consistent report carrying the complete ("fully linked") axis.

    Unit A (100 B) is flagged complete; unit B is not. complete_code therefore
    equals A's total_code, and the percent agrees with complete_code/total_code.
    """
    return {
        "version": 2,
        "measures": {
            "total_code": "300",
            "matched_code": "100",
            "matched_code_percent": 100.0 / 3,
            "total_data": "0",
            "matched_data": "0",
            "matched_data_percent": 0.0,
            "total_functions": 2,
            "matched_functions": 1,
            "matched_functions_percent": 50.0,
            "total_units": 2,
            "fuzzy_match_percent": 100.0 / 3,
            "complete_code": 100,
            "complete_code_percent": 100.0 / 3,
        },
        "units": [
            {
                "name": "src/cod/done",
                "metadata": {"complete": True},
                "measures": {"total_code": "100", "fuzzy_match_percent": 100.0},
                "functions": [
                    {"name": "a", "size": "100", "fuzzy_match_percent": 100.0}
                ],
            },
            {
                "name": "src/cod/wip",
                "measures": {"total_code": "200", "fuzzy_match_percent": 0.0},
                "functions": [
                    {"name": "b", "size": "200", "fuzzy_match_percent": 0.0}
                ],
            },
        ],
        "categories": [],
    }


def test_consistent_complete_code_passes(lint):
    assert lint.lint_report(_report_with_complete()) == []


def test_complete_code_disagreeing_with_flagged_units_is_flagged(lint):
    # Headline claims 250 B complete, but only one 100 B unit is flagged.
    r = _report_with_complete()
    r["measures"]["complete_code"] = 250
    problems = lint.lint_report(r)
    assert any("complete_code" in p for p in problems)


def test_complete_code_percent_inconsistent_is_flagged(lint):
    r = _report_with_complete()
    r["measures"]["complete_code_percent"] = 99.0  # bytes say 100/300 = 33%
    problems = lint.lint_report(r)
    assert any("complete_code_percent" in p for p in problems)


def test_complete_code_exceeding_total_is_flagged(lint):
    r = _report_with_complete()
    r["units"][0]["measures"]["total_code"] = "400"
    r["measures"]["complete_code"] = 400  # > total_code (300)
    problems = lint.lint_report(r)
    assert any("complete_code" in p for p in problems)


def test_report_without_complete_axis_still_passes(lint):
    # The complete axis is optional: a report with no complete_code (older
    # objdiff output) must not be penalised.
    assert lint.lint_report(_good_report()) == []


def test_committed_report_is_clean(lint):
    """The report.json actually committed to the repo must pass the lint."""
    report = json.loads((ROOT / "progress" / "report.json").read_text())
    assert lint.lint_report(report) == []


def test_main_returns_0_on_clean_file(lint, tmp_path):
    p = tmp_path / "report.json"
    p.write_text(json.dumps(_good_report()))
    assert lint.main([str(p)]) == 0


def test_main_returns_1_on_broken_file(lint, tmp_path):
    r = _good_report()
    r["measures"]["matched_functions"] = 99
    p = tmp_path / "report.json"
    p.write_text(json.dumps(r))
    assert lint.main([str(p)]) == 1


def test_main_skips_when_file_missing(lint, tmp_path):
    assert lint.main([str(tmp_path / "nope.json")]) == 77
