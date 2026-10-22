/* sn-2.95.3-136: func_0017B2E0, double swing gimmick step (variant of 0017b0d8.c with start/stop SE calls). */
#include "godhand/cOmBase.h"

extern void cOmSub_initMove1_ang(char *dst, char *obj, int idx, int a3, void *a4, float f12, float f13, int a5);
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(char *a0);
extern int cSnd_SeCall_2CB8A0(void *snd, int slot, int key, int idA, int idB, int a5, int a6);
extern char D_005FEE00[];

/* A gimmick that swings two parts once when triggered. */
typedef struct cOmDoubleSwing {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x600 - 0x5E0];
    unsigned char triggered;            /* 0x600 set by the trigger, cleared when the swing ends */
    unsigned char swung;                /* 0x601 1 once the swing has run */
    char unk602[0x604 - 0x602];
    short timer;                        /* 0x604 frames to wait before and after the swing */
    char unk606[0x610 - 0x606];
    char moveA[0x770 - 0x610];          /* 0x610 cOmSub move work of entry 0 */
    char moveB[0x140];                  /* 0x770 cOmSub move work of entry 2 */
} cOmDoubleSwing;

__attribute__((section(".text.func_0017B2E0")))
void func_0017B2E0(cOmDoubleSwing *self)
{
    float ang[4];
    float z;
    int r;
    int r2;

    switch (self->base.phase) {
    case 0:
        if (self->swung == 0) {
            self->base.mode = 0;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
            break;
        }
        ang[0] = 1.3962634f;
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
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x1F, -1, -1, 0, 0);
        }
        self->timer -= 1;
        break;
    case 2:
        r = cOmSub_move(self->moveA);
        r2 = cOmSub_move(self->moveB);
        if (r == 0 && r2 == 0) {
            cSnd_SeCall_2CB8A0(D_005FEE00, 2, 0x20, -1, -1, 0, 0);
            self->timer = 15;
            self->base.phase = 3;
            self->swung = 0;
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
