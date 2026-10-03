#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);

/* sn-2.95.3-136 matched TU. */




/* Phase machine on the step byte, 6 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00281F38"))) void func_00281F38(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            if (self->stepArg) {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x60), EM_RES_REC(res, 0x68), 0.0f, 5, t0, 0);
            } else {
                res = self->resource;
                func_002A8578(self, EM_RES_REC(res, 0x60), EM_RES_REC(res, 0x64), 0.0f, 5, t0, 0);
            }
            self->step++;
            goto L_mm;
        case 2:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x6C), EM_RES_REC(res, 0x70), 0.0f, 5, t0, 0);
            self->step++;
            /* fallthrough */
        case 1:
        case 3:
        L_mm:
            moveMotion(self);
            break;
        case 4:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0x74), EM_RES_REC(res, 0x78), 0.0f, 5, t0, 0);
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
