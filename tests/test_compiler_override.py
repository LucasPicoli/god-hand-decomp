"""Unit tests for the per-TU compiler override.

Scope: cover the pure-Python plumbing that lets ``compile_config.json``
name which cc1 (Cygnus 2.96 default, SN 2.95.3-136 opt-in) gets invoked
for each C TU. The end-to-end ``.o`` byte-equality checks that the
acceptance criteria mention (default = cygnus reproduces today's output;
sn-2.95.3-136 produces ``sq`` saves) live in the integration harness
``scripts/session_check.sh`` + the smoke test inside
``scripts/setup_toolchain.sh § 5b``; here we lock in the *dispatch* so
those integration checks don't silently regress at the Python layer.

Inventory (one ``-k`` slice per behaviour):

    Config.compile_units      — empty / explicit-cygnus / explicit-sn /
                                doc-entry-filtered / unknown-compiler-raises
    CompileUnit.compiler      — default field is cygnus-2.96
    discover() compiler tag   — c units pick up per-TU override; asm/vsm
                                are unaffected
    _cc() argv shape          — --compiler= flag forwarded to ee-cc-wrap
    ee-cc-wrap dispatch       — argparse accepts --compiler; sn dispatch
                                strips the flag and re-execs sn-cc-wrap
"""
from __future__ import annotations

import json
import subprocess
import sys
import textwrap
from pathlib import Path

import pytest

import compile as cm

import importlib.util as _ilu

# ee-cc-wrap.py has a hyphenated filename → load it as a module so the pure
# helpers (e.g. the .s-level C++ frame strip) can be unit-tested directly.
_EECC_SPEC = _ilu.spec_from_file_location(
    "ee_cc_wrap", cm.ROOT / "scripts" / "ee-cc-wrap.py")
eecc = _ilu.module_from_spec(_EECC_SPEC)
_EECC_SPEC.loader.exec_module(eecc)


# --------------------------------------------------------------------------- #
# Tiny test helpers
# --------------------------------------------------------------------------- #
def _mkcfg(**overrides) -> cm.Config:
    """Mirror tests/test_compile.py::_mkcfg — minimal Config + overrides."""
    raw = {
        "tools": {},
        "include_dirs": [],
        "defines": [],
        "c_flags": [],
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
# Config.compile_units
# --------------------------------------------------------------------------- #
class TestConfigCompileUnits:

    def test_empty_list_returns_empty(self):
        assert _mkcfg().compile_units == {}

    def test_missing_key_returns_empty(self):
        """Config without the `compile_units` key behaves like an empty
        list (back-compat for older compile_config.json files).
        """
        cfg = _mkcfg()
        # Force-strip the key the helper inserted.
        cfg.raw.pop("compile_units", None)
        assert cfg.compile_units == {}

    def test_entry_without_compiler_defaults_to_cygnus(self):
        cfg = _mkcfg(compile_units=[{"path": "src/cod/000293.c"}])
        out = cfg.compile_units
        assert set(out.keys()) == {"src/cod/000293.c"}
        assert out["src/cod/000293.c"]["compiler"] == "cygnus-2.96"

    def test_entry_with_explicit_cygnus(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/000293.c", "compiler": "cygnus-2.96"},
        ])
        assert cfg.compile_units["src/cod/000293.c"]["compiler"] == "cygnus-2.96"

    def test_entry_with_explicit_sn(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/02XXXX.c", "compiler": "sn-2.95.3-136"},
        ])
        assert cfg.compile_units["src/cod/02XXXX.c"]["compiler"] == "sn-2.95.3-136"

    def test_doc_entries_filtered_via_underscore_path(self):
        """Documentation entries (path starting with `_`) drop out, the
        same way ``Config.carved_funcs`` filters `_comment` blocks.
        """
        cfg = _mkcfg(compile_units=[
            {"_comment": "doc block"},
            {"path": "_doc", "compiler": "cygnus-2.96"},
            {"path": "src/cod/real.c", "compiler": "sn-2.95.3-136"},
        ])
        assert set(cfg.compile_units.keys()) == {"src/cod/real.c"}

    def test_non_dict_entries_filtered(self):
        cfg = _mkcfg(compile_units=[
            "not a dict",
            {"path": "src/cod/real.c"},
        ])
        assert set(cfg.compile_units.keys()) == {"src/cod/real.c"}

    def test_unknown_compiler_raises_buildereror(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/x.c", "compiler": "mwccps2"},
        ])
        with pytest.raises(cm.BuildError, match="unknown compiler"):
            _ = cfg.compile_units


