/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern int Forward30F348_31CFE0(void);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void func_00262980(void *a0);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_00260B30(void *a0);
extern int D_00569B70;
extern int SetCustomIDDispOneOrAll_1EE1C0();
extern int CustomIDWork_SetColorAnimSin();
extern void MaxField514_292030(void *a0, int a1);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxByte538_292EF0(void *a0, int a1);
extern void SetField548AndGlobals_292F38(void *a0, float a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00129578(void *a0);
extern void ShiftDownBytesA8_FAC00(void *a0);
extern void InvokeVirtualAtField214AndForward_124E68(void *a0, float f);
extern void func_00124EC0(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_00129630(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_0010A438(void *a0);
extern void cSnd_SeStop(void *a0, int a1);
extern char D_005864F0[];
extern char D_005FEE00[];
extern char D_00462FC0[];
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float a2);
extern void func_00274FE8(void *a0);
extern void func_00262750(void *a0, int a1);
extern char D_005CB000[];

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_00227FE8")))
void func_00227FE8(void *a0)
{
    char *s1 = (char *)a0;

    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        char *v0;
        int a1v, a2v;
        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        *(unsigned char *)(s1 + 0x2F7) = (unsigned int)Forward30F348_31CFE0() % 3;
        v0 = *(char **)(s1 + 0x304);
        a1v = *(int *)(v0 + 0x2FEC) + (int)v0;
        a2v = *(int *)(v0 + 0x2FF0) + (int)v0;
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = *(char **)(s1 + 0x304);
            a2v = *(int *)(v1 + 0x2FF4) + (int)v1;
        }
        StoreMotionParamsBoth_2609A8(s1, 0x28, 0, 0x3E, -1, 0);
        func_002A8578(s1, a1v, a2v, 0.0f, 3, gb, 0);
        *(int *)(s1 + 0x5F0) = 0x1E;
        *(float *)(s1 + 0x600) = 20.0f;
        *(unsigned char *)(s1 + 0x2F6) += 1;
        *(int *)(s1 + 0x5F4) = 0;
        *(int *)(s1 + 0x5FC) = 0;
    }
        /* fallthrough */
    case 1: {
        float f1;
        if (*(int *)(s1 + 0x5F0) != 0) {
            char *v0;
            *(int *)(s1 + 0x5F0) -= 1;
            v0 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
            AddScaledDeltaToField_104_2A7498(s1, *(int *)(v0 + 0xF0), *(float *)(s1 + 0x5A8) * 0.19634955f);
        }
        f1 = *(float *)(s1 + 0x600);
        if (f1 > 0.0f) {
            *(int *)(s1 + 0x16D0) |= 0x2000;
            *(float *)(s1 + 0x600) = f1 - *(float *)(s1 + 0x5A8);
            *(int *)(s1 + 0x16D4) |= 0x2000;
        }
        if (*(int *)(s1 + 0x16D4) & 0x4000) {
            *(int *)(s1 + 0x5FC) = 1;
            func_00262980(s1);
        }
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x10) && *(int *)(s1 + 0x5FC) == 0) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        break;
    }
    case 2: {
        int gb;
        char *v1;
        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v1 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v1 + 0x2FF8) + (int)v1, *(int *)(v1 + 0x2FFC) + (int)v1, 0.0f, 3, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_00260B30(s1);
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001EE2E8")))
void func_001EE2E8(void *a0, int a1, int a2)
{
    char *s1 = (char *)a0;

    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x2, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x3, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x4, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x5, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x6, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x7, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x8, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x9, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xA, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xB, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xC, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xD, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xE, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0xF, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x10, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x17, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x18, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x19, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1A, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1B, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x11, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x12, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x13, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x14, a1);
    SetCustomIDDispOneOrAll_1EE1C0(s1, 0x1C, a1);
    if (a2) {
        int mff = ~0xFF;
        int m24 = 0xFFFFFF;
        int hi = 0x80000000;
        int m16 = ~0xFF0000;
        int m8 = ~0xFF00;
        int b;
        int c;
        int x = ((((((((b & m24) | hi) & m16) | 0x800000) & m8) | 0x8000) & mff) | 0x80);
        int y = ((((((((c & mff) | 0xD0) & m8) | 0xD000) & m16) | 0xD00000) & m24) | hi);
        CustomIDWork_SetColorAnimSin(s1 + 0xA8C, x, y, 6);
        SetCustomIDDispOneOrAll_1EE1C0(s1, 0x15, a1);
    } else {
        int mff = ~0xFF;
        int m24 = 0xFFFFFF;
        int hi = 0x80000000;
        int m16 = ~0xFF0000;
        int m8 = ~0xFF00;
        int b;
        int c;
        int x = ((((((((b & m24) | hi) & m16) | 0x800000) & m8) | 0x8000) & mff) | 0x80);
        int y = ((((((((c & mff) | 0xD0) & m8) | 0xD000) & m16) | 0xD00000) & m24) | hi);
        CustomIDWork_SetColorAnimSin(s1 + 0xB08, x, y, 6);
        SetCustomIDDispOneOrAll_1EE1C0(s1, 0x16, a1);
    }
}

