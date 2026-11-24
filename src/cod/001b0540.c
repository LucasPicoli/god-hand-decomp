/* sn-2.95.3-136 matched TU. */
#include "godhand/cGameObj.h"
#include "godhand/cObjBase.h"
#include "godhand/cDamageUnit.h"
#include "godhand/cSnd.h"
#include "godhand/gameWork.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/capVu0.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/rollObj.h"

/* Moves the object by its velocity until it stops rolling: friction, gravity,
 * wall and floor contact, the landing sounds, and a dust puff every 11 frames
 * while it rolls on the ground. */
__attribute__((section(".text.func_001B0540")))
void func_001B0540(RollObj *self)
{
    cVec flat;
    cVec hit;

    VU0_LQC2(4, &self->vel, 0);
    VU0_SQC2_MEM(4, &flat, 0);
    flat.y = 0.0f;
    if (__builtin_sqrtf(capVu0LengthSq(&flat)) < 0.03f)
        self->rolling = 0;
    if (self->rolling == 1 || self->falling == 1) {
        VU0_VADD_XYZ_IP(self->base.pos, 0, &self->vel);
        VU0_VSCALE_XYZ_MEM(&self->vel, 0, self->falling == 1 ? 0.95f : 0.7f);
    }
    self->vel.y += -0.02f;
    cVec_zero(&hit);
    if (ChkCollScrWall((cGameObj *)self, 2.2f, &hit, 0, 0, 0, 0) != 0) {
        self->base.pos->x = hit.x;
        self->base.pos->z = hit.z;
    }
    cVec_zero(&hit);
    if (func_001329C0((cGameObj *)self, &hit, 0, 0, 10.0f) != 0) {
        if (self->falling == 1) {
            if (self->base.pos->y < hit.y) {
                self->vel.x *= 0.5f;
                self->vel.z *= 0.5f;
                self->falling = 0;
                self->smokeWait = 0;
                if (self->damage != 0)
                    cDamageUnit_SetDamageCollActive(self->damage, 1);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 2, 0x91, -1, -1, 0, 0);
                cSnd_SeCall_2CB8A0(&D_005FEE00, 2, 0x92, -1, -1, 0, 0);
            }
        } else {
            /* retail subtracts a zero here */
            self->base.pos->y = hit.y - 0.0f;
        }
    }
    if (self->falling == 0 && self->rolling == 1) {
        self->base.pos->y += (D_007474A0.frame & 1U) * 0.01f;
        if (self->smokeWait > 0) {
            self->smokeWait--;
        } else {
            SetEffect(1, 1, (cObj *)self, 0, -1, EFFECT_FOLLOW_OWNER);
            self->smokeWait = 10;
        }
    }
}