# --------------------------------------------------------------------------- #
# CompileUnit.compiler default
# --------------------------------------------------------------------------- #
class TestCompileUnitCompilerField:

    def test_default_is_cygnus(self, tmp_path):
        u = cm.CompileUnit(
            src=tmp_path / "x.c",
            obj=tmp_path / "x.o",
            kind="c",
            rel=Path("x.c"),
        )
        assert u.compiler == "cygnus-2.96"

    def test_explicit_sn(self, tmp_path):
        u = cm.CompileUnit(
            src=tmp_path / "x.c",
            obj=tmp_path / "x.o",
            kind="c",
            rel=Path("x.c"),
            compiler="sn-2.95.3-136",
        )
        assert u.compiler == "sn-2.95.3-136"


# --------------------------------------------------------------------------- #
# discover() applies the per-TU override to C units
# --------------------------------------------------------------------------- #
class TestDiscoverCompilerTagging:
    """The override must reach the CompileUnit, not just sit in Config."""

    @staticmethod
    def _setup_tree(tmp_path: Path, monkeypatch) -> None:
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src/cod").mkdir(parents=True)
        (tmp_path / "src/cod/default_tu.c").write_text("")
        (tmp_path / "src/cod/sn_tu.c").write_text("")
        (tmp_path / "asm").mkdir(parents=True)
        (tmp_path / "asm/a.s").write_text("")

    def _mkcfg_with_globs(self, tmp_path: Path, compile_units: list[dict]) -> cm.Config:
        cfg = _mkcfg(
            asm_sources_glob=["asm/**/*.s"],
            c_sources_glob=["src/**/*.c"],
            vsm_sources_glob=[],
            compile_units=compile_units,
        )
        # Config.build_dir reads `build_dir` from raw; ROOT/build is fine
        # since the actual .o paths are never written in this test.
        return cfg

    def test_c_unit_without_override_defaults_to_cygnus(self, tmp_path, monkeypatch):
        self._setup_tree(tmp_path, monkeypatch)
        cfg = self._mkcfg_with_globs(tmp_path, compile_units=[])
        units = cm.discover(cfg, carve=None)
        c_units = {str(u.rel): u for u in units if u.kind == "c"}
        assert c_units["src/cod/default_tu.c"].compiler == "cygnus-2.96"
        assert c_units["src/cod/sn_tu.c"].compiler == "cygnus-2.96"

    def test_c_unit_picks_up_sn_override(self, tmp_path, monkeypatch):
        self._setup_tree(tmp_path, monkeypatch)
        cfg = self._mkcfg_with_globs(tmp_path, compile_units=[
            {"path": "src/cod/sn_tu.c", "compiler": "sn-2.95.3-136"},
        ])
        units = cm.discover(cfg, carve=None)
        c_units = {str(u.rel): u for u in units if u.kind == "c"}
        # The SN-opted-in TU carries the override; the other stays default.
        assert c_units["src/cod/sn_tu.c"].compiler == "sn-2.95.3-136"
        assert c_units["src/cod/default_tu.c"].compiler == "cygnus-2.96"

    def test_asm_units_are_unaffected(self, tmp_path, monkeypatch):
        """The compiler field still has a value on non-C units (the
        dataclass default) but it's never read by ``_assemble`` —
        documenting that here so a future refactor that conditionalises
        on ``kind != 'c'`` doesn't accidentally route asm through a
        cc-wrap.
        """
        self._setup_tree(tmp_path, monkeypatch)
        cfg = self._mkcfg_with_globs(tmp_path, compile_units=[])
        units = cm.discover(cfg, carve=None)
        asm_units = [u for u in units if u.kind == "asm"]
        assert asm_units, "asm fixture missing"
        for u in asm_units:
            assert u.compiler == "cygnus-2.96"  # the dataclass default


