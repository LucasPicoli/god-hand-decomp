/* sn-2.95.3-136 matched TU. */

extern void func_002E1468(void *a0, void *a1, void *a2, void *a3, float f0, float f1, float f2);

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"



__attribute__((section(".text.func_0013C630")))
void func_0013C630(void *arg) {
    char *s0 = (char *)arg;
    float buf[16];
    float *p;
    float r;

    if (*(unsigned char *)(s0 + 0x74) != 0) {
        return;
    }
    if (*(unsigned char *)(s0 + 0x75) == 0) {
        return;
    }
    if (*(unsigned char *)(s0 + 0x76) != 0) {
        int t;

        t = *(unsigned short *)(s0 + 0x72);
        t = t + 1;
        *(short *)(s0 + 0x72) = t;
        if (*(short *)(s0 + 0x70) < (short)t) {
            *(short *)(s0 + 0x72) = *(unsigned short *)(s0 + 0x70);
            *(unsigned char *)(s0 + 0x75) = 0;
        }
    } else {
        int t;

        t = *(unsigned short *)(s0 + 0x72);
        t = t - 1;
        *(short *)(s0 + 0x72) = t;
        if ((short)t < 0) {
            *(short *)(s0 + 0x72) = 0;
            *(unsigned char *)(s0 + 0x75) = 0;
        }
    }
    r = (float)*(short *)(s0 + 0x72) / (float)*(short *)(s0 + 0x70);
    buf[0] = 0.0f;
    buf[1] = 0.0f;
    buf[2] = 0.0f;
    buf[3] = 1.0f;
    buf[4] = *(float *)(s0 + 0x58) - *(float *)(s0 + 0x50);
    buf[5] = *(float *)(s0 + 0x5C) - *(float *)(s0 + 0x54);
    buf[6] = 0.0f;
    p = buf + 4;
    p[3] = 1.0f;
    VU0_SQC2_VF0(buf, 0x20);
    func_002E1468(&buf[12], &buf[8], &buf[0], p, r, 0.0f, 0.0f);
    *(float *)(s0 + 0x60) = buf[8];
    *(float *)(s0 + 0x64) = buf[9];
}
