#include "godhand/vu0.h"

/* sceVu0FTOI4Vector — VU0 float-to-fixed (4-bit) conversion: *a0 = ftoi4(*a1). */

__attribute__((section(".text.sceVu0FTOI4Vector")))
void sceVu0FTOI4Vector(void *a0, void *a1) {
    VU0_LQC2(4, a1, 0);
    VU0_VFTOI4_XYZW(5, 4);
    VU0_SQC2(5, a0, 0);
}
