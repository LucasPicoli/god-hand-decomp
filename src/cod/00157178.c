/* sn-2.95.3-136 matched TU. */

extern void StoreVecFromFieldB0_2B6160(void *dst, void *obj);
extern void func_002FEB18(void *obj);
extern int D_005CAFF0;

/* sn-2.95.3-136 candidate. */

__attribute__((section(".text.GetPointCalcPointLine")))
void GetPointCalcPointLine(float *p, float *q, float *r, float *out) {
    float dx = q[0] - p[0];
    float dy = q[1] - p[1];
    float dz = q[2] - p[2];
    float ex = r[0] - p[0];
    float ey = r[1] - p[1];
    float ez = r[2] - p[2];
    float t = (dx * ex + dy * ey + dz * ez) / (dx * dx + dy * dy + dz * dz);

    out[0] = p[0] + t * dx;
    out[1] = p[1] + t * dy;
    out[2] = p[2] + t * dz;
    out[3] = 1.0f;
}

#include "godhand/vu0.h"





__attribute__((section(".text.func_002F6F48")))
void func_002F6F48(char *p) {
    char buf[0x20] __attribute__((aligned(16)));
    float hi;
    float lim;
    float save;
    float scale;
    float d;
    float *src;
    float b;

    hi = *(float *)(p + 0x2B8);
    lim = hi - *(float *)(p + 0x2BC);
    save = *(float *)(p + 0x194);

    VU0_SQC2_VF0(buf, 0x0);
    src = (float *)(D_005CAFF0 + 0x210);
    if ((float *)buf != src) {
        *(float *)(buf + 0x0) = src[0];
        *(float *)(buf + 0x4) = src[1];
        *(float *)(buf + 0x8) = src[2];
    }
    StoreVecFromFieldB0_2B6160(buf + 0x10, p);

    scale = 1.0f;
    d = *(float *)(buf + 0x0);
    b = *(float *)(buf + 0x10);
    d = d - b;
    d = __builtin_fabsf(d);
    if (lim < d) {
        if (d < hi) {
            scale = 1.0f - (d - lim) / *(float *)(p + 0x2BC);
        } else {
            scale = 0.0f;
        }
    }
    d = *(float *)(buf + 0x8);
    b = *(float *)(buf + 0x18);
    d = d - b;
    d = __builtin_fabsf(d);
    if (lim < d) {
        if (d < hi) {
            scale = scale * (1.0f - (d - lim) / *(float *)(p + 0x2BC));
        } else {
            scale = 0.0f;
        }
    }
    *(float *)(p + 0x194) = *(float *)(p + 0x194) * scale;
    func_002FEB18(p);
    *(float *)(p + 0x194) = save;
}
