#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int GetSeqSEBase(void *a0);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */







/* Phase machine on the step byte, 6 case labels. Calls func_002A8578, cSnd_SeCall_2CBA48,
 * GetSeqSEBase, moveMotion. */
__attribute__((section(".text.func_00280770"))) void func_00280770(cEm00 *self)
{
    int res;
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x120), EM_RES_REC(res, 0x124), 0.0f, 2, t0, 0);
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(self), self, 0, 0, 0, 0);
            self->step++;
            goto L_mm;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x128), EM_RES_REC(res, 0x12C), 0.0f, 2, t0, 0);
            self->step++;
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x130), EM_RES_REC(res, 0x134), 0.0f, 2, t0, 0);
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
