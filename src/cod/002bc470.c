/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

#include "godhand/objField.h"
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern float Tramp_001F7DF8_00101E28(void *v);
extern void func_002BC0F8(void *a0, void *a1, float r0, float len0, void *b0, void *b1, float r1, float len1);

/* Build two capsules from two matrices and test them against each other.
 * Capsule 0 runs from mtx's origin along its local y axis for len0, with both
 * ends pulled in by r0, so its core is len0 - 2 * r0 long. Capsule 1 runs from
 * mtx2's origin along its y axis for len1. f holds a0 (0x00), a1 (0x10),
 * b0 (0x20), b1 (0x30), the axis (0x40), a scratch vector (0x50) and the unit
 * direction (0x60). */
__attribute__((section(".text.HitCheck_capsulePairFromMtx")))
void HitCheck_capsulePairFromMtx(void *mtx, void *mtx2, float r0, float len0, float r1, float len1)
{
    unsigned char f[0x70];
    float *a1;
    float *axis;
    float *dir;
    float *tmp;
    float *b0;
    float *b1;
    float len;
    float inv;

    VU0_SQC2_VF0(f, 0x0);
    VU0_SQC2_VF0(f, 0x10);
    VU0_SQC2_VF0(f, 0x20);
    VU0_SQC2_VF0(f, 0x30);
    axis = (float *)(f + 0x40);
    a1 = (float *)(f + 0x10);
    VU0_SQC2_VF0(f, 0x40);
    ForwardVec3At30_147C60(f, mtx);
    dir = (float *)(f + 0x60);
    *(float *)(f + 0x14) = len0;
    VU0_LQC2(4, a1, 0x0);
    VU0_SQC2(4, axis, 0x20);
    sceVu0ApplyMatrix(dir, mtx, dir);
    VU0_LQC2(4, dir, 0x0);
    VU0_SQC2(4, f, 0x50);
    tmp = (float *)(f + 0x50);
    *(float *)(f + 0x10) = *(float *)(f + 0x50);
    *(float *)(f + 0x14) = *(float *)(f + 0x54);
    *(float *)(f + 0x18) = *(float *)(f + 0x58);
    VU0_SQC2_VF0(f, 0x60);
    VU0_LQC2(4, a1, 0x0);
    VU0_LQC2(5, f, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, axis, 0x20);
    VU0_LQC2(4, dir, 0x0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x40) = *(float *)(f + 0x50);
    *(float *)(f + 0x44) = *(float *)(f + 0x54);
    *(float *)(f + 0x48) = *(float *)(f + 0x58);
    VU0_SQC2_VF0(f, 0x60);
    len = Tramp_001F7DF8_00101E28(axis);
    if (0.0f < len) {
        inv = 1.0f / len;
        *(float *)(f + 0x60) = *(float *)(f + 0x40) * inv;
        *(float *)(f + 0x64) = axis[1] * inv;
        *(float *)(f + 0x68) = axis[2] * inv;
        *(float *)(f + 0x6C) = axis[3];
    }
    VU0_LQC2(4, dir, 0x0);
    VU0_SQC2(4, f, 0x50);
    *(float *)(f + 0x40) = *(float *)(f + 0x50);
    *(float *)(f + 0x44) = *(float *)(f + 0x54);
    *(float *)(f + 0x48) = *(float *)(f + 0x58);
    VU0_LQC2(4, f, 0x40);
    VU0_LOAD_SCALAR(5, r0);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x40);
    VU0_VADD_XYZ_IP(f, 0x0, axis);
    VU0_LQC2(4, f, 0x10);
    VU0_LQC2(5, axis, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, f, 0x10);
    len0 = len0 - (r0 + r0);
    b0 = (float *)(f + 0x20);
    ForwardVec3At30_147C60(b0, mtx2);
    *(float *)(f + 0x34) = len1;
    b1 = (float *)(f + 0x30);
    VU0_LQC2(4, b1, 0x0);
    VU0_SQC2(4, f, 0x50);
    sceVu0ApplyMatrix(tmp, mtx2, tmp);
    VU0_LQC2(4, tmp, 0x0);
    VU0_SQC2(4, f, 0x40);
    *(float *)(f + 0x30) = *(float *)(f + 0x40);
    *(float *)(f + 0x34) = *(float *)(f + 0x44);
    *(float *)(f + 0x38) = *(float *)(f + 0x48);
    func_002BC0F8(f, f + 0x10, r0, len0, b0, b1, r1, len1);
}
