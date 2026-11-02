#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* sn-2.95.3-136 matched TU. */

extern int moveMotion(void *a0);

/* func_0027CA50 — +0x2F6 phase machine, twin of func_0027C620. sn-2.95.3-136. */


/* Phase machine on the step byte, 6 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027CA50"))) void func_0027CA50(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x90), EM_RES_REC(res, 0x94), 5, 0.0f, 0, 0);
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            break;
        case 2:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0x98), EM_RES_REC(res, 0x9C), 5, 0.0f, 0, 0);
            self->step = self->step + 1;
        case 3:
            moveMotion(self);
            break;
        case 4:
            res = EM_RES(self);
            func_002A8578(self, EM_RES_REC(res, 0xA0), EM_RES_REC(res, 0xA4), 5, 0.0f, 0, 0);
            self->step = self->step + 1;
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
