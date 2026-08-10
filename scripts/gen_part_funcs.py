#!/usr/bin/env python3
"""Generate ``progress/unit_part_funcs.json`` — the carved-monolith fragment
manifest consumed by ``scripts/gen_unit_names.py``.

``compile.py::maybe_carve`` splits the monolithic ``asm/cod/000000.s`` into
``N+1`` fragments around the carve points and writes them as
``build/asm/cod/000000.part{idx}.s`` (``idx`` = position in the
``split_monolithic`` fragment list, in retail VMA order, no filtering).  Each
fragment is the *gap* between two carves, so it holds zero, one, or several
un-carved functions.

decomp.dev names a unit by its objdiff ``name``, so a fragment shows as the
opaque ``cod/000000.partN``.  This tool reproduces the build's exact split (same
``split_monolithic`` + the same ``Config.carved_funcs`` carve name-list) and
records, per part unit, the start *vaddrs* of the functions inside it — not
their names.  ``scripts/gen_unit_names.py`` resolves those vaddrs to names via
the committed symbol table, so the manifest never bakes in a name absent from
public source, and folders the fragment under its primary function's subsystem.

Run locally (needs the gitignored ``asm/cod/000000.s``); the output is committed
like ``progress/report.json`` so the toolchain-free publish path can consume it.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path
from types import SimpleNamespace

_ROOT = Path(__file__).resolve().parent.parent
# ``from scripts.carver import ...`` needs the repo root (parent of ``scripts/``)
# on ``sys.path``.  Run as ``python3 scripts/gen_part_funcs.py`` Python prepends
# only ``scripts/`` itself, so ``scripts`` would be undiscoverable; insert ROOT.
# (Same blessed pattern as scripts/auto_carve_func.py.)
if str(_ROOT) not in sys.path:
    sys.path.insert(0, str(_ROOT))

from scripts.carver import CarveSchema, _GLABEL_RE

# Instruction line in a splat-disassembled fragment:
#   ``    /* FILE_OFF HEX_VRAM HEX_BYTES */  insn ...``
# The middle hex field is the runtime VRAM; the first instruction after a
# ``glabel`` is the function's start address.
_VRAM_INSN_RE = re.compile(
    r"^\s*/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]+)\s+[0-9A-Fa-f]+\s*\*/"
)

# The only monolithic carved out of so far (matches compile.py::maybe_carve).
_MONOLITHIC_REL = Path("asm") / "cod" / "000000.s"
_UNIT_PREFIX = "asm/cod/000000"


def extract_funcs(fragment_text: str) -> list[str]:
    """Return the start vaddr of every function in *fragment_text*, in source
    (VMA) order, as ``0x``-prefixed 8-hex strings.  The vaddr is the first
    instruction's VRAM after each ``glabel``.

    Only the address is recorded — names are resolved downstream from the
    committed symbol table, so no name is baked into the manifest.  A ``glabel``
    with no following ``/* off vram bytes */`` instruction (e.g. a data-only
    label) has no derivable start address and is dropped.
    """
    lines = fragment_text.splitlines()
    n = len(lines)
    out: list[str] = []
    for i, line in enumerate(lines):
        if not _GLABEL_RE.match(line):
            continue
        for j in range(i + 1, n):
            if _GLABEL_RE.match(lines[j]):
                break  # next function with no insn between -> drop this label
            vm = _VRAM_INSN_RE.match(lines[j])
            if vm:
                out.append(f"0x{int(vm.group(1), 16):08X}")
                break
    return out


def filter_carved_funcs(raw: list) -> list[dict]:
    """Replicate ``compile.py``'s ``Config.carved_funcs``: keep every entry
    that is not a documentation record.

    The two filters must stay identical or the fragment split — and every
    ``partN`` index — drifts from the real ``objdiff.json``.  Ticket 36
    changed the shared rule: ``_``-prefixed C++ operator mangles such as
    ``__ls__7ostreamc`` ARE carved by the build now, so they are kept here
    too.  The predicate itself lives in ``scripts.carver.is_doc_record``;
    this function must never re-spell it.
    """
    return [e for e in raw if not CarveSchema.is_doc_record(e)]


def build_manifest(fragments: list[str], unit_prefix: str) -> dict[str, list[str]]:
    """Map each fragment to its ``<unit_prefix>.partN`` unit name (N = list
    index, matching ``compile.py``'s ``enumerate(fragments)``), with the start
    vaddrs of the functions it contains."""
    return {
        f"{unit_prefix}.part{idx}": extract_funcs(frag)
        for idx, frag in enumerate(fragments)
    }


def generate(root: Path = _ROOT) -> dict[str, list[dict]]:
    """Reproduce the build-time carve split from committed config + the local
    monolithic asm, and return the ``{partN unit: [funcs]}`` manifest."""
    monolithic_text = (root / _MONOLITHIC_REL).read_text()
    cfg = json.loads((root / "compile_config.json").read_text())
    carved = filter_carved_funcs(cfg.get("carved_funcs", []))
    entries = CarveSchema.parse_entries(SimpleNamespace(carved_funcs=carved))
    names = [e.name for e in entries]
    fragments, _carved, _ranges = CarveSchema.split_monolithic(monolithic_text, names)
    return build_manifest(fragments, _UNIT_PREFIX)


def main() -> None:
    ap = argparse.ArgumentParser(description="carved-monolith fragment manifest")
    ap.add_argument("--root", type=Path, default=_ROOT)
    args = ap.parse_args()
    manifest = generate(args.root)
    out_path = args.root / "progress" / "unit_part_funcs.json"
    out_path.write_text(json.dumps(manifest, indent=2, sort_keys=True) + "\n")
    non_empty = sum(1 for v in manifest.values() if v)
    print(
        f"wrote {out_path} ({len(manifest)} part units, "
        f"{non_empty} with functions)"
    )


if __name__ == "__main__":
    main()
