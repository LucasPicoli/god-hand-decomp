#include "godhand/cEm00.h"

/* func_0027C620 — +0x2F6 phase machine (record fields 0x28/0x2C, mode 5): phase 0
 * fires func_002A8578 and registers a render struct (InitRenderStruct_2A8608,
 * 0xBC/0x1C, flags from +0x15B0), advances; both phases step moveMotion and reset
 * the 0x2F4..0x2F7 phase block when done.  sn-2.95.3-136. */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void InitRenderStruct_2A8608(void *a0, int a1, int a2, int a3, int t0, int t1);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, InitRenderStruct_2A8608,
 * moveMotion. */
__attribute__((section(".text.func_0027C620"))) void func_0027C620(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x28), EM_RES_REC(res, 0x2C), 0.0f, 5, 0, 0);
            InitRenderStruct_2A8608(self, 0xBC, 0x1C, 0, 2, self->gotoFlags);
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
