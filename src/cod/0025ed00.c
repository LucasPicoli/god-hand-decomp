/* sn-2.95.3-136 matched TU. */

extern unsigned int Forward30F348_31CFE0(void);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern int Obj0000_Get_Field_424_1595F0(void *a0);
extern int moveMotion(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern unsigned char D_005FEE00[];

/* sn-2.95.3-136 matched TU. */












#include "godhand/vu0.h"

typedef struct {
    float f00;          /* 0x00 */
    float f04;          /* 0x04 */
    float f08;          /* 0x08 */
    float f0C;          /* 0x0C */
    char q10[0x10];     /* 0x10 sqc2 */
    char q20[0x10];     /* 0x20 sqc2 */
    float f30;          /* 0x30 */
    float f34;          /* 0x34 */
    float f38;          /* 0x38 */
    float f3C;          /* 0x3C */
    float f40;          /* 0x40 */
    int i44;            /* 0x44 */
    int i48;            /* 0x48 */
    signed char b4C;    /* 0x4C */
    signed char b4D;    /* 0x4D */
    signed char b4E;    /* 0x4E */
    unsigned char b4F;  /* 0x4F */
    int i50;            /* 0x50 */
    char pad54[0xC];    /* 0x54 */
    char q60[0x10];     /* 0x60 sqc2 */
    short h70;          /* 0x70 */
    short h72;          /* 0x72 */
    signed char b74;    /* 0x74 */
    char pad75[3];      /* 0x75 */
    int i78;            /* 0x78 */
} S;

__attribute__((section(".text.func_0025ED00")))
void func_0025ED00(void *a0)
{
    char *s3 = (char *)a0;
    S s;
    int s2;
    int s1;
    int nb;

    s.f00 = 1.0f;
    s.f04 = 1.0f;
    s.f08 = 1.0f;
    s.f0C = 1.0f;
    VU0_SQC2_VF0(&s, 0x10);
    VU0_SQC2_VF0(&s, 0x20);
    {
        float *q = &s.f30;
        s.f30 = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    s.f40 = 1.0f;
    s.b4C = -1;
    s.b4F = 0xFF;
    s.i44 = 0;
    s.i48 = 0;
    s.b4D = 0;
    s.b4E = 0;
    s.i50 = 0;
    VU0_SQC2_VF0(&s, 0x60);
    s.h70 = 0;
    s.f40 = *(float *)(s3 + 0x114);
    s.h72 = 0;
    s.b74 = 0;
    s.i78 = 0;
    switch (*(unsigned char *)(s3 + 0x2F6)) {
    case 0:
        nb = Obj0000_Get_Byte_17C3_NZ_2_276468(s3) & 0xFFFF;
        switch (*(int *)(s3 + 0x564)) {
        default:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                if ((Forward30F348_31CFE0() & 1) != 0) {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x380) + b;
                    s1 = *(int *)(b + 0x384) + b;
                } else {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x388) + b;
                    s1 = *(int *)(b + 0x38C) + b;
                }
            } else {
                if ((Forward30F348_31CFE0() & 1) != 0) {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x370) + b;
                    s1 = *(int *)(b + 0x374) + b;
                } else {
                    int b = *(int *)(s3 + 0x304);
                    s2 = *(int *)(b + 0x378) + b;
                    s1 = *(int *)(b + 0x37C) + b;
                }
            }
            break;
        case 0x20A:
        case 0x20B:
        case 0x20C:
        case 0x20D:
        case 0x20E:
        case 0x218:
        case 0x245:
        case 0x246:
        case 0x247:
        case 0x24F:
        case 0x278:
        case 0x279:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB44) + b;
                s1 = *(int *)(b + 0xB48) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB3C) + b;
                s1 = *(int *)(b + 0xB40) + b;
            }
            break;
        case 0x250:
        case 0x251:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB44) + b;
                s1 = *(int *)(b + 0xB48) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB3C) + b;
                s1 = *(int *)(b + 0xB40) + b;
            }
            cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s3) + 0x23),
                               s3, 0, 0, 0, 0);
            break;
        case 0x260:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB44) + b;
                s1 = *(int *)(b + 0xB48) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xB3C) + b;
                s1 = *(int *)(b + 0xB40) + b;
            }
            break;
        case 0x264:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x326C) + b;
                s1 = *(int *)(b + 0x3270) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x326C) + b;
                s1 = *(int *)(b + 0x3270) + b;
            }
            break;
        case 0x265:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3818) + b;
                s1 = *(int *)(b + 0x381C) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x3818) + b;
                s1 = *(int *)(b + 0x381C) + b;
            }
            break;
        case 0x205:
        case 0x206:
        case 0x207:
        case 0x208:
        case 0x224:
        case 0x241:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x17B8) + b;
                s1 = *(int *)(b + 0x17BC) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x17B0) + b;
                s1 = *(int *)(b + 0x17B4) + b;
            }
            break;
        case 0x209:
        case 0x21F:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x17B8) + b;
                s1 = *(int *)(b + 0x17BC) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x17B0) + b;
                s1 = *(int *)(b + 0x17B4) + b;
            }
            break;
        case 0x20F:
        case 0x210:
        case 0x211:
        case 0x226:
        case 0x270:
        case 0x271:
        case 0x272:
        case 0x273:
        case 0x274:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xF6C) + b;
                s1 = *(int *)(b + 0xF70) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0xF64) + b;
                s1 = *(int *)(b + 0xF68) + b;
            }
            break;
        case 0x21A:
        case 0x21B:
        case 0x21C:
        case 0x21D:
        case 0x21E:
        case 0x225:
        case 0x22C:
        case 0x22D:
        case 0x22E:
        case 0x22F:
        case 0x248:
        case 0x249:
        case 0x24C:
        case 0x24D:
        case 0x24E:
        case 0x252:
        case 0x25A:
            if ((*(unsigned short *)(s3 + 0x3AC) & 0x200) != 0) {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1398) + b;
                s1 = *(int *)(b + 0x139C) + b;
            } else {
                int b = *(int *)(s3 + 0x304);
                s2 = *(int *)(b + 0x1390) + b;
                s1 = *(int *)(b + 0x1394) + b;
            }
            break;
        }
        func_002A8578(s3, s2, s1, 0.0f, 5, nb, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                           (short)(Obj0000_Get_Field_424_1595F0(s3) + 8),
                           s3, 0, 0, 0, 0);
        switch (*(int *)(s3 + 0x564)) {
        case 0x207:
        case 0x240:
        case 0x249:
        case 0x24A:
        case 0x24E:
            SetEffect(0x58, 0x9F, s3, &s, -1, 0xFFFFFFFF);
            cSnd_SeCall_2CBA48(&D_005FEE00, 1,
                               (short)(Obj0000_Get_Field_424_1595F0(s3) + 0x22),
                               s3, 0, 0, 0, 0);
            break;
        }
        *(unsigned char *)(s3 + 0x2F6) += 1;
        /* fallthrough */
    case 1:
        if (moveMotion(s3) != 0) {
            if ((*(int *)(s3 + 0x1644) & 0x800000) != 0) {
                *(signed char *)(s3 + 0x2F4) = 2;
                *(signed char *)(s3 + 0x2F5) = 3;
                *(signed char *)(s3 + 0x2F6) = 0;
                *(signed char *)(s3 + 0x2F7) = 0;
            } else {
                *(signed char *)(s3 + 0x2F4) = 2;
                *(signed char *)(s3 + 0x2F5) = 2;
                *(signed char *)(s3 + 0x2F6) = 0;
                *(signed char *)(s3 + 0x2F7) = 0;
            }
        } else {
            AddScaledVecToField_100_14F9F0(s3, 1.0f);
            AddScaledXfmVecToField_F0_14F928(s3, 1.0f);
        }
        break;
    }
}
