/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmWeapon.h"
#include "godhand/vu0.h"

extern void func_001331B8(char *a0, long a1, int a2);
extern char D_005CAE50[];
extern void cModel_calcParts(void *model);
extern char *Getplayer(void);
extern void MtxInitRotY(void *a0, float angle);
extern void sceVu0ApplyMatrix(void *dst, void *m, void *src);

/* Reset a weapon to its resting state: release the hold bit, normal anim rate, state bytes cleared and phase 2. */
__attribute__((section(".text.cOmWeapon_resetHold")))
void cOmWeapon_resetHold(cOmWeapon *self) {
    self->base.animRate = 1.0f;
    self->base.objFlags = self->base.objFlags & 0xFFFFFFEF;
    self->base.phase = 2;
    self->fallSpeed = 0.0f;
    self->base.mode = 0;
    self->base.step = 0;
    self->base.stepArg = 0;
    func_001331B8(D_005CAE50, self->base.modelHandle, 0);
}

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

/* The ChkLine call reserves the first 0x30 bytes of the frame for outgoing
 * arguments, so the stack vector f sits at sp+0x30. Retail's sqc2 uses sp as
 * the base and 0x30 as the literal offset, which only builds from a base
 * pointer that folds to sp itself. */
#define SP_BASE(f, ofs) ((char *)(f) - (ofs))

/* Let a held weapon fall: drop it at the holder's feet (snapped to the floor when the line check hits) and clear the state bytes. */
__attribute__((section(".text.cOmWeapon_setFall")))
void cOmWeapon_setFall(cOmWeapon *self) {
    float f[16] __attribute__((aligned(16)));
    cOmBase *body;
    cOmBase *body2;
    cVec *d;
    int n, n2;
    float y2;
    unsigned char ok, ok2;

    if (self->parent != 0) {
        VU0_SQC2_VF0(SP_BASE(f, 0x30), 0x30);
        ok = ((*(int *)&f[4] = n = self->base.childNum), (n != 0));
        if (ok) body = self->base.children[0]; else body = 0;
        d = &self->base.posA;
        cVec_copy3(d, self->parent->pos);
        cVec_copy3((cVec *)f, self->parent->pos);
        if (body != 0) f[1] = body->pos->y; else f[1] = self->base.pos->y;
        f[1] = f[1] + 0.1f;
        VU0_SQC2_VF0(SP_BASE(f, 0x30), 0x50);
        VU0_SQC2_VF0(SP_BASE(f, 0x30), 0x60);
        cVec_copy3((cVec *)(f + 8), (cVec *)f);
        f[9] = f[9] + 0.5f;
        if (ChkLine(f + 8, f, f + 12, 0, 7, 0x534, 0, 0, 0, 0, 0, 0, 1)) {
            y2 = f[13] + 0.1f;
            if (f[1] < y2) {
                f[1] = y2;
            }
        }
        cVec_copy3(&self->base.posA, (cVec *)f);
        cVec_copy3(self->base.pos, (cVec *)f);
    }
    self->base.animRate = 1.0f;
    self->base.objFlags = self->base.objFlags & 0xFFFFFFEF;
    self->fallSpeed = 0.065f;
    self->parent = 0;
    ok2 = ((*(int *)&f[0] = n2 = self->base.childNum), (n2 != 0));
    if (ok2) body2 = self->base.children[0]; else body2 = 0;
    if (body2 != 0) {
        body2->owner = &self->base;
        body2->posPrev.x = 0.0f;
        body2->posPrev.y = 0.0f;
        body2->posPrev.z = 0.0f;
        cModel_calcParts(self);
        self->base.mode = 0;
        self->base.phase = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}

/* Drop a held weapon at its holder's position (y taken from the child body) and put it in state 4. */
__attribute__((section(".text.cOmWeapon_dropToGround")))
void cOmWeapon_dropToGround(cOmWeapon *self) {
    float f[8] __attribute__((aligned(16)));
    cOmBase *body;
    cOmBase *body2;
    int n2;
    unsigned char ok2;
    cVec *d;
    int n;
    unsigned char ok;

    if (self->parent != 0) {
        VU0_SQC2_VF0(f, 0);
        ok = ((*(int *)&f[4] = n = self->base.childNum), (n != 0));
        if (ok) body = self->base.children[0]; else body = 0;
        d = &self->base.posA;
        cVec_copy3(d, self->parent->pos);
        cVec_copy3((cVec *)f, self->parent->pos);
        if (body != 0) f[1] = body->pos->y; else f[1] = self->base.pos->y;
        cVec_copy3(&self->base.posA, (cVec *)f);
        cVec_copy3(self->base.pos, (cVec *)f);
    }
    self->base.animRate = 1.0f;
    self->base.objFlags = self->base.objFlags & 0xFFFFFFEF;
    self->fallSpeed = 0.065f;
    self->parent = 0;
    ok2 = ((*(int *)f = n2 = self->base.childNum), (n2 != 0));
    if (ok2) body2 = self->base.children[0]; else body2 = 0;
    if (body2 != 0) {
        body2->owner = &self->base;
        body2->posPrev.x = 0.0f;
        body2->posPrev.y = 0.0f;
        body2->posPrev.z = 0.0f;
        cModel_calcParts(self);
        self->base.step = 4;
        self->base.mode = 0;
        self->base.phase = 0;
        self->base.stepArg = 0;
    }
}

/* Kick a held weapon off its holder: drop it at the holder's position, give it a small sideways velocity rotated by the player's heading, and enter state 0x13. */
__attribute__((section(".text.cOmWeapon_kickOff")))
void cOmWeapon_kickOff(cOmWeapon *self) {
    float f[24] __attribute__((aligned(16)));
    float *mtx;
    cOmBase *body;
    cOmBase *body2;
    int n2;
    unsigned char ok2;
    cVec *d;
    int n;
    unsigned char ok;

    if (self->parent != 0) {
        VU0_SQC2_VF0(f, 0);
        ok = ((*(int *)&f[4] = n = self->base.childNum), (n != 0));
        if (ok) body = self->base.children[0]; else body = 0;
        d = &self->base.posA;
        cVec_copy3(d, self->parent->pos);
        cVec_copy3((cVec *)f, self->parent->pos);
        if (body != 0) f[1] = body->pos->y; else f[1] = self->base.pos->y;
        cVec_copy3(&self->base.posA, (cVec *)f);
        cVec_copy3(self->base.pos, (cVec *)f);
    }
    self->base.animRate = 1.0f;
    self->base.objFlags = self->base.objFlags & 0xFFFFFFEF;
    self->fallSpeed = 0.065f;
    self->parent = 0;
    mtx = &f[8];
    MtxInitRotY(mtx, *(float *)(Getplayer() + 0x104));
    self->vel.x = 0.1f;
    self->vel.y = 0.05f;
    self->vel.z = -0.1f;
    sceVu0ApplyMatrix(&self->vel, mtx, &self->vel);
    ok2 = ((*(int *)f = n2 = self->base.childNum), (n2 != 0));
    if (ok2) body2 = self->base.children[0]; else body2 = 0;
    if (body2 != 0) {
        body2->owner = &self->base;
        body2->posPrev.x = 0.0f;
        body2->posPrev.y = 0.0f;
        body2->posPrev.z = 0.0f;
        cModel_calcParts(self);
        self->base.phase = 0x13;
        self->base.mode = 0;
        self->base.step = 0;
        self->base.stepArg = 0;
    }
}
