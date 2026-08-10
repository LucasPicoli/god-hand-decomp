"""Unit tests for the per-TU flag ADD key, ``compile_units[].c_flags_add``.

Issue 45.  ``c_flags_drop`` removes one of the three global ``c_flags`` from a
single translation unit; ``c_flags_add`` appends one.  The additive direction
is the one retail needs for ``-f=-fno-gcse``, which stops gcc 2.9x unifying
two ``sp+K`` address computations into one pseudo whose live range crosses a
call (issue 42).

The additive direction is also the dangerous one: ``c_flags_drop`` is bounded
by construction (there are only three flags to remove), while an unbounded ADD
would let one TU select any code-generation option and call the result a
match.  So the vocabulary is CLOSED — ``compile.SUPPORTED_C_FLAG_ADDS`` — and
these tests lock that shut.

Inventory (one ``-k`` slice per behaviour):

    Config.compile_units   — default empty / accepted flag / rejected flag /
                             wrong type / duplicate / add-and-drop collision
    CompileUnit            — default field is the empty tuple
    discover()             — a c unit picks the key up; asm/vsm are unaffected
    _cc() argv shape       — the flag is appended AFTER the drop filter
    dual_compiler_regress  — the gate honours the key
    the necessity gate     — an inert c_flags_add fails scripts/checks

Issue 58 generalised the necessity gate to BOTH keys and renamed it
``scripts/checks/c_flags_necessary.py``.  The drop side of it, and the drop
vocabulary this file's docstring calls "bounded by construction", live in
tests/test_c_flags_drop_key.py.
"""
from __future__ import annotations

import dataclasses
import json
import sys
from pathlib import Path

import pytest

import compile as cm

sys.path.insert(0, str(cm.ROOT / "scripts" / "checks"))
import dual_compiler_regress as dcr  # noqa: E402
import c_flags_necessary as cfan  # noqa: E402

GCSE = "-f=-fno-gcse"
REORDER = "-f=-freorder-blocks"


def _mkcfg(**overrides) -> cm.Config:
    raw = {
        "tools": {},
        "include_dirs": [],
        "defines": [],
        "c_flags": ["-O2", "-G0", REORDER],
        "as_flags": [],
        "dvp_as_flags": [],
        "linker_scripts": [],
        "linker_flags": [],
        "asm_sources_glob": [],
        "c_sources_glob": [],
        "vsm_sources_glob": [],
        "sdata_overrides": {},
        "build_dir": "build",
        "output_elf": "build/out.elf",
        "output_map": "build/out.map",
        "preserve_in_build": [],
        "objdiff": {},
        "section_flag_overrides": {},
        "carved_funcs": [],
        "compile_units": [],
    }
    raw.update(overrides)
    return cm.Config(raw=raw)


