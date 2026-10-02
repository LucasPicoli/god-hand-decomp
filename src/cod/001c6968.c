/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmWeapon.h"
#include "godhand/cObjSimple.h"

extern void func_001C6C30(void *a0, void *a1);
extern float fRand1_1(void);
extern void cModel_calcParts(void *a0);
extern void func_001C6A90(void *a0, int a1, void *a2, void *a3, int t0);

/* sn-2.95.3-136 matched TU. */

/* Attach this prop to `parent` (or to its child `idx`; -1 = the parent itself) with two offsets.
 * Does nothing when the parent or the child is missing. Turns the parent follow on. */
__attribute__((section(".text.cObjSimple_SetParentInfo")))
void cObjSimple_SetParentInfo(cObjSimple *self, cObjSimple *parent, int idx,
                              cObjSimpleVec3 *ofsA, cObjSimpleVec3 *ofsB)
{
    char hold[16];
    cObjSimpleVec3 *d;

    if (parent == 0) {
        return;
    }
    if (idx != -1) {
        cObjSimpleChild *e;
        int ok;
        int cnt;

        ok = 0;
        cnt = parent->childNum;
        *((int *) hold) = cnt;
        if (idx >= 0) {
            ok = idx < cnt;
            cnt = 0;
        }
        if (ok & 0xFF) {
            e = parent->children[idx];
        } else {
            e = 0;
        }
        if (e == 0) {
            return;
        }
    }
    self->parent = parent;
    self->parentIdx = idx;
    d = &self->parentOfsA;
    if (d != ofsA) {
        d->x = ofsA->x;
        d->y = ofsA->y;
        d->z = ofsA->z;
    }
    d = &self->parentOfsB;
    if (d != ofsB) {
        d->x = ofsB->x;
        d->y = ofsB->y;
        d->z = ofsB->z;
    }
    self->parentOn = 1;
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.cOmSub_initMove3_y")))
void cOmSub_initMove3_y(char *a, unsigned char *obj, int idx, void *v)
{
    char hold[16];
    char *e;

    if (obj != 0) {
        if (idx >= 0) {
            char *e2;
            int cnt;

            cnt = *((unsigned char *) (obj + 0x2B4));
            *((int *) hold) = cnt;
            if (idx < cnt) {
                e2 = *((char **) (*((char **) (obj + 0x278)) + idx * 4));
            } else {
                e2 = 0;
            }
            e = e2;
        } else {
            e = (char *) obj;
        }
        if (e != 0) {
            float *d;
            float *s;

            *((char **) (a + 0x4)) = (char *) obj;
            *((char **) (a + 0x8)) = e;
            if (idx >= 0) {
                *((char **) (a + 0x40)) = *((char **) (e + 0xD0));
            } else {
                *((char **) (a + 0x40)) = *((char **) (e + 0xF0));
            }
            d = (float *) (a + 0x70);
            s = *((float **) (a + 0x40));
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
            d = (float *) (a + 0x80);
            s = (float *) (e + 0x100);
            if (d != s) {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
            }
        }
    }
    func_001C6C30(a, v);
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.cOmThrow_SetThrow")))
void cOmThrow_SetThrow(unsigned char *p, float *v)
{
    char hold[16];
    char *e;
    int cnt;
    float *d;
    float *s;

    p[0x2F4] = 0;
    p[0x2F5] = 1;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
    d = (float *) (p + 0x610);
    s = v;
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
    *((int *) (p + 0x644)) = 0;
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e = *((char **) *((char **) (p + 0x278)));
    } else {
        e = 0;
    }
    if (e != 0) {
        float *dd;
        float *ss;

        dd = *((float **) (e + 0xD0));
        ss = (float *) (p + 0x630);
        if (dd != ss) {
            dd[0] = ss[0];
            dd[1] = ss[1];
            dd[2] = ss[2];
        }
        *((int *) (e + 0x100)) = 0;
        *((int *) (e + 0x104)) = 0;
        *((float *) (e + 0x108)) =
            fRand1_1() * 0.5235987901687622f + 0.5235987901687622f;
        p[0x640] = 0;
    }
}

/* sn-2.95.3-136 matched TU. */



/* Throw a weapon with velocity v: let go of the holder, aim the collision body and enter state 3. */
__attribute__((section(".text.cOmWeapon_setThrow")))
void cOmWeapon_setThrow(cOmWeapon *self, cVec *v, int n)
{
    char hold[16];
    cOmBase *par;
    cOmBase *body;
    int cnt;

    par = self->parent;
    if (par != 0) {
        cVec *d;
        cVec *s;

        d = &self->base.posA;
        s = par->pos;
        if (d != s) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
    }
    self->base.animRate = 1.0f;
    self->base.objFlags = self->base.objFlags & 0xFFFFFFEF;
    self->parent = 0;
    self->fallSpeed = 0.0f;
    cnt = self->base.childNum;
    *((int *) hold) = cnt;
    if (cnt != 0) {
        body = self->base.children[0];
    } else {
        body = 0;
    }
    if (body != 0) {
        cVec *d;
        cVec *s;

        body->owner = &self->base;
        body->posPrev.x = 0.0f;
        body->posPrev.y = 0.0f;
        body->posPrev.z = 0.0f;
        cModel_calcParts(self);
        d = &self->vel;
        s = v;
        if (d != s) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
        self->throwArg = n;
        self->base.mode = 0;
        self->base.phase = 3;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* sn-2.95.3-136 matched TU. */




/* Throw a weapon at the player with velocity v: like setThrow, but the collision body gets a random spin (stored in posPrev.z) and the state is 5. */
__attribute__((section(".text.cOmWeapon_setThrowPL")))
void cOmWeapon_setThrowPL(cOmWeapon *self, cVec *v)
{
    char hold[16];
    cOmBase *par;
    cOmBase *body;
    int cnt;

    par = self->parent;
    if (par != 0) {
        cVec *d;
        cVec *s;

        d = &self->base.posA;
        s = par->pos;
        if (d != s) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
    }
    self->base.animRate = 1.0f;
    self->base.objFlags = self->base.objFlags & 0xFFFFFFEF;
    self->parent = 0;
    self->fallSpeed = 0.0f;
    cnt = self->base.childNum;
    *((int *) hold) = cnt;
    if (cnt != 0) {
        body = self->base.children[0];
    } else {
        body = 0;
    }
    if (body != 0) {
        cVec *d;
        cVec *s;

        body->owner = &self->base;
        body->posPrev.x = 0.0f;
        body->posPrev.y = 0.0f;
        body->posPrev.z =
            fRand1_1() * 0.5235987901687622f + 0.5235987901687622f;
        cModel_calcParts(self);
        d = &self->vel;
        s = v;
        if (d != s) {
            d->x = s->x;
            d->y = s->y;
            d->z = s->z;
        }
        self->base.mode = 0;
        self->base.phase = 5;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

static inline int GetLayerObj(char *a0, int *frame, int idx)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (idx >= 0 && idx < b) {
        return *(int *)(*(int *)(a0 + 0x278) + idx * 4);
    }
    return 0;
}

/* Throw variant that also zeroes the body's anchor vector: velocity pos, throw argument arg, state 4. */
__attribute__((section(".text.func_001CFB28")))
void func_001CFB28(cOmWeapon *self, cVec *pos, int arg)
{
    unsigned char frame[0x10];
    cOmBase *holder;
    cVec *d;
    cOmBase *body;

    holder = self->parent;
    if (holder != 0) {
        cVec *m = holder->pos;
        d = &self->base.posA;
        if (d != m) { d->x = m->x; d->y = m->y; d->z = m->z; }
    }
    self->base.animRate = 1.0f;
    self->base.objFlags = self->base.objFlags & 0xFFFFFFEF;
    self->parent = 0;
    self->fallSpeed = 0.0f;
    body = cOmBase_childAt(&self->base, (int *)frame, 0);
    if (body != 0) {
        body->owner = &self->base;
        body->posPrev.x = 0.0f;
        body->posPrev.y = 0.0f;
        body->posPrev.z = 0.0f;
        body->anchor->x = 0.0f;
        body->anchor->y = 0.0f;
        body->anchor->z = 0.0f;
        cModel_calcParts(self);
        {
            cVec *d2 = &self->vel;
            if (d2 != pos) { d2->x = pos->x; d2->y = pos->y; d2->z = pos->z; }
        }
        self->throwArg = arg;
        self->base.phase = 4;
        self->base.mode = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001C6968")))
void func_001C6968(char *a, int n, void *v)
{
    func_001C6A90(a, n, v, a + 0x80, 1);
}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_001C6A60")))
void func_001C6A60(char *a, int n, void *v, int fl)
{
    func_001C6A90(a, n, a + 0x70, v, fl | 2);
}
