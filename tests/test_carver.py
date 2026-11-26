"""Phase-1 smoke tests for `scripts/carver.py`.

These cover the schema-half public surface (`CarveSchema.parse_entries`,
`CarveSchema.split_monolithic`, `CarveSchema.carve_unit_size_bytes`)
plus the `CarveEntry` / `CarveState` / `BuildError` re-exports.

Phase 2 will add `CarveSession` tests (snapshot/revert/atomic). The
existing carve-flow tests in `tests/test_compile.py` continue to
exercise `compile.py`'s call sites via the re-export shim and are NOT
duplicated here — these are smoke tests for the new module's public
surface in isolation.

A behaviour-preserving refactor.
"""
from __future__ import annotations

import dataclasses
import sys
from pathlib import Path

import pytest

# Make the project root importable so `import compile as cm` works for
# the re-export consistency checks below.
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from scripts.carver import (
    BuildError,
    CarveEntry,
    CarveError,
    CarveSchema,
    CarveSession,
    CarveSnapshot,
    CarveState,
    _AutoCarveSnapshot,
)


# --------------------------------------------------------------------------- #
# Re-export consistency with compile.py
# --------------------------------------------------------------------------- #


class TestReexportConsistency:
    """`compile.py` re-exports these symbols from `scripts.carver`;
    consumers of `cm.X` should see literally the same objects as
    consumers of `scripts.carver.X`.

    Phase-1 contract: every moved symbol is identity-equal across both
    import paths. Phase 3 drops the re-export shim and these checks
    become no-ops or get retargeted.
    """

    def test_build_error_identity(self):
        import compile as cm
        assert cm.BuildError is BuildError

    def test_carve_entry_identity(self):
        import compile as cm
        assert cm.CarveEntry is CarveEntry

    def test_carve_state_identity(self):
        import compile as cm
        assert cm.CarveState is CarveState

    def test_carve_schema_identity(self):
        import compile as cm
        assert cm.CarveSchema is CarveSchema

    def test_private_helpers_identity(self):
        """The private helpers (`_split_monolithic` etc.) survive the
        re-export so existing compile.py call sites still find them in
        their own namespace. Phase 3 removes this dependency.
        """
        import compile as cm
        from scripts.carver import (
            _carve_unit_size_bytes,
            _eeas_compat_registers,
            _index_functions,
            _parse_carved_entries,
            _preamble_end_index,
            _split_monolithic,
        )
        assert cm._carve_unit_size_bytes is _carve_unit_size_bytes
        assert cm._eeas_compat_registers is _eeas_compat_registers
        assert cm._index_functions is _index_functions
        assert cm._parse_carved_entries is _parse_carved_entries
        assert cm._preamble_end_index is _preamble_end_index
        assert cm._split_monolithic is _split_monolithic


# --------------------------------------------------------------------------- #
# CarveEntry / CarveState shape
# --------------------------------------------------------------------------- #


class TestCarveEntry:

    def test_minimal_entry_is_frozen(self):
        e = CarveEntry(
            name="func_00100000",
            unit="asm/cod/000000",
            vaddr=0x00100000,
            size=8,
        )
        assert e.name == "func_00100000"
        assert e.tu is None  # default for asm-only carves
        with pytest.raises(dataclasses.FrozenInstanceError):
            e.name = "other"  # frozen contract

    def test_entry_with_tu(self):
        e = CarveEntry(
            name="func_00100000",
            unit="asm/cod/000000",
            vaddr=0x00100000,
            size=8,
            tu="src/cod/000000.c",
        )
        assert e.tu == "src/cod/000000.c"


