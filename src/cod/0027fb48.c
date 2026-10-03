#include "godhand/cEm00.h"

/* func_0027FB48 — +0x2F6 phase machine (record fields 0x78/0x7C, mode 5): phase 0
 * fires func_002A8578, sets +0x5F0=1 and advances; both phases step moveMotion and
 * clear the 0x2F4..0x2F7 phase block when it reports done.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027FB48"))) void func_0027FB48(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x78), EM_RES_REC(res, 0x7C), 0.0f, 5, 0, 0);
            self->timerA = 1;
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
