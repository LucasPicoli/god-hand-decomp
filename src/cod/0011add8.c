/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005FEE00[];
extern unsigned char D_007474A0[];
extern unsigned int Forward30F348_31CFE0(void);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern void func_0012C348(void *a0, int a1);
extern float capVu0Atan2(float y, float x);
extern float Adjust_theta(float f12);
extern void CallWithAndClearField698_12AC28(void *a0);
extern void func_0012B928(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_0010A438(void *a0);

/* sn-2.95.3-136 matched TU. */





















#include "godhand/vu0.h"

__attribute__((section(".text.func_0011ADD8")))
void func_0011ADD8(void *a0)
{
    char *s1 = (char *)a0;
    float buf[4] __attribute__((aligned(16)));
    int s3v, s2v;

    *(float *)(s1 + 0x54C) = 15.0f;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        char *g;
        char *p;

        switch (*(unsigned char *)(s1 + 0x2F7)) {
        case 0: default:
            switch (Forward30F348_31CFE0() % 5) {
            case 0: default: {
                char *v0 = *(char **)(s1 + 0x304);
                s3v = *(int *)(v0 + 0x158) + (int)v0;
                s2v = *(int *)(v0 + 0x15C) + (int)v0;
                break;
            }
            case 1: {
                char *v0 = *(char **)(s1 + 0x304);
                s3v = *(int *)(v0 + 0x4FC) + (int)v0;
                s2v = *(int *)(v0 + 0x500) + (int)v0;
                break;
            }
            case 2: {
                char *v0 = *(char **)(s1 + 0x304);
                s3v = *(int *)(v0 + 0x164) + (int)v0;
                s2v = *(int *)(v0 + 0x168) + (int)v0;
                break;
            }
            case 3: {
                char *v0 = *(char **)(s1 + 0x304);
                s3v = *(int *)(v0 + 0x504) + (int)v0;
                s2v = *(int *)(v0 + 0x508) + (int)v0;
                break;
            }
            case 4: {
                char *v0 = *(char **)(s1 + 0x304);
                s3v = *(int *)(v0 + 0x50C) + (int)v0;
                s2v = *(int *)(v0 + 0x510) + (int)v0;
                break;
            }
            }
            break;
        case 1: {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x158) + (int)v0;
            s2v = *(int *)(v0 + 0x15C) + (int)v0;
            break;
        }
        case 2: {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x4FC) + (int)v0;
            s2v = *(int *)(v0 + 0x500) + (int)v0;
            break;
        }
        case 3: {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x514) + (int)v0;
            s2v = *(int *)(v0 + 0x518) + (int)v0;
            break;
        }
        case 4: {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x164) + (int)v0;
            s2v = *(int *)(v0 + 0x168) + (int)v0;
            break;
        }
        case 5: {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x504) + (int)v0;
            s2v = *(int *)(v0 + 0x508) + (int)v0;
            break;
        }
        case 6: {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x50C) + (int)v0;
            s2v = *(int *)(v0 + 0x510) + (int)v0;
            break;
        }
        }
        g = (char *)&D_005FEE00;
        cSnd_SeCall_2CBA48(g, 0, 0xD7, s1, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(g, 0, 0x123, s1, 0, 0, 0, 0);
        ClearField15F4Bit1_124F60(s1, 0, 0);
        func_0012C348(s1, 2);
        p = *(char **)(s1 + 0x678);
        if (p != 0) {
            VU0_LQC2(4, p + 0x10, 0);
            VU0_SQC2(4, buf, 0);
            *(float *)(s1 + 0x104) = capVu0Atan2(buf[0], buf[2]) + 3.1415927f;
            *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        }
        CallWithAndClearField698_12AC28(s1);
        func_0012B928(s1);
        func_002A8578(s1, s3v, s2v, 0.0f, 2, 0, 0);
        *(int *)(s1 + 0x15B0) = 0;
        *(int *)(s1 + 0x15B4) = 0;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        char *g;

        if (*(int *)(s1 + 0x15B4) != 0) {
            *(int *)(s1 + 0x15B4) -= 1;
        }
        g = (char *)&D_007474A0;
        if ((*(int *)(g + 8) & 0xF0) != 0) {
            *(int *)(s1 + 0x15B4) = 0xA;
        }
        if (moveMotion(s1) != 0) {
            if (*(int *)(s1 + 0x15B4) > 0) {
                *(unsigned char *)(s1 + 0x2F5) = 4;
                *(unsigned char *)(s1 + 0x2F4) = 1;
                *(unsigned char *)(s1 + 0x2F6) = 0;
                *(unsigned char *)(s1 + 0x2F7) = 1;
            } else {
                *(unsigned char *)(s1 + 0x2F4) = 1;
                *(unsigned char *)(s1 + 0x2F5) = 4;
                *(unsigned char *)(s1 + 0x2F6) = 0;
                *(unsigned char *)(s1 + 0x2F7) = 0;
            }
            break;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x20) != 0) {
            *(int *)(s1 + 0x15B0) = 1;
            if (*(unsigned char *)(s1 + 0x61E) != 0 || (*(int *)(g + 8) & 0xF0) != 0) {
                *(unsigned char *)(s1 + 0x2F7) = 1;
                *(float *)(s1 + 0x54C) = 5.0f;
                *(unsigned char *)(s1 + 0x2F5) = 6;
                *(unsigned char *)(s1 + 0x2F6) = 0;
                *(unsigned char *)(s1 + 0x2F4) = 0;
            }
            break;
        }
        if (*(int *)(s1 + 0x15B0) != 0) {
            *(int *)(s1 + 0x15B0) = 0;
            func_0012C0F8(s1, *(int *)(s1 + 0x160C));
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(short *)(s1 + 0x54A) = 1;
            }
            *(int *)(s1 + 0x160C) = 0;
        }
        break;
    }
    case 2: {
        if (*(int *)(s1 + 0x15B4) != 0) {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x51C) + (int)v0;
            s2v = *(int *)(v0 + 0x520) + (int)v0;
            Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(s1, 0xA, 0x17, 0x2A, 0, 0xA);
            Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(s1, 0xA, 0x17, 0x2A, 0, 0xA);
            *(char *)(s1 + 0x1684) = 0;
        } else {
            char *v0 = *(char **)(s1 + 0x304);
            s3v = *(int *)(v0 + 0x174) + (int)v0;
            s2v = *(int *)(v0 + 0x178) + (int)v0;
        }
        func_002A8578(s1, s3v, s2v, 0.0f, 0xA, 0, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F4) = 0;
            *(unsigned char *)(s1 + 0x2F5) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 0;
            *(unsigned char *)(s1 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (func_00123938(s1, 1) == 0) {
            func_0010A438(s1);
        }
        break;
    }
}
