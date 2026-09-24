/* sn-2.95.3-136 matched TU. */

/* func_0011D198 — 0x0011D198, 792 B — sn-2.95.3-136.
 * +0x2F6 phase machine, 0x694 object family; template src/cod/0011c348.c
 * (func_0011C348, jaccard 1.00). */
#include "godhand/vu0.h"

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void Obj293_SetByte_53C_2(void *a0);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_001299F0(void *a0, void *a1, void *a2, int a3, float a4);
extern void cEm00_GetPlMotion(void *a0, int a1, float a2, float a3);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern void func_00124EC0(void *a0);
extern int  moveMotion(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0012C0F8(void *a0, int a1);
extern void func_0012C348(void *a0, int a1);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern int  D_00747A24;
extern int  D_00569B70;
extern char D_00462FC0[];
extern char D_005864F0[];
extern char D_005FEE00[];

__attribute__((section(".text.func_0011D198")))
void func_0011D198(void *a0)
{
    char *s1 = (char *)a0;
    char *s0;
    char *p;
    char *q;

    *(float *)(s1 + 0x54C) = 5.0f;
    *(int *)(s1 + 0x250) |= 0x10000;
    s0 = *(char **)(s1 + 0x694);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    Obj293_SetByte_53C_2(D_005864F0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        float buf[4];
        float z;

        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        buf[1] = 0.0f;
        z = buf[1];
        buf[0] = -0.4165f;
        buf[2] = 1.1225f;
        buf[3] = 1.0f;
        func_001299F0(s1, s0, buf, 0, z);
        cEm00_GetPlMotion(s0, 0x10, z, z);
        *(short *)(s1 + 0x56E) = 0xF;
        *(int *)(s1 + 0x15B0) = 1;
        *(int *)(s1 + 0x15B4) = 1;
        cCoreSave_addGameLevelPoint(&D_00569B70, -0x140);
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    do {
    do {
    case 1:
        if (*(short *)(s1 + 0x56E) == 0 || s0 == 0)
            goto join;
        (*(short *)(s1 + 0x56E))--;
        p = *(char **)(s1 + 0xF0);
    } while (0);
        q = s0 + 0x550;
        VU0_LQC2(4, p, 0);
        VU0_LQC2(5, q, 0);
    } while (0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p, 0);
    join:
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
        if ((*(unsigned short *)(s1 + 0x3AC) & 1) != 0) {
            if (*(int *)(s1 + 0x15B0) != 0) {
                *(int *)(s1 + 0x15B0) = 0;
                if (s0 != 0) {
                    func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 8.0f));
                }
                func_0012C348(s1, 0);
            }
        } else {
            *(int *)(s1 + 0x15B0) = 1;
        }
        if ((*(unsigned short *)(s1 + 0x3AC) & 2) != 0) {
            if (*(int *)(s1 + 0x15B4) != 0) {
                *(int *)(s1 + 0x15B4) = 0;
                if (s0 != 0) {
                    func_0012C0F8(s1, (int)(*(float *)(s0 + 0x76C) * 16.0f));
                }
                if (*(short *)(s1 + 0x54A) <= 0) {
                    char *g = D_005FEE00;

                    *(short *)(s1 + 0x54A) = 0;
                    cSnd_SeCall_2CBA48(g, 0, 0xD6, s1, 0, 0, 0, 0);
                    OrChildField98AndSelfFieldB0AC_2CA718(g);
                    cCoreSave_addGameLevelPoint(&D_00569B70, -0x3E8);
                    *(unsigned short *)(s1 + 0x434) |= 8;
                } else {
                    cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD7, s1, 0, 0, 0, 0);
                }
                func_0012C348(s1, 2);
            }
        } else {
            *(int *)(s1 + 0x15B4) = 1;
        }
        break;
    default:
        break;
    }
}
