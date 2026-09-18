/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void cCamManager_setPartsCamera(void *cam, int mode);
extern void Obj0000_Set_Fields_360_364_368_139B68(void *parts, void *obj, int a2, int a3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern void Obj1D00_ClearState_9(void *a0);
extern int D_00463050;

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

__attribute__((section(".text.func_00212C08")))
void func_00212C08(void *a0)
{
    char *s1 = (char *)a0;
    S s;
    void *s2;
    char *base;
    char *parts;
    int a2v;
    int a3v;
    int b;
    int lim;
    int nb;
    int spill[2];

    s2 = Obj0000_Get_D_00747A94_2DB6B0();
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
    s.f40 = *(float *)(s1 + 0x114);
    s.h72 = 0;
    s.b74 = 0;
    s.i78 = 0;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        switch (*(int *)(s1 + 0x564)) {
        case 0x220:
        case 0x221:
        case 0x222:
        default:
            { int v0 = *(int *)(s1 + 0x304);
            func_002A8578(s1, *(int *)(v0 + 0x1D08) + v0, *(int *)(v0 + 0x1D0C) + v0, 0.0f, 3, nb, 0); }
            break;
        case 0x223:
            { int v0 = *(int *)(s1 + 0x304);
            func_002A8578(s1, *(int *)(v0 + 0x2E4C) + v0, *(int *)(v0 + 0x2E50) + v0, 0.0f, 3, nb, 0); }
            break;
        case 0x209:
            { int v0 = *(int *)(s1 + 0x304);
            func_002A8578(s1, *(int *)(v0 + 0x34F4) + v0, *(int *)(v0 + 0x34F8) + v0, 0.0f, 3, nb, 0); }
            break;
        }
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        return;
    case 2:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        { int v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x1D78) + v0, *(int *)(v0 + 0x1D7C) + v0, 0.0f, 0, nb, 0); }
        *(unsigned char *)(s1 + 0x616) = 1;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 3:
        base = (char *)&D_00463050;
        cCamManager_setPartsCamera(base, 0);
        parts = base + 0x920;
        b = *(unsigned char *)(s1 + 0x2B4);
        spill[0] = b;
        lim = 0x1B;
        if (lim < b) {
            a2v = *(int *)(*(int *)(s1 + 0x278) + 0x6C);
        } else {
            a2v = 0;
        }
        b = *(unsigned char *)(s1 + 0x2B4);
        spill[0] = b;
        lim = 0x1C;
        if (lim < b) {
            a3v = *(int *)(*(int *)(s1 + 0x278) + 0x70);
        } else {
            a3v = 0;
        }
        Obj0000_Set_Fields_360_364_368_139B68(parts, s1, a2v, a3v);
        *(float *)(s1 + 0x54C) = 3.0f;
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s2, 0, 1);
            func_002705D8(s1);
            *(unsigned char *)(s1 + 0x616) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        return;
    case 4:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        { int v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x2EE4) + v0, *(int *)(v0 + 0x2EE8) + v0, 0.0f, 0, nb, 0); }
        SetEffect(0x7B, 0xB9, s1, 0, -1, 0xFFFFFFFFu);
        *(unsigned char *)(s1 + 0x616) = 1;
        if (*(int *)(s1 + 0x6F4) != 0) {
            Obj1D00_ClearState_9(*(void **)(s1 + 0x6F4));
        }
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 5:
        *(float *)(s1 + 0x54C) = 3.0f;
        if (moveMotion(s1) != 0) {
            SetEffect(0x7B, 0xB7, s1, &s, 1, 0xFFFFFFFFu);
            func_002705D8(s1);
            *(unsigned char *)(s1 + 0x616) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        return;
    case 6:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        { int v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x3418) + v0, *(int *)(v0 + 0x341C) + v0, 0.0f, 3, nb, 0); }
        *(unsigned char *)(s1 + 0x616) = 1;
        *(float *)(s1 + 0x600) = 30.0f;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 7:
        *(float *)(s1 + 0x54C) = 3.0f;
        moveMotion(s1);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        *(float *)(s1 + 0x600) = *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
        if (*(float *)(s1 + 0x600) <= 0.0f) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        break;
    case 8:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        { int v0 = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x3420) + v0, *(int *)(v0 + 0x3424) + v0, 0.0f, 3, nb, 0); }
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 9:
        *(float *)(s1 + 0x54C) = 3.0f;
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
            *(unsigned char *)(s1 + 0x616) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