/* sn-2.95.3-136 matched TU. */




























__attribute__((section(".text.func_00111750")))
void func_00111750(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    MaxField514_292030(D_005864F0, 2);
    Obj293_SetByte_53C_2(D_005864F0);
    MaxByte538_292EF0(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    if (*(unsigned char *)(s1 + 0x2F6) != 0 &&
        *(unsigned char *)(s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)(s1 + 0x649) = 1;
        ShiftDownBytesA8_FAC00(&D_00569B70);
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x82, 0x11, 0x1F, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x82, 0x11, 0x1F, 0, 0x123);
        t = *(int *)(s1 + 0x304);
        *(char *)(s1 + 0x1684) = 1;
        func_002A8578(s1, *(int *)(t + 0x1C0) + t, *(int *)(t + 0x1C4) + t,
                      0.0f, 3, 0, 0);
        func_00129578(s1);
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
        InvokeVirtualAtField214AndForward_124E68(s1, 3.14159274f);
        *(int *)(s1 + 0x15B0) = 1;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
            Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
        }
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        SetField548AndGlobals_292F38(D_005864F0, 0.1f);
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
        char *g = D_005FEE00;
        cSnd_SeStop(g, *(int *)(s1 + 0x161C));
        *(int *)(s1 + 0x161C) = 0;
        *(int *)(g + 0xB0) &= 0xFFBFFFFF;
        *(int *)(g + 0xAC) &= 0xFFBFFFFF;
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 0, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}

/* sn-2.95.3-136 matched TU. */















#include "godhand/vu0.h"

__attribute__((section(".text.func_0025C5D8")))
void func_0025C5D8(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3BFC) + p, *(int *)(p + 0x3C00) + p,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x5F0) = 0x2A;
        *(int *)(s0 + 0x5F4) = 1;
        *(short *)(s0 + 0x56E) = 0x1E;
        (*(unsigned char *)(s0 + 0x2F6))++;
        *(int *)(s0 + 0x16EC) = 0;
    }
        /* fallthrough */
    case 1:
        if ((*(unsigned short *)(s0 + 0x3AC) & 8) == 0) {
            *(int *)(s0 + 0x16D0) |= 0x10000;
            *(float *)(*(char **)(s0 + 0xF0) + 4) =
                *(float *)(*(char **)(s1 + 0xF0) + 4)
                - (*(float *)(s0 + 0x114) - 1.0f) * 0.1f;
        }
        if (*(short *)(s0 + 0x56E) != 0) {
            char *p;
            char *q;

            (*(short *)(s0 + 0x56E))--;
            p = *(char **)(s0 + 0xF0);
            do { } while (0);
            q = s1 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        if ((*(unsigned short *)(s0 + 0x3AC) & 2) != 0
            && *(int *)(s0 + 0x5F4) != 0) {
            char *vt;
            int (*fp)();

            *(int *)(s0 + 0x5F4) = 0;
            vt = *(char **)(s0 + 0x214);
            fp = *(int (**)())(vt + 0xAC);
            fp(s0 + *(short *)(vt + 0xA8), 0x64, s1, 1, 0);
            cHeatSys_AddHeatGage(D_005CB000, 0, 10.0f);
        }
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) <= 0) {
                if ((*(int *)(s0 + 0x1644) & 0x800000) != 0) {
                    *(char *)(s0 + 0x2F4) = 2;
                    *(char *)(s0 + 0x2F5) = 3;
                    *(char *)(s0 + 0x2F6) = 0;
                    *(char *)(s0 + 0x2F7) = 0;
                    return;
                } else {
                    func_0025FE30(s0, 0x1000000, 0);
                    *(char *)(s0 + 0x2F4) = 2;
                    *(char *)(s0 + 0x2F5) = 2;
                    *(char *)(s0 + 0x2F6) = 0;
                    *(char *)(s0 + 0x2F7) = 0;
                }
            } else {
                func_00274FE8(s0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0)
        func_00262750(s0, 0);
}
