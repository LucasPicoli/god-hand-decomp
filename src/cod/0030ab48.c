#include "godhand/vu0.h"

/* sceVu0RotTransPers — VU0 4x4 matrix * vector with perspective divide, converting
 * the result to fixed-point.  Transforms the vector (a2) by the matrix (a1),
 * divides x/y/z by w (Q-pipe), converts to int with vftoi4, and — when a3 is
 * set — also converts z/w via vftoi0, storing the packed result to a0. */

__attribute__((section(".text.sceVu0RotTransPers")))
void sceVu0RotTransPers(void *a0, void *a1, void *a2, int a3) {
    VU0_LQC2(4, a1, 0);
    VU0_LQC2(5, a1, 0x10);
    VU0_LQC2(6, a1, 0x20);
    VU0_LQC2(7, a1, 0x30);
    VU0_LQC2(8, a2, 0);
    VU0_VMULAX_XYZW(4, 8);
    VU0_VMADDAY_XYZW(5, 8);
    VU0_VMADDAZ_XYZW(6, 8);
    VU0_VMADDW_XYZW(9, 7, 8);
    VU0_VDIV_W_W(0, 9);
    VU0_VWAITQ();
    VU0_VMULQ_XYZ(9, 9);
    VU0_VFTOI4_XYZW(10, 9);
    if (a3)
        VU0_VFTOI0_ZW(10, 9);
    VU0_SQC2(10, a0, 0);
}
