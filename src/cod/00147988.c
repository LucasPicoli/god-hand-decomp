#include "godhand/vu0.h"

/* MtxInitRotY — build an identity matrix in a0, then apply a Y-axis rotation by
 * `angle` (delegated to sceVu0RotMatrixY).  sn-2.95.3-136. */

extern void sceVu0RotMatrixY(void *, void *, float);

__attribute__((section(".text.MtxInitRotY")))
void MtxInitRotY(void *a0, float angle) {
    VU0_VMOVE_XYZW(4, 0);
    VU0_VMR32_XYZW(5, 4);
    VU0_VMR32_XYZW(6, 5);
    VU0_VMR32_XYZW(7, 6);
    VU0_SQC2(4, a0, 0x30);
    VU0_SQC2(5, a0, 0x20);
    VU0_SQC2(6, a0, 0x10);
    VU0_SQC2(7, a0, 0x0);
    sceVu0RotMatrixY(a0, a0, angle);
}
