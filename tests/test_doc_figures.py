# tests/test_doc_figures.py
from __future__ import annotations

import json

from scripts.checks import doc_figures as df


def _measures(mf=1912, tf=11199, fuzzy=3.5454729, linked=3.0193895,
              data=83.01497, units=2278):
    return {"matched_functions": mf, "total_functions": tf,
            "fuzzy_match_percent": fuzzy, "complete_code_percent": linked,
            "matched_data_percent": data, "total_units": units}


def _readme(mf="1,912", tf="11,199", fpct="17.07", fuzzy="3.55",
            linked="3.02", data="83.01", units="2,278"):
    return (
        "## Progress\n\n| Metric | Value |\n| --- | --- |\n"
        f"| Code matched (fuzzy) | **{fuzzy} %** |\n"
        f"| Code fully linked | **{linked} %** |\n"
        f"| Functions matched | **{mf} / {tf}** ({fpct} %) |\n"
        f"| Data matched | **{data} %** |\n"
        f"| Translation units | {units} |\n")


class TestExpectedFigures:
    def test_pct_math(self):
        exp = df.expected_figures(_measures())
        assert exp["functions_matched"] == 1912
        assert abs(exp["functions_pct"] - 17.0729) < 0.01
        assert exp["units"] == 2278


class TestReconcile:
    def _tree(self, tmp_path, *, readme=None, measures=None):
        (tmp_path / "progress").mkdir()
        (tmp_path / "progress" / "report.json").write_text(
            json.dumps({"measures": measures or _measures()}))
        (tmp_path / "README.md").write_text(
            readme if readme is not None else _readme())
        return tmp_path

    def test_passes_when_synced(self, tmp_path):
        assert df.reconcile(self._tree(tmp_path)) == []

    def test_rounding_within_tolerance_passes(self, tmp_path):
        # report 17.0729 displayed as 17.07 must not trip the check
        assert df.reconcile(self._tree(
            tmp_path, readme=_readme(fpct="17.07"))) == []

    def test_detects_function_count_drift(self, tmp_path):
        errs = df.reconcile(self._tree(
            tmp_path, readme=_readme(mf="1,843", fpct="16.46")))
        assert any("functions matched" in e for e in errs)

    def test_detects_units_drift(self, tmp_path):
        errs = df.reconcile(self._tree(tmp_path, readme=_readme(units="2,185")))
        assert any("units" in e for e in errs)

    def test_detects_percent_drift(self, tmp_path):
        errs = df.reconcile(self._tree(tmp_path, readme=_readme(fuzzy="3.35")))
        assert any("fuzzy" in e.lower() or "Code matched" in e for e in errs)


class TestHasProgressTable:
    """The lint only engages when the README hard-codes a numeric Progress
    table.  A prose README that delegates its figures to decomp.dev (the
    current layout) has nothing to reconcile and must not trip the check —
    otherwise doc_figures.py reds CI on the intentional no-numbers format.
    """

    def test_true_when_hardcoded_table_present(self):
        assert df.has_progress_table(_readme()) is True

    def test_false_when_readme_delegates_to_decompdev(self):
        prose = (
            "## Measuring progress\n\n"
            "Progress is measured two complementary ways:\n\n"
            "- **matched_code_percent** — objdiff diffs every unit ...\n"
            "- **Full-ELF byte identity** — the pass/fail gate ...\n\n"
            "Live progress is also tracked at decomp.dev/LucasPicoli/god-hand-decomp.\n"
        )
        assert df.has_progress_table(prose) is False
