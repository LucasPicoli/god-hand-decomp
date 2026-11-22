/* sn-2.95.3-136 matched TU. */
#include "godhand/cObjSimple.h"
#include "godhand/cOmBase.h"
#include "godhand/globals.h"

extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern void cModel_setMeshDisplay(void *model, char *name, int on);

/* Reset child N's anchor position (or its trans) to the default vector D_003BD880. */
#define COBJSIMPLE_RESET_OUT(N)                                               \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        cOmBase *ep;                                                          \
        cVec *dp;                                                             \
        if (((*((int *) hold) = n = self->partNum), (i < n)))                 \
            ep = self->children[N];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = ep->anchor;                                                      \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

#define COBJSIMPLE_RESET_E0(N)                                                \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        cOmBase *ep;                                                          \
        cVec *dp;                                                             \
        if (((*((int *) hold) = n = self->partNum), (i < n)))                 \
            ep = self->children[N];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = &ep->trans;                                                      \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

/* Same two resets for child 0, whose test is "any children". */
#define COBJSIMPLE_RESET_OUT0()                                               \
    {                                                                         \
        int n;                                                                \
        cOmBase *ep;                                                          \
        cVec *dp;                                                             \
        if (((*((int *) hold) = n = self->partNum), (n != 0)))                \
            ep = self->children[0];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = ep->anchor;                                                      \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

#define COBJSIMPLE_RESET_E00()                                                \
    {                                                                         \
        int n;                                                                \
        cOmBase *ep;                                                          \
        cVec *dp;                                                             \
        if (((*((int *) hold) = n = self->partNum), (n != 0)))                \
            ep = self->children[0];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = &ep->trans;                                                      \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

extern cObjSimpleVec3 D_003BD880;
/* Make the prop follow its parent: copy the offset into this object's position and put it in the
 * parent's frame (the parent, or its child `parentIdx`), copy rot, tint and objFlags bit 4 from the
 * parent, and reset the child positions chosen by `followSel`. */
__attribute__((section(".text.cObjSimple_FollowParent")))
void cObjSimple_FollowParent(cObjSimple *self)
{
    char hold[16];
    int idx;
    int sel;
    cObjSimple *obj;

    idx = self->parentIdx;
    if (idx != -1) {
        cObjSimple *o = self->parentObj;
        int n = o->partNum;
        int ok = 0;
        cOmBase *ep;
        cVec *dd;
        cVec *ss;

        *((int *) hold) = n;
        if (idx >= 0) {
            ok = idx < n;
            n = 0;
        }
        if (ok & 0xFF)
            ep = o->children[idx];
        else
            ep = 0;
        dd = self->pos;
        ss = &self->parentOfsA;
        if (dd != ss) {
            dd->x = ss->x;
            dd->y = ss->y;
            dd->z = ss->z;
        }
        sceVu0ApplyMatrix(self->pos, ep->mtx, self->pos);
    } else {
        cVec *dd = self->pos;
        cVec *ss = &self->parentOfsA;
        cVec *m;

        if (dd != ss) {
            dd->x = ss->x;
            dd->y = ss->y;
            dd->z = ss->z;
        }
        m = self->pos;
        sceVu0ApplyMatrix(m, self->parentObj->mtx, m);
    }

    {
        cObjSimple *o2 = self->parentObj;
        cVec *d2 = &self->rot;
        cVec *s2 = &o2->rot;

        if (d2 != s2) {
            d2->x = s2->x;
            d2->y = s2->y;
            d2->z = s2->z;
        }
    }

    sel = self->followSel;
    switch (sel) {
    case 1:
        COBJSIMPLE_RESET_OUT0()
        COBJSIMPLE_RESET_OUT(1)
        COBJSIMPLE_RESET_E00()
        COBJSIMPLE_RESET_E0(1)
        COBJSIMPLE_RESET_OUT(17)
        COBJSIMPLE_RESET_OUT(18)
        COBJSIMPLE_RESET_E0(17)
        COBJSIMPLE_RESET_E0(18)
        break;
    case 2:
        COBJSIMPLE_RESET_OUT0()
        COBJSIMPLE_RESET_OUT(1)
        COBJSIMPLE_RESET_OUT(2)
        COBJSIMPLE_RESET_E00()
        COBJSIMPLE_RESET_E0(1)
        COBJSIMPLE_RESET_E0(2)
        break;
    case 3:
        COBJSIMPLE_RESET_OUT0()
        COBJSIMPLE_RESET_OUT(1)
        COBJSIMPLE_RESET_E00()
        COBJSIMPLE_RESET_E0(1)
        cModel_setMeshDisplay(self->parentObj, D_0044B4D8, 0);
        cModel_setMeshDisplay(self->parentObj, D_0044B4E0, 0);
        cModel_setMeshDisplay(self->parentObj, D_0044B4E8, 0);
        break;
    case 4:
        COBJSIMPLE_RESET_OUT0()
        COBJSIMPLE_RESET_OUT(1)
        COBJSIMPLE_RESET_OUT(2)
        COBJSIMPLE_RESET_OUT(3)
        COBJSIMPLE_RESET_OUT(4)
        COBJSIMPLE_RESET_OUT(5)
        COBJSIMPLE_RESET_OUT(6)
        COBJSIMPLE_RESET_E00()
        COBJSIMPLE_RESET_E0(1)
        COBJSIMPLE_RESET_E0(2)
        COBJSIMPLE_RESET_E0(3)
        COBJSIMPLE_RESET_E0(4)
        COBJSIMPLE_RESET_E0(5)
        COBJSIMPLE_RESET_E0(6)
        break;
    case 0:
    case 5:
    default:
        break;
    }

    {
        cObjSimple *o3 = self->parentObj;
        cVec *d3 = &self->tint;
        cVec *s3 = &o3->tint;

        if (d3 != s3) {
            d3->x = s3->x;
            d3->y = s3->y;
            d3->z = s3->z;
        }
    }
    obj = self->parentObj;
    self->tint.w = obj->tint.w;
    if (obj->objFlags & 0x10) {
        self->objFlags |= 0x10;
    } else {
        self->objFlags &= 0xFFFFFFEF;
    }
}
