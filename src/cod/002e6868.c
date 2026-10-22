/* sn-2.95.3-136: func_002E6868, object ground-mode step, then sync the node position and scale. */
#include "godhand/cObjSimple.h"

#define GROUND_FADE_DEFAULT  0x1E       /* fade length when fadeInit is 0 */
#define LINK_SCALES          2          /* link flags bit: the link's factor scales the fade */
#define MOT_HIDDEN           2          /* motion flags250 bit set when it is not synced */

/* The low bits of the ground word at 0x2DC. */
typedef struct ObjFlags {
    unsigned char b0 : 1;               /* on the ground */
    unsigned char b1 : 1;
    unsigned char b2 : 1;
} ObjFlags;

/* The object a link at 0x120 points to. */
typedef struct cObjLink {
    char unk00[8];
    float factor;                       /* 0x08 */
    cObjSimple *owner;                  /* 0x0C */
    int flags;                          /* 0x10 LINK_* */
} cObjLink;

/* The object this steps: its ground mode, a fade counter and the motion node it syncs. */
typedef struct cObjGround {
    char unk000[0x120];
    cObjLink *link;                     /* 0x120 0 when none */
    char unk124[0x188 - 0x124];
    float color[4];                     /* 0x188 copied to the motion node's vec240 and f24C */
    char unk198[0x24C - 0x198];
    unsigned char fadeLen;              /* 0x24C */
    unsigned char fadePos;              /* 0x24D */
    char unk24E[0x2B0 - 0x24E];
    cObjSimple *mot;                    /* 0x2B0 motion node, 0 when none */
    char unk2B4[0x2D4 - 0x2B4];
    unsigned int groundMode;            /* 0x2D4 */
    char unk2D8[4];
    unsigned int ground;                /* 0x2DC bit 0 on the ground (read as ObjFlags), bit 2 start the fade */
    char unk2E0[0x2E5 - 0x2E0];
    unsigned char fadeInit;             /* 0x2E5 fade length, 0 for the default */
} cObjGround;

extern void func_002FBED0(void *self);
extern void *StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void *CopyVec16From20_B62E0(void *dst, char *self);
extern void cNode_setLocalScale(void *self, void *v);
extern void *func_002B60D0(void *dst, void *self);
extern int func_00307118(void *p);
extern void Pos_followGroundB(char *self);
extern void cOmBase_dropTest(void *self);
extern void func_002E7098(void *self);
extern void UpdateObjByIndexedOp_2FBE50(void *self);
extern int func_002FB060(char *self);

static inline void vcopy(cObjSimpleVec3 *d, cObjSimpleVec3 *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int notGround(cObjGround *self)
{
    return !((ObjFlags *)&self->ground)->b0;
}

static inline int linkOn(cObjGround *self)
{
    cObjLink *q = self->link;
    if (q) {
        if ((int)q->owner->flags250 >= 0) {
            if (func_00307118(q) == 1)
                return 1;
        } else {
            self->link = 0;
        }
    }
    return 0;
}

__attribute__((section(".text.func_002E6868")))
void func_002E6868(cObjGround *self)
{
    cObjSimpleVec3 v;
    cObjSimpleVec3 w;
    cObjSimple *o;
    float scale;
    cObjLink *q;

    func_002FBED0(self);
    if (notGround(self)) {
        switch (self->groundMode) {
        case 0:
            Pos_followGroundB((char *)self);
            break;
        case 1:
            cOmBase_dropTest(self);
            break;
        case 2:
            func_002E7098(self);
            break;
        default:
            UpdateObjByIndexedOp_2FBE50(self);
            return;
        }
    } else if (self->ground & 4) {
        if (self->fadeInit)
            self->fadeLen = self->fadeInit;
        else
            self->fadeLen = GROUND_FADE_DEFAULT;
        self->ground &= ~4;
    }
    if (self->mot && func_002FB060((char *)self)) {
        o = self->mot;
        StoreVecFromFieldB0_2B6160(&v, self);
        vcopy(o->parentPos, &v);
        CopyVec16From20_B62E0(&v, (char *)self);
        v.z = v.x;
        cNode_setLocalScale(self, &v);
        func_002B60D0(&w, self);
        vcopy(&self->mot->rot, &w);
        vcopy(&self->mot->scale, &v);
        self->mot->vec240.x = self->color[0];
        self->mot->vec240.y = self->color[1];
        self->mot->vec240.z = self->color[2];
        self->mot->f24C = self->color[3];
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
        self->mot->f24C *= scale;
    } else {
        /* Retail writes here even when mot is 0, which lands at address 0x250. */
        self->mot->flags250 |= MOT_HIDDEN;
    }
}
