/* sn-2.95.3-136 matched TU. */

extern float capVu0LengthSq(void *a0);
extern float sqrtf(float x);
extern void cDamageUnit_SetDamageCollActive(int a0, int a1);
extern int D_005FEE00[];

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"




extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g,
                              int h);


__attribute__((section(".text.func_001B0980")))
void func_001B0980(void *a0) {
    char *s0 = (char *)a0;
    float *d;
    float *s;
    float k;
    long flags;
    unsigned char on;
    float len;
    int coll;

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        d = (float *)(s0 + 0x610);
        s = (float *)(s0 + 0x5C0);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
        k = 0.08f;
        VU0_LQC2(4, s0, 0x610);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, s0, 0x610);
        flags = *(unsigned int *)(s0 + 0x5B4);
        on = (flags >> 2) & 1;
        if (on == 1) {
            len = __builtin_sqrtf(capVu0LengthSq(d));
            *(float *)(s0 + 0x614) = len * 0.1f;
            *(float *)(s0 + 0x610) = *(float *)(s0 + 0x610) * 0.1f;
            *(float *)(s0 + 0x618) = *(float *)(s0 + 0x618) * 0.1f;
            *(unsigned char *)(s0 + 0x624) = on;
            coll = *(int *)(s0 + 0x600);
            if (coll != 0) {
                cDamageUnit_SetDamageCollActive(coll, 0);
            }
        }
        *(short *)(s0 + 0x622) = 0;
        *(unsigned char *)(s0 + 0x625) = 1;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x30, s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = 1;
        *(unsigned char *)(s0 + 0x2F7) = 0;
    case 1:
        *(unsigned char *)(s0 + 0x2F5) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
}
