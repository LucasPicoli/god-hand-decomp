/* sn-2.95.3-136 */
#include "godhand/cNode.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

/* Shared spin settings of an effect node. */
typedef struct FxParam {
    char unk00[0x1C0];
    float spinDamp;                     /* 0x1C0 */
    float spin[3];                      /* 0x1C4 per step, in thousandths */
} FxParam;

/* The object an effect node is released from. */
typedef struct FxAnchor {
    char unk00[0x80];
    float mtx[4][4];                    /* 0x80 */
} FxAnchor;

/* An effect node that drifts away from its origin and falls. */
typedef struct cFxDrift {
    cNode base;                         /* 0x000 */
    char unkF4[0xC];
    FxParam *param;                     /* 0x100 */
    FxAnchor *holder;                   /* 0x104 object holding the node until release */
    FxAnchor *anchor;                   /* 0x108 */
    char unk10C[0x10];
    float pos[3];                       /* 0x11C */
    float rot[3];                       /* 0x128 */
    float vel[3];                       /* 0x134 */
    char unk140[0x30];
    float speed;                        /* 0x170 push away from the origin */
    float spread;                       /* 0x174 scale on the position before the push, 0 for none */
    float fall;                         /* 0x178 drop per step */
    char unk17C[0xE];
    short delay;                        /* 0x18A frames until release, counts down by 2 */
} cFxDrift;

/* Set a point: x, y, z and w = 1. */
static __inline__ void vecSet(cVec *d, float x, float y, float z)
{
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = 1.0f;
}

extern void sceVu0ScaleVectorXYZ(void *a0, void *a1, float s);
extern void sceVu0Normalize(void *a0, void *a1);
extern void capVu0AddVectorXYZ(void *a0, void *a1, void *a2);
extern void *func_002B6310(void *dst, void *node);
extern void cNode_setLocalTranslation(void *self, void *v);
extern void MtxCopy(void *dst, void *src);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);
extern void *func_002B62F8(void *a0, char *a1);
extern float *CallThenReturnPlusB0_002B6420_2B61B0(void *node);
extern void func_00147C88(void *a0, void *a1, int a2);
extern void func_002B6230(char *a0, float *a1);
extern void func_002B5D58(void *arg, void *parent);
extern void MtxMultiply(void *dst, void *a, void *b);
extern void func_002B6350(void *node, void *m);
extern void *func_002B6080(void *a0, void *a1);
extern void *StoreVecFromFieldB0_2B6160(void *a0, void *a1);
extern void cNode_setLocalScale(void *self, void *v);

/* Push the position away from the origin, drop it, and add it to the velocity. */
__attribute__((section(".text.func_003033A8")))
void func_003033A8(cFxDrift *self)
{
    cVec p;
    cVec v;
    cVec d;

    p.x = self->pos[0];
    p.y = self->pos[1];
    p.z = self->pos[2];
    p.w = 1.0f;
    v.x = self->vel[0];
    v.y = self->vel[1];
    v.z = self->vel[2];
    v.w = 1.0f;
    if (self->spread != 0.0f) {
        sceVu0ScaleVectorXYZ(&p, &p, self->spread);
    }
    VU0_SQC2_VF0_MEM(&d, 0);
    sceVu0Normalize(&d, &p);
    sceVu0ScaleVectorXYZ(&d, &d, self->speed);
    capVu0AddVectorXYZ(&p, &p, &d);
    p.y -= self->fall;
    VU0_VADD_XYZ_IP(&v, 0, &p);
    self->pos[0] = p.x;
    self->pos[1] = p.y;
    self->pos[2] = p.z;
    self->vel[1] = v.y;
    self->vel[0] = v.z;                 /* z into vel[0], as retail does at 0x303484 */
}

