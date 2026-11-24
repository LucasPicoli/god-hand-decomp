/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/sceVu0.h"
#include "godhand/mtx.h"

/* Throw weapon w from part 8 of enemy self: the start point in the part
 * depends on unk1869, which counts down to 0 here; the throw goes 0.1
 * forward along the enemy's facing. */
__attribute__((section(".text.func_0026BBD0")))
void func_0026BBD0(cEm00 *self, cOmWeapon *w)
{
    int frame[3];
    float m[16];
    cVec pos;
    cVec dir;
    cOmBase *hand;

    if (w == 0) {
        return;
    }
    hand = cOmBase_childAt((cOmBase *)self, frame, 8);
    if (hand == 0) {
        return;
    }
    cVec_zero(&pos);
    cVec_zero(&dir);
    switch (self->unk1869) {
    case 0:
    default:
        pos.x = -0.4407f;
        pos.y = 0.1209f;
        pos.z = 0.1202f;
        break;
    case 1:
        pos.x = -0.4407f;
        pos.y = -0.1205f;
        pos.z = 0.1209f;
        break;
    case 2:
        pos.x = -0.4407f;
        pos.y = -0.121f;
        pos.z = -0.12f;
        break;
    case 3:
        pos.x = -0.4407f;
        pos.y = 0.1201f;
        pos.z = -0.121f;
        break;
    }
    if (--self->unk1869 <= 0) {
        self->unk1869 = 0;
    }
    cVec_applyMatrix(&pos, hand->mtx);
    cVec_copy3(w->base.pos, &pos);
    cVec_copy3(&w->base.posA, &pos);
    MtxInitRotY(m, self->rot.y);
    dir.z = 0.1f;
    dir.x = 0.0f;
    dir.y = 0.0f;
    cVec_applyMatrix(&dir, m);
    func_001D0140(w, &dir, (cGameObj *)self);
}
