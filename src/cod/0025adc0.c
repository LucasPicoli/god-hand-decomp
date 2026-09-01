/* sn-2.95.3-136 matched TU. */

extern int D_00462FC0;
extern void cCollisionSolidManage_SetPriority(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00262750(void *a0, int a1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);

/* sn-2.95.3-136 matched TU. */









extern int ChkLine(void *a0, void *a1, void *a2, int a3, int a4, int a5, int a6,
                   int a7, int a8, int a9, int a10, int a11, int a12);

#include "godhand/vu0.h"

#define FRAME ((char *)va - 0x30)

__attribute__((section(".text.func_0025ADC0")))
void func_0025ADC0(void *a0)
{
    float va[4], vb[4], vc[4], vd[4];
    char *s1 = (char *)a0;

    VU0_SQC2_VF0(FRAME, 0x30);
    *(char *)(s1 + 0x617) = 1;
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0: {
        int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        int s2v, s0v;

        switch (*(int *)(s1 + 0x564)) {
        default:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x124) + b;
                s0v = *(int *)(b + 0x128) + b;
            }
            break;
        case 0x20a: case 0x20b: case 0x20c: case 0x20d: case 0x20e:
        case 0x218: case 0x245: case 0x246: case 0x247: case 0x24f:
        case 0x278: case 0x279:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x89c) + b;
                s0v = *(int *)(b + 0x8a0) + b;
            }
            break;
        case 0x250: case 0x251:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x89c) + b;
                s0v = *(int *)(b + 0x8a0) + b;
            }
            break;
        case 0x260:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x89c) + b;
                s0v = *(int *)(b + 0x8a0) + b;
            }
            break;
        case 0x214: case 0x215: case 0x21a: case 0x21b: case 0x21c:
        case 0x21d: case 0x21e: case 0x225: case 0x22c: case 0x22d:
        case 0x22e: case 0x22f: case 0x248: case 0x249: case 0x24c:
        case 0x24d: case 0x24e: case 0x252: case 0x25a:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x112c) + b;
                s0v = *(int *)(b + 0x1130) + b;
            }
            break;
        case 0x20f: case 0x210: case 0x211: case 0x226: case 0x270:
        case 0x271: case 0x272: case 0x273: case 0x274:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x124) + b;
                s0v = *(int *)(b + 0x128) + b;
            }
            break;
        case 0x205: case 0x206: case 0x207: case 0x208: case 0x209:
        case 0x21f: case 0x224: case 0x241:
            {
                int b = *(int *)(s1 + 0x304);
                s2v = *(int *)(b + 0x15d4) + b;
                s0v = *(int *)(b + 0x15d8) + b;
            }
            break;
        }
        cCollisionSolidManage_SetPriority(&D_00462FC0, s1, 5);
        func_002A8578(s1, s2v, s0v, 0.0f, 3, gb, 0);
        *(unsigned char *)(s1 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1: {
        char *p;
        float *dp;
        float *pd;
        float k;
        int f;

        *(float *)(s1 + 0x54C) = 3.0f;
        *(int *)(s1 + 0x16D0) |= 0x1000;
        func_00262750(s1, 4);
        f = *(int *)(s1 + 0x16D0);
        f |= 0x10000;
        f |= 0x20000;
        *(int *)(s1 + 0x16D0) = f;
        pd = vd;
        k = 0.1f;

        VU0_LQC2(4, s1 + 0x580, 0);
        VU0_SQC2(4, FRAME, 0x60);
        VU0_LQC2(4, FRAME, 0x60);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, FRAME, 0x60);

        VU0_LQC2(4, pd, 0);
        VU0_SQC2(4, FRAME, 0x50);
        k = *(float *)(s1 + 0x5A8);
        VU0_LQC2(4, vc, 0);
        VU0_SQC2(4, FRAME, 0x60);
        VU0_LQC2(4, FRAME, 0x60);
        VU0_LOAD_SCALAR(5, k);
        VU0_VMULX_XYZ(4, 4, 5);
        VU0_SQC2(4, FRAME, 0x60);
        VU0_LQC2(4, pd, 0);
        VU0_SQC2(4, FRAME, 0x40);

        dp = va;
        if (dp != vb) {
            float t0, t1, t2;
            t0 = vb[0];
            t1 = vb[1];
            dp[0] = t0;
            *(float *)&dp[1] = t1;
            t2 = *(float *)&vb[2];
            dp[2] = t2;
        }
        p = *(char **)(s1 + 0xF0);
        VU0_LQC2(4, p, 0);
        VU0_LQC2(5, dp, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p, 0);
        VU0_LQC2(4, s1, 0x580);
        VU0_LQC2(5, dp, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, s1, 0x580);

        if (moveMotion(s1) != 0) {
            *(short *)(s1 + 0x54A) = 0;
            *(char *)(s1 + 0x2F4) = 2;
            *(char *)(s1 + 0x2F5) = 2;
            *(char *)(s1 + 0x2F7) = 1;
            *(char *)(s1 + 0x2F6) = 0;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if (*(unsigned short *)(s1 + 0x3AC) & 0x10) {
            float *q;
            int r;

            VU0_SQC2_VF0(FRAME, 0x40);
            VU0_SQC2_VF0(FRAME, 0x50);
            VU0_SQC2_VF0(FRAME, 0x60);
            q = (float *)(s1 + 0x490);
            if (vb != q) {
                vb[0] = q[0];
                vb[1] = q[1];
                vb[2] = q[2];
            }
            q = *(float **)(s1 + 0xF0);
            if (vc != q) {
                vc[0] = q[0];
                vc[1] = q[1];
                vc[2] = q[2];
            }
            vb[1] = vb[1] + 0.5f;
            r = ChkLine(vb, vc, pd, 0, 2, 0x400, 0, 0, 0, 0, 0, 0, 1);
            if (r == 1) {
                char *fp = *(char **)(s1 + 0xF0);
                char *vt;
                short ofs;

                *(float *)(fp + 4) = vd[1];
                vt = *(char **)(s1 + 0x214);
                ofs = *(short *)(vt + 0xA8);
                ((int (*)(void *, int, int, int, int)) * (void **)(vt + 0xAC))(
                    s1 + ofs, 0x32, 0, 0, 0);
                *(char *)(s1 + 0x2F4) = r;
                *(char *)(s1 + 0x2F5) = 8;
                *(char *)(s1 + 0x2F6) = 2;
                *(char *)(s1 + 0x2F7) = 0;
            }
        }
        break;
    }
    }
}
