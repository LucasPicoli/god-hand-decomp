"""Unit tests for ``scripts/gen_unit_names.py`` — the objdiff/decomp.dev
display-name remap generator.

The generator turns address-keyed objdiff unit names
(``asm/cod/000000.part17``, ``src/cod/001004c8``) into subsystem-foldered
display names (``enemy/IsTargetVisibleOrForced``) so decomp.dev's file tree
reads like the real codebase.

Resolution inputs (already-merged dicts, so the pure logic stays trivial):
  * ``funcname_by_vaddr``  — vaddr -> symbol name (from config/symbol_addrs.txt)
  * ``vaddr_by_funcname``  — symbol name -> vaddr (reverse)
  * ``folder_by_vaddr``    — vaddr -> subsystem/library folder (engine subsys
                             from progress/unit_subsystems.json merged with
                             library categories from function_categories.json)
"""
from __future__ import annotations

import pytest

import json
from pathlib import Path

from scripts.gen_unit_names import (
    compute_display_names,
    load_folder_map,
    load_part_funcs,
    load_symbol_addrs,
    load_units,
    resolve_unit,
)

_ROOT = Path(__file__).resolve().parent.parent


# --------------------------------------------------------------------------- #
# Fixtures: tiny synthetic maps
# --------------------------------------------------------------------------- #
FUNC_BY_VADDR = {
    0x1004C8: "IsTargetVisibleOrForced_1004C8",   # named engine fn (enemy)
    0x10B780: "UpdateBossPhase_10B780",            # named engine fn (no subsys)
    0x17F5D0: "criAdxRead_17F5D0",                 # named library fn
    0x100000: "func_00100000",                     # auto-name (anonymous)
}
VADDR_BY_FUNC = {v: k for k, v in FUNC_BY_VADDR.items()}
FOLDER_BY_VADDR = {
    0x1004C8: "enemy",            # engine subsystem (from unit_subsystems.json)
    0x17F5D0: "cri-middleware",   # library category (from function_categories)
    # 0x10B780 deliberately absent -> residue
}


def _resolve(name):
    return resolve_unit(name, FUNC_BY_VADDR, VADDR_BY_FUNC, FOLDER_BY_VADDR)


def _resolve_pf(name, partfuncs_by_unit):
    """resolve_unit with a part-funcs manifest (asm/cod/<obj>.partN naming)."""
    return resolve_unit(
        name, FUNC_BY_VADDR, VADDR_BY_FUNC, FOLDER_BY_VADDR,
        partfuncs_by_unit=partfuncs_by_unit,
    )


# --------------------------------------------------------------------------- #
# resolve_unit — the per-unit (folder, leaf) rule table
# --------------------------------------------------------------------------- #
class TestResolveUnit:
    def test_carved_src_with_subsystem_and_name(self):
        # src/cod/<vaddr>, known funcname + known subsystem -> <subsys>/<clean leaf>
        assert _resolve("src/cod/001004c8") == "enemy/IsTargetVisibleOrForced"

    def test_carved_src_named_but_no_subsystem_is_residue(self):
        # known funcname, no subsystem -> cod/ residue folder, named leaf
        assert _resolve("src/cod/0010b780") == "cod/UpdateBossPhase"

    def test_library_nonmatching_routed_to_category_folder(self):
        assert _resolve("asm/nonmatching/criAdxRead_17F5D0") == "cri-middleware/criAdxRead"

    def test_already_foldered_tu_is_preserved(self):
        # src/cod/<subsys>/<file> keeps its folder; only the build prefix drops
        assert _resolve("src/cod/object/devil_arm") == "object/devil_arm"

    def test_already_foldered_tu_nested_leaf_preserved(self):
        assert _resolve("src/cod/enemy/boss/phase") == "enemy/boss/phase"

    def test_asm_monolith_fragment_is_residue(self):
        assert _resolve("asm/cod/000000.part17") == "cod/000000.part17"

    def test_anonymous_func_addr_leaf_falls_back_to_basename(self):
        # auto-name (func_<addr>) is not a usable leaf -> keep original basename
        assert _resolve("src/cod/00100000") == "cod/00100000"

    def test_flat_word_named_tu_without_subsystem_is_residue(self):
        assert _resolve("src/cod/merged_orphans_d") == "cod/merged_orphans_d"

    def test_asm_data_routed_to_data_folder(self):
        assert _resolve("asm/data/cod/2BBF80") == "data/cod/2BBF80"

    def test_rel_routed_to_rel_folder(self):
        assert _resolve("rel/r207/asm/rel/r207/main") == "rel/r207/asm/rel/r207/main"

    def test_idempotent_on_already_display_name(self):
        # feeding a produced display name back must be stable
        assert _resolve("enemy/IsTargetVisibleOrForced") == "enemy/IsTargetVisibleOrForced"


