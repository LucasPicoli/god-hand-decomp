/* sn-2.95.3-136: func_001AC980, breakable gimmick phase update: run the handler of the current
 * phase entry, regenerate one guard point every 5 frames, and on a new hit (when not locked)
 * take its damage from the guard, breaking it at zero, with a hit sound. */
extern void func_001AC370(char *self);
extern void func_001B7EE0(void *self, float f);

#include "godhand/cOmBase.h"
#include "godhand/cModel.h"
#include "godhand/cSnd.h"
#include "godhand/emPhaseTable.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cGameObj.h"

__attribute__((section(".text.func_001AC980")))
void func_001AC980(cGameObj *self)
{
    cDamageTake *hit;
    int n;
    int m;
    int c;
    unsigned long t;

    EM_PHASE_RUN(&D_003BDC40, self, self->phase);

    c = --*(signed char *)((char *)self + 0x621);
    if (c <= 0) {
        *(signed char *)((char *)self + 0x621) = 5;
        n = self->hp + 1;
        if (n >= self->hpMax)
            self->hp = self->hpMax;
        else
            self->hp = n;
    }
    if (*(unsigned char *)((char *)self + 0x60D) == 0) {
        hit = *(cDamageTake **)((char *)self + 0x624);
        if (hit != 0) {
            t = hit->hitFlags;
            t &= 1;
            if (t != 0) {
            int d = hit->power;

            m = self->hp;
            m -= d;
            self->hitFlash = 3.0f;
            if (m >= self->hpMax)
                self->hp = self->hpMax;
            else
                self->hp = m;
            *(int *)((char *)self + 0x618) += d;
            if (self->hp <= 0) {
                self->mode = 1;
                self->phase = 0;
                self->step = 0;
                self->stepArg = 0;
            } else {
                *(short *)((char *)self + 0x610) = 8;
                *(float *)((char *)self + 0x614) = (*(float **)((char *)self + 0xF0))[1];
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 0, 10, (cObj *)self, 0, 0, 0, 0);
            }
        }
    }
    func_001AC370(self);
    if (*(unsigned char *)((char *)self + 0x60C) == 1)
        func_001B7EE0(self, 2.0f);
}
