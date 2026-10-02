/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern unsigned int Forward30F348_31CFE0(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_0012C348(void *a0, int a1);
extern void func_00126770(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern char D_005FEE00[];
extern void cEmManage_SetSlotWait(void *a0, int a1);
extern void cEmManage_SetPlCatched(void *a0);
extern void cEmManage_SetBigHitEffWait(void *a0, int a1);
extern void cEmManage_SetSpeedRate(void *a0, float a1);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00129578(void *a0);
extern void func_00124EC0(void *a0);
extern void func_00129630(void *a0);
extern void func_0010A438(void *a0);
extern void func_0012BC00(void *a0, int a1, int a2);
extern char D_005864F0[];
extern void cSnd_SeStop(void *a0, int a1);
extern int D_00747A0C;
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern unsigned char D_00462FC0[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);

__attribute__((section(".text.func_0011B900")))
void func_0011B900(void *a0)
{
    char *s1 = (char *)a0;
    float one;

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
        func_00126770(s1);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) <= 0) {
                goto st;
            }
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    default:
        break;
    }
    if (*(short *)(s1 + 0x54A) <= 0) {
        if (*(unsigned short *)(s1 + 0x3AC) & 0x10) {
        st:
            *(char *)(s1 + 0x2F7) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F4) = 2;
        }
    } else {
        func_00123938(s1, 1);
    }
}

__attribute__((section(".text.func_001127F8")))
void func_001127F8(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int t;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x8C, 0x1E, 0x25, 0, 0x123);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x8C, 0x1E, 0x25, 0, 0x123);
        *(char *)(s1 + 0x1684) = 1;
        cCoreSave_shiftGodItem(&D_00569B70);
        func_00129578(s1);
        t = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(t + 0x4A4) + t, *(int *)(t + 0x4A8) + t,
                      0.0f, 3, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        *(int *)(s1 + 0x15B0) = 1;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            ClearField15F4Bit1_124F60(s1, 1, 0);
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
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0 && *(int *)(s1 + 0x15B0) != 0) {
        *(int *)(s1 + 0x15B0) = 0;
        func_0012BC00(s1, 0x2E, 0);
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}

__attribute__((section(".text.func_00112A48")))
void func_00112A48(void *a0)
{
    char *s1 = (char *)a0;

    *(float *)(s1 + 0x54C) = 30.0f;
    cEmManage_SetSlotWait(D_005864F0, 2);
    cEmManage_SetPlCatched(D_005864F0);
    cEmManage_SetBigHitEffWait(D_005864F0, 2);
    *(int *)(s1 + 0x15F4) |= 0x200;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int p1, p2;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        *(char *)(s1 + 0x1684) = 1;
        func_00129578(s1);
        cCoreSave_shiftGodItem(&D_00569B70);
        if (*(unsigned char *)(s1 + 0x2F7) != 0) {
            char *v0 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v0 + 0x450) + (int)v0;
            p2 = *(int *)(v0 + 0x458) + (int)v0;
        } else {
            char *v1 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v1 + 0x450) + (int)v1;
            p2 = *(int *)(v1 + 0x454) + (int)v1;
        }
        func_002A8578(s1, p1, p2, 0.0f, 3, 0, 0);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        *(int *)(s1 + 0x15B0) = 1;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            ClearField15F4Bit1_124F60(s1, 1, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0 && *(int *)(s1 + 0x15B0) != 0) {
        *(int *)(s1 + 0x15B0) = 0;
        if (*(unsigned char *)(s1 + 0x2F7) != 0) {
            func_0012BC00(s1, 0x2D, 0);
            func_0012BC00(s1, 0x2D, 1);
            func_0012BC00(s1, 0x2D, 2);
        } else {
            func_0012BC00(s1, 0x2C, 0);
        }
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
    }
    if (func_00123938(s1, 1) != 0) {
        func_00129630(s1);
        ClearField15F4Bit1_124F60(s1, 1, 0);
    } else {
        *(unsigned short *)(s1 + 0x3AC) |= 0x800;
        *(float *)(s1 + 0x674) = 0.05f;
    }
}

struct VtEnt { short delta; short index; void *pfn; };

__attribute__((section(".text.func_00111A20")))
void func_00111A20(void *a0)
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
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int p1, p2;

        Obj0000_Clear_Fields_640_648_124E58(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        if (*(unsigned char *)(s1 + 0x2F7) != 0) {
            char *v0;
            if (D_00747A0C != 0) {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x64, 0x15, 0x21, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x32, 0x15, 0x21, 0, 0x123);
            } else {
                Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x3C, 0x15, 0x21, 0, 0x123);
                Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x3C, 0x15, 0x21, 0, 0x123);
            }
            v0 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v0 + 0x20C) + (int)v0;
            p2 = *(int *)(v0 + 0x214) + (int)v0;
        } else {
            char *v1;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0x23, 0x15, 0x21, 0, 0x123);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0x23, 0x15, 0x21, 0, 0x123);
            v1 = *(char **)(s1 + 0x304);
            p1 = *(int *)(v1 + 0x20C) + (int)v1;
            p2 = *(int *)(v1 + 0x210) + (int)v1;
        }
        *(char *)(s1 + 0x1684) = 1;
        func_002A8578(s1, p1, p2, 0.0f, 3, 0, 0);
        func_00129578(s1);
        cEmManage_SetSpeedRate(D_005864F0, 0.1f);
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
            Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
        }
        if (moveMotion(s1) != 0) {
            func_00129630(s1);
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
            char *e = *(char **)(s1 + 0x640);
            if (e != 0) {
                struct VtEnt *vt = *(struct VtEnt **)(e + 0x214);
                float *pos = *(float **)(s1 + 0xF0);
                void *r = ((void *(*)(void *))vt[13].pfn)(e + vt[13].delta);
                if (capVu0MagnitudeSqXZ(pos, r) < 1.21000004f) {
                    *(int *)(s1 + 0x330) = 0;
                    *(int *)(s1 + 0x338) = 0;
                }
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if ((*(unsigned short *)(s1 + 0x3AC) & 0x100) != 0) {
        cEmManage_SetSpeedRate(D_005864F0, 0.05f);
    }
    if ((*(unsigned short *)(s1 + 0x3AC) & 3) != 0) {
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
