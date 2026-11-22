/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/vu0.h"

/* Puts weapon (of CreateObj kind) in the enemy's hand with the grip for its
 * kind, the left hand when bit 1 of motionFlags is set, then keeps it: kind 0x369
 * in unk1648 with its state cleared first, any other kind in unk1634. */
__attribute__((section(".text.func_0028D138")))
void func_0028D138(cEm00 *self, cOmWeapon *weapon, int kind)
{
    cVec pos;
    cVec rot;
    int hand;

    if (weapon == 0) {
        return;
    }
    VU0_SQC2_VF0_MEM(&pos, 0);
    VU0_SQC2_VF0_MEM(&rot, 0);
    CEM00_WEAPON_GRIP(self, kind, self->motionFlags & 2, pos, rot, hand);
    cOmWeapon_setParent(weapon, (cGameObj *)self, hand, &pos, &rot);
    if (kind != 0x369) {
        self->unk1634 = weapon;
    } else {
        Obj1D00_ClearState_8(&weapon->base);
        self->unk1648 = weapon;
    }
}
