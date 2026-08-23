/* Struct: CGObj33F8_t — lock/word at +0xC/+0x10; u16 pair +0x28..+0x2E; s16 trio +0x34..+0x38 (StorePair/LoadPair/StoreS16Trio). */
#include "include_asm.h"

/* ── Forward declarations ───────────────────────────────────────────────── */
extern void func_003A52F0(void *a0, int a1, int a2);
extern void func_0033E6B8();          /* K&R: fp args, complex signature    */
extern void Forward33B568_33B658(void);
extern void Forward33B5C8_33B670(void);
extern void func_0033F130(void);

/* ── Extern globals ─────────────────────────────────────────────────────── */
extern char D_003EB858[];   /* struct array, size >= 0x3C0, Obj33F8_Init_D003EB858_F888   */
extern int  D_003EB850;     /* boolean flag, Obj33F8_SetFlag_D003EB850_FB68 sets = 1          */

/* ── Addiu-only / store-only stubs — no jr $ra; unrepresentable in C ─────── */
INCLUDE_ASM("nonmatching", func_0033F810);
INCLUDE_ASM("nonmatching", func_0033F8B0);

/* ── Branched functions — T0 attempt failed (wrong code size) ────────────── */
INCLUDE_ASM("nonmatching", func_0033F850);

/* ── Obj33F8_Init_D003EB858_F888 — memset D_003EB858 (size 0x3C0) ─────────────────────── */
__attribute__((section(".text.Obj33F8_Init_D003EB858_F888")))
void Obj33F8_Init_D003EB858_F888(void) {
    func_003A52F0(D_003EB858, 0, 0x3C0);
}

/* ── Obj33F8_Thunk_0033E6B8_F988 — rearrange args and tail-call func_0033E6B8 ──────────── */
/* Asm: new_a0=a2, a1 stays, new_a2=a0+0x30, new_a3=a0+0x32                 */
__attribute__((section(".text.Obj33F8_Thunk_0033E6B8_F988")))
void Obj33F8_Thunk_0033E6B8_F988(char *a0, int a1, char *a2) {
    func_0033E6B8(a2, a1, a0 + 0x30, a0 + 0x32);
}

/* ── Obj33F8_StorePair_28_2C_F9B0 — copy two u16-pairs from a1/a2 into a0 struct ────────── */
__attribute__((section(".text.Obj33F8_StorePair_28_2C_F9B0")))
void Obj33F8_StorePair_28_2C_F9B0(char *a0, unsigned short *a1, unsigned short *a2) {
    *(unsigned short *)(a0 + 0x28) = a1[0];
    *(unsigned short *)(a0 + 0x2A) = a2[0];
    *(unsigned short *)(a0 + 0x2C) = a1[1];
    *(unsigned short *)(a0 + 0x2E) = a2[1];
}

/* ── Obj33F8_LoadPair_28_2C_F9D8 — extract two u16-pairs from a0 struct into a1/a2 ───── */
__attribute__((section(".text.Obj33F8_LoadPair_28_2C_F9D8")))
void Obj33F8_LoadPair_28_2C_F9D8(char *a0, unsigned short *a1, unsigned short *a2) {
    a1[0] = *(unsigned short *)(a0 + 0x28);
    a2[0] = *(unsigned short *)(a0 + 0x2A);
    a1[1] = *(unsigned short *)(a0 + 0x2C);
    a2[1] = *(unsigned short *)(a0 + 0x2E);
}

/* ── Obj33F8_StoreS16Trio_34_FA00 — store three s16 fields into a0 struct ─────────────── */
__attribute__((section(".text.Obj33F8_StoreS16Trio_34_FA00")))
void Obj33F8_StoreS16Trio_34_FA00(char *a0, short a1, short a2, short a3) {
    *(short *)(a0 + 0x34) = a1;
    *(short *)(a0 + 0x36) = a2;
    *(short *)(a0 + 0x38) = a3;
}

/* ── Obj33F8_LoadU16Trio_34_FA10 — load three u16 fields from a0 struct to out-ptrs ────── */
__attribute__((section(".text.Obj33F8_LoadU16Trio_34_FA10")))
void Obj33F8_LoadU16Trio_34_FA10(char *a0, unsigned short *a1, unsigned short *a2,
                   unsigned short *a3) {
    *a1 = *(unsigned short *)(a0 + 0x34);
    *a2 = *(unsigned short *)(a0 + 0x36);
    *a3 = *(unsigned short *)(a0 + 0x38);
}

