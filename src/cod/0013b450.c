/* sn-2.95.3-136 matched TU. */

#include "godhand/cPlCamera.h"
#include "godhand/vu0.h"

extern void *Getplayer(void);
extern void MtxInitRotVec(float *mtx, float *rot, int roll);
extern void sceVu0ApplyMatrix(cVec *out, float *mtx, cVec *in);

#define PLCAM_EASE  0.25f

static __inline__ void plcam_vec(cVec *v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

/* Follow step that ends: turn the camera offset by the target's rotation,
 * move the camera eye a quarter of the way to it, place the target from the
 * rotation's third row, reset the up vector, and count the wait down; when
 * it is spent go back to follow mode 1. */
__attribute__((section(".text.cPlCamera_followEnd")))
void cPlCamera_followEnd(struct cPlCamera *self) {
    struct {
        float mtx[16];                  /* 0x00 */
        cVec out;                       /* 0x40 */
        cVec up;                        /* 0x50 */
    } f;
    float dx, dy, dz, ex, ey, ez;
    if (Getplayer() == 0) return;
    cVec_copy3(&self->goal, self->target->pos);
    VU0_SQC2_VF0(&f, 0x40);
    MtxInitRotVec(f.mtx, self->target->rot, 0);
    f.mtx[12] = self->target->pos->x;
    f.mtx[13] = self->target->pos->y;
    f.mtx[14] = self->target->pos->z;
    sceVu0ApplyMatrix(&f.out, f.mtx, &self->offset);
    dx = f.out.x - self->base.eye.x;
    dy = f.out.y - self->base.eye.y;
    dz = f.out.z - self->base.eye.z;
    self->base.eye.x = self->base.eye.x + dx * PLCAM_EASE;
    self->base.eye.y = self->base.eye.y + dy * PLCAM_EASE;
    self->base.eye.z = self->base.eye.z + dz * PLCAM_EASE;
    MtxInitRotVec(f.mtx, self->target->rot, 0);
    ex = f.mtx[8];
    ey = f.mtx[9];
    ez = f.mtx[10];
    self->base.target.x = ex + self->base.eye.x;
    self->base.target.y = ey + self->base.eye.y;
    self->base.target.z = ez + self->base.eye.z;
    plcam_vec(&f.up, 0, 1.0f, 0, 1.0f);
    cVec_copy3(&self->up, &f.up);
    if (self->wait != 0) {
        self->wait = self->wait - 1;
    } else {
        self->flags528 &= ~1;
        self->followMode = 1;
    }
}
