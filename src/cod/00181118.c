/* sn-2.95.3-136: func_00181118, enemy phase update: run the handler of the current phase entry, regenerate one guard point every 4 frames, and on a new hit take its damage from the guard (breaking it at zero) with a hit sound. */
extern void func_00180CD8(char *self);

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cSnd.h"
#include "godhand/emPhaseTable.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cGameObj.h"

__attribute__((section(".text.func_00181118")))
void func_00181118(cGameObj *self)
{
    cDamageTake *hit;
    int n;
    int m;
    int c;
    unsigned long t;

    EM_PHASE_RUN(&D_003BDB18, self, self->phase);

    c = --*(signed char *)((char *)self + 0x60A);
    if (c <= 0) {
        *(signed char *)((char *)self + 0x60A) = 4;
        n = self->hp + 1;
        if (n >= self->hpMax)
            self->hp = self->hpMax;
        else
            self->hp = n;
    }
    hit = *(cDamageTake **)((char *)self + 0x60C);
    if (hit != 0) {
        t = hit->hitFlags;
        t &= 1;
        if (t != 0) {
        m = self->hp;
        m -= hit->power;
        self->hitFlash = 3.0f;
        if (m >= self->hpMax)
            self->hp = self->hpMax;
        else
            self->hp = m;
        if (self->hp <= 0) {
            self->mode = 1;
            self->phase = 0;
            self->step = 0;
            self->stepArg = 0;
        } else {
            *(short *)((char *)self + 0x600) = 8;
            *(float *)((char *)self + 0x604) = (*(float **)((char *)self + 0xF0))[1];
        }
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 10, (cObj *)self, 0, 0, 0, 0);
        }
    }
    func_00180CD8(self);
}
