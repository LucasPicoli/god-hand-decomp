/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern unsigned char D_005FEE00[];
extern unsigned char D_00569B70[];
extern int D_00747A24;
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern void func_0012C0F8(void *a0, int a1);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void func_0012C348(void *a0, int a1);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

#include "godhand/vu0.h"
























__attribute__((section(".text.func_00120E00")))
void func_00120E00(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    float buf[4] __attribute__((aligned(16)));

    *(float *)(s0 + 0x54C) = 5.0f;
    *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x10000;
    s1 = *(char **)(s0 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    Obj293_SetByte_53C_2(&D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        float v;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xCF, s0, 0, 0, 0, 0);
        if (s1 != 0)
            func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 30.0f));
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.07f;
        buf[2] = 1.0074f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 0, v);
        cEm00_GetPlMotion(s1, 0x28, v, v);
        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        *(int *)(s0 + 0x15B0) = 0x1E;
        *(short *)(s0 + 0x56E) = 0xF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        if (*(short *)(s0 + 0x56E) != 0 && s1 != 0) {
            char *q = s1 + 0x550;
            char *p;
            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            p = *(char **)(s0 + 0xF0);
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        func_00124EC0(s0);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.07f;
        buf[2] = 0.4842f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x29, v, v);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        func_00124EC0(s0);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 1) && *(int *)(s0 + 0x15B4) != 0) {
            *(int *)(s0 + 0x15B4) = 0;
            if (s1 != 0)
                func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 30.0f));
        } else {
            *(int *)(s0 + 0x15B4) = 1;
        }
        break;
    case 4: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.066f;
        buf[2] = 0.488f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x2B, v, v);
        *(int *)(s0 + 0x15B0) = 0x28;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        func_00124EC0(s0);
        if (*(int *)(s0 + 0x15B0) != 0) {
            int t = *(int *)(s0 + 0x15B0) - 1;
            *(int *)(s0 + 0x15B0) = t;
            if (t <= 0) {
                *(short *)(s0 + 0x54A) = 0;
                OrChildField98AndSelfFieldB0AC_2CA718(&D_005FEE00);
                cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                *(short *)(s0 + 0x434) = *(unsigned short *)(s0 + 0x434) | 8;
                func_0012C348(s0, 2);
                D_00747A24 |= 8;
            }
        }
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6: {
        float v;
        buf[1] = 0.0f;
        v = buf[1];
        buf[0] = -0.066f;
        buf[2] = 0.488f;
        buf[3] = 1.0f;
        func_001299F0(s0, s1, buf, 1, v);
        cEm00_GetPlMotion(s1, 0x2A, v, v);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 7:
        func_00124EC0(s0);
        if (moveMotion(s0)) {
            ClearField15F4Bit1_124F60(s0, 0, 0);
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (func_00123938(s0, 1)) {
            ClearField15F4Bit1_124F60(s0, 0, 0);
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        break;
    default:
        break;
    }
}
