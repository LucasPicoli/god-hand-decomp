/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0010A438(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern unsigned int Forward30F348_31CFE0(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern char D_005FEE00[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void cEmManage_SetPlCatched(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void func_00124EC0(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern int D_00747A24;
extern char D_00462FC0[];
extern char D_005864F0[];
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void func_00129578(void *a0);
extern void func_00129630(void *a0);
extern void cSnd_SeStop(void *a0, int a1);

__attribute__((section(".text.func_001142E0")))
void func_001142E0(void *a0)
{
    char *s0 = (char *)a0;
    char *v0;
    float one;

    *(float *)(s0 + 0x54C) = 15.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s0);
        v0 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x18) + (int)v0, *(int *)(v0 + 0x1C) + (int)v0, 0.0f, 3, 0, 0);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s0, 5, 0x17, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s0, 5, 0x17, 0x2A, 0, 0xA);
        *(char *)(s0 + 0x1684) = 1;
        *(unsigned short *)(s0 + 0x3AC) |= 1;
        func_0010A438(s0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        break;
    }
    if (func_00123938(s0, 1) != 0) {
        return;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        *(int *)(s0 + 0x15F4) = (*(int *)(s0 + 0x15F4) & ~0x10) | 0x20;
    }
    *(unsigned short *)(s0 + 0x3AC) |= 0x800;
    *(float *)(s0 + 0x674) = 0.05f;
}

__attribute__((section(".text.func_0011AAA0")))
void func_0011AAA0(void *a0)
{
    char *s1 = (char *)a0;
    float one;
    float f;

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int p1, p2;
        switch (Forward30F348_31CFE0() & 3) {
        case 0:
        default:
            {
            char *v0 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v0 + 0x148) + (int)v0;
            p2 = *(int *)(v0 + 0x14C) + (int)v0;
            }
            break;
        case 1:
            {
            char *v1 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v1 + 0x150) + (int)v1;
            p2 = *(int *)(v1 + 0x154) + (int)v1;
            }
            break;
        case 2:
            {
            char *v2 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v2 + 0x4EC) + (int)v2;
            p2 = *(int *)(v2 + 0x4F0) + (int)v2;
            }
            break;
        case 3:
            {
            char *v3 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v3 + 0x4F4) + (int)v3;
            p2 = *(int *)(v3 + 0x4F8) + (int)v3;
            }
            break;
        }
        func_002A8578(s1, p1, p2, 0.0f, 1, 0, 0);
        if (Forward30F348_31CFE0() & 1) {
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xCF, s1, 0, 0, 0, 0);
        } else {
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD0, s1, 0, 0, 0, 0);
        }
        func_0012C348(s1, 1);
        ClearField15F4Bit1_124F60(s1, 0, 0);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(s1) != 0) {
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        f = *(float *)(s1 + 0x54C);
        break;
    default:
        f = *(float *)(s1 + 0x54C);
        break;
    }
    if (f <= 1.0f) {
        *(unsigned short *)(s1 + 0x3AC) |= 0x40;
    }
    func_00123938(s1, 1);
}

#include "godhand/vu0.h"




















__attribute__((section(".text.func_001209A0")))
void func_001209A0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    char *p;
    char *q;

    *(float *)(s0 + 0x54C) = 5.0f;
    *(int *)(s0 + 0x250) |= 0x10000;
    s1 = *(char **)(s0 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    cEmManage_SetPlCatched(D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        float buf[4];
        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        if (s1 != 0) {
            func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 50.0f));
        }
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        buf[1] = 0.0f;
        buf[0] = 0.0631f;
        buf[2] = 1.1214f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, 3.14159274f);
        cEm00_GetPlMotion(s1, 0x21, 0.0f, 0.0f);
        *(int *)(s0 + 0x15B0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)(s0 + 0x56E) == 0 || s1 == 0)
            goto join;
        (*(short *)(s0 + 0x56E))--;
        p = *(char **)(s0 + 0xF0);
        q = s1 + 0x550;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) <= 0) {
                D_00747A24 |= 8;
            } else {
                ClearField15F4Bit1_124F60(s0, 1, 0);
                *(char *)(s0 + 0x2F4) = 0;
                *(char *)(s0 + 0x2F5) = 0;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
    if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0) {
        if (*(int *)(s0 + 0x15B0) != 0) {
            func_0012C348(s0, 2);
            *(int *)(s0 + 0x15B0) = 0;
        }
    }
}

__attribute__((section(".text.func_00111210")))
void func_00111210(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    if (*(unsigned char *)(s1 + 0x2F6) != 0 &&
        *(unsigned char *)(s1 + 0x649) == 0 &&
        func_0010B2E8(s1, 1) != 0) {
        *(char *)(s1 + 0x649) = 1;
        cCoreSave_shiftGodItem(&D_00569B70);
        cCoreSave_shiftGodItem(&D_00569B70);
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x190, 0xF, 0x1E, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x190, 0xF, 0x1E, 0, 0x123);
        t = *(int *)(s1 + 0x304);
        *(char *)(s1 + 0x1684) = 1;
        func_002A8578(s1, *(int *)(t + 0x19C) + t, *(int *)(t + 0x1A0) + t,
                      0.0f, 3, 0, 0);
        func_00129578(s1);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
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
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
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
