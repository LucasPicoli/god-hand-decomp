"""The FDIV hazard pad must reach exactly two nops, whatever cc1 already emitted.

Retail's `div.s` sites carry two hazard nops. SN cc1 emits ONE of them itself, so
an all-or-nothing idempotency guard ("are BOTH slots already nops?") answers no,
adds the full pad, and the site ends with THREE. No rule combination could then
reach retail's two — measured on func_0020F3C0.

Both cc-wraps carried the same guard, so both are tested here.
"""
import importlib.util
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[1]


def _load(name):
    spec = importlib.util.spec_from_file_location(
        name.replace("-", "_"), ROOT / "scripts" / f"{name}.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


WRAPS = ["sn-cc-wrap", "ee-cc-wrap"]


def _pad_count(mod, existing_nops):
    """Nops directly above the div.s after the inserter runs."""
    body = ["\t.set reorder", "\tmtc1 $at,$f1"]
    body += ["\tnop"] * existing_nops
    body += ["\tdiv.s $f0,$f2,$f1"]
    out = mod._insert_ee_fp_hazard_nops("\n".join(body), ["fdiv"]).split("\n")
    div = next(i for i, l in enumerate(out) if l.strip().startswith("div.s"))
    n = 0
    while div - n - 1 >= 0 and out[div - n - 1].strip() == "nop":
        n += 1
    return n


@pytest.mark.parametrize("wrap", WRAPS)
@pytest.mark.parametrize("existing", [0, 1, 2])
def test_pad_reaches_exactly_two(wrap, existing):
    mod = _load(wrap)
    assert _pad_count(mod, existing) == 2, (
        f"{wrap}: {existing} pre-existing nop(s) must still yield exactly 2")


@pytest.mark.parametrize("wrap", WRAPS)
def test_prev_nop_run_counts_up_to_the_limit(wrap):
    mod = _load(wrap)
    lines = ["\tnop", "\tnop", "\tnop", "\tdiv.s $f0,$f2,$f1"]
    assert mod._prev_nop_run(lines, 3, 2) == 2   # capped at the limit
    assert mod._prev_nop_run(lines, 1, 2) == 1   # only one above index 1
    assert mod._prev_nop_run(lines, 0, 2) == 0   # nothing above index 0


if __name__ == "__main__":
    for w in WRAPS:
        m = _load(w)
        for e in (0, 1, 2):
            got = _pad_count(m, e)
            assert got == 2, f"{w}: {e} existing -> {got}"
        print(f"{w}: pad reaches exactly 2 from 0, 1 and 2 existing nops")
    print("OK")


# --- the `sqrt` rule: the mirror of `div` (issue 77 Route A) -----------------
#
# `fdiv` pads div.s + sqrt.s + rsqrt.s; `div` pads div.s alone; `sqrt` pads
# sqrt.s + rsqrt.s alone. Four unmatched functions carry a PADDED sqrt.s and a
# BARE div.s in one body, which neither of the older two can express.

_MIXED_ASM = "\n".join([
    "\tmul.s\t$f1,$f1,$f5",
    "\tdiv.s\t$f2,$f2,$f0",
    "\tmov.s\t$f3,$f4",
    "\tsqrt.s\t$f0,$f12",
    "\tadd.s\t$f5,$f5,$f6",
])


def _nops_before(text, mnemonic):
    """Nops directly above the first *mnemonic* site."""
    head = text.split(mnemonic)[0].rstrip().split("\n")
    n = 0
    for line in reversed(head):
        if line.strip() == "nop":
            n += 1
        elif line.strip():
            break
    return n


@pytest.mark.parametrize("wrap", WRAPS)
@pytest.mark.parametrize("rule,want_div,want_sqrt", [
    ("fdiv", 2, 2),
    ("div",  2, 0),
    ("sqrt", 0, 2),
])
def test_rule_selects_the_instruction_class(wrap, rule, want_div, want_sqrt):
    mod = _load(wrap)
    inserter = getattr(mod, "_insert_ee_fp_hazard_nops", None) or \
        getattr(mod, "_insert_sn_fp_hazard_nops")
    out = inserter(_MIXED_ASM, rules=mod._parse_fp_hazard_rules(rule))
    assert _nops_before(out, "div.s") == want_div
    assert _nops_before(out, "sqrt.s") == want_sqrt


@pytest.mark.parametrize("wrap", WRAPS)
def test_sqrt_is_in_the_vocabulary_and_a_typo_still_dies(wrap):
    mod = _load(wrap)
    assert "sqrt" in mod._FP_RULES_KNOWN
    assert mod._parse_fp_hazard_rules("sqrt") == frozenset({"sqrt"})
    with pytest.raises(ValueError):
        mod._parse_fp_hazard_rules("sqrtt")
