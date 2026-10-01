/* sn-2.95.3-136 matched TU. */
#include "godhand/cObjSimple.h"

extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern void cModel_setMeshDisplay(void *model, char *name, int on);
extern char D_0044B4D8[];
extern char D_0044B4E0[];
extern char D_0044B4E8[];

#define CD(N)                                                                 \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (i < n)))                                                        \
            ep = *((char **) (*((char **) (p + 0x278)) + (N) * 4));           \
        else                                                                  \
            ep = 0;                                                           \
        dp = *((float **) (ep + 0xD0));                                       \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

#define CE(N)                                                                 \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (i < n)))                                                        \
            ep = *((char **) (*((char **) (p + 0x278)) + (N) * 4));           \
        else                                                                  \
            ep = 0;                                                           \
        dp = (float *) (ep + 0xE0);                                           \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

#define CD0()                                                                 \
    {                                                                         \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (n != 0)))                                                       \
            ep = *((char **) *((char **) (p + 0x278)));                       \
        else                                                                  \
            ep = 0;                                                           \
        dp = *((float **) (ep + 0xD0));                                       \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

#define CE0()                                                                 \
    {                                                                         \
        int n;                                                                \
        char *ep;                                                             \
        float *dp;                                                            \
        if (((*((int *) hold) = n = *((unsigned char *) (p + 0x2B4))),         \
             (n != 0)))                                                       \
            ep = *((char **) *((char **) (p + 0x278)));                       \
        else                                                                  \
            ep = 0;                                                           \
        dp = (float *) (ep + 0xE0);                                           \
        dp[0] = ((float *) D_003BD880)[0];                                    \
        dp[1] = ((float *) D_003BD880)[1];                                    \
        dp[2] = ((float *) D_003BD880)[2];                                    \
    }

/* Reset child N's output position (or its vecE0) to the default vector D_003BD880. */
#define COBJSIMPLE_RESET_OUT(N)                                               \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        cObjSimple *ep;                                                       \
        cObjSimpleVec3 *dp;                                                   \
        if (((*((int *) hold) = n = self->childNum), (i < n)))                \
            ep = self->children[N];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = (cObjSimpleVec3 *) ep->outPos;                                   \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

#define COBJSIMPLE_RESET_E0(N)                                                \
    {                                                                         \
        int i = (N);                                                          \
        int n;                                                                \
        cObjSimple *ep;                                                       \
        cObjSimpleVec3 *dp;                                                   \
        if (((*((int *) hold) = n = self->childNum), (i < n)))                \
            ep = self->children[N];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = &ep->vecE0;                                                      \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

/* Same two resets for child 0, whose test is "any children". */
#define COBJSIMPLE_RESET_OUT0()                                               \
    {                                                                         \
        int n;                                                                \
        cObjSimple *ep;                                                       \
        cObjSimpleVec3 *dp;                                                   \
        if (((*((int *) hold) = n = self->childNum), (n != 0)))               \
            ep = self->children[0];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = (cObjSimpleVec3 *) ep->outPos;                                   \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

#define COBJSIMPLE_RESET_E00()                                                \
    {                                                                         \
        int n;                                                                \
        cObjSimple *ep;                                                       \
        cObjSimpleVec3 *dp;                                                   \
        if (((*((int *) hold) = n = self->childNum), (n != 0)))               \
            ep = self->children[0];                                           \
        else                                                                  \
            ep = 0;                                                           \
        dp = &ep->vecE0;                                                      \
        dp->x = D_003BD880.x;                                                 \
        dp->y = D_003BD880.y;                                                 \
        dp->z = D_003BD880.z;                                                 \
    }

extern cObjSimpleVec3 D_003BD880;
/* Make the prop follow its parent: copy the offset into this object's position and put it in the
 * parent's frame (the parent, or its child `parentIdx`), copy rot/vec240/f24C/flag bit 4 from the
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
        cObjSimple *o = self->parent;
        int n = o->childNum;
        int ok = 0;
        cObjSimple *ep;
        cObjSimpleVec3 *dd;
        cObjSimpleVec3 *ss;

        *((int *) hold) = n;
        if (idx >= 0) {
            ok = idx < n;
            n = 0;
        }
        if (ok & 0xFF)
            ep = o->children[idx];
        else
            ep = 0;
        dd = self->parentPos;
        ss = &self->parentOfsA;
        if (dd != ss) {
            dd->x = ss->x;
            dd->y = ss->y;
            dd->z = ss->z;
        }
        sceVu0ApplyMatrix(self->parentPos, ep->mtx, self->parentPos);
    } else {
        cObjSimpleVec3 *dd = self->parentPos;
        cObjSimpleVec3 *ss = &self->parentOfsA;
        cObjSimpleVec3 *m;

        if (dd != ss) {
            dd->x = ss->x;
            dd->y = ss->y;
            dd->z = ss->z;
        }
        m = self->parentPos;
        sceVu0ApplyMatrix(m, self->parent->mtx, m);
    }

    {
        cObjSimple *o2 = self->parent;
        cObjSimpleVec3 *d2 = &self->rot;
        cObjSimpleVec3 *s2 = &o2->rot;

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
        cModel_setMeshDisplay(self->parent, D_0044B4D8, 0);
        cModel_setMeshDisplay(self->parent, D_0044B4E0, 0);
        cModel_setMeshDisplay(self->parent, D_0044B4E8, 0);
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
        cObjSimple *o3 = self->parent;
        cObjSimpleVec3 *d3 = &self->vec240;
        cObjSimpleVec3 *s3 = &o3->vec240;

        if (d3 != s3) {
            d3->x = s3->x;
            d3->y = s3->y;
            d3->z = s3->z;
        }
    }
    obj = self->parent;
    self->f24C = obj->f24C;
    if (obj->flags250 & 0x10) {
        self->flags250 |= 0x10;
    } else {
        self->flags250 &= 0xFFFFFFEF;
    }
}
