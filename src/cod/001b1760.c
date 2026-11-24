/* sn-2.95.3-136 matched TU. */

#include "godhand/cOm60.h"
#include "godhand/cSnd.h"
#include "godhand/cObjBase.h"

extern float capVu0Atan2(float y, float x);

/* The held bit cleared as an unsigned mask: retail builds it with lui+ori,
 * where ~0x10 would give a one-instruction addiu. */
#define COM60_KEEP_NOT_HELD 0xFFFFFFEF

/* Launch the object: drop the parent, take the velocity (and the flight
 * timer when positive), face along it, then run the throw effect and sound once. */
__attribute__((section(".text.cOm60_setThrow")))
void cOm60_setThrow(cOm60 *self, cVec *dir, float time) {
    self->parent = 0;
    cVec_copy3(&self->throwDir, dir);
    if (time > 0.0f) {
        self->flightTime = time;
    }
    self->base.rot.y = capVu0Atan2(dir->x, dir->z);
    self->pitch = COM60_THROW_PITCH;
    self->base.tint.w = 1.0f;
    self->base.objFlags &= COM60_KEEP_NOT_HELD;
    self->hitFlag = 0;
    if (self->started == 0) {
        self->started = 1;
        SetEffect(COM60_THROW_EFFECT, 5, (cObj *)self, 0, 7, EFFECT_FOLLOW_OWNER);
        self->seHandle = cSnd_SeCall_2CBA48(&D_005FEE00, 0, COM60_THROW_SE, (cObj *)self, 0, 0, 0, 0);
    }
}
