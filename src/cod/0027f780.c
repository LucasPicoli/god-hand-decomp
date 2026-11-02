#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





/* Phase machine on the step byte, 6 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027F780"))) void func_0027F780(cEm00 *self)
{
    int res;
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                int v1 = self->resource;
                func_002A8578(self, EM_RES_REC(v1, 0x48), EM_RES_REC(v1, 0x50), 5, 0.0f, t0, 0);
            } else {
                int v2 = self->resource;
                func_002A8578(self, EM_RES_REC(v2, 0x48), EM_RES_REC(v2, 0x4C), 5, 0.0f, t0, 0);
            }
            self->step++;
            goto L_mm;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x48), EM_RES_REC(res, 0x58), 5, 0.0f, t0, 0);
            self->step++;
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x48), EM_RES_REC(res, 0x60), 5, 0.0f, t0, 0);
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
