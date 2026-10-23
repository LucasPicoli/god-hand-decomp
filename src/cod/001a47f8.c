/* sn-2.95.3-136: func_001A47F8, flap gimmick step: start a 12-frame turn through angA - angB with
 * vibration, wait out the start timer and play the start sound, run the move and hold for 15 frames, then finish. */
#include "godhand/cOmSubGimmick.h"

extern char D_005FEE00[];
extern int cSnd_SeCall_2CB8A0(void *snd, int slot, short key1, short idA, short idB, int a5, int a6);
extern void func_001A4CF8(char *p);

__attribute__((section(".text.func_001A47F8")))
void func_001A47F8(cOmFlap *self)
{
    float ang[4];

    switch (self->base.phase) {
    case 0:
        if (self->turned == 1)
            break;
        ang[0] = self->angA - self->angB;
        ang[1] = 0.0f;
        ang[2] = 0.0f;
        ang[3] = 1.0f;
        cOmSub_initMove1_ang(self->move, (char *)self, 0, 0xC, ang, 0.2f, 0.0f, 0);
        cOmSub_setVibration(self->move, 3, 3, 4.0f, 0.0f, 4.0f);
        self->base.phase = 1;
        self->timer = 7;
        self->base.step = 0;
        self->base.stepArg = 0;
        /* fallthrough */
    case 1:
        if (self->timer < 0) {
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x85, -1, -1, 0, 0);
            self->base.step = 0;
            self->base.phase = 2;
            self->base.stepArg = 0;
        }
        self->timer -= 1;
        break;
    case 2:
        if (cOmSub_move(self->move) == 0) {
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
            func_001A4CF8((char *)self);
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        self->timer -= 1;
        break;
    }
}
