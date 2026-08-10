"""Pin the documentation-record predicate for ``compile_config.json``.

Ticket 36. ``compile.py``'s ``Config.carved_funcs`` used to drop an entry
whose ``name`` starts with ``_`` and that has no ``tu``::

    if not name or (name.startswith("_") and not raw.get("tu")):
        continue

The rule exists to drop the ``{"_comment": ...}`` markers that live inside
the ``carved_funcs`` array. Written as a name-prefix test, it also dropped
**50 real library functions / 8,548 B** whose C identifier legitimately
begins with an underscore. They parsed, they passed every validation, and
then produced no LCF slot, no carve unit and no objdiff unit — inert since
``c3eafb4`` (2026-06-16) renamed them off their ``func_<addr>`` names.

Four readers carried the predicate; two of them had drifted apart:

===========================================  ==========================
reader                                       old behaviour
===========================================  ==========================
``compile.Config.carved_funcs``              dropped ``_`` with no ``tu``
``compile.Config.rels``                      same test, copied verbatim
``scripts.gen_part_funcs.filter_carved``     dropped ``_`` unconditionally
``scripts.check_tu_complete.load_carved``    dropped ``_`` unconditionally
===========================================  ==========================

The last two dropped 7 more entries than the build did — ``__umoddi3``,
``__dynamic_cast``, ``__floatdidf``, ``__fixdfdi``, ``__fixunsdfdi``,
``__fixunssfdi``, ``_waitIpuIdle`` — so the ``partN`` fragment index they
generate did not match the build's.

There is now one predicate, ``scripts.carver.is_doc_record``, and these
tests exist so the prefix rule cannot come back.
"""
from __future__ import annotations

import json
from pathlib import Path

import pytest

import compile as cm
from scripts.carver import CarveSchema, is_doc_record
from scripts.check_tu_complete import load_carved_funcs
from scripts.gen_part_funcs import filter_carved_funcs

ROOT = Path(__file__).resolve().parent.parent
CONFIG = ROOT / "compile_config.json"

# The four names the ticket cites as evidence. Each is a real library
# function with a `glabel` in the monolithic asm and a `nonmatching`
# marker; each was inert while the prefix rule stood.
#
# If one of these fails because the function was RENAMED, update the name
# here. Do not delete the test — the name is the evidence that produced it.
INERT_EVIDENCE = {
    # name                    (vaddr,      size)
    "_IO_adjust_column":      ("0x0038CE10", 72),
    "__rtti_class":           ("0x0031EE80", 36),
    "__7filebuf":             ("0x0038EB98", 108),
    "_InitAlarm":             ("0x003B76B8", 76),
}


def _raw_config() -> dict:
    return json.loads(CONFIG.read_text())


def _mkcfg(**overrides) -> cm.Config:
    """Minimal ``Config`` — only the fields these tests read."""
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
    }
    raw.update(overrides)
    return cm.Config(raw=raw)


# --------------------------------------------------------------------------- #
# The predicate itself
# --------------------------------------------------------------------------- #
class TestIsDocRecord:

    def test_comment_only_marker_is_documentation(self):
        assert is_doc_record({"_comment": "PERMANENT: jump-table labels"})

    def test_non_dict_is_documentation(self):
        assert is_doc_record("not a dict")
        assert is_doc_record(None)

    def test_underscore_name_is_data_not_documentation(self):
        # The whole ticket in one assertion.
        entry = {"name": "_IO_adjust_column", "unit": "asm/cod/000000",
                 "vaddr": "0x0038CE10", "size": 72, "lib": True}
        assert not is_doc_record(entry)

    def test_ordinary_name_is_data(self):
        assert not is_doc_record({"name": "func_00100000"})

    def test_schema_static_alias_is_the_same_predicate(self):
        # One definition, four call sites. A second spelling is how this
        # defect survived the first fix (ticket 29).
        for probe in ({"_comment": "x"}, {"name": "_IO_init"}, "str"):
            assert CarveSchema.is_doc_record(probe) is is_doc_record(probe)


