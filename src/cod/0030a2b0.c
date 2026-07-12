#include "godhand/vu0.h"

/* sceVu0ApplyMatrix — VU0 full 4x4 matrix x 4-vector: *a0 = (mat a1) * (vec a2),
 * accumulating all four rows (vmulax/vmadday/vmaddaz/vmaddw). */

__attribute__((section(".text.sceVu0ApplyMatrix")))
void sceVu0ApplyMatrix(void *a0, void *a1, void *a2) {
    VU0_LQC2(4, a1, 0);
    VU0_LQC2(5, a1, 0x10);
    VU0_LQC2(6, a1, 0x20);
    VU0_LQC2(7, a1, 0x30);
    VU0_LQC2(8, a2, 0);
    VU0_VMULAX_XYZW(4, 8);
    VU0_VMADDAY_XYZW(5, 8);
    VU0_VMADDAZ_XYZW(6, 8);
    VU0_VMADDW_XYZW(9, 7, 8);
    VU0_SQC2(9, a0, 0);
}
