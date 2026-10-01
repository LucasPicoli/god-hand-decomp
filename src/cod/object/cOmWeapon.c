/* TU: cOmWeapon [object] - recovered C++ class. */
#include "godhand/cOmWeapon.h"
#include "include_asm.h"

extern void func_001CF3A8(void *a0);
extern void cModel_calcParts(void *a0);
extern void func_001331B8(char *a0, long a1, int a2);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern char D_005CAE50[];

static inline void cpy3(float *d, float *s)
{
    if (d != s) {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
    }
}

/* Attach the weapon to slot idx of a fighter: pin its collision body to the fighter's body part, copy the hold offsets and start the held state. */
__attribute__((section(".text.cOmWeapon_setParent")))
void cOmWeapon_setParent(cOmWeapon *self, cOmBase *par, int idx, cVec *heldPos, cVec *heldOfs)
{
    unsigned char frame[0x10] __attribute__((aligned(16)));
    int b, b2;
    unsigned char ok, ok2;
    cOmBase *part;
    cOmBase *body;
    cVec *anchor;

    ok = ((*(int *)frame = b = par->childNum), (idx >= 0 && idx < b));
    if (ok) part = par->children[idx]; else part = 0;
    if (part == 0) return;
    ok2 = ((*(int *)frame = b2 = self->base.childNum), (b2 != 0));
    if (ok2) body = self->base.children[0]; else body = 0;
    if (body == 0) return;
    anchor = body->anchor;
    body->posPrev.x = 0.0f;
    body->posPrev.y = 0.0f;
    body->posPrev.z = 0.0f;
    body->owner = part;
    cVec_copy3(anchor, heldPos);
    cVec_copy3(&body->posPrev, heldOfs);
    self->parentIdx = idx;
    self->parent = par;
    cVec_copy3(&self->heldPos, heldPos);
    cVec_copy3(&self->heldOfs, heldOfs);
    self->base.mode = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
    self->unk664 = 0;
    self->base.phase = 1;
    func_001CF3A8(self);
    cModel_calcParts(self);
    func_001331B8(D_005CAE50, self->base.modelHandle, 0);
    if (self->base.actorId != 0x369) return;
    if (par == 0) return;
    if (par->actionId == 0x252) {
        SetEffect(0xAA, 0xC, self, 0, 8, 0xFFFFFFFFu);
    }
    if (par->actionId == 0x263) {
        SetEffect(0xBC, 0x1D, self, 0, 8, 0xFFFFFFFFu);
    }
}