# --------------------------------------------------------------------------- #
# Config.compile_units validation
# --------------------------------------------------------------------------- #
class TestValidation:

    def test_absent_key_is_an_empty_tuple(self):
        cfg = _mkcfg(compile_units=[{"path": "src/cod/a.c"}])
        assert cfg.compile_units["src/cod/a.c"]["c_flags_add"] == ()

    def test_allowed_flag_is_accepted(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_add": [GCSE]}])
        assert cfg.compile_units["src/cod/a.c"]["c_flags_add"] == (GCSE,)

    def test_flag_outside_the_vocabulary_is_rejected(self):
        """The whole point of the key: a TU cannot select an arbitrary
        code-generation option and call the result a match."""
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_add": ["-O0"]}])
        with pytest.raises(cm.BuildError, match="not in the allowed set"):
            cfg.compile_units

    def test_a_bare_string_is_rejected(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_add": GCSE}])
        with pytest.raises(cm.BuildError, match="must be a list"):
            cfg.compile_units

    def test_a_non_string_member_is_rejected(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_add": [1]}])
        with pytest.raises(cm.BuildError, match="must be a list"):
            cfg.compile_units

    def test_a_duplicate_is_rejected(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_add": [GCSE, GCSE]}])
        with pytest.raises(cm.BuildError, match="duplicate"):
            cfg.compile_units

    def test_the_same_flag_in_add_and_drop_is_rejected(self):
        """Adding and dropping one flag has no defined meaning, so it is a
        config error rather than a silent win for whichever runs last."""
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c",
             "c_flags_add": [GCSE], "c_flags_drop": [GCSE]}])
        with pytest.raises(cm.BuildError, match="both"):
            cfg.compile_units

    def test_the_vocabulary_holds_exactly_the_gcse_flag_today(self):
        """Widening this set is a map decision. If this test fails, the map
        owes the record an argument for the new member."""
        assert cm.SUPPORTED_C_FLAG_ADDS == frozenset({GCSE})


# --------------------------------------------------------------------------- #
# CompileUnit + discover()
# --------------------------------------------------------------------------- #
class TestUnitPlumbing:

    def test_default_field_is_empty(self, tmp_path):
        u = cm.CompileUnit(src=tmp_path / "x.c", obj=tmp_path / "x.o",
                           kind="c", rel=Path("x.c"))
        assert u.c_flags_add == ()

    def test_discover_picks_the_key_up_for_a_c_unit(self, tmp_path, monkeypatch):
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src/cod").mkdir(parents=True)
        (tmp_path / "src/cod/a.c").write_text("")
        (tmp_path / "src/cod/b.c").write_text("")
        cfg = _mkcfg(c_sources_glob=["src/cod/*.c"],
                     compile_units=[{"path": "src/cod/a.c",
                                     "c_flags_add": [GCSE]}])
        units = {str(u.rel): u for u in cm.discover(cfg) if u.kind == "c"}
        assert units["src/cod/a.c"].c_flags_add == (GCSE,)
        assert units["src/cod/b.c"].c_flags_add == ()


# --------------------------------------------------------------------------- #
# _cc() argv shape
# --------------------------------------------------------------------------- #
class TestArgv:

    @staticmethod
    def _argv(monkeypatch, tmp_path, **unit_kw) -> list[str]:
        captured: list[list[str]] = []
        monkeypatch.setattr(cm, "run",
                            lambda argv, log, stage=None, **kw: captured.append(list(argv)))
        monkeypatch.setattr(cm, "_fix_section_flags",
                            lambda unit, cfg, log: None)
        cfg = _mkcfg(tools={"ee_cc_wrap": "/bin/true"})
        unit = cm.CompileUnit(src=tmp_path / "x.c", obj=tmp_path / "x.o",
                              kind="c", rel=Path("x.c"), **unit_kw)
        cm._cc(unit, cfg, cm.Logger(verbose=False))
        return captured[0]

    def test_no_key_leaves_the_flags_alone(self, monkeypatch, tmp_path):
        argv = self._argv(monkeypatch, tmp_path)
        assert GCSE not in argv
        assert REORDER in argv

    def test_the_flag_is_appended(self, monkeypatch, tmp_path):
        argv = self._argv(monkeypatch, tmp_path, c_flags_add=(GCSE,))
        assert GCSE in argv
        assert REORDER in argv

    def test_add_runs_after_drop(self, monkeypatch, tmp_path):
        """The two keys have a defined order, so they cannot fight."""
        argv = self._argv(monkeypatch, tmp_path,
                          c_flags_drop=(REORDER,), c_flags_add=(GCSE,))
        assert REORDER not in argv
        assert argv.index(GCSE) > argv.index("-O2")


# --------------------------------------------------------------------------- #
# the gate honours the key
# --------------------------------------------------------------------------- #
class TestGateHonoursTheKey:

    def test_dual_compiler_regress_forwards_c_flags_add(self, monkeypatch, tmp_path):
        """Mirrors tests/test_dual_compiler_regress.py's shape. Without this
        the harness recompiles a c_flags_add TU WITHOUT the flag and reports
        false gate drift — the omission that bit the gnu-as route."""
        seen: list[cm.CompileUnit] = []
        monkeypatch.setattr(dcr.cpy, "_cc",
                            lambda unit, cfg, log: seen.append(unit))
        src = cm.ROOT / "src" / "cod" / "probe_c_flags_add.c"
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/probe_c_flags_add.c", "c_flags_add": [GCSE]}])
        dcr._compile_one(src, "cygnus-2.96", tmp_path / "o.o", cfg,
                         cm.Logger(verbose=False))
        assert seen and seen[0].c_flags_add == (GCSE,)

    def test_dual_compiler_regress_forwards_fp_hazard_rules(self, monkeypatch, tmp_path):
        """The sibling key issue 40 shipped in the cc-wraps and could not
        land. Same rail, same failure mode."""
        seen: list[cm.CompileUnit] = []
        monkeypatch.setattr(dcr.cpy, "_cc",
                            lambda unit, cfg, log: seen.append(unit))
        src = cm.ROOT / "src" / "cod" / "probe_fp_rules.c"
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/probe_fp_rules.c",
             "fp_hazard_rules": "mtc1,fdiv"}])
        dcr._compile_one(src, "cygnus-2.96", tmp_path / "o.o", cfg,
                         cm.Logger(verbose=False))
        assert seen and seen[0].fp_hazard_rules == "mtc1,fdiv"


