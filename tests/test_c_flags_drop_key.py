"""The per-TU flag DROP key, ``compile_units[].c_flags_drop``.

Issue 58.  ``c_flags_drop`` removes one flag from the global ``c_flags`` for a
single translation unit.  It shipped years before ``c_flags_add`` and it
shipped with neither of the two guards issue 45 built for the additive key:

  * no CLOSED vocabulary — any string was accepted, so a TU could drop ``-O2``
    and call an unoptimised compile a match;
  * no NECESSITY gate — nothing checked that the TU needed the drop.

The second gap is the one the ELF byte gate cannot cover.  A per-TU key that
is invisible on its own TU keeps
``cmp build/SLUS_215.03.elf disc_extract/SLUS_215.03`` at rc 0 while claiming
something no byte supports.

Inventory (one ``-k`` slice per behaviour):

    Config.compile_units — accepted flag / rejected flag / wrong type /
                           duplicate / add-and-drop collision ordering
    the live config      — every drop in compile_config.json is in the set
    the necessity gate   — inert / load-bearing / one key at a time /
                           the unreachable-flag state
    exit-code classes    — the four non-pass terminal paths (issue 44)
    the control          — the compile is reproducible, so an inert key can
                           actually be detected
"""
from __future__ import annotations

import dataclasses
import json
import sys
from pathlib import Path

import pytest

import compile as cm

sys.path.insert(0, str(cm.ROOT / "scripts" / "checks"))
import c_flags_necessary as cfn  # noqa: E402

REORDER = "-f=-freorder-blocks"
GCSE = "-f=-fno-gcse"


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


def _one_unit_cfg(tmp_path, monkeypatch, **unit_keys) -> cm.Config:
    monkeypatch.setattr(cm, "ROOT", tmp_path)
    (tmp_path / "src/cod").mkdir(parents=True)
    (tmp_path / "src/cod/a.c").write_text("int a;\n")
    entry = {"path": "src/cod/a.c"}
    entry.update(unit_keys)
    return _mkcfg(c_sources_glob=["src/cod/*.c"], compile_units=[entry])


# --------------------------------------------------------------------------- #
# the closed vocabulary
# --------------------------------------------------------------------------- #
class TestVocabulary:

    def test_the_set_holds_exactly_the_reorder_flag_today(self):
        """Widening this set is a map decision. If this test fails, the map
        owes the record an argument for the new member."""
        assert cm.SUPPORTED_C_FLAG_DROPS == frozenset({REORDER})

    def test_the_allowed_flag_is_accepted(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_drop": [REORDER]}])
        assert cfg.compile_units["src/cod/a.c"]["c_flags_drop"] == (REORDER,)

    def test_an_arbitrary_flag_is_rejected(self):
        """The whole point: a TU cannot silently disable optimisation and
        call the result a match."""
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_drop": ["-O2"]}])
        with pytest.raises(cm.BuildError, match="not in the allowed set"):
            cfg.compile_units

    def test_a_bare_string_is_rejected(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_drop": REORDER}])
        with pytest.raises(cm.BuildError, match="must be a list"):
            cfg.compile_units

    def test_a_duplicate_is_rejected(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c", "c_flags_drop": [REORDER, REORDER]}])
        with pytest.raises(cm.BuildError, match="duplicate"):
            cfg.compile_units

    def test_the_add_drop_collision_is_reported_before_the_vocabulary(self):
        """A TU that both adds and drops one flag must name the
        contradiction, not the vocabulary. The checks are ordered for it."""
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/a.c",
             "c_flags_add": [GCSE], "c_flags_drop": [GCSE]}])
        with pytest.raises(cm.BuildError, match="both"):
            cfg.compile_units


