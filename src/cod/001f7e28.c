/* cygnus-2.96 matched TU. */

#include "godhand/vu0.h"

/* capVu0LengthSq — squared length of the xyz vector at a0:
 * returns v.x*v.x + v.y*v.y + v.z*v.z (computed on VU0, returned via the
 * COP2->GPR->FPU move chain). */

__attribute__((section(".text.capVu0LengthSq")))
float capVu0LengthSq(void *a0) {
    float r;
    int t;
    VU0_LQC2(4, a0, 0);
    VU0_VMUL_XYZ(4, 4, 4);
    VU0_VADDY_X(4, 4);
    VU0_VADDZ_X(4, 4, 4);
    VU0_QMFC2_NI(t, 4);
    VU0_MTC1(r, t);
    return r;
}
