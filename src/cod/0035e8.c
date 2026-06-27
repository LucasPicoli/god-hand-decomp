/* Struct: CGObj35E8_t — fields +0x4..+0x70; counter (StepCounter) and indirect pointer (SetIndirect). */
#include "include_asm.h"

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035E868 — call-chain (jal×2, complex branch)                         */
/* ════════════════════════════════════════════════════════════════════════ */
extern void *getElemInfPtr(int a0, int a1);
extern int isEnableVidFtr(int a0, void *a1);

__attribute__((section(".text.func_0035E868")))
int func_0035E868(int a0, int a1, int *a2)
{
    void *s1;
    int s0;
    s0 = a1 & 0xFF;
    *a2 = -1;
    s1 = getElemInfPtr(a0, s0);
    if (s1 == 0) {
        return 0;
    }
    if (isEnableVidFtr(s0, s1) == 0) {
        return 0;
    }
    if (*(int *)((char *)a0 + 0xC) < 0xD2) {
        return 0;
    }
    *a2 = *(unsigned char *)((char *)s1 + 0x27);
    return 1;
}

/* func_0035E8F8 (0x0035E8F8): NOT carved — jump-table entries              */
/* (.L0035E920) are referenced from rodata D_00459C50; the label must      */
/* remain in the monolithic fragment to be visible to the jump-table .o.   */

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035E968 — call-chain: jal E9E8 + branch + movz                       */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", isEnableAudFtr);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035E9A8 — call-chain: jal E9E8 + branch + movz (checks 0xE0)         */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", isEnableVidFtr);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035E9E8 — branched leaf: range checks + exact matches                 */
/*  a0 in [0xC0,0xE0) → 0xC0;  in [0xE0,0xF0) → 0xE0                     */
/*  a0 == 0xBD or 0xBF → 0xBD; else → 0                                   */
/*  NOTE: compiler generates bne+delay v0=0 in reference vs xori+movn      */
/*  here → size mismatch (0x40 vs 0x44) → keep as nonmatching asm          */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035E9E8);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EA30 — arg-rearrange + stores + ra-save tail-call                  */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EA30);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EA60 — medium leaf: counter step arithmetic                        */
/*  *(int*)(a0+0xC) = count                                                */
/*  *(int*)(a0+0x10) = step                                                */
/*  result: a0[4] += step*(count-1); a0[0x10] = -step                     */
/* ════════════════════════════════════════════════════════════════════════ */
__attribute__((section(".text.Obj35E8_StepCounter_EA60")))
void Obj35E8_StepCounter_EA60(char *a0)
{
    int v1 = *(int *)(a0 + 0xC);
    int v0 = *(int *)(a0 + 0x10);
    int a1 = *(int *)(a0 + 0x4);
    *(int *)(a0 + 0x10) = -v0;
    *(int *)(a0 + 0x4) = a1 + v0 * (v1 - 1);
}

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EA88 — large branched call-chain (jal FBD8)                        */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EA88);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EB60 — branched leaf: type-dispatch via movn                       */
/*  if *(a0+4)==0x51: return 4;  if *(a0+4)==0x61: return 5               */
/*  else: return (*(a1+0x94) != 0x51) ? 5 : 4                              */
/*  NOTE: reference uses $a2 for 0x51 constant + movn; compiled uses $v1   */
/*  + xori + movz → register mismatch → keep as nonmatching asm            */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EB60);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EB98 — ra-save trampoline (sd ra; ld ra; j EBB0) — nonmatching     */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EB98);

