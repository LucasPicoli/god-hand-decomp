#include "godhand/cEm00.h"

/* func_00281D10 — +0x2F6 phase machine like func_0027F570, but the func_002A8578
 * "t0" argument is 2 when the +0x15B0 flag is set, else 0.  sn-2.95.3-136.
 * (t0's constant is held in a separate long so SN emits move/movn, not movz.) */
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_00281D10"))) void func_00281D10(cEm00 *self)
{
    int res;
    int t0 = 0;
    unsigned long two = 2;
    if (*(unsigned char *)((char *)self + 0x15B0))
        t0 = two;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xC), EM_RES_REC(res, 0x10), 0.0f, 5, t0, 0);
            self->step = self->step + 1;
        case 1:
            moveMotion(self);
            break;
    }
}
