/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */
#include "godhand/vu0.h"


extern int D_005FEE00;
extern int cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int t0, int t1, int t2, int t3);
extern float DoubleFloatMinusHalf_31D020(void);
extern void func_0014FA60(void *a0, float f12, float f13);

__attribute__((section(".text.func_001BBC08")))
void func_001BBC08(char *s0)
{
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x568) = 0xE;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 1:
        (*(float **)(s0 + 0xF0))[1] = (*(float **)(s0 + 0xF0))[1] - 0.100000001f;
        if (*(short *)(s0 + 0x568) != 0) {
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
        } else {
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 2:
        *(short *)(s0 + 0x568) = 0x1E;
        *(short *)(s0 + 0x56A) = 0xF;
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x110, s0, 0, 0, 0, 0);
        *(float *)(s0 + 0x330) = DoubleFloatMinusHalf_31D020() * 0.200000003f;
        *(float *)(s0 + 0x334) = 0.100000001f;
        *(float *)(s0 + 0x338) = -0.100000001f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        /* fallthrough */
    case 3:
        func_0014FA60(s0, *(float *)(s0 + 0x104), 1.0f);
        {
        float k = 0.0199999996f;
        *(float *)(s0 + 0x100) = *(float *)(s0 + 0x100) + -0.17453292f;
        VU0_LQC2(4, s0, 0x330);
        VU0_LOAD_SCALAR(5, k);
        VU0_VSUBX_XYZ(4, 4, 5);
        VU0_SQC2(4, s0, 0x330);
        }
        if (*(short *)(s0 + 0x568) < 0xF) {
            *(float *)(s0 + 0x24C) = *(float *)(s0 + 0x24C) - 0.100000001f;
            *(int *)(s0 + 0x250) |= 0x10;
            if (*(float *)(s0 + 0x24C) <= 0.150000006f) {
                *(float *)(s0 + 0x24C) = 0.0f;
                *(int *)(s0 + 0x250) |= 2;
                *(unsigned int *)(s0 + 0x250) &= 0xFFFFFFEF;
            }
        }
        if (*(short *)(s0 + 0x56A) != 0) {
            *(short *)(s0 + 0x56A) = *(unsigned short *)(s0 + 0x56A) - 1;
            if (*(short *)(s0 + 0x56A) == 0) {
                cSnd_SeCall_2CBA48(&D_005FEE00, 0, 0x32, s0, 0, 0, 0, 0);
            }
        }
        if (*(short *)(s0 + 0x568) != 0) {
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
        } else {
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F4) = 1;
        }
        break;
    }
}
