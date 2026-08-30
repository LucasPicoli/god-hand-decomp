/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int cCoreSave_getGameLevel(void *a0);
extern void func_0026B9E8(void *a0);
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern int SetEffect(int a0, int a1, void *a2, void *a3, int t0, unsigned int t1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern char D_00462FC0[];
extern char D_00569B70[];
extern char D_005FEE00[];

#include "godhand/vu0.h"














typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

typedef struct S {
    float f00;            /* 0x00 */
    float f04;
    float f08;
    float f0C;
    Vec4 v10;             /* 0x10 sqc2 */
    Vec4 v20;             /* 0x20 sqc2 */
    float f30;            /* 0x30 */
    float f34;
    float f38;
    float f3C;
    float f40;            /* 0x40 */
    int i44;
    int i48;
    signed char b4C;      /* 0x4C */
    signed char b4D;
    signed char b4E;
    unsigned char b4F;
    int i50;              /* 0x50 */
    char pad54[0xC];
    char q60[0x10];       /* 0x60 sqc2 */
    short h70;            /* 0x70 */
    short h72;
    signed char b74;      /* 0x74 */
    char pad75[3];
    int i78;              /* 0x78 */
    char pad7C[4];
} S;

__attribute__((section(".text.func_00242880")))
void func_00242880(void *a0)
{
    char *s0 = (char *)a0;
    S fr;
    S *e = &fr;

    e->f00 = 1.0f;
    e->f04 = 1.0f;
    e->f08 = 1.0f;
    e->f0C = 1.0f;
    VU0_SQC2_VF0(&fr, 0x10);
    VU0_SQC2_VF0(&fr, 0x20);
    {
        float *q = &e->f30;
        q[0] = 1.0f;
        q[1] = 1.0f;
        q[2] = 1.0f;
        q[3] = 1.0f;
    }
    e->f40 = 1.0f;
    fr.i44 = 0;
    fr.i48 = 0;
    e->b4C = -1;
    fr.b4D = 0;
    fr.b4E = 0;
    e->b4F = 0xFF;
    fr.i50 = 0;
    VU0_SQC2_VF0(&fr, 0x60);
    e->f40 = *(float *)(s0 + 0x114);
    *(float *)(s0 + 0x54C) = 3.0f;
    fr.h70 = 0;
    fr.h72 = 0;
    fr.b74 = 0;
    fr.i78 = 0;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);

    *(int *)(s0 + 0x16D0) |= 0x10000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x245C) + w,
                      *(int *)(w + 0x2460) + w, 0.0f, 3, 0, 0);
        *(float *)(s0 + 0x600) = 45.0f;
        *(float *)(s0 + 0x604) = 0.053333335f;
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(float *)(s0 + 0x172C) = 450.0f;
            break;
        case 2:
            *(float *)(s0 + 0x172C) = 600.0f;
            break;
        case 3:
            *(float *)(s0 + 0x172C) = 750.0f;
            break;
        case 4:
            *(float *)(s0 + 0x172C) = 750.0f;
            break;
        case 5:
            *(float *)(s0 + 0x172C) = 900.0f;
            break;
        }
        func_0026B9E8(s0);
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x107, s0, 0, 0, 0, 0);
        SetEffect(0x69, 1, s0, &fr, 1, 0xFFFFFFFFU);
        *(int *)(s0 + 0x16D4) |= 0x20;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        float t = *(float *)(s0 + 0x600);
        float *p;
        if (0.0f < t) {
            *(float *)(s0 + 0x600) = t - *(float *)(s0 + 0x5A8);
        } else {
            *(float *)(s0 + 0x604) =
                *(float *)(s0 + 0x604) * (1.0f - *(float *)(s0 + 0x5A8) * 0.1f);
        }
        p = (float *)(*(int *)(s0 + 0xF0) + 4);
        *p = *p + *(float *)(s0 + 0x604) * *(float *)(s0 + 0x5A8);
        if (moveMotion(s0)) {
            float fv = *(float *)(*(int *)(s0 + 0xF0) + 4);
            *(unsigned char *)(s0 + 0x2F5) = 0x7F;
            *(float *)(s0 + 0x1738) = fv;
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    default:
        break;
    }
}
