#include "include_asm.h"
#include "godhand/gameWork.h"

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

/* ── 2 × call_chain (nonmatching — T1 will match) ────────────────────────── */

extern void *func_002D50C0(void *a0);

__attribute__((section(".text.func_0030E568")))
void func_0030E568(int a0, int a1) {
    if (a1 == 0xFFFF && a0 != 0) {
        func_002D50C0(&D_00752C00);
    }
}

/* Picks the background mode; mode 1 also takes a fill colour. */
__attribute__((section(".text.Set_bg_mode")))
void Set_bg_mode(int mode, unsigned char r, unsigned char g, unsigned char b)
{
    switch (mode) {
    case 0:
        D_007474A0.bgB = 0x10;
        D_007474A0.bgA = 0x10;
        break;
    case 1:
        D_007474A0.bgB = 0x16;
        D_007474A0.bgA = 0x16;
        D_007474A0.bgColor = r | (g << 8) | (b << 16);
        break;
    }
}

/* ── PERMANENT: func_0030E660 (0x698 B) stays in monolithic ──────────────── */
/* func_0030E660 — jump-table dispatcher, mult, dsrl32, complex — PERMANENT */
