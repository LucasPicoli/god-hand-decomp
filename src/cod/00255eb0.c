/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"

extern unsigned int irand(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int GetSeqSEBase(void *a0);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);


extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void cGameObj_SetTgtTurn(void *a0, void *a1, float a2);
extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);
extern unsigned char D_005FEE00[];
extern unsigned char D_005CB010;
extern unsigned char D_00747A2C[];

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_00255EB0")))
void func_00255EB0(void *a0)
{
    float va[4], vb[4], vc[4], vd[4];
    char *s2 = (char *)a0;
    char *p = *(char **)(s2 + 0xF0);
    int ma;
    int mb;
    int gb;

    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x30);
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    *(int *)(s2 + 0x16D0) |= 0x10000;
    switch (*(unsigned char *)(s2 + 0x2F6)) {
    case 0:
        if (*(int *)(s2 + 0x6EC) != 0) {
            switch (*(int *)(s2 + 0x564)) {
            case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
            case 0x22C: case 0x22D: case 0x22E: case 0x22F: case 0x23A:
            case 0x24A: case 0x24B: case 0x25A:
                break;
            default:
                if ((irand() & 3) == 0) {
                    ReleaseField6ECByTag564_26B1E8(s2);
                }
                break;
            }
        }
        *(float *)(s2 + 0x5C4) = -0.39000002f;
        *(int *)(s2 + 0x1710) = 0;
        if (func_002740D8(s2) != 0) {
            if ((irand() & 1) != 0) {
                *(char *)(s2 + 0x17C3) = 1;
            } else {
                *(char *)(s2 + 0x17C3) = 0;
            }
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        switch (*(int *)(s2 + 0x564)) {
        default:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x628) + b;
            mb = *(int *)(b + 0x62C) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0xF74) + b;
            mb = *(int *)(b + 0xF78) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x278: case 0x279:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0xB4C) + b;
            mb = *(int *)(b + 0xB50) + b;
        }
            break;
        case 0x250: case 0x251:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0xB4C) + b;
            mb = *(int *)(b + 0xB50) + b;
            cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)(GetSeqSEBase(s2) + 0x23), s2, 0, 0, 0, 0);
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0xB4C) + b;
            mb = *(int *)(b + 0xB50) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x326C) + b;
            mb = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x3818) + b;
            mb = *(int *)(b + 0x381C) + b;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        case 0x241:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x17C0) + b;
            mb = *(int *)(b + 0x17C4) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x17C0) + b;
            mb = *(int *)(b + 0x17C4) + b;
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x628) + b;
            mb = *(int *)(b + 0x62C) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x2E34) + b;
            mb = *(int *)(b + 0x2E38) + b;
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x22F:
        case 0x248: case 0x249: case 0x24C: case 0x24D: case 0x24E:
        case 0x252: case 0x25A:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x13A0) + b;
            mb = *(int *)(b + 0x13A4) + b;
        }
            break;
        }
        func_002A8578(s2, ma, mb, 0.0f, 3, gb, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 1, (short)GetSeqSEBase(s2), s2, 0, 0, 0, 0);
        *(int *)(s2 + 0x5F0) = 0;
        {
            char *q = *(char **)(s2 + 0x698);

            if (q != 0) {
                char *r = *(char **)(q + 0x34);

                if (r != 0) {
                    float *d = (float *)(s2 + 0x5D0);
                    float *e;

                    *(int *)(s2 + 0x5F0) = 0xA;
                    e = *(float **)(r + 0xF0);
                    if (d != e) {
                        *(float *)(s2 + 0x5D0) = e[0];
                        d[1] = e[1];
                        d[2] = e[2];
                    }
                }
            }
        }
        *(int *)(s2 + 0x5F4) = 0;
        *(unsigned char *)(s2 + 0x2F6) += 1;
        /* fallthrough */
    case 1:
    {
        int c = *(int *)(s2 + 0x5F0);
        float one;
        char *q;

        if (c != 0) {
            *(int *)(s2 + 0x5F0) = c - 1;
            cGameObj_SetTgtTurn(s2, s2 + 0x5D0, *(float *)(s2 + 0x5A8) * 0.3926991f);
        }
        *(float *)(*(char **)(s2 + 0xF0) + 4) = *(float *)(*(char **)(s2 + 0xF0) + 4) + *(float *)(s2 + 0x5C4) * *(float *)(s2 + 0x5A8);
        q = *(char **)(s2 + 0xF0);
        *(float *)(s2 + 0x5C4) = *(float *)(s2 + 0x5C4) - *(float *)(s2 + 0x5A8) * 0.013f;
        va[1] = va[1] + 0.5f;
        vb[1] = *(float *)(q + 4) - 10.0f;
        if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
            char *r = *(char **)(s2 + 0xF0);

            if (*(float *)(r + 4) <= vc[1] + 0.01f) {
                *(float *)(r + 4) = vc[1];
                *(int *)(s2 + 0x5F4) |= 2;
            }
        }
        *(unsigned short *)(s2 + 0x434) |= 8;
        if (moveMotion(s2) != 0) {
            *(int *)(s2 + 0x5F4) |= 1;
        }
        one = 1.0f;
        cObjBase_addNullSpeed_Rotation(s2, one);
        cObjBase_addNullSpeed(s2, one);
        if (*(int *)(s2 + 0x5F4) == 3) {
            *(unsigned char *)(s2 + 0x2F6) += 1;
        }
        break;
    }
    case 2: {
        float v = 0.156f;

        *(int *)(s2 + 0x1710) = 0;
        if (*(unsigned char *)(s2 + 0x2F7) != 0) {
            v = 0.208f;
        }
        *(volatile float *)(s2 + 0x5C4) = v;
        switch (*(volatile int *)(s2 + 0x564)) {
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
            *(float *)(s2 + 0x5C4) = *(float *)(s2 + 0x5C4) * 1.1f;
            break;
        case 0x250: case 0x251:
        {
            char *pad = (char *)D_00747A2C;

            if ((*(int *)(pad + 0x10) & 0x8000) != 0) {
                goto padck;
            }
            if ((*(int *)(pad + 0x10) & 0x4000) != 0) {
            padck:
                if (*(unsigned short *)(pad + 0x24) == 0x45) {
                    *(float *)(s2 + 0x5C4) = 0.1092f;
                }
            }
        }
            if (D_005CB010 == 0) {
                *(float *)(s2 + 0x5C4) = *(float *)(s2 + 0x5C4) * 0.8f;
            }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x260: case 0x264: case 0x265: case 0x278: case 0x279:
            if (D_005CB010 == 0) {
                *(float *)(s2 + 0x5C4) = *(float *)(s2 + 0x5C4) * 0.8f;
            }
            break;
        default:
            break;
        }
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
        switch (*(int *)(s2 + 0x564)) {
        default:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x630) + b;
            mb = *(int *)(b + 0x634) + b;
        }
            break;
        case 0x20F: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0xF7C) + b;
            mb = *(int *)(b + 0xF80) + b;
        }
            break;
        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
        case 0x250: case 0x251: case 0x278: case 0x279:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0xB54) + b;
            mb = *(int *)(b + 0xB58) + b;
        }
            break;
        case 0x260:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0xB54) + b;
            mb = *(int *)(b + 0xB58) + b;
        }
            break;
        case 0x264:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x326C) + b;
            mb = *(int *)(b + 0x3270) + b;
        }
            break;
        case 0x265:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x3818) + b;
            mb = *(int *)(b + 0x381C) + b;
        }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x224:
        case 0x241:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x17C8) + b;
            mb = *(int *)(b + 0x17CC) + b;
        }
            break;
        case 0x209: case 0x21F:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x17C8) + b;
            mb = *(int *)(b + 0x17CC) + b;
        }
            break;
        case 0x220: case 0x221: case 0x222:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x630) + b;
            mb = *(int *)(b + 0x634) + b;
        }
            break;
        case 0x223:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x2EA4) + b;
            mb = *(int *)(b + 0x2EA8) + b;
        }
            break;
        case 0x21A: case 0x21B: case 0x21C: case 0x21D: case 0x21E:
        case 0x225: case 0x22C: case 0x22D: case 0x22E: case 0x248:
        case 0x249: case 0x24C: case 0x24D: case 0x24E: case 0x252:
        {
            int b = *(int *)(s2 + 0x304);
            ma = *(int *)(b + 0x13A8) + b;
            mb = *(int *)(b + 0x13AC) + b;
        }
            break;
        }
        func_002A8578(s2, ma, mb, 0.0f, 0, gb, 0);
        *(unsigned char *)(s2 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
    {
        int c = *(int *)(s2 + 0x5F0);

        if (c != 0) {
            *(int *)(s2 + 0x5F0) = c - 1;
            cGameObj_SetTgtTurn(s2, s2 + 0x5D0, *(float *)(s2 + 0x5A8) * 0.3926991f);
        }
        if (*(unsigned short *)(s2 + 0x3AC) & 4) {
            char *q;
            float vy;

            q = *(char **)(s2 + 0xF0);
            *(float *)(q + 4) = *(float *)(q + 4) + *(float *)(s2 + 0x5C4) * *(float *)(s2 + 0x5A8);
            vy = *(float *)(s2 + 0x5C4);
            if (vy <= 0.0f) {
                *(float *)(s2 + 0x5C4) = vy - *(float *)(s2 + 0x5A8) * 0.0078000003f;
            } else {
                *(float *)(s2 + 0x5C4) = vy - *(float *)(s2 + 0x5A8) * 0.013f;
            }
            if (*(float *)(s2 + 0x5C4) <= 0.0f) {
                char *t = *(char **)(s2 + 0xF0);

                va[1] = va[1] + 0.5f;
                vb[1] = *(float *)(t + 4) - 10.0f;
                if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    char *r = *(char **)(s2 + 0xF0);

                    if (*(float *)(r + 4) <= vc[1] + 0.01f) {
                        *(float *)(r + 4) = vc[1];
                        *(unsigned char *)(s2 + 0x2F4) = 1;
                        *(unsigned char *)(s2 + 0x2F5) = 8;
                        *(unsigned char *)(s2 + 0x2F6) = 2;
                        *(unsigned char *)(s2 + 0x2F7) = 0;
                        switch (*(int *)(s2 + 0x564)) {
                        case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
                        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24F:
                        case 0x250: case 0x251: case 0x260: case 0x264: case 0x265:
                        case 0x278: case 0x279:
                            switch (cCoreSave_getGameLevel(&D_00569B70)) {
                            case 2: case 3: case 4:
                                if (irand() % 3 != 0) {
                                    break;
                                }
                                /* fallthrough */
                            case 5:
                                if (*(short *)(s2 + 0x54A) > 0) {
                                    if (func_0026F1D8(s2) == 0) {
                                        *(unsigned char *)(s2 + 0x2F4) = 1;
                                        *(unsigned char *)(s2 + 0x2F5) = 8;
                                        *(unsigned char *)(s2 + 0x2F6) = 4;
                                        *(unsigned char *)(s2 + 0x2F7) = 0;
                                    }
                                }
                                break;
                            case 1:
                            default:
                                break;
                            }
                            break;
                        default:
                            break;
                        }
                    }
                }
            } else {
                char *t;

                VU0_SQC2_VF0(FRAME, 0x60);
                t = *(char **)(s2 + 0xF0);
                vb[1] = *(float *)(t + 4) + 10.0f;
                if (ChkLine(va, vb, vd, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                    char *r = *(char **)(s2 + 0xF0);
                    float h = vd[1] - 1.5f;

                    if (h < *(float *)(r + 4)) {
                        *(float *)(r + 4) = h;
                        *(float *)(s2 + 0x5C4) = 0.0f;
                    }
                }
            }
        }
        *(unsigned short *)(s2 + 0x434) |= 8;
        moveMotion(s2);
        cObjBase_addNullSpeed_Rotation(s2, 1.0f);
        cObjBase_addNullSpeed(s2, 1.0f);
        break;
    }
    }
}
