/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern unsigned char D_00569B70[];
extern int D_007474A8;
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxField514_292030(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern float Adjust_theta(float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_002DB7A8(void);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void SetField444SignedByFlag434_158288(void *a0, float f12);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

#include "godhand/vu0.h"























__attribute__((section(".text.func_00119BF0")))
void func_00119BF0(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float buf[4] __attribute__((aligned(16)));

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 0x10000;
    s2 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(&D_005864F0);
    MaxField514_292030(&D_005864F0, 2);
    *(int *)(s1 + 0x15F4) = *(int *)(s1 + 0x15F4) | 0x80000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        *(short *)(s1 + 0x5E0) = 0;
        *(short *)(s1 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s1);
        if (s2 != 0) {
            VU0_SQC2_VF0(buf, 0);
            buf[0] = -0.01001f;
            buf[2] = 0.86998f;
            buf[1] = 0.0f;
            sceVu0ApplyMatrix(buf, s2 + 0x80, buf);
            *(float *)(*(int *)(s1 + 0xF0) + 0x0) = buf[0];
            *(float *)(*(int *)(s1 + 0xF0) + 0x8) = buf[2];
            *(float *)(s1 + 0x104) = *(float *)(s2 + 0x104) + 3.14159274f;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        cEm00_GetPlMotion(s2, 0x4F, 0.0f, 0.0f);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        *(short *)(s1 + 0x56A) = 1;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (moveMotion(s1))
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 2:
        cEm00_GetPlMotion(s2, 0x50, 0.0f, 0.0f);
        *(short *)(s1 + 0x568) = 0x5A;
        *(int *)(s1 + 0x15B0) = 0;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        *(int *)(s1 + 0x15B4) = 0;
        *(int *)(s1 + 0x15B8) = 0;
    /* fallthrough */
    case 3:
        func_002DB7A8();
        if (*(short *)(s1 + 0x568) != 0)
            *(short *)(s1 + 0x568) = *(unsigned short *)(s1 + 0x568) - 1;
        if (*(int *)(s1 + 0x15B8) != 0)
            *(int *)(s1 + 0x15B8) = *(int *)(s1 + 0x15B8) - 1;
        *(int *)(s1 + 0x15B0) = *(int *)(s1 + 0x15B0) + 1;
        if ((D_007474A8 & 0xF0) != 0) {
            int lim;
            switch (*(int *)(s1 + 0x15B4)) {
            default:
            case 0:
                lim = 0x3E7;
                break;
            case 1:
                lim = 6;
                break;
            case 2:
                lim = 5;
                break;
            case 3:
                lim = 4;
                break;
            case 4:
                lim = 3;
                break;
            case 5:
                lim = 2;
                break;
            }
            if (*(int *)(s1 + 0x15B0) < lim)
                *(int *)(s1 + 0x15B4) = *(int *)(s1 + 0x15B4) + 1;
            if (lim < *(int *)(s1 + 0x15B0))
                *(int *)(s1 + 0x15B4) = *(int *)(s1 + 0x15B4) - 1;
            if (*(int *)(s1 + 0x15B4) < 0)
                *(int *)(s1 + 0x15B4) = 0;
            if (*(int *)(s1 + 0x15B4) >= 5)
                *(int *)(s1 + 0x15B4) = 4;
            *(int *)(s1 + 0x15B0) = 0;
            *(int *)(s1 + 0x15B8) = 0xA;
        } else if (*(int *)(s1 + 0x15B8) <= 0) {
            int t;
            *(int *)(s1 + 0x15B8) = 5;
            t = *(int *)(s1 + 0x15B4) - 1;
            *(int *)(s1 + 0x15B4) = t;
            if (t < 0)
                *(int *)(s1 + 0x15B4) = 0;
        }
        switch (*(int *)(s1 + 0x15B4)) {
        default:
        case 0:
            *(float *)(s1 + 0x5A8) = 0.7f;
            break;
        case 1:
            *(float *)(s1 + 0x5A8) = 1.0f;
            break;
        case 2:
            *(float *)(s1 + 0x5A8) = 1.5f;
            break;
        case 3:
            *(float *)(s1 + 0x5A8) = 2.0f;
            break;
        case 4:
            *(float *)(s1 + 0x5A8) = 2.5f;
            break;
        }
        SetField444SignedByFlag434_158288(s1, *(float *)(s1 + 0x5A8));
        func_00124EC0(s1);
        if (moveMotion(s1) && *(short *)(s1 + 0x568) <= 0)
            *(unsigned char *)(s1 + 0x2F6) = 4;
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    case 4:
        cEm00_GetPlMotion(s2, 0x51, 0.0f, 0.0f);
        *(short *)(s1 + 0x56E) = 0xF;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    /* fallthrough */
    case 5:
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
