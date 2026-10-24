/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cNode.h"
#include "godhand/objField.h"
#include "godhand/vu0.h"

typedef struct espEmitRec {
    unsigned char flags0;               /* 0x00 bit 7: the emitter follows nothing */
    char unk01[3];
    unsigned int flags;                 /* 0x04 */
    char unk08[0x133 - 0x8];
    unsigned char espNo;                /* 0x133 the particle kind it emits */
} espEmitRec;

/* The node an emitter rides on. */
typedef struct espAnchor {
    char unk00[0x80];
    float mtx[4][4];                    /* 0x80 world matrix, translation in row 3 */
} espAnchor;

typedef struct espEmitter {
    cNode base;                         /* 0x000 */
    char unk0F4[0x100 - 0xF4];
    espEmitRec *rec;                    /* 0x100 */
    espAnchor *parent;                  /* 0x104 */
    cGameObj *owner;                    /* 0x108 */
    char unk10C[0x114 - 0x10C];
    unsigned int flags;                 /* 0x114 */
    unsigned int flags2;                /* 0x118 */
    char unk11C[0x180 - 0x11C];
    float time;                         /* 0x180 */
    char unk184[2];
    short delay;                        /* 0x186 frames before it starts */
    char unk188[2];
    short unk18A;
    char unk18C[0x1A0 - 0x18C];
    cVec emitPos;                       /* 0x1A0 */
    cVec rot;                           /* 0x1B0 */
    cVec trans;                         /* 0x1C0 */
    char unk1D0[0x224 - 0x1D0];
    unsigned short life;                /* 0x224 0: no limit */
    char unk226[2];
    float age;                          /* 0x228 */
} espEmitter;

typedef struct espEmitVt {
    char unk00[0x18];
    short emitDelta;                    /* 0x18 */
    short pad1A;
    int (*emit)(void *self, cVec *pos); /* 0x1C */
    char unk20[0x30 - 0x20];
    short addDelta;                     /* 0x30 */
    short pad32;
    void (*add)(void *self, void *child);
    short upd0Delta;                    /* 0x38 */
    short pad3A;
    void (*upd0)(void *self);
    short upd1Delta;                    /* 0x40 */
    short pad42;
    void (*upd1)(void *self);
    short upd2Delta;                    /* 0x48 */
    short pad4A;
    void (*upd2)(void *self);
    short upd3Delta;                    /* 0x50 */
    short pad52;
    void (*upd3)(void *self);
} espEmitVt;

extern void func_00302918(int *a0);
extern void MtxCopy(void *dst, void *src);
extern void MtxMultiply(void *dst, void *a, void *b);
extern void MtxInitRotVec(void *a0, float *a1, unsigned char order);
extern void MtxInitTransVec(float *a0, float *a1);
extern int CallThenReturnPlusB0_002B6420_2B61B0(int a0);
extern void func_00147C88(void *a0, void *a1, int a2);
extern void func_002B6230(char *a0, float *a1);
extern void cNode_setLocalTranslation(int a0, int a1);
extern void func_002FA350(float *time);
extern void *PullEsp(int a0);
extern void UpdateObjByIndexedOp_2FBE50(void *a0);
extern int func_002B5E58(void *self);
extern void func_002B5CF0(void *a0, void *a1);
extern int func_002B5E50(void *a0);
extern void func_003005D8(char *p);
extern int func_003035D0(espEmitter *self);
extern unsigned int D_00747A84;

static __inline__ int espEmitter_recFlag(espEmitter *self, unsigned int bit)
{
    return (self->rec->flags & bit) != 0;
}

/* An effect emitter's frame: follow its owner, place itself, count its age
 * and emit the particles due this frame. */
__attribute__((section(".text.func_003029C0")))
void func_003029C0(espEmitter *self)
{
    if (self->flags & 0x4000000)
        return;
    self->flags |= 0x1000000;
    if (self->flags2 & 0x40)
        self->flags &= ~0x1000000;
    if (self->rec->flags & 0x2000)
        self->flags &= ~0x1000000;
    if (espEmitter_recFlag(self, 0x40000) || espEmitter_recFlag(self, 0x8000)) {
        if (self->owner != 0 && self->owner->mode == 2)
            func_00302918((int *)self);
    }
    if (self->owner != 0 && self->owner->objFlags < 0) {
        self->unk18A = 0;
        func_00302918((int *)self);
    }
    if ((float)self->delay <= self->time) {
        unsigned long alone = self->rec->flags0;

        if (alone >> 7) {
            ((espEmitVt *)self->base.vt)->upd2((char *)self + ((espEmitVt *)self->base.vt)->upd2Delta);
            ((espEmitVt *)self->base.vt)->upd3((char *)self + ((espEmitVt *)self->base.vt)->upd3Delta);
            ((espEmitVt *)self->base.vt)->upd0((char *)self + ((espEmitVt *)self->base.vt)->upd0Delta);
            ((espEmitVt *)self->base.vt)->upd1((char *)self + ((espEmitVt *)self->base.vt)->upd1Delta);
        } else {
            float m[4][4];
            cVec v;
            float rm[4][4];
            float tm[4][4];

            if (self->parent != 0) {
                if (self->rec->flags & 0x400000) {
                    MtxCopy(m, self->owner->mtx);
                    cVec_set4(&v, self->parent->mtx[3][0], self->parent->mtx[3][1], self->parent->mtx[3][2], 1.0f);
                    m[3][0] = v.x;
                    m[3][1] = v.y;
                    m[3][2] = v.z;
                } else {
                    MtxCopy(m, self->parent->mtx);
                }
                MtxInitRotVec(rm, &self->rot.x, 0);
                MtxInitTransVec(tm[0], &self->trans.x);
                MtxMultiply(rm, tm, rm);
                MtxMultiply(m, m, rm);
            } else {
                MtxCopy(m, (void *)CallThenReturnPlusB0_002B6420_2B61B0((int)self));
            }
            VU0_SQC2_VF0_MEM(&v, 0);
            func_00147C88(&v, m, 0);
            func_002B6230((char *)self, &v.x);
            VU0_SQC2_VF0_MEM(rm, 0);
            ForwardVec3At30_147C60(rm, m[0]);
            cNode_setLocalTranslation((int)self, (int)rm);
        }
        self->flags |= 0x800000;
    }
    if (self->flags & 0x40000000) {
        if (func_002B5E58(self) == 0) {
            func_002B5CF0(self, (void *)func_002B5E50(self));
            func_003005D8((char *)self);
        }
        return;
    }
    if (((self->rec->flags & 0x2000) == 0 && (self->flags & 0x1000000)) || (D_00747A84 & 0x20000))
        func_002FA350(&self->time);
    else
        self->time += 1.0f;
    if (((self->rec->flags & 0x2000) == 0 && (self->flags & 0x1000000)) || (D_00747A84 & 0x20000))
        func_002FA350(&self->age);
    else
        self->age += 1.0f;
    if (self->life != 0 && (short)(int)self->age >= self->life) {
        func_00302918((int *)self);
        return;
    }
    {
        int n = func_003035D0(self);

        while (n-- > 0) {
            cNode *esp = PullEsp(self->rec->espNo);

            if (esp != 0) {
                espEmitVt *evt;

                ((espEmitVt *)self->base.vt)->add((char *)self + ((espEmitVt *)self->base.vt)->addDelta, esp);
                evt = (espEmitVt *)esp->vt;
                if (evt->emit((char *)esp + evt->emitDelta, &self->emitPos) == 0)
                    UpdateObjByIndexedOp_2FBE50(esp);
            }
        }
    }
}
