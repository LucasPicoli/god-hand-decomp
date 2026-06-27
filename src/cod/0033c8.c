/* Struct: CGObj33C8_t — mixed byte/short/word fields +0xD..+0xCC; short array at +0xE2. */
#include "include_asm.h"

/* ── CALL CHAIN (4) — deferred ─────────────────────────── */
INCLUDE_ASM("nonmatching", func_0033C918);

/* ── MEDIUM (1) — large initializer ───────────────────────────────────────*/
INCLUDE_ASM("nonmatching", func_0033CC50);


/* ── ACCESSOR / BRANCHED_LEAF (15) ─────────────────────────────────────── */
__attribute__((section(".text.Obj33C8_SetFields_78_7C")))
void Obj33C8_SetFields_78_7C(char *a0, int a1, int a2) {
    *(int *)(a0 + 0x78) = a1;
    *(int *)(a0 + 0x7C) = a2;
}

/* func_0033CE78 — standalone asm (alabel/.aent prevents INCLUDE_ASM) */
__attribute__((section(".text.Obj33C8_GetShort_98")))
int Obj33C8_GetShort_98(char *a0) {
    return *(short *)(a0 + 0x98);
}

__attribute__((section(".text.Obj33C8_GetField_14")))
int Obj33C8_GetField_14(char *a0) {
    return *(int *)(a0 + 0x14);
}

__attribute__((section(".text.Obj33C8_GetByte_D")))
int Obj33C8_GetByte_D(char *a0) {
    return a0[0xD];
}

__attribute__((section(".text.Obj33C8_GetField_10")))
int Obj33C8_GetField_10(char *a0) {
    return *(int *)(a0 + 0x10);
}

__attribute__((section(".text.Obj33C8_GetField_18")))
int Obj33C8_GetField_18(char *a0) {
    return *(int *)(a0 + 0x18);
}

__attribute__((section(".text.Obj33C8_GetShort_24")))
int Obj33C8_GetShort_24(char *a0) {
    return *(short *)(a0 + 0x24);
}

__attribute__((section(".text.Obj33C8_GetField_28")))
int Obj33C8_GetField_28(char *a0) {
    return *(int *)(a0 + 0x28);
}

__attribute__((section(".text.Obj33C8_GetField_2C_OrZeroIfNull")))
int Obj33C8_GetField_2C_OrZeroIfNull(char *a0) {
    if (!a0) return 0;
    return *(int *)(a0 + 0x2C);
}

__attribute__((section(".text.Obj33C8_GetField_30")))
int Obj33C8_GetField_30(char *a0) {
    return *(int *)(a0 + 0x30);
}

__attribute__((section(".text.Obj33C8_GetField_34")))
int Obj33C8_GetField_34(char *a0) {
    return *(int *)(a0 + 0x34);
}

__attribute__((section(".text.Obj33C8_GetField_CC")))
int Obj33C8_GetField_CC(char *a0) {
    return *(int *)(a0 + 0xCC);
}

__attribute__((section(".text.Obj33C8_GetShort_E0")))
int Obj33C8_GetShort_E0(char *a0) {
    return *(short *)(a0 + 0xE0);
}

__attribute__((section(".text.Obj33C8_GetShortArrayE2_idx")))
int Obj33C8_GetShortArrayE2_idx(char *a0, int a1) {
    return *(short *)(a0 + 0xE2 + a1 * 2);
}

/* ── CALL CHAIN (continued) ─────────────────────────────────────────────── */
INCLUDE_ASM("nonmatching", func_0033CFB8);
INCLUDE_ASM("nonmatching", func_0033CFF8);
