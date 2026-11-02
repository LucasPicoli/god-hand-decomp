#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */





/* Phase machine on the step byte, 8 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027FEB0"))) void func_0027FEB0(cEm00 *self)
{
    int res;
    unsigned long t0 = 0;
    switch (self->step) {
        case 0:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x138), EM_RES_REC(res, 0x13C), 5, 0.0f, t0, 0);
            self->step++;
            goto L_mm;
        case 2:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x140), EM_RES_REC(res, 0x144), 5, 0.0f, t0, 0);
            self->step++;
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x140), EM_RES_REC(res, 0x144), 5, 0.0f, t0, 0);
            self->step++;
        case 5:
            if (moveMotion(self) != 0) {
                self->mode = 0;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            }
            break;
        case 6:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x150), EM_RES_REC(res, 0x154), 5, 0.0f, t0, 0);
            self->step++;
        case 7:
            moveMotion(self);
            break;
    }
}
