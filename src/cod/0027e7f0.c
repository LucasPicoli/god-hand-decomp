/* sn-2.95.3-136 matched TU. */

/* Hand the enemy over to `target`'s side: clear its target link and the held flag, make its first child belong to it, and
 * when `target` is given put the enemy at a fixed offset in the target's frame and copy the target's rotation. Then go to
 * mode 0 phase 1. */
#include "godhand/cEm00.h"
#include "godhand/vu0.h"

#define EM_F250_NOT_HELD   0xFFFFFFEFU  /* objFlags mask that drops the held bit (0x10); written out, ~0x10 gives a shorter li */
#define EM_HOLD_X          0.1973f      /* offset from the target, x */
#define EM_HOLD_Z          (-1.6929f)   /* offset from the target, z */

extern void MtxInitRotY(float *mtx, float angle);
extern void CopyVec3ToField30_147C40(float *mtx, cVec *v);
extern void sceVu0ApplyMatrix(void *dst, void *mtx, void *v);
extern void cModel_calcParts(void *model);

__attribute__((section(".text.cEm00_attachToTarget")))
void cEm00_attachToTarget(cEm00 *self, cEm00 *target) {
    unsigned char f[0x80] __attribute__((aligned(16)));
    float *rot;
    float *work;
    cVec *pos;
    cOmBase *child;
    int count;

    self->animRate = 1.0f;
    self->objFlags = self->objFlags & EM_F250_NOT_HELD;
    self->target = 0;
    child = cOmBase_childAt((cOmBase *)self, (int *)f, 0);
    if (child == 0) {
        return;
    }
    child->owner = (cOmBase *)self;
    if (target != 0) {
        VU0_SQC2_VF0(f, 0x50);
        rot = (float *)(f + 0x10);
        MtxInitRotY(rot, target->rot.y);
        CopyVec3ToField30_147C40(rot, target->pos);
        *(float *)(f + 0x50) = EM_HOLD_X;
        *(float *)(f + 0x58) = EM_HOLD_Z;
        *(float *)(f + 0x54) = 0.0f;
        work = (float *)(f + 0x70);
        VU0_LQC2(4, (char *)f + 0x50, 0);
        VU0_SQC2(4, f, 0x70);
        sceVu0ApplyMatrix(work, rot, work);
        VU0_LQC2(4, work, 0);
        VU0_SQC2(4, f, 0x60);
        pos = self->pos;
        if (pos != (cVec *)(f + 0x60)) {
            pos->x = *(float *)(f + 0x60);
            pos->y = *(float *)(f + 0x64);
            pos->z = *(float *)(f + 0x68);
        }
        cVec_copy3(&self->rot, &target->rot);
        cModel_calcParts(self);
    }
    self->stepArg = 0;
    self->mode = 0;
    self->step = 0;
    self->phase = 1;
}
