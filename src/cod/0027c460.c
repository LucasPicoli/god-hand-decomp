#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern unsigned int irand(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern int D_005FEE00;

/* Phase machine on the step byte, 7 case labels. Calls func_002A8578, moveMotion, irand,
 * cSnd_SeCall_2CBA48. */
__attribute__((section(".text.func_0027C460"))) void func_0027C460(cEm00 *self)
{
    char *v0;
    float f1, f0;

    self->unk1560 |= 3;
    switch (self->step) {
        case 0:
            v0 = (char *)self->resource;
            func_002A8578(self, EM_RES_REC((int)v0, 0xC0), EM_RES_REC((int)v0, 0xC4), 0.0f, 5, 0,
                          0);
            self->timer = 15.0f;
            self->step += 1;
            /* fallthrough */
        case 1:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            f1 = self->timer;
            if (f1 > 0.0f) {
                f0 = f1 - self->speedRate;
                self->timer = f0;
                if (f0 <= 0.0f) {
                    switch (irand() % 5) {
                        case 0:
                        default:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xA, self, 0, 0, 0, 0);
                            break;
                        case 1:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xB, self, 0, 0, 0, 0);
                            break;
                        case 2:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xE, self, 0, 0, 0, 0);
                            break;
                        case 3:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xF, self, 0, 0, 0, 0);
                            break;
                        case 4:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x10, self, 0, 0, 0, 0);
                            break;
                    }
                }
            }
            break;
    }
}
