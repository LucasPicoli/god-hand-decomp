/* sn-2.95.3-136: cEm00_setGoto. */
#include "godhand/cOmWeapon.h"
#include "godhand/cEm00.h"

extern void cEm00_setAlphaMode(void *a0, char a1);
extern void func_001D0408(cOmWeapon *a0);

/* Starts a goto toward pos: copies the target, sets the slide time and hit kind, and drops the held effect. */
__attribute__((section(".text.cEm00_setGoto")))
void cEm00_setGoto(cEm00 *self, cVec *pos, int kind, int reset, float time)
{
    cVec_copy3(&self->unk16B0, pos);
    self->slideTime = time;
    self->hitKind = kind;
    if (reset != 0) {
        self->mode = 0;
        self->phase = 0x13;
        self->step = 0;
        self->stepArg = 0;
    }
    if (kind == 0xF) {
        cEm00_setAlphaMode(self, 0);
        self->vitalMax = 1;
        self->vital = 1;
    }
    if (self->gotoEffect != 0) {
        func_001D0408(self->gotoEffect);
        self->gotoEffect = 0;
    }
}
