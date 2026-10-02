"""Unit tests for scripts/checks/link_symbols.py (link names from committed files).

Offline: ``unresolved`` is pure, so these run without the toolchain. The
compile half of the gate runs in the link-symbols CI job.
"""
from __future__ import annotations

import importlib.util
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
spec = importlib.util.spec_from_file_location(
    "link_symbols", ROOT / "scripts" / "checks" / "link_symbols.py")
ls = importlib.util.module_from_spec(spec)
spec.loader.exec_module(ls)

NAMES = {"_IO_seekoff": 0x0038E3F0, "Named": 0x00100000}
LCF = {"func_0010012C": 0x0010012C}


def test_resolved_names_pass():
    carves = [{"_comment": "x"},
              {"name": "Named", "vaddr": "0x00100000"},
              {"name": "func_00200000", "vaddr": "0x00200000"}]
    undefined = [("_IO_seekoff", "a"), ("InTU", "a"), ("func_0010012C", "a"),
                 ("func_00300000", "a"), ("D_00410000", "a"), (".L0021A8A4", "a")]
    assert ls.unresolved(NAMES, LCF, carves, {"InTU"}, undefined) == []


def test_issue_3_name_missing_from_symbol_addrs():
    errs = ls.unresolved(NAMES, LCF, [], set(),
                         [("_IO_getline_info", "src/cod/0038a8d8")])
    assert errs == ["src/cod/0038a8d8: _IO_getline_info is defined by no TU "
                    "and named nowhere in config/symbol_addrs.txt"]


def test_auto_name_for_a_named_address():
    errs = ls.unresolved(NAMES, LCF, [], set(), [("func_00100000", "u")])
    assert errs == ["u: func_00100000, but splat labels that address Named"]


def test_carve_name_splat_will_not_write():
    carves = [{"name": "Gone", "vaddr": "0x00200000"},
              {"name": "func_00100000", "vaddr": "0x00100000"}]
    assert ls.unresolved(NAMES, LCF, carves, set(), []) == [
        "carved_funcs: Gone at 0x00200000, but splat labels that address func_00200000",
        "carved_funcs: func_00100000 at 0x00100000, but splat labels that address Named",
    ]


def test_committed_carves_resolve():
    cfg = json.loads((ROOT / "compile_config.json").read_text())
    names = ls.assignments(ROOT / "config" / "symbol_addrs.txt")
    assert ls.unresolved(names, {}, cfg["carved_funcs"], set(), []) == []
