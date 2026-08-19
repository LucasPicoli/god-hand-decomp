/* sn-2.95.3-136 matched TU. */

extern float capVu0Length(void *a0);
extern float capVu0LengthSq(void *a0);
extern float Tramp_001F7DF8_00101E28(void *a0);
extern void func_001565A0(void *a0, void *a1, void *a2, void *a3);
extern float sqrtf(float x);

/* sn-2.95.3-136 matched TU. */







#include "godhand/vu0.h"

__attribute__((section(".text.LengthPositionToGivenLine")))
float LengthPositionToGivenLine(void *a0, void *a1, void *a2, int *a3) {
    char buf[0x30] __attribute__((aligned(16)));
    float d1;
    float d2;
    float mx;
    float r;
    float len;
    float dp;
    char *p3;

    VU0_SQC2_VF0(buf, 0x10);
    VU0_LQC2(4, a1, 0x0);
    VU0_LQC2(5, a0, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x10);
    VU0_LQC2(4, buf + 0x10, 0x0);
    VU0_SQC2(4, buf, 0x0);
    d1 = capVu0Length(buf);

    VU0_SQC2_VF0(buf, 0x10);
    VU0_LQC2(4, a2, 0x0);
    VU0_LQC2(5, a0, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x10);
    VU0_LQC2(4, buf + 0x10, 0x0);
    VU0_SQC2(4, buf, 0x0);
    d2 = capVu0Length(buf);

    p3 = buf + 0x10;
    if (d1 < d2) {
        mx = d1;
    } else {
        mx = d2;
    }

    {
        VU0_SQC2_VF0(buf, 0x10);
        VU0_LQC2(4, a2, 0x0);
        VU0_LQC2(5, a1, 0x0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, p3, 0x0);
        VU0_SQC2(4, buf, 0x0);
    }
    r = __builtin_sqrtf(capVu0LengthSq(buf) + mx * mx);

    func_001565A0(buf, a1, a2, a0);

    VU0_SQC2_VF0(buf, 0x20);
    len = Tramp_001F7DF8_00101E28(buf);
    if (len > 0.0f) {
        float inv = 1.0f / len;

        *(float *)(buf + 0x2C) = *(float *)(buf + 0xC);
        *(float *)(buf + 0x20) = *(float *)(buf + 0x0) * inv;
        *(float *)(buf + 0x24) = *(float *)(buf + 0x4) * inv;
        *(float *)(buf + 0x28) = *(float *)(buf + 0x8) * inv;
    }
    VU0_LQC2(4, buf + 0x20, 0x0);
    VU0_SQC2(4, buf, 0x10);
    {
        float *d = (float *)(buf + 0x0);
        float *s = (float *)(buf + 0x10);

        if (d != s) {
            float x = *(float *)(buf + 0x10);
            float y = *(float *)(buf + 0x14);
            float z = *(float *)(buf + 0x18);

            *(float *)(buf + 0x0) = x;
            *(float *)(buf + 0x4) = y;
            *(float *)(buf + 0x8) = z;
        }
    }

    VU0_SQC2_VF0(buf, 0x20);
    VU0_LQC2(4, a1, 0x0);
    VU0_LQC2(5, a0, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x20);
    VU0_LQC2(4, buf + 0x20, 0x0);
    VU0_SQC2(4, buf, 0x10);

    dp = *(float *)(buf + 0x0) * *(float *)(buf + 0x10)
       + *(float *)(buf + 0x4) * *(float *)(buf + 0x14)
       + *(float *)(buf + 0x8) * *(float *)(buf + 0x18);

    if (r <= d1 || r <= d2) {
        if (a3 != 0) {
            int t = 1;

            if (d1 < d2) {
                t = 0;
            }
            *a3 = t;
        }
        return mx;
    }
    if (a3 != 0) {
        *a3 = 2;
    }
    return dp;
}
