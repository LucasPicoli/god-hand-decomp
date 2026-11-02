#include "godhand/cEm00.h"
#include "godhand/motion.h"

/* func_0027F570 — per-frame state machine on the +0x2F6 phase byte:
 * phase 0 fires func_002A8578 with motion params from the +0x304 record and
 * advances to phase 1; both phases then step moveMotion.  sn-2.95.3-136. */


/* Phase machine on the step byte, 2 case labels. Calls func_002A8578, moveMotion. */
__attribute__((section(".text.func_0027F570"))) void func_0027F570(cEm00 *self)
{
    int res;
    switch (self->step) {
        case 0:
            res = self->resource;
            func_002A8578(self, EM_RES_REC(res, 0xC), EM_RES_REC(res, 0x10), 5, 0.0f, 0, 0);
            self->step++;
            /* fallthrough */
        case 1:
            moveMotion(self);
            break;
    }
}
