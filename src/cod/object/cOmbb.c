/* TU: cOmbb [object] - recovered C++ class. */
#include "godhand/cOmbb.h"
#include "godhand/cSnd.h"

/* Kind of bomb this object is. */
__attribute__((section(".text.cOmbb_ckBomb")))
unsigned char cOmbb_ckBomb(cOmbb *self) {
    return self->bombKind;
}

extern void KillEffect(void *obj, int a1, int a2);
extern int SetEffect(int a0, int a1, void *obj, int a3, int t0, unsigned t1);

/* Light the fuse: reset the effects, start the hiss and remember its handle. */
__attribute__((section(".text.cOmbb_setFire")))
void cOmbb_setFire(cOmbb *self)
{
    if (self->fireLit == 0) {
        self->base.mode = 0;
        self->base.step = COMBB_FUSE_LIT;
        KillEffect(self, 0, 2);
        SetEffect(1, 1, self, 0, 0, 0xFFFFFFFFU);
        self->hissSe = cSnd_SeCall_2CBA48(&D_005FEE00, 2, COMBB_SE_HISS, (cObj *)self, 0, 0, 0, 0);
        self->fireLit = 1;
    }
}
