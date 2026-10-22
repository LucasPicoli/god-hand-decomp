/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cOmBase.h"
#include "godhand/cOmWeapon.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"

#define HAND_CHILD   10
#define DROP_SPEED   0.1f

/* The frame: the child count cOmBase_childAt leaves, the heading matrix and two vectors. */
typedef struct DropFrame {
    int childNum;
    char unk04[0xC];
    float mtx[16];
    cVec hand;
    cVec vel;
} DropFrame;

extern void MtxInitRotY(void *a0, float angle);
extern void func_001D0240(cOmWeapon *self, cVec *pos, int arg);

/* Puts the weapon at the enemy's hand and lets it go straight ahead. */
__attribute__((section(".text.func_0026BDD0")))
void func_0026BDD0(cGameObj *self, cOmWeapon *weapon)
{
    DropFrame f;
    cOmBase *child;

    if (weapon == 0) {
        return;
    }
    child = cOmBase_childAt((cOmBase *)self, &f.childNum, HAND_CHILD);
    if (child == 0) {
        return;
    }
    VU0_SQC2_VF0_MEM(&f.hand, 0);
    VU0_SQC2_VF0_MEM(&f.vel, 0);
    cVec_copy3(&f.hand, child->pos);
    cVec_copy3(weapon->base.pos, &f.hand);
    cVec_copy3(&weapon->base.posA, &f.hand);
    MtxInitRotY(f.mtx, self->rot[1]);
    f.vel.x = 0;
    f.vel.y = 0;
    f.vel.z = DROP_SPEED;
    cVec_applyMatrix(&f.vel, f.mtx);
    func_001D0240(weapon, &f.vel, (int)self);
}
