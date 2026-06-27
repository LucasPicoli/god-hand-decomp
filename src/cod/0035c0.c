/* Struct: CGObj35C0_t — indexed 68-byte-stride table +0x138..+0x170 (CopyPair); fields +0x1F30..+0x1F3C with callbacks at +0x1F3C; view into a large entity object. */
#include "include_asm.h"

/* ── Forward declarations for within-TU calls ────────────────────────────── */
void func_0035C1C0(char *a0, int a1, int a2, int a3);
void func_0035C200(char *a0, int a1, int a2);

/* ── INCLUDE_ASM: call-chain / loop-leaf / medium-leaf (nonmatching) ───────── */
INCLUDE_ASM("nonmatching", sftrn_BuildAudio);
__attribute__((section(".text.func_0035C238")))
int func_0035C238(int a0, int a1) {
    char *e = (char *)(a0 + 0x1F30);
    int i;
    int ret = 0;
    for (i = 0; i < 9; i++) {
        int *tbl = *(int **)(e + 0xC);
        e += 0x44;
        if (tbl) {
            int (*fn)(int, int, int, int) = (int (*)(int, int, int, int))tbl[a1];
            ret = fn(a0, 0, 0, 0);
            if (ret) break;
        }
    }
    return ret;
}

typedef int (*Fn)(int, int, int, int);

__attribute__((section(".text.func_0035C2D0")))
int func_0035C2D0(int a0, int a1, int a2, int a3, int t0) {
    Fn *tbl;
    char *p = (char *)a0 + a1 * 68;
    tbl = *(Fn **)(p + 0x1F3C);
    if (tbl == 0) {
        return 0;
    }
    return tbl[a2](a0, a3, t0, 0);
}

INCLUDE_ASM("nonmatching", func_0035C3A0);
INCLUDE_ASM("nonmatching", func_0035C480);
INCLUDE_ASM("nonmatching", func_0035C548);
/* Medium-leaf (nonmatching — instruction scheduling hard to reproduce exactly): */
INCLUDE_ASM("nonmatching", func_0035C1C0);
INCLUDE_ASM("nonmatching", func_0035C200);

/* ── INCLUDE_ASM: permanent (beql/bnel, never matchable in C) ────────────── */
INCLUDE_ASM("permanent", func_0035C5A0);

/* ════════════════════════════════════════════════════════════════════════════ */
/* Accessor thunks — set constant args then tail-call deeper function          */
/* Pattern: addiu sp,-10; addiu aK,const; sd ra; addiu aL,const; ld ra;       */
/*           j TARGET; delay: addiu sp,+10                                     */
/* ════════════════════════════════════════════════════════════════════════════ */

/* 0x0035C120 — set a1=7, a2=8, tail-call func_0035C200                        */
__attribute__((section(".text.sftrn_BuildUsr")))
void sftrn_BuildUsr(char *a0)
{
    func_0035C200(a0, 7, 8);
}

/* 0x0035C140 — move a2→a3, set a2=0, tail-call func_0035C1C0                  */
__attribute__((section(".text.Obj35C0_Set_a1_0_a2_C140")))
void Obj35C0_Set_a1_0_a2_C140(char *a0, int a1, int a2)
{
    func_0035C1C0(a0, a1, 0, a2);
}

/* 0x0035C160 — identical to C140 (same disassembly, different address)         */
__attribute__((section(".text.Obj35C0_Set_a1_0_a2_C160")))
void Obj35C0_Set_a1_0_a2_C160(char *a0, int a1, int a2)
{
    func_0035C1C0(a0, a1, 0, a2);
}

/* 0x0035C180 — move a2→a3, set a2=1, tail-call func_0035C1C0                  */
__attribute__((section(".text.sftrn_ConnTrnBufA")))
void sftrn_ConnTrnBufA(char *a0, int a1, int a2)
{
    func_0035C1C0(a0, a1, 1, a2);
}

/* 0x0035C1A0 — move a2→a3, set a2=2, tail-call func_0035C1C0                  */
__attribute__((section(".text.sftrn_ConnTrnBufU")))
void sftrn_ConnTrnBufU(char *a0, int a1, int a2)
{
    func_0035C1C0(a0, a1, 2, a2);
}

/* ════════════════════════════════════════════════════════════════════════════ */
/* Index accessor family — stride 68 (= a1 * 17 * 4)                          */
/* sll v0,a1,4; addu v0,v0,a1; sll v0,v0,2 computes a1*68.                   */
/* KEY: use a0 += a1*68 to force addu a0,a0,v0 (rs=a0) matching retail.       */
/* ════════════════════════════════════════════════════════════════════════════ */

/* 0x0035C320 — store a2 at index-68 slot +0x1F30  (setter) */
__attribute__((section(".text.Obj35C0_SetIndexed_1F30_C320")))
void Obj35C0_SetIndexed_1F30_C320(char *a0, int a1, int a2)
{
    a0 += a1 * 68;
    *(int *)(a0 + 0x1F30) = a2;
}