# --------------------------------------------------------------------------- #
# resolve_unit + part-funcs manifest — the asm/cod/<obj>.partN naming.
# A carved monolith fragment (partN) is the gap between two carves; it can hold
# zero, one, or several un-carved functions.  The manifest maps the part unit to
# the (name, vaddr) of each function it contains, so the resolver can name the
# fragment after its primary function instead of the opaque hex part-index.
# --------------------------------------------------------------------------- #
class TestResolvePartUnits:
    # The manifest maps a part unit to the vaddrs it contains (asm-structural
    # fact); ALL names come from the committed symbol table (FUNC_BY_VADDR), so
    # no name absent from public source can ever surface.
    def test_single_named_func_uses_subsystem_and_name(self):
        pf = {"asm/cod/000000.part3": [0x1004C8]}
        assert _resolve_pf("asm/cod/000000.part3", pf) == "enemy/IsTargetVisibleOrForced"

    def test_multi_func_anchors_lowest_vaddr_named_with_count(self):
        # input order shuffled; anchor is the lowest-vaddr named function, and
        # the (+n) suffix counts the other functions sharing the fragment.
        pf = {"asm/cod/000000.part4": [0x17F5D0, 0x1004C8]}
        assert _resolve_pf("asm/cod/000000.part4", pf) == "enemy/IsTargetVisibleOrForced (+1)"

    def test_empty_fragment_buckets_under_pad(self):
        # alignment-only gap between adjacent carves -> quiet residue folder.
        pf = {"asm/cod/000000.part7": []}
        assert _resolve_pf("asm/cod/000000.part7", pf) == "cod/_pad/000000.part7"

    def test_part_absent_from_manifest_is_residue(self):
        # manifest present but this unit missing -> graceful current behavior.
        assert _resolve_pf("asm/cod/000000.part17", {}) == "cod/000000.part17"

    def test_no_manifest_is_residue(self):
        # no manifest at all (None) -> unchanged legacy residue naming.
        assert _resolve("asm/cod/000000.part17") == "cod/000000.part17"

    def test_vaddr_unknown_to_symbol_table_uses_hex_leaf(self):
        # vaddr not in the committed symbol table (or only an auto-name) -> the
        # stable hex address, never a name pulled from elsewhere.
        pf = {"asm/cod/000000.part9": [0x100000]}      # FUNC_BY_VADDR -> func_*
        assert _resolve_pf("asm/cod/000000.part9", pf) == "cod/00100000"
        pf2 = {"asm/cod/000000.part9b": [0x1AB340]}    # absent from FUNC_BY_VADDR
        assert _resolve_pf("asm/cod/000000.part9b", pf2) == "cod/001ab340"

    def test_named_preferred_over_lower_vaddr_anonymous(self):
        # lowest vaddr is anonymous; anchor jumps to the first *named* fn, but
        # the count still reflects every function in the fragment.
        pf = {"asm/cod/000000.part10": [0x100000, 0x1004C8]}
        assert _resolve_pf("asm/cod/000000.part10", pf) == "enemy/IsTargetVisibleOrForced (+1)"


