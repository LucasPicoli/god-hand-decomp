/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern void Obj0000_Clear_Fields_640_648_124E58(void *a0);
extern void func_00126770(void *a0);
extern void ClearField15F4Bit1_124F60(void *a0, int a1, int a2);
extern float *func_0012A2E0(void *a0);
extern int func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_0012A3C0(void *a0);
extern void func_00123938(void *a0, int a1);

__attribute__((section(".text.func_0010FF80")))
void func_0010FF80(void *a0)
{
    float b[12] __attribute__((aligned(16)));
    char *s0 = (char *)a0;
    char *s1;
    float *src;
    float *dp;
    float *dd;
    float *d;
    char *obj;
    char *q;
    char *q2;
    char *obj2;
    float k;
    float one;
    int t;

    VU0_SQC2_VF0(b, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(short *)(s0 + 0x5E0) = 0;
        *(short *)(s0 + 0x5E2) = 0;
        Obj0000_Clear_Fields_640_648_124E58(s0);
        s1 = s0 + 0x580;
        func_00126770(s0);
        ClearField15F4Bit1_124F60(s0, 0, 0);
        src = func_0012A2E0(s0);
        if ((float *)s1 != src) {
            *(float *)(s0 + 0x580) = src[0];
            *(float *)(s1 + 4) = src[1];
            *(float *)(s1 + 8) = src[2];
        }
        t = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(t + 0x20C) + t, *(int *)(t + 0x6DC) + t, 15.0f, 3, 0, 0);
        obj = *(char **)(s0 + 0xF0);
        d = &b[4];
        VU0_SQC2_VF0(b, 0x20);
        VU0_LQC2(4, s1, 0);
        VU0_LQC2(5, obj, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, b, 0x20);
        q = (char *)b + 0x20;
        VU0_LQC2(4, q, 0);
        VU0_SQC2(4, b, 0x10);
        dp = (float *)(s0 + 0x590);
        if (dp != d) {
            float t0, t1, t2;
            t0 = b[4];
            t1 = b[5];
            dp[0] = t0;
            *(volatile float *)&dp[1] = t1;
            t2 = *(volatile float *)&b[6];
            dp[2] = t2;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        k = 0.1f;
        q2 = (char *)b + 0x20;
        VU0_LQC2(4, s0 + 0x590, 0);
        VU0_SQC2(4, b, 0x20);
        VU0_LQC2(4, b, 0x20);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, b, 0x20);
        VU0_LQC2(4, q2, 0);
        VU0_SQC2(4, b, 0x10);
        dd = b;
        src = &b[4];
        if (dd != src) {
            float t0, t1, t2;
            t0 = b[4];
            t1 = b[5];
            t2 = b[6];
            dd[0] = t0;
            dd[1] = t1;
            dd[2] = t2;
        }
        obj2 = *(char **)(s0 + 0xF0);
        VU0_LQC2(4, obj2, 0);
        VU0_LQC2(5, b, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, obj2, 0);
        VU0_LQC2(4, s0, 0x590);
        VU0_LQC2(5, b, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, s0, 0x590);
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        one = 1.0f;
        AddScaledVecToField_100_14F9F0(s0, one);
        if (!(*(unsigned short *)(s0 + 0x3AC) & 4)) {
            AddScaledXfmVecToField_F0_14F928(s0, one);
        }
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        func_0012A3C0(s0);
    }
    *(unsigned short *)(s0 + 0x3AC) = *(unsigned short *)(s0 + 0x3AC) | 0x200;
    func_00123938(s0, 1);
}
