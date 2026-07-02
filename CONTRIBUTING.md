# Contributing — a guide to god-hand-decomp

This is a **matching decompilation** of *God Hand* (PS2, 2006, Clover Studio /
Capcom). The job is to rewrite the game's machine code as C/C++ that, when
compiled with the original toolchain, produces **byte-for-byte the same** boot
ELF and `.rel` overlays as the retail disc.

> **Contributions welcome.** This guide walks through setup and the per-function
> matching loop end to end. Good first contributions are small leaf functions
> (see §4); open an issue if you'd like to coordinate on something larger or have
> a question. By submitting a contribution you agree it is licensed under the
> project's [MIT License](./LICENSE).

---

## 1. The mental model (read this before anything else)

You are not "porting" or "rewriting" the game in the loose sense. You are
**reproducing the exact bytes** the original compiler emitted. Two ideas drive
everything:

- **The ratchet.** There is one number that only ever goes up:
  `matched_code_percent` — the fraction of `.text` bytes that compile
  *byte-identical* to retail. Every commit must keep the build reproducing
  retail (`scripts/session_check.sh` enforces this). You never land a change
  that lowers the number or breaks the build.

- **Carving.** The whole game starts as one giant disassembly
  (`asm/cod/000000.s`, the "monolithic"). Functions are pulled out one at a
  time. Until a function is matched, the C source `#include`s its raw assembly
  via `INCLUDE_ASM(...)`. When you match it, the `INCLUDE_ASM` line is replaced
  by real C. This is called **carving** a function.

A function is **matched** when the compiler, fed your C with the project's
exact flags, emits the identical machine code. Not "equivalent" — *identical*,
down to register allocation and instruction order. That's the bar.

You'll see two related metrics:

| Metric | What it means |
|---|---|
| `matched_code_percent` | % of `.text` bytes byte-identical to retail (the ratchet) |
| `matched_functions` | count of functions that match |
| full-ELF sha256 gate | pass/fail: does the whole built ELF still equal retail? |

Regenerate the current numbers with `scripts/progress.sh` — never hand-type them.

---

## 2. One-time setup

