#include "godhand/cEm00.h"

/* func_0027F8D8 — +0x2F6 phase machine: phase 0 fires func_002A8578 (params from
 * +0x304 record, fields 0x64/0x68) and advances; both phases step moveMotion, and
 * when it reports done the 0x2F4..0x2F7 phase block is cleared.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027F8D8"))) void func_0027F8D8(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x64), EM_RES_REC(res, 0x68), 0.0f, 5, 0, 0);
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
