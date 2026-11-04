#include "godhand/vu0.h"
#include "godhand/capVu0.h"

/* capVu0ApplyMatrixXYZ — VU0 3x3 matrix x vector via the COP2 accumulator:
 * *dst = mtx * *v, with the vector's x/y/z broadcast across the three matrix
 * rows (vmulax / vmadday / vmaddz). */

__attribute__((section(".text.capVu0ApplyMatrixXYZ")))
void capVu0ApplyMatrixXYZ(cVec *dst, float *mtx, cVec *v) {
    VU0_LQC2(4, v, 0);
    VU0_LQC2(5, mtx, 0);
    VU0_LQC2(6, mtx, 0x10);
    VU0_LQC2(7, mtx, 0x20);
    VU0_VMULAX_XYZW(5, 4);
    VU0_VMADDAY_XYZW(6, 4);
    VU0_VMADDZ_XYZW(8, 7, 4);
    VU0_SQC2(8, dst, 0);
}
