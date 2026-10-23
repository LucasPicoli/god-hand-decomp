/* sn-2.95.3-136: func_001A5540, strike gimmick step: play the attack motion and effect with the damage volume on for
 * 12 frames, off for 58, then on until the motion ends; then push the knock vector out and die. It also dies when its
 * hp runs out. */
#include "godhand/cEmManage.h"
#include "godhand/cModel.h"
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/cDamageGive.h"
extern char D_00747B00[];
extern void SetMotionStep(void *a0, float f12);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern int moveMotion(void *a0);
extern void VecRotVec(float *out, float *in, float *rot, int order);
extern int cOmBase_checkDamage(cOmBase *self, cDamageTake *take);

/* A gimmick that plays one attack motion with its damage volume on, off and on again,
 * then dies; it also dies when its hp runs out. */
typedef struct cOmStrike {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x620 - 0x5E0];
    cDamageGive *give;                  /* 0x620 the attack's damage volume */
    cDamageTake *take;                  /* 0x624 */
    short timer;                        /* 0x628 frames left in the on and off phases */
} cOmStrike;

static inline void VCall(cOmStrike *o, int slot, void *arg)
{
    cVtEnt *e = &o->base.vtable[slot];
    ((void (*)(void *, void *))e->pfn)((char *)o + e->delta, arg);
}

static inline void SetV3(float *d, float x, float y, float z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
}

static inline void SetV4(float *d, float x, float y, float z, float w)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
    d[3] = w;
}

__attribute__((section(".text.func_001A5540")))
void func_001A5540(cOmStrike *self)
{
    float rate;
    float rot[4];
    char *mot;

    rate = cEmManage_GetSpeedRate(&D_005864F0);
    self->base.speedRate = rate;
    SetMotionStep(self, rate);
    switch (self->base.phase) {
    case 0:
        VCall(self, 14, D_00747B00);
        VCall(self, 15, D_00747B00);
        mot = (char *)self->base.texKey;
        func_002A8578(self, *(int *)(mot + 0xC) + (int)mot, *(int *)(mot + 0x10) + (int)mot, 0.0f, 0, 0, 0);
        SetEffect(1, 2, self, 0, -1, 0xFFFFFFFF);
        if (self->give)
            cDamageUnit_SetDamageCollActive(self->give, 1);
        self->base.phase = 1;
        self->timer = 12;
        self->base.step = 0;
        self->base.stepArg = 0;
        /* fallthrough */
    case 1:
        moveMotion(self);
        if (--self->timer < 0) {
            if (self->give)
                cDamageUnit_SetDamageCollActive(self->give, 0);
            self->timer = 0x3A;
            self->base.phase = 2;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    case 2:
        moveMotion(self);
        if (--self->timer < 0) {
            if (self->give)
                cDamageUnit_SetDamageCollActive(self->give, 1);
            self->base.step = 0;
            self->base.phase = 3;
            self->base.stepArg = 0;
        }
        break;
    case 3:
        if (moveMotion(self)) {
            SetV3(&self->base.knock.x, 0.0f, 0.0f, 10.0f);
            SetV4(rot, 0.0f, 0.86f, 0.0f, 1.0f);
            VecRotVec(&self->base.knock.x, &self->base.knock.x, rot, 0);
            self->base.mode = 1;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
        break;
    }
    if (cOmBase_checkDamage(&self->base, self->take) == 1 && self->base.hp <= 0) {
        self->base.mode = 1;
        self->base.flags0 |= 1;
        self->base.step = 0;
        self->base.stepArg = 0;
        self->base.phase = 0;
    }
}
