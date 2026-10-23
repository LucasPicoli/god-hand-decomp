/* sn-2.95.3-136 */
#include "godhand/cOmBase.h"
#include "godhand/sceVu0.h"

extern void capVu0AddVectorXYZ(void *a0, void *a1, void *a2);
extern void sceVu0MulVector(void *a0, void *a1, void *a2);
extern int func_002B6328(int a0);
extern void cNode_setTranslationFromWorld(void *self, float *pos);
extern void MtxCopy(void *dst, void *src);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);

/* The particle's resource record: the phases of its life, as fractions of it. */
typedef struct espPtclData {
    char unk000[0x1A0];
    int life;                           /* 0x1A0 frames */
    char unk1A4[0x1D0 - 0x1A4];
    float accelFrom;                    /* 0x1D0 */
    char unk1D4[0x1E0 - 0x1D4];
    float accelTo;                      /* 0x1E0 */
    float accel[3];                     /* 0x1E4 */
    float dragFrom;                     /* 0x1F0 */
    float drag[3];                      /* 0x1F4 */
    float windFrom;                     /* 0x200 */
    float windBase[3];                  /* 0x204 */
    float windTo;                       /* 0x210 */
    float windAccel[3];                 /* 0x214 */
    float gustFrom;                     /* 0x220 */
    float gustDecay[3];                 /* 0x224 */
} espPtclData;

typedef struct espPtclParent {
    char unk00[0xB0];
    float pos[3];                       /* 0xB0 */
} espPtclParent;

/* One particle: its velocity, the wind it carries and the base it moves from. */
typedef struct espPtcl {
    char unk000[0x100];
    espPtclData *data;                  /* 0x100 */
    espPtclParent *parent;              /* 0x104 */
    char unk108[0x134 - 0x108];
    float offset[3];                    /* 0x134 */
    float base[3];                      /* 0x140 */
    float vel[3];                       /* 0x14C */
    char unk158[0x164 - 0x158];
    float wind[3];                      /* 0x164 */
    char unk170[0x180 - 0x170];
    float time;                         /* 0x180 */
    char unk184[2];
    short delay;                        /* 0x186 */
    char unk188[2];
    short attached;                     /* 0x18A nonzero: follow the parent */
    char unk18C[0x1A0 - 0x18C];
    cVec scale;                         /* 0x1A0 */
} espPtcl;

/* Moves a particle for one frame: acceleration, drag and wind by life phase, then places it. */
__attribute__((section(".text.func_00302F68")))
void func_00302F68(espPtcl *self)
{
    cVec pos;
    cVec move;
    cVec tmp;
    cVec a;
    cVec b;
    float mtx[16];
    cVec c;
    cVec d;
    cVec e;
    float t;

    cVec_zero(&pos);
    cVec_zero(&move);
    cVec_zero(&tmp);
    if (self->data->life != 0)
        t = (self->time - self->delay) / self->data->life;
    else
        t = 0.0f;
    if (self->data->accelFrom <= t && t < self->data->accelTo) {
        cVec_set4(&a, self->vel[0], self->vel[1], self->vel[2], 1.0f);
        cVec_set4(&b, self->data->accel[0], self->data->accel[1], self->data->accel[2], 1.0f);
        cVec_copy3(&tmp, &b);
        capVu0AddVectorXYZ(&a, &a, &tmp);
        self->vel[0] = a.x;
        self->vel[1] = a.y;
        self->vel[2] = a.z;
    }
    if (self->data->dragFrom <= t) {
        self->vel[0] *= self->data->drag[0];
        self->vel[1] *= self->data->drag[1];
        self->vel[2] *= self->data->drag[2];
    }
    MtxCopy(mtx, (void *)func_002B6328((int)self));
    cVec_zero(&a);
    CopyVec3ToField30_147C40(mtx, (float *)&a);
    cVec_set4(&a, self->vel[0], self->vel[1], self->vel[2], 1.0f);
    sceVu0MulVector(&tmp, &a, &self->scale);
    sceVu0ApplyMatrix(&move, mtx, &tmp);
    cVec_set4(&b, self->offset[0], self->offset[1], self->offset[2], 1.0f);
    if (self->attached != 0) {
        if (self->parent != 0) {
            cVec_set4(&c, self->parent->pos[0], self->parent->pos[1], self->parent->pos[2], 1.0f);
            capVu0AddVectorXYZ(&pos, &c, &b);
            self->base[0] = c.x;
            self->base[1] = c.y;
            self->base[2] = c.z;
        }
    } else {
        cVec_set4(&c, self->base[0], self->base[1], self->base[2], 1.0f);
        capVu0AddVectorXYZ(&pos, &c, &b);
    }
    capVu0AddVectorXYZ(&pos, &pos, &move);
    if (self->data->gustFrom <= t) {
        cVec_set4(&c, self->data->windBase[0], self->data->windBase[1], self->data->windBase[2], 1.0f);
        self->wind[0] *= self->data->gustDecay[0];
        self->wind[1] *= self->data->gustDecay[1];
        self->wind[2] *= self->data->gustDecay[2];
        cVec_set4(&d, self->wind[0], self->wind[1], self->wind[2], 1.0f);
        capVu0AddVectorXYZ(&tmp, &c, &d);
        capVu0AddVectorXYZ(&pos, &pos, &tmp);
    }
    if (self->data->windFrom <= t && t < self->data->windTo) {
        cVec_set4(&c, self->data->windBase[0], self->data->windBase[1], self->data->windBase[2], 1.0f);
        cVec_set4(&d, self->data->windAccel[0], self->data->windAccel[1], self->data->windAccel[2], 1.0f);
        cVec_set4(&e, self->wind[0], self->wind[1], self->wind[2], 1.0f);
        capVu0AddVectorXYZ(&e, &e, &d);
        capVu0AddVectorXYZ(&tmp, &e, &c);
        capVu0AddVectorXYZ(&pos, &pos, &tmp);
        self->wind[0] = e.x;
        self->wind[1] = e.y;
        self->wind[2] = e.z;
    }
    cNode_setTranslationFromWorld(self, (float *)&pos);
}
