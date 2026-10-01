/* sn-2.95.3-136 matched TU. */

#include "godhand/cHeatSys.h"
#include "godhand/cArea.h"
#include "godhand/vu0.h"
#include "godhand/cObjSimple.h"

extern cHeatSys D_005CB000;
extern void cHeatSys_UpdateHeatMax(cHeatSys *self, float range);
extern void cHeatSys_SetHeatGage(cHeatSys *self, float gage);
extern void func_002A9C90(cHeatSys *self, float range);
extern int func_001573C8(float *pt, cAreaVec4 *a, cAreaVec4 *b, cAreaVec4 *c, cAreaVec4 *d);
extern void cModel_ScrollTexture(cObjSimple *self, float dt);
extern void func_002B6FE8(cObjSimple *self);
extern void cModel_calcParts(cObjSimple *self);
extern void cObjBase_KageDraw(cObjSimple *self);
extern void EmClothMove(int cloth, cObjSimple *self, void *data, void *anchor);
extern void func_002B6A40(cObjSimple *self);
extern void func_002B79E0(cObjSimple *self);
extern void func_002B6DA0(cObjSimple *self);

/* Clear the gauge, then size it for the player and set the lv 1 threshold. */
__attribute__((section(".text.cHeatSys_Initialize")))
void cHeatSys_Initialize(cHeatSys *self)
{
    float range = HEATSYS_THRESHOLD_INIT;
    self->max = 0.0f;
    self->cur = 0.0f;
    self->threshold = 0.0f;
    self->floor = 0.0f;
    self->lv = 0;
    cHeatSys_UpdateHeatMax(&D_005CB000, range);
    cHeatSys_SetHeatGage(&D_005CB000, 0.0f);
    func_002A9C90(&D_005CB000, range);
}

/* Is point `pt` inside the quad area: inside the height band, then inside the four corners. */
__attribute__((section(".text.cArea_HitCheckQuad")))
int cArea_HitCheckQuad(cArea *self, float *pt)
{
    cAreaVec4 q[4] __attribute__((aligned(16)));
    float top;
    VU0_SQC2_VF0(q, 0x0);
    VU0_SQC2_VF0(q, 0x10);
    VU0_SQC2_VF0(q, 0x20);
    VU0_SQC2_VF0(q, 0x30);
    top = self->y + self->height;
    if (pt[1] < self->y) return 0;
    if (top < pt[1]) return 0;
    q[0].x = self->corner[0].x;
    q[0].y = 0.0f;
    q[0].z = self->corner[0].z;
    q[1].x = self->corner[1].x;
    q[1].y = 0.0f;
    q[1].z = self->corner[1].z;
    q[2].x = self->corner[2].x;
    q[2].y = 0.0f;
    q[2].z = self->corner[2].z;
    q[3].x = self->corner[3].x;
    q[3].y = 0.0f;
    q[3].z = self->corner[3].z;
    return func_001573C8(pt, &q[0], &q[1], &q[2], &q[3]) != 0;
}

static __inline__ void cObjSimpleVec3_Copy(cObjSimpleVec3 *d, cObjSimpleVec3 *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

/* Per-frame update: scroll the texture, step the model, then the pendulum, bust and ring physics. */
__attribute__((section(".text.cObjSimple_Update")))
void cObjSimple_Update(cObjSimple *self)
{
    int state = self->state;
    if (state >= 0) { if (state >= 4) { if (state == COBJSIMPLE_STATE_ACTIVE) {
        cObjSimpleVtEnt *vt = self->vtbl;
        vt[11].pfn((char *)self + vt[11].delta);
    }}}
    cModel_ScrollTexture(self, 1.0f);
    if (self->parentOn)
        func_002B6FE8(self);
    cModel_calcParts(self);
    if (self->kageObj)
        cObjBase_KageDraw(self);
    if (self->pendulumOn)
        EmClothMove(self->pendulumId, self, self->pendulumData, self->clothAnchor);
    if (self->bustFlag)
        func_002B6A40(self);
    if (self->ringFlag)
        func_002B79E0(self);
    if (self->oneBodyFlag)
        func_002B6DA0(self);
    cObjSimpleVec3_Copy(&self->pos, self->parentPos);
}