# --------------------------------------------------------------------------- #
# the necessity gate
# --------------------------------------------------------------------------- #
class TestNecessityGate:

    @staticmethod
    def _cfg_with_one_unit(tmp_path, monkeypatch):
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src/cod").mkdir(parents=True)
        (tmp_path / "src/cod/a.c").write_text("int a;\n")
        return _mkcfg(c_sources_glob=["src/cod/*.c"],
                      compile_units=[{"path": "src/cod/a.c",
                                      "c_flags_add": [GCSE]}])

    def test_no_such_tu_is_a_pass(self, tmp_path, monkeypatch):
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src/cod").mkdir(parents=True)
        (tmp_path / "src/cod/a.c").write_text("int a;\n")
        cfg = _mkcfg(c_sources_glob=["src/cod/*.c"])
        assert cfan.check(cfg, cm.Logger(verbose=False)) == 0

    def test_an_inert_flag_fails(self, tmp_path, monkeypatch, capsys):
        """A per-TU flag that moves no byte is a claim about retail's build
        with no evidence behind it. The ELF gate cannot see it, because the
        flag is invisible on most TUs — so this gate exists."""
        cfg = self._cfg_with_one_unit(tmp_path, monkeypatch)
        monkeypatch.setattr(cfan.cpy, "_cc",
                            lambda unit, cfg, log: unit.obj.write_bytes(b"same"))
        assert cfan.check(cfg, cm.Logger(verbose=False)) == 1
        assert "INERT" in capsys.readouterr().out

    def test_a_load_bearing_flag_passes(self, tmp_path, monkeypatch):
        cfg = self._cfg_with_one_unit(tmp_path, monkeypatch)

        def fake_cc(unit, cfg_, log):
            unit.obj.write_bytes(b"with" if unit.c_flags_add else b"without")

        monkeypatch.setattr(cfan.cpy, "_cc", fake_cc)
        assert cfan.check(cfg, cm.Logger(verbose=False)) == 0

    def test_the_gate_compiles_the_tu_exactly_as_the_build_does(
            self, tmp_path, monkeypatch):
        """It must call compile.py's own _cc, not a hand-rolled invocation.
        Issue 42's sample used `-I include -I src` and no defines, so it
        measured a compile the build never performs."""
        cfg = self._cfg_with_one_unit(tmp_path, monkeypatch)
        seen: list[cm.CompileUnit] = []

        def fake_cc(unit, cfg_, log):
            seen.append(unit)
            unit.obj.write_bytes(b"x" if unit.c_flags_add else b"y")

        monkeypatch.setattr(cfan.cpy, "_cc", fake_cc)
        cfan.check(cfg, cm.Logger(verbose=False))
        assert [u.c_flags_add for u in seen] == [(GCSE,), ()]
        assert all(u.compiler == "cygnus-2.96" for u in seen)
