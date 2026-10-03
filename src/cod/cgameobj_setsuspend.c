#include "godhand/cGameObj.h"

/* cGameObj_setSuspend — when a1==1 set the suspend flags (0x8000 at 0x250,
 * 0x8 at 0x5A0); otherwise clear them.  sn-2.95.3-136. */

/* Sets the suspend bits in objFlags and scrFlags when on is 1, clears them
 * otherwise. */
__attribute__((section(".text.cGameObj_setSuspend")))
void cGameObj_setSuspend(cGameObj *self, int on) {
    if (on == 1)
        self->objFlags |= GAMEOBJ_OBJ_SUSPEND;
    else
        self->objFlags &= ~GAMEOBJ_OBJ_SUSPEND;
    if (on == 1)
        self->scrFlags |= GAMEOBJ_SCR_SUSPEND;
    else
        self->scrFlags &= ~GAMEOBJ_SCR_SUSPEND;
}