/* Count the release delay down; when it runs out, move the node into the anchor's frame and detach it. */
__attribute__((section(".text.func_003034A8")))
void func_003034A8(cFxDrift *self)
{
    cVec p;
    float m[4][4];
    cVec t;
    cVec r;

    if (self->holder == 0) {
        return;
    }
    if (self->delay < 0) {
        return;
    }
    self->delay -= 2;
    if (self->delay > 0) {
        return;
    }
    p.x = self->pos[0];
    p.y = self->pos[1];
    p.z = self->pos[2];
    p.w = 1.0f;
    self->delay = 0;
    MtxCopy(m, self->anchor->mtx);
    VU0_SQC2_VF0_MEM(&t, 0);
    CopyVec3ToField30_147C40((float *)m, (float *)&t);
    sceVu0ApplyMatrix(&p, m, &p);
    self->pos[0] = p.x;
    self->pos[1] = p.y;
    self->pos[2] = p.z;
    func_002B62F8(&t, (char *)self);
    VU0_SQC2_VF0_MEM(&r, 0);
    func_00147C88(&r, CallThenReturnPlusB0_002B6420_2B61B0(self), 0);
    func_002B6230((char *)self, (float *)&t);
    cNode_setTranslationFromParent(self, &r);
    func_002B5D58(self, 0);
    self->holder = 0;
}

/* Push the node's translation away from its origin, drop it, and set it from the parent's frame. */
__attribute__((section(".text.func_00304940")))
void func_00304940(cFxDrift *self)
{
    cVec p;
    cVec v;
    cVec d;

    p.x = self->pos[0];
    p.y = self->pos[1];
    p.z = self->pos[2];
    p.w = 1.0f;
    VU0_SQC2_VF0_MEM(&v, 0);
    func_002B6310(&d, self);
    v.x = d.x;
    v.y = d.y;
    v.z = d.z;
    if (self->spread != 0.0f) {
        sceVu0ScaleVectorXYZ(&p, &p, self->spread);
    }
    VU0_SQC2_VF0_MEM(&d, 0);
    sceVu0Normalize(&d, &p);
    sceVu0ScaleVectorXYZ(&d, &d, self->speed);
    capVu0AddVectorXYZ(&p, &p, &d);
    p.y -= self->fall;
    VU0_VADD_XYZ_IP(&v, 0, &p);
    self->pos[0] = p.x;
    self->pos[1] = p.y;
    self->pos[2] = p.z;
    cNode_setLocalTranslation(self, &v);
}

/* Count the release delay down; when it runs out, take the node out of the holder's frame into its own. */
__attribute__((section(".text.func_00304A48")))
void func_00304A48(cFxDrift *self)
{
    float m[4][4];
    cVec work[4];
    cVec z;

    if (self->holder == 0) {
        return;
    }
    if (self->delay < 0) {
        return;
    }
    self->delay -= 2;
    if (self->delay > 0) {
        return;
    }
    self->delay = 0;
    MtxCopy(m, CallThenReturnPlusB0_002B6420_2B61B0(self));
    if (self->holder != 0) {
        MtxCopy(work, self->holder->mtx);
        MtxMultiply(m, work, m);
        func_002B6350(self, m);
    }
    func_002B6080(&work[0], self);
    VU0_SQC2_VF0_MEM(&work[1], 0);
    func_00147C88(&work[1], m, 0);
    StoreVecFromFieldB0_2B6160(&work[2], self);
    cNode_setLocalScale(self, &work[0]);
    func_002B6230((char *)self, (float *)&work[1]);
    cNode_setLocalTranslation(self, &work[2]);
    vecSet(&work[3], self->pos[0], self->pos[1], self->pos[2]);
    VU0_SQC2_VF0_MEM(&z, 0);
    CopyVec3ToField30_147C40((float *)m, (float *)&z);
    sceVu0ApplyMatrix(&work[3], m, &work[3]);
    self->pos[0] = work[3].x;
    self->pos[1] = work[3].y;
    self->pos[2] = work[3].z;
    func_002B5D58(self, 0);
    self->holder = 0;
}
