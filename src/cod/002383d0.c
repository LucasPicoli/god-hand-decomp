/* sn-2.95.3-136 matched TU. */

/* func_002383D0, 996 B, sn-2.95.3-136. Wave 2026-08-31 V2 h2 + a block-local base pointer per if/else arm (pa1..pa4) so local-alloc takes the base first. */
#include "godhand/vu0.h"

extern char D_00462FC0[];
extern int D_00569B70;
extern int D_007474A8;

extern int Obj0000_Get_D_00747A94_2DB6B0();
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern void StoreMotionParamsBoth_2609A8(void *a0, int a1, int a2, int a3, int a4, int a5);
extern int cCoreSave_getGameLevel(void *a0);
extern float SetField444SignedByFlag434_158288(void *a0, float f);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f12);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f12);
extern void func_00260B30(void *a0);

__attribute__((section(".text.func_002383D0")))
void func_002383D0(char *s0)
{
    char *s3;
    char *s1;
    char *s2;

    s3 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int t8;
        char *pp;
        int n;

        *(char *)(s0 + 0x1864) = 0;
        t8 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            char *pa1 = *(char **)(s0 + 0x304);
            s2 = (char *)(*(int *)(pa1 + 0x2B24) + (int)pa1);
            s1 = (char *)(*(int *)(pa1 + 0x2B28) + (int)pa1);
        } else {
            char *pa2 = *(char **)(s0 + 0x304);
            s2 = (char *)(*(int *)(pa2 + 0x2B40) + (int)pa2);
            s1 = (char *)(*(int *)(pa2 + 0x2B44) + (int)pa2);
        }
        func_002A8578(s0, (int)s2, (int)s1, 0.0f, 0, t8, 0);
        StoreMotionParamsBoth_2609A8(s0, 4, 0, 0x3D, -1, 0);
        *(short *)(s0 + 0x56A) = 0;
        *(short *)(s0 + 0x56C) = 0;
        *(short *)(s0 + 0x568) = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: n = 0xF; break;
        case 2: n = 0x14; break;
        case 3: case 4: n = 0x19; break;
        case 5: n = 0x1E; break;
        }
        if ((*(int *)(s0 + 0x16D4) & 0x4000000) != 0) {
            n = n + 5;
        }
        if (n >= 0x24) {
            n = 0x23;
        }
        *(int *)(s0 + 0x5F0) = 0xF;
        *(short *)(s0 + 0x56E) = n;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(int *)(s0 + 0x5F0) != 0) {
            char *p;
            char *q;

            *(int *)(s0 + 0x5F0) = *(int *)(s0 + 0x5F0) - 1;
            p = *(char **)(s0 + 0xF0);
            do { } while (0);
            q = s3 + 0x550;
            VU0_LQC2(4, p, 0x0);
            VU0_LQC2(5, q, 0x0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0x0);
        }
        *(float *)(s0 + 0x54C) = 5.0f;
        if ((*(int *)(s0 + 0x16D4) & 0x4000000) != 0) {
            SetField444SignedByFlag434_158288(s0, *(float *)(s0 + 0x5A8) * 3.0f);
        } else {
            SetField444SignedByFlag434_158288(s0,
                *(float *)(s0 + 0x5A8) + *(float *)(s0 + 0x5A8));
        }
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        {
            int t = *(unsigned short *)(s0 + 0x568) - 1;

            *(short *)(s0 + 0x568) = t;
            if ((short)t <= 0) {
                *(char *)(s0 + 0x2F6) = 2;
                *(char *)(s3 + 0x2F6) = 4;
                if (*(short *)(s0 + 0x56A) >= *(short *)(s0 + 0x56E)) {
                    *(short *)(s3 + 0x56C) = 1;
                } else {
                    *(short *)(s0 + 0x56C) = 1;
                }
            } else {
                if (*(short *)(s3 + 0x54A) > 0) {
                    if ((D_007474A8 & 0xF0) != 0) {
                        int m = *(unsigned short *)(s0 + 0x56A) + 1;

                        *(short *)(s0 + 0x56A) = m;
                        if ((short)m == 5) {
                            *(char *)(s3 + 0x2F6) = 2;
                            *(short *)(s0 + 0x568) = 0x3C;
                        }
                    }
                }
            }
        }
        break;
    case 2:
    {
        int t8;
        char *pp;

        if (*(unsigned char *)(s0 + 0x2F7) != 0) {
            char *pa3 = *(char **)(s0 + 0x304);
            s2 = (char *)(*(int *)(pa3 + 0x2B2C) + (int)pa3);
            s1 = (char *)(*(int *)(pa3 + 0x2B30) + (int)pa3);
        } else {
            char *pa4 = *(char **)(s0 + 0x304);
            s2 = (char *)(*(int *)(pa4 + 0x2B48) + (int)pa4);
            s1 = (char *)(*(int *)(pa4 + 0x2B4C) + (int)pa4);
        }
        t8 = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        func_002A8578(s0, (int)s2, (int)s1, 0.0f, 0, t8, 0);
        StoreMotionParamsBoth_2609A8(s0, 0x3C, 0, 0x41, -1, 0);
        *(int *)(s0 + 0x5F0) = 0xF;
        *(float *)(s0 + 0x54C) = 2.0f;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
        if (*(int *)(s0 + 0x5F0) != 0) {
            char *p;
            char *q;

            q = s3 + 0x550;
            *(int *)(s0 + 0x5F0) = *(int *)(s0 + 0x5F0) - 1;
            p = *(char **)(s0 + 0xF0);
            VU0_LQC2(4, p, 0x0);
            VU0_LQC2(5, q, 0x0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0x0);
        }
        if (*(short *)(s0 + 0x56C) != 0) {
            *(float *)(s0 + 0x54C) = 5.0f;
        }
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
    func_00260B30(s0);
}
