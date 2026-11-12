/* Struct: CGUnk_0010B5C8_t — own word at +0x1560; embeds shared CGStateBlock4 at +0x2F4 (shares the +0x2F4..+0x2F7 block with CGObj1D00_t — likely a common CG base class). */
#include "godhand/cGameObj.h"

/* ── All-zero (5-insn): sb 0,2F7; sb 0,2F4; sb 0,2F5; jr; delay:sb 0,2F6 ── */
/* Optimizer reorders 4 independent zero-stores non-trivially; use ASM.    */
/* func_00281260: the do{}while(0) barriers keep the retail store order. */
__attribute__((section(".text.func_00281260")))
void func_00281260(unsigned char *p) {
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

/* ── Group B6 (6-insn, 2F7=a1): li; sb a1,2F7; sb v0,2F5; sb 0,2F4; jr; delay:2F6 ── */
/* Note: -O2 reverses adjacent equal-value zero-stores.                     */
/* Write 2F6=0 before 2F4=0 in C so optimizer produces 2F4,2F6 → delay:2F6 */

/* addiu v0,1; sb a1,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_SetState_1_a1")))
void Obj2810_SetState_1_a1(char *a0, int a1) {
    a0[0x2F7] = a1;
    a0[0x2F5] = 1;
    a0[0x2F6] = 0;
    a0[0x2F4] = 0;
}

/* addiu v0,2; sb a1,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_SetState_2_a1")))
void Obj2810_SetState_2_a1(char *a0, int a1) {
    a0[0x2F7] = a1;
    a0[0x2F5] = 2;
    a0[0x2F6] = 0;
    a0[0x2F4] = 0;
}

/* ── Branched_leaf: func_002812A8 (0x74 B) — INCLUDE_ASM nonmatching ── */

/* ee-2.9-991111 (the owner TU src/cod/002810.c key; sn-2.95.3-136 also matches): the same body as its twin func_002831C8 in src/cod/002831c8.c. */

static inline void cGameObj_setState(cGameObj *self, unsigned char phase, unsigned char step, unsigned char arg)
{
    self->stepArg = arg;
    self->phase = phase;
    self->step = step;
    self->mode = 0;
}

/* Starts phase 3 at the step for `kind`: 0, 2, 4 or 6 for kinds 0 to 3. */
__attribute__((section(".text.func_002812A8")))
void func_002812A8(cGameObj *self, unsigned int kind, unsigned char arg)
{
    switch (kind) {
    default:
    case 0:
        cGameObj_setState(self, 3, 0, arg);
        break;
    case 1:
        cGameObj_setState(self, 3, 2, arg);
        break;
    case 2:
        cGameObj_setState(self, 3, 4, arg);
        break;
    case 3:
        cGameObj_setState(self, 3, 6, arg);
        break;
    }
}

/* ── Group A (6-insn, 2F6=2F7=0): li; sb 0,2F7; sb v0,2F5; sb 0,2F4; jr; delay:2F6 ── */

/* addiu v0,4; sb 0,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_ClearState_4")))
void Obj2810_ClearState_4(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 4;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

/* addiu v0,5; sb 0,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_ClearState_5")))
void Obj2810_ClearState_5(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 5;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

/* addiu v0,6; sb 0,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_ClearState_6")))
void Obj2810_ClearState_6(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 6;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

/* ── Branched_leaf: func_00281368 (0x54 B) ── */

__attribute__((section(".text.func_00281368")))
void func_00281368(unsigned char *p, int mode) {
    if (mode == 1) goto a1;
    if (mode == 0) goto def;
    if (mode == 2) goto a2;
def:
    p[0x2F4] = 0; p[0x2F5] = 7; p[0x2F6] = 0; p[0x2F7] = 0;
    return;
a1:
    p[0x2F5] = 7; p[0x2F6] = 2; p[0x2F4] = 0; p[0x2F7] = 0;
    return;
a2:
    p[0x2F5] = 7; p[0x2F6] = 4; p[0x2F4] = 0; p[0x2F7] = 0;
}

/* ── Group B6 (6-insn, 2F7=a1) ── */

/* addiu v0,8; sb a1,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_SetState_8_a1")))
void Obj2810_SetState_8_a1(char *a0, int a1) {
    a0[0x2F7] = a1;
    a0[0x2F5] = 8;
    a0[0x2F6] = 0;
    a0[0x2F4] = 0;
}

/* addiu v0,9; sb a1,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_SetState_9_a1")))
void Obj2810_SetState_9_a1(char *a0, int a1) {
    a0[0x2F7] = a1;
    a0[0x2F5] = 9;
    a0[0x2F6] = 0;
    a0[0x2F4] = 0;
}

/* ── Branched_leaf: func_002813F0 (0x68 B) ── */

__attribute__((section(".text.func_002813F0")))
void func_002813F0(unsigned char *p, int mode) {
    if (mode == 1) goto a1;
    if (mode == 0) goto def;
    if (mode == 2) goto a2;
    if (mode == 3) goto a3;
def:
    p[0x2F4] = 0; p[0x2F5] = 0xA; p[0x2F6] = 0; p[0x2F7] = 0;
    return;
a1:
    p[0x2F5] = 0xA; p[0x2F6] = 2; p[0x2F4] = 0; p[0x2F7] = 0;
    return;
a2:
    p[0x2F5] = 0xA; p[0x2F6] = 4; p[0x2F4] = 0; p[0x2F7] = 0;
    return;
a3:
    p[0x2F5] = 0xA; p[0x2F6] = 6; p[0x2F4] = 0; p[0x2F7] = 0;
}

/* ── Group B6 (6-insn, 2F7=a1) ── */

/* addiu v0,0xE; sb a1,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_SetState_E_a1")))
void Obj2810_SetState_E_a1(char *a0, int a1) {
    a0[0x2F7] = a1;
    a0[0x2F5] = 0xE;
    a0[0x2F6] = 0;
    a0[0x2F4] = 0;
}

/* ── Branched_leaf: func_00281470 (0x44 B) ── */

__attribute__((section(".text.func_00281470")))
void func_00281470(int a0, unsigned char a1) {
    switch (a1) {
    case 0:
        *(unsigned char *)(a0 + 0x2F4) = 0;
        *(unsigned char *)(a0 + 0x2F5) = 0xF;
        *(unsigned char *)(a0 + 0x2F6) = 0;
        *(unsigned char *)(a0 + 0x2F7) = 0;
        break;
    case 1:
        *(unsigned char *)(a0 + 0x2F4) = 0;
        *(unsigned char *)(a0 + 0x2F5) = 0xF;
        *(unsigned char *)(a0 + 0x2F6) = 2;
        *(unsigned char *)(a0 + 0x2F7) = 0;
        break;
    default:
        *(unsigned char *)(a0 + 0x2F4) = 0;
        *(unsigned char *)(a0 + 0x2F5) = 0xF;
        *(unsigned char *)(a0 + 0x2F6) = 0;
        *(unsigned char *)(a0 + 0x2F7) = 0;
        break;
    }
}

/* ── Group A (6-insn, 2F6=2F7=0) ── */

/* addiu v0,0xB; sb 0,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_ClearState_B")))
void Obj2810_ClearState_B(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 0xB;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

/* addiu v0,0xC; sb 0,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_ClearState_C")))
void Obj2810_ClearState_C(char *a0) {
    a0[0x2F4] = 0;
    a0[0x2F5] = 0xC;
    a0[0x2F6] = 0;
    a0[0x2F7] = 0;
}

/* addiu v0,0xD; sb a1,2F7; sb v0,2F5; sb 0,2F4; jr; delay:sb 0,2F6 */
__attribute__((section(".text.Obj2810_SetState_D_a1")))
void Obj2810_SetState_D_a1(char *a0, int a1) {
    a0[0x2F7] = a1;
    a0[0x2F5] = 0xD;
    a0[0x2F6] = 0;
    a0[0x2F4] = 0;
}

/* ── Branched_leaf: func_00281500, func_00281560 (0x5C B each) — nonmatching ── */

__attribute__((section(".text.func_00281500")))
void func_00281500(unsigned char *p, int mode) {
    int m = mode & 0xFF;
    if (m == 1) goto a1;
    if (m < 2) goto def;
    if (m == 2) goto a2;
def:
    p[0x2F4] = 0; p[0x2F5] = 0x10; p[0x2F6] = 0; p[0x2F7] = 0;
    return;
a1:
    p[0x2F5] = 0x10; p[0x2F6] = 2; p[0x2F4] = 0; p[0x2F7] = 0;
    return;
a2:
    p[0x2F5] = 0x10; p[0x2F6] = 4; p[0x2F4] = 0; p[0x2F7] = 0;
}

__attribute__((section(".text.func_00281560")))
void func_00281560(unsigned char *p, int mode) {
    int m = mode & 0xFF;
    if (m == 1) goto a1;
    if (m < 2) goto def;
    if (m == 2) goto a2;
def:
    p[0x2F4] = 0; p[0x2F5] = 0x11; p[0x2F6] = 0; p[0x2F7] = 0;
    return;
a1:
    p[0x2F5] = 0x11; p[0x2F6] = 2; p[0x2F4] = 0; p[0x2F7] = 0;
    return;
a2:
    p[0x2F5] = 0x11; p[0x2F6] = 4; p[0x2F4] = 0; p[0x2F7] = 0;
}

/* ── Getter: lw v0,0x1560(a0); jr ra; delay:andi v0,v0,1 ── */

/* lw v0, 0x1560(a0); jr ra; delay:andi v0,v0,1 */
__attribute__((section(".text.Obj2810_GetField1560_Bit0")))
int Obj2810_GetField1560_Bit0(char *a0) {
    return *(int *)(a0 + 0x1560) & 1;
}

/* ── Getter: lw v0,0x1560(a0); andi v0,v0,2; jr ra; delay:sltu v0,zero,v0 ── */
/* The `> 0` form yields andi+sltu (`& 2` / `!= 0` do not).                  */
__attribute__((section(".text.func_002815D0")))
int func_002815D0(char *a0) {
    return (*(int *)(a0 + 0x1560) & 2) > 0;
}

/* ── Call-chain (INCLUDE_ASM nonmatching — T1 will match) ── */

/* GetClassDescB_2815E8 moved to src/cod/merged_orphans_b.c (matched, SN pin). */

/* ── PERMANENT: func_002816E0 (0x260 B) — complex init — stays in asm ── */
