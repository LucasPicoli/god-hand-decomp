#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





/* Phase machine on the step byte, 6 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027FBE8"))) void func_0027FBE8(cEm00 *self)
{
    int res;
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x14), EM_RES_REC(res, 0x18), 0.0f, 5, t0, 0);
            self->timerA = 1;
            self->step++;
            /* fallthrough */
        case 1:
            moveMotion(self);
            break;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x1C), EM_RES_REC(res, 0x20), 0.0f, 5, t0, 0);
            self->timerA = 1;
            self->step++;
            /* fallthrough */
        case 3:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
        case 4:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x24), EM_RES_REC(res, 0x28), 0.0f, 5, t0, 0);
            self->timerA = 1;
            self->step++;
            /* fallthrough */
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
