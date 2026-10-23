/* sn-2.95.3-136: func_001A49A8, reverse flap gimmick step: like func_001A47F8 but turns through angB - angA
 * and resets the gimmick when it has not turned yet. */
#include "godhand/cOmBase.h"

extern char D_005FEE00[];
extern void cOmSub_initMove1_ang(char *dst, char *obj, int idx, int a3, void *a4, float f12, float f13, int a5);
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(char *a0);
extern int cSnd_SeCall_2CB8A0(void *snd, int slot, int key, int idA, int idB, int a5, int a6);
extern void func_001A4CF8(char *p);

/* A gimmick that turns once between two angles when triggered; func_001A49A8 turns it back. */
typedef struct cOmFlap {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    char move[0x760 - 0x600];           /* 0x600 cOmSub move work */
    unsigned char triggered;            /* 0x760 set by the trigger, cleared when the turn ends */
    unsigned char turned;               /* 0x761 1 once the turn has run */
    char unk762[0x794 - 0x762];
    float angA;                         /* 0x794 angle at one end */
    float angB;                         /* 0x798 angle at the other end */
    short timer;                        /* 0x79C frames to wait before and after the turn */
} cOmFlap;

__attribute__((section(".text.func_001A49A8")))
void func_001A49A8(cOmFlap *self)
{
    float ang[4];
    float z;

    switch (self->base.phase) {
    case 0:
        if (self->turned == 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
            break;
        }
        ang[0] = self->angB - self->angA;
        ang[1] = 0.0f;
        ang[2] = 0.0f;
        ang[3] = 1.0f;
        z = ang[1];
        cOmSub_initMove1_ang(self->move, (char *)self, 0, 0xC, ang, 0.2f, z, 0);
        cOmSub_setVibration(self->move, 3, 3, 4.0f, z, 4.0f);
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
            self->timer = 15;
            self->base.phase = 3;
            self->turned = 0;
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
