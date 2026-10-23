/* sn-2.95.3-136: cOmDoor_setOpen, start a door swinging one way or the other: the open heading is
 * 90 or 100 degrees from the closed one. Nothing happens when the door is open, locked or busy. */
#include "godhand/cOmDoor.h"

extern float Adjust_theta(float angle);

__attribute__((section(".text.cOmDoor_setOpen")))
void cOmDoor_setOpen(cOmDoor *self, long kind, int instant)
{
    long one = 1;
    long v = (unsigned int)self->flags620;

    if ((v & one) == one) {
        return;
    }
    if (((v >> one) & one) == one) {
        return;
    }
    if (self->base.mode >= 2) {
        return;
    }
    self->closedHeading = self->base.rot[1];
    switch (kind) {
    case DOOR_OPEN_NEAR:
        switch (self->base.actorId) {
        case DOOR_ACTOR_A:
        case DOOR_ACTOR_B:
        case DOOR_ACTOR_C:
            self->openHeading = Adjust_theta(self->base.rot[1] - DOOR_ANGLE_90);
            break;
        default:
            self->openHeading = Adjust_theta(self->base.rot[1] - DOOR_ANGLE_100);
            break;
        }
        break;
    case DOOR_OPEN_FAR:
        switch (self->base.actorId) {
        case DOOR_ACTOR_A:
        case DOOR_ACTOR_B:
        case DOOR_ACTOR_C:
            self->openHeading = Adjust_theta(self->base.rot[1] + DOOR_ANGLE_90);
            break;
        default:
            self->openHeading = Adjust_theta(self->base.rot[1] + DOOR_ANGLE_100);
            break;
        }
        break;
    }
    self->flags620 |= DOOR_FLAG_OPEN;
    if (instant == 0) {
        self->base.phase = 1;
        self->base.mode = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    } else {
        self->base.rot[1] = self->openHeading;
    }
}
