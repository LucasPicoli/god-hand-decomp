from __future__ import annotations

import scripts.session_finalize as sf


def _seed(root):
    (root / "progress").mkdir(parents=True, exist_ok=True)
    (root / "progress" / "report.json").write_text("{}")


def test_returns_true_when_canonical(monkeypatch, tmp_path):
    _seed(tmp_path)
    monkeypatch.setattr(sf, "report_is_canonical", lambda root: True)
    monkeypatch.setattr(sf.subprocess, "run", lambda *a, **k: None)
    assert sf.regen_report(tmp_path, commit=False) is True


def test_lean_report_returns_false(monkeypatch, tmp_path):
    _seed(tmp_path)
    monkeypatch.setattr(sf, "report_is_canonical", lambda root: False)
    calls = []
    monkeypatch.setattr(sf.subprocess, "run",
                        lambda *a, **k: calls.append(a[0]))
    assert sf.regen_report(tmp_path, commit=False) is False
    # default: lean report is reverted (checkout appears in the git calls)
    assert any("checkout" in c for c in calls)


def test_no_revert_when_opted_out(monkeypatch, tmp_path):
    _seed(tmp_path)
    monkeypatch.setattr(sf, "report_is_canonical", lambda root: False)
    calls = []
    monkeypatch.setattr(sf.subprocess, "run",
                        lambda *a, **k: calls.append(a[0]))
    ok = sf.regen_report(tmp_path, commit=False, revert_on_noncanonical=False)
    assert ok is False
    assert not any("checkout" in c for c in calls)
