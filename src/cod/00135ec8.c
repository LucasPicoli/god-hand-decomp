/* sn-2.95.3-136 matched TU. */

extern void sceVu0Normalize(void *a0, void *a1);
extern float sceVu0InnerProduct(void *a0, void *a1);
extern float func_00156AC0(void *a0, void *a1, void *a2);
extern float Tramp_001F7DF8_00101E28(void *a0);

#include "godhand/vu0.h"




__attribute__((section(".text.func_00135EC8")))
int func_00135EC8(void *a0, void *a1, void *a2, void *a3, void *a4) {
    char buf[0x50] __attribute__((aligned(16)));
    char *s3 = (char *)a0;
    char *s2 = (char *)a4;
    char *p;
    float t;
    float d;

    VU0_SQC2_VF0(buf, 0x10);
    VU0_LQC2(4, a1, 0x0);
    VU0_LQC2(5, s3, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x10);
    p = buf + 0x10;
    VU0_LQC2(4, p, 0x0);
    VU0_SQC2(4, buf, 0x0);
    VU0_SQC2_VF0(buf, 0x10);

    sceVu0Normalize(p, a2);
    t = sceVu0InnerProduct(p, a3);
    t = t - sceVu0InnerProduct(p, s3);
    d = sceVu0InnerProduct(p, buf);

    if (d != 0.0f) {
        t = t / d;
        if (t >= 0.0f) {
            if (t <= 1.0f) {
                if (s2 != 0) {
                    char *q = buf + 0x40;
                    char *r;

                    VU0_LQC2(4, buf, 0x0);
                    VU0_SQC2(4, buf, 0x40);
                    VU0_LQC2(4, buf, 0x40);
                    VU0_LOAD_SCALAR(5, t);
                    VU0_VMULX_XYZ(4, 4, 5);
                    VU0_SQC2(4, buf, 0x40);
                    VU0_LQC2(4, q, 0x0);
                    VU0_SQC2(4, buf, 0x30);
                    r = buf + 0x30;

                    VU0_LQC2(4, s3, 0x0);
                    VU0_SQC2(4, buf, 0x40);
                    VU0_LQC2(4, buf, 0x40);
                    VU0_LQC2(5, r, 0x0);
                    VU0_VADD_XYZ(4, 4, 5);
                    VU0_SQC2(4, buf, 0x40);
                    VU0_LQC2(4, q, 0x0);
                    VU0_SQC2(4, buf, 0x20);

                    if (s2 != buf + 0x20) {
                        *(float *)(s2 + 0x0) = *(float *)(buf + 0x20);
                        *(float *)(s2 + 0x4) = *(float *)(buf + 0x24);
                        *(float *)(s2 + 0x8) = *(float *)(buf + 0x28);
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

#include "godhand/vu0.h"




__attribute__((section(".text.func_00156BE8")))
void *func_00156BE8(void *a0, void *a1, void *a2, void *a3, void *a4) {
    char buf[0x40] __attribute__((aligned(16)));
    char *s2 = (char *)a3;
    char *p1;
    char *p2;
    char *p3;
    float k;
    float len;

    VU0_SQC2_VF0(buf, 0x0);
    k = func_00156AC0(a1, a2, s2);
    p1 = buf + 0x10;
    VU0_SQC2_VF0(buf, 0x20);
    VU0_LQC2(4, a4, 0x0);
    VU0_LQC2(5, s2, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x20);
    p2 = buf + 0x20;
    VU0_LQC2(4, p2, 0x0);
    VU0_SQC2(4, buf, 0x10);
    if ((char *)buf != p1) {
        float x = *(float *)(buf + 0x10);
        float y = *(float *)(buf + 0x14);
        float z = *(float *)(buf + 0x18);

        *(float *)(buf + 0x0) = x;
        *(float *)(buf + 0x4) = y;
        *(float *)(buf + 0x8) = z;
    }

    VU0_SQC2_VF0(buf, 0x30);
    len = Tramp_001F7DF8_00101E28(buf);
    if (len > 0.0f) {
        float inv = 1.0f / len;

        *(float *)(buf + 0x3C) = *(float *)(buf + 0xC);
        *(float *)(buf + 0x30) = *(float *)(buf + 0x0) * inv;
        *(float *)(buf + 0x34) = *(float *)(buf + 0x4) * inv;
        *(float *)(buf + 0x38) = *(float *)(buf + 0x8) * inv;
    }

    p3 = buf + 0x30;
    VU0_LQC2(4, p3, 0x0);
    VU0_SQC2(4, buf, 0x20);
    VU0_LQC2(4, p2, 0x0);
    VU0_SQC2(4, buf, 0x30);
    VU0_LQC2(4, buf, 0x30);
    VU0_LOAD_SCALAR(5, k);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x30);
    VU0_LQC2(4, p3, 0x0);
    VU0_SQC2(4, buf, 0x10);
    if ((char *)buf != p1) {
        float x = *(float *)(buf + 0x10);
        float y = *(float *)(buf + 0x14);
        float z = *(float *)(buf + 0x18);

        *(float *)(buf + 0x0) = x;
        *(float *)(buf + 0x4) = y;
        *(float *)(buf + 0x8) = z;
    }

    VU0_LQC2(4, buf, 0x0);
    VU0_SQC2(4, buf, 0x10);
    VU0_LQC2(4, buf, 0x10);
    VU0_LQC2(5, s2, 0x0);
    VU0_VADD_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x10);
    VU0_LQC2(4, p1, 0x0);
    VU0_SQC2(4, a0, 0x0);
    return a0;
}
