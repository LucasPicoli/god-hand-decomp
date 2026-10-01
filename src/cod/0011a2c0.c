/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern unsigned char D_005FEE00[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxField514_292030(void *a0, int a1);

extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0010A438(void *a0);

extern void SetField548AndGlobals_292F38(void *a0, float a1);

__attribute__((section(".text.func_0011A2C0")))
void func_0011A2C0(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;

    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    *(float *)(s1 + 0x54C) = 5.0f;
    s2 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(&D_005864F0);
    MaxField514_292030(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x200;
    if (func_0010B2E8(s1, 0) != 0) {
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, s1, 0, 0, 0, 0);
    }
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[0] = 0.0f;
        buf[1] = 0.0f;
        buf[2] = 1.7999999523162842f;
        buf[3] = 1.0f;
        v = buf[0];
        func_001299F0(s1, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x53, v, v);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 5, 0, 0x2A, 0, 0xA);
        Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 5, 0, 0x2A, 0, 0xA);
        *(char *)(s1 + 0x1684) = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1)) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_0010A438(s1);
    if (func_00123938(s1, 1)) {
        ClearField15F4Bit1_124F60(s1, 0, 0);
    } else if (*(unsigned short *)(s1 + 0x3AC) & 0x100) {
        SetField548AndGlobals_292F38(&D_005864F0, 0.1f);
    }
}