# --------------------------------------------------------------------------- #
# _cc() forwards --compiler to ee-cc-wrap.py
# --------------------------------------------------------------------------- #
class TestCcForwardsCompilerFlag:
    """``_cc`` is the seam where the per-TU override turns into a CLI
    flag.  We intercept ``compile.run`` to capture argv without touching
    the real toolchain — the actual compilation behaviour is locked in
    by ``scripts/session_check.sh build`` (the full-build sha256 ratchet)
    and the ``sq`` probe.
    """

    @pytest.fixture
    def captured(self, tmp_path, monkeypatch):
        captured: list[list[str]] = []

        def fake_run(argv, log, stage):
            captured.append(list(argv))

        monkeypatch.setattr(cm, "run", fake_run)
        # No-op the post-cc objcopy probe so we don't shell out.
        monkeypatch.setattr(cm, "_fix_section_flags", lambda u, c, l: None)
        return captured

    def _mkconfig_for_cc(self, tmp_path: Path) -> cm.Config:
        return cm.Config(raw={
            "tools": {
                "ee_cc_wrap": "scripts/ee-cc-wrap.py",
                "sn_cc_wrap": "scripts/sn-cc-wrap.py",
            },
            "include_dirs": [],
            "defines": [],
            "c_flags": ["-O2", "-G0"],
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
        })

    def test_default_unit_forwards_cygnus_flag(self, tmp_path, captured):
        cfg = self._mkconfig_for_cc(tmp_path)
        unit = cm.CompileUnit(
            src=tmp_path / "x.c", obj=tmp_path / "x.o",
            kind="c", rel=Path("x.c"),
        )
        cm._cc(unit, cfg, cm.Logger(verbose=False))
        assert len(captured) == 1
        argv = captured[0]
        assert "--compiler=cygnus-2.96" in argv

    def test_sn_unit_forwards_sn_flag(self, tmp_path, captured):
        cfg = self._mkconfig_for_cc(tmp_path)
        unit = cm.CompileUnit(
            src=tmp_path / "x.c", obj=tmp_path / "x.o",
            kind="c", rel=Path("x.c"),
            compiler="sn-2.95.3-136",
        )
        cm._cc(unit, cfg, cm.Logger(verbose=False))
        argv = captured[0]
        assert "--compiler=sn-2.95.3-136" in argv
        # The flag must land before the positional input + -o pair so
        # ee-cc-wrap.py's argparse sees it before any source.
        assert argv.index("--compiler=sn-2.95.3-136") < argv.index(str(unit.src))


