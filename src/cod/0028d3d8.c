/* sn-2.95.3-136 matched TU. */

/* Hand a weapon to its holder: pick the grip offset (x, y, z) and rotation (x, y, z) for this enemy kind (two kinds hold it differently) and for the left or right hand, then attach it. Does nothing without a weapon. */
#include "godhand/vu0.h"
#include "godhand/cOmBase.h"

#define EM_KIND_LEFTY_A    0x225
#define EM_KIND_LEFTY_B    0x24D
#define GRIP_RIGHT         0xA
#define GRIP_LEFT          0x10

typedef struct GripBuf {
    float ofs[3];                       /* 0x00 grip offset */
    float pad0C;
    float rot[3];                       /* 0x10 grip rotation */
    float pad1C;
} GripBuf;

extern int cOmWeapon_setParent();

__attribute__((section(".text.func_0028D3D8")))
void func_0028D3D8(cOmBase *self, void *weapon, int left)
{
    GripBuf grip;
    int idx;
    float mirror, turn;

    if (weapon == 0)
        return;
    VU0_SQC2_VF0(&grip, 0x0);
    VU0_SQC2_VF0(&grip, 0x10);
    if (self->actionId != EM_KIND_LEFTY_A && self->actionId != EM_KIND_LEFTY_B) {
        idx = GRIP_RIGHT;
        grip.ofs[0] = -0.28f;
        grip.ofs[1] = -0.035f;
        grip.ofs[2] = 0.185f;
        grip.rot[1] = -0.78539819f;
        *(int *)&grip.rot[0] = 0;
        *(int *)&grip.rot[2] = 0;
        if (left) {
            mirror = 0.28f;
            idx = GRIP_LEFT;
            turn = 0.78539819f;
            grip.ofs[0] = mirror;
            grip.rot[1] = turn;
        }
    } else {
        mirror = -0.08f;
        idx = GRIP_RIGHT;
        turn = -0.03f;
        grip.ofs[0] = mirror;
        grip.ofs[1] = turn;
        *(int *)&grip.ofs[2] = 0;
        *(int *)&grip.rot[0] = 0;
        *(int *)&grip.rot[1] = 0;
        *(int *)&grip.rot[2] = 0;
        if (left) {
            mirror = 0.08f;
            idx = GRIP_LEFT;
            turn = 3.1415927f;
            grip.ofs[0] = mirror;
            grip.rot[2] = turn;
        }
    }
    cOmWeapon_setParent(weapon, self, idx, &grip, &grip.rot[0]);
}