class TestLiveConfig:
    """The shipped compile_config.json, not a fixture."""

    @staticmethod
    def _entries() -> list[dict]:
        raw = json.loads((cm.ROOT / "compile_config.json").read_text())
        return [u for u in raw.get("compile_units", [])
                if isinstance(u, dict) and u.get("c_flags_drop")]

    def test_at_least_one_tu_carries_the_key(self):
        """If this fails the necessity gate is vacuous in this tree and its
        pass says nothing."""
        assert self._entries()

    def test_every_live_drop_is_inside_the_vocabulary(self):
        outside = sorted({f for u in self._entries()
                          for f in u["c_flags_drop"]
                          if f not in cm.SUPPORTED_C_FLAG_DROPS})
        assert outside == []

    def test_every_live_drop_names_a_flag_the_global_set_contains(self):
        """An exact-match filter cannot remove a flag that is not there."""
        raw = json.loads((cm.ROOT / "compile_config.json").read_text())
        gflags = set(raw["c_flags"])
        unreachable = sorted({f for u in self._entries()
                              for f in u["c_flags_drop"] if f not in gflags})
        assert unreachable == []


# --------------------------------------------------------------------------- #
# the necessity gate, drop side
# --------------------------------------------------------------------------- #
class TestNecessityGate:

    def test_an_inert_drop_fails(self, tmp_path, monkeypatch, capsys):
        cfg = _one_unit_cfg(tmp_path, monkeypatch, c_flags_drop=[REORDER])
        monkeypatch.setattr(cfn.cpy, "_cc",
                            lambda unit, cfg_, log: unit.obj.write_bytes(b"s"))
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 1
        assert "INERT" in capsys.readouterr().out

    def test_a_load_bearing_drop_passes(self, tmp_path, monkeypatch):
        cfg = _one_unit_cfg(tmp_path, monkeypatch, c_flags_drop=[REORDER])

        def fake_cc(unit, cfg_, log):
            unit.obj.write_bytes(b"with" if unit.c_flags_drop else b"without")

        monkeypatch.setattr(cfn.cpy, "_cc", fake_cc)
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 0

    def test_only_the_named_key_is_neutralised(self, tmp_path, monkeypatch):
        """A TU may carry both keys. Neutralising both at once would test a
        compile the build never performs, exactly the defect issue 45 found
        in an earlier sample."""
        cfg = _one_unit_cfg(tmp_path, monkeypatch,
                            c_flags_drop=[REORDER], c_flags_add=[GCSE])
        seen: list[tuple] = []

        def fake_cc(unit, cfg_, log):
            seen.append((unit.c_flags_drop, unit.c_flags_add))
            unit.obj.write_bytes(str(len(seen)).encode())

        monkeypatch.setattr(cfn.cpy, "_cc", fake_cc)
        cfn.check(cfg, cm.Logger(verbose=False))
        assert seen == [
            ((REORDER,), (GCSE,)),   # drop probe: as the build does
            ((), (GCSE,)),           # drop probe: drop neutralised, add kept
            ((REORDER,), (GCSE,)),   # add probe: as the build does
            ((REORDER,), ()),        # add probe: add neutralised, drop kept
        ]

    def test_a_drop_of_a_flag_that_is_not_in_c_flags_fails(
            self, tmp_path, monkeypatch, capsys):
        """The third state: neither necessary nor inert-but-valid. The filter
        is exact-match, so the key can never fire. compile.py's validator
        rejects it first today; the gate keeps its own diagnosis so the state
        stays visible if the global c_flags ever change."""
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src/cod").mkdir(parents=True)
        (tmp_path / "src/cod/a.c").write_text("int a;\n")
        cfg = _mkcfg(c_sources_glob=["src/cod/*.c"],
                     c_flags=["-O2", "-G0"],
                     compile_units=[{"path": "src/cod/a.c",
                                     "c_flags_drop": [REORDER]}])
        called: list[int] = []
        monkeypatch.setattr(cfn.cpy, "_cc",
                            lambda u, c, l: called.append(1))
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 1
        assert "UNREACHABLE" in capsys.readouterr().out
        assert called == [], "an unreachable key must not be compiled twice"

    def test_the_key_argument_selects_one_direction(self, tmp_path, monkeypatch):
        cfg = _one_unit_cfg(tmp_path, monkeypatch,
                            c_flags_drop=[REORDER], c_flags_add=[GCSE])
        seen: list[str] = []

        def fake_cc(unit, cfg_, log):
            seen.append("x")
            unit.obj.write_bytes(str(len(seen)).encode())

        monkeypatch.setattr(cfn.cpy, "_cc", fake_cc)
        cfn.check(cfg, cm.Logger(verbose=False), keys=("c_flags_drop",))
        assert len(seen) == 2


