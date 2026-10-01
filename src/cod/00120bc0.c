/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f12);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f12);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern unsigned int D_00747A24;
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_005FEE00[];
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5,
                              int a6, int a7);
__attribute__((section(".text.func_00120BC0")))
void func_00120BC0(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;
    float buf[4];
    *(float *)(s1 + 0x54C) = 5.0f;
    s0 = *(char **)(s1 + 0x694);
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        float z;
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        if (s0 != 0)
            func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 30.0f));
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        buf[1] = 0.0f;
        buf[0] = 0.0273f;
        buf[2] = 1.369f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x22, z, z);
        if (*(short *)(s1 + 0x54A) <= 0) {
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD6, s1, 0, 0, 0, 0);
            func_0012C348(s1, 2);
        } else {
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD7, s1, 0, 0, 0, 0);
            func_0012C348(s1, 2);
        }
        *(int *)(s1 + 0x15B0) = 1;
        *(short *)(s1 + 0x56E) = 0xF;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) <= 0) {
                D_00747A24 |= 8;
            } else {
                ClearField15F4Bit1_124F60(s1, 0, 0);
                *(char *)(s1 + 0x2F4) = 1;
                *(char *)(s1 + 0x2F5) = 4;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 0;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
}
