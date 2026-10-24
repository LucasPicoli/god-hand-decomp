/* sn-2.95.3-136 */
#include "godhand/cCamera.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

#define SYS_FLAG_CAM_LOCK  0x800000     /* leave the camera where it is */

extern unsigned int D_00747A78;
extern void func_001F8080(cVec *out, float angle);
extern cVec *cCamera__calcRotation(cVec *out, struct cCamera *self, cVec *a, cVec *b);

static __inline__ void vecSet(cVec *d, float x, float y, float z)
{
    d->x = x;
    d->y = y;
    d->z = z;
    d->w = 1.0f;
}

/* An object the camera follows: a position and an angle in radians. */
typedef struct CamNode {
    char unk00[0x30];
    float x, y, z;                      /* 0x030 */
    char unk3C[0xC8];
    float angle;                        /* 0x104 */
} CamNode;

/* The view the follow camera works in. */
typedef struct CamView {
    char unk00[0x80];
    float mtx[4][4];                    /* 0x080 */
} CamView;

/* A camera placed from two followed objects. */
typedef struct cFollowCamera {
    struct cCamera base;                /* 0x000 */
    CamView *view;                      /* 0x360 */
    CamNode *tgtSrc;                    /* 0x364 */
    CamNode *eyeSrc;                    /* 0x368 */
} cFollowCamera;

/* Place the camera: target and eye from the two objects through the view matrix, field of view from
 * the target object's angle, roll from the eye object's. */
__attribute__((section(".text.func_001399A0")))
void func_001399A0(cFollowCamera *self)
{
    struct {
        cVec tgt;                       /* 0x00 */
        cVec eye;                       /* 0x10 */
        cVec out;                       /* 0x20 */
        cVec tmp;                       /* 0x30 */
    } f;
    CamNode *a;
    CamNode *b;
    cVec *eye;
    cVec *tmp;
    float (*m)[4];

    if (D_00747A78 & SYS_FLAG_CAM_LOCK) {
        return;
    }
    a = self->tgtSrc;
    if (a == 0) {
        return;
    }
    b = self->eyeSrc;
    if (b == 0) {
        return;
    }
    eye = &f.eye;
    tmp = &f.tmp;
    m = self->view->mtx;
    vecSet(&f.tgt, a->x, a->y, a->z);
    vecSet(&f.eye, b->x, b->y, b->z);
    VU0_LQC2(4, &f, 0x00);
    VU0_SQC2(4, &f, 0x30);
    sceVu0ApplyMatrix(tmp, m, tmp);
    VU0_LQC2(4, tmp, 0);
    VU0_SQC2(4, &f, 0x20);
    cVec_copy3(&self->base.target, &f.out);
    VU0_LQC2(4, eye, 0);
    VU0_SQC2(4, &f, 0x30);
    sceVu0ApplyMatrix(tmp, m, tmp);
    VU0_LQC2(4, tmp, 0);
    VU0_SQC2(4, &f, 0x20);
    cVec_copy3(&self->base.eye, &f.out);
    self->base.fov = self->tgtSrc->angle * 57.295776f;
    func_001F8080(&self->base.up, Adjust_theta(-self->eyeSrc->angle));
    sceVu0ApplyMatrix(&self->base.up, m, &self->base.up);
    cCamera__calcRotation(&f.out, &self->base, &self->base.target, &self->base.eye);
    cVec_copy3(&self->base.rot, &f.out);
}
