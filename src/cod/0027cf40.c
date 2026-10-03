#include "godhand/cEm00.h"

/* func_0027CF40 — +0x2F6 phase machine; phase 0 picks func_002A8578 record fields
 * by the +0x2F7 sub-flag (0xB0/0xB4 when set, else 0xB8/0xBC; mode 3), advances;
 * both phases step moveMotion.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027CF40"))) void func_0027CF40(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0xB0), EM_RES_REC(res, 0xB4), 0.0f, 3, 0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0xB8), EM_RES_REC(res, 0xBC), 0.0f, 3, 0, 0);
            }
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            break;
    }
}
