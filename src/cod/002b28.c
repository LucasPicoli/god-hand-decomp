/* Struct: CGObj2B28_t — u16 pair at +0x34/+0x38, field +0x8C (CopyU16/SetField34). */
#include "include_asm.h"

/* ── call-chain (3) — save $ra, call sub-function, return 0 ─────────── */

INCLUDE_ASM("nonmatching", func_002B2A30);
INCLUDE_ASM("nonmatching", func_002B2A58);

/* ── accessor leaves (14) ────────────────────────────────────────────── */

/*
 * func_002B2AE8 — 0x1C B (7 insns)
 * addiu v1,2; daddu v0,0; sb v1,A4; sb 0,3C; sb v1,70; jr; delay:sw 0,18
 * The store order 0x3C, 0x70, 0x18, 0xA4 gives the retail register order.
 */
__attribute__((section(".text.func_002B2AE8")))
int func_002B2AE8(char *p)
{
    *(unsigned char *)(p + 0x3C) = 0;
    *(unsigned char *)(p + 0x70) = 2;
    *(int *)(p + 0x18) = 0;
    *(unsigned char *)(p + 0xA4) = 2;
    return 0;
}

/*
 * func_002B2B78 — 0x30 B (12 insns)
 * addiu v1,4; addiu v0,2; sb v1,A4; sb v0,70; sw 0,18; daddu v0,0;
 * lw v1,8C; lhu a1,2(v1); sb 0,3C; sh a1,94; jr; delay:sh 0,96
 */
__attribute__((section(".text.func_002B2B78")))
int func_002B2B78(char *p) {
    *(char *)(p + 0x70) = 2;
    *(char *)(p + 0xA4) = 4;
    *(int *)(p + 0x18) = 0;
    *(short *)(p + 0x94) = *(unsigned short *)(*(int *)(p + 0x8C) + 0x2);
    *(short *)(p + 0x96) = 0;
    *(char *)(p + 0x3C) = 0;
    return 0;
}

/*
 * func_002B2BA8 — 0x30 B (12 insns)
 * Same shape as func_002B2B78 but A4=5.
 */
__attribute__((section(".text.func_002B2BA8")))
int func_002B2BA8(char *p) {
    *(char *)(p + 0x70) = 2;
    *(char *)(p + 0xA4) = 5;
    *(int *)(p + 0x18) = 0;
    *(short *)(p + 0x94) = *(unsigned short *)(*(int *)(p + 0x8C) + 0x2);
    *(short *)(p + 0x96) = 0;
    *(char *)(p + 0x3C) = 0;
    return 0;
}

/*
 * Obj2B28_SetField34_To1_ReturnZero — 0x10 B (4 insns)
 * addiu v1,1; daddu v0,0; jr; delay:sw v1,0x34
 * Sets *(int*)(a0+0x34)=1; returns 0.
 */
__attribute__((section(".text.Obj2B28_SetField34_To1_ReturnZero")))
int Obj2B28_SetField34_To1_ReturnZero(char *a0) {
    *(int *)(a0 + 0x34) = 1;
    return 0;
}

/*
 * Obj2B28_SetField34_To2_ReturnZero — 0x10 B (4 insns)
 * addiu v1,2; daddu v0,0; jr; delay:sw v1,0x34
 * Sets *(int*)(a0+0x34)=2; returns 0.
 */
__attribute__((section(".text.Obj2B28_SetField34_To2_ReturnZero")))
int Obj2B28_SetField34_To2_ReturnZero(char *a0) {
    *(int *)(a0 + 0x34) = 2;
    return 0;
}

/*
 * Obj2B28_ReturnZero_F68 — 0x8 B (2 insns)
 * jr $ra; delay:daddu v0,0
 * Returns 0 (no side effects).
 */
__attribute__((section(".text.Obj2B28_ReturnZero_F68")))
int Obj2B28_ReturnZero_F68(char *a0) { return 0; }

/*
 * Obj2B28_ReturnZero_F70 — 0x8 B (2 insns)
 * jr $ra; delay:daddu v0,0
 * Returns 0 (no side effects).
 */
__attribute__((section(".text.Obj2B28_ReturnZero_F70")))
int Obj2B28_ReturnZero_F70(char *a0) { return 0; }

/*
 * Obj2B28_ReturnZero_F78 — 0x8 B (2 insns)
 * jr $ra; delay:daddu v0,0
 * Returns 0 (no side effects).
 */
__attribute__((section(".text.Obj2B28_ReturnZero_F78")))
int Obj2B28_ReturnZero_F78(char *a0) { return 0; }

/* ── call-chain (cont.) ──────────────────────────────────────────────── */

INCLUDE_ASM("nonmatching", func_002B2F80);

/* ── accessor leaves (cont.) ─────────────────────────────────────────── */

/*
 * Obj2B28_ReturnZero_FA8 — 0x8 B (2 insns)
 * jr $ra; delay:daddu v0,0
 * Returns 0 (no side effects).
 */
__attribute__((section(".text.Obj2B28_ReturnZero_FA8")))
int Obj2B28_ReturnZero_FA8(char *a0) { return 0; }

/*
 * func_002B2FB0 — 0x20 B (8 insns)
 * lw a1,8C; daddu v0,0; lw v1,14; lbu a2,2(a1);
 * ori v1,v1,0x200; sw v1,14; jr; delay:sb a2,0x31
 * A local for the 0x8C pointer forces the retail load order.
 */
__attribute__((section(".text.func_002B2FB0")))
int func_002B2FB0(char *p)
{
    char *q = *(char **)(p + 0x8C);
    unsigned char b = *(unsigned char *)(q + 0x2);

    *(unsigned char *)(p + 0x31) = b;
    *(int *)(p + 0x14) |= 0x200;
    return 0;
}

/*
 * Obj2B28_ReturnZero_FD0 — 0x8 B (2 insns)
 * jr $ra; delay:daddu v0,0
 * Returns 0 (no side effects).
 */
__attribute__((section(".text.Obj2B28_ReturnZero_FD0")))
int Obj2B28_ReturnZero_FD0(char *a0) { return 0; }

/*
 * Obj2B28_CopyU16_8C2_To38_ReturnZero — 0x14 B (5 insns)
 * lw v1,8C; daddu v0,0; lhu a1,2(v1); jr; delay:sh a1,0x38
 * Copies u16 from *(p_8C)+2 to *(u16*)(a0+0x38); returns 0.
 */
__attribute__((section(".text.Obj2B28_CopyU16_8C2_To38_ReturnZero")))
int Obj2B28_CopyU16_8C2_To38_ReturnZero(char *a0) {
    *(unsigned short *)(a0 + 0x38) = *(unsigned short *)(*(int *)(a0 + 0x8C) + 2);
    return 0;
}

/*
 * Obj2B28_ReturnZero_FF0 — 0x8 B (2 insns)
 * jr $ra; delay:daddu v0,0
 * Returns 0 (no side effects).
 */
__attribute__((section(".text.Obj2B28_ReturnZero_FF0")))
int Obj2B28_ReturnZero_FF0(char *a0) { return 0; }

/*
 * Obj2B28_ReturnZero_FF8 — 0x8 B (2 insns)
 * jr $ra; delay:daddu v0,0
 * Returns 0 (no side effects).
 */
__attribute__((section(".text.Obj2B28_ReturnZero_FF8")))
int Obj2B28_ReturnZero_FF8(char *a0) { return 0; }
