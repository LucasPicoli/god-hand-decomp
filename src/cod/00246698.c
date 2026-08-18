/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float DoubleFloatMinusHalf_31D020(void);
extern void AddScaledVecToField_100_14F9F0(void *a0, float s);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float s);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern int Forward30F348_31CFE0(void);
extern void func_002744E0(void *a0);
extern char *CreateObj(int a0, int a1);
extern int cOmWeapon_setParent();
extern void func_001D0340(void *a0);
extern void func_001D0408(void *a0);
extern void func_002705D8(void *a0);
extern int func_00292DC8(void *a0, void *a1, float f);
extern char D_005864F0[];

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"



















__attribute__((section(".text.func_00246698")))
void func_00246698(void *a0)
{
    char *p = (char *)a0;
    int s2v, s1v;
    float buf[7];

    switch (*(unsigned char *)(p + 0x2F6)) {
    case 0: {
        int gb;
        int w;
        float fv;

        *(char *)(p + 0x1864) = 0;
        w = *(int *)(p + 0x564);
        w -= 0x205;
        switch (w) {
        default:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x43C) + b;
                s1v = *(int *)(b + 0x440) + b;
            }
            break;
        case 21: case 22: case 23: case 24: case 25:
        case 32:
        case 39: case 40: case 41: case 42:
        case 67: case 68:
        case 71: case 72: case 73:
        case 77:
        case 85:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1458) + b;
                s1v = *(int *)(b + 0x145C) + b;
            }
            break;
        case 5: case 6:
        case 8: case 9:
        case 19:
        case 64: case 65: case 66:
        case 115: case 116:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xBF8) + b;
                s1v = *(int *)(b + 0xBFC) + b;
            }
            break;
        case 75: case 76:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xB84) + b;
                s1v = *(int *)(b + 0xB88) + b;
            }
            break;
        case 91:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3038) + b;
                s1v = *(int *)(b + 0x303C) + b;
            }
            break;
        case 95:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x326C) + b;
                s1v = *(int *)(b + 0x3270) + b;
            }
            break;
        case 96:
            {
                int b = *(int *)(p + 0x304);
                int t = *(int *)(p + 0x744);
                s2v = *(int *)(b + 0x3724) + b;
                s1v = *(int *)(b + 0x3728) + b;
                if (t != 0) {
                    ForwardAnimParamPairByIndex_27EA50(t, 0);
                }
            }
            break;
        case 7:
        case 74:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xB84) + b;
                s1v = *(int *)(b + 0xB88) + b;
            }
            break;
        case 0: case 2:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x17F8) + b;
                s1v = *(int *)(b + 0x17FC) + b;
            }
            break;
        case 31:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x18DC) + b;
                s1v = *(int *)(b + 0x18E0) + b;
            }
            break;
        case 60:
            if ((Forward30F348_31CFE0() & 1) != 0) {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3B1C) + b;
                s1v = *(int *)(b + 0x3B20) + b;
            } else {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3B24) + b;
                s1v = *(int *)(b + 0x3B28) + b;
            }
            break;
        case 1:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1890) + b;
                s1v = *(int *)(b + 0x1894) + b;
            }
            break;
        case 3:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1EA0) + b;
                s1v = *(int *)(b + 0x1EA4) + b;
            }
            break;
        case 4:
        case 26:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3418) + b;
                s1v = *(int *)(b + 0x341C) + b;
            }
            break;
        case 10: case 11: case 12:
        case 33:
        case 107: case 108: case 109: case 110: case 111:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xF94) + b;
                s1v = *(int *)(b + 0xF98) + b;
            }
            break;
        case 27: case 28: case 29:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x1BC0) + b;
                s1v = *(int *)(b + 0x1BC4) + b;
            }
            break;
        case 30:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x2D38) + b;
                s1v = *(int *)(b + 0x2D3C) + b;
            }
            break;
        case 112: case 113:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x3F4) + b;
                s1v = *(int *)(b + 0x3F8) + b;
            }
            break;
        }
        switch (*(unsigned short *)(p + 0x640) & 7) {
        default:
        case 0:
            fv = 0.0f;
            break;
        case 1:
            fv = 30.0f;
            break;
        case 2:
            fv = 15.0f;
            break;
        case 3:
            fv = 45.0f;
            break;
        case 4:
            fv = 10.0f;
            break;
        case 5:
            fv = 40.0f;
            break;
        case 6:
            fv = 5.0f;
            break;
        case 7:
            fv = 25.0f;
            break;
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p);
        func_002A8578(p, s2v, s1v, fv, 10, gb & 0xFFFF, 0);
        *(int *)(p + 0x5F0) = 1;
        *(float *)(p + 0x600) = DoubleFloatMinusHalf_31D020() * 300.0f + 150.0f;
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    }
    case 1:
        moveMotion(p);
        AddScaledVecToField_100_14F9F0(p, 1.0f);
        AddScaledXfmVecToField_F0_14F928(p, 1.0f);
        if ((*(int *)(p + 0x16D0) & 0x20000000) != 0) {
            if ((*(unsigned short *)(p + 0x3AC) & 3) != 0 && *(int *)(p + 0x5F0) != 0) {
                *(int *)(p + 0x5F0) = 0;
                func_002744E0(p);
            }
            if (func_00294A68(D_005864F0) != 0) {
                *(float *)(p + 0x600) = DoubleFloatMinusHalf_31D020() * 300.0f + 150.0f;
            } else {
                *(float *)(p + 0x600) = *(float *)(p + 0x600) - *(float *)(p + 0x5A8);
                if (*(float *)(p + 0x600) <= 0.0f) {
                    D_005864F0[0x540] = 10;
                    *(char *)(p + 0x2F6) = 2;
                }
            }
        }
        break;
    case 2: {
        int gb;

        *(char *)(p + 0x1864) = 0;
        switch (*(int *)(p + 0x564)) {
        default:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0x504) + b;
                s1v = *(int *)(b + 0x508) + b;
            }
            break;
        case 0x20A:
        case 0x20D: case 0x20E:
        case 0x218:
        case 0x245: case 0x246: case 0x247:
            {
                int b = *(int *)(p + 0x304);
                s2v = *(int *)(b + 0xC54) + b;
                s1v = *(int *)(b + 0xC58) + b;
            }
            break;
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(p);
        func_002A8578(p, s2v, s1v, 0.0f, 10, gb & 0xFFFF, 0);
        *(int *)(p + 0x5F0) = 1;
        *(unsigned char *)(p + 0x2F6) = *(unsigned char *)(p + 0x2F6) + 1;
    }
    case 3:
        D_005864F0[0x540] = 10;
        if (moveMotion(p) != 0) {
            *(char *)(p + 0x2F6) = 0;
        }
        AddScaledVecToField_100_14F9F0(p, 1.0f);
        AddScaledXfmVecToField_F0_14F928(p, 1.0f);
        if ((*(unsigned short *)(p + 0x3AC) & 1) != 0 && *(int *)(p + 0x738) == 0) {
            char *obj = CreateObj(0x3B1, 0xFFFF);
            *(char **)(p + 0x738) = obj;
            if (obj != 0) {
                char *cls;
                int (*fn)(char *);
                short off;
                float *src;
                float *src2;
                float *dst;
                float *d490;
                int *p100;

                VU0_SQC2_VF0(buf, 0x0);
                VU0_SQC2_VF0(buf, 0x10);
                cls = *(char **)(obj + 0x214);
                fn = *(int (**)(char *))(cls + 0x44);
                off = *(short *)(cls + 0x40);
                fn(obj + off);

                dst = *(float **)(*(char **)(p + 0x738) + 0xF0);
                src = *(float **)(p + 0xF0);
                if (dst != src) {
                    dst[0] = src[0];
                    dst[1] = src[1];
                    dst[2] = src[2];
                }
                src2 = *(float **)(p + 0xF0);
                d490 = (float *)(*(char **)(p + 0x738) + 0x490);
                if (d490 != src2) {
                    d490[0] = src2[0];
                    d490[1] = src2[1];
                    d490[2] = src2[2];
                }
                p100 = (int *)(*(char **)(p + 0x738) + 0x100);
                p100[0] = 0;
                p100[1] = 0;
                p100[2] = 0;
                buf[0] = 0.0f;
                buf[1] = -0.3f;
                buf[2] = 0.1f;
                buf[4] = 1.3f;
                buf[5] = 0.0f;
                buf[6] = 0.0f;
                cOmWeapon_setParent(*(int *)(p + 0x738), p, 10, buf, (char *)buf + 0x10);
            }
        }
        if ((*(unsigned short *)(p + 0x3AC) & 2) != 0 && *(int *)(p + 0x738) != 0) {
            func_001D0340(*(void **)(p + 0x738));
            *(int *)(p + 0x738) = 0;
        }
        break;
    }
    if (func_00292DC8(D_005864F0, *(void **)(p + 0xF0), 10.0f) == 0) {
        if (*(int *)(p + 0x738) != 0) {
            func_001D0408(*(void **)(p + 0x738));
            *(int *)(p + 0x738) = 0;
        }
        func_002705D8(p);
    } else if (*(float *)(p + 0x16C0) > 0.0f || *(int *)(p + 0x16EC) > 0) {
        func_002705D8(p);
    }
}
