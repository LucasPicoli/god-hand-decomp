/* m2c per-function context header for god-hand-decomp.
 *
 * Concatenated ahead of the generated C code while iterating an
 * `m2c`-direct function toward a byte match.  This file is NOT in the
 * matching-build link path (it is never #included from anything under
 * `src/`); changing it cannot perturb the `build/SLUS_215.03.elf` or
 * rel-overlay byte output.  Header-only.
 *
 * Goal: give m2c-direct output enough types / externs to compile
 * against `ctx.h` without having to bootstrap a typedef by hand each
 * time.
 *
 * Sections, in order:
 *   1. Width-alias typedefs (matches m2c's primitive emit + the
 *      precedent PS2-era decomp projects).
 *   2. m2c "valid syntax" mode helpers (forwarded from
 *      `tools/m2c/m2c_macros.h` so m2c output with --valid-syntax
 *      still compiles in our context; no-op otherwise).
 *   3. Opaque struct shapes for the $a0 / $a1 argument types of the
 *      stress-test candidates.  Sized at "highest observed
 *      field offset + 4, rounded up to multiple of 16".
 *   4. extern decls for the D_* globals referenced by the
 *      candidates + one loader-group global (cMcLoaderState).
 *
 * If a declaration collides with an existing one under the `include` tree once
 * the SCE / SN headers are vendored, prefer the header and drop the
 * shim here.
 */

#ifndef CTX_H
#define CTX_H

/* -- 1. Width aliases ----------------------------------------------- */
/* ee-gcc 2.96 / R5900 conventions.  Matches the precedent PS2-era
 * decomp projects (`celophi/lom-decomp`, `2Tie/mh1j`,
 * `fmil95/recvx-decomp`).  Also matches m2c's
 * primitive emit (`tools/m2c/m2c_macros.h` references `s8`/`s16`/`s32`
 * /`s64` as already-typedef'd).
 */
typedef signed char         s8;
typedef unsigned char       u8;
typedef signed short        s16;
typedef unsigned short      u16;
typedef signed int          s32;
typedef unsigned int        u32;
typedef signed long long    s64;
typedef unsigned long long  u64;
typedef float               f32;
typedef double              f64;

/* -- 2. m2c "valid syntax" helpers ---------------------------------- */
/* m2c with --valid-syntax emits `M2C_UNK` placeholders for fields
 * whose type it couldn't infer + `M2C_FIELD(expr, type_ptr, off)` for
 * raw-offset access patterns.  Forwarded here so those names compile
 * even when m2c didn't run with that flag (the macros expand to the
 * obvious thing; the placeholder typedefs are harmless aliases).
 * Mirrors `tools/m2c/m2c_macros.h`.
 */
typedef s32  M2C_UNK;
typedef s8   M2C_UNK8;
typedef s16  M2C_UNK16;
typedef s32  M2C_UNK32;
typedef s64  M2C_UNK64;
#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif

/* -- 3. Opaque struct shapes ---------------------------------------- */
/* Naming convention (loose-seed):
 *
 *     CGUnk_<seed-addr>_t      — opaque shape with byte-padding to the
 *                                highest observed field offset + 4,
 *                                rounded up to multiple of 16.
 *
 * "Seed-addr" is the VRAM of the first candidate observed to
 * operate on that shape (so the symbol is greppable back to where it
 * was first seen).  When/if the shape is named in Ghidra, rename here
 * in the same commit.
 *
 * Each shape gets a forward decl so callers can use the pointer-form
 * without depending on the size baked in below.  The size is the
 * "size_expected" lower bound for any decomp touching the shape.
 */

/* Actor-ish object operated on by `func_0013C5C8` (struct zero-init,
 * 20 stores to offsets 0x50..0x7C) and `func_00146F70` (two-path
 * setter on offsets 0x78 + 0x90 + 0x91).  Merged: highest observed
 * offset is 0x91, +4 = 0x95, round up to 0xA0.  Likely a small actor /
 * effect / control-block shape (the per-byte writes at 0x74..0x7C +
 * the boolean field at 0x90 are characteristic of an enable / phase /
 * timer block).
 */
