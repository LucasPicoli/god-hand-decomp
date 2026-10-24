/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"
#include "godhand/cNode.h"
#include "godhand/objField.h"
#include "godhand/vu0.h"
#include "godhand/espSys.h"
#include "godhand/gameWork.h"

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
    if (((self->rec->flags & 0x2000) == 0 && (self->flags & 0x1000000)) || (D_007474A0.flags5E4 & SYSFLAG_SLOWMO))
        func_002FA350(&self->time);
    else
        self->time += 1.0f;
    if (((self->rec->flags & 0x2000) == 0 && (self->flags & 0x1000000)) || (D_007474A0.flags5E4 & SYSFLAG_SLOWMO))
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
