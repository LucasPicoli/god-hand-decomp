"""The `cmpfull` fp_hazard_rules value: drop the c.<cond>.s -> bc1* pad when
the branch delay slot is FULL.

Retail pads 2,673 of 2,693 full-slot pairs, so this can never be global. It is
a per-TU opt-in describing twenty sites in eight functions, none of which mixes
the two forms. Census:
`.scratch/decomp-velocity/findings/wave-2026-08-31/cmpfull_census.py`.
"""
import importlib.util
import pathlib

ROOT = pathlib.Path(__file__).resolve().parents[1]


def _load(name, path):
    spec = importlib.util.spec_from_file_location(name, ROOT / path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


SN = _load("sn_cc_wrap", "scripts/sn-cc-wrap.py")

FULL = "\n".join([
    "\tc.eq.s\t$f20,$f20",
    "#nop",
    "\tbc1t\t$L42",
    "\taddiu\t$v0,$v0,1",       # a FULL delay slot
])
EMPTY = "\n".join([
    "\tc.eq.s\t$f20,$f20",
    "#nop",
    "\tbc1t\t$L42",
    "\tnop",                     # an EMPTY delay slot
])


def _rules(spec):
    return SN._parse_fp_hazard_rules(spec)


def test_cmpfull_drops_the_pad_on_a_full_slot():
    assert "nop" not in SN._materialize_hazard_nops(FULL, _rules("cmpfull")).split("bc1t")[0]


def test_cmpfull_leaves_an_empty_slot_alone():
    """The `libm` half owns the empty-slot case; `cmpfull` must not touch it."""
    out = SN._materialize_hazard_nops(EMPTY, _rules("cmpfull"))
    assert out.split("bc1t")[0].count("nop") == 1


def test_without_the_rule_the_pad_stays():
    out = SN._materialize_hazard_nops(FULL, _rules("mtc1"))
    assert out.split("bc1t")[0].count("nop") == 1


def test_the_value_is_in_the_known_vocabulary():
    assert "cmpfull" in SN._FP_RULES_KNOWN
    ee = _load("ee_cc_wrap", "scripts/ee-cc-wrap.py")
    assert "cmpfull" in ee._FP_RULES_KNOWN
    # the two wrappers must agree byte-for-byte on this pass
    assert ee._compare_slot_is_full.__doc__ == SN._compare_slot_is_full.__doc__
