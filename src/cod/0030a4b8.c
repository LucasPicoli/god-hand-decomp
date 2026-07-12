#include "godhand/vu0.h"

/* sceVu0SubVector — VU0 vector vsub.xyzw: *a0 = *a1 (op) *a2. */

__attribute__((section(".text.sceVu0SubVector")))
void sceVu0SubVector(void *a0, void *a1, void *a2) {
    VU0_LQC2(4, a1, 0);
    VU0_LQC2(5, a2, 0);
    VU0_VSUB_XYZW(6, 4, 5);
    VU0_SQC2(6, a0, 0);
}