/* 0x0035C338 — load from index-68 slot +0x1F30  (getter, lw in delay slot) */
__attribute__((section(".text.Obj35C0_GetIndexed_1F30_C338")))
int Obj35C0_GetIndexed_1F30_C338(char *a0, int a1)
{
    a0 += a1 * 68;
    return *(int *)(a0 + 0x1F30);
}

/* 0x0035C350 — store a2 at index-68 slot +0x1F34  (setter) */
__attribute__((section(".text.Obj35C0_SetIndexed_1F34_C350")))
void Obj35C0_SetIndexed_1F34_C350(char *a0, int a1, int a2)
{
    a0 += a1 * 68;
    *(int *)(a0 + 0x1F34) = a2;
}

/* 0x0035C368 — load from index-68 slot +0x1F34  (getter, lw in delay slot) */
__attribute__((section(".text.Obj35C0_GetIndexed_1F34_C368")))
int Obj35C0_GetIndexed_1F34_C368(char *a0, int a1)
{
    a0 += a1 * 68;
    return *(int *)(a0 + 0x1F34);
}

/* 0x0035C380 — test non-zero: lw before jr ra, sltu v0,zero,v0 in delay slot */
__attribute__((section(".text.Obj35C0_IsIndexedSet_1F3C_C380")))
int Obj35C0_IsIndexedSet_1F3C_C380(char *a0, int a1)
{
    a0 += a1 * 68;
    return *(int *)(a0 + 0x1F3C) != 0;
}

/* ════════════════════════════════════════════════════════════════════════════ */
/* Simple setter / getter stubs — 2 instructions (jr ra + sw/lw in delay)     */
/* ════════════════════════════════════════════════════════════════════════════ */

/* 0x0035C4C0 — *(int*)a0 = a1 */
__attribute__((section(".text.Obj35C0_SetField_0_C4C0")))
void Obj35C0_SetField_0_C4C0(char *a0, int a1)
{
    *(int *)a0 = a1;
}

/* 0x0035C538 — *(int*)(a0+4) = a1 */
__attribute__((section(".text.Obj35C0_SetField_4_C538")))
void Obj35C0_SetField_4_C538(char *a0, int a1)
{
    *(int *)(a0 + 4) = a1;
}

/* 0x0035C540 — *(int*)(a0+0xC) = a1 */
__attribute__((section(".text.Obj35C0_SetField_C_C540")))
void Obj35C0_SetField_C_C540(char *a0, int a1)
{
    *(int *)(a0 + 0xC) = a1;
}

/* ════════════════════════════════════════════════════════════════════════════ */
/* 64-bit pair copiers — copy two consecutive 64-bit (long long) words         */
/* Pattern: ld v0,0(a1); sd v0,OFF(a0); ld v1,8(a1); jr ra; sd v1,OFF+8(a0) */
/* Second sd is in the delay slot of jr ra.                                    */
/* ════════════════════════════════════════════════════════════════════════════ */

/* 0x0035C4C8 — copy a1[0..1] → a0[0x138..0x140] */
__attribute__((section(".text.Obj35C0_CopyPair_138_C4C8")))
void Obj35C0_CopyPair_138_C4C8(char *a0, long long *a1)
{
    *(long long *)(a0 + 0x138) = a1[0];
    *(long long *)(a0 + 0x140) = a1[1];
}

/* 0x0035C4E0 — copy a1[0..1] → a0[0x148..0x150] */
__attribute__((section(".text.Obj35C0_CopyPair_148_C4E0")))
void Obj35C0_CopyPair_148_C4E0(char *a0, long long *a1)
{
    *(long long *)(a0 + 0x148) = a1[0];
    *(long long *)(a0 + 0x150) = a1[1];
}

/* 0x0035C4F8 — copy a1[0..1] → a0[0x158..0x160] */
__attribute__((section(".text.Obj35C0_CopyPair_158_C4F8")))
void Obj35C0_CopyPair_158_C4F8(char *a0, long long *a1)
{
    *(long long *)(a0 + 0x158) = a1[0];
    *(long long *)(a0 + 0x160) = a1[1];
}

/* 0x0035C510 — copy a1[0..1] → a0[0x168..0x170] */
__attribute__((section(".text.Obj35C0_CopyPair_168_C510")))
void Obj35C0_CopyPair_168_C510(char *a0, long long *a1)
{
    *(long long *)(a0 + 0x168) = a1[0];
    *(long long *)(a0 + 0x170) = a1[1];
}

/* ════════════════════════════════════════════════════════════════════════════ */
/* Branched leaf — conditional store using bgtzl (branch-likely > 0)           */
/* bgtzl a1, .L; sw a1, 0x10(a0) [delay, only if taken]; .L: jr ra; nop       */
/* ════════════════════════════════════════════════════════════════════════════ */

/* 0x0035C528 — store a1 at a0+0x10 only if a1 > 0 */
__attribute__((section(".text.Obj35C0_SetField10_IfPositive_C528")))
void Obj35C0_SetField10_IfPositive_C528(char *a0, int a1)
{
    if (a1 > 0) *(int *)(a0 + 0x10) = a1;
}
