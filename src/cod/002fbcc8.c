/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/globals.h"

extern void InitObjectVtable_2FBD98(char *p);

#include "godhand/vu0.h"




__attribute__((section(".text.InitObject_2FBCC8")))
char *InitObject_2FBCC8(char *a0)
{
    char *s0 = a0;
    float *p1;
    float *p2;
    InitObjectVtable_2FBD98(a0);
    *(int*)(s0 + 0xF0) = (int)&D_0044FAD0;
    p1 = (float*)(s0 + 0x188);
    p2 = (float*)(s0 + 0x1F8);
    p1[0] = 1.0f;
    p1[1] = 1.0f;
    p1[2] = 1.0f;
    p1[3] = 1.0f;
    p2[0] = 1.0f;
    p2[1] = 1.0f;
    p2[2] = 1.0f;
    p2[3] = 1.0f;
    *(short*)(s0 + 0x238) = -1;
    *(float*)(s0 + 0x210) = 1.0f;
    *(float*)(s0 + 0x240) = 1.0f;
    *(char*)(s0 + 0x23E) = 1;
    *(char*)(s0 + 0x23F) = 1;
    *(char*)(s0 + 0x245) = 1;
    *(char*)(s0 + 0x246) = 1;
    VU0_SQC2_VF0(s0, 0x280);
    VU0_SQC2_VF0(s0, 0x290);
    {
        int t = *(int*)(s0 + 0x11C);
        t |= 0x4000000;
        *(int*)(s0 + 0x280) = 0;
        t |= 0x2000000;
        *(int*)(s0 + 0x284) = 0;
        *(int*)(s0 + 0x11C) = t;
    }
    *(int*)(s0 + 0x288) = 0;
    *(int*)(s0 + 0x290) = 0;
    *(int*)(s0 + 0x294) = 0;
    *(int*)(s0 + 0x298) = 0;
    *(char*)(s0 + 0x2A1) = 0;
    *(char*)(s0 + 0x2A0) = 0;
    *(short*)(s0 + 0x276) = 0;
    return s0;
}
