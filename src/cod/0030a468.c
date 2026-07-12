#include "godhand/vu0.h"

/* sceVu0DivVector — VU0 vector / scalar (reciprocal via Q-pipe): *a0 = *a1 / s. */

__attribute__((section(".text.sceVu0DivVector")))
void sceVu0DivVector(void *a0, void *a1, float s) {
    VU0_LQC2(4, a1, 0);
    VU0_LOAD_SCALAR(5, s);
    VU0_VDIV_W_X(0, 5);
    VU0_VWAITQ();
    VU0_VMULQ_XYZW(4, 4);
    VU0_SQC2(4, a0, 0);
}
