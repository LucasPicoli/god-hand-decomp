/* sn-2.95.3-136 matched TU. */

extern void ForwardVec3At30_147C60(void *dst, void *src);
extern void sceVu0ApplyMatrix(void *v1, void *m0, void *v0);
extern float Tramp_001F7DF8_00101E28(void *a0);
extern float LengthPositionToGivenLine(void *a0, void *a1, void *a2, int *a3);

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"






__attribute__((section(".text.func_002BCD58")))
int func_002BCD58(void *arg, void *node, float k, float h)
{
    char buf[0x50] __attribute__((aligned(16)));
    char *s0 = (char *)arg;
    float *c;
    float *b;
    float *d;
    float len;

    VU0_SQC2_VF0(buf, 0x0);
    VU0_SQC2_VF0(buf, 0x10);
    c = (float *)(buf + 0x20);
    b = (float *)(buf + 0x10);
    VU0_SQC2_VF0(buf, 0x20);
    ForwardVec3At30_147C60(buf, s0);
    d = (float *)(buf + 0x40);
    *(float *)(buf + 0x14) = h;
    VU0_LQC2(4, b, 0x0);
    VU0_SQC2(4, c, 0x20);
    sceVu0ApplyMatrix(d, s0, d);
    VU0_LQC2(4, d, 0x0);
    VU0_SQC2(4, buf, 0x30);
    {
        float x = *(float *)(buf + 0x30);
        float y = *(float *)(buf + 0x34);
        float z = *(float *)(buf + 0x38);

        *(float *)(buf + 0x10) = x;
        *(float *)(buf + 0x14) = y;
        *(float *)(buf + 0x18) = z;
    }
    VU0_SQC2_VF0(buf, 0x40);
    VU0_LQC2(4, b, 0x0);
    VU0_LQC2(5, buf, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, c, 0x20);
    VU0_LQC2(4, d, 0x0);
    VU0_SQC2(4, buf, 0x30);
    {
        float x = *(float *)(buf + 0x30);
        float y = *(float *)(buf + 0x34);
        float z = *(float *)(buf + 0x38);

        *(float *)(buf + 0x20) = x;
        *(float *)(buf + 0x24) = y;
        *(float *)(buf + 0x28) = z;
    }
    VU0_SQC2_VF0(buf, 0x40);
    len = Tramp_001F7DF8_00101E28(c);
    if (len > 0.0f) {
        float inv = 1.0f / len;

        *(float *)(buf + 0x40) = *(float *)(buf + 0x20) * inv;
        *(float *)(buf + 0x44) = c[1] * inv;
        *(float *)(buf + 0x48) = c[2] * inv;
        *(float *)(buf + 0x4C) = c[3];
    }
    VU0_LQC2(4, d, 0x0);
    VU0_SQC2(4, buf, 0x30);
    {
        float x = *(float *)(buf + 0x30);
        float y = *(float *)(buf + 0x34);
        float z = *(float *)(buf + 0x38);

        *(float *)(buf + 0x20) = x;
        *(float *)(buf + 0x24) = y;
        *(float *)(buf + 0x28) = z;
    }
    VU0_LQC2(4, buf, 0x20);
    VU0_LOAD_SCALAR(5, k);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x20);
    VU0_LQC2(4, buf, 0x0);
    VU0_LQC2(5, c, 0x0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x0);
    VU0_LQC2(4, buf, 0x10);
    VU0_LQC2(5, c, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x10);
    return LengthPositionToGivenLine(node, buf, b, 0) <= k;
}

#include "godhand/vu0.h"






__attribute__((section(".text.func_002BB488")))
int func_002BB488(void *a0, void *a1, float a2, float a3, float a4) {
    char buf[0x50] __attribute__((aligned(16)));
    char *p1;
    char *p2;
    char *p3;
    float len;
    float dist;

    VU0_SQC2_VF0(buf, 0x0);
    VU0_SQC2_VF0(buf, 0x10);
    p1 = buf + 0x20;
    p3 = buf + 0x10;
    VU0_SQC2_VF0(buf, 0x20);
    ForwardVec3At30_147C60(buf, a1);
    p2 = buf + 0x40;
    *(float *)(buf + 0x14) = a4;
    VU0_LQC2(4, p3, 0x0);
    VU0_SQC2(4, p1, 0x20);
    sceVu0ApplyMatrix(p2, a1, p2);
    VU0_LQC2(4, p2, 0x0);
    VU0_SQC2(4, buf, 0x30);
    {
        float x = *(float *)(buf + 0x30);
        float y = *(float *)(buf + 0x34);
        float z = *(float *)(buf + 0x38);

        *(float *)(buf + 0x10) = x;
        *(float *)(buf + 0x14) = y;
        *(float *)(buf + 0x18) = z;
    }
    VU0_SQC2_VF0(buf, 0x40);
    VU0_LQC2(4, p3, 0x0);
    VU0_LQC2(5, buf, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, p1, 0x20);
    VU0_LQC2(4, p2, 0x0);
    VU0_SQC2(4, buf, 0x30);
    {
        float x = *(float *)(buf + 0x30);
        float y = *(float *)(buf + 0x34);
        float z = *(float *)(buf + 0x38);

        *(float *)(buf + 0x20) = x;
        *(float *)(buf + 0x24) = y;
        *(float *)(buf + 0x28) = z;
    }
    VU0_SQC2_VF0(buf, 0x40);
    len = Tramp_001F7DF8_00101E28(p1);
    if (len > 0.0f) {
        float inv = 1.0f / len;

        *(float *)(buf + 0x40) = *(float *)(buf + 0x20) * inv;
        *(float *)(buf + 0x44) = *(float *)(p1 + 0x4) * inv;
        *(float *)(buf + 0x48) = *(float *)(p1 + 0x8) * inv;
        *(float *)(buf + 0x4C) = *(float *)(p1 + 0xC);
    }
    VU0_LQC2(4, p2, 0x0);
    VU0_SQC2(4, buf, 0x30);
    {
        float x = *(float *)(buf + 0x30);
        float y = *(float *)(buf + 0x34);
        float z = *(float *)(buf + 0x38);

        *(float *)(buf + 0x20) = x;
        *(float *)(buf + 0x24) = y;
        *(float *)(buf + 0x28) = z;
    }
    VU0_LQC2(4, buf, 0x20);
    VU0_LOAD_SCALAR(5, a3);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x20);
    VU0_LQC2(4, buf, 0x0);
    VU0_LQC2(5, p1, 0x0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x0);
    VU0_LQC2(4, buf, 0x10);
    VU0_LQC2(5, p1, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x10);
    dist = LengthPositionToGivenLine(a0, buf, p3, 0);
    return dist <= a2 + a3;
}
