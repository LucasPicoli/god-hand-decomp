/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/cOmWeapon.h"
#include "godhand/vu0.h"

/* Puts weapon (of CreateObj kind) in the enemy's hand with the grip for its
 * kind, the left hand when unk17C3 is set, then keeps it in the slot for its
 * kind: 0x366 in weapon366 and 0x369 in weapon369 (each with its state cleared first),
 * 0x36D in weapon36D, 0x375, 0x377 and 0x378 in weapon375, any other in unk6EC. */
__attribute__((section(".text.func_0026AB20")))
void func_0026AB20(cEm00 *self, cOmWeapon *weapon, int kind)
{
    cVec pos;
    cVec rot;
    int hand;

    if (weapon == 0) {
        return;
    }
    VU0_SQC2_VF0_MEM(&pos, 0);
    VU0_SQC2_VF0_MEM(&rot, 0);
    CEM00_WEAPON_GRIP(self, kind, self->unk17C3 != 0, pos, rot, hand);
    cOmWeapon_setParent(weapon, (cGameObj *)self, hand, &pos, &rot);
    switch (kind) {
    default:
        self->unk6EC = weapon;
        break;
    case 0x366:
        Obj1D00_ClearState_6(&weapon->base);
        self->weapon366 = weapon;
        break;
    case 0x369:
        Obj1D00_ClearState_8(&weapon->base);
        self->weapon369 = weapon;
        break;
    case 0x36D:
        self->weapon36D = weapon;
        break;
    case 0x375:
    case 0x377:
    case 0x378:
        self->weapon375 = weapon;
        break;
    }
}