# --------------------------------------------------------------------------- #
# exit-code classes — issue 44's rule applied to this gate
# --------------------------------------------------------------------------- #
class TestExitCodes:

    def test_no_tu_carries_a_key_is_a_vacuous_pass(self, tmp_path, monkeypatch):
        """The unit set was determined and it is genuinely empty of keys."""
        cfg = _one_unit_cfg(tmp_path, monkeypatch)
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 0

    def test_zero_c_units_is_a_void_verdict(self, tmp_path, monkeypatch):
        """Not a pass. The gate examined nothing and cannot say so with 0."""
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src").mkdir(parents=True)
        cfg = _mkcfg(c_sources_glob=["src/cod/*.c"])
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 2

    def test_an_invalid_config_is_a_void_verdict_not_a_skip(
            self, tmp_path, monkeypatch):
        """Before issue 58 the gate caught every BuildError and returned 77,
        so a config error read as 'toolchain unavailable' — a skip, which
        session_check.sh treats as non-fatal."""
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src/cod").mkdir(parents=True)
        (tmp_path / "src/cod/a.c").write_text("int a;\n")
        cfg = _mkcfg(c_sources_glob=["src/cod/*.c"],
                     compile_units=[{"path": "src/cod/a.c",
                                     "c_flags_drop": ["-O2"]}])
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 2

    def test_an_unreadable_config_is_a_void_verdict(self, tmp_path):
        assert cfn.main(["--config", str(tmp_path / "nope.json")]) == 2

    def test_an_absent_compiler_tree_is_a_skip(self, tmp_path, monkeypatch):
        cfg = _one_unit_cfg(tmp_path, monkeypatch, c_flags_drop=[REORDER])
        monkeypatch.setitem(cfg.raw, "tools",
                            {"ee_dvp_as": "compiler/does/not/exist"})
        called: list[int] = []
        monkeypatch.setattr(cfn.cpy, "_cc", lambda u, c, l: called.append(1))
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 77
        assert called == []

    def test_a_failed_compile_with_the_tree_present_is_a_void_verdict(
            self, tmp_path, monkeypatch):
        """A broken build must not launder itself into a skip."""
        cfg = _one_unit_cfg(tmp_path, monkeypatch, c_flags_drop=[REORDER])

        def boom(unit, cfg_, log):
            raise cm.BuildError("cc1 died")

        monkeypatch.setattr(cfn.cpy, "_cc", boom)
        assert cfn.check(cfg, cm.Logger(verbose=False)) == 2


# --------------------------------------------------------------------------- #
# the control — without it the gate could pass for the wrong reason
# --------------------------------------------------------------------------- #
class TestGateHasPower:

    def test_the_compile_is_reproducible(self):
        """If two identical compiles produced different objects, EVERY TU
        would read as load-bearing and this gate could never fail. That is
        the failure mode the gate itself cannot see, so it is pinned here.

        Falsifier: make ee-cc-wrap.py stamp a timestamp into the object and
        this test goes red while the gate stays green.
        """
        cfg = cm.Config.load(cm.ROOT / "compile_config.json")
        if not cfn.toolchain_present(cfg):
            pytest.skip("the compiler tree is not installed")
        units = [u for u in cm.discover(cfg)
                 if u.kind == "c" and u.c_flags_drop]
        if not units:
            pytest.skip("no TU carries c_flags_drop")
        import hashlib
        import tempfile
        unit = units[0]
        with tempfile.TemporaryDirectory(prefix="cfn-ctl-") as td:
            tdp = Path(td)
            digests = []
            for name in ("a.o", "b.o"):
                u = dataclasses.replace(unit, obj=tdp / name)
                cm._cc(u, cfg, cm.Logger(verbose=False))
                digests.append(hashlib.sha256(u.obj.read_bytes()).hexdigest())
        assert digests[0] == digests[1]