class TestCarveStateInvariants:

    def _entry(self, name: str, tu: str | None = None) -> CarveEntry:
        return CarveEntry(
            name=name, unit="asm/cod/000000",
            vaddr=0x00100000, size=8, tu=tu,
        )

    def _state(self, entries: list[CarveEntry]) -> CarveState:
        carve_dir = ROOT / "build" / "asm" / "nonmatching"
        return CarveState(
            original_unit_src=ROOT / "asm/cod/000000.s",
            original_unit_rel=Path("asm/cod/000000.s"),
            fragment_sources=[ROOT / "build/asm/cod/000000.part0.s"],
            carved_sources={e.name: carve_dir / f"{e.name}.s" for e in entries},
            entries=entries,
            lcf=ROOT / "build/SLUS_215.03.lcf",
        )

    def test_entry_by_name_hit(self):
        e1 = self._entry("func_001")
        e2 = self._entry("func_002")
        s = self._state([e1, e2])
        assert s.entry_by_name("func_001") is e1
        assert s.entry_by_name("func_002") is e2

    def test_entry_by_name_miss_raises_build_error(self):
        s = self._state([self._entry("func_001")])
        with pytest.raises(BuildError, match="no entry for 'absent'"):
            s.entry_by_name("absent")

    def test_is_tu_owned(self):
        e_asm = self._entry("func_001", tu=None)
        e_c = self._entry("func_002", tu="src/cod/000000.c")
        s = self._state([e_asm, e_c])
        assert s.is_tu_owned("func_001") is False
        assert s.is_tu_owned("func_002") is True

    def test_carve_link_obj_rel_asm_only(self):
        e = self._entry("func_001", tu=None)
        s = self._state([e])
        # asm-only carve: link slot is build/asm/nonmatching/<name>.o
        assert s.carve_link_obj_rel("func_001") == "build/asm/nonmatching/func_001.o"

    def test_carve_link_obj_rel_tu_owned(self):
        e = self._entry("func_001", tu="src/cod/000000.c")
        s = self._state([e])
        # TU-owned carve: link slot is the TU's .o
        assert s.carve_link_obj_rel("func_001") == "build/src/cod/000000.o"


# --------------------------------------------------------------------------- #
# CarveSchema.parse_entries
# --------------------------------------------------------------------------- #


class _StubConfig:
    """Duck-typed `compile.Config` stand-in (`.carved_funcs` attribute)."""

    def __init__(self, carved_funcs: list[dict]):
        self.carved_funcs = carved_funcs


class TestParseEntries:

    def test_empty(self):
        assert CarveSchema.parse_entries(_StubConfig([])) == []

    def test_one_entry_str_hex_vaddr(self):
        cfg = _StubConfig([
            {"name": "func_00100000", "unit": "asm/cod/000000",
             "vaddr": "0x00100000", "size": 8},
        ])
        out = CarveSchema.parse_entries(cfg)
        assert len(out) == 1
        assert out[0] == CarveEntry(
            name="func_00100000",
            unit="asm/cod/000000",
            vaddr=0x00100000,
            size=8,
            tu=None,
        )

    def test_one_entry_int_vaddr(self):
        cfg = _StubConfig([
            {"name": "func_00100000", "unit": "asm/cod/000000",
             "vaddr": 0x00100000, "size": 8, "tu": "src/cod/000000.c"},
        ])
        out = CarveSchema.parse_entries(cfg)
        assert out[0].vaddr == 0x00100000
        assert out[0].tu == "src/cod/000000.c"

    def test_skips_comment_only_entries(self):
        """Documentation-only entries (no `name` key) are skipped."""
        cfg = _StubConfig([
            {"_comment": "permanent: jump-table-referenced"},
            {"name": "func_00100000", "unit": "asm/cod/000000",
             "vaddr": "0x00100000", "size": 8},
        ])
        out = CarveSchema.parse_entries(cfg)
        assert len(out) == 1
        assert out[0].name == "func_00100000"

    def test_parse_carved_entries_lib_flag(self):
        """The optional `lib` flag marks library/middleware/CRT carves."""
        cfg = _StubConfig([
            {"name": "func_00000001", "unit": "asm/cod/000000",
             "vaddr": "0x1", "size": 4},
            {"name": "func_00000002", "unit": "asm/cod/000000",
             "vaddr": "0x2", "size": 4, "lib": True},
        ])
        entries = CarveSchema.parse_entries(cfg)
        assert entries[0].lib is False          # default when key absent
        assert entries[1].lib is True
        assert entries[1].name == "func_00000002"


# --------------------------------------------------------------------------- #
# CarveSchema.split_monolithic + carve_unit_size_bytes
# --------------------------------------------------------------------------- #