# --------------------------------------------------------------------------- #
# ee-cc-wrap.py argparse + SN dispatch shape
# --------------------------------------------------------------------------- #
class TestEeCcWrapDispatch:
    """End-to-end smoke of the wrapper's CLI surface.  We exercise the
    argparse plumbing + the SN dispatch's argument-forwarding rules; we
    do NOT exercise the actual compile (that needs binaries).
    """

    EE_WRAP = cm.ROOT / "scripts" / "ee-cc-wrap.py"

    def test_help_lists_compiler_choices(self):
        result = subprocess.run(
            [sys.executable, str(self.EE_WRAP), "--help"],
            capture_output=True, text=True, check=True,
        )
        assert "--compiler" in result.stdout
        assert "cygnus-2.96" in result.stdout
        assert "sn-2.95.3-136" in result.stdout

    def test_unknown_compiler_value_rejected(self, tmp_path):
        (tmp_path / "x.c").write_text("")
        result = subprocess.run(
            [sys.executable, str(self.EE_WRAP),
             "--compiler=mwccps2", "-c", str(tmp_path / "x.c")],
            capture_output=True, text=True, check=False,
        )
        assert result.returncode != 0
        assert "mwccps2" in (result.stdout + result.stderr)

    def test_sn_dispatch_forwards_to_sn_wrap(self, tmp_path, monkeypatch):
        """When --compiler=sn-2.95.3-136, ee-cc-wrap.py re-execs
        scripts/sn-cc-wrap.py with the --compiler flag stripped.  We
        verify that by pointing the wrapper at a stub sn-cc-wrap.py
        that records argv to a file.
        """
        # Build a fake ROOT layout: scripts/ee-cc-wrap.py is the real
        # script (copied so its ``Path(__file__).resolve().parent.parent``
        # ROOT lookup lands inside tmp_path), scripts/sn-cc-wrap.py is
        # a stub that dumps argv.  Symlinks don't work here because
        # Path.resolve() follows them back to the real repo.
        import shutil
        scripts_dir = tmp_path / "scripts"
        scripts_dir.mkdir()
        shutil.copy2(self.EE_WRAP, scripts_dir / "ee-cc-wrap.py")
        capture = tmp_path / "argv.json"
        stub = scripts_dir / "sn-cc-wrap.py"
        stub.write_text(textwrap.dedent(f"""\
            #!{sys.executable}
            import json, sys
            from pathlib import Path
            Path({str(capture)!r}).write_text(json.dumps(sys.argv[1:]))
            sys.exit(0)
        """))
        stub.chmod(0o755)
        (tmp_path / "src.c").write_text("")

        result = subprocess.run(
            [sys.executable, str(scripts_dir / "ee-cc-wrap.py"),
             "--compiler=sn-2.95.3-136",
             "-c", "-x", "c", "-O2", "-G0",
             "-Iinclude", "-Dsomething=1",
             str(tmp_path / "src.c"),
             "-o", str(tmp_path / "src.o")],
            capture_output=True, text=True, check=False,
        )
        assert result.returncode == 0, result.stderr
        forwarded = json.loads(capture.read_text())
        # --compiler must be stripped before forwarding so sn-cc-wrap.py
        # (which doesn't know that flag) doesn't argparse-fail.
        assert "--compiler=sn-2.95.3-136" not in forwarded
        assert "--compiler" not in forwarded
        # All the other flags survive the dispatch.
        for expected in ("-c", "-x", "c", "-O2", "-G0", "-Iinclude",
                         "-Dsomething=1", "-o"):
            assert expected in forwarded, f"missing {expected!r} in {forwarded}"
        assert str(tmp_path / "src.c") in forwarded
        assert str(tmp_path / "src.o") in forwarded

    def test_sn_dispatch_strips_space_separated_compiler_flag(self, tmp_path):
        """Same as above but using the ``--compiler X`` form instead of
        ``--compiler=X`` — argparse accepts both; the dispatch's strip
        loop has to handle both."""
        import shutil
        scripts_dir = tmp_path / "scripts"
        scripts_dir.mkdir()
        shutil.copy2(self.EE_WRAP, scripts_dir / "ee-cc-wrap.py")
        capture = tmp_path / "argv.json"
        stub = scripts_dir / "sn-cc-wrap.py"
        stub.write_text(textwrap.dedent(f"""\
            #!{sys.executable}
            import json, sys
            from pathlib import Path
            Path({str(capture)!r}).write_text(json.dumps(sys.argv[1:]))
            sys.exit(0)
        """))
        stub.chmod(0o755)
        (tmp_path / "src.c").write_text("")

        result = subprocess.run(
            [sys.executable, str(scripts_dir / "ee-cc-wrap.py"),
             "--compiler", "sn-2.95.3-136",
             "-c", str(tmp_path / "src.c"),
             "-o", str(tmp_path / "src.o")],
            capture_output=True, text=True, check=False,
        )
        assert result.returncode == 0, result.stderr
        forwarded = json.loads(capture.read_text())
        assert "--compiler" not in forwarded
        assert "sn-2.95.3-136" not in forwarded


