/* Struct: CGObj1D00_t — own fields +0x664/+0x665/+0x668; embeds shared CGStateBlock4 at +0x2F4 (shares the +0x2F4..+0x2F7 {reset,state,substate,arg} block with CGUnk_0010B5C8_t — likely a common CG base class). */
#include "godhand/cOmBase.h"
#include "godhand/cOmWeapon.h"
#include "include_asm.h"

/* ── PERMANENT (6) — fp-heavy / bnel — stay in monolithic asm/cod/000000 ── */
/* func_001D0090 (fp-heavy+bnel, 0x78 B) — PERMANENT */
/* func_001D0108 (fp-heavy, 0x38 B) — PERMANENT */
/* func_001D0140 (fp-heavy+bnel, 0x100 B) — PERMANENT */
/* func_001D0240 (fp-heavy+bnel, 0x100 B) — PERMANENT */
/* func_001D0340 (fp-heavy+bnel, 0xC8 B) — PERMANENT */
/* func_001D0408 (fp-heavy+bnel, 0xC8 B) — PERMANENT */

/* ── Group A: 6-insn, a0[2F7]=0, a0[2F6]=0 (5 functions) ────────────────── */
/* C order: 2F4, 2F5=V, 2F6, 2F7 → ASM: li; sb 2F7; sb v0·2F5; sb 2F4; jr; delay:2F6 */

/* Set the four state bytes: mode 0, phase 6, step 0, stepArg 0. */
__attribute__((section(".text.Obj1D00_ClearState_6")))
void Obj1D00_ClearState_6(cOmBase *self) {
    self->mode = 0;
    self->phase = 6;
    self->step = 0;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 0, stepArg 0. */
__attribute__((section(".text.Obj1D00_ClearState_7")))
void Obj1D00_ClearState_7(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 0;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 8, step 0, stepArg 0. */
__attribute__((section(".text.Obj1D00_ClearState_8")))
void Obj1D00_ClearState_8(cOmBase *self) {
    self->mode = 0;
    self->phase = 8;
    self->step = 0;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 9, step 0, stepArg 0. */
__attribute__((section(".text.Obj1D00_ClearState_9")))
void Obj1D00_ClearState_9(cOmBase *self) {
    self->mode = 0;
    self->phase = 9;
    self->step = 0;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 0xA, step 0, stepArg 0. */
__attribute__((section(".text.cOmWeapon_setWing")))
void cOmWeapon_setWing(cOmBase *self) {
    self->mode = 0;
    self->phase = 0xA;
    self->step = 0;
    self->stepArg = 0;
}

/* ── Group D: 6-insn, a0[2F5]=a0[2F6]=6, a0[2F7]=a1 (1 function) ────────── */
/* C order: 2F5, 2F7, 2F6, 2F4 → ASM: li; sb a1·2F7; sb v0·2F6; sb 0·2F4; jr; delay:v0·2F5 */

/* Set the four state bytes: phase 6, stepArg arg, step 6, mode 0. */
__attribute__((section(".text.Obj1D00_SetState6_Variant6_a1")))
void Obj1D00_SetState6_Variant6_a1(cOmBase *self, int arg) {
    self->phase = 6;
    self->stepArg = arg;
    self->step = 6;
    self->mode = 0;
}

/* ── Group B: 8-insn, a0[2F7]=a1 (9 functions) ──────────────────────────── */
/* C order: 2F7=a1, 2F5=V, 2F6=W, 2F4=0 → ASM: li v0; li v1; sb a1·2F7; sb v0·2F5; sb v1·2F6; jr; delay:2F4 */

/* Set the four state bytes: stepArg arg, phase 6, step 2, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_6_2_a1")))
void Obj1D00_SetState_6_2_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 6;
    self->step = 2;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 6, step 4, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_6_4_a1")))
void Obj1D00_SetState_6_4_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 6;
    self->step = 4;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 6, step 0xC, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_6_C_a1")))
void Obj1D00_SetState_6_C_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 6;
    self->step = 0xC;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 6, step 8, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_6_8_a1")))
void Obj1D00_SetState_6_8_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 6;
    self->step = 8;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 6, step 0xE, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_6_E_a1")))
void Obj1D00_SetState_6_E_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 6;
    self->step = 0xE;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 7, step 0xA, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_7_A_a1")))
void Obj1D00_SetState_7_A_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 7;
    self->step = 0xA;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 7, step 0xC, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_7_C_a1")))
void Obj1D00_SetState_7_C_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 7;
    self->step = 0xC;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 7, step 0xE, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_7_E_a1")))
void Obj1D00_SetState_7_E_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 7;
    self->step = 0xE;
    self->mode = 0;
}

/* Set the four state bytes: stepArg arg, phase 7, step 0x1A, mode 0. */
__attribute__((section(".text.Obj1D00_SetState_7_1A_a1")))
void Obj1D00_SetState_7_1A_a1(cOmBase *self, int arg) {
    self->stepArg = arg;
    self->phase = 7;
    self->step = 0x1A;
    self->mode = 0;
}

/* ── Group C: 8-insn, a0[2F7]=0 (11 functions) ──────────────────────────── */
/* C order: 2F4=0, 2F5=V, 2F6=W, 2F7=0 → ASM: li v0; li v1; sb v0·2F5; sb v1·2F6; sb 0·2F7; jr; delay:2F4 */

/* Set the four state bytes: mode 0, phase 6, step 0xA, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_6_A")))
void Obj1D00_SetState_6_A(cOmBase *self) {
    self->mode = 0;
    self->phase = 6;
    self->step = 0xA;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 2, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_2")))
void Obj1D00_SetState_7_2(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 2;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 4, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_4")))
void Obj1D00_SetState_7_4(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 4;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 6, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_6")))
void Obj1D00_SetState_7_6(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 6;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 8, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_8")))
void Obj1D00_SetState_7_8(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 8;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 0x10, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_10")))
void Obj1D00_SetState_7_10(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 0x10;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 0x12, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_12")))
void Obj1D00_SetState_7_12(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 0x12;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 0x14, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_14")))
void Obj1D00_SetState_7_14(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 0x14;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 0x16, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_16")))
void Obj1D00_SetState_7_16(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 0x16;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 0x18, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_18")))
void Obj1D00_SetState_7_18(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 0x18;
    self->stepArg = 0;
}

/* Set the four state bytes: mode 0, phase 7, step 0x1C, stepArg 0. */
__attribute__((section(".text.Obj1D00_SetState_7_1C")))
void Obj1D00_SetState_7_1C(cOmBase *self) {
    self->mode = 0;
    self->phase = 7;
    self->step = 0x1C;
    self->stepArg = 0;
}

/* ── Group E: 2-insn getters (2 functions) ───────────────────────────────── */
/* jr ra; lbu v0, offset(a0) */

__attribute__((section(".text.cOmWeapon_ckGetEnable")))
int cOmWeapon_ckGetEnable(cOmWeapon *self) {
    return self->unk664;
}

__attribute__((section(".text.Obj1D00_GetField_665")))
int Obj1D00_GetField_665(cOmWeapon *self) {
    return self->unk665;
}

/* ── Group F: BRANCHED-LEAF (1 function) ─────────────────────────────────── */
/* Count the timer down by dt frames; returns 1 once it has run out (and clamps it to 0). */
__attribute__((section(".text.cOmWeapon_SetDamage")))
int cOmWeapon_SetDamage(cOmWeapon *self, int dt) {
    int val = self->timer - dt;
    self->timer = val;
    if (val <= 0) { self->timer = 0; return 1; }
    return 0;
}