# Minimal monolithic .s shape: preamble + two functions, each with the
# splat-disassembled instruction-line format the regexes expect.
_MIN_MONO = """\
.set noat
.set noreorder
.include "macro.inc"

.section .text, "ax"
.align 3
nonmatching func_00100000, 8
glabel func_00100000
    /* 0 100000 03e00008 */ jr      $ra
    /* 4 100004 00000000 */ nop
endlabel func_00100000

.align 3
nonmatching func_00100008, 12
glabel func_00100008
    /* 8 100008 24020001 */ addiu   $v0, $zero, 1
    /* C 10000C 03e00008 */ jr      $ra
    /* 10 100010 00000000 */ nop
endlabel func_00100008
"""


class TestSplitMonolithicSmoke:

    def test_split_returns_correct_counts(self):
        fragments, carved, ranges = CarveSchema.split_monolithic(
            _MIN_MONO, ["func_00100000", "func_00100008"]
        )
        # N carves → N+1 fragments
        assert len(fragments) == 3
        assert set(carved.keys()) == {"func_00100000", "func_00100008"}
        # ranges are in source order
        assert [r[0] for r in ranges] == ["func_00100000", "func_00100008"]

    def test_split_one_only(self):
        fragments, carved, ranges = CarveSchema.split_monolithic(
            _MIN_MONO, ["func_00100008"]
        )
        assert len(fragments) == 2
        assert list(carved.keys()) == ["func_00100008"]

    def test_dlabel_block_bounds_previous_carve(self):
        """Data splat put in .text after a function stays out of its carve."""
        mono = _MIN_MONO.replace("""
.align 3
nonmatching func_00100008, 12""", """
.align 3
nonmatching D_00100008

dlabel D_00100008
    /* 8 100008 00000001 */ .word 0x00000001
enddlabel D_00100008

.align 3
nonmatching func_00100008, 12""")
        fragments, carved, _ = CarveSchema.split_monolithic(mono, ["func_00100000"])
        assert "D_00100008" not in carved["func_00100000"]
        assert "dlabel D_00100008" in fragments[1]

    def test_split_missing_function_raises(self):
        with pytest.raises(BuildError, match="not present in monolithic"):
            CarveSchema.split_monolithic(_MIN_MONO, ["func_DEADBEEF"])

    def test_carved_text_rewrites_section(self):
        """Per-carve .s should land in `.section .text.<NAME>`."""
        _, carved, _ = CarveSchema.split_monolithic(
            _MIN_MONO, ["func_00100000"]
        )
        ct = carved["func_00100000"]
        assert '.section .text.func_00100000, "ax"' in ct
        # macro.inc swapped to labels.inc for ee-as compat
        assert '.include "labels.inc"' in ct

    def test_carved_text_eeas_register_rewrite(self):
        """Symbolic GPRs ($ra, $zero, $v0) get rewritten to numeric."""
        _, carved, _ = CarveSchema.split_monolithic(
            _MIN_MONO, ["func_00100008"]
        )
        ct = carved["func_00100008"]
        assert "$31" in ct        # $ra
        assert "$0" in ct         # $zero
        assert "$2" in ct         # $v0
        assert "$ra" not in ct    # rewritten
        assert "$zero" not in ct  # rewritten


class TestCarveUnitSizeBytes:

    def test_empty_text_is_zero(self):
        assert CarveSchema.carve_unit_size_bytes("") == 0

    def test_directives_only_is_zero(self):
        text = ".align 3\nglabel func_X\nendlabel func_X\n"
        assert CarveSchema.carve_unit_size_bytes(text) == 0

    def test_two_insn_is_eight_bytes(self):
        text = (
            "    /* 0 100000 03e00008 */ jr      $ra\n"
            "    /* 4 100004 00000000 */ nop\n"
        )
        assert CarveSchema.carve_unit_size_bytes(text) == 8

    def test_three_insn_is_twelve_bytes(self):
        text = (
            "    /* 0 100000 24020001 */ addiu   $v0, $zero, 1\n"
            "    /* 4 100004 03e00008 */ jr      $ra\n"
            "    /* 8 100008 00000000 */ nop\n"
        )
        assert CarveSchema.carve_unit_size_bytes(text) == 12


