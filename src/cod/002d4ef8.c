/* sn-2.95.3-136 matched TU. */

#include "godhand/cSpline.h"
#include "godhand/vu0.h"

extern void sceVu0ScaleVectorXYZ(cVec *out, cVec *in, float s);
extern void sceVu0AddVector(cVec *out, cVec *a, cVec *b);

/* Evaluate the cubic at t into *out: ((c3 * t + c2) * t + c1) * t + c0, w = 1. */
__attribute__((section(".text.cSpline_getPoint")))
void cSpline_getPoint(cSpline *self, cVec *out, float t) {
    cVec tmp;
    VU0_SQC2_VF0(&tmp, 0);
    cVec_copy3(out, &self->coef[3]);
    sceVu0ScaleVectorXYZ(&tmp, out, t);
    sceVu0AddVector(out, &tmp, &self->coef[2]);
    sceVu0ScaleVectorXYZ(&tmp, out, t);
    sceVu0AddVector(out, &tmp, &self->coef[1]);
    sceVu0ScaleVectorXYZ(&tmp, out, t);
    sceVu0AddVector(out, &tmp, &self->coef[0]);
    out->w = 1.0f;
}
