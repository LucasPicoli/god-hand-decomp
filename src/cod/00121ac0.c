/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f12);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f12);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern unsigned int D_00747A24;
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_00569B70[];
extern char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */
















extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5,
                              int a6, int a7);







#include "godhand/vu0.h"

__attribute__((section(".text.func_00121AC0")))
void func_00121AC0(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;
    float buf[4];

    *(float *)(s1 + 0x54C) = 5.0f;
    s0 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        float z;

        buf[1] = 0.0f;
        buf[0] = 0.124f;
        buf[2] = 0.871f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x30, z, z);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(int *)(s1 + 0x15B0) = 1;
        *(short *)(s1 + 0x56E) = 0xF;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)(s1 + 0x56E) != 0 && s0 != 0) {
            char *p;
            char *q;

            *(short *)(s1 + 0x56E) = *(unsigned short *)(s1 + 0x56E) - 1;
            p = *(char **)(s1 + 0xF0);
            do { } while (0);
            q = s0 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s1, 0, 0);
                *(char *)(s1 + 0x2F4) = 1;
                *(char *)(s1 + 0x2F5) = 4;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0
            && *(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
            if (s0 != 0)
                func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 30.0f));
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(short *)(s1 + 0x54A) = 0;
                cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD6, s1, 0, 0, 0, 0);
                OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
                cCoreSave_addGameLevelPoint(D_00569B70, -0x3E8);
                *(short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
            } else {
                cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD7, s1, 0, 0, 0, 0);
            }
            func_0012C348(s1, 2);
        }
        break;
    case 2:
    {
        float z;

        buf[1] = 0.0f;
        buf[0] = -0.016f;
        buf[2] = 0.208f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x31, z, z);
        cCoreSave_addGameLevelPoint(D_00569B70, 0x64);
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(char *)(s1 + 0x2F4) = 0;
            *(char *)(s1 + 0x2F5) = 0;
            *(char *)(s1 + 0x2F6) = 0;
            *(char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (func_00123938(s1, 1) != 0)
            ClearField15F4Bit1_124F60(s1, 0, 0);
        break;
    default:
        break;
    }
}
