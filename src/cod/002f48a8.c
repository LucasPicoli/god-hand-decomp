/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 [as=sn]: cObjBlend_stepBlendAndSync, advances the object's blend value and its rate, restarts the
 * motion node's texture motion at that blend, then syncs the node position, scale and colour (the
 * same tail as func_002E6868). */
#include "godhand/cObjSimple.h"

#define LINK_SCALES          2          /* link flags bit: the link's factor scales the fade */

/* The object a link at 0x120 points to. */
typedef struct cObjLink {
    char unk00[8];
    float factor;                       /* 0x08 */
    cObjSimple *owner;                  /* 0x0C */
    int flags;                          /* 0x10 LINK_* */
} cObjLink;

/* The texture motion header the node points to at 0x4D0. */
typedef struct cObjTexMotion {
    char unk00[4];
    unsigned short frames;              /* 0x04 */
} cObjTexMotion;

/* The motion node as this routine sees it: the texture motion at 0x4D0. */
typedef struct cObjBlendMot {
    char unk000[0x4D0];
    cObjTexMotion *tex;                 /* 0x4D0 */
} cObjBlendMot;

/* The object this steps: a blend value, its rate and the motion node it syncs. */
typedef struct cObjBlend {
    char unk000[0x120];
    cObjLink *link;                     /* 0x120 0 when none */
    char unk124[0x188 - 0x124];
    float color[4];                     /* 0x188 copied to the motion node's vec240 and f24C */
    char unk198[0x24C - 0x198];
    unsigned char fadeLen;              /* 0x24C */
    unsigned char fadePos;              /* 0x24D */
    char unk24E[0x2B0 - 0x24E];
    cObjSimple *mot;                    /* 0x2B0 motion node */
    char unk2B4[0x2C0 - 0x2B4];
    float blendRate;                    /* 0x2C0 */
    float rateRate;                     /* 0x2C4 */
    char unk2C8[0x2D8 - 0x2C8];
    float blend;                        /* 0x2D8 0..1 */
} cObjBlend;

extern void func_002FBED0(void *self);
extern void *StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void *CopyVec16From20_B62E0(void *dst, char *self);
extern void cNode_setLocalScale(void *self, void *v);


extern int setMotionInfo(void *self, void *motion, char *motionEnd, unsigned int start,
                         float rate, float blend, int flags);
extern int moveMotion(void *self);

static inline int linkOn(cObjBlend *self)
{
    cObjLink *q = self->link;
    if (q) {
        if (q->owner->objFlags >= 0) {
            if (func_00307118(q) == 1)
                return 1;
        } else {
            self->link = 0;
        }
    }
    return 0;
}

__attribute__((section(".text.cObjBlend_stepBlendAndSync")))
void cObjBlend_stepBlendAndSync(cObjBlend *self)
{
    cObjSimpleVec3 v;
    cObjSimpleVec3 w;
    cObjSimple *o;
    cObjTexMotion *tex;
    int last;
    float scale;
    cObjLink *q;

    func_002FBED0(self);
    last = 0;
    self->blend = self->blend + self->blendRate;
    self->blendRate = self->blendRate + self->rateRate;
    if (1.0f < self->blend)
        self->blend = 1.0f;
    if (self->blend < 0.0f)
        self->blend = 0.0f;
    /* A volatile read of mot: retail does not reuse this load for setMotionInfo. */
    tex = ((cObjBlendMot *)*(cObjSimple * volatile *)&self->mot)->tex;
    if (tex != 0)
        last = tex->frames - 1;
    {
        float t = (float)(unsigned int)last * self->blend;
        setMotionInfo(self->mot, ((cObjBlendMot *)self->mot)->tex, 0, 0, 0.0f, t, 0);
    }
    moveMotion(self->mot);
    o = self->mot;
    StoreVecFromFieldB0_2B6160(&v, self);
    cVec_copy3(o->pos, &v);
    CopyVec16From20_B62E0(&v, (char *)self);
    v.z = v.x;
    cNode_setLocalScale(self, &v);
    func_002B60D0(&w, self);
    cVec_copy3(&self->mot->rot, &w);
    cVec_copy3(&self->mot->scale, &v);
    self->mot->tint.x = self->color[0];
    self->mot->tint.y = self->color[1];
    self->mot->tint.z = self->color[2];
    self->mot->tint.w = self->color[3];
    scale = 1.0f;
    if (self->fadeLen) {
        int a = self->fadeLen;
        scale = (float)(a - self->fadePos) / (float)a;
    }
    if (linkOn(self) == 1) {
        q = self->link;
        if ((q->flags >> 1) & 1)
            scale *= q->factor;
    }
    self->mot->tint.w *= scale;
}
