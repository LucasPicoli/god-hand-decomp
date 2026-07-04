#!/usr/bin/env python3
"""Patch ee-as 2.10 to disable the R5900 short-loop assemble-time check.

This follows the project's policy of patching vendored toolchain
binaries when the alternative is significantly more invasive.

What this changes (one byte):
  At file offset 0x20f54 the ee-as binary contains a `je` (0x74)
  immediately after `cmpl $0x0, 0x80e8888` (= `mips_opts.noreorder`).
  That conditional jump is the *skip-error* exit from the R5900 short-
  loop errata check at VMA 0x8068f4d / `append_insn+0x5ef`: when
  noreorder == 0 the check is skipped, otherwise ee-as raises the
  "problematic short loop for Emotion Engine in noreorder section"
  build-time error.  Our INCLUDE_ASM carve preamble emits `.set
  noreorder` by design (see include/include_asm.h), so any short
  carve below the threshold trips the gate.

  Flipping the byte from 0x74 (`je`) to 0xeb (`jmp`) makes the
  skip-error path *always* taken — the short-loop check is dead.
  Byte output for accepted inputs is unchanged (empirically verified
  by a full retail-rebuild sha256 hold).

Idempotency contract:
  * If the file's sha256 already equals POST_SHA256, we log
    "already-applied" and exit 0 without writing.
  * Else if it equals PRE_SHA256, we verify the byte at OFFSET is
    EXPECTED_PRE_BYTE, flip it to NEW_BYTE, fsync, and confirm the
    new sha256 == POST_SHA256.
  * Else we refuse to apply (exit non-zero with a named error).
    This is the "someone bumped the ee-gcc tarball" branch: the
    patch must be re-derived and the sha256s re-pinned.

The script uses only the Python standard library; it's safe to run
before the project venv exists.
"""

from __future__ import annotations

import hashlib
import os
import sys
from pathlib import Path

# Resolve repo root from this file's location: patches/ee-as/<this>.py
ROOT = Path(__file__).resolve().parent.parent.parent
BINARY_PATH = ROOT / "compiler" / "linux" / "ee" / "gcc" / "bin" / "ee-as"

# File offset (within ee-as) of the `je` opcode whose flip we own.
# VMA 0x8068f54 in the ee-as ELF maps to file offset 0x20f54.
OFFSET = 0x20F54
EXPECTED_PRE_BYTE = 0x74  # `je rel8`
NEW_BYTE = 0xEB  # `jmp rel8` (unconditional; preserves the 1-byte size)

# sha256(ee-as) derived from the pinned EE_GCC_SHA256 tarball
# (decompme/compilers ee-gcc2.96.tar.xz; see scripts/setup_toolchain.sh
# EE_GCC_SHA256).  Re-derive both constants whenever the tarball is bumped.
PRE_SHA256 = "b8cfdb6ecb6931642914020f92a62e653378f57230eed4895f69afa050d47b5e"
POST_SHA256 = "fa549d510cd2644671f2deef9128969b981833662b4a13b06ea64588359e780b"

PATCH_NAME = "01-disable-short-loop-check"


def _sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def _read_byte_at(path: Path, offset: int) -> int:
    with path.open("rb") as f:
        f.seek(offset)
        b = f.read(1)
    if len(b) != 1:
        raise RuntimeError(
            f"{path}: short read at offset {offset:#x} (file truncated?)"
        )
    return b[0]


def _write_byte_at(path: Path, offset: int, value: int) -> None:
    # Open r+b so we leave every other byte exactly as-is.  fsync after
    # the write so a crash between patch and the post-sha256 verify
    # cannot leave the file in an in-between state on disk.
    with path.open("r+b") as f:
        f.seek(offset)
        f.write(bytes([value]))
        f.flush()
        os.fsync(f.fileno())


def _log(level: str, msg: str) -> None:
    # Match scripts/setup_toolchain.sh's coloured log format so the
    # output sits cleanly under that block.
    colour = {"log": "34", "ok": "32", "warn": "33", "die": "31"}.get(level, "0")
    sys.stderr.write(f"\033[1;{colour}m[patches/ee-as/{PATCH_NAME}]\033[0m {msg}\n")


def main() -> int:
    if not BINARY_PATH.exists():
        _log(
            "warn",
            f"ee-as not found at {BINARY_PATH} — skipping (setup_toolchain.sh "
            "must extract the ee-gcc tarball before this patch can apply).",
        )
        return 0  # not an error: setup_toolchain.sh handles ordering.

    # Byte-level idempotency FIRST: if OUR byte is already flipped, this patch
    # is applied — regardless of whether a LATER patch (e.g.
    # 02-fix-short-loop-pad) has since changed the whole-file sha256. Without
    # this, re-running setup_toolchain.sh after 02 applied would make the
    # whole-file check below see neither PRE nor POST and wrongly die.
    if _read_byte_at(BINARY_PATH, OFFSET) == NEW_BYTE:
        _log("ok", f"already-applied (byte at {OFFSET:#x} is {NEW_BYTE:#04x})")
        return 0

    current_sha = _sha256(BINARY_PATH)

    if current_sha == POST_SHA256:
        _log("ok", f"already-applied (sha256={POST_SHA256})")
        return 0

    if current_sha != PRE_SHA256:
        _log(
            "die",
            f"refusing to patch: sha256({BINARY_PATH}) = {current_sha} "
            f"matches neither PRE_SHA256 ({PRE_SHA256}) nor POST_SHA256 "
            f"({POST_SHA256}).  This usually means the ee-gcc tarball was "
            "bumped; re-derive OFFSET / EXPECTED_PRE_BYTE / NEW_BYTE / "
            "PRE_SHA256 / POST_SHA256 and re-pin.",
        )
        return 1

    pre_byte = _read_byte_at(BINARY_PATH, OFFSET)
    if pre_byte != EXPECTED_PRE_BYTE:
        _log(
            "die",
            f"refusing to patch: byte at offset {OFFSET:#x} is "
            f"{pre_byte:#04x}, expected {EXPECTED_PRE_BYTE:#04x}.  "
            "PRE_SHA256 matched, so the binary is the pinned ee-as — "
            "this means OFFSET is wrong.  Re-derive and re-pin.",
        )
        return 1

    _log(
        "log",
        f"applying: offset {OFFSET:#x} byte {EXPECTED_PRE_BYTE:#04x} "
        f"(je) -> {NEW_BYTE:#04x} (jmp); disables R5900 short-loop "
        "errata check",
    )
    _write_byte_at(BINARY_PATH, OFFSET, NEW_BYTE)

    post_sha = _sha256(BINARY_PATH)
    if post_sha != POST_SHA256:
        _log(
            "die",
            f"post-patch sha256 = {post_sha}, expected {POST_SHA256}.  "
            "Filesystem corruption or a non-byte-flip side effect; do "
            "not use this ee-as.",
        )
        return 1

    _log("ok", f"patched (sha256={post_sha})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
