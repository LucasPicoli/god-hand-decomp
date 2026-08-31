/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern int cCoreSave_getGameLevel(void *a0);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern int cHeatSys_SubHeatGage(void *a0, int a1, float f12);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_00569B70[];
extern char D_005CB000[];

/* sn-2.95.3-136 matched TU. */






















#include "godhand/vu0.h"

__attribute__((section(".text.func_0011C988")))
void func_0011C988(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float v[4] __attribute__((aligned(16)));

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) |= 0x10000;
    s2 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        float z;
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0822f;
        v[2] = 0.0009f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 0, z);
        cEm00_GetPlMotion(s2, 0xB, z, z);
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(float *)(s1 + 0x15C0) = 0.1f;
        case 2:
            *(float *)(s1 + 0x15C0) = 0.2f;
        case 3:
            *(float *)(s1 + 0x15C0) = 0.5f;
        case 4:
            *(float *)(s1 + 0x15C0) = 0.5f;
        case 5:
            *(float *)(s1 + 0x15C0) = 1.0f;
        }
        cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
        *(int *)(s1 + 0x15B0) = 0xA;
        *(short *)(s1 + 0x56E) = 0xF;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        char *q = s2 + 0x550;
        char *p = *(char **)(s1 + 0xF0);
        VU0_LQC2(4, p, 0);
        VU0_LQC2(5, q, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p, 0);
        func_00124EC0(s1);
        if (moveMotion(s1))
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 2: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0822f;
        v[2] = 0.0009f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 0, z);
        cEm00_GetPlMotion(s2, 0xC, z, z);
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(float *)(s1 + 0x15C0) = 0.1f;
        case 2:
            *(float *)(s1 + 0x15C0) = 0.2f;
        case 3:
            *(float *)(s1 + 0x15C0) = 0.5f;
        case 4:
            *(float *)(s1 + 0x15C0) = 0.5f;
        case 5:
            *(float *)(s1 + 0x15C0) = 1.0f;
        }
        *(int *)(s1 + 0x15B0) = 0xA;
        *(short *)(s1 + 0x56E) = 0xF;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        if (*(short *)(s1 + 0x56E) != 0 && s2 != 0) {
            char *p;
            char *q;
            *(short *)(s1 + 0x56E) = *(unsigned short *)(s1 + 0x56E) - 1;
            p = *(char **)(s1 + 0xF0);
            do { } while (0);
            q = s2 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        func_00124EC0(s1);
        moveMotion(s1);
        cHeatSys_SubHeatGage(D_005CB000, 0, *(float *)(s1 + 0x15C0));
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = *(int *)(s1 + 0x15B0) - 1;
        } else {
            *(int *)(s1 + 0x15B0) = 0xA;
            if (s2 != 0) {
                float t = *(float *)(s2 + 0x76C);
                func_0012C0F8(s1, (int)(t + t));
            }
            if (*(short *)(s1 + 0x54A) <= 0)
                *(short *)(s1 + 0x54A) = 1;
        }
        func_0012C348(s1, 4);
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 4: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = 0.1133f;
        v[2] = 0.7251f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 1, z);
        cEm00_GetPlMotion(s2, 0xD, 3.0f, z);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        func_00124EC0(s1);
        *(short *)(s1 + 0x434) = *(unsigned short *)(s1 + 0x434) | 8;
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
    case 6: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.1007f;
        v[2] = 0.3456f;
        v[3] = 1.0f;
        func_001299F0(s1, s2, v, 1, z);
        cEm00_GetPlMotion(s2, 0xE, 3.0f, z);
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 7:
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
    default:
        break;
    }
}
