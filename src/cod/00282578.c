#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */




/* Phase machine on the step byte, 8 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00282578"))) void func_00282578(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x138), EM_RES_REC(res, 0x13C), 0.0f, 5, t0, 0);
            self->step++;
            goto L_mm;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x140), EM_RES_REC(res, 0x144), 0.0f, 5, t0, 0);
            self->step++;
            /* fallthrough */
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x148), EM_RES_REC(res, 0x14C), 0.0f, 5, t0, 0);
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
        case 6:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x150), EM_RES_REC(res, 0x154), 0.0f, 5, t0, 0);
            self->step++;
            /* fallthrough */
        case 7:
            moveMotion(self);
            break;
    }
}
