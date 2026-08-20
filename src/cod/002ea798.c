/* sn-2.95.3-136 matched TU. */

extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern float capVu0Length(void *a0);
extern char *D_005CAFF0;

#include "godhand/vu0.h"

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_002EA798")))
float func_002EA798(void *arg) {
    char *s0 = (char *)arg;
    float buf[8];
    float r;

    StoreVecFromFieldB0_2B6160(buf, s0);
    VU0_LQC2(4, D_005CAFF0 + 0x210, 0);
    VU0_SQC2(4, buf, 0x10);
    if (*(float *)(s0 + 0x2C8) != 0.0f) {
        float k = 1000.0f;
        buf[0] = buf[0] - buf[4];
        buf[1] = buf[1] - buf[5];
        buf[2] = buf[2] - buf[6];
        VU0_LQC2(4, buf, 0);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0);
        r = capVu0Length(buf) / *(float *)(s0 + 0x2C8);
        if (1.0f < r) {
            r = 1.0f;
        }
        if (r < 0.0f) {
            r = 0.0f;
        }
        return 1.0f - r;
    }
    return 1.0f;
}
