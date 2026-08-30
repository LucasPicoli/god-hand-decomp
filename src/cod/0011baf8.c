/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern unsigned char D_00569B70[];
extern unsigned char D_005FEE00[];
extern int D_00747A24;
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void func_0012C348(void *a0, int a1);

/* sn-2.95.3-136 matched TU. */
























#include "godhand/vu0.h"

__attribute__((section(".text.func_0011BAF8")))
void func_0011BAF8(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;
    float buf[4] __attribute__((aligned(16)));
    float v;

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    s0 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(&D_005864F0);

    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, s1, 0, 0, 0, 0);
        buf[0] = -0.167f;
        buf[1] = 0.0f;
        buf[2] = 1.0176f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s0, buf, 0, v);
        cEm00_GetPlMotion(s0, 0, v, v);
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(int *)(s1 + 0x15B0) = 0x1E;
        *(short *)(s1 + 0x56E) = 0xF;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        if (*(short *)(s1 + 0x56E) != 0 && s0 != 0) {
            char *d;
            char *e = s0 + 0x550;
            *(short *)(s1 + 0x56E) = *(unsigned short *)(s1 + 0x56E) - 1;
            d = *(char **)(s1 + 0xF0);
            VU0_LQC2(4, d, 0);
            VU0_LQC2(5, e, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, d, 0);
        }
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 2:
        cEm00_GetPlMotion(s0, 1, 3.0f, 0.0f);
        *(int *)(s1 + 0x15B0) = 0x19;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 3:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            if (*(short *)(s1 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s1, 0, 0);
                *(unsigned char *)(s1 + 0x2F4) = 1;
                *(unsigned char *)(s1 + 0x2F5) = 4;
                *(unsigned char *)(s1 + 0x2F6) = 0;
                *(unsigned char *)(s1 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = *(int *)(s1 + 0x15B0) - 1;
            if (*(int *)(s1 + 0x15B0) == 0) {
                char *s2 = (char *)&D_00569B70;
                cCoreSave_addGameLevelPoint(s2, -0x140);
                if (s0 != 0) {
                    func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 30.0f));
                }
                if (*(short *)(s1 + 0x54A) <= 0) {
                    char *g = (char *)&D_005FEE00;
                    *(short *)(s1 + 0x54A) = 0;
                    cSnd_SeCall_2CBA48(g, 0, 0xD6, s1, 0, 0, 0, 0);
                    OrChildField98AndSelfFieldB0AC_2CA718(g);
                    cCoreSave_addGameLevelPoint(s2, -0x3E8);
                    *(unsigned short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
                } else {
                    cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xD7, s1, 0, 0, 0, 0);
                }
                func_0012C348(s1, 2);
            }
        }
        break;
    case 4:
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        cEm00_GetPlMotion(s0, 2, 3.0f, 0.0f);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 5:
        func_00124EC0(s1);
        if (moveMotion(s1) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (func_00123938(s1, 1) != 0 || (*(unsigned short *)(s1 + 0x3AC) & 0x20) != 0) {
            ClearField15F4Bit1_124F60(s1, 0, 0);
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        break;
    }
}
