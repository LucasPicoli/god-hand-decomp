#!/usr/bin/env python3
"""Patch ee-as 2.10 to use retail's R5900 short-loop *pad* length (4, not 5).

Sibling of 01-disable-short-loop-check.py.  Where 01 disables the assemble-
time short-loop *error*, this fixes the short-loop *pad count* so ee-as emits
byte-for-byte what the retail (SN ProDG era) assembler emitted.

What this changes (one byte):
  ee-as implements the R5900 "short loop" errata by padding a single-block
  backward-conditional loop so the number of instructions BEFORE the branch is
  at least a minimum.  ee-as uses a minimum of 5 (`nops = 5 - pre_count`);
  retail used 4.  So any loop with pre_count == 4 gets ONE extra nop from
  ee-as (a +4-byte over-pad) and can never match retail.

  At file offset 0x20ACD the binary holds the immediate of
  `mov [ebp-0x18], 5`  (bytes  c7 45 e8 05 00 00 00,  unique in the binary),
  the R5900 short-loop minimum pre-branch length.  Flipping the immediate
  0x05 -> 0x04 makes ee-as's errata pad identical to retail's.

  This unblocks the whole errata-pad class (~543 single-block backward loops
  at pre<=4 across the binary; proven end-to-end on func_001268F0 and
  func_002BB040, which go 44B [+1 nop] -> exact retail 40B).  It is regression-
  safe: a function that ALREADY matches under min-5 must have pre_count >= 5 in
  every loop (zero pad either way), so min-4 cannot change its bytes — verified
  by a full retail-rebuild sha256 hold (the gate this patch is committed under)
  plus per-function spot-checks of matched loop-bearing TUs.  Not the same as
  01 (which only kills the *error*, not the pad count); the SN-as-via-wibo and
  modern-binutils routes were both refuted (they pad to 5 / emit wrong insns).

Idempotency contract (byte-level, order-independent):
  * If the byte at OFFSET is already NEW_BYTE, log "already-applied" and exit 0.
  * Else if the whole-file sha256 == PRE_SHA256 (== 01's POST_SHA256; i.e. 01
    has run and 02 has not) AND the byte at OFFSET is EXPECTED_PRE_BYTE, flip
    it, fsync, and confirm the new sha256 == POST_SHA256.
  * Else refuse (exit non-zero): either 01 has not run yet (ordering bug) or
    the ee-gcc tarball was bumped and the constants must be re-pinned.

setup_toolchain.sh runs patches/ee-as/*.py in lexical order, so 01 applies
before 02.  Standard library only; safe before the venv exists.
"""

from __future__ import annotations

import hashlib
import os
import sys
from pathlib import Path

# Resolve repo root from this file's location: patches/ee-as/<this>.py
ROOT = Path(__file__).resolve().parent.parent.parent
BINARY_PATH = ROOT / "compiler" / "linux" / "ee" / "gcc" / "bin" / "ee-as"

# File offset of the `mov [ebp-0x18],5` immediate (VMA 0x8068ACD): the R5900
# short-loop minimum pre-branch length.
OFFSET = 0x20ACD
EXPECTED_PRE_BYTE = 0x05  # min pre-branch length 5 (ee-as default)
NEW_BYTE = 0x04  # retail's min pre-branch length 4

# sha256(ee-as) BEFORE this patch == 01-disable-short-loop-check's POST_SHA256
# (01 applied, 02 not).  AFTER == this patch applied on top of 01.
PRE_SHA256 = "fa549d510cd2644671f2deef9128969b981833662b4a13b06ea64588359e780b"
POST_SHA256 = "a512f211b4ce5facc1b19fbf115d6c944e6af5ba8cc52f1cef258e419806f6f8"

PATCH_NAME = "02-fix-short-loop-pad"


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
    with path.open("r+b") as f:
        f.seek(offset)
        f.write(bytes([value]))
        f.flush()
        os.fsync(f.fileno())


def _log(level: str, msg: str) -> None:
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

    # Byte-level idempotency FIRST (order-independent, survives re-runs).
    if _read_byte_at(BINARY_PATH, OFFSET) == NEW_BYTE:
        _log("ok", f"already-applied (byte at {OFFSET:#x} is {NEW_BYTE:#04x})")
        return 0

    current_sha = _sha256(BINARY_PATH)

    if current_sha != PRE_SHA256:
        _log(
            "die",
            f"refusing to patch: sha256({BINARY_PATH}) = {current_sha} "
            f"!= PRE_SHA256 ({PRE_SHA256}).  Expected 01-disable-short-loop-"
            "check to have run first (its POST == our PRE).  Either the patch "
            "order is wrong or the ee-gcc tarball was bumped; re-derive and "
            "re-pin OFFSET / EXPECTED_PRE_BYTE / NEW_BYTE / PRE_SHA256 / "
            "POST_SHA256.",
        )
        return 1

    pre_byte = _read_byte_at(BINARY_PATH, OFFSET)
    if pre_byte != EXPECTED_PRE_BYTE:
        _log(
            "die",
            f"refusing to patch: byte at offset {OFFSET:#x} is "
            f"{pre_byte:#04x}, expected {EXPECTED_PRE_BYTE:#04x}.  "
            "PRE_SHA256 matched, so OFFSET is wrong.  Re-derive and re-pin.",
        )
        return 1

    _log(
        "log",
        f"applying: offset {OFFSET:#x} byte {EXPECTED_PRE_BYTE:#04x} -> "
        f"{NEW_BYTE:#04x}; R5900 short-loop min pre-branch length 5 -> 4 "
        "(retail pad fidelity)",
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
