/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void CopyVec3From110To120_14A2B0(void *a0);
extern void Forward30A2B0_2DA9B8(void *a0);
extern void func_002A74E0(void *a0, void *a1, int a2);

#include "godhand/vu0.h"


extern int func_00291010(void *a0, void *a1, void *a2, int a3, int t0,
                         float f12, float f13, float f14);








__attribute__((section(".text.func_00286AA8")))
void func_00286AA8(void *a0)
{
    char *s0 = (char *)a0;
    float buf[4] __attribute__((aligned(16)));
    int s1 = 1;
    int a;
    int bb;
    float *v1;

    {
        float *q = *(float **)(s0 + 0xF0);
        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, buf, 0);
    }
    if (func_00291010(&D_005864F0, buf, 0, 1, 0,
                      *(float *)(s0 + 0x104), 10.0f, 3.14159274f) == 0) {
        s1 = 0;
    }
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(int *)(s0 + 0x15B0) = *(int *)(s0 + 0x15B0) | 1;
        switch (*(unsigned char *)(s0 + 0x2F7)) {
        case 0: default:
            { int b = *(int *)(s0 + 0x304); a = *(int *)(b + 0xC0) + b; bb = *(int *)(b + 0xC4) + b; }
            break;
        case 1:
            { int b = *(int *)(s0 + 0x304); a = *(int *)(b + 0xC8) + b; bb = *(int *)(b + 0xCC) + b; }
            break;
        case 2:
            { int b = *(int *)(s0 + 0x304); a = *(int *)(b + 0xD0) + b; bb = *(int *)(b + 0xD4) + b; }
            break;
        case 3:
            { int b = *(int *)(s0 + 0x304); a = *(int *)(b + 0xD8) + b; bb = *(int *)(b + 0xDC) + b; }
            break;
        case 4:
            { int b = *(int *)(s0 + 0x304); a = *(int *)(b + 0x148) + b; bb = *(int *)(b + 0x14C) + b; }
            break;
        }
        func_002A8578(s0, a, bb, 0.0f, 0xA, 0, 0);
        {
            float *dst = (float *)(s0 + 0x5C0);
            float *src = *(float **)(s0 + 0xF0);

            if (dst != src) {
                *(float *)(s0 + 0x5C0) = src[0];
                dst[1] = src[1];
                dst[2] = src[2];
            }
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        v1 = *(float **)(s0 + 0xF0);
        v1[0] = v1[0] * 0.99f + *(float *)(s0 + 0x5C0) * 0.01f;
        {
            float *p2 = *(float **)(s0 + 0xF0);

            p2[2] = p2[2] * 0.99f + *(float *)(s0 + 0x5C8) * 0.01f;
        }
        if (0.0f < *(float *)(s0 + 0x24C)) {
            moveMotion(s0);
            CopyVec3From110To120_14A2B0(s0);
            Forward30A2B0_2DA9B8(s0);
        }
        if (*(unsigned char *)(s0 + 0x1560) != 5) {
            if (*(float *)(s0 + 0x618) < 16.0f) {
                if (func_00289328(s0) != 0) goto doit;
            }
            if (s1 == 0) goto doit;
        }
        if ((*(int *)(s0 + 0x15B0) & 8) == 0) break;
    doit:
        func_002A74E0(s0, s0 + 0x1590, 1);
        func_002A7CA0(s0, s0 + 0x1570);
        *(unsigned char *)(s0 + 0x2F7) = 0;
        *(unsigned char *)(s0 + 0x2F4) = 0;
        *(unsigned char *)(s0 + 0x2F6) = 0;
        *(unsigned char *)(s0 + 0x2F5) = 4;
        break;
    default:
        break;
    }
}
