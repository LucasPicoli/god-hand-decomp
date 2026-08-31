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
            # Handles both label spellings splat emits for in-function
            # targets: jump-table entries (`.word .L<addr>`) and
            # exception-region boundaries (`.word $LEH_<addr>`).
            label_re = re.compile(r"^(\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/ \.word )"
                                  r"(?:\.L|\$LEH_)0*"
                                  + addr.lstrip("0") + r"$", re.MULTILINE)
            # Converted entries are written back lowercase (`0x0026af5c`),
            # so the already-raw probe must match the hex case-blind.
            raw_line = re.compile(r"^\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/ \.word 0x0*(?i:"
                                  + addr.lstrip("0") + r")$", re.MULTILINE)
            if label_re.search(text):
                # EVERY occurrence, not the first. One arm label can fill several
                # table slots (func_00273230 repeats `.L002735FC` four times), and
                # a caller that lists the label ONCE -- which land_jtbl.py does,
                # because its append is idempotent -- then left the rest as
                # undefined `.L` references and the link failed. There is no case
                # where one occurrence must stay a label while another goes raw.
                text, n = label_re.subn(lambda m: m.group(1) + "0x" + addr.lower(),
                                        text)
                converted += n
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
