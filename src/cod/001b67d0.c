/* sn-2.95.3-136: func_001B67D0, enemy setup with a three-sphere (radius 0.25) damage-give volume along z, the give attributes 0x41/0x14/0xF0 and a forward direction. */
#include "godhand/cOmHitVolumeSetup.h"
#include "godhand/cDamageGive.h"
extern char D_00574380[];

static inline void copyVec3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

/* An enemy whose attack is a damage-give volume of three spheres along z. */
typedef struct cOmGiveSpheres {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x620 - 0x5E0];
    cDamageGive *give;                  /* 0x620 */
} cOmGiveSpheres;

__attribute__((section(".text.func_001B67D0")))
int func_001B67D0(cOmGiveSpheres *self)
{
    float f[16];
    float *t;
    float *a;
    float *b;
    void *give;
    cDamageGive *u;

    func_001B6FB8((cOmHitVolume *)self);
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.5f;
    f[3] = 1.0f;
    t = &f[4];
    a = t;
    f[4] = 0.0f;
    a[1] = 0.0f;
    a[2] = 0.0f;
    a[3] = 1.0f;
    t = &f[8];
    b = t;
    f[8] = 0.0f;
    b[1] = 0.0f;
    b[2] = -0.5f;
    b[3] = 1.0f;
    t = &f[12];
    f[12] = 0.0f;
    f[13] = 0.0f;
    t[2] = 1.0f;
    t[3] = 1.0f;
    give = cDamageManage_CreateDamageGive(D_00574380, 2, self);
    self->give = give;
    if (give != 0) {
        cDamageUnit_AddDamageCollSphere(give, self->base.mtx, f, 0.25f);
        cDamageUnit_AddDamageCollSphere(self->give, self->base.mtx, a, 0.25f);
        cDamageUnit_AddDamageCollSphere(self->give, self->base.mtx, b, 0.25f);
        cDamageUnit_SetDamageCollActive(self->give, 0);
        self->give->flags |= 1;
        self->give->unk46 = 0x41;
        self->give->activeTime = 0x14;
        u = self->give;
        u->unk44 = 0xF0;
        u->unk40 = 0;
        copyVec3(&self->give->hitVec.x, &f[12]);
    }
    self->base.flags2 &= ~1;
    return 1;
}
