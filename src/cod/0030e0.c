#include "include_asm.h"

/* ── 5 × accessor void stubs (jr $ra; nop — matched) ──────────────────── */

__attribute__((section(".text.Obj30E0_NoOp_E538")))
void Obj30E0_NoOp_E538(void) {}

__attribute__((section(".text.Obj30E0_NoOp_E540")))
void Obj30E0_NoOp_E540(void) {}

__attribute__((section(".text.Obj30E0_NoOp_E548")))
void Obj30E0_NoOp_E548(void) {}

__attribute__((section(".text.Obj30E0_NoOp_E550")))
void Obj30E0_NoOp_E550(void) {}

__attribute__((section(".text.Obj30E0_NoOp_E558")))
void Obj30E0_NoOp_E558(void) {}

/* ── 2 × accessor single-insn fragments (nonmatching — no jr $ra) ───────── */

INCLUDE_ASM("nonmatching", func_0030E560);

/* ── 2 × call_chain (nonmatching — T1 will match) ────────────────────────── */

INCLUDE_ASM("nonmatching", func_0030E568);

/* ── 1 × accessor single-insn fragment (nonmatching — no jr $ra) ─────────── */

INCLUDE_ASM("nonmatching", func_0030E5B8);

/* ── 1 × branched_leaf (nonmatching — T1 will match) ─────────────────────── */

INCLUDE_ASM("nonmatching", Set_bg_mode);

/* ── PERMANENT: func_0030E660 (0x698 B) stays in monolithic ──────────────── */
/* func_0030E660 — jump-table dispatcher, mult, dsrl32, complex — PERMANENT */
