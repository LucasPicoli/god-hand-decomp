#include "godhand/cEm00.h"

/* func_001CB828 — refresh speed-rate field then a +0x2F6 phase machine (record field 0xC,
 * mode 0) stepping moveMotion.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern float SetMotionStep(void *a0, float f);
extern int D_005864F0;
/* Phase machine on the step byte, 2 case labels. Calls cEmManage_GetSpeedRate, SetMotionStep,
 * func_002A8578, moveMotion. */
__attribute__((section(".text.func_001CB828"))) void func_001CB828(cEm00 *self)
{
    int res;
    float r = cEmManage_GetSpeedRate(&D_005864F0);
    self->speedRate = r;
    SetMotionStep(self, r);
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xC), 0, 0.0f, 0, 0, 0);
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            break;
    }
}
