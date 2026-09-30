/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void func_0027E7F0(void *a0, void *a1);

extern void cCamManager_setPartsCamera(void *cam, int mode);
extern void Obj0000_Set_Fields_360_364_368_139B68(void *parts, void *obj, int a2, int a3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void ReleaseObj(void *a0);
extern void func_00275DA8(void *a0);
extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int D_00463050;
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

__attribute__((section(".text.func_00247B18")))
void func_00247B18(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    int spill[2];
    S s;
    char *v;
    char *base;
    char *parts;
    int nb, b, lim, a2v, a3v;
    float one;
    float *fp;

    s2 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x40000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        *(char *)(s1 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x38B0) + b, *(int *)(b + 0x38B4) + b, 0.0f, 0, nb, 0);
        if (*(void **)(s1 + 0x744) != 0) {
            func_0027E7F0(*(void **)(s1 + 0x744), s1);
        }
        *(float *)(s1 + 0x1768) = 600.0f;
        v = func_0014B730(s1, &D_0042CAD0);
        if (v != 0) {
            *(int *)(v + 0x380) = *(int *)(v + 0x380) & 0xFFFFFFFE;
        }
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        *(float *)(s1 + 0x54C) = 3.0f;
        base = (char *)&D_00463050;
        cCamManager_setPartsCamera(base, 0);
        parts = base + 0x920;
        b = *(unsigned char *)(s1 + 0x2B4);
        spill[0] = b;
        lim = 0x24;
        if (lim < b) {
            a2v = *(int *)(*(int *)(s1 + 0x278) + 0x90);
        } else {
            a2v = 0;
        }
        b = *(unsigned char *)(s1 + 0x2B4);
        spill[0] = b;
        lim = 0x25;
        if (lim < b) {
            a3v = *(int *)(*(int *)(s1 + 0x278) + 0x94);
        } else {
            a3v = 0;
        }
        Obj0000_Set_Fields_360_364_368_139B68(parts, s1, a2v, a3v);
        *(int *)(s1 + 0x16D0) = *(int *)(s1 + 0x16D0) | 0x800000;
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s2, 0, 1);
            if (*(void **)(s1 + 0x744) != 0) {
                ReleaseObj(*(void **)(s1 + 0x744));
                *(int *)(s1 + 0x744) = 0;
                func_00275DA8(s1);
            }
            fp = &s.f00;
            s.f00 = 1.0f;
            fp[1] = 1.0f;
            fp[2] = 1.0f;
            fp[3] = 1.0f;
            VU0_SQC2_VF0(spill, 0x20);
            VU0_SQC2_VF0(spill, 0x30);
            {
                float *q = &s.f30;
                s.f30 = 1.0f;
                q[1] = 1.0f;
                q[2] = 1.0f;
                q[3] = 1.0f;
            }
            fp[0x10] = 1.0f;
            s.i44 = 0;
            s.i48 = 0;
            ((signed char *)fp)[0x4C] = -1;
            s.b4D = 0;
            s.b4E = 0;
            ((unsigned char *)fp)[0x4F] = 0xFF;
            s.i50 = 0;
            VU0_SQC2_VF0(spill, 0x70);
            s.f40 = *(float *)(s1 + 0x114);
            s.h70 = 0;
            s.h72 = 0;
            s.b74 = 0;
            s.i78 = 0;
            SetEffect(0xBD, 0x19, s1, &s, 1, 0xFFFFFFFF);
            *(int *)(s1 + 0x16D4) = *(int *)(s1 + 0x16D4) | 0x20000000;
            *(char *)(s1 + 0x186C) = 2;
            *(unsigned char *)(s1 + 0x2F6) = 2;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    case 2:
        *(char *)(s1 + 0x1864) = 0;
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        b = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(b + 0x3778) + b, *(int *)(b + 0x377C) + b, 0.0f, 3, nb, 0);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 3:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0x9C;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
}
