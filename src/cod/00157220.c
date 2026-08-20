/* sn-2.95.3-136 matched TU. */

extern float sceVu0InnerProduct(void *a0, void *a1);
extern float capVu0Length(void *a0);

/* sn-2.95.3-136 candidate. */




#include "godhand/vu0.h"

__attribute__((section(".text.GetDistCalcPointSegment")))
float GetDistCalcPointSegment(void *a0, void *a1, void *a2, float *out) {
    char buf[0x60] __attribute__((aligned(16)));
    float t;
    char *p;
    char *q;
    char *r30;
    char *r50;

    VU0_SQC2_VF0(buf, 0x10);
    VU0_LQC2(4, a2, 0x0);
    VU0_LQC2(5, a0, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x10);
    p = buf + 0x10;
    VU0_LQC2(4, p, 0x0);
    VU0_SQC2(4, buf, 0x0);

    VU0_SQC2_VF0(buf, 0x20);
    VU0_LQC2(4, a1, 0x0);
    VU0_LQC2(5, a0, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x20);
    VU0_LQC2(4, buf + 0x20, 0x0);
    VU0_SQC2(4, buf, 0x10);

    t = sceVu0InnerProduct(buf, p) / sceVu0InnerProduct(p, p);
    if (t < 0.0f) {
        t = 0.0f;
    } else if (1.0f < t) {
        t = 1.0f;
    }

    q = buf + 0x40;
    VU0_LQC2(4, p, 0x0);
    VU0_SQC2(4, buf, 0x40);
    VU0_LQC2(4, buf, 0x40);
    VU0_LOAD_SCALAR(5, t);
    VU0_VMULX_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x40);
    VU0_LQC2(4, q, 0x0);
    VU0_SQC2(4, buf, 0x30);
    r30 = buf + 0x30;
    VU0_SQC2_VF0(buf, 0x40);
    VU0_LQC2(4, buf, 0x0);
    VU0_LQC2(5, r30, 0x0);
    VU0_VSUB_XYZ(4, 4, 5);
    VU0_SQC2(4, buf, 0x40);
    VU0_LQC2(4, q, 0x0);
    VU0_SQC2(4, buf, 0x20);

    if (out != 0) {
        r50 = buf + 0x50;
        VU0_LQC2(4, p, 0x0);
        VU0_SQC2(4, buf, 0x50);
        VU0_LQC2(4, buf, 0x50);
        VU0_LOAD_SCALAR(5, t);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x50);
        VU0_LQC2(4, r50, 0x0);
        VU0_SQC2(4, buf, 0x40);
        VU0_LQC2(4, a0, 0x0);
        VU0_SQC2(4, buf, 0x50);
        VU0_LQC2(4, buf, 0x50);
        VU0_LQC2(5, q, 0x0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x50);
        VU0_LQC2(4, r50, 0x0);
        VU0_SQC2(4, buf, 0x30);
        if (out != (float *)r30) {
            float x = *(float *)(buf + 0x30);
            float y = *(float *)(buf + 0x34);
            float z = *(float *)(buf + 0x38);

            out[0] = x;
            out[1] = y;
            out[2] = z;
        }
    }
    return capVu0Length(buf + 0x20);
}
