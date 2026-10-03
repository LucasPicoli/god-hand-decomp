#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */







/* Phase machine on the step byte, 6 case labels. Calls cSnd_SeCall_2CBA48, func_002A8578,
 * moveMotion. */
__attribute__((section(".text.func_0027C888"))) void func_0027C888(cEm00 *self)
{
    switch (self->step) {
        case 0:
            cSnd_SeCall_2CBA48(D_005FEE00, 1, 0xC, self, 0, 0, 0, 0);
            if (self->stepArg) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x60), EM_RES_REC(v, 0x64), 0.0f, 0, 0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x48), EM_RES_REC(v, 0x4C), 0.0f, 0, 0, 0);
            }
            self->step++;
            goto L_mm;
        case 2:
            if (self->stepArg) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x68), EM_RES_REC(v, 0x6C), 0.0f, 3, 0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x50), EM_RES_REC(v, 0x54), 0.0f, 3, 0, 0);
            }
            self->step++;
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            if (self->stepArg) {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x70), EM_RES_REC(v, 0x74), 0.0f, 3, 0, 0);
            } else {
                int v = self->resource;
                func_002A8578(self, EM_RES_REC(v, 0x58), EM_RES_REC(v, 0x5C), 0.0f, 3, 0, 0);
            }
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
