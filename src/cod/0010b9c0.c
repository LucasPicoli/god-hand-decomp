/* sn-2.95.3-136 matched TU. */

extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern float DoubleFloatMinusHalf_31D020(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern unsigned int Forward30F348_31CFE0(void);
extern void func_0012C348(void *a0, int a1);
extern char D_00462FC0[];
extern char D_005FEE00[];

#include "godhand/vu0.h"














__attribute__((section(".text.func_0010B9C0")))
void func_0010B9C0(void *a0)
{
    float fr[4];
    char *s0 = (char *)a0;

    *(float *)(s0 + 0x54C) = 5.0f;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(int *)(s0 + 0x15F4) |= 0x2000;
    *(float *)(s0 + 0x5A8) = 1.0f;
    SetField444SignedByFlag434_158288(s0, 1.0f);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int p = *(int *)(s0 + 0x304);

        func_002A8578(s0, *(int *)(p + 0x28) + p, *(int *)(p + 0x2C) + p,
                      0.0f, 5, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        moveMotion(s0);
        break;
    case 2: {
        int f1, f2;

        switch (*(unsigned char *)(s0 + 0x2F7)) {
        case 1:
            {
                int p = *(int *)(s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        case 2:
            {
                int p = *(int *)(s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        case 3:
            {
                int p = *(int *)(s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        default:
        case 0:
            {
                int p = *(int *)(s0 + 0x304);

                f1 = *(int *)(p + 0x94C) + p;
                f2 = *(int *)(p + 0x950) + p;
            }
            break;
        }
        func_002A8578(s0, f1, f2, 0.0f, 3, 0, 0);
        *(short *)(s0 + 0x568) = 1;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        if (moveMotion(s0) != 0)
            *(unsigned char *)(s0 + 0x2F6) = 0;
        if ((*(unsigned short *)(s0 + 0x3AC) & 3) &&
            *(short *)(s0 + 0x568) != 0) {
            float k;

            VU0_SQC2_VF0(fr, 0);
            k = 0.1f;
            fr[0] = DoubleFloatMinusHalf_31D020() * k + -0.2f;
            fr[1] = DoubleFloatMinusHalf_31D020() * k + 1.5f;
            fr[2] = DoubleFloatMinusHalf_31D020() * k + 0.5f;
            sceVu0ApplyMatrix(fr, s0 + 0x80, fr);
            *(short *)(s0 + 0x568) = 0;
            SetEffectPos(0, 0x40, 0, fr, -1, 1.0f);
            cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x111, s0, 0, 0, 0, 0);
        }
        break;
    case 4: {
        int f1, f2;

        switch (Forward30F348_31CFE0() % 3) {
        default:
        case 0:
            {
                int p = *(int *)(s0 + 0x304);

                f1 = *(int *)(p + 0x140) + p;
                f2 = *(int *)(p + 0x144) + p;
            }
            break;
        case 1:
            {
                int p = *(int *)(s0 + 0x304);

                f1 = *(int *)(p + 0x4DC) + p;
                f2 = *(int *)(p + 0x4E0) + p;
            }
            break;
        case 2:
            {
                int p = *(int *)(s0 + 0x304);

                f1 = *(int *)(p + 0x4E4) + p;
                f2 = *(int *)(p + 0x4E8) + p;
            }
            break;
        }
        func_002A8578(s0, f1, f2, 0.0f, 1, 0, 0);
        cSnd_SeCall_2CBA48(D_005FEE00, 0, 0xCE, s0, 0, 0, 0, 0);
        func_0012C348(s0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        if (moveMotion(s0) != 0)
            *(unsigned char *)(s0 + 0x2F6) = 0;
        break;
    default:
        break;
    }
}
