/* sn-2.95.3-136 matched TU. */

extern float capVu0LengthSq(void *a0);
extern float Tramp_001F7DF8_00101E28(void *a0);
extern int func_001377E8(void *a0, void *a1, void *a2, float a3, void *a4);
extern float sqrtf(float x);

/* sn-2.95.3-136 matched TU. */






#include "godhand/vu0.h"

__attribute__((section(".text.func_002ADF50")))
void func_002ADF50(char *self, void *a1, float a2)
{
    char buf[0x30] __attribute__((aligned(16)));
    int i;
    char *p;
    float *s;
    float len;
    float t;

    if (*(int *)(self + 0xC) < 0x80) {
        p = *(char **)(self + 0x14);
        for (i = 0; i < *(int *)(self + 0x8); i++, p += 0x18) {
            if (*(unsigned char *)(p + 0x14) == 0) {
                continue;
            }
            if (*(int *)(self + 0xC) + 1 >= 0x80) {
                continue;
            }
            VU0_SQC2_VF0(buf, 0x0);
            if (func_001377E8(*(void **)(p + 0x0), *(void **)(p + 0x4), a1, a2,
                              buf) == 0) {
                continue;
            }
            VU0_LQC2(4, buf, 0x0);
            VU0_LQC2(5, a1, 0x0);
            VU0_VSUB_XYZ(4, 4, 5);
            VU0_SQC2(4, buf, 0x0);
            t = __builtin_sqrtf(capVu0LengthSq(buf));
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
            {
                float k = a2 - t;

                VU0_LQC2(4, buf, 0x0);
                VU0_SQC2(4, buf, 0x20);
                VU0_LQC2(4, buf, 0x20);
                VU0_LOAD_SCALAR(5, k);
                VU0_VMULX_XYZ(4, 4, 5);
                VU0_SQC2(4, buf, 0x20);
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
            *(int *)(self + ((*(int *)(self + 0xC)) << 5) + 0x20) =
                *(int *)(p + 0x0);
            {
                float *d = (float *)(((*(int *)(self + 0xC)) << 5)
                                     + (int)self);
                float *q = (float *)buf;

                d += 12;

                if (d != q) {
                    float t0 = q[0];
                    float t1 = q[1];
                    float t2;

                    d[0] = t0;
                    *(volatile float *)&d[1] = t1;
                    t2 = *(volatile float *)&q[2];
                    d[2] = t2;
                }
            }
            *(int *)(self + 0xC) = *(int *)(self + 0xC) + 1;
            *(int *)(self + ((*(int *)(self + 0xC)) << 5) + 0x20) =
                *(int *)(p + 0x4);
            {
                float *d = (float *)(((*(int *)(self + 0xC)) << 5)
                                     + (int)self);
                float *q = (float *)buf;

                d += 12;

                if (d != q) {
                    float t0 = q[0];
                    float t1 = q[1];
                    float t2;

                    d[0] = t0;
                    *(volatile float *)&d[1] = t1;
                    t2 = *(volatile float *)&q[2];
                    d[2] = t2;
                }
            }
            *(int *)(self + 0xC) = *(int *)(self + 0xC) + 1;
        }
    }
}
