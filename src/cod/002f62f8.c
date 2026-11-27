/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */
#include "godhand/cFxTrail.h"
#include "godhand/cOmBase.h"
#include "godhand/vu0.h"


extern void *StoreVecFromFieldB0_2B6160(cVec *dst, void *obj);

extern float *CallThenReturnPlusB0_002B6420_2B61B0(void *node);
extern void MtxCopy(void *dst, void *src);
extern void CopyVec3ToField30_147C40(float *a0, float *a1);

#define SEG(base, i)  ((FxTrailSeg *)((base) + ((i) << 6)))
#define FXTRAIL_K60   0x3F80000080808080L   /* segment constant at 0x60 */
#define FXTRAIL_K68   1L
#define FXTRAIL_K0A8  2L

/* A trail bound to a part of its owner object. Fields past cFxTrail are this TU's. */
typedef struct FxPartLink { char unk[0x220]; } FxPartLink;   /* the record a child's link points into */

typedef struct FxPartTrailParam {
    char unk00[0x13C];
    float offset[3];                    /* 0x13C in centimetres */
    float fadeIn;                       /* 0x148 */
    char unk14C[0x20];
    int part;                           /* 0x16C nonzero: follow a part of the owner */
    int partIdx;                        /* 0x170 */
} FxPartTrailParam;

#define FXPT_NODE_FLAGS(t)  (*(unsigned int *)((char *)(t) + 0x104))  /* in cNode */
#define FXPT_NODE_LINKED    0x80
#define FXPT_OWNER(t)       (*(cOmBase **)((char *)(t) + 0x114))
#define FXPT_PTS2(t)        (*(cVec **)((char *)(t) + 0x2C0))
#define FXPT_PART_FOLLOW    0x4                                       /* flags2 */
#define FXPT_OFFSET(t)      ((float *)((char *)(t) + 0x2F0))
#define FXPT_FADE(t)        (*(float *)((char *)(t) + 0x300))
#define FXPT_PART(t)        (*(int *)((char *)(t) + 0x304))
#define FXPT_PART_IDX(t)    (*(int *)((char *)(t) + 0x308))
#define CHILD_LINK(c)       (*(FxPartLink **)((char *)(c) + 0x14C))

static __inline__ unsigned char childOk(cOmBase *b, int *frame, int idx)
{
    int n;
    return (*frame = n = b->partNum, idx >= 0 && idx < n);
}

/* Child idx of b, or 0 when idx is out of range; the count goes to *frame. */
static __inline__ cOmBase *childAt(cOmBase *b, int *frame, int idx)
{
    return childOk(b, frame, idx) ? b->children[idx] : 0;
}

/* Set a part-following trail up: copy the part binding from the parameters and
   resolve it on the owner, then build the segments as cFxTrail_setup does with
   a second point array, and set the life. */
__attribute__((section(".text.func_002F62F8")))
int func_002F62F8(cFxTrail *self, void *arg)
{
    int frame[4];
    cVec start;
    cVec start2;
    float m[16];
    cVec zero;
    int i;
    float wA, wB;
    FxTrailParam *prm;
    FxPartTrailParam *pp;
    cOmBase *owner;

    self->flags2 |= FXPT_PART_FOLLOW;
    FXPT_PART(self) = ((FxPartTrailParam *)self->param)->part;
    FXPT_PART_IDX(self) = ((FxPartTrailParam *)self->param)->partIdx;
    if (FXPT_PART(self) != 0) {
        owner = FXPT_OWNER(self);
        if (owner == 0) goto fail;
        if (childAt(owner, frame, FXPT_PART_IDX(self)) == 0) return 0;
        if (FXPT_NODE_FLAGS(self) & FXPT_NODE_LINKED) {
            if (CHILD_LINK(childAt(FXPT_OWNER(self), frame, FXPT_PART_IDX(self))) != 0) {
                FxPartLink *link = CHILD_LINK(childAt(FXPT_OWNER(self), frame, FXPT_PART_IDX(self)));
                FXPT_PART_IDX(self) = link - (FxPartLink *)childAt(FXPT_OWNER(self), frame, 0);
            }
        }
    }
    self->segNum = self->param->segNum;
    if (!(self->segNum < FXTRAIL_SEG_MAX + 1 && self->segNum != 0)) {
        self->segNum = FXTRAIL_SEG_DEF;
    }
    if (func_002EBD10(self, (int)arg, self->segNum) == 0) {
    fail: /* the owner test shares this return; a return of its own threads to the epilogue */
        return 0;
    }
    pp = (FxPartTrailParam *)self->param;
    FXPT_OFFSET(self)[0] = pp->offset[0] * 0.01f;
    FXPT_OFFSET(self)[1] = pp->offset[1] * 0.01f;
    FXPT_OFFSET(self)[2] = pp->offset[2] * 0.01f;
    FXPT_FADE(self) = 1.0f - pp->fadeIn;
    StoreVecFromFieldB0_2B6160(&start, self);
    func_002F6258(&start2, self, FXPT_OFFSET(self));
    for (i = 0; i < self->segNum; i++) {
        cVec_copy3(self->pts + i, &start);
        cVec_copy3(FXPT_PTS2(self) + i, &start2);
        ((FxTrailSeg *)self->segA)->k60 = FXTRAIL_K60;
        ((FxTrailSeg *)self->segA)->k68 = FXTRAIL_K68;
        ((FxTrailSeg *)self->segB)->k60 = FXTRAIL_K60;
        ((FxTrailSeg *)self->segB)->k68 = FXTRAIL_K68;
        wA = 1.0f;
        if (self->flags & FXTRAIL_FLIP_A) {
            wA = -1.0f;
        }
        wB = 1.0f;
        if ((self->flags & FXTRAIL_FLIP_B) == 0) {
            wB = -1.0f;
        }
        SEG(self->segA, i)->a0 = 0;
        SEG(self->segA, i)->fade = wB * (float)i / (float)(self->segNum - 1) * self->width;
        SEG(self->segA, i)->k0A8 = FXTRAIL_K0A8;
        SEG(self->segA, i)->end0 = wA;
        SEG(self->segA, i)->end1 = SEG(self->segA, i)->fade;
        SEG(self->segA, i)->kC8 = FXTRAIL_K0A8;
        SEG(self->segB, i)->a0 = 0;
        SEG(self->segB, i)->fade = SEG(self->segA, i)->fade;
        SEG(self->segB, i)->k0A8 = FXTRAIL_K0A8;
        SEG(self->segB, i)->end0 = wA;
        SEG(self->segB, i)->end1 = SEG(self->segA, i)->fade;
        SEG(self->segB, i)->kC8 = FXTRAIL_K0A8;
    }
    MtxCopy(m, CallThenReturnPlusB0_002B6420_2B61B0(self));
    VU0_SQC2_VF0_MEM(&zero, 0);
    CopyVec3ToField30_147C40(m, (float *)&zero);
    prm = self->param;
    self->life = prm->life + 1;
    if (FXPT_PART(self) != 0 && FXPT_OWNER(self) == 0) {
        return 0;
    }
    return 1;
}
