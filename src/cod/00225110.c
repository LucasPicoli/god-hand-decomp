/* sn-2.95.3-136 matched TU. */

extern void CheckSlotsShort2FEAndSetByte1864_262A10(void *a0);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void func_002A8578(void *a0, int a1, int a2, int a3, float a4, int a5, int a6);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, int a1, float a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern int Obj293_IsByteSet_53D(void *a0);
extern int Obj293_IsByteSet_53C(void *a0);
extern void func_00262750(void *a0, int a1);
extern void func_002705D8(void *a0);
extern void func_00260B30(void *a0);
extern unsigned char D_005864F0[];

/* sn-2.95.3-136 matched TU. */










extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);







#include "godhand/vu0.h"

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_00225110")))
void func_00225110(void *a0)
{
    float va[4], vb[4], vc[4], vd[4], ve[4];
    char *s1 = (char *)a0;
    char *p = *(char **)(s1 + 0xF0);

    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x30);
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, FRAME, 0x40);
    VU0_SQC2_VF0(FRAME, 0x50);
    *(char *)(s1 + 0x186A) = 2;
    *(int *)(s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(s1);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb;
        char *v0;
        *(char *)(s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        StoreMotionParamsBoth_2609A8(s1, 0x28, 0xA, 0x41, 0, 0xF5);
        v0 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v0 + 0x974) + (int)v0,
                      *(int *)(v0 + 0x978) + (int)v0, 0xA, 0.0f, gb, 0);
        *(int *)(s1 + 0x5FC) = 0;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        char *o = (char *)Obj0000_Get_D_00747A94_2DB6B0();
        AddScaledDeltaToField_104_2A7498(s1, *(int *)(o + 0xF0),
                                         *(float *)(s1 + 0x5A8) * 0.19634955f);
        if (moveMotion(s1) != 0) {
            *(unsigned char *)(s1 + 0x2F6) += 1;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    case 2: {
        int gb;
        char *v1;
        float z = 0.0f;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v1 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v1 + 0x97C) + (int)v1,
                      *(int *)(v1 + 0x980) + (int)v1, 2, z, gb, 0);
        *(float *)(s1 + 0x580) = z;
        *(float *)(s1 + 0x588) = 0.2f;
        *(float *)(s1 + 0x584) = *(float *)(s1 + 0x170C) * 15.0f;
        *(float *)(s1 + 0x600) = z;
        *(int *)(s1 + 0x5F0) = 4;
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3: {
        float dt;
        float *dp;
        char *ep;

        *(int *)(s1 + 0x16D0) |= 0x10000;
        moveMotion(s1);
        dt = *(float *)(s1 + 0x5A8);
        ep = (char *)ve;
        VU0_LQC2(4, (char *)s1 + 0x580, 0);
        VU0_SQC2(4, FRAME, 0x70);
        VU0_LQC2(4, FRAME, 0x70);
        VU0_LOAD_SCALAR(5, dt);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, FRAME, 0x70);
        VU0_LQC2(4, ep, 0);
        VU0_SQC2(4, FRAME, 0x60);
        dp = (float *)(s1 + 0x330);
        if (dp != vd) {
            float t0, t1, t2;
            t0 = vd[0];
            t1 = vd[1];
            dp[0] = t0;
            *(volatile float *)&dp[1] = t1;
            t2 = *(volatile float *)&vd[2];
            dp[2] = t2;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (*(float *)(s1 + 0x584) <= 0.0f) {
            char *q = *(char **)(s1 + 0xF0);
            va[1] = va[1] + 0.5f;
            vb[1] = *(float *)(q + 4) - 10.0f;
            if (ChkLine(va, vb, vc, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1) == 1) {
                char *r = *(char **)(s1 + 0xF0);
                if (*(float *)(r + 4) <= vc[1] + 0.01f) {
                    int n;
                    *(float *)(r + 4) = vc[1];
                    *(float *)(s1 + 0x600) = 3.0f;
                    *(float *)(s1 + 0x584) = *(float *)(s1 + 0x170C) * 15.0f;
                    n = *(int *)(s1 + 0x5F0) - 1;
                    *(int *)(s1 + 0x5F0) = n;
                    if (n <= 0) {
                        *(char *)(s1 + 0x2F6) = 4;
                    }
                }
            }
        } else {
            char *q;
            VU0_SQC2_VF0(FRAME, 0x60);
            q = *(char **)(s1 + 0xF0);
            vb[1] = *(float *)(q + 4) + 10.0f;
            if (ChkLine(va, vb, vd, 0, 7, 0, 0, 0, 0, 0, 0, 0, 1) == 1) {
                char *r = *(char **)(s1 + 0xF0);
                float h = vd[1] - 1.5f;
                if (h < *(float *)(r + 4)) {
                    *(float *)(r + 4) = h;
                    *(float *)(s1 + 0x584) = 0.0f;
                }
            }
        }
        *(float *)(s1 + 0x584) =
            *(float *)(s1 + 0x584) -
            *(float *)(s1 + 0x170C) * *(float *)(s1 + 0x5A8);
        if (0.0f < *(float *)(s1 + 0x600)) {
            *(float *)(s1 + 0x600) =
                *(float *)(s1 + 0x600) - *(float *)(s1 + 0x5A8);
            if (36.0f < *(float *)(s1 + 0x618)) {
                char *o = (char *)Obj0000_Get_D_00747A94_2DB6B0();
                AddScaledDeltaToField_104_2A7498(
                    s1, *(int *)(o + 0xF0),
                    *(float *)(s1 + 0x5A8) * 0.5235988f);
            }
        }
        if (*(float *)(s1 + 0x618) < 16.0f) {
            if (*(int *)(s1 + 0x5F0) >= 2) {
                *(int *)(s1 + 0x5F0) = 1;
            }
        }
        if (Obj293_IsByteSet_53D(D_005864F0) != 0 ||
            Obj293_IsByteSet_53C(D_005864F0) != 0) {
            *(char *)(s1 + 0x1864) = 1;
        }
        if (*(unsigned char *)(s1 + 0x1864) != 0) {
            *(int *)(s1 + 0x5F0) = 0;
        }
        func_00262750(s1, 1);
        break;
    }
    case 4: {
        int gb;
        char *v1;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        v1 = *(char **)(s1 + 0x304);
        func_002A8578(s1, *(int *)(v1 + 0x984) + (int)v1,
                      *(int *)(v1 + 0x988) + (int)v1, 2, 0.0f, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 5:
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
            return;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        break;
    }
    func_00260B30(s1);
    if (*(unsigned short *)(s1 + 0x3AC) & 3) {
        *(int *)(s1 + 0x16F8) = 0xA;
        *(int *)(s1 + 0x5FC) = 1;
        *(int *)(s1 + 0x16D0) |= 0x1000;
    }
    if (*(int *)(s1 + 0x5FC) != 0) {
        *(int *)(s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}
