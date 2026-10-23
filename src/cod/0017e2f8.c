/* sn-2.95.3-136: func_0017E2F8, reverse quarter-turn gimmick step with sounds: start a 90-frame
 * rotate back with vibration, wait out the start timer, run the move and hold for 15 frames. */
#include "godhand/cOmSubGimmick.h"

extern char D_005FEE00[];
extern int cSnd_SeCall_2CB8A0(void *snd, int slot, short key1, short idA, short idB, int a5, int a6);

__attribute__((section(".text.func_0017E2F8")))
void func_0017E2F8(cOmQuarterTurn *self)
{
    float ang[4];

    switch (self->base.phase) {
    case 0:
        if (self->turned == 1)
            break;
        ang[0] = -1.5707964f;
        ang[1] = 0.0f;
        ang[2] = 0.0f;
        ang[3] = 1.0f;
        cOmSub_initMove1_ang(self->move, (char *)self, 0, 0x5A, ang, 0.2f, 0.0f, 0);
        cOmSub_setVibration(self->move, 5, 5, 2.0f, 0.5f, 2.0f);
        self->base.phase = 1;
        self->timer = 7;
        self->base.step = 0;
        self->base.stepArg = 0;
        /* fallthrough */
    case 1:
        if (self->timer < 0) {
            self->base.phase = 2;
            self->base.step = 0;
            self->base.stepArg = 0;
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x1F, -1, -1, 0, 0);
        }
        self->timer -= 1;
        break;
    case 2:
        if (cOmSub_move(self->move) == 0) {
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x20, -1, -1, 0, 0);
            self->turned = 1;
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
