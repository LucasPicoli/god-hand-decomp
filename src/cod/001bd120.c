#include "godhand/cOmDoor.h"

/* sn-2.95.3-136 matched TU. */

/* Swing the door shut: only while it is open (bit 0) and not already
 * closing (bit 1), and only before the move state byte reaches 2. */
__attribute__((section(".text.cOmDoor_setClose")))
void cOmDoor_setClose(cOmDoor *self)
{
    int one;
    long v = (unsigned int)self->flags620;
    long b;
    unsigned char *stepArg;
    if ((v & DOOR_FLAG_OPEN) == 0)
    {
        do { } while (0);
        return;
    }
    b = (v >> (one = 1)) & one;
    stepArg = &self->base.stepArg;
    if (b == one)
    {
        return;
    }
    if (self->base.mode < 2)
    {
        self->base.phase = 2;
        self->flags620 &= ~one;
        self->base.mode = 0;
        self->base.step = 0;
        *stepArg = 0;
    }
}
