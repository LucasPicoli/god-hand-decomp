#include "godhand/cEm00.h"

/* func_001CB8C0 — refresh +0x5A8 speed-rate field, then a +0x2F6 phase machine
 * (record field 0xC, mode 0); phase 0 also spawns effect 0x7B/0xB8 via SetEffect,
 * and the moveMotion-done reset re-arms 0x2F5=1.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern float SetMotionStep(void *a0, float f);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int D_005864F0;
/* Phase machine on the step byte, 2 case labels. Calls cEmManage_GetSpeedRate, SetMotionStep,
 * func_002A8578, SetEffect, moveMotion. */
__attribute__((section(".text.func_001CB8C0"))) void func_001CB8C0(cEm00 *self)
{
    int res;
    float r = cEmManage_GetSpeedRate(&D_005864F0);
    self->speedRate = r;
    SetMotionStep(self, r);
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xC), 0, 0.0f, 0, 0, 0);
            SetEffect(0x7B, 0xB8, self, 0, -1, 0xFFFFFFFFU);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 1;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}
