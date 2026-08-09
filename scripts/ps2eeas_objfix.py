#!/usr/bin/env python3
"""Repair the one malformed field in a ``ps2eeas.exe`` object file.

SN Systems' ``ps2eeas`` writes ``.symtab``'s ``sh_info`` as the index of the
first symbol *it* considers global, but it emits ``gcc2_compiled.`` and
``__gnu_compiled_c`` as ``STB_LOCAL`` symbols *after* that index.  The ELF spec
defines ``sh_info`` on a symbol table as "one greater than the symbol table
index of the last local symbol", so the object is malformed and GNU ``ld``
refuses it outright::

    .symtab local symbol at index 2 (>= sh_info of 2)
    error adding symbols: bad value

The section *contents* are fine — this is a section-header metadata bug, and it
is why the route could be scored (the scorer reads ``.text.<name>`` straight
out of the object) but not linked.  Recomputing ``sh_info`` from the symbols'
own ``STB_*`` bindings is a lossless repair: no byte of any section moves.

Precedent: ``scripts/mipsel-as-wrap.py`` already patches the ``gnu`` route's
object header (``EF_MIPS_ABI`` back to ``eabi64``) for the same class of reason
— the assembler is right about the code and wrong about the metadata.

Verified against ee-as: for the same ``.s``, ee-as emits the same symbols with
``sh_info`` pointing one past the last local, which is what this restores.
"""
from __future__ import annotations

import struct
from pathlib import Path

SHT_SYMTAB = 2
STB_LOCAL = 0

# Elf32_Shdr field offsets.
_SH_TYPE = 0x04
_SH_OFFSET = 0x10
_SH_SIZE = 0x14
_SH_INFO = 0x1C
_SH_ENTSIZE = 0x24

# Elf32_Sym field offsets.
_ST_INFO = 0x0C


class ObjFixError(Exception):
    """The object is not the shape this repair knows how to reason about."""


def repair_symtab_info(obj: Path) -> bool:
    """Recompute ``.symtab``'s ``sh_info`` in *obj* from symbol bindings.

    Returns True when a field was rewritten, False when the object was already
    well-formed.  Raises :class:`ObjFixError` rather than writing anything if
    the symbol table is not sorted locals-first — in that case ``sh_info``
    alone cannot describe it and a silent patch would produce a *differently*
    broken object.
    """
    data = bytearray(obj.read_bytes())
    if data[:4] != b"\x7fELF":
        raise ObjFixError(f"{obj}: not an ELF file")
    if data[4] != 1 or data[5] != 1:
        raise ObjFixError(f"{obj}: expected little-endian ELF32")

    e_shoff, = struct.unpack_from("<I", data, 0x20)
    e_shentsize, = struct.unpack_from("<H", data, 0x2E)
    e_shnum, = struct.unpack_from("<H", data, 0x30)

    changed = False
    for i in range(e_shnum):
        sh = e_shoff + i * e_shentsize
        sh_type, = struct.unpack_from("<I", data, sh + _SH_TYPE)
        if sh_type != SHT_SYMTAB:
            continue
        sh_off, = struct.unpack_from("<I", data, sh + _SH_OFFSET)
        sh_size, = struct.unpack_from("<I", data, sh + _SH_SIZE)
        sh_entsize, = struct.unpack_from("<I", data, sh + _SH_ENTSIZE)
        sh_info, = struct.unpack_from("<I", data, sh + _SH_INFO)
        if sh_entsize == 0:
            raise ObjFixError(f"{obj}: .symtab has entsize 0")
        nsyms = sh_size // sh_entsize

        bindings = [data[sh_off + n * sh_entsize + _ST_INFO] >> 4
                    for n in range(nsyms)]
        first_global = next((n for n, b in enumerate(bindings)
                             if b != STB_LOCAL), nsyms)
        # Everything from first_global on must be non-local, or the table is
        # not sorted and no single sh_info describes it.
        if any(b == STB_LOCAL for b in bindings[first_global:]):
            raise ObjFixError(
                f"{obj}: .symtab is not sorted locals-first; refusing to "
                f"patch sh_info (would produce a differently malformed object)"
            )
        if sh_info != first_global:
            struct.pack_into("<I", data, sh + _SH_INFO, first_global)
            changed = True

    if changed:
        obj.write_bytes(bytes(data))
    return changed


if __name__ == "__main__":  # pragma: no cover - operator convenience
    import sys
    for arg in sys.argv[1:]:
        p = Path(arg)
        print(f"{p}: {'patched' if repair_symtab_info(p) else 'already valid'}")
