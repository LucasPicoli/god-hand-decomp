#include "godhand/vu0.h"

/* sceVu0UnitMatrix — builds a 4x4 identity matrix at a0: makes [0,0,0,1] in $vf4
 * then rotates it across the four rows (vmr32). */

__attribute__((section(".text.sceVu0UnitMatrix")))
void sceVu0UnitMatrix(void *a0) {
    VU0_VSUB_XYZW(4, 0, 0);
    VU0_VADD_W(4, 4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, a0, 0x30);
    VU0_SQC2(5, a0, 0x20);
    VU0_SQC2(6, a0, 0x10);
    VU0_SQC2(7, a0, 0x0);
}
