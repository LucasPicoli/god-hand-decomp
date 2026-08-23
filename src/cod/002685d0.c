/* sn-2.95.3-136 matched TU. */

extern int cEmManage_DarkWorldCk(void *a0);
extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern void KillEffect(void *a0, int a1, int a2);
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 candidate. */






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

__attribute__((section(".text.func_002685D0")))
void func_002685D0(void *a0)
{
    char *s0 = (char *)a0;
    S s;
    int s1;

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
    s.f40 = *(float *)(s0 + 0x114);
    s.h72 = 0;
    s.b74 = 0;
    s.i78 = 0;
    s1 = 0;
    if (*(int *)(s0 + 0x564) < 0x216) {
        s1 = (*(int *)(s0 + 0x564) >= 0x214);
    }
    if (cEmManage_DarkWorldCk(&D_005864F0) != 0 || s1 != 0) {
        if ((*(int *)(s0 + 0x16D0) & 0x100) == 0) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x100;
            switch (*(int *)(s0 + 0x564)) {
            case 0x200: default:
                SetEffect(0x58, 0xB, s0, &s, 4, 0xFFFFFFFFu);
                break;
            case 0x205: case 0x206: case 0x207: case 0x224: case 0x241:
                SetEffect(0x58, 0xD, s0, &s, 4, 0xFFFFFFFFu);
                break;
            case 0x20F: case 0x210: case 0x226:
                SetEffect(0x58, 0xE, s0, &s, 4, 0xFFFFFFFFu);
                break;
            case 0x20A: case 0x20C: case 0x20D: case 0x245: case 0x247: case 0x24F:
                SetEffect(0x58, 0xC, s0, &s, 4, 0xFFFFFFFFu);
                break;
            case 0x21A: case 0x21B: case 0x21D: case 0x21E: case 0x225: case 0x22C:
            case 0x22D: case 0x22E: case 0x22F: case 0x248: case 0x249: case 0x24C:
            case 0x24D: case 0x24E: case 0x25A:
                SetEffect(0x58, 0x6D, s0, &s, 4, 0xFFFFFFFFu);
                break;
            case 0x208: case 0x209: case 0x20B: case 0x20E: case 0x211: case 0x213:
            case 0x214: case 0x215: case 0x217: case 0x21C: case 0x21F: case 0x220:
            case 0x221: case 0x222: case 0x223: case 0x23B: case 0x250: case 0x251:
            case 0x252: case 0x256: case 0x260: case 0x264: case 0x265: case 0x26A:
            case 0x270: case 0x271: case 0x272: case 0x273: case 0x274: case 0x275:
            case 0x276: case 0x278: case 0x279: case 0x27E:
                break;
            }
        }
    } else {
        if ((*(int *)(s0 + 0x16D0) & 0x100) != 0) {
            *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) & 0xFFFFFEFF;
            KillEffect(s0, 4, 2);
        }
    }
}
