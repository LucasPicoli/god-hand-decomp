#!/usr/bin/env python3
"""Convert listed jump-table `.word .L<addr>` blob entries to raw words.

Companion of compile_units[].extern_jtbl (see config/jtbl_extern_words.txt
for the why). Run by scripts/resplat.sh after every splat split so the
conversion survives asm regeneration. Idempotent: already-raw entries are
left untouched; a listed entry that is missing entirely is an error (the
split moved or the address is stale).
"""
from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CONFIG = ROOT / "config" / "jtbl_extern_words.txt"


def main() -> int:
    if not CONFIG.exists():
        return 0
    converted = raw_already = 0
    entries: dict[Path, list[str]] = {}
    for ln in CONFIG.read_text().splitlines():
        ln = ln.split("#", 1)[0].strip()
        if not ln:
            continue
        path_s, addr = ln.split()
        entries.setdefault(ROOT / path_s, []).append(addr.upper().lstrip("0X").rjust(8, "0"))
    for path, addrs in entries.items():
        text = path.read_text()
        for addr in addrs:
            label_re = re.compile(r"^(\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/ \.word )\.L0*"
                                  + addr.lstrip("0") + r"$", re.MULTILINE)
            raw_line = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/ \.word 0x0*"
                                  + addr.lstrip("0") + r"$", re.MULTILINE)
            if label_re.search(text):
                text = label_re.sub(lambda m: m.group(1) + "0x" + addr.lower(),
                                    text, count=1)
                converted += 1
            elif raw_line.search(text):
                raw_already += 1
            else:
                print(f"apply_jtbl_extern_words: entry .L{addr} not found in {path}",
                      file=sys.stderr)
                return 1
        path.write_text(text)
    print(f"apply_jtbl_extern_words: {converted} converted, {raw_already} already raw")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
