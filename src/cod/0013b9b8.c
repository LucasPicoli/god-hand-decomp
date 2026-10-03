/* sn-2.95.3-136 matched TU. */

#include "godhand/cPlCamera.h"
#include "godhand/vu0.h"

extern int D_005CAFF0;                  /* the camera manager's live camera */
extern void MtxInitRotVec(float *mtx, float *rot, int roll);
extern void sceVu0ApplyMatrix(cVec *out, float *mtx, cVec *in);
extern void Adjust_theta_vec(cVec *v);

#define PLCAM_FOV_SET  31.0f
#define PLCAM_UPDATE_OFS 0x51C         /* cleared word; only a raw store matches (aliases D_005CAFF0) */

static __inline__ void plcam_vec(cVec *v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

/* Place the camera for the next update. With `snap` set the pose is copied
 * from the live camera; otherwise it is rebuilt from the anchor object: the
 * eye is the anchor's position plus the offset turned by its rotation, the
 * target lies `setDist` in front of the eye along the turned rotation, and
 * the up vector is reset to (0, 1, 0). */
__attribute__((section(".text.cPlCamera_setCamUpdate")))
void cPlCamera_setCamUpdate(struct cPlCamera *self, int snap) {
    struct {
        float mtx[16];                  /* 0x00 */
        cVec out;                       /* 0x40 */
        cVec place;                     /* 0x50 */
        cVec back;                      /* 0x60 */
        cVec rot;                       /* 0x70 */
        cVec up;                        /* 0x80 */
    } f;
    if (D_005CAFF0 == 0) return;
    *(int *)((char *)self + PLCAM_UPDATE_OFS) = 0;
    if (snap != 0) {
        cVec_copy3(&self->base.target, &((struct cCamera *)D_005CAFF0)->target);
        cVec_copy3(&self->base.eye, &((struct cCamera *)D_005CAFF0)->eye);
        self->base.fov = ((struct cCamera *)D_005CAFF0)->fov;
        return;
    }
    VU0_SQC2_VF0(&f, 0x40);
    MtxInitRotVec(f.mtx, self->pose.obj->rot, 0);
    f.mtx[12] = self->pose.obj->pos->x;
    f.mtx[13] = self->pose.obj->pos->y;
    f.mtx[14] = self->pose.obj->pos->z;
    sceVu0ApplyMatrix(&f.out, f.mtx, &self->pose.ofs);
    cVec_copy3(&self->base.eye, &f.out);
    VU0_SQC2_VF0(&f, 0x50);
    VU0_SQC2_VF0(&f, 0x60);
    plcam_vec(&f.rot, self->pose.obj->rot[0] + self->pose.rotOfs.x,
              self->pose.obj->rot[1] + self->pose.rotOfs.y, self->pose.obj->rot[2], 1.0f);
    Adjust_theta_vec(&f.rot);
    MtxInitRotVec(f.mtx, (float *)&f.rot, 0);
    f.mtx[12] = f.out.x;
    f.mtx[13] = f.out.y;
    f.mtx[14] = f.out.z;
    f.back.x = 0;
    f.back.y = 0;
    f.back.z = -self->pose.dist;
    sceVu0ApplyMatrix(&f.place, f.mtx, &f.back);
    cVec_copy3(&self->base.target, &f.place);
    plcam_vec(&f.up, 0, 1.0f, 0, 1.0f);
    cVec_copy3(&self->up, &f.up);
    self->base.fov = PLCAM_FOV_SET;
}
