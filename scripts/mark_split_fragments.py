#!/usr/bin/env python3
"""Turn splat's false function splits into symbol-less fragments.

splat starts a new function at every non-nop word after a `jr`/`j` epilogue
and its alignment pad. About 700 such blocks in `asm/cod/000000.s` are not
functions: they hold a few stray words (mostly `addiu $sp,$sp,N`, a store,
each followed by a `nop`), no jump, branch or call, and nothing in the binary
references them. No C body can own them, and their `glabel` made objdiff
count each one as an open function.

A block becomes a fragment when all of these hold:
  * it has at least one non-nop word and no control transfer
    (j, jr, jal, jalr, any branch, eret, syscall, break);
  * the block before it ends in `jr` or `j` plus its delay slot;
  * its name appears nowhere else in asm/ (no call, jump-table or pointer).

The rewrite drops the `nonmatching` line and swaps `glabel`/`endlabel` for
`fragment`/`endfragment` (include/macro.inc), which emit no symbol. The
words still assemble in place, so the ELF is unchanged. The carver treats a
fragment as a block boundary, so a carved neighbour never swallows it.

Run after every `splat split` (scripts/resplat.sh does). Idempotent.
Exit 0 = rewrote or found already-marked fragments, 2 = examined nothing.
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MONOLITH = ROOT / "asm/cod/000000.s"

_GLABEL = re.compile(r"^glabel (\S+)$")
_ENDLABEL = re.compile(r"^endlabel (\S+)$")
_NONMATCHING = re.compile(r"^nonmatching (\S+)(, \S+)?$")
_INSN = re.compile(r"/\* \w+ \w{8} \w{8} \*/\s+(\S+)")
_CONTROL = {"j", "jr", "jal", "jalr", "eret", "syscall", "break"}


def _ops(lines: list[str], start: int, end: int) -> list[str]:
    return [m.group(1) for ln in lines[start:end] if (m := _INSN.search(ln))]


def _is_control(op: str) -> bool:
    return op in _CONTROL or op.startswith("b")


def find_fragments(lines: list[str], other_text: str) -> list[tuple[int, int, str]]:
    """Return (glabel_line, endlabel_line, name) for each fragment block."""
    blocks = []  # (glabel_idx, endlabel_idx, name)
    for i, ln in enumerate(lines):
        m = _GLABEL.match(ln)
        if not m:
            continue
        name = m.group(1)
        for k in range(i + 1, len(lines)):
            em = _ENDLABEL.match(lines[k])
            if em and em.group(1) == name:
                blocks.append((i, k, name))
                break
    counts: dict[str, int] = {}
    for tok in re.findall(r"[A-Za-z_][\w.$]*", other_text):
        counts[tok] = counts.get(tok, 0) + 1
    out = []
    for n, (g, e, name) in enumerate(blocks):
        ops = _ops(lines, g, e)
        if not ops or all(o == "nop" for o in ops) or any(map(_is_control, ops)):
            continue
        if n == 0:
            continue
        prev = _ops(lines, blocks[n - 1][0], blocks[n - 1][1])
        if len(prev) < 2 or prev[-2] not in ("jr", "j"):
            continue
        # own glabel + endlabel + nonmatching = 3 mentions in the monolith
        if counts.get(name, 0) > 3:
            continue
        out.append((g, e, name))
    return out


def rewrite(lines: list[str], frags: list[tuple[int, int, str]]) -> list[str]:
    drop = set()
    lines = list(lines)
    for g, e, name in frags:
        for j in range(g - 1, max(g - 4, -1), -1):
            m = _NONMATCHING.match(lines[j])
            if m and m.group(1) == name:
                drop.add(j)
                break
        lines[g] = f"fragment {name}"
        lines[e] = f"endfragment {name}"
    return [ln for j, ln in enumerate(lines) if j not in drop]


def main() -> int:
    text = MONOLITH.read_text()
    lines = text.split("\n")
    other = text + "".join(
        p.read_text(errors="replace")
        for p in sorted((ROOT / "asm").rglob("*.s"))
        if p != MONOLITH
    )
    frags = find_fragments(lines, other)
    already = sum(1 for ln in lines if ln.startswith("fragment "))
    if frags:
        MONOLITH.write_text("\n".join(rewrite(lines, frags)))
    nbytes = sum(len(_ops(lines, g, e)) * 4 for g, e, _ in frags)
    print(f"mark_split_fragments: {len(frags)} rewritten / {nbytes} B, "
          f"{already} already marked")
    return 0 if frags or already else 2


if __name__ == "__main__":
    sys.exit(main())
