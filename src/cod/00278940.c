/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float f12);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

#include "godhand/vu0.h"









__attribute__((section(".text.func_00278940")))
void func_00278940(void *a0)
{
    float buf[8];
    char *s0 = (char *)a0;

    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int p = *(int *)(s0 + 0x304);
        int k;
        unsigned char m;

        func_002A8578(s0, *(int *)(p + 0x24) + p, *(int *)(p + 0x28) + p,
                      0.0f, 0, 0, 0);
        k = *(unsigned char *)(s0 + 0x2FC) & 7;
        *(float *)(s0 + 0x580) = 0.0f;
        *(float *)(s0 + 0x600) = 1.0f;
        *(float *)(s0 + 0x584) = 0.1f;
        *(float *)(s0 + 0x588) = 0.1f;
        switch (k) {
        default:
        case 0:
            *(float *)(s0 + 0x604) = 16.0f;
            break;
        case 1:
            *(float *)(s0 + 0x604) = 12.0f;
            break;
        case 2:
            *(float *)(s0 + 0x604) = 18.0f;
            break;
        case 3:
            *(float *)(s0 + 0x604) = 14.0f;
            break;
        case 4:
            *(float *)(s0 + 0x604) = 11.0f;
            break;
        case 5:
            *(float *)(s0 + 0x604) = 13.0f;
            break;
        case 6:
            *(float *)(s0 + 0x604) = 17.0f;
            break;
        case 7:
            *(float *)(s0 + 0x604) = 15.0f;
            break;
        }
        m = *(unsigned char *)(s0 + 0x2FC) % 3;
        switch (m) {
        default:
        case 0:
            *(float *)(s0 + 0x608) = 0.012271846644580364f;
            break;
        case 1:
            *(float *)(s0 + 0x608) = 0.01602853462100029f;
            break;
        case 2:
            *(float *)(s0 + 0x608) = 0.02094395086169243f;
            break;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        char *q;
        char *r;
        float k;
        float *dp;

        if (900.0f < *(float *)(s0 + 0x618)) {
            char *o = Obj0000_Get_D_00747A94_2DB6B0();

            AddScaledDeltaToField_104_2A7498(s0, *(int *)(o + 0xF0),
                                             *(float *)(s0 + 0x608) *
                                             *(float *)(s0 + 0x5A8));
        }
        SetField444SignedByFlag434_158288(s0, *(float *)(s0 + 0x5A8) *
                                              *(float *)(s0 + 0x600));
        moveMotion(s0);
        {
            char *o = Obj0000_Get_D_00747A94_2DB6B0();
            float d = *(float *)(*(int *)(s0 + 0xF0) + 4) -
                      *(float *)(*(int *)(o + 0xF0) + 4);

            if (*(float *)(s0 + 0x604) < d)
                *(float *)(s0 + 0x584) = 0.0f;
            else
                *(float *)(s0 + 0x584) = 0.1f;
        }
        k = *(float *)(s0 + 0x5A8);
        q = (char *)buf + 0x10;
        k = k * *(float *)(s0 + 0x600);
        r = s0 + 0x580;
        VU0_LQC2(4, r, 0);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, buf, 0x10);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, buf, 0x10);
        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, buf, 0);
        dp = (float *)(s0 + 0x330);
        if (dp != buf) {
            float t0, t1, t2;

            t0 = buf[0];
            t1 = buf[1];
            dp[0] = t0;
            *(volatile float *)&dp[1] = t1;
            t2 = *(volatile float *)&buf[2];
            dp[2] = t2;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    default:
        break;
    }
}