# --------------------------------------------------------------------------- #
# Per-TU c_flags_drop
# --------------------------------------------------------------------------- #
class TestCompileUnitsCFlagsDrop:
    """The c_flags_drop entry-field surfaces on the CompileUnit and gets
    applied as an exact-match filter against cfg.c_flags inside _cc()."""

    def test_default_empty_in_config(self):
        cfg = _mkcfg(compile_units=[{"path": "src/cod/x.c"}])
        assert cfg.compile_units["src/cod/x.c"]["c_flags_drop"] == ()

    def test_explicit_list_round_trips_as_tuple(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/x.c",
             "c_flags_drop": ["-f=-freorder-blocks", "-O2"]},
        ])
        assert cfg.compile_units["src/cod/x.c"]["c_flags_drop"] == (
            "-f=-freorder-blocks", "-O2",
        )

    def test_invalid_drop_type_raises(self):
        cfg = _mkcfg(compile_units=[
            {"path": "src/cod/x.c", "c_flags_drop": "-not-a-list"},
        ])
        with pytest.raises(cm.BuildError, match="c_flags_drop"):
            _ = cfg.compile_units

    def test_compileunit_default_is_empty_tuple(self, tmp_path):
        u = cm.CompileUnit(
            src=tmp_path / "x.c", obj=tmp_path / "x.o",
            kind="c", rel=Path("x.c"),
        )
        assert u.c_flags_drop == ()

    def test_discover_threads_c_flags_drop(self, tmp_path, monkeypatch):
        monkeypatch.setattr(cm, "ROOT", tmp_path)
        (tmp_path / "src/cod").mkdir(parents=True)
        (tmp_path / "src/cod/special.c").write_text("")
        (tmp_path / "src/cod/normal.c").write_text("")
        (tmp_path / "asm").mkdir(parents=True)
        cfg = _mkcfg(
            asm_sources_glob=[],
            c_sources_glob=["src/**/*.c"],
            vsm_sources_glob=[],
            compile_units=[
                {"path": "src/cod/special.c",
                 "c_flags_drop": ["-f=-freorder-blocks"]},
            ],
        )
        units = {str(u.rel): u for u in cm.discover(cfg, carve=None)
                 if u.kind == "c"}
        assert units["src/cod/special.c"].c_flags_drop == (
            "-f=-freorder-blocks",
        )
        assert units["src/cod/normal.c"].c_flags_drop == ()

    def test_cc_filters_dropped_flag_from_argv(self, tmp_path, monkeypatch):
        captured: list[list[str]] = []
        monkeypatch.setattr(cm, "run",
                            lambda argv, log, stage: captured.append(list(argv)))
        monkeypatch.setattr(cm, "_fix_section_flags", lambda u, c, l: None)
        cfg = cm.Config(raw={
            "tools": {
                "ee_cc_wrap": "scripts/ee-cc-wrap.py",
                "sn_cc_wrap": "scripts/sn-cc-wrap.py",
            },
            "include_dirs": [],
            "defines": [],
            "c_flags": ["-O2", "-G0", "-f=-freorder-blocks"],
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
        })
        unit_default = cm.CompileUnit(
            src=tmp_path / "n.c", obj=tmp_path / "n.o",
            kind="c", rel=Path("n.c"),
        )
        unit_dropped = cm.CompileUnit(
            src=tmp_path / "s.c", obj=tmp_path / "s.o",
            kind="c", rel=Path("s.c"),
            c_flags_drop=("-f=-freorder-blocks",),
        )
        cm._cc(unit_default, cfg, cm.Logger(verbose=False))
        cm._cc(unit_dropped, cfg, cm.Logger(verbose=False))
        assert "-f=-freorder-blocks" in captured[0]   # default TU keeps it
        assert "-f=-freorder-blocks" not in captured[1]  # dropped TU strips it
        # Other flags pass through unchanged.
        for flag in ("-O2", "-G0"):
            assert flag in captured[0]
            assert flag in captured[1]


# --------------------------------------------------------------------------- #
# Surgical C++ DWARF-frame strip (.s-level, not whole .data)
# --------------------------------------------------------------------------- #
# ee-gcc 2.9 cc1plus emits an unconditional per-TU DWARF frame block as the
# LAST thing in the .s: its own `.data` re-entry + `.align` + `.globl
# _GLOBAL_$F$<sym>` + the `_GLOBAL_$F$<sym>:`/`__FRAME_BEGIN__:` labels + the
# CIE/FDE bytes, terminated by `.4byte 0x0` / `.align 0`.  --strip-cxx-frame
# must remove ONLY that block, preserving any real program `.data` emitted
# earlier (initialized globals, vtables, typeinfo, string literals).  The old
# implementation removed the whole `.data` section, which would silently wipe
# real program data the moment a multi-function C++ TU is added.