typedef struct CGUnk_0013C5C8 { u8 unk[0xA0]; } CGUnk_0013C5C8_t;

/* Large actor-ish shape operated on by the existing matched
 * `func_0010BE10` (`arg0[0x2F4] = 0;`), its sister `func_0010B5C8`
 * (BRANCHED-LEAF flag-check on `arg0[0x2F4]` + `arg0[0x2F5]`), and the
 * also-matched `func_0014B638` (`return arg0[0x2B1];`).  Highest
 * observed offset is 0x2F5, +4 = 0x2F9, round up to 0x300.  Probably
 * the main per-entity state shape (sister of the existing matched
 * func_0010BE10).
 */
typedef struct CGUnk_0010B5C8 { u8 unk[0x300]; } CGUnk_0010B5C8_t;

/* Linked-list node operated on by `func_001346C8` (LOOP-LEAF; reads
 * `node->key` at offset 0x0 and walks `node->next` at offset 0x10 via
 * `lw $a0, 0x10($a0)`).  Highest observed offset is 0x10 + 4 = 0x14,
 * round up to 0x20.  Layout is `{ s32 key; pad[0xC]; struct ... *next; }`.
 */
typedef struct CGListNode_001346C8 { u8 unk[0x20]; } CGListNode_001346C8_t;

/* Medium-size shape touched by the existing matched `func_0013E3F8`
 * (`arg0[0x104] = 0;`).  Highest observed offset 0x104, +4 = 0x108,
 * round up to 0x110.  Distinct from the 0x300-shape — the offset-
 * range is significantly smaller and the call sites don't overlap.
 */
typedef struct CGUnk_0013E3F8 { u8 unk[0x110]; } CGUnk_0013E3F8_t;

/* Small shape touched by the existing matched `func_00134648`
 * (`*((int *)((char *)arg0 + 0x8)) = arg1;`).  Highest observed
 * offset 0x8 + 4 = 0xC, round up to 0x10.  Smallest of the shapes —
 * likely a 3- or 4-field handle / cursor / iterator.
 */
typedef struct CGUnk_00134648 { u8 unk[0x10]; } CGUnk_00134648_t;

/* Game-object state-accessor shape operated on by the first-TU
 * group at 0x002930A8 – 0x00293C40.
 * Observed field touches (signed/unsigned byte + word):
 *
 *   +0x500  w_500   word     (func_00293130 — return)
 *   +0x53A  b_53A   s8       (func_002930B8 — set 2)
 *   +0x53B  b_53B   s8       (func_002930D0 set 0x3C; func_002930E0 truthy)
 *   +0x53C  b_53C   s8       (func_002930F0 set 2;    func_00293100 truthy)
 *   +0x53D  b_53D   s8       (func_00293110 set 2;    func_00293120 truthy)
 *   +0x55C  w_55C   word     (func_002930A8 — post-inc counter)
 *   +0x564  w_564   word     (func_00293760 — read via arg1)
 *   +0x574  w_574   word ptr (func_00293760 — jump-table case 0)
 *   +0x578  w_578   word ptr (func_00293760 — jump-table case 1)
 *   +0x57C  w_57C   word ptr (func_00293760 — jump-table case 2)
 *   +0x580  w_580   word ptr (func_00293760 — jump-table case 3)
 *   +0x584  w_584   word ptr (func_00293760 — jump-table case 4)
 *   +0x5A0  b_5A0   u8       (func_00293728 — clear)
 *   +0x5A3  b_5A3   u8       (func_00293718 |= mask;  func_00293728 clear)
 *   +0x5A4  b_5A4   u8       (func_00293738 |= mask)
 *   +0x5A5  b_5A5   u8       (func_00293750 |= 1)
 *
 * Highest observed offset is 0x584 + 4 = 0x588, round up to 0x590.
 * NOTE: func_00293138 stays in monolithic asm and almost certainly
 * touches higher offsets; size will bump if a later decomp surfaces a
 * higher offset, per the sizing rule. func_002937C0 and func_00293C40
 * are C (src/cod/002937c0.c, 00293c40.c) and read cEmManage.
 * Field names are seed-conservative (`b_<off>` / `w_<off>`)
 * pending Ghidra-side naming; rename here in the same commit once the
 * field is understood.
 */
