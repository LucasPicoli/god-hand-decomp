#!/usr/bin/env python3
"""Patch ee-as 2.10 so relaxation copies forward instead of calling memcpy.

Sibling of 01 and 02.  This fixes a host-dependent misassembly.

The bug:
  `md_convert_frag` (tc-mips.c) relaxes a macro frag by moving the second
  variant down over the first: `memcpy (fixptr - old, fixptr, new)`.  The two
  regions overlap whenever new > old.  ee-as is dynamically linked, so the
  call goes to the host glibc, which picks a copy routine from the buffer
  alignment.  Some of those routines copy backward, and a backward copy over
  an overlap repeats a word.

  Example: `lw $4,SYM($3)` at -G0 emits a gp-relative variant (8 bytes) and a
  `lui / addu / lw` variant (12 bytes).  A backward copy leaves
  `lw / addu / lw`, so retail's `lui a0,0x46` assembles as `lw a0,0x46(a0)`.
  Heap alignment moves with the length of the -o path and the -I paths, so
  the same .s assembles right in one checkout and wrong in another.  Found in
  SFD_GetFps (+0x54): bad for -o names of 12 to 24 characters in a bare
  tempdir, good otherwise.

What this changes (12 bytes at file offset 0x31DCC, VMA 0x8079DCC):
  before  89 d0 29 f0 53 52 50 e8 d8 f7 fc ff
          mov %edx,%eax ; sub %esi,%eax ; push %ebx ; push %edx ; push %eax ;
          call memcpy@plt
  after   56 89 d7 29 f7 89 d6 89 d9 f3 a4 5e
          push %esi ; mov %edx,%edi ; sub %esi,%edi ; mov %edx,%esi ;
          mov %ebx,%ecx ; rep movsb ; pop %esi

  The destination is always below the source (old >= 0), so a forward byte
  copy is correct for any overlap.  %edi is dead here (the epilogue pops it),
  %esi is saved around the copy, and the epilogue restores %esp from %ebp, so
  dropping the three pushes is safe.  The output no longer depends on glibc.

Idempotency contract (order-independent):
  * If the bytes at OFFSET already equal NEW_BYTES, log "already-applied" and
    exit 0.
  * Else if the whole-file sha256 == PRE_SHA256 (== 02's POST_SHA256) and the
    bytes at OFFSET equal OLD_BYTES, write NEW_BYTES, fsync, and confirm the
    new sha256 == POST_SHA256.
  * Else refuse (exit non-zero) and re-derive the constants.

setup_toolchain.sh and flake.nix run patches/ee-as/*.py in lexical order, so
01 and 02 apply first.  Standard library only; safe before the venv exists.
"""

from __future__ import annotations

import hashlib
import os
import sys
from pathlib import Path

# Resolve repo root from this file's location: patches/ee-as/<this>.py
ROOT = Path(__file__).resolve().parent.parent.parent
BINARY_PATH = ROOT / "compiler" / "linux" / "ee" / "gcc" / "bin" / "ee-as"

OFFSET = 0x31DCC
OLD_BYTES = bytes.fromhex("89d029f0535250e8d8f7fcff")
NEW_BYTES = bytes.fromhex("5689d729f789d689d9f3a45e")

# sha256(ee-as) BEFORE this patch == 02-fix-short-loop-pad's POST_SHA256.
PRE_SHA256 = "a512f211b4ce5facc1b19fbf115d6c944e6af5ba8cc52f1cef258e419806f6f8"
POST_SHA256 = "d6195c78ef181cfb35b6f6f5339c3ff90c534727f5151091a3b7dc55b5dbde12"

PATCH_NAME = "03-forward-copy-relax-frag"


def _sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def _read_at(path: Path, offset: int, n: int) -> bytes:
    with path.open("rb") as f:
        f.seek(offset)
        return f.read(n)


def _log(level: str, msg: str) -> None:
    colour = {"log": "34", "ok": "32", "warn": "33", "die": "31"}.get(level, "0")
    sys.stderr.write(f"\033[1;{colour}m[patches/ee-as/{PATCH_NAME}]\033[0m {msg}\n")


def main() -> int:
    if not BINARY_PATH.exists():
        _log("warn", f"ee-as not found at {BINARY_PATH}; skipping "
             "(setup_toolchain.sh extracts the tarball first).")
        return 0

    if _read_at(BINARY_PATH, OFFSET, len(NEW_BYTES)) == NEW_BYTES:
        _log("ok", f"already-applied (bytes at {OFFSET:#x})")
        return 0

    current_sha = _sha256(BINARY_PATH)
    if current_sha != PRE_SHA256:
        _log("die", f"refusing to patch: sha256({BINARY_PATH}) = {current_sha} "
             f"!= PRE_SHA256 ({PRE_SHA256}).  Expected 01 and 02 to have run "
             "first, or the ee-gcc tarball was bumped; re-derive and re-pin.")
        return 1

    if _read_at(BINARY_PATH, OFFSET, len(OLD_BYTES)) != OLD_BYTES:
        _log("die", f"refusing to patch: bytes at {OFFSET:#x} are not the "
             "memcpy call.  PRE_SHA256 matched, so OFFSET is wrong.")
        return 1

    _log("log", f"applying: {OFFSET:#x} memcpy call -> forward rep movsb")
    with BINARY_PATH.open("r+b") as f:
        f.seek(OFFSET)
        f.write(NEW_BYTES)
        f.flush()
        os.fsync(f.fileno())

    post_sha = _sha256(BINARY_PATH)
    if post_sha != POST_SHA256:
        _log("die", f"post-patch sha256 = {post_sha}, expected {POST_SHA256}; "
             "do not use this ee-as.")
        return 1

    _log("ok", f"patched (sha256={post_sha})")
    return 0


if __name__ == "__main__":
    sys.exit(main())
