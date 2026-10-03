#include "godhand/cObj.h"

/* cObj_setSuspend — sets (a1==1) or clears bit 0x8000 of the flags at a0+0x250.
 * Compiled with sn-2.95.3-136. */

/* Suspend the actor (suspend == 1) or let it run again. */
__attribute__((section(".text.cObj_setSuspend")))
void cObj_setSuspend(cObj *self, int suspend) {
    if (suspend == 1) {
        int flags = self->objFlags;
        self->objFlags = flags | COBJ_F_SUSPEND;
    } else {
        int flags = self->objFlags;
        self->objFlags = flags & 0xFFFF7FFF;
    }
}