typedef struct CGObj293 { u8 unk[0x590]; } CGObj293_t;

/* -- 4. extern globals ---------------------------------------------- */
/* The D_* names mirror `config/symbol_addrs.txt` (the Ghidra-seeded
 * symbol map; cross-reference per-symbol for shape info when present).
 * Types are opaque (`u8[]` / forward-declared struct) until a decomp
 * narrows them.
 */

/* MMI 4-row lookup table at VRAM 0x0041EDF0, indexed by
 * `func_00156550` via `lq $a, 0x10*idx($v0)`.  Four 16 B rows = 0x40 B
 * minimum; declared as a `u8[]` array (rather than a sized array) so
 * decomps can refine into a typed `{ u128 row[4]; }` shape later
 * without source churn here.
 */
extern u8 D_0041EDF0[];

/* Opaque global whose address is passed as a single arg by
 * `func_001492C8` (`jal func_00149378` after `daddiu $a0, %lo(D_00466448)`).
 * Shape unknown until `func_00149378` is decomp'd.
 */
extern u8 D_00466448[];

/* SN ProDG loader runtime state — `cMcLoaderState` (the 0x00752C00
 * global is the SN cMcLoaderState).  32 slots × 0x88 B + a
 * `u32 refcount` at slot+0x1104 = 0x1108 B total.  Used by the loader
 * group (`func_00200CB0`, `func_00201788`, the SN `Load__*` runtime).
 * Declared as `u8[]` for now; a real `cMcLoaderSlot slots[32]; u32 refcount;`
 * shape lands when the first loader-group function decomps.
 */
extern u8 cMcLoaderState[0x1108];

/* Jump-table for func_00293760 (first-TU group).  Five word-
 * sized code-pointer slots at 0x0044A7B0..0x0044A7C3, indexed by
 * `(*(int*)(arg1 + 0x564)) - 0x270` after a `sltiu $v1, $a0, 0x5`
 * range check.  Each slot's target is a `sw $a1, 0x57N($a2); jr $ra`
 * fragment inside func_00293760's body.  Declared as `u8[]` because
 * the array is interpreted as code pointers by the dispatcher itself,
 * not by any C consumer — only used by the asm carved as PERMANENT.
 */
extern u8 D_0044A7B0[];

/* Accessor-group at 0x0038B810–0x0038BFF8.                            */
/* Singleton globals for init-check patterns in func_0038B8B0 /         */
/* func_0038BE98: each is a 32-bit int; non-zero = already initialized. */
/* &D_786768 / &D_786778 are passed to func_0031EEA8 as the destination  */
/* struct pointer.  Addresses use lui+addiu since > 0x8000 from $gp.   */
extern int D_786768;    /* 0x786768 — singleton object, func_0038B8B0   */
extern int D_786778;    /* 0x786778 — singleton object, func_0038BE98   */
extern int D_0045D350;  /* arg to func_0031EEA8 from func_0038B8B0      */
extern int D_0045D360;  /* arg to func_0031EEA8 from func_0038BE98      */
extern int D_00460DB0;  /* arg to func_0031EEA8 from func_0038BE98      */

/* Game-object accessor type for the group at 0x0038B810.              */
/* Observed field offsets up to 0x50 (vtable ptr); size rounded to 0x60.*/
/* Field mapping: +0x0=flags(int), +0x14=cursor(int), +0x1A=flags(u8),  */
/* +0x1B=flags(u8), +0x38=signed_val(int), +0x50=vtable_ptr(ptr).       */
typedef struct CGObj38B8 { u8 unk[0x60]; } CGObj38B8_t;

#endif /* CTX_H */
