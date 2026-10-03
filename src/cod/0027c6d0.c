#include "godhand/cEm00.h"

/* func_0027C6D0 — +0x2F6 phase machine (record fields 0x30/0x34, mode 5): phase 0
 * triggers a sound (cSnd_SeCall_2CBA48) and func_002A8578, advances; both phases
 * step moveMotion and reset the 0x2F4..0x2F7 phase block when done.  sn-2.95.3-136.
 * (cSnd_SeCall_2CBA48 declared int-returning so SN keeps the record ptr in v1.) */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int D_005FEE00[];

/* Phase machine on the step byte, 2 case labels. Calls cSnd_SeCall_2CBA48, func_002A8578,
 * moveMotion. */
__attribute__((section(".text.func_0027C6D0"))) void func_0027C6D0(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0, self, 0, 0, 0, 0);
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x30), EM_RES_REC(res, 0x34), 0.0f, 5, 0, 0);
            self->step = self->step + 1;
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
    }
}
