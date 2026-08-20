/* sn-2.95.3-136 matched TU. */

extern float Tramp_001F7DF8_00101E28(void *a0);
extern void func_001569A0(void *a0, void *a1, void *a2, void *a3);

/* sn-2.95.3-136 matched TU. */




#include "godhand/vu0.h"

__attribute__((section(".text.func_00156AC0")))
float func_00156AC0(void *a0, void *a1, void *a2) {
    char buf[0x30] __attribute__((aligned(16)));
    float len;
    float dp;
    float *s;

    func_001569A0(buf, a0, a1, a2);
    s = (float *)(buf + 0x10);
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
    VU0_LQC2(4, a0, 0x0);
    VU0_LQC2(5, a2, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x20);
    VU0_LQC2(4, buf + 0x20, 0x0);
    VU0_SQC2(4, buf, 0x10);

    dp = *(float *)(buf + 0x0) * *(float *)(buf + 0x10)
       + *(float *)(buf + 0x4) * *(float *)(buf + 0x14)
       + *(float *)(buf + 0x8) * *(float *)(buf + 0x18);
    return dp;
}
