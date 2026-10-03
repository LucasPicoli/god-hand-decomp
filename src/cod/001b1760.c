/* sn-2.95.3-136 matched TU. */

#include "godhand/cOm60.h"

extern float capVu0Atan2(float y, float x);
extern int SetEffect(int kind, int id, void *owner, void *param, int handle, unsigned int owner2);
extern int cSnd_SeCall_2CBA48(void *snd, int a, int b, void *owner, int c, int d, int e, int f);
extern char D_005FEE00[];

/* The held bit cleared as an unsigned mask: retail builds it with lui+ori,
 * where ~0x10 would give a one-instruction addiu. */
#define COM60_KEEP_NOT_HELD 0xFFFFFFEF

/* Launch the object: drop the parent, take the direction (and the speed
 * when positive), face along it, then run the throw effect and sound once. */
__attribute__((section(".text.cOm60_setThrow")))
void cOm60_setThrow(cOm60 *self, cVec *dir, float speed) {
    self->parent = 0;
    cVec_copy3(&self->throwDir, dir);
    if (speed > 0.0f) {
        self->speed = speed;
    }
    self->base.rot[1] = capVu0Atan2(dir->x, dir->z);
    self->pitch = COM60_THROW_PITCH;
    self->base.animRate = 1.0f;
    self->base.objFlags &= COM60_KEEP_NOT_HELD;
    self->hitFlag = 0;
    if (self->started == 0) {
        self->started = 1;
        SetEffect(COM60_THROW_EFFECT, 5, self, 0, 7, 0xFFFFFFFF);
        self->seHandle = cSnd_SeCall_2CBA48(D_005FEE00, 0, COM60_THROW_SE, self, 0, 0, 0, 0);
    }
}