# --------------------------------------------------------------------------- #
# Phase 2 — Session half (mutation + atomic rollback)
# --------------------------------------------------------------------------- #


class TestPhase2Reexports:
    """Re-export back-compat alias.

    Checks the live back-compat alias on the carve snapshot type, so the
    legacy name keeps resolving to the current one.
    """

    def test_carve_snapshot_back_compat_alias(self):
        assert _AutoCarveSnapshot is CarveSnapshot


class TestCarveSessionShape:
    """`CarveSession` is a thin facade over the carve primitives
    (behaviour-preserving; no internal atomic wrap; the caller handles
    rollback). These smoke tests cover the facade's shape; the
    underlying primitives `_auto_carve_uncarved` / `_atomic_auto_carve`
    are exercised elsewhere.
    """

    def test_session_default_root_is_module_root(self):
        from scripts.carver import ROOT as CARVER_ROOT
        s = CarveSession()
        assert s.root == CARVER_ROOT

    def test_session_custom_root(self, tmp_path: Path):
        s = CarveSession(root=tmp_path)
        assert s.root == tmp_path

    def test_session_has_expected_public_methods(self):
        s = CarveSession()
        assert callable(s.carve_one)
        assert callable(s.snapshot)
        assert callable(s.revert)
        assert callable(s.atomic)

    def test_carve_error_can_be_raised_and_caught(self):
        with pytest.raises(CarveError, match="smoke test"):
            raise CarveError("smoke test")


