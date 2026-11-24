#include "godhand/cEm00.h"
#include "godhand/cSnd.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int moveMotion(void *a0);
extern unsigned int irand(void);

/* Phase machine on the step byte, 7 case labels. Calls func_002A8578, moveMotion, irand,
 * cSnd_SeCall_2CBA48. */
__attribute__((section(".text.func_0027C460"))) void func_0027C460(cEm00 *self)
{
    char *v0;
    float f1, f0;

    self->unk1560 |= 3;
    switch (self->step) {
        case 0:
            v0 = (char *)EM_RES(self);
            func_002A8578(self, EM_RES_REC((int)v0, 0xC0), EM_RES_REC((int)v0, 0xC4), 5, 0.0f, 0,
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
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xA, (cObj *)self, 0, 0, 0, 0);
                            break;
                        case 1:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xB, (cObj *)self, 0, 0, 0, 0);
                            break;
                        case 2:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xE, (cObj *)self, 0, 0, 0, 0);
                            break;
                        case 3:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0xF, (cObj *)self, 0, 0, 0, 0);
                            break;
                        case 4:
                            cSnd_SeCall_2CBA48(&D_005FEE00, 1, 0x10, (cObj *)self, 0, 0, 0, 0);
                            break;
                    }
                }
            }
            break;
    }
}