# --------------------------------------------------------------------------- #
# compute_display_names — whole-set: uniqueness + determinism
# --------------------------------------------------------------------------- #
class TestComputeDisplayNames:
    def test_returns_mapping_for_each_unit(self):
        out = compute_display_names(
            ["src/cod/001004c8", "asm/cod/000000.part17"],
            FUNC_BY_VADDR, VADDR_BY_FUNC, FOLDER_BY_VADDR,
        )
        assert out["src/cod/001004c8"] == "enemy/IsTargetVisibleOrForced"
        assert out["asm/cod/000000.part17"] == "cod/000000.part17"

    def test_collision_is_disambiguated_with_original_basename(self):
        # two distinct units whose cleaned leaves both reduce to "Foo"
        funcs = {0x10000: "Foo_10000", 0x20000: "Foo_20000"}
        rev = {v: k for k, v in funcs.items()}
        folders = {0x10000: "enemy", 0x20000: "enemy"}
        out = compute_display_names(
            ["src/cod/00010000", "src/cod/00020000"], funcs, rev, folders,
        )
        names = set(out.values())
        # both land in enemy/, both unique, base name 'Foo' preserved
        assert len(names) == 2
        assert all(n.startswith("enemy/Foo") for n in names)

    def test_deterministic_regardless_of_input_order(self):
        units = ["src/cod/00010000", "src/cod/00020000"]
        funcs = {0x10000: "Foo_10000", 0x20000: "Foo_20000"}
        rev = {v: k for k, v in funcs.items()}
        folders = {0x10000: "enemy", 0x20000: "enemy"}
        a = compute_display_names(units, funcs, rev, folders)
        b = compute_display_names(list(reversed(units)), funcs, rev, folders)
        assert a == b

    def test_threads_part_funcs_manifest_to_resolver(self):
        out = compute_display_names(
            ["asm/cod/000000.part4"],
            FUNC_BY_VADDR, VADDR_BY_FUNC, FOLDER_BY_VADDR,
            partfuncs_by_unit={"asm/cod/000000.part4": [0x1004C8]},
        )
        assert out["asm/cod/000000.part4"] == "enemy/IsTargetVisibleOrForced"


# --------------------------------------------------------------------------- #
# load_part_funcs — committed progress/unit_part_funcs.json -> in-memory map.
# Generated locally by scripts/gen_part_funcs.py (which needs the gitignored
# asm/), committed, then consumed here at toolchain-free publish time.
# --------------------------------------------------------------------------- #
class TestLoadPartFuncs:
    def test_parses_units_and_normalizes_vaddrs_to_int(self, tmp_path):
        p = tmp_path / "unit_part_funcs.json"
        p.write_text(json.dumps({
            "asm/cod/000000.part4": ["0x001004C8", "0x0017F5D0"],
            "asm/cod/000000.part7": [],
        }))
        m = load_part_funcs(p)
        assert m["asm/cod/000000.part4"] == [0x1004C8, 0x17F5D0]
        assert m["asm/cod/000000.part7"] == []

    def test_missing_file_yields_empty_map(self, tmp_path):
        assert load_part_funcs(tmp_path / "nope.json") == {}


# --------------------------------------------------------------------------- #
# Loaders — file -> dict
# --------------------------------------------------------------------------- #
class TestLoadSymbolAddrs:
    def test_parses_func_lines_both_directions(self, tmp_path):
        p = tmp_path / "symbol_addrs.txt"
        p.write_text(
            "_start = 0x00100008; // type:func\n"
            "UpdateBossPhase_10B780 = 0x0010B780; // type:func\n"
        )
        by_vaddr, by_func = load_symbol_addrs(p)
        assert by_vaddr[0x10B780] == "UpdateBossPhase_10B780"
        assert by_func["UpdateBossPhase_10B780"] == 0x10B780
        assert by_vaddr[0x100008] == "_start"

    def test_ignores_non_func_symbols(self, tmp_path):
        p = tmp_path / "symbol_addrs.txt"
        p.write_text(
            "AFunc_100000 = 0x00100000; // type:func\n"
            "D_00200000 = 0x00200000; // type:data\n"
        )
        by_vaddr, _ = load_symbol_addrs(p)
        assert 0x100000 in by_vaddr
        assert 0x200000 not in by_vaddr