class TestCarveSessionAtomicSmoke:
    """Lightweight smoke for `CarveSession.atomic` against a controlled
    `compile_config.json` + TU under tmp_path. Verifies (a) the
    pre-state is restored on exception, (b) the wrapped block sees the
    carve applied, (c) no exception leaves the carve in place.
    """

    def _setup_minimal_tree(self, tmp_path: Path) -> tuple[Path, Path]:
        """Create a minimal compile_config.json + TU + asm/cod/000000.s
        under tmp_path so `_auto_carve_uncarved` can run end-to-end
        without writing to the real project tree.
        """
        # compile_config.json with empty carved_funcs[]
        cfg = tmp_path / "compile_config.json"
        import json
        cfg.write_text(json.dumps({"carved_funcs": []}, indent=2) + "\n")
        # src/cod/000000.c (TU)
        tu_dir = tmp_path / "src" / "cod"
        tu_dir.mkdir(parents=True)
        tu = tu_dir / "000000.c"
        tu.write_text("/* TU pre-carve */\n")
        # asm/cod/000000.s with a tiny `nonmatching func_smoke, 0x8` entry.
        # The size lookup falls back to declared_size if the directive
        # isn't found; we don't strictly need it for this smoke.
        asm_dir = tmp_path / "asm" / "cod"
        asm_dir.mkdir(parents=True)
        (asm_dir / "000000.s").write_text(
            "nonmatching func_smoke, 0x8\nglabel func_smoke\n    nop\n    nop\nendlabel func_smoke\n"
        )
        return cfg, tu

    def test_atomic_carve_applies_on_clean_exit(self, tmp_path: Path):
        cfg, tu = self._setup_minimal_tree(tmp_path)
        s = CarveSession(root=tmp_path)
        candidate = {
            "address": "0x00100000",
            "size_bytes": 8,
            "asm_module_path": "asm/cod/000000.s",
        }
        with s.atomic("func_smoke", candidate, config_path=cfg):
            # Wrapped block sees the carve already applied:
            assert "func_smoke" in cfg.read_text()
            assert "INCLUDE_ASM" in tu.read_text()
        # Clean exit: carve stays applied.
        assert "func_smoke" in cfg.read_text()
        assert "INCLUDE_ASM" in tu.read_text()

    def test_atomic_carve_reverts_on_exception(self, tmp_path: Path):
        cfg, tu = self._setup_minimal_tree(tmp_path)
        cfg_pre = cfg.read_text()
        tu_pre = tu.read_text()
        s = CarveSession(root=tmp_path)
        candidate = {
            "address": "0x00100000",
            "size_bytes": 8,
            "asm_module_path": "asm/cod/000000.s",
        }
        with pytest.raises(RuntimeError, match="downstream failed"):
            with s.atomic("func_smoke", candidate, config_path=cfg):
                # Wrapped block sees carve applied, then raises:
                assert "func_smoke" in cfg.read_text()
                raise RuntimeError("downstream failed")
        # Reverted:
        assert cfg.read_text() == cfg_pre
        assert tu.read_text() == tu_pre

    def test_carve_one_idempotent(self, tmp_path: Path):
        cfg, tu = self._setup_minimal_tree(tmp_path)
        s = CarveSession(root=tmp_path)
        candidate = {
            "address": "0x00100000",
            "size_bytes": 8,
            "asm_module_path": "asm/cod/000000.s",
        }
        result1 = s.carve_one("func_smoke", candidate, config_path=cfg)
        result2 = s.carve_one("func_smoke", candidate, config_path=cfg)
        assert result1 == "carved"
        assert result2 == "already_carved"

    def test_auto_carve_func_script_invocation_resolves_imports(
        self, tmp_path: Path
    ):
        """Regression test: when ``auto_carve_func.py`` is invoked as
        ``python3 scripts/auto_carve_func.py NAME``, Python
        auto-prepends only the script's own directory (``scripts/``) to
        ``sys.path``.  The carver extraction changed the in-script import
        to ``from scripts.carver import ...``, which requires the
        **repo root** (parent of ``scripts/``) on ``sys.path``.  Pytest
        doesn't exercise this invocation path (it uses ``-m`` /
        ``pytest`` runner hooks), so this is the only thing that catches a
        ``ModuleNotFoundError: scripts`` regression.  This test invokes
        ``auto_carve_func.py`` that way and asserts the import resolves.

        Invoked with a bogus function name so the script short-circuits
        before any real carve mutation; we just exercise the import path.
        """
        import subprocess

        # Use the actual repo root + auto_carve_func.py path.
        repo_root = ROOT
        script = repo_root / "scripts" / "auto_carve_func.py"
        assert script.is_file(), f"{script} missing"

        # Run from repo root with a relative script path. Pass a name
        # that doesn't exist in the target metadata so the script exits
        # early with rc=2 ("no candidate metadata") rather than
        # attempting a real carve.
        cp = subprocess.run(
            [sys.executable, "scripts/auto_carve_func.py",
             "func_TEST_DOES_NOT_EXIST_AUTO_CARVE_REGRESSION"],
            cwd=str(repo_root),
            capture_output=True,
            text=True,
            check=False,
        )
        # The script should NOT fail with a `ModuleNotFoundError` /
        # "failed to import scripts.carver" message.
        combined = cp.stdout + cp.stderr
        assert "failed to import scripts.carver" not in combined, (
            f"auto_carve_func.py regressed on `from scripts.carver` "
            f"import resolution. Output:\n{combined}"
        )
        assert "No module named 'scripts'" not in combined, (
            f"auto_carve_func.py couldn't find the `scripts` package. "
            f"Output:\n{combined}"
        )
        # The expected exit code for a non-existent candidate is 2;
        # rc=3 would mean the import-failure path fired.
        assert cp.returncode == 2, (
            f"Expected rc=2 (no candidate metadata) but got"
            f" rc={cp.returncode}. Output:\n{combined}"
        )

    def test_carve_one_raises_carve_error_on_missing_tu(self, tmp_path: Path):
        """If the TU file doesn't exist, `carve_one` raises `CarveError`
        (the carver module owns its own error class).
        """
        cfg = tmp_path / "compile_config.json"
        import json
        cfg.write_text(json.dumps({"carved_funcs": []}, indent=2) + "\n")
        # Note: NO `src/cod/000000.c` created.
        s = CarveSession(root=tmp_path)
        candidate = {
            "address": "0x00100000",
            "size_bytes": 8,
            "asm_module_path": "asm/cod/000000.s",
        }
        with pytest.raises(CarveError, match="TU file not found"):
            s.carve_one("func_smoke", candidate, config_path=cfg)
