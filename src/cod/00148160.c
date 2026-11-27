/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */
#include "godhand/fpu.h"

extern void func_00150710(void *dst, float x, float y, float z);

/* The scale of each axis of m: the length of its first three rows, set into dst. */
__attribute__((section(".text.MtxGetScaleVec")))
void MtxGetScaleVec(void *dst, float *m)
{
    float sx, sy, sz;

    FPU_SQRT_S(sx, m[0] * m[0] + m[1] * m[1] + m[2] * m[2]);
    FPU_SQRT_S(sy, m[4] * m[4] + m[5] * m[5] + m[6] * m[6]);
    FPU_SQRT_S(sz, m[8] * m[8] + m[9] * m[9] + m[10] * m[10]);
    func_00150710(dst, sx, sy, sz);
}
