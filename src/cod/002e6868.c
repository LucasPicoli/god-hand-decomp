/* sn-2.95.3-136: func_002E6868, object ground-mode step, then sync the node position and scale. */
#include "godhand/cObjSimple.h"
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

typedef struct ObjFlags {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
} ObjFlags;

static inline void vcopy(cObjSimpleVec3 *d, cObjSimpleVec3 *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

static inline int notGround(char *self)
{
    return !((ObjFlags *)(self + 0x2DC))->b0;
}

static inline int linkOn(char *self)
{
    char *q = *(char **)(self + 0x120);
    if (q) {
        if (*(int *)(*(char **)(q + 0xC) + 0x250) >= 0) {
            if (func_00307118(q) == 1)
                return 1;
        } else {
            *(char **)(self + 0x120) = 0;
        }
    }
    return 0;
}

#define F(p, o) (*(float *)((char *)(p) + (o)))
#define MOT(s) (*(char **)((char *)(s) + 0x2B0))

__attribute__((section(".text.func_002E6868")))
void func_002E6868(char *self)
{
    cObjSimpleVec3 v;
    cObjSimpleVec3 w;
    char *o;
    float scale;
    char *q;

    func_002FBED0(self);
    if (notGround(self)) {
        switch (*(unsigned int *)(self + 0x2D4)) {
        case 0:
            Pos_followGroundB(self);
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
    } else if (*(unsigned int *)(self + 0x2DC) & 4) {
        if (*(unsigned char *)(self + 0x2E5))
            *(unsigned char *)(self + 0x24C) = *(unsigned char *)(self + 0x2E5);
        else
            *(unsigned char *)(self + 0x24C) = 0x1E;
        *(unsigned int *)(self + 0x2DC) &= ~4;
    }
    if (MOT(self) && func_002FB060(self)) {
        o = MOT(self);
        StoreVecFromFieldB0_2B6160(&v, self);
        vcopy(*(cObjSimpleVec3 **)(o + 0xF0), &v);
        CopyVec16From20_B62E0(&v, self);
        v.z = v.x;
        cNode_setLocalScale(self, &v);
        func_002B60D0(&w, self);
        vcopy((cObjSimpleVec3 *)(MOT(self) + 0x100), &w);
        vcopy((cObjSimpleVec3 *)(MOT(self) + 0x110), &v);
        F(MOT(self), 0x240) = F(self, 0x188);
        F(MOT(self), 0x244) = F(self, 0x18C);
        F(MOT(self), 0x248) = F(self, 0x190);
        F(MOT(self), 0x24C) = F(self, 0x194);
        scale = 1.0f;
        if (*(unsigned char *)(self + 0x24C)) {
            int a = *(unsigned char *)(self + 0x24C);
            scale = (float)(a - *(unsigned char *)(self + 0x24D)) / (float)a;
        }
        if (linkOn(self) == 1) {
            q = *(char **)(self + 0x120);
            if ((*(int *)(q + 0x10) >> 1) & 1)
                scale *= F(q, 8);
        }
        F(MOT(self), 0x24C) *= scale;
    } else {
        *(int *)(MOT(self) + 0x250) |= 2;
    }
}