See the [README → Setup](./README.md#setup) section. In short: supply your own
legally-dumped NTSC-U disc, run `./scripts/extract_iso.sh` then
`./scripts/setup_toolchain.sh` (or `nix develop` first), and
`.venv/bin/python compile.py --setup`. A fresh "empty" build already reproduces
the retail boot ELF byte-for-byte; that's how you confirm your environment is
correct.

**A note on `.venv`.** All Python tooling runs under the repo's virtualenv.
Prefix Python commands with `.venv/bin/python` (the examples below sometimes
drop it for brevity).

---

## 3. The lay of the land

You'll touch these constantly:

| Path | What it is |
|---|---|
| `asm/cod/000000.s` | the **monolithic** — raw disassembly of the whole game, with retail bytes embedded in each instruction comment |
| `src/cod/*.c` | decompiled C. Each file is a translation unit (TU) holding one or more functions. |
| `include/` | shared headers: `sce/` (SDK), `cri/`, `capcom/`, `gh/` (game) |
| `compile_config.json` | the build manifest: which functions are carved, which compiler each TU uses, per-TU flags |
| `config/symbol_addrs.txt` | name → address map (seeded from Ghidra); where you record names you learn |
| `expected/build/*.o` | the objdiff *target* — disassembled-from-retail object files |
| `compile.py` | the build entry point |
| `objdiff.json` | objdiff scoring project (per-`.o` byte diff) |

**Search hygiene — important.** The repo root holds multi-GB artefacts (the
ISO, `tools/`, `build/`, `asm/`). **Never** run `find /`, `find ~`, or
`grep -r` above the project. Use `git grep` / `rg` from the project root (both
respect `.gitignore` and skip the heavy trees), or `scripts/proj-find.sh` if
you need `find`.

---

## 4. The per-function workflow

This is the core loop. The goal: take one function from `INCLUDE_ASM` to a
byte-identical C match.

### Step 0 — pick a target

Good first targets are **small leaf functions** (no calls, simple control
flow): getters/setters, small constructors, math helpers. Avoid huge
dispatchers and anything with VU0 microcode or 64-bit runtime shifts until
you're comfortable — those hit toolchain-fidelity walls.

Browse the worklist by scanning the `glabel func_*` entries in
`asm/cod/000000.s`, or the named entries in `config/symbol_addrs.txt`. Pick a
`func_XXXXXXXX` (the address-based default name) or a name you recognise.

### Step 1 — look at what you're matching

The retail bytes and disassembly for any function come straight out of the
monolithic. In `asm/cod/000000.s` the function lives between
`glabel func_002772A8` and `endlabel func_002772A8`; the 3rd field of each
`/* ... */` comment is the raw retail bytes. That is your target.

### Step 2 — first-pass C with m2c

`m2c` turns MIPS back into rough C. It won't match, but it gives you the
shape — control flow, struct offsets, call signatures:

```bash
.venv/bin/python tools/m2c/m2c.py --target mipsee-gcc-c <asm-for-the-function>
```

Clean it up: name the locals, replace raw offsets with struct field accesses
(Ghidra helps here), declare the externs it references. Large, jump-table-heavy
functions are harder — you may need to reassemble the jump tables and inject the
labels splat omits by hand.

### Step 3 — compile just that unit and diff it

Build the single TU and diff its compiled `.o` against the retail target with
objdiff. This is the inner loop — no full relink needed:

```bash
# compile one TU (no link)
.venv/bin/python compile.py --single-file src/cod/002772.c

# unit = the TU path minus its extension, symbol = the function name
tools/objdiff-cli diff -p . -u src/cod/002772 func_002772A8
```

`asm-differ` (in `tools/asm-differ/`) is the interactive sibling if you prefer
a scrolling side-by-side.

Read the diff structurally. A different register or a reordered load almost
always means the **C structure** is wrong, not that you need to fight the
compiler. Common fixes: reorder local declarations, store an address directly
instead of through a temp, fix a return-value's liveness, get a cast right.

Some functions were built with a different compiler in the SDK. The per-TU
compiler is recorded in `compile_config.json`; if a function won't match under
the default (`cygnus-2.96`), try an alternate. The SN compiler
(`sn-2.95.3-136`) reproduces `sq`-prologue functions; the older
`ee-2.9-991111` cc1 reproduces the statically-linked newlib (mprec/dtoa, and
much of the libc/libm region) whose prologues use 64-bit `sd` callee-saves in
16-byte stack slots — a shape neither of the other two emits. The same
`ee-2.9-991111` toolchain ships a `cc1plus`, selected automatically for C++
TUs (`.cc`/`.cpp`), for the C++ iostream/streambuf/filebuf runtime, which uses
that same `sd`-in-16-byte-slot prologue.

### Step 4 — brute-force the last mile with decomp-permuter

When you're *close* (right instructions, wrong order/registers), let the
permuter mutate your C looking for a byte-identical arrangement:

```bash
tools/decomp-permuter/import.py ...        # uses permuter_settings.toml
tools/decomp-permuter/permuter.py <workdir>
```

`permuter_settings.toml` is already wired to the project's `ee-gcc 2.96` flags.
The permuter is for closing gaps, not for generating matches from scratch.

### Step 5 — carve it in and verify

When the unit matches, carve the function: replace its `INCLUDE_ASM(...)` line
with your C in `src/cod/`, add its `carved_funcs` entry in `compile_config.json`,
then rebuild and confirm the full ELF still equals retail:

```bash
.venv/bin/python compile.py            # rebuild + main-ELF sha256 gate (must == retail)
scripts/session_check.sh               # full ratchet — must exit clean
```

`session_check.sh` builds the ELF, verifies the sha256 ratchet, checks the
objdiff score didn't drop, validates the carve, and runs the forced-register
guard.

---

## 5. The rules (these are non-negotiable)

1. **Honor the ratchet.** Never commit something that lowers
   `matched_code_percent` or breaks the build. `scripts/session_check.sh` is
   the gate.

2. **No forced registers.** Do **not** use
   `register T x __asm__("$N");` to force the compiler's hand. A register-only
   diff means your C structure is wrong — fix the structure, run the permuter,
   and if it still won't match, ship an honest `INCLUDE_ASM("nonmatching", ...)`.
   A pinned pseudo-match is *not* a match, and `scripts/check_forced_regs.py`
   hard-fails any pin (the allowlist is kept empty).

3. **Name what you understand, in the same commit.** Names don't affect the
   ratchet but they *are* most of the deliverable (and what makes the
   decompilation legible). If you figure out what a function, global, or struct is, propagate
   the name into `config/symbol_addrs.txt`, the C source, `carved_funcs`, and
   Ghidra — together, in the commit that matched it.

4. **One focused change per commit.** Prefix the commit subject with a short
   context tag in brackets, e.g. `[func-match] func_002772A8: …`. Don't sneak
   unrelated "small fixes" into a match commit.

5. **A non-matching decomp is still progress.** If a function resists matching,
   landing readable `INCLUDE_ASM("nonmatching", name)` C with the structure and
   names figured out is valuable — it can be ratcheted to matching later, and
   it feeds the port. Honest beats fake.

---

## 6. Submitting work

### Fork and pull request

Work in a branch on your fork, then open a pull request against `main` on the upstream repo. That is how commits get reviewed, discussed, and merged with your authorship intact.

A few things that make PRs easy to merge:

- **One focused change per PR.** A single matched function, a batch of names, or a single new tool. Smaller PRs land faster and are easier to review.
- **Open an issue first for tooling or workflow changes.** New scripts, build system changes, and workflow additions should be discussed in an issue before you put the work in, so nothing gets wasted if the direction needs adjusting.
- **If you are unsure whether something is worth pursuing,** open an issue to ask before investing time in it.

Function matches and naming fixes are always welcome directly as PRs; no prior issue needed.

---

## 7. Measuring progress

```bash
scripts/progress.sh                      # regenerate report + print headline
```

Never hand-type the matched percentage anywhere — regenerate it.

---

## 8. Quick reference

| You want to… | Command |
|---|---|
| See a function's retail bytes/disasm | read `asm/cod/000000.s` between its `glabel`/`endlabel` |
| First-pass C from asm | `tools/m2c/m2c.py --target mipsee-gcc-c <asm>` |
| Compile one TU only | `compile.py --single-file src/cod/<x>.c` |
| See *where* the bytes differ | `tools/objdiff-cli diff -p . -u <tu> <name>` |
| Close the last mile | `tools/decomp-permuter/permuter.py <workdir>` |
| Build the ELF + sha256 gate | `compile.py` |
| Full ratchet check | `scripts/session_check.sh` |
| Progress headline | `scripts/progress.sh` |

Welcome aboard. Match one small function end-to-end first — it teaches the
whole loop in an afternoon.