# Real cc1plus layout for a 2-function TU with an initialized global:
# program `.data` (g_value) first, then `.text`, then the frame block last.
_PROGRAM_PART = "\n".join([
    '\t.file\t1 "multi.i"',
    'gcc2_compiled.:',
    '__gnu_compiled_cplusplus:',
    '\t.globl\tg_value',
    '\t.data',
    '\t.align\t2',
    '\t.type\t g_value,@object',
    '\t.size\t g_value,4',
    'g_value:',
    '\t.word\t305419896',
    '\t.text',
    '\t.p2align 3',
    '\t.globl\tfoo',
    '$LFB1:',
    '\t.ent\tfoo',
    'foo:',
    '\tj\t$31',
    '\t.end\tfoo',
    '$LFE1:',
    '\t.p2align 3',
    '\t.globl\tbar',
    '$LFB2:',
    '\t.ent\tbar',
    'bar:',
    '\tj\t$31',
    '\t.end\tbar',
    '$LFE2:',
])
_FRAME_PART = "\n".join([
    '\t.data',
    '\t.align\t2',
    '\t.globl\t_GLOBAL_$F$g_value',
    '_GLOBAL_$F$g_value:',
    '__FRAME_BEGIN__:',
    '\t.4byte\t$LECIE1-$LSCIE1',
    '$LSCIE1:',
    '\t.4byte\t0x0',
    '\t.align\t2',
    '$LECIE1:',
    '\t.4byte\t$LEFDE1-$LSFDE1',
    '$LSFDE1:',
    '\t.4byte\t$LSFDE1-__FRAME_BEGIN__',
    '\t.4byte\t$LFB1',
    '\t.align\t2',
    '$LEFDE1:',
    '\t.4byte\t0x0',
    '\t.align\t0',
])
_MULTI_FN_S = _PROGRAM_PART + "\n" + _FRAME_PART + "\n"

# Single-function frame-only TU (the real __dynamic_cast shape): the frame
# block IS the entire `.data` — there is no real program data to preserve.
_SINGLE_FN_S = "\n".join([
    '\t.section .text.__dynamic_cast,"ax",@progbits',
    '\t.globl\t__dynamic_cast',
    '$LFB1:',
    '__dynamic_cast:',
    '\tj\t$31',
    '\t.end\t__dynamic_cast',
    '$LFE1:',
    '',
    '\t.data',
    '\t.align\t2',
    '\t.globl\t_GLOBAL_$F$__dynamic_cast',
    '_GLOBAL_$F$__dynamic_cast:',
    '__FRAME_BEGIN__:',
    '\t.4byte\t$LECIE1-$LSCIE1',
    '$LSCIE1:',
    '\t.4byte\t0x0',
    '\t.align\t0',
]) + "\n"


class TestStripCxxFrameBlock:
    """The pure .s-level frame strip removes ONLY the DWARF frame block,
    preserving real program `.data`."""

    def test_multi_fn_preserves_program_data_exactly(self):
        out = eecc._strip_cxx_frame_block(_MULTI_FN_S)
        # The frame block (and only the frame block) is cut, byte-exact.
        assert out == _PROGRAM_PART + "\n"

    def test_multi_fn_real_global_survives(self):
        out = eecc._strip_cxx_frame_block(_MULTI_FN_S)
        assert "g_value:" in out
        assert "305419896" in out          # the initialized .word value
        assert "\t.globl\tg_value" in out

    def test_multi_fn_frame_block_removed(self):
        out = eecc._strip_cxx_frame_block(_MULTI_FN_S)
        assert "__FRAME_BEGIN__" not in out
        assert "_GLOBAL_$F$" not in out
        # Exactly one `.data` directive remains (the program one); the frame's
        # `.data` re-entry is gone.
        assert out.count("\t.data") == 1

    def test_multi_fn_text_survives(self):
        out = eecc._strip_cxx_frame_block(_MULTI_FN_S)
        assert "foo:" in out
        assert "bar:" in out

    def test_single_fn_frame_removed(self):
        out = eecc._strip_cxx_frame_block(_SINGLE_FN_S)
        assert "__FRAME_BEGIN__" not in out
        assert "_GLOBAL_$F$" not in out
        # The function text is untouched.
        assert "__dynamic_cast:" in out
        assert ".text.__dynamic_cast" in out
        # All `.data` is gone (the frame WAS the entire .data section).
        assert ".data" not in out

    def test_idempotent(self):
        once = eecc._strip_cxx_frame_block(_MULTI_FN_S)
        twice = eecc._strip_cxx_frame_block(once)
        assert twice == once

    def test_no_frame_is_noop(self):
        plain = "\n".join([
            '\t.text',
            '\t.globl\tmain',
            'main:',
            '\tj\t$31',
            '\t.data',
            'k:',
            '\t.word\t7',
        ]) + "\n"
        assert eecc._strip_cxx_frame_block(plain) == plain
