#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern float SetMotionStep(void *a0, float f);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int D_005864F0;

/* SN ProDG ee-gcc 2.95.3 matched TU. */






/* Phase machine on the step byte, 6 case labels. Calls cEmManage_GetSpeedRate, SetMotionStep,
 * func_002A8578, moveMotion. */
__attribute__((section(".text.func_001B8338"))) void func_001B8338(cEm00 *self)
{
    int res;
    float r = cEmManage_GetSpeedRate(&D_005864F0);
    float f2 = self->timer2;
    if (0.0f < f2) {
        self->timer2 = f2 - r;
    }
    self->speedRate = r;
    SetMotionStep(self, r);
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xC), 0, 0.0f, 0, 0, 0);
            moveMotion(self);
            *(unsigned short *)((char *)self + 0x434) |= 8;
            self->step++;
            break;
        case 1:
            break;
        case 2:
            self->step++;
            /* fallthrough */
        case 3:
            *(unsigned short *)((char *)self + 0x434) |= 8;
            if (moveMotion(self) != 0) {
                *(unsigned char *)((char *)self + 0x601) = 1;
            }
            break;
        case 4:
            self->step++;
            break;
        case 5:
            break;
    }
}
