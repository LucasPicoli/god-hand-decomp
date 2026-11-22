/* sn-2.95.3-136 matched TU. */

/* Hand a weapon to its holder: pick the grip offset (x, y, z) and rotation (x, y, z) for this enemy kind (two kinds hold it differently) and for the left or right hand, then attach it. Does nothing without a weapon. */
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmWeapon.h"

#define EM_KIND_LEFTY_A    0x225
#define EM_KIND_LEFTY_B    0x24D
#define GRIP_RIGHT         0xA
#define GRIP_LEFT          0x10

typedef struct GripBuf {
    cVec ofs;                           /* 0x00 grip offset */
    cVec rot;                           /* 0x10 grip rotation */
} GripBuf;


__attribute__((section(".text.cOmBase_attachWeaponGrip")))
void cOmBase_attachWeaponGrip(cOmBase *self, void *weapon, int left)
{
    GripBuf grip;
    int idx;
    float mirror, turn;

    if (weapon == 0)
        return;
    VU0_SQC2_VF0(&grip, 0x0);
    VU0_SQC2_VF0(&grip, 0x10);
    if (self->emNo != EM_KIND_LEFTY_A && self->emNo != EM_KIND_LEFTY_B) {
        idx = GRIP_RIGHT;
        grip.ofs.x = -0.28f;
        grip.ofs.y = -0.035f;
        grip.ofs.z = 0.185f;
        grip.rot.y = -0.78539819f;
        *(int *)&grip.rot.x = 0;
        *(int *)&grip.rot.z = 0;
        if (left) {
            mirror = 0.28f;
            idx = GRIP_LEFT;
            turn = 0.78539819f;
            grip.ofs.x = mirror;
            grip.rot.y = turn;
        }
    } else {
        mirror = -0.08f;
        idx = GRIP_RIGHT;
        turn = -0.03f;
        grip.ofs.x = mirror;
        grip.ofs.y = turn;
        *(int *)&grip.ofs.z = 0;
        *(int *)&grip.rot.x = 0;
        *(int *)&grip.rot.y = 0;
        *(int *)&grip.rot.z = 0;
        if (left) {
            mirror = 0.08f;
            idx = GRIP_LEFT;
            turn = 3.1415927f;
            grip.ofs.x = mirror;
            grip.rot.z = turn;
        }
    }
    cOmWeapon_setParent(weapon, (cGameObj *)self, idx, &grip.ofs, &grip.rot);
}
