/* sn-2.95.3-136: func_0017EF98, timed tip-over state machine on the phase byte: wait 7 frames, then rotate the
 * tilt angle down with growing speed (SE 0xE6 once, 25 frames in) until it reaches -pi/2, where it lands
 * (effect, SE 0xE7) and holds 15 frames before going idle again. */
#include "godhand/cOmBase.h"
#include "godhand/cEmManage.h"
extern char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);

/* A gimmick that tips over once, falling faster as it goes. The tilt is rot.x (0x100, the
 * euler angles, as in cParts). */
typedef struct cOmTipOver {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    unsigned char fallen;               /* 0x600 1 once it has tipped over */
    char unk601[0x604 - 0x601];
    float timer;                        /* 0x604 frames to wait; 1000 once the falling sound has played */
    float speed;                        /* 0x608 fall speed in degrees per frame, 16% faster each frame */
} cOmTipOver;

__attribute__((section(".text.func_0017EF98")))
void func_0017EF98(cOmTipOver *self)
{
    float rate;
    float t;
    float s;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    switch (self->base.phase) {
    case 0:
        if (self->fallen == 1)
            return;
        self->base.phase = 1;
        self->timer = 7.0f;
        self->base.step = 0;
        self->base.stepArg = 0;
    case 1:
        t = self->timer - rate;
        self->timer = t;
        if (t < 0.0f) {
            self->timer = 25.0f;
            self->speed = 0.01f;
            self->base.phase = 2;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 2:
        s = self->speed;
        self->timer = self->timer - rate;
        self->base.rot.x = self->base.rot.x - s * rate * 0.017453292f;
        self->speed = s + s * 0.16f * rate;
        if (self->timer <= 0.0f) {
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xE6, self, 0, 0, 0, 0);
            self->timer = 1000.0f;
        }
        t = self->base.rot.x;
        if (t <= (-1.5707964f)) {
            SetEffect(1, 1, 0, 0, -1, 0xFFFFFFFFU);
            cSnd_SeCall_2CBA48(D_005FEE00, 2, 0xE7, self, 0, 0, 0, 0);
            self->base.rot.x = (-1.5707964f);
            self->fallen = 1;
            self->timer = 15.0f;
            self->base.phase = 3;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 3:
        t = self->timer - rate;
        self->timer = t;
        if (t <= 0.0f) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    }
}
