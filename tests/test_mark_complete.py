"""Unit tests for scripts/mark_complete.py (the "fully linked" axis).

Offline. Covers the source-only completeness predicate and verifies the
*committed* objdiff.json / report.json are mutually consistent on the
complete axis (every flagged unit really is built from source; the headline
complete_code equals the sum of flagged units' code).
"""
from __future__ import annotations

import importlib.util
import json
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parent.parent


@pytest.fixture(scope="module")
def mc():
    name = "mark_complete"
    spec = importlib.util.spec_from_file_location(
        name, ROOT / "scripts" / "mark_complete.py"
    )
    mod = importlib.util.module_from_spec(spec)
    sys.modules[name] = mod
    spec.loader.exec_module(mod)
    return mod


def _write(root: Path, rel: str, text: str) -> None:
    p = root / rel
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(text)


def test_pure_c_tu_is_complete(mc, tmp_path):
    _write(tmp_path, "src/cod/aa.c", "void f(void) {}\n")
    assert mc.is_complete_tu("src/cod/aa", tmp_path) is True


def test_tu_with_include_asm_is_not_complete(mc, tmp_path):
    _write(tmp_path, "src/cod/bb.c", 'INCLUDE_ASM("nonmatching", func_bb);\n')
    assert mc.is_complete_tu("src/cod/bb", tmp_path) is False


def test_guarded_partial_is_not_complete(mc, tmp_path):
    # A NON_MATCHING-guarded body still carries INCLUDE_ASM in its #else, so it
    # is (correctly) not "fully linked" in the default build.
    _write(
        tmp_path,
        "src/cod/cc.c",
        "#ifdef NON_MATCHING\nvoid f(void){}\n#else\n"
        'INCLUDE_ASM("nonmatching", f);\n#endif\n',
    )
    assert mc.is_complete_tu("src/cod/cc", tmp_path) is False


def test_hand_written_asm_source_is_complete(mc, tmp_path):
    # A src/ .s TU with no INCLUDE_ASM is built from source and linked.
    _write(tmp_path, "src/cod/dd.s", ".globl f\nf:\n  jr $ra\n")
    assert mc.is_complete_tu("src/cod/dd", tmp_path) is True


def test_asm_unit_is_never_complete(mc, tmp_path):
    # The undecompiled asm/ remainder is not a source TU.
    _write(tmp_path, "asm/cod/000000.part0.c", "whatever")  # should be ignored
    assert mc.is_complete_tu("asm/cod/000000.part0", tmp_path) is False


def test_missing_source_is_not_complete(mc, tmp_path):
    assert mc.is_complete_tu("src/cod/ghost", tmp_path) is False


def test_committed_artifacts_are_consistent(mc):
    """objdiff.json and report.json agree with the predicate and each other."""
    report = json.loads((ROOT / "progress" / "report.json").read_text())
    expected = set(mc.complete_units(report, ROOT))

    # report.json: flagged units, the headline measure, and the predicate all agree.
    flagged = {
        u["name"]
        for u in report["units"]
        if (u.get("metadata") or {}).get("complete")
    }
    assert flagged == expected
    derived = sum(
        int(mc._num((u.get("measures") or {}).get("total_code")))
        for u in report["units"]
        if u["name"] in expected
    )
    assert int(mc._num(report["measures"].get("complete_code"))) == derived
    total = mc._num(report["measures"].get("total_code"))
    want_pct = 0.0 if total == 0 else 100.0 * derived / total
    assert abs(report["measures"]["complete_code_percent"] - want_pct) < 1e-6

    # objdiff.json carries the same flags, so any objdiff-cli regen reproduces it.
    objdiff = json.loads((ROOT / "objdiff.json").read_text())
    od_flagged = {
        u["name"]
        for u in objdiff["units"]
        if (u.get("metadata") or {}).get("complete")
    }
    assert od_flagged == expected


def test_check_mode_passes_on_committed_report(mc):
    assert mc.main(["--check"]) == 0


def test_mark_report_writes_complete_units(mc, tmp_path, monkeypatch):
    """mark_report must set measures.complete_units (= |complete|) authoritatively,
    not rely on objdiff-cli having emitted it at generate time. A lean report
    (as objdiff-cli produces when objdiff.json has no complete flags yet) must
    come out with complete_units present after a single mark_report pass."""
    report = tmp_path / "report.json"
    report.write_text(json.dumps({
        "measures": {"total_code": 100, "matched_code": 50},   # NO complete_units
        "units": [
            {"name": "src/cod/aa", "measures": {"total_code": 30}},
            {"name": "src/cod/bb", "measures": {"total_code": 20}},
            {"name": "asm/cod/xx", "measures": {"total_code": 50}},
        ],
    }))
    monkeypatch.setattr(mc, "REPORT", report)

    changed = mc.mark_report({"src/cod/aa", "src/cod/bb"})

    assert changed is True
    out = json.loads(report.read_text())["measures"]
    assert out["complete_units"] == 2
    assert out["complete_code"] == 50          # 30 + 20
    assert abs(out["complete_code_percent"] - 50.0) < 1e-6


def test_committed_report_has_complete_units_measure(mc):
    """The committed report's headline complete_units equals the predicate count —
    the invariant a lean night-loop regen used to violate."""
    report = json.loads((ROOT / "progress" / "report.json").read_text())
    expected = set(mc.complete_units(report, ROOT))
    assert int(mc._num(report["measures"].get("complete_units"))) == len(expected)
