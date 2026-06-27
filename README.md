# god-hand-decomp

[![Code](https://decomp.dev/LucasPicoli/god-hand-decomp.svg?mode=shield&label=Code&measure=matched_code_percent)](https://decomp.dev/LucasPicoli/god-hand-decomp)
[![Functions](https://decomp.dev/LucasPicoli/god-hand-decomp.svg?mode=shield&label=Functions&measure=matched_functions)](https://decomp.dev/LucasPicoli/god-hand-decomp)

Matching decompilation of **God Hand** (PS2, 2006, Clover Studio / Capcom). The
goal is to rewrite the game's machine code as C/C++ that, compiled with the
original toolchain, reproduces the NTSC-U retail master (`SLUS-21503`)
**byte-for-byte** from a single source tree.

| key | serial | region | disc | boot ELF | status |
|-----|--------|--------|------|----------|--------|
| `us` | SLUS-21503 | NTSC-U | 1.00 | `SLUS_215.03` | matching (primary) |

The build is **byte-identical to the retail boot ELF** (`elf_sha256` in
[`config/versions.json`](./config/versions.json)) and carries the active C
decompilation. An empty carve already reproduces retail; as functions are
decompiled it stays byte-identical, so 100% matched code means a byte-identical
ELF.

## Goal

Produce C/C++ that compiles back into a byte-identical `SLUS_215.03` plus
matching `.rel` overlays, using the original PS2 toolchain (ee-gcc 2.96 + the
SN linker + dvp-as). The sole aim of this project is to decompile the game;
there is no port.

## How it works

This is a **matching** decompilation: the bar is reproducing the *exact bytes*
the original compiler emitted, not writing equivalent code.

- **splat** disassembles the retail boot ELF into one monolithic assembly file
  (`asm/cod/000000.s`), with the retail bytes embedded in each instruction
  comment.
- Every function starts as raw assembly `#include`d from C via `INCLUDE_ASM(...)`.
  Functions are rewritten to C one at a time — **carving** — and the
  `INCLUDE_ASM` line is replaced by real C once it matches.
- **objdiff** scores each compiled unit against the retail disassembly. A
  function is *matched* when its compiled `.text` is identical down to register
  allocation and instruction order.
- One ratchet drives everything: every commit keeps the full ELF byte-identical
  to retail, and `matched_code_percent` only ever goes up.

```
┌─────────────────────────────────────────────────────────────────┐
│  splat + ee-gcc 2.96 + dvp-as + ee-ld + objdiff + asm-differ    │
│  ground truth: disc_extract/SLUS_215.03 (sha256 1742f95b…f3cd)  │
└─────────────────────────────────────────────────────────────────┘
```

Inspirations:
- [decomp.me](https://decomp.me) — the collaborative matching-scratch model
- [recvx-decomp](https://github.com/fmil95/recvx-decomp) — a PS2 matching-decomp
  template from the same era and publisher

## Layout

```
.
├── God Hand (USA).iso       your own dump, gitignored
├── disc_extract/            extracted boot ELF + tables, gitignored
├── config/
│   ├── SLUS_215.03.yaml      splat config
│   ├── SLUS_215.03.lcf       ee-ld linker script
│   ├── symbol_addrs.txt      name → address map (seeded from Ghidra)
│   ├── reloc_addrs.txt
│   └── versions.json         per-version serials + retail hashes
├── src/                     decompiled C/C++
├── include/                 shared headers (sce/, cri/, capcom/, gh/)
├── asm/                     splat output, INCLUDE_ASM'd from src (gitignored)
├── bin/                     splat data dumps (gitignored)
├── expected/                disassembled-from-retail .o files (objdiff target, gitignored)
├── build/                   compile output (.o, .elf, .map), gitignored
├── tools/                   splat, m2c, asm-differ, objdiff, decomp-permuter (provisioned by setup)
├── scripts/                 build entry helpers + utilities
├── compile.py               top-level build entry point
└── objdiff.json             objdiff project (per-.o scoring)
```

## Setup

You need your own legally-dumped NTSC-U disc. **No game data ships in this
repo** and none should ever be committed.

```bash
# 1. Place your own dumped ISO at the repo root as 'God Hand (USA).iso',
#    then extract + verify the boot ELF:
./scripts/extract_iso.sh

# 2. Provision the toolchain (ee-gcc 2.96 + SN linker + dvp-as, splat, m2c,
#    objdiff, asm-differ, decomp-permuter), the venv, and the git hooks:
./scripts/setup_toolchain.sh

# 3. One-time host dependency (the cross assembler the build calls):
#    install your distro's mipsel-linux-gnu binutils.

# 4. Generate the asm split + objdiff scoring project:
.venv/bin/python compile.py --setup

# 5. Build (an empty matching link to start — every byte comes from re-assembled asm):
.venv/bin/python compile.py          # default version is 'us'

# 6. Sanity-check the tooling:
.venv/bin/python -m pytest tests/    # parsers, carve splitter, mappers — wall < 1 s
```

After step 5 you should have a `build/SLUS_215.03.elf` whose sha256 equals the
retail boot ELF. If that holds, your environment is correct.

## Nix dev environment

`nix develop` provisions a sealed toolchain (compiler, wibo, objdiff,
cross-binutils, python, node). It is **additive** to `scripts/setup_toolchain.sh`:
the shellHook symlinks the pinned blobs into the exact gitignored paths the
script already guards, so the script skips the blob fetches and only sets up the
venv, the Python tools, the assembler patches, and the git hooks.

- **Linux (x86_64 or ARM):** `nix develop`, then `./scripts/setup_toolchain.sh`
  (the blobs are already provisioned), then `python compile.py`. On x86_64 the
  i386 compiler blobs run natively; on ARM they run transparently under
  `qemu-i386` (wired into the shell).
- **Without Nix:** install the host prerequisites and run
  `./scripts/setup_toolchain.sh` as before, then `python compile.py`.
- **macOS:** the compiler is an i386-Linux binary, so run the Linux flow inside a
  `linux/amd64` container:

  ```bash
  docker run --platform linux/amd64 -v "$PWD":/src -w /src nixos/nix \
    nix develop --extra-experimental-features 'nix-command flakes' --command bash
  ```

## Measuring progress

Progress is measured two complementary ways:

- **`matched_code_percent` / `matched_functions`** — the fine-grained metric.
  [objdiff](https://github.com/encounter/objdiff) diffs every compiled unit
  against the frozen retail-disassembly target and counts the `.text` bytes (in
  real C units) that compile byte-identical to retail:

  ```bash
  python compile.py --setup     # build units + write objdiff.json
  scripts/progress.sh           # -> progress/report.json + headline
  ```

- **Full-ELF byte identity** — the binary pass/fail gate. The build checks the
  built ELF's sha256 against the retail boot ELF: it stays green only while every
  carved function reproduces retail exactly, so 100% matched code ⇒ a
  byte-identical ELF.

The two are complementary: objdiff shows *how far in* the decomp is; the sha256
gate shows whether the binary still reproduces.

Live progress is also tracked at [decomp.dev/LucasPicoli/god-hand-decomp](https://decomp.dev/LucasPicoli/god-hand-decomp).

## Contributing

Contributions are welcome. See [`CONTRIBUTING.md`](./CONTRIBUTING.md) for how the
matching loop works, how to set up locally, and how to take a function from raw
asm to a byte-identical match. Good first targets are small leaf functions; open
an issue if you'd like to coordinate on something larger or have a question.

## Legal

This repository contains no copyrighted Capcom or Sony assets. The boot ELF hash
recorded in [`config/versions.json`](./config/versions.json) identifies the
legitimately-dumped NTSC-U retail disc, but no game data is distributed here. The
original PS2 SDK binaries used for matching builds are not redistributed; the
setup script downloads them from public archives maintained by the PS2 decomp
community.

Trademarks of *God Hand*, *Clover Studio*, and *Capcom* belong to their
respective holders. This project is for preservation, education, and
non-commercial research.

## License

The original code, tooling, and documentation in this repository are released
under the [MIT License](./LICENSE). This covers only the project's own authored
work: the reconstructed C, the build scripts, and the configuration.

It grants no rights to *God Hand* itself. The game, its code, and its assets
remain the property of Capcom. This is an independent, unofficial
reverse-engineering project, and it is not affiliated with, authorized by, or
endorsed by Capcom or Clover Studio. See [Legal](#legal) for what is and is not
distributed here.

By contributing, you agree that your contributions are licensed under the same
MIT License.
