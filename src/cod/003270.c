/* Struct: CGObj3270_t — word getter/setter block +0x2C..+0x4C and +0x9C. */
#include "include_asm.h"

/* -- Forward declarations for tail-call targets ----------------------------- */
extern int Forward33C548_33D040(void *a0);
extern int Obj33C8_GetShort_98(void *a0);
extern int Obj33C8_GetField_14(void *a0);
extern int func_0033CE98(void *a0);
extern int func_0033CEF0(void *a0);
extern int Obj33C8_GetField_10(void *a0);
extern int Obj33C8_GetField_18(void *a0);

/* -- 1 call_chain ----------------------------------------------------------- */
/* func_003276A8: iterating loop with bnel, calls func_00327370 — nonmatching */
INCLUDE_ASM("nonmatching", func_003276A8);

/* -- 16 accessor leaves ----------------------------------------------------- */

/* jr $ra; lw $v0, 0x30($a0) */
__attribute__((section(".text.Obj3270_GetField_30")))
int Obj3270_GetField_30(void *a0) {
    return *(int *)((char *)a0 + 0x30);
}

/* jr $ra; lw $v0, 0x2C($a0) */
__attribute__((section(".text.Obj3270_GetField_2C")))
int Obj3270_GetField_2C(void *a0) {
    return *(int *)((char *)a0 + 0x2C);
}

/* jr $ra; sw $a1, 0x34($a0) */
__attribute__((section(".text.Obj3270_SetField_34")))
void Obj3270_SetField_34(void *a0, int a1) {
    *(int *)((char *)a0 + 0x34) = a1;
}

/* jr $ra; sw $a1, 0x9C($a0) */
__attribute__((section(".text.Obj3270_SetField_9C")))
void Obj3270_SetField_9C(void *a0, int a1) {
    *(int *)((char *)a0 + 0x9C) = a1;
}

/* addiu sp,-0x10; sd ra; ld ra; j Forward33C548_33D040; addiu sp,+0x10 */
__attribute__((section(".text.Obj3270_Tramp_0033D040_7728")))
int Obj3270_Tramp_0033D040_7728(void *a0) {
    return Forward33C548_33D040(a0);
}

/* sw $a1, 0x50($a0) only — 1-insn fallthrough, no jr $ra */
INCLUDE_ASM("nonmatching", func_00327740);

/* sw $a2, 0x4C($a0); jr $ra; sw $a1, 0x48($a0) [delay slot] */
__attribute__((section(".text.Obj3270_SetField_48_4C")))
void Obj3270_SetField_48_4C(void *a0, int a1, int a2) {
    *(int *)((char *)a0 + 0x48) = a1;
    *(int *)((char *)a0 + 0x4C) = a2;
}

/* jr $ra; sw $a1, 0x3C($a0) */
__attribute__((section(".text.Obj3270_SetField_3C")))
void Obj3270_SetField_3C(void *a0, int a1) {
    *(int *)((char *)a0 + 0x3C) = a1;
}

/* jr $ra; sw $a1, 0x40($a0) */
__attribute__((section(".text.Obj3270_SetField_40")))
void Obj3270_SetField_40(void *a0, int a1) {
    *(int *)((char *)a0 + 0x40) = a1;
}

/* jr $ra; sw $a1, 0x44($a0) */
__attribute__((section(".text.Obj3270_SetField_44")))
void Obj3270_SetField_44(void *a0, int a1) {
    *(int *)((char *)a0 + 0x44) = a1;
}

/* addiu sp,-0x10; sd ra; lw $a0,0x4($a0); ld ra; j Obj33C8_GetShort_98; addiu sp,+0x10 */
__attribute__((section(".text.Obj3270_GetVia4_Obj33C8_98_7770")))
int Obj3270_GetVia4_Obj33C8_98_7770(void *a0) {
    return Obj33C8_GetShort_98(*(void **)((char *)a0 + 0x4));
}

/* addiu sp,-0x10; sd ra; lw $a0,0x4($a0); ld ra; j Obj33C8_GetField_14; addiu sp,+0x10 */
__attribute__((section(".text.Obj3270_GetVia4_Obj33C8_14_7788")))
int Obj3270_GetVia4_Obj33C8_14_7788(void *a0) {
    return Obj33C8_GetField_14(*(void **)((char *)a0 + 0x4));
}

/* addiu sp,-0x10; sd ra; lw $a0,0x4($a0); ld ra; j func_0033CE98; addiu sp,+0x10 */
__attribute__((section(".text.Obj3270_GetVia4_0033CE98_77A0")))
int Obj3270_GetVia4_0033CE98_77A0(void *a0) {
    return func_0033CE98(*(void **)((char *)a0 + 0x4));
}

/* addiu sp,-0x10; sd ra; lw $a0,0x4($a0); ld ra; j func_0033CEF0; addiu sp,+0x10 */
__attribute__((section(".text.Obj3270_GetVia4_0033CEF0_77B8")))
int Obj3270_GetVia4_0033CEF0_77B8(void *a0) {
    return func_0033CEF0(*(void **)((char *)a0 + 0x4));
}

/* addiu sp,-0x10; sd ra; lw $a0,0x4($a0); ld ra; j Obj33C8_GetField_10; addiu sp,+0x10 */
__attribute__((section(".text.Obj3270_GetVia4_Obj33C8_10_77D0")))
int Obj3270_GetVia4_Obj33C8_10_77D0(void *a0) {
    return Obj33C8_GetField_10(*(void **)((char *)a0 + 0x4));
}

/* addiu sp,-0x10; sd ra; lw $a0,0x4($a0); ld ra; j Obj33C8_GetField_18; addiu sp,+0x10 */
__attribute__((section(".text.Obj3270_GetVia4_Obj33C8_18_77E8")))
int Obj3270_GetVia4_Obj33C8_18_77E8(void *a0) {
    return Obj33C8_GetField_18(*(void **)((char *)a0 + 0x4));
}
