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

# MIPS ECOFF symbolic-debug header, carried in `.mdebug`.
_HDRR_MAGIC = 0x7009
# Offsets of the HDRR fields we need, from the start of the header. HDRR is
# `short magic; short vstamp;` then 23 longs; isymMax is the 8th, cbSymOffset
# the 9th, iextMax the 22nd and cbExtOffset the 23rd — i.e. 4 + n*4.
_HDRR_ISYMMAX = 0x20
_HDRR_CBSYMOFFSET = 0x24
_HDRR_IEXTMAX = 0x58
_HDRR_CBEXTOFFSET = 0x5C
# sizeof(struct ext_ext): es_flags[2], es_ifd[2], then a 12-byte SYMR.
_EXTR_SIZE = 16
_EXTR_SYMR_OFF = 4
_SYMR_SIZE = 12
# SYMR's trailing word packs `st:6, sc:5, reserved:1, index:20` (LSB first).
_SYMR_BITS_OFF = 8
_SYMR_RESERVED_BIT = 1 << 11
# Only three bits of es_flags are defined (jmptbl, cobol_main, weakext); the
# remaining 13 are reserved and must be zero.
_EXTR_FLAG_MASK = 0x0007

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

    changed |= _scrub_mdebug_ext_flags(data, e_shoff, e_shentsize, e_shnum)

    if changed:
        obj.write_bytes(bytes(data))
    return changed


def _scrub_mdebug_ext_flags(data: bytearray, e_shoff: int, e_shentsize: int,
                            e_shnum: int) -> bool:
    """Zero the uninitialised reserved bits of `.mdebug`'s EXTR flag words.

    ps2eeas leaves ``es_flags`` uninitialised on some external-symbol records,
    so the same input assembles to two different objects across runs: the
    field holds a stale heap value (observed 0xB1C0 vs 0xC1A0 on consecutive
    builds of the same TU, both shifted by a constant 0xFE0 — an allocator
    base, not data).  Nothing downstream reads it: `.mdebug` is stripped from
    the linked ELF, which is byte-identical to retail either way.  But the
    ``expected/build/<u>.o`` gate compares whole objects, so a TU on this
    route would flap between two hashes forever.

    Evidence the correct value is zero: in the same object ps2eeas writes 0
    into this field for some records and garbage into others, and the adjacent
    ``es_ifd`` is stable across runs.  Only the three defined bits (jmptbl,
    cobol_main, weakext) are preserved — a real weak external keeps its bit.

    The same records also carry an uninitialised SYMR ``reserved`` bit, which
    is what remained after the flag word was fixed: assembling one TU eight
    times gave two hashes differing in exactly one byte, and the only bit that
    moved was ``reserved`` (``st``/``sc``/``index`` all stable).  It is defined
    as reserved and must be zero, so clearing it is a correction rather than a
    normalisation.  Cleared in the local symbol table too — the same SYMR
    layout, the same spec rule — so the flap cannot resurface there on some
    other TU; only the external table was ever measured unstable.
    """
    changed = False

    def _clear_reserved(off: int) -> bool:
        """Zero the SYMR reserved bit of the record whose SYMR starts at *off*."""
        pos = off + _SYMR_BITS_OFF
        if pos + 4 > len(data):
            return False
        bits, = struct.unpack_from("<I", data, pos)
        if bits & _SYMR_RESERVED_BIT:
            struct.pack_into("<I", data, pos, bits & ~_SYMR_RESERVED_BIT)
            return True
        return False

    for i in range(e_shnum):
        sh = e_shoff + i * e_shentsize
        sh_off, = struct.unpack_from("<I", data, sh + _SH_OFFSET)
        sh_size, = struct.unpack_from("<I", data, sh + _SH_SIZE)
        if sh_size < 0x60 or sh_off + 2 > len(data):
            continue
        magic, = struct.unpack_from("<H", data, sh_off)
        if magic != _HDRR_MAGIC:
            continue
        iext_max, = struct.unpack_from("<i", data, sh_off + _HDRR_IEXTMAX)
        cb_ext, = struct.unpack_from("<i", data, sh_off + _HDRR_CBEXTOFFSET)
        if iext_max > 0 and cb_ext > 0:
            for k in range(iext_max):
                off = cb_ext + k * _EXTR_SIZE
                if off + _EXTR_SIZE > len(data):
                    break
                flags, = struct.unpack_from("<H", data, off)
                keep = flags & _EXTR_FLAG_MASK
                if flags != keep:
                    struct.pack_into("<H", data, off, keep)
                    changed = True
                changed |= _clear_reserved(off + _EXTR_SYMR_OFF)
        isym_max, = struct.unpack_from("<i", data, sh_off + _HDRR_ISYMMAX)
        cb_sym, = struct.unpack_from("<i", data, sh_off + _HDRR_CBSYMOFFSET)
        if isym_max > 0 and cb_sym > 0:
            for k in range(isym_max):
                off = cb_sym + k * _SYMR_SIZE
                if off + _SYMR_SIZE > len(data):
                    break
                changed |= _clear_reserved(off)
    return changed


if __name__ == "__main__":  # pragma: no cover - operator convenience
    import sys
    for arg in sys.argv[1:]:
        p = Path(arg)
        print(f"{p}: {'patched' if repair_symtab_info(p) else 'already valid'}")
