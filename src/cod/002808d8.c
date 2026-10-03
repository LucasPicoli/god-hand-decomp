#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void *Getplayer(void);
extern float SetMotionStep(void *a0, float f);

/* sn-2.95.3-136 matched TU. */







/* Phase machine on the step byte, 6 case labels. Calls Getplayer, SetMotionStep, func_002A8578,
 * moveMotion. */
__attribute__((section(".text.func_002808D8"))) void func_002808D8(cEm00 *self)
{
    int res;
    unsigned long t0 = 0;
    float r = *(float *)((char *)Getplayer() + 0x5A8);
    self->speedRate = r;
    SetMotionStep(self, r);
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x168), EM_RES_REC(res, 0x16C), 0.0f, 2, t0, 0);
            self->step++;
            goto L_mm;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x170), EM_RES_REC(res, 0x174), 0.0f, 2, t0, 0);
            self->step++;
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x178), EM_RES_REC(res, 0x17C), 0.0f, 2, t0, 0);
            self->step++;
        case 5:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}
