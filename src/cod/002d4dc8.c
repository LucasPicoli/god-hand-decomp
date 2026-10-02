/* sn-2.95.3-136 matched TU. */

#include "godhand/cSpline.h"
#include "godhand/vu0.h"

extern void sceVu0ApplyMatrix(cVec *out, void *mtx, cVec *in);
extern char D_003C3560[];

/* Fit the cubic through four control points: for each coordinate, run the
 * four values through the basis matrix and store the result across the
 * four coefficient vectors. */
__attribute__((section(".text.cSpline_setBasePoint")))
void cSpline_setBasePoint(cSpline *self, cVec *p) {
    cVec v;
    VU0_SQC2_VF0(&v, 0);
    v.x = p[0].x; v.y = p[1].x; v.z = p[2].x; v.w = p[3].x;
    sceVu0ApplyMatrix(&v, D_003C3560, &v);
    self->coef[0].x = v.x; self->coef[1].x = v.y; self->coef[2].x = v.z; self->coef[3].x = v.w;
    v.x = p[0].y; v.y = p[1].y; v.z = p[2].y; v.w = p[3].y;
    sceVu0ApplyMatrix(&v, D_003C3560, &v);
    self->coef[0].y = v.x; self->coef[1].y = v.y; self->coef[2].y = v.z; self->coef[3].y = v.w;
    v.x = p[0].z; v.y = p[1].z; v.z = p[2].z; v.w = p[3].z;
    sceVu0ApplyMatrix(&v, D_003C3560, &v);
    self->coef[0].z = v.x; self->coef[1].z = v.y; self->coef[2].z = v.z; self->coef[3].z = v.w;
}
