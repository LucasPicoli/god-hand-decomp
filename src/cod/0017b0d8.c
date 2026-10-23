/* sn-2.95.3-136: func_0017B0D8, double swing gimmick step: start two 90-frame rotations (moveA and moveB)
 * with vibration, wait out the start timer, run both moves and hold for 15 frames, then finish. */
#include "godhand/cOmSubGimmick.h"

__attribute__((section(".text.func_0017B0D8")))
void func_0017B0D8(cOmDoubleSwing *self)
{
    float ang[4];
    float z;
    int r;
    int r2;

    switch (self->base.phase) {
    case 0:
        if (self->swung == 1)
            break;
        ang[0] = -1.3962634f;
        ang[1] = 0.0f;
        ang[2] = 0.0f;
        ang[3] = 1.0f;
        z = ang[1];
        cOmSub_initMove1_ang(self->moveA, (char *)self, 0, 0x5A, ang, 0.2f, z, 0);
        cOmSub_setVibration(self->moveA, 5, 5, 2.0f, 0.5f, 2.0f);
        cOmSub_initMove1_ang(self->moveB, (char *)self, 2, 0x5A, ang, 0.2f, z, 0);
        cOmSub_setVibration(self->moveB, 5, 5, 2.0f, 0.5f, 2.0f);
        self->base.phase = 1;
        self->timer = 7;
        self->base.step = 0;
        self->base.stepArg = 0;
        /* fallthrough */
    case 1:
        if (self->timer < 0) {
            self->base.step = 0;
            self->base.phase = 2;
            self->base.stepArg = 0;
        }
        self->timer -= 1;
        break;
    case 2:
        r = cOmSub_move(self->moveA);
        r2 = cOmSub_move(self->moveB);
        if (r == 0 && r2 == 0) {
            self->swung = 1;
            self->timer = 15;
            self->base.phase = 3;
            self->triggered = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 3:
        if (self->timer < 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        self->timer -= 1;
        break;
    }
}
