import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

from scripts.carver import _split_monolithic
from scripts.mark_split_fragments import find_fragments, rewrite

MONO = """\
.include "macro.inc"

.set noat
.set noreorder

.section .text, "ax"
.align 3
nonmatching f_real, 0x8

glabel f_real
    /* 0 00100000 0800E003 */  jr         $ra
    /* 4 00100004 1000BD27 */   addiu     $sp, $sp, 0x10
endlabel f_real

.align 3
nonmatching func_00100008, 0x4

glabel func_00100008
    /* 8 00100008 1000BD27 */  addiu      $sp, $sp, 0x10
endlabel func_00100008
    /* C 0010000C 00000000 */  nop

.align 3
nonmatching func_00100010, 0x4

glabel func_00100010
    /* 10 00100010 0800E003 */  jr         $ra
    /* 14 00100014 00000000 */   nop
endlabel func_00100010
"""


def _frags(text, other=""):
    lines = text.split("\n")
    return lines, find_fragments(lines, text + other)


def test_stray_words_after_a_return_are_a_fragment():
    _, frags = _frags(MONO)
    assert [n for _, _, n in frags] == ["func_00100008"]


def test_a_referenced_block_stays_a_function():
    _, frags = _frags(MONO, "    .word func_00100008\n")
    assert frags == []


def test_rewrite_drops_the_symbol_and_is_idempotent():
    lines, frags = _frags(MONO)
    out = "\n".join(rewrite(lines, frags))
    assert "fragment func_00100008" in out
    assert "endfragment func_00100008" in out
    assert "glabel func_00100008" not in out
    assert "nonmatching func_00100008" not in out
    assert _frags(out)[1] == []


def test_carving_the_previous_function_leaves_the_fragment_in_place():
    lines, frags = _frags(MONO)
    out = "\n".join(rewrite(lines, frags))
    fragments, carved, _ = _split_monolithic(out, ["f_real"])
    assert "00100008" not in carved["f_real"]
    assert "fragment func_00100008" in fragments[1]
