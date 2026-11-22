#include "godhand/vu0.h"

/* katVu0ViewVolumeClip — VU0 4x4 matrix * vector with W-clip: loads the matrix
 * (a1, rows at 0x0/0x10/0x20/0x30) and the vector (a2), transforms via the
 * mulax/madday/maddaz/maddw accumulator chain, runs vclipw, stores the result
 * to a0, and returns the clip flags read from $vi18. */

__attribute__((section(".text.katVu0ViewVolumeClip")))
int katVu0ViewVolumeClip(void *a0, void *a1, void *a2) {
    int r;
    VU0_LQC2(4, a1, 0);
    VU0_LQC2(5, a1, 0x10);
    VU0_LQC2(6, a1, 0x20);
    VU0_LQC2(7, a1, 0x30);
    VU0_LQC2(8, a2, 0);
    VU0_VMULAX_XYZW(4, 8);
    VU0_VMADDAY_XYZW(5, 8);
    VU0_VMADDAZ_XYZW(6, 8);
    VU0_VMADDW_XYZW(12, 7, 0);
    VU0_VCLIPW_XYZ_VF12();
    VU0_VNOP();
    VU0_VNOP();
    VU0_VNOP();
    VU0_SQC2(12, a0, 0);
    VU0_VNOP();
    VU0_CFC2_NI(r, 18);
    return r;
}
