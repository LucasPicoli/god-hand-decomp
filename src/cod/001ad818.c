/* sn-2.95.3-136 matched TU. */
#include "godhand/cOmWeapon.h"

extern void cModel_calcParts(void *m);
extern void cOmBase_setMeshColorFromLayer(void *a0, int a1, float r, float g, float b);
extern float fRand0_1(void);
extern float DoubleFloatMinusHalf_31D020(void);

/* sn-2.95.3-136 */



static inline int GetLayerObj(char *a0, int *frame, int idx)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (idx >= 0 && idx < b) {
        return *(int *)(*(int *)(a0 + 0x278) + idx * 4);
    }
    return 0;
}

/* Throw a weapon with velocity pos and throw argument arg and enter state 0x11. */
__attribute__((section(".text.func_001D0140")))
void func_001D0140(cOmWeapon *self, cVec *pos, int arg)
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
        cModel_calcParts(self);
        self->throwArg = arg;
        {
            cVec *d2 = &self->vel;
            if (d2 != pos) { d2->x = pos->x; d2->y = pos->y; d2->z = pos->z; }
        }
        self->base.mode = 0;
        self->base.phase = 0x11;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* sn-2.95.3-136 */



/* Throw a weapon with velocity pos and throw argument arg and enter state 0x12. */
__attribute__((section(".text.func_001D0240")))
void func_001D0240(cOmWeapon *self, cVec *pos, int arg)
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
        cModel_calcParts(self);
        self->throwArg = arg;
        {
            cVec *d2 = &self->vel;
            if (d2 != pos) { d2->x = pos->x; d2->y = pos->y; d2->z = pos->z; }
        }
        self->base.mode = 0;
        self->base.phase = 0x12;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* sn-2.95.3-136 */



/* Let go of the holder and enter state 0x14 with the throw argument cleared. */
__attribute__((section(".text.func_001D0340")))
void func_001D0340(cOmWeapon *self)
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
        cModel_calcParts(self);
        self->throwArg = 0;
        self->base.mode = 0;
        self->base.phase = 0x14;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* sn-2.95.3-136 */



/* Let go of the holder and enter state 0x15 with the throw argument cleared. */
__attribute__((section(".text.func_001D0408")))
void func_001D0408(cOmWeapon *self)
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
        cModel_calcParts(self);
        self->throwArg = 0;
        self->base.mode = 0;
        self->base.phase = 0x15;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

__attribute__((section(".text.func_001AD818")))
void func_001AD818(char *p)
{
    unsigned char frame[0x10];

    if (GetLayerObj(p, (int *)frame, 1) != 0) {
        int e1 = GetLayerObj(p, (int *)frame, 1);
        *(int *)(e1 + 0x104) = 0;
    }
    if (GetLayerObj(p, (int *)frame, 2) != 0) {
        int e2 = GetLayerObj(p, (int *)frame, 2);
        *(int *)(e2 + 0x104) = 0;
    }
}

__attribute__((section(".text.func_002F53A8")))
int func_002F53A8(char *p)
{
    unsigned char frame[0x10];
    char *c;
    char *q;
    char *q2;
    int b1, b2;
    int obj1, obj2;
    int idx1, idx2;
    unsigned char ok2;

    c = *(char **)(p + 0x110);
    q = *(char **)(p + 0x114);
    *(int *)(p + 0x2B0) = *(char *)(c + 0x18C);
    if (q == 0) return 0;
    idx1 = *(char *)(c + 0xBE);
    if (idx1 < 0) return 0;
    *(int *)frame = b1 = *(unsigned char *)(q + 0x2B4);
    if (idx1 < b1) obj1 = *(int *)(*(int *)(q + 0x278) + idx1 * 4); else obj1 = 0;
    if (obj1 == 0) return 0;
    q2 = *(char **)(p + 0x114);
    idx2 = *(int *)(p + 0x2B0);
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(q2 + 0x2B4)), (idx2 >= 0 && idx2 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(q2 + 0x278) + idx2 * 4); else obj2 = 0;
    return obj2 != 0;
}

__attribute__((section(".text.func_001B54E8")))
void func_001B54E8(char *p)
{
    unsigned char frame[0x10];
    int obj;
    long fl;
    int t;
    float d;

    fl = *(unsigned int *)(p + 0x600);
    if (((fl >> 4) & 1) == 0) {
        return;
    }
    t = *(short *)(p + 0x644);
    if (t == 0) {
        cOmBase_setMeshColorFromLayer(p, 0, 1.0f, 1.0f, 1.0f);
        *(int *)(p + 0x600) = *(int *)(p + 0x600) & -0x11;
    } else {
        d = 0.10471976f;
        t = *(unsigned short *)(p + 0x644);
        if (t & 1) {
            d = -d;
        }
        obj = GetLayerObj(p, (int *)frame, 0);
        *(float *)(obj + 0x104) = *(float *)(obj + 0x104) + d;
        *(unsigned short *)(p + 0x644) = *(unsigned short *)(p + 0x644) - 1;
    }
}

/* Throw a weapon at target with a random arc and spin and enter state 0xC. */
__attribute__((section(".text.func_001CFD60")))
void func_001CFD60(cOmWeapon *self, int target)
{
    unsigned char frame[0x10];
    cOmBase *holder;
    cVec *d;
    cOmBase *body;
    float f;

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
        cModel_calcParts(self);
        self->target = target;
        self->unk6A0 = 0;
        self->unk6A4 = fRand0_1() * 2.0f + 2.0f;
        self->unk6A8 = fRand0_1() * 2.0f + 7.0f;
        f = DoubleFloatMinusHalf_31D020();
        self->base.phase = 0xC;
        self->base.stepArg = 0;
        self->base.mode = 0;
        self->base.step = 0;
        self->spin = f * 3.14159274f;
    }
}