# --------------------------------------------------------------------------- #
# Config.carved_funcs
# --------------------------------------------------------------------------- #
class TestConfigCarvedFuncs:

    def test_keeps_underscore_named_entry_with_no_tu(self):
        cfg = _mkcfg(carved_funcs=[
            {"_comment": "doc block lives next to the array"},
            {"name": "_IO_adjust_column", "unit": "asm/cod/000000",
             "vaddr": "0x0038CE10", "size": 72, "lib": True},
            {"name": "func_00100000", "unit": "asm/cod/000000",
             "vaddr": "0x00100000", "size": 4},
        ])
        assert [e["name"] for e in cfg.carved_funcs] == [
            "_IO_adjust_column", "func_00100000",
        ]

    def test_drops_comment_only_record(self):
        cfg = _mkcfg(carved_funcs=[{"_comment": "doc"}])
        assert cfg.carved_funcs == []

    def test_drops_non_dict_element(self):
        cfg = _mkcfg(carved_funcs=["not a dict"])
        assert cfg.carved_funcs == []

    def test_empty_name_raises_instead_of_vanishing(self):
        # A `name` key with an empty value is malformed DATA, not
        # documentation. Silently discarding it is the failure mode this
        # ticket exists to remove, so it must be loud.
        cfg = _mkcfg(carved_funcs=[
            {"name": "", "unit": "asm/cod/000000", "vaddr": 0, "size": 4},
        ])
        with pytest.raises(cm.BuildError, match="empty 'name'"):
            _ = cfg.carved_funcs


# --------------------------------------------------------------------------- #
# Config.rels — the copied predicate
# --------------------------------------------------------------------------- #
class TestConfigRels:

    _R207 = {
        "name": "r207",
        "lcf": "config/r207.lcf",
        "sha256_expected": "ea59932301345e48add7a3eff029b7d0d0138fff1abc"
                           "67569467880678c653c1",
        "size_expected": 1720,
        "build_path": "build/rel/r207",
        "parts": [{"kind": "bin", "path": "bin/rel/r207/header.bin",
                   "size": 1720}],
    }

    def test_underscore_named_rel_is_not_dropped(self):
        # No REL is named `_boot` today, so the copied prefix test cost
        # nothing yet. It is fixed rather than justified because a copied
        # predicate is how the carved_funcs defect survived one fix.
        entry = dict(self._R207, name="_boot")
        cfg = _mkcfg(rels=[entry])
        [rel] = cfg.rels
        assert rel.name == "_boot"

    def test_comment_only_rel_record_is_dropped(self):
        cfg = _mkcfg(rels=[{"_comment": "doc"}, dict(self._R207)])
        assert [r.name for r in cfg.rels] == ["r207"]

    def test_empty_name_raises(self):
        cfg = _mkcfg(rels=[dict(self._R207, name="")])
        with pytest.raises(cm.BuildError, match="empty 'name'"):
            _ = cfg.rels


# --------------------------------------------------------------------------- #
# The committed config — the entry-count identity and the named evidence
# --------------------------------------------------------------------------- #
class TestCommittedConfig:

    def test_yielded_count_equals_raw_minus_documentation(self):
        raw = _raw_config()["carved_funcs"]
        docs = [e for e in raw if is_doc_record(e)]
        cfg = cm.Config(raw=_raw_config())
        # The difference is NAMED, not tolerated: it is exactly the
        # `_comment` markers. Nothing else is discarded.
        assert len(cfg.carved_funcs) == len(raw) - len(docs)
        assert all("_comment" in d for d in docs)

    def test_every_named_entry_survives(self):
        raw = _raw_config()["carved_funcs"]
        named = {e["name"] for e in raw if isinstance(e, dict) and "name" in e}
        cfg = cm.Config(raw=_raw_config())
        assert {e["name"] for e in cfg.carved_funcs} == named

    @pytest.mark.parametrize("name", sorted(INERT_EVIDENCE))
    def test_inert_evidence_entry_now_reaches_the_build(self, name):
        vaddr, size = INERT_EVIDENCE[name]
        cfg = cm.Config(raw=_raw_config())
        [entry] = [e for e in cfg.carved_funcs if e["name"] == name]
        assert entry["vaddr"] == vaddr
        assert entry["size"] == size
        assert entry.get("tu") is None      # standalone carve, no C owner
        assert entry.get("lib") is True

    def test_all_four_readers_agree_on_the_same_set(self):
        # The lockstep property. gen_part_funcs' manifest indexes the
        # build's fragments by position, so a one-entry disagreement
        # renames every downstream partN unit.
        raw_cfg = _raw_config()
        raw = raw_cfg["carved_funcs"]
        from_config = [e["name"] for e in cm.Config(raw=raw_cfg).carved_funcs]
        from_part_funcs = [e["name"] for e in filter_carved_funcs(raw)]
        from_tu_complete = [e["name"] for e in load_carved_funcs(CONFIG)]
        from_carver = [
            e.name for e in CarveSchema.parse_entries(
                cm.Config(raw=raw_cfg)
            )
        ]
        assert from_part_funcs == from_config
        assert from_tu_complete == from_config
        assert from_carver == from_config
