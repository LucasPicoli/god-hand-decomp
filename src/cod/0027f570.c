#include "godhand/cEm00.h"

/* func_0027F570 — per-frame state machine on the +0x2F6 phase byte:
 * phase 0 fires func_002A8578 with motion params from the +0x304 record and
 * advances to phase 1; both phases then step moveMotion.  sn-2.95.3-136. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void moveMotion(void *a0);

/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027F570"))) void func_0027F570(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xC), EM_RES_REC(res, 0x10), 0.0f, 5, 0, 0);
            self->step++;
            /* fallthrough */
        case 1:
            moveMotion(self);
            break;
    }
}
