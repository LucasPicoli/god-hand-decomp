#include "godhand/vu0.h"

/* sceVu0ScaleVector — VU0 scalar*vector (broadcast): *a0 = *a1 * s (xyzw). */

__attribute__((section(".text.sceVu0ScaleVector")))
void sceVu0ScaleVector(void *a0, void *a1, float s) {
    VU0_LQC2(4, a1, 0);
    VU0_LOAD_SCALAR(5, s);
    VU0_VMULX_XYZW(6, 4, 5);
    VU0_SQC2(6, a0, 0);
}