/* ── Obj33F8_InitIfNonNull_FA30 — conditional memset-like init of a0 ─────────────────── */
/* First zeros offset 0, then calls func_003A52F0(a0, 0, 0x3C).              */
__attribute__((section(".text.Obj33F8_InitIfNonNull_FA30")))
void Obj33F8_InitIfNonNull_FA30(void *a0) {
    if (a0) {
        *(int *)a0 = 0;
        func_003A52F0(a0, 0, 0x3C);
    }
}

/* ── Obj33F8_GetWord_C_FA68 — return *(int*)(a0+0xC) ────────────────────────────── */
__attribute__((section(".text.Obj33F8_GetWord_C_FA68")))
int Obj33F8_GetWord_C_FA68(char *a0) {
    return *(int *)(a0 + 0xC);
}

/* ── Branched store functions — moved to src/cod/0033fa70.c ──────────────── */
/* func_0033FA70, func_0033FAA0 and func_0033FAD0 match under sn-2.95.3-136   */
/* only.  This TU needs cygnus-2.96, so the three live in their own TU.       */

/* ── func_0033FB00 — acquire lock ───────────────────────────────────────── */
__attribute__((section(".text.func_0033FB00")))
void func_0033FB00(int *p) {
    if (p[3] == 0) {
        p[4] = 0;
        p[3] = 1;
    }
}

/* ── Obj33F8_ResetLock_FB20 — zero lock + memset sub-struct ──────────────────────── */
__attribute__((section(".text.Obj33F8_ResetLock_FB20")))
void Obj33F8_ResetLock_FB20(char *a0) {
    *(int *)(a0 + 0xC) = 0;
    func_003A52F0(a0 + 0x28, 0, 8);
}

/* ── func_0033FB48 — clear lock if == 3 ─────────────────────────────────── */
__attribute__((section(".text.func_0033FB48")))
void func_0033FB48(int *p) {
    if (p[3] == 3) {
        p[3] = 0;
    }
}

/* ── Obj33F8_GetWord_10_FB60 — return *(int*)(a0+0x10) ────────────────────────────── */
__attribute__((section(".text.Obj33F8_GetWord_10_FB60")))
int Obj33F8_GetWord_10_FB60(char *a0) {
    return *(int *)(a0 + 0x10);
}

/* ── Obj33F8_SetFlag_D003EB850_FB68 — set global flag D_003EB850 = 1 ─────────────────────── */
__attribute__((section(".text.Obj33F8_SetFlag_D003EB850_FB68")))
void Obj33F8_SetFlag_D003EB850_FB68(void) {
    D_003EB850 = 1;
}

/* ── Simple tail-call trampolines (addiu; sd $ra; ld $ra; j target) ─────── */

/* Obj33F8_Tramp_0033B658_FC70 → j Forward33B568_33B658 */
__attribute__((section(".text.Obj33F8_Tramp_0033B658_FC70")))
void Obj33F8_Tramp_0033B658_FC70(void) { Forward33B568_33B658(); }

/* Obj33F8_Tramp_0033B670_FC88 → j Forward33B5C8_33B670 */
__attribute__((section(".text.Obj33F8_Tramp_0033B670_FC88")))
void Obj33F8_Tramp_0033B670_FC88(void) { Forward33B5C8_33B670(); }

/* ── Obj33F8_NoOp_FCA0 — empty function (jr $ra; nop) ───────────────────────── */
__attribute__((section(".text.Obj33F8_NoOp_FCA0")))
void Obj33F8_NoOp_FCA0(void) {}

/* ── Obj33F8_NoOp_FCA8 — empty function (jr $ra; nop) ───────────────────────── */
__attribute__((section(".text.Obj33F8_NoOp_FCA8")))
void Obj33F8_NoOp_FCA8(void) {}

/* Obj33F8_Tramp_0033F130_FCB0 → j func_0033F130 */
__attribute__((section(".text.Obj33F8_Tramp_0033F130_FCB0")))
void Obj33F8_Tramp_0033F130_FCB0(void) { func_0033F130(); }

/* ── Store-only stub (sw $zero, 0x8($v1); no jr $ra) ────────────────────── */
INCLUDE_ASM("nonmatching", func_0033FCC8);

/* ── Call-chain functions deferred ───────────────────── */
INCLUDE_ASM("nonmatching", func_0033FCD0);

/* ── Addiu-only stub (no jr $ra) ─────────────────────────────────────────── */
INCLUDE_ASM("nonmatching", func_0033FD68);

/* ── Call-chain: calls func_0033FCD0 + global access ────────────────────── */
INCLUDE_ASM("nonmatching", func_0033FD70);
