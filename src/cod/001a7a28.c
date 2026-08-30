/* sn-2.95.3-136 matched TU. */

extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"

#define FRAME ((char *)va - 0x30)

extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);




__attribute__((section(".text.func_001A7A28")))
void func_001A7A28(void *a0)
{
    char *s1 = (char *)a0;
    float va[4];
    float vb[4];
    char *p2, *p5, *p4, *p3;
    int m;
    float d;
    float k;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        {
        char *q = *(char **)(s1 + 0xF0);
        *(float *)(s1 + 0x624) = *(float *)(q + 4);
        *(int *)(s1 + 0x5A0) &= -2;
        if (*(float *)(s1 + 0x620) == 0.0f) {
            char *pa = (char *)va;
            VU0_LQC2(4, q, 0x0);
            VU0_SQC2(4, FRAME, 0x30);
            VU0_SQC2_VF0(FRAME, 0x40);
            d = va[1] - 50.0f;
            va[1] = d;
            *(float *)(s1 + 0x61C) = d;
            if (ChkLine(q, pa, vb, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) != 0) {
                *(float *)(s1 + 0x61C) = vb[1];
            }
            *(float *)(s1 + 0x620) = *(float *)(s1 + 0x61C) + 2.0f;
        }
        }
        *(unsigned char *)(s1 + 0x2F7) = 0;
        *(unsigned char *)(s1 + 0x2F6) = 1;
    case 1:
        {
        char *q1 = *(char **)(s1 + 0xF0);
        *(float *)(q1 + 4) = *(float *)(q1 + 4) - 0.5f;
        }
        if (*(float *)(*(char **)(s1 + 0xF0) + 4) <= *(float *)(s1 + 0x620)) {
            *(unsigned char *)(s1 + 0x2F7) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        break;
    case 2:
        {
        int c2;
        func_001A7F58(s1);
        c2 = *(unsigned char *)(s1 + 0x613) + 1;
        *(unsigned char *)(s1 + 0x2F6) = 3;
        *(unsigned short *)(s1 + 0x616) = *(unsigned short *)(s1 + 0x628);
        *(unsigned char *)(s1 + 0x613) = c2;
        }
        *(unsigned char *)(s1 + 0x2F7) = 0;
        break;
    case 3:
        if (*(short *)(s1 + 0x616) <= 0 || *(unsigned char *)(s1 + 0x614) == 1) {
            *(unsigned char *)(s1 + 0x614) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 4;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        *(unsigned short *)(s1 + 0x616) = *(unsigned short *)(s1 + 0x616) - 1;
        break;
    case 4:
        {
        char *q4 = *(char **)(s1 + 0xF0);
        *(float *)(q4 + 4) = *(float *)(q4 + 4) + 0.100000001f;
        }
        if (*(float *)(s1 + 0x624) <= *(float *)(*(char **)(s1 + 0xF0) + 4)) {
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(int *)(s1 + 0x5A0) |= 1;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        break;
    }
    {
        int lim = 1;
        int b;
        unsigned char ok;
        ok = ((*(int *)va = b = *(unsigned char *)(s1 + 0x2B4)), (lim < b));
        if (ok) p2 = *(char **)(*(char **)(s1 + 0x278) + 4); else p2 = 0;
    }
    {
        int lim = 2;
        int b;
        unsigned char ok;
        ok = ((*(int *)va = b = *(unsigned char *)(s1 + 0x2B4)), (lim < b));
        if (ok) p5 = *(char **)(*(char **)(s1 + 0x278) + 8); else p5 = 0;
    }
    {
        int lim = 3;
        int b;
        unsigned char ok;
        ok = ((*(int *)va = b = *(unsigned char *)(s1 + 0x2B4)), (lim < b));
        if (ok) p4 = *(char **)(*(char **)(s1 + 0x278) + 0xC); else p4 = 0;
    }
    {
        int lim = 4;
        int b;
        unsigned char ok;
        ok = ((*(int *)va = b = *(unsigned char *)(s1 + 0x2B4)), (lim < b));
        if (ok) p3 = *(char **)(*(char **)(s1 + 0x278) + 0x10); else p3 = 0;
    }
    if (p2 == 0) {
        return;
    }
    if (p5 == 0) {
        return;
    }
    if (p4 == 0) {
        return;
    }
    if (p3 == 0) {
        return;
    }
    m = *(unsigned char *)(s1 + 0x613);
    if (m == 1) {
        goto L1;
    }
    if (m < 2) {
        return;
    }
    if (m == 2) {
        goto L2;
    }
    if (m == 3) {
        goto L3;
    }
    return;
L1:
    {
    char *mg = D_005864F0;
    k = 0.17453292f;
    *(float *)(p2 + 0x100) = *(float *)(p2 + 0x100) + cEmManage_GetSpeedRate(mg) * k;
    *(float *)(p5 + 0x108) = *(float *)(p5 + 0x108) + cEmManage_GetSpeedRate(mg) * k;
    *(float *)(p4 + 0x100) = *(float *)(p4 + 0x100) - cEmManage_GetSpeedRate(mg) * k;
    *(float *)(p3 + 0x108) = *(float *)(p3 + 0x108) - cEmManage_GetSpeedRate(mg) * k;
    if (2.96705961f <= *(float *)(p2 + 0x100)) {
        *(float *)(p2 + 0x100) = 2.96705961f;
        *(float *)(p5 + 0x108) = 2.96705961f;
        *(float *)(p4 + 0x100) = -2.96705961f;
        *(float *)(p3 + 0x108) = -2.96705961f;
        *(short *)(s1 + 0x618) = 60;
        *(unsigned char *)(s1 + 0x613) = *(unsigned char *)(s1 + 0x613) + 1;
    }
    }
    return;
L2:
    *(unsigned short *)(s1 + 0x618) = *(unsigned short *)(s1 + 0x618) - 1;
    if (*(short *)(s1 + 0x618) <= 0) {
        *(unsigned char *)(s1 + 0x613) = *(unsigned char *)(s1 + 0x613) + 1;
    }
    return;
L3:
    {
    char *mg = D_005864F0;
    k = 0.0872664601f;
    *(float *)(p2 + 0x100) = *(float *)(p2 + 0x100) - cEmManage_GetSpeedRate(mg) * k;
    *(float *)(p5 + 0x108) = *(float *)(p5 + 0x108) - cEmManage_GetSpeedRate(mg) * k;
    *(float *)(p4 + 0x100) = *(float *)(p4 + 0x100) + cEmManage_GetSpeedRate(mg) * k;
    *(float *)(p3 + 0x108) = *(float *)(p3 + 0x108) + cEmManage_GetSpeedRate(mg) * k;
    if (*(float *)(p2 + 0x100) <= 0.0f) {
        *(float *)(p2 + 0x100) = 0.0f;
        *(float *)(p5 + 0x108) = 0.0f;
        *(float *)(p4 + 0x100) = 0.0f;
        *(float *)(p3 + 0x108) = 0.0f;
        *(unsigned char *)(s1 + 0x613) = 0;
    }
    }
}
