"""Unit tests for ``scripts/gen_part_funcs.py`` — the carved-monolith fragment
manifest generator.

``compile.py`` splits the monolithic ``asm/cod/000000.s`` into ``N+1`` fragments
around the carve points (``compile.py``: ``for idx, frag in enumerate(fragments):
000000.part{idx}.s``).  A fragment is the *gap* between two carves, so it holds
zero, one, or several un-carved functions.  This generator reproduces that exact
split (same ``split_monolithic`` + same carve name-list) and records, per part
unit, the functions it contains so the decomp.dev display remap can name the
fragment instead of showing an opaque ``cod/000000.partN`` leaf.

The pure halves (``extract_funcs`` / ``build_manifest``) take text and need no
toolchain; ``generate`` is the thin file-loading glue, exercised hermetically
with a synthetic monolithic so it runs without the gitignored real asm.
"""
from __future__ import annotations

import json
from pathlib import Path

from scripts.gen_part_funcs import (
    build_manifest,
    extract_funcs,
    filter_carved_funcs,
    generate,
)


# --------------------------------------------------------------------------- #
# extract_funcs — glabel + first-instruction VRAM -> [vaddr hex strings].
# Only the address is recorded; names are resolved downstream from the public
# symbol table, so no private-tree name is ever baked into the committed file.
# --------------------------------------------------------------------------- #
class TestExtractFuncs:
    def test_single_func_takes_first_instruction_vaddr(self):
        frag = (
            ".align 3\n"
            "nonmatching func_00100000, 8\n"
            "glabel func_00100000\n"
            "    /* 0 100000 03e00008 */ jr      $ra\n"
            "    /* 4 100004 00000000 */ nop\n"
        )
        assert extract_funcs(frag) == ["0x00100000"]

    def test_multiple_funcs_in_source_order(self):
        frag = (
            "glabel func_00100000\n"
            "    /* 0 100000 03e00008 */ jr      $ra\n"
            ".align 3\n"
            "glabel Foo_1004C8\n"
            "    /* 4c8 1004c8 27bdfff0 */ addiu   $sp, $sp, -0x10\n"
        )
        assert extract_funcs(frag) == ["0x00100000", "0x001004C8"]

    def test_empty_alignment_gap_yields_no_funcs(self):
        assert extract_funcs(".align 3\n\n") == []

    def test_glabel_without_instruction_is_skipped(self):
        # a label with no following /* off vram bytes */ insn has no derivable
        # start vaddr -> can't fold it, so it's dropped rather than guessed.
        frag = (
            "glabel Foo_1004C8\n"
            "    /* 4c8 1004c8 27bdfff0 */ addiu   $sp, $sp, -0x10\n"
            "glabel jtbl_dataonly\n"
            "    .word 0x00100000\n"
        )
        assert extract_funcs(frag) == ["0x001004C8"]


# --------------------------------------------------------------------------- #
# filter_carved_funcs — replicate compile.py's Config.carved_funcs so the carve
# name-list (and thus the fragment split) matches the build EXACTLY.  The build
# drops documentation records only: a non-dict element, or a dict with no
# `name` key.  Ticket 36: a `_`-prefixed name is a real C++ operator mangle
# (`__ls__7ostreamc`) or a real library symbol (`_IO_adjust_column`), so it IS
# carved.  This filter and compile.py's had drifted 7 entries apart — the old
# text here dropped `__umoddi3` and `__dynamic_cast`, which the build carves.
# --------------------------------------------------------------------------- #
class TestFilterCarvedFuncs:
    def test_drops_doc_records_and_keeps_underscore_names(self):
        raw = [
            {"name": "Foo_1004C8", "vaddr": "0x001004C8", "size": 8, "unit": "asm/cod/000000"},
            {"name": "__ls__7ostreamc", "vaddr": "0x00100500", "size": 8, "unit": "asm/cod/000000"},
            {"_comment": "doc-only marker"},
            {"vaddr": "0x00100600"},          # no name -> documentation
            "not-a-dict",
        ]
        kept = filter_carved_funcs(raw)
        assert [e["name"] for e in kept] == ["Foo_1004C8", "__ls__7ostreamc"]