class TestLoadFolderMap:
    def test_merges_engine_subsystems_and_library_categories(self, tmp_path):
        subs = tmp_path / "unit_subsystems.json"
        subs.write_text(json.dumps({"subsystems": {"enemy": ["0x0010B780"]}}))
        cats = tmp_path / "function_categories.json"
        cats.write_text(json.dumps({"categories": {"cri-middleware": ["0X0017F5D0"]}}))
        folder = load_folder_map(subs, cats)
        assert folder[0x10B780] == "enemy"
        assert folder[0x17F5D0] == "cri-middleware"

    def test_missing_files_yield_empty_map(self, tmp_path):
        folder = load_folder_map(tmp_path / "nope.json", tmp_path / "nope2.json")
        assert folder == {}


class TestLoadUnits:
    def test_recovers_original_name_from_base_path(self, tmp_path):
        # base_path (build/<orig>.o) is the stable key even when ``name`` has
        # already been remapped — so regeneration is order-independent.
        p = tmp_path / "objdiff.json"
        p.write_text(json.dumps({"units": [
            {"name": "cod/InitObjectVtables", "base_path": "build/src/cod/00100280.o"},
            {"name": "asm/cod/000000.part0", "base_path": "build/asm/cod/000000.part0.o"},
        ]}))
        assert load_units(p) == ["src/cod/00100280", "asm/cod/000000.part0"]

    def test_falls_back_to_name_when_no_base_path(self, tmp_path):
        p = tmp_path / "objdiff.json"
        p.write_text(json.dumps({"units": [{"name": "src/cod/001004c8"}]}))
        assert load_units(p) == ["src/cod/001004c8"]


# --------------------------------------------------------------------------- #
# NOTE: there is deliberately no "committed unit_names.json matches generator"
# drift guard.  ``progress/unit_names.json`` is a publish-time display remap
# that the decomp.dev upload workflow (.github/workflows/progress.yml)
# regenerates from the committed config on every run — nothing reads a
# committed copy.  Committing it only created a derived artifact that went
# stale on every match/rename commit and turned CI red for no functional
# reason, so it is no longer tracked (see .gitignore).  The generator itself
# is covered by the ``resolve_unit`` / ``compute_display_names`` / loader
# tests above; ``apply_to_report`` (the publish transform) is covered below.
# --------------------------------------------------------------------------- #


# --------------------------------------------------------------------------- #
# apply_to_report — publish-time transform of the decomp.dev artifact
# (the committed report.json stays original-named; only the uploaded copy is
# renamed, so tracker tooling that keys on src/ names is untouched).
# --------------------------------------------------------------------------- #
class TestApplyToReport:
    def test_renames_unit_names_via_map(self):
        from scripts.gen_unit_names import apply_to_report
        report = {"units": [
            {"name": "src/cod/00100280", "measures": {"total_code": "8"}},
            {"name": "asm/cod/000000.part0", "measures": {"total_code": "16"}},
        ]}
        n = apply_to_report(report, {"src/cod/00100280": "cod/InitObjectVtables"})
        assert n == 1
        assert report["units"][0]["name"] == "cod/InitObjectVtables"
        assert report["units"][1]["name"] == "asm/cod/000000.part0"  # unmapped: unchanged

    def test_does_not_touch_measures(self):
        from scripts.gen_unit_names import apply_to_report
        report = {"units": [{"name": "src/cod/00100280", "measures": {"total_code": "8"}}],
                  "measures": {"matched_code": "100"}}
        apply_to_report(report, {"src/cod/00100280": "cod/InitObjectVtables"})
        assert report["units"][0]["measures"] == {"total_code": "8"}
        assert report["measures"] == {"matched_code": "100"}
