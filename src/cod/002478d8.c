/* sn-2.95.3-136 matched TU. */

/* func_002478D8 parked, sn-2.95.3-136 --fp-hazard-rules mtc1: EXACT 137/143, insn delta -1, ONE missing nop: retail has 'mtc1 $at,$f1 ; L: nop ; c.lt.s $f0,$f1' (nop AFTER the branch-target label). cc1 emits no #nop hint across a label, so no source or listed rule reaches it. Tool ask: an mtc1 rule that pads a label-separated mtc1 -> c.<cond>.s. */
#include "godhand/cEm00.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float f);
extern void cObjBase_addNullSpeed(void *a0, float f);
extern void cActionButton_set(void *, int, int, int, void *, void *, int);
extern void InitStateBytes_2478B8(void);
extern char D_00568288;
__attribute__((section(".text.func_002478D8")))
void func_002478D8(cEm00 *self)
{
        float one;
    switch (self->step) {
    case 0: {
        char *p = (char *)(int)self->pos;
        char *d = &self->unk580;
        self->stepArg = 0;
        if (d != p) {
            *(float *)(d + 0) = *(float *)(p + 0);
            *(float *)(d + 4) = *(float *)(p + 4);
            *(float *)(d + 8) = *(float *)(p + 8);
        }
        self->step += 1;
    }
    case 1: {
        char *p = (char *)(int)self->pos;
        char *d = &self->unk580;
        int m, b;
        if (p != d) {
            *(float *)(p + 0) = *(float *)(d + 0);
            *(float *)(p + 4) = *(float *)(d + 4);
            *(float *)(p + 8) = *(float *)(d + 8);
        }
        self->unk617 = 1;
        self->hitFlash = 3.0f;
        m = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        b = self->resource;
        func_002A8578(self, EM_RES_REC(b, 0x2BC), EM_RES_REC(b, 0x2C0), 0.0f, 0, m, 0);
        moveMotion(self);
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        self->moveFlags |= 0x400;
        if (self->unk768 < 0.7853982f) {
            float lim = 4.0f;
            if (self->stepArg != 0) {
                lim = 9.0f;
            }
            if (self->playerDist < lim) {
                self->stepArg = 1;
                cActionButton_set(&D_00568288, 7, 0x2A, 0, (void *)InitStateBytes_2478B8, self, 0);
                return;
            }
        }
        self->stepArg = 0;
        break; }
    case 2: {
        int m = Obj0000_Get_Byte_17C3_NZ_2_276468(self) & 0xFFFF;
        int b = self->resource;
        func_002A8578(self, EM_RES_REC(b, 0x2BC), EM_RES_REC(b, 0x2C0), 0.0f, 0, m, 0);
        self->step += 1;
    }
    case 3:
        if (moveMotion(self) != 0) {
            func_002705D8(self);
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(self, one);
        cObjBase_addNullSpeed(self, one);
        break;
    }
}
