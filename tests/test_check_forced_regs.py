"""Unit tests for scripts/check_forced_regs.py (forced-register ratchet).

Offline; exercises the pure detection helpers (``strip_comments``,
``count_pins``, ``PIN_RE``) against synthetic source files in tmp_path.
These are the load-bearing logic: a false negative lets a forced-register
pin slip past the gate, a false positive on comment prose breaks every
commit.
"""
from __future__ import annotations

from scripts import check_forced_regs as cfr


def _write(tmp_path, name, text):
    p = tmp_path / name
    p.write_text(text)
    return p


def test_counts_real_dual_pin_constructor(tmp_path):
    src = (
        'void *f(void *obj) {\n'
        '    register int *vtable __asm__("$3");\n'
        '    register int *type_name __asm__("$3");\n'
        '    return obj;\n'
        '}\n'
    )
    assert cfr.count_pins(_write(tmp_path, "a.c", src)) == 2


def test_comment_prose_does_not_count(tmp_path):
    # Both block- and line-comment mentions of the idiom must be ignored —
    # the matched-function headers in src/cod/ are full of these.
    src = (
        '/* example: register int *X __asm__("$3"); is BANNED */\n'
        '// also register int *Y __asm__("$2"); in a line comment\n'
        'void g(void) {}\n'
    )
    assert cfr.count_pins(_write(tmp_path, "b.c", src)) == 0


def test_midline_pin_is_caught(tmp_path):
    # Regression guard: an unanchored pin (not at line start) must still
    # count — this was a false-negative in the first cut of the checker.
    src = 'void h(int c){ if(c){ register int x __asm__("$2"); (void)x; } }\n'
    assert cfr.count_pins(_write(tmp_path, "c.c", src)) == 1


def test_plain_register_without_asm_does_not_count(tmp_path):
    # The bare `register` storage class is not a forced-register pin.
    src = 'void k(void){ register int i; for(i=0;i<4;i++){} }\n'
    assert cfr.count_pins(_write(tmp_path, "d.c", src)) == 0


def test_plain_asm_spelling_is_caught(tmp_path):
    # GCC's plain `asm` binding spelling is codegen-identical to `__asm__`
    # and previously evaded BOTH this gate and the inline-asm gate.
    src = 'void *f(void *o){ register int *v asm("$3"); return o; }\n'
    assert cfr.count_pins(_write(tmp_path, "asm.c", src)) == 1


def test_single_underscore_asm_spelling_is_caught(tmp_path):
    # The `__asm` (single-pair) binding spelling must also count.
    src = 'void *f(void *o){ register int *v __asm("$3"); return o; }\n'
    assert cfr.count_pins(_write(tmp_path, "uasm.c", src)) == 1


def test_all_three_spellings_counted_together(tmp_path):
    src = (
        'register int a asm("$2");\n'
        'register int b __asm("$3");\n'
        'register int c __asm__("$4");\n'
    )
    assert cfr.count_pins(_write(tmp_path, "mix.c", src)) == 3


def test_identifier_ending_in_asm_does_not_count(tmp_path):
    # A call to a helper whose name ends in `asm` is not a register pin;
    # the `\b` before the keyword and `[^;{}]` (no statement fusion) guard it.
    src = (
        'void k(void){\n'
        '    register int i;\n'
        '    i = foo_asm(3);\n'
        '    (void)i;\n'
        '}\n'
    )
    assert cfr.count_pins(_write(tmp_path, "helper.c", src)) == 0


def test_multiple_pins_across_lines(tmp_path):
    src = (
        'register int a __asm__("$2");\n'
        'register int b __asm__("$3");\n'
        'register int c __asm__("$4");\n'
    )
    assert cfr.count_pins(_write(tmp_path, "e.c", src)) == 3


def test_strip_comments_removes_block_and_line(tmp_path):
    text = "code1; /* block\n still block */ code2; // line comment\ncode3;"
    out = cfr.strip_comments(text)
    assert "block" not in out
    assert "line comment" not in out
    assert "code1" in out and "code2" in out and "code3" in out
