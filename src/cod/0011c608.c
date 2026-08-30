/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_00569B70[];
extern char D_005FEE00[];
extern int D_00747A24;

#include "godhand/vu0.h"






















__attribute__((section(".text.func_0011C608")))
void func_0011C608(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    float v[4] __attribute__((aligned(16)));

    *(int *)(s0 + 0x250) |= 0x10000;
    *(float *)(s0 + 0x54C) = 5.0f;
    s1 = *(char **)(s0 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0746000037f;
        v[2] = 0.637199998f;
        v[3] = 1.0f;
        func_001299F0(s0, s1, v, 0, z);
        CallWithAndClearField698_12AC28(s0);
        func_0012B928(s0);
        cEm00_GetPlMotion(s1, 7, z, z);
        *(short *)(s0 + 0x56E) = 0xF;
        cCoreSave_addGameLevelPoint(D_00569B70, -0x140);
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
        float z;
        v[1] = 0.0f;
        z = v[1];
        v[0] = -0.0746000037f;
        v[2] = 0.637199998f;
        v[3] = 1.0f;
        func_001299F0(s0, s1, v, 0, z);
        cEm00_GetPlMotion(s1, 8, z, z);
        *(int *)(s0 + 0x15B0) = 5;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        func_00124EC0(s0);
        if (moveMotion(s0))
            *(int *)(s0 + 0x15B0) = 5;
        if (*(int *)(s0 + 0x15B0) != 0) {
            int t = *(int *)(s0 + 0x15B0) - 1;
            *(int *)(s0 + 0x15B0) = t;
            if (t == 0) {
                if (s1 != 0)
                    func_0012C0F8(s0, (int)(*(float *)(s1 + 0x76C) * 10.0f));
                func_0012C348(s0, 0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 4:
        cEm00_GetPlMotion(s1, 9, 3.0f, 0.0f);
        *(int *)(s0 + 0x15B0) = 0x1E;
        OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
        cCoreSave_addGameLevelPoint(D_00569B70, -0x3E8);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    /* fallthrough */
    case 5:
        func_00124EC0(s0);
        *(short *)(s0 + 0x434) = *(unsigned short *)(s0 + 0x434) | 8;
        if (moveMotion(s0))
            D_00747A24 |= 8;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6:
        cEm00_GetPlMotion(s1, 0xA, 3.0f, 0.0f);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
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
        break;
    default:
        break;
    }
}
