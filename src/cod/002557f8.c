/* sn-2.95.3-136 matched TU. */

extern int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_0026ECD0(void *a0, int a1);
extern float DoubleFloatMinusHalf_31D020(void);
extern float Adjust_theta(float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_00262750(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern void func_00262AA8(void *a0);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */










extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);




extern int SetEffectParts(int a0, int a1, void *a2, int a3, float f12,
                           float f13, float f14, float f15, int a4);







#include "godhand/vu0.h"

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_002557F8")))
void func_002557F8(void *a0)
{
    float va[4], vb[4], vc[4], vd[4];
    char *s1 = (char *)a0;
    char *p = *(char **)(s1 + 0xF0);
    int p1, p2;

    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x30);
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    *(int *)(s1 + 0x16D0) |= 0x1000;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb, w;
        *(int *)(s1 + 0x1710) = 0;
        *(float *)(s1 + 0x5C4) = 0.233999997f;
        if (func_002740D8(s1) != 0) {
            if (Forward30F348_31CFE0() & 1) {
                *(char *)(s1 + 0x17C3) = 1;
            } else {
                *(char *)(s1 + 0x17C3) = 0;
            }
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        w = *(int *)(s1 + 0x564);
        w -= 0x205;
        switch (w) {
        default:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x5D0) + b;
                p2 = *(int *)(b + 0x5D4) + b;
            }
            break;
        case 81: case 121:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x2BF4) + b;
                p2 = *(int *)(b + 0x2BF8) + b;
            }
            break;
        case 10: case 11: case 12: case 33: case 107: case 108: case 109: case 110:
        case 111:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xEC4) + b;
                p2 = *(int *)(b + 0xEC8) + b;
            }
            break;
        case 5: case 6: case 7: case 8: case 9: case 19: case 64: case 65:
        case 66: case 74: case 75: case 76: case 115: case 116:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xA84) + b;
                p2 = *(int *)(b + 0xA88) + b;
            }
            break;
        case 91:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xA84) + b;
                p2 = *(int *)(b + 0xA88) + b;
            }
            break;
        case 95:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3300) + b;
                p2 = *(int *)(b + 0x3304) + b;
            }
            break;
        case 96:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3818) + b;
                p2 = *(int *)(b + 0x381C) + b;
            }
            break;
        case 0: case 1: case 2: case 3: case 31: case 60:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x1728) + b;
                p2 = *(int *)(b + 0x172C) + b;
            }
            break;
        case 4: case 26:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x1728) + b;
                p2 = *(int *)(b + 0x172C) + b;
            }
            break;
        case 27: case 28: case 29:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x1D10) + b;
                p2 = *(int *)(b + 0x1D14) + b;
            }
            break;
        case 30:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x2D38) + b;
                p2 = *(int *)(b + 0x2D3C) + b;
            }
            break;
        case 21: case 22: case 23: case 24: case 25: case 32: case 39: case 40:
        case 41: case 42: case 67: case 68: case 71: case 72: case 73: case 77:
        case 85:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x12F0) + b;
                p2 = *(int *)(b + 0x12F4) + b;
            }
            break;
        }
        func_002A8578(s1, p1, p2, 0.0f, 3, gb, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)(Obj0000_Get_Field_424_1595F0(s1) + 4),
                           s1, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0xF6, s1, 0, 0, 0, 0);
        *(float *)(s1 + 0x54C) = 10.0f;
        *(int *)(s1 + 0x16E8) += 0x3E7;
        func_0026ECD0(s1, 0);
        *(int *)(s1 + 0x5F0) = 0;
        {
            char *q = *(char **)(s1 + 0x698);
            if (q != 0) {
                char *r = *(char **)(q + 0x34);
                if (r != 0) {
                    float *d = (float *)(s1 + 0x5D0);
                    float *e;
                    *(int *)(s1 + 0x5F0) = 0xA;
                    e = *(float **)(r + 0xF0);
                    if (d != e) {
                        *(float *)(s1 + 0x5D0) = e[0];
                        d[1] = e[1];
                        d[2] = e[2];
                    }
                }
            }
        }
        *(float *)(s1 + 0x104) =
            *(float *)(s1 + 0x104) + DoubleFloatMinusHalf_31D020() * 0.52359879f;
        *(float *)(s1 + 0x104) = Adjust_theta(*(float *)(s1 + 0x104));
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
    case 1: {
        float z = 0.0f;
        float one;
        char *q;
        *(int *)(s1 + 0x16D0) |= 0x10000;
        q = *(char **)(s1 + 0xF0);
        *(float *)(q + 4) = *(float *)(q + 4) + *(float *)(s1 + 0x5C4);
        *(float *)(s1 + 0x5C4) = *(float *)(s1 + 0x5C4) - 0.0260000005f;
        if (*(float *)(s1 + 0x5C4) <= z) {
            char *t = *(char **)(s1 + 0xF0);
            va[1] = va[1] + 0.5f;
            vb[1] = *(float *)(t + 4) - 10.0f;
            if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
                char *r = *(char **)(s1 + 0xF0);
                if (*(float *)(r + 4) <= vc[1] + 0.100000001f) {
                    *(float *)(r + 4) = vc[1];
                    *(char *)(s1 + 0x2F6) = 2;
                }
            }
        } else {
            char *t;
            VU0_SQC2_VF0(FRAME, 0x60);
            t = *(char **)(s1 + 0xF0);
            vb[1] = *(float *)(t + 4) + 10.0f;
            if (ChkLine(va, vb, vd, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                char *r = *(char **)(s1 + 0xF0);
                float h = vd[1] - 1.5f;
                if (h < *(float *)(r + 4)) {
                    *(float *)(r + 4) = h;
                    *(float *)(s1 + 0x5C4) = z;
                }
            }
        }
        one = 1.0f;
        *(unsigned short *)(s1 + 0x434) |= 8;
        moveMotion(s1);
        *(float *)(s1 + 0x338) = *(float *)(s1 + 0x5A8) * -0.159999996f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        func_00262750(s1, 4);
        break;
    }
    case 2: {
        int gb, w;
        float z;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        w = *(int *)(s1 + 0x564);
        w -= 0x205;
        switch (w) {
        default:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x5D8) + b;
                p2 = *(int *)(b + 0x5DC) + b;
            }
            break;
        case 81: case 121:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x2BFC) + b;
                p2 = *(int *)(b + 0x2C00) + b;
            }
            break;
        case 10: case 11: case 12: case 33: case 107: case 108: case 109: case 110:
        case 111:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xECC) + b;
                p2 = *(int *)(b + 0xED0) + b;
            }
            break;
        case 5: case 6: case 7: case 8: case 9: case 19: case 64: case 65:
        case 66: case 74: case 75: case 76: case 115: case 116:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xA8C) + b;
                p2 = *(int *)(b + 0xA90) + b;
            }
            break;
        case 91:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0xA8C) + b;
                p2 = *(int *)(b + 0xA90) + b;
            }
            break;
        case 95:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3300) + b;
                p2 = *(int *)(b + 0x3304) + b;
            }
            break;
        case 96:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x3818) + b;
                p2 = *(int *)(b + 0x381C) + b;
            }
            break;
        case 0: case 1: case 2: case 3: case 31: case 60:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x1730) + b;
                p2 = *(int *)(b + 0x1734) + b;
            }
            break;
        case 4: case 26:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x1730) + b;
                p2 = *(int *)(b + 0x1734) + b;
            }
            break;
        case 27: case 28: case 29:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x5D8) + b;
                p2 = *(int *)(b + 0x5DC) + b;
            }
            break;
        case 30:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x2D38) + b;
                p2 = *(int *)(b + 0x2D3C) + b;
            }
            break;
        case 21: case 22: case 23: case 24: case 25: case 32: case 39: case 40:
        case 41: case 42: case 67: case 68: case 71: case 72: case 73: case 77:
        case 85:
            {
                int b = *(int *)(s1 + 0x304);
                p1 = *(int *)(b + 0x12F8) + b;
                p2 = *(int *)(b + 0x12FC) + b;
            }
            break;
        }
        z = 0.0f;
        func_002A8578(s1, p1, p2, z, 0, gb, 0);
        SetEffectParts(0x58, 2, s1, 0, z, z, z, 1.0f, -1);
        *(unsigned char *)(s1 + 0x2F6) += 1;
        *(int *)(s1 + 0x5F0) = 0xA;
    }
    case 3: {
        float one;
        char *o;
        int n;
        if (moveMotion(s1) != 0) {
            if (func_00274E98(s1) != 0) {
                return;
            }
            func_002705D8(s1);
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s1, one);
        AddScaledXfmVecToField_F0_14F928(s1, one);
        o = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s1, *(int *)(o + 0xF0),
                                         *(float *)(s1 + 0x5A8) * 0.196349546f);
        n = *(int *)(s1 + 0x5F0);
        if (n != 0) {
            *(int *)(s1 + 0x5F0) = n - 1;
        } else {
            if (func_00274E98(s1) != 0) {
                return;
            }
            func_00262AA8(s1);
        }
        break;
    }
    }
}