/* func_0035EBB0 (0x0035EBB0): NOT carved — PERMANENT (bnel) AND            */
/* jump-table label .L0035ECC8 referenced from rodata D_00459CE0; must     */
/* remain in the monolithic fragment for label visibility.                  */

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035ED08 — PERMANENT (beql): branch logic with beql instructions       */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("permanent", func_0035ED08);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EDA8 — ra-save + lw×3 + tail-call func_003603D8                   */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EDA8);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EDC8 — ra-save + lw + tail-call func_0035EDE0                     */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EDC8);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EDE0 — PERMANENT (.word 0x460000E4): FP init table                 */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("permanent", func_0035EDE0);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EE98 — ra-save + lw×3 + tail-call func_0036CBC0                   */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EE98);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EEB8 — ra-save + lw×3 + tail-call func_0036CC08                   */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EEB8);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EED8 — ra-save + lw×3 + tail-call func_0036CC40                   */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EED8);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EEF8 — branched leaf: optional function-pointer call               */
/*  v0 = *(int*)(a0+0x70); if (v0) call v0(*(int*)(a0+0x38))              */
/*  NOTE: reference uses beqz, compiled uses beqzl (likely-branch)         */
/*  at offset c → different delay-slot content → keep as nonmatching asm   */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EEF8);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF20 — no-jr-ra stub (addiu sp+0x20 twice) — nonmatching           */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EF20);

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF30 — accessor: *(a0+0x68) = a1                                  */
/* jr $ra; sw $a1, 0x68($a0)                                               */
/* ════════════════════════════════════════════════════════════════════════ */
__attribute__((section(".text.Obj35E8_SetField_68")))
void Obj35E8_SetField_68(char *a0, int a1)
{
    *(int *)(a0 + 0x68) = a1;
}

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF38 — accessor: *(a0+0x6C) = a1                                  */
/* jr $ra; sw $a1, 0x6C($a0)                                               */
/* ════════════════════════════════════════════════════════════════════════ */
__attribute__((section(".text.Obj35E8_SetField_6C")))
void Obj35E8_SetField_6C(char *a0, int a1)
{
    *(int *)(a0 + 0x6C) = a1;
}

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF40 — indirect accessor: ptr=*(a0+0x30); *(ptr+0x18)=a1          */
/* lw $v0, 0x30($a0); jr $ra; sw $a1, 0x18($v0)                           */
/* ════════════════════════════════════════════════════════════════════════ */
__attribute__((section(".text.Obj35E8_SetIndirect_30_18")))
void Obj35E8_SetIndirect_30_18(char *a0, int a1)
{
    *(int *)(*(int *)(a0 + 0x30) + 0x18) = a1;
}

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF50 — indirect accessor: ptr=*(a0+0x30); *(ptr+0x20)=a1          */
/* lw $v0, 0x30($a0); jr $ra; sw $a1, 0x20($v0)                           */
/* ════════════════════════════════════════════════════════════════════════ */
__attribute__((section(".text.Obj35E8_SetIndirect_30_20")))
void Obj35E8_SetIndirect_30_20(char *a0, int a1)
{
    *(int *)(*(int *)(a0 + 0x30) + 0x20) = a1;
}

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF60 — indirect accessor: ptr=*(a0+0x30); *(ptr+0x1C)=a1          */
/* lw $v0, 0x30($a0); jr $ra; sw $a1, 0x1C($v0)                           */
/* ════════════════════════════════════════════════════════════════════════ */
__attribute__((section(".text.Obj35E8_SetIndirect_30_1C")))
void Obj35E8_SetIndirect_30_1C(char *a0, int a1)
{
    *(int *)(*(int *)(a0 + 0x30) + 0x1C) = a1;
}

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF70 — accessor: *(a0+0x70) = a1                                  */
/* jr $ra; sw $a1, 0x70($a0)                                               */
/* ════════════════════════════════════════════════════════════════════════ */
__attribute__((section(".text.Obj35E8_SetField_70")))
void Obj35E8_SetField_70(char *a0, int a1)
{
    *(int *)(a0 + 0x70) = a1;
}

/* ════════════════════════════════════════════════════════════════════════ */
/* 0x0035EF78 — large call-chain (0x258 bytes; jal×4)                       */
/* ════════════════════════════════════════════════════════════════════════ */
INCLUDE_ASM("nonmatching", func_0035EF78);
