/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_005864F0[];
extern unsigned char D_00569B70[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void MaxField514_292030(void *a0, int a1);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float f12);
extern void cEm00_GetPlMotion(void *a0, int a1, float f12, float f13);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

#include "godhand/vu0.h"



















__attribute__((section(".text.func_00117600")))
void func_00117600(void *a0)
{
    char *s1 = (char *)a0;
    char *s2;
    float buf[4] __attribute__((aligned(16)));
    float v;
    float d0;
    float d1;

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
        d0 = 1.0f / *(float *)(s2 + 0x110);
        d1 = 1.0f / *(float *)(s2 + 0x118);
        buf[0] = d0 * -0.5842f;
        buf[1] = 0.0f;
        buf[2] = d1 * 0.1376f;
        buf[3] = 1.0f;
        v = buf[1];
        func_001299F0(s1, s2, buf, 0, v);
        cEm00_GetPlMotion(s2, 0x38, v, v);
        cCoreSave_addGameLevelPoint(&D_00569B70, 0x64);
        if (*(short *)(s1 + 0x54A) <= 0)
            *(short *)(s1 + 0x54A) = 1;
        *(short *)(s1 + 0x56E) = 0x1E;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        func_00124EC0(s1);
        if (*(short *)(s1 + 0x56E) != 0 && s2 != 0) {
            char *d;
            char *e = s2 + 0x550;
            *(short *)(s1 + 0x56E) = *(unsigned short *)(s1 + 0x56E) - 1;
            d = *(char **)(s1 + 0xF0);
            VU0_LQC2(4, d, 0);
            VU0_LQC2(5, e, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, d, 0);
        }
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
}
