/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */

extern void ForwardVec3At30_147C60(void *dst, void *src);
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern float Tramp_001F7DF8_00101E28(void *a0);
extern void func_002BC0F8(void *a0, void *a1, float r0, float len0, void *b0, void *b1, float r1, float len1);

#include "godhand/vu0.h"

/* Builds two capsules from two matrices, both pulled in by their radius, and
 * tests them against each other. Capsule 0 runs from mtx's origin along its
 * local y axis for len0, its start moved in by r0 along the axis, so its core is
 * len0 - 2 * r0 long; capsule 1 is built the same way from mtx2, r1 and len1.
 * f holds a0 (0x00), a1 (0x10), b0 (0x20), b1 (0x30), the axis (0x40), a
 * scratch vector (0x50) and the unit direction (0x60). The core length gets its
 * own local: updating len0 in place swaps the f21/f22 picks of r1 and len0. */
__attribute__((section(".text.HitCheck_capsulePairFromMtxInset")))
void HitCheck_capsulePairFromMtxInset(void *mtx, void *mtx2, float r0, float len0, float r1, float len1)
{
    float core0;
    char f[0x70] __attribute__((aligned(16)));
    float *axis;
    float *a1v;
    float *dir;
    float *b0;
    float *b1;
    float len;

    VU0_SQC2_VF0(f, 0x0);
    VU0_SQC2_VF0(f, 0x10);
    VU0_SQC2_VF0(f, 0x20);
    VU0_SQC2_VF0(f, 0x30);
    axis = (float *)(f + 0x40);
    a1v = (float *)(f + 0x10);
    VU0_SQC2_VF0(f, 0x40);
    ForwardVec3At30_147C60(f, mtx);
    dir = (float *)(f + 0x60);
    *(float *)(f + 0x14) = len0;
    VU0_LQC2(4, a1v, 0);
    VU0_SQC2(4, axis, 0x20);
    sceVu0ApplyMatrix(dir, mtx, dir);
    VU0_LQC2(4, dir, 0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x10) = *(float *)(f + 0x50);
    *(float *)(f + 0x14) = *(float *)(f + 0x54);
    *(float *)(f + 0x18) = *(float *)(f + 0x58);
    VU0_SQC2_VF0(f, 0x60);
    VU0_LQC2(4, a1v, 0);
    VU0_LQC2(5, f, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, axis, 0x20);
    VU0_LQC2(4, dir, 0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x40) = *(float *)(f + 0x50);
    *(float *)(f + 0x44) = *(float *)(f + 0x54);
    *(float *)(f + 0x48) = *(float *)(f + 0x58);
    VU0_SQC2_VF0(f, 0x60);
    len = Tramp_001F7DF8_00101E28(axis);
    if (len > 0.0f) {
        float inv = 1.0f / len;
        *(float *)(f + 0x60) = *(float *)(f + 0x40) * inv;
        *(float *)(f + 0x64) = axis[1] * inv;
        *(float *)(f + 0x68) = axis[2] * inv;
        *(float *)(f + 0x6C) = axis[3];
    }
    VU0_LQC2(4, dir, 0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x40) = *(float *)(f + 0x50);
    *(float *)(f + 0x44) = *(float *)(f + 0x54);
    *(float *)(f + 0x48) = *(float *)(f + 0x58);
    VU0_LQC2(4, f, 0x40);
    VU0_LOAD_SCALAR(5, r0);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x40);
    VU0_LQC2(4, f, 0);
    VU0_LQC2(5, axis, 0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0);
    VU0_LQC2(4, f, 0x10);
    VU0_LQC2(5, axis, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x10);
    core0 = len0 - (r0 + r0);
    b0 = (float *)(f + 0x20);
    b1 = (float *)(f + 0x30);
    VU0_SQC2_VF0(f, 0x40);
    ForwardVec3At30_147C60(b0, mtx2);
    *(float *)(f + 0x34) = len1;
    VU0_LQC2(4, b1, 0);
    VU0_SQC2(4, axis, 0x20);
    sceVu0ApplyMatrix(dir, mtx2, dir);
    VU0_LQC2(4, dir, 0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x30) = *(float *)(f + 0x50);
    *(float *)(f + 0x34) = *(float *)(f + 0x54);
    *(float *)(f + 0x38) = *(float *)(f + 0x58);
    VU0_SQC2_VF0(f, 0x60);
    VU0_LQC2(4, b1, 0);
    VU0_LQC2(5, b0, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, axis, 0x20);
    VU0_LQC2(4, dir, 0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x40) = *(float *)(f + 0x50);
    *(float *)(f + 0x44) = *(float *)(f + 0x54);
    *(float *)(f + 0x48) = *(float *)(f + 0x58);
    VU0_SQC2_VF0(f, 0x60);
    len = Tramp_001F7DF8_00101E28(axis);
    if (len > 0.0f) {
        float inv = 1.0f / len;
        *(float *)(f + 0x60) = *(float *)(f + 0x40) * inv;
        *(float *)(f + 0x64) = axis[1] * inv;
        *(float *)(f + 0x68) = axis[2] * inv;
        *(float *)(f + 0x6C) = axis[3];
    }
    VU0_LQC2(4, dir, 0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x40) = *(float *)(f + 0x50);
    *(float *)(f + 0x44) = *(float *)(f + 0x54);
    *(float *)(f + 0x48) = *(float *)(f + 0x58);
    VU0_LQC2(4, f, 0x40);
    VU0_LOAD_SCALAR(5, r1);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x40);
    VU0_LQC2(4, f, 0x20);
    VU0_LQC2(5, axis, 0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x20);
    VU0_LQC2(4, f, 0x30);
    VU0_LQC2(5, axis, 0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x30);
    func_002BC0F8(f, a1v, r0, core0, b0, b1, r1, len1 - (r1 + r1));
}
