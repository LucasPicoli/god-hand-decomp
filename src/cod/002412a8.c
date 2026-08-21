/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

#include "godhand/vu0.h"







extern int func_00291010(void *a0, void *a1, void *a2, int a3, int t0,
                         float f12, float f13, float f14);

__attribute__((section(".text.func_002412A8")))
void func_002412A8(void *a0)
{
    char *s0 = (char *)a0;
    float buf[4] __attribute__((aligned(16)));

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int b = (int)*(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x1A50) + b,
                      *(int *)(b + 0x1A54) + b, 0.0f, 3, 0, 0);
        *(short *)(s0 + 0x568) = 0xA;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        int m = *(int *)(s0 + 0x16D0);
        m |= 0x10000;
        *(float *)(s0 + 0x54C) = 3.0f;
        m |= 0x20000;
        *(int *)(s0 + 0x16D0) = m;
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f / *(float *)(s0 + 0x118));
        break;
    }
    case 2: {
        int b = (int)*(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x18F0) + b,
                      *(int *)(b + 0x18F4) + b, 10.0f, 0, 0, 0);
        *(short *)(s0 + 0x568) = 0xA;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3: {
        float *dst;
        float *src;
        int m = *(int *)(s0 + 0x16D0);
        m |= 0x10000;
        *(float *)(s0 + 0x54C) = 3.0f;
        m |= 0x20000;
        *(int *)(s0 + 0x16D0) = m;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(int *)(s0 + 0x16D0) & 0x20000000) == 0) {
            int n;
            float *q = *(float **)(s0 + 0xF0);
            VU0_LQC2(4, q, 0);
            VU0_SQC2(4, buf, 0);
            if (func_00291010(&D_005864F0, buf, s0, 2, 0,
                              *(float *)(s0 + 0x104), 100.0f, 3.14159274f) != 0)
                break;
            n = *(unsigned short *)(s0 + 0x568) - 1;
            *(short *)(s0 + 0x568) = n;
            if ((short)n > 0)
                break;
        }
        dst = (float *)(s0 + 0x6D0);
        src = *(float **)(s0 + 0xF0);
        if (dst != src) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
        }
        *(unsigned char *)(s0 + 0x2F5) = 0x75;
        *(float *)(s0 + 0x6E0) = *(float *)(s0 + 0x104);
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F7) = 0;
        break;
    }
    }
}
