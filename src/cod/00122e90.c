/* sn-2.95.3-136 matched TU. */

extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_0012C348(void *a0, int a1);
extern void OrChildField98AndSelfFieldB0AC_2CA718(void *a0);
extern void cCoreSave_addGameLevelPoint(void *a0, int a1);
extern unsigned int Forward30F348_31CFE0(void);
extern float capVu0Atan2(float y, float x);
extern float Adjust_theta(float f12);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00124EC0(void *a0);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern unsigned char D_005FEE00[];
extern unsigned char D_00569B70[];
extern int D_00747A24;

/* sn-2.95.3-136 */

















#include "godhand/vu0.h"

__attribute__((section(".text.func_00122E90")))
void func_00122E90(void *a0)
{
    float buf[4];
    char *s1 = (char *)a0;
    int s2;
    int s0;
    float one;

    *(float *)(s1 + 0x54C) = 30.0f;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xD6, s1, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x123, s1, 0, 0, 0, 0);
        func_0012C348(s1, 3);
        OrChildField98AndSelfFieldB0AC_2CA718(D_005FEE00);
        cCoreSave_addGameLevelPoint(D_00569B70, -1000);
        switch (*(unsigned char *)(s1 + 0x2F7)) {
        case 0:
        default:
            switch (Forward30F348_31CFE0() % 5) {
            case 0:
            default:
            {
                int b = *(int *)(s1 + 0x304);
                s2 = *(int *)(b + 0x158) + b;
                s0 = *(int *)(b + 0x15C) + b;
            }
                break;
            case 1:
            {
                int b = *(int *)(s1 + 0x304);
                s2 = *(int *)(b + 0x4FC) + b;
                s0 = *(int *)(b + 0x500) + b;
            }
                break;
            case 2:
            {
                int b = *(int *)(s1 + 0x304);
                s2 = *(int *)(b + 0x164) + b;
                s0 = *(int *)(b + 0x168) + b;
            }
                break;
            case 3:
            {
                int b = *(int *)(s1 + 0x304);
                s2 = *(int *)(b + 0x504) + b;
                s0 = *(int *)(b + 0x508) + b;
            }
                break;
            case 4:
            {
                int b = *(int *)(s1 + 0x304);
                s2 = *(int *)(b + 0x50C) + b;
                s0 = *(int *)(b + 0x510) + b;
            }
                break;
            }
            break;
        case 1:
        {
            int b = *(int *)(s1 + 0x304);
            s2 = *(int *)(b + 0x158) + b;
            s0 = *(int *)(b + 0x15C) + b;
        }
            break;
        case 2:
        {
            int b = *(int *)(s1 + 0x304);
            s2 = *(int *)(b + 0x4FC) + b;
            s0 = *(int *)(b + 0x500) + b;
        }
            break;
        case 3:
        {
            int b = *(int *)(s1 + 0x304);
            s2 = *(int *)(b + 0x514) + b;
            s0 = *(int *)(b + 0x518) + b;
        }
            break;
        case 4:
        {
            int b = *(int *)(s1 + 0x304);
            s2 = *(int *)(b + 0x164) + b;
            s0 = *(int *)(b + 0x168) + b;
        }
            break;
        case 5:
        {
            int b = *(int *)(s1 + 0x304);
            s2 = *(int *)(b + 0x504) + b;
            s0 = *(int *)(b + 0x508) + b;
        }
            break;
        case 6:
        {
            int b = *(int *)(s1 + 0x304);
            s2 = *(int *)(b + 0x50C) + b;
            s0 = *(int *)(b + 0x510) + b;
        }
            break;
        }
        {
            char *p = *(char **)(s1 + 0x678);
            if (p != 0) {
                float th;

                VU0_LQC2(4, p + 0x10, 0);
                VU0_SQC2(4, buf, 0);
                th = capVu0Atan2(buf[0], buf[2]) + 3.14159274f;
                *(float *)(s1 + 0x104) = th;
                *(float *)(s1 + 0x104) = Adjust_theta(th);
            }
        }
        func_002A8578(s1, s2, s0, 0.0f, 2, 0, 0);
        *(int *)(s1 + 0x15B0) = 0x28;
        *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
    case 1:
        func_00124EC0(s1);
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = *(int *)(s1 + 0x15B0) - 1;
        } else {
            D_00747A24 = D_00747A24 | 8;
        }
        if (moveMotion(s1) != 0) {
            D_00747A24 = D_00747A24 | 8;
            *(unsigned char *)(s1 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6) + 1;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        break;
    }
}
