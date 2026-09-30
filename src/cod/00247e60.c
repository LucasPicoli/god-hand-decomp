/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void ReleaseObj(void *a0);
extern void func_00275DA8(void *a0);

extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int D_0042CAD0;

typedef struct {
    float f00;
    float f04;
    float f08;
    float f0C;
    char q10[0x10];
    char q20[0x10];
    float f30;
    float f34;
    float f38;
    float f3C;
    float f40;
    int i44;
    int i48;
    signed char b4C;
    signed char b4D;
    signed char b4E;
    unsigned char b4F;
    int i50;
    char pad54[0xC];
    char q60[0x10];
    short h70;
    short h72;
    signed char b74;
    char pad75[3];
    int i78;
} S;

__attribute__((section(".text.func_00247E60")))
void func_00247E60(void *a0)
{
    char *s0 = (char *)a0;
    S s;
    char *v;
    int t0, b, p1, p2;
    float one;

    *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x40000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(char *)(s0 + 0x1864) = 0;
        t0 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        b = *(int *)(s0 + 0x304);
        p1 = *(int *)(b + 0x38C0) + b;
        p2 = *(int *)(b + 0x38C4) + b;
        *(int *)(s0 + 0x16D4) = *(int *)(s0 + 0x16D4) | 0x20000000;
        *(char *)(s0 + 0x186C) = 2;
        func_002A8578(s0, p1, p2, 0.0f, 10, t0, 0);
        *(float *)(s0 + 0x1768) = 600.0f;
        if (*(void **)(s0 + 0x744) != 0) {
            ReleaseObj(*(void **)(s0 + 0x744));
            *(int *)(s0 + 0x744) = 0;
            func_00275DA8(s0);
        }
        s.f00 = 1.0f;
        s.f04 = 1.0f;
        s.f08 = 1.0f;
        s.f0C = 1.0f;
        VU0_SQC2_VF0(&s, 0x10);
        VU0_SQC2_VF0(&s, 0x20);
        {
            float *q = &s.f30;
            s.f30 = 1.0f;
            q[1] = 1.0f;
            q[2] = 1.0f;
            q[3] = 1.0f;
        }
        s.f40 = 1.0f;
        s.b4C = -1;
        s.b4F = 0xFF;
        s.i44 = 0;
        s.i48 = 0;
        s.b4D = 0;
        s.b4E = 0;
        s.i50 = 0;
        VU0_SQC2_VF0(&s, 0x60);
        s.h70 = 0;
        s.f40 = *(float *)(s0 + 0x114);
        s.h72 = 0;
        s.b74 = 0;
        s.i78 = 0;
        SetEffect(0xBD, 0x19, s0, &s, 1, 0xFFFFFFFF);
        v = func_0014B730(s0, &D_0042CAD0);
        if (v != 0) {
            *(int *)(v + 0x380) = *(int *)(v + 0x380) & 0xFFFFFFFE;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x800000;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x9C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
}
