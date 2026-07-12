#include "godhand/vu0.h"

/* sceVu0Normalize — VU0 vector normalize: *a0 = *a1 / |*a1| (xyz).
 * length via the Q-pipe sqrt, then reciprocal-multiply.  ee-as encodes
 * `vsqrt Q, $vf5x` differently from retail, so it is emitted as a raw .word. */

__attribute__((section(".text.sceVu0Normalize")))
void sceVu0Normalize(void *a0, void *a1) {
    VU0_LQC2(4, a1, 0);
    VU0_VMUL_XYZ(5, 4, 4);
    VU0_VADDY_X(5, 5);
    VU0_VADDZ_X(5, 5, 5);
    VU0_VSQRT_Q_VF5X();
    VU0_VWAITQ();
    VU0_VADDQ_X(5, 0);
    VU0_VNOP();
    VU0_VNOP();
    VU0_VDIV_W_X(0, 5);
    VU0_VSUB_XYZW(6, 0, 0);
    VU0_VWAITQ();
    VU0_VMULQ_XYZ(6, 4);
    VU0_SQC2(6, a0, 0);
}
