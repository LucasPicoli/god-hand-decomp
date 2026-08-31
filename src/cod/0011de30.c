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






















#include "godhand/vu0.h"

__attribute__((section(".text.func_0011DE30")))
void func_0011DE30(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;

    *(float *)(s0 + 0x54C) = 5.0f;
    s1 = *(char **)(s0 + 0x694);
    *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x10000;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        buf[0] = 0.1473f;
        buf[1] = 0.0f;
        buf[2] = 1.406f;
        buf[3] = 1.0f;
        z = buf[1];
        func_001299F0(s0, s1, buf, 0, z);
        cEm00_GetPlMotion(s1, 0x15, z, z);
        *(int *)(s0 + 0x15B0) = 1;
        *(int *)(s0 + 0x15B4) = 0;
        *(short *)(s0 + 0x56E) = 0x3C;
        cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)(s0 + 0x56E) != 0 && s1 != 0) {
            char *p;
            char *q;

            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            p = *(char **)(s0 + 0xF0);
            do { } while (0);
            q = s1 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) > 0) {
                ClearField15F4Bit1_124F60(s0, 0, 0);
                *(char *)(s0 + 0x2F4) = 1;
                *(char *)(s0 + 0x2F5) = 4;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            } else {
                D_00747A24 |= 8;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(int *)(s0 + 0x15B4) > 0)
            *(int *)(s0 + 0x15B4) = *(int *)(s0 + 0x15B4) - 1;
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) != 0
            && *(int *)(s0 + 0x15B4) <= 0) {
            *(int *)(s0 + 0x15B4) = 5;
            if (s1 != 0) {
                func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 10.0f));
                if (*(short *)(s0 + 0x54A) < 2)
                    *(short *)(s0 + 0x54A) = 1;
            }
            func_0012C348(s0, 2);
        }
        if ((*(unsigned short *)(s0 + 0x3AC) & 2) != 0
            && *(int *)(s0 + 0x15B0) != 0) {
            *(int *)(s0 + 0x15B0) = 0;
            cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
            if (s1 != 0)
                func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 20.0f));
            if (*(short *)(s0 + 0x54A) <= 0) {
                *(short *)(s0 + 0x54A) = 0;
                OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
                cCoreSave_addGameLevelPoint(D_00569B70, -0x3E8);
                *(short *)(s0 + 0x434) = *(unsigned short *)(s0 + 0x434) | 8;
            }
            func_0012C348(s0, 2);
        }
        break;
    case 2:
        cEm00_GetPlMotion(s1, 0x16, 0.0f, 0.0f);
        cCoreSave_addGameLevelPoint(D_00569B70, 0x64);
        (*(unsigned char *)(s0 + 0x2F6))++;
        /* fallthrough */
    case 3:
        func_00124EC0(s0);
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) <= 0)
                *(short *)(s0 + 0x54A) = 1;
            ClearField15F4Bit1_124F60(s0, 1, 0);
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}