# --------------------------------------------------------------------------- #
# build_manifest — fragments (in order) -> {<prefix>.partN: [funcs]}
# --------------------------------------------------------------------------- #
class TestBuildManifest:
    def test_indexes_fragments_by_part_position(self):
        frags = [
            ".align 3\n",  # empty pad -> part0
            "glabel Foo_1004C8\n    /* 4c8 1004c8 27bdfff0 */ addiu $sp, $sp, -0x10\n",
        ]
        m = build_manifest(frags, "asm/cod/000000")
        assert m["asm/cod/000000.part0"] == []
        assert m["asm/cod/000000.part1"] == ["0x001004C8"]


# --------------------------------------------------------------------------- #
# generate — full glue: synthetic monolithic + carve config -> manifest.
# Mirrors compile.py::maybe_carve: same split_monolithic, same parse_entries
# name-list, so the part indices line up with the real build.
# --------------------------------------------------------------------------- #
_MONO = (
    ".set noat\n"
    ".section .text\n"
    ".align 3\n"
    "nonmatching Foo_1004C8, 8\n"
    "glabel Foo_1004C8\n"
    "    /* 0 1004c8 27bdfff0 */ addiu   $sp, $sp, -0x10\n"
    "    /* 4 1004cc 03e00008 */ jr      $ra\n"
    "endlabel Foo_1004C8\n"
    ".align 3\n"
    "nonmatching Bar_100500, 8\n"
    "glabel Bar_100500\n"
    "    /* 8 100500 03e00008 */ jr      $ra\n"
    "    /* c 100504 00000000 */ nop\n"
    "endlabel Bar_100500\n"
)


class TestGenerateIntegration:
    def _setup(self, root: Path):
        (root / "asm" / "cod").mkdir(parents=True)
        (root / "asm" / "cod" / "000000.s").write_text(_MONO)
        (root / "compile_config.json").write_text(json.dumps({"carved_funcs": [
            {"name": "Foo_1004C8", "unit": "asm/cod/000000",
             "vaddr": "0x001004C8", "size": 8, "tu": None},
        ]}))

    def test_carved_func_leaves_its_fragment_neighbour_recorded(self, tmp_path):
        # carve Foo out -> the trailing fragment still holds un-carved Bar, whose
        # vaddr the manifest records so it can be named on decomp.dev.
        self._setup(tmp_path)
        m = generate(tmp_path)
        assert m["asm/cod/000000.part1"] == ["0x00100500"]
        # the leading fragment is preamble-only (Foo carved away) -> empty pad.
        assert m["asm/cod/000000.part0"] == []

    def test_part_indices_match_enumerate_of_fragments(self, tmp_path):
        # exactly N+1 part units for N carves (compile.py enumerate invariant).
        self._setup(tmp_path)
        m = generate(tmp_path)
        assert set(m) == {"asm/cod/000000.part0", "asm/cod/000000.part1"}

    def test_manifest_roundtrips_through_display_resolver(self, tmp_path):
        # the on-disk JSON this writes must feed gen_unit_names' loader/resolver:
        # generate -> JSON -> load_part_funcs -> resolve_unit, across the vaddr
        # hex-string <-> int seam.
        from scripts.gen_unit_names import load_part_funcs, resolve_unit

        self._setup(tmp_path)
        (tmp_path / "progress").mkdir()
        manifest_path = tmp_path / "progress" / "unit_part_funcs.json"
        manifest_path.write_text(json.dumps(generate(tmp_path)))

        pf = load_part_funcs(manifest_path)
        # vaddr resolved against the (here-supplied) public symbol table.
        fbv = {0x100500: "Bar_100500"}
        disp = resolve_unit("asm/cod/000000.part1", fbv, {}, {}, partfuncs_by_unit=pf)
        assert disp == "cod/Bar"
        # empty fragment -> pad bucket, regardless of symbol table.
        assert resolve_unit("asm/cod/000000.part0", {}, {}, {}, partfuncs_by_unit=pf) \
            == "cod/_pad/000000.part0"
