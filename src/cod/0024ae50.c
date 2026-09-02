/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern float capVu0Atan2(float x, float z);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void func_00281368(void *a0, int a1);
extern void func_002832A0(void *a0, int a1);
extern void func_002498A8(void *a0, float a1);
extern float DoubleFloatMinusHalf_31D020(void);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_0026DB00(void *a0, int a1, int a2);
extern int D_005850B0;

#include "godhand/vu0.h"
















__attribute__((section(".text.func_0024AE50")))
void func_0024AE50(void *a0)
{
    char *s0 = (char *)a0;
    float v[12];
    float dist;
    void *sb;
    char *o;

    VU0_SQC2_VF0(v, 0);
    o = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    sb = &D_005850B0;
    dist = capVu0MagnitudeSqXZ(*(void **)(o + 0xF0), sb);
    *(int *)(s0 + 0x16D0) |= 0x30400;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int gb;
        char *p;
        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        p = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3D3C) + (int)p, *(int *)(p + 0x3D40) + (int)p, 0.0f, 0xA, gb, 0);
        if (*(int *)(s0 + 0x748) != 0) {
            func_00281368(*(void **)(s0 + 0x748), 0);
        }
        if (*(int *)(s0 + 0x74C) != 0) {
            func_002832A0(*(void **)(s0 + 0x74C), 0);
        }
        if (*(int *)(s0 + 0x750) != 0) {
            func_002832A0(*(void **)(s0 + 0x750), 0);
        }
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 1:
        *(char *)(s0 + 0x617) = 1;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2: {
        int gb;
        float ang;
        void *q = *(void **)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0xF0);
        float *cs = v + 4;
        float *tq = v + 8;
        VU0_SQC2_VF0(v, 0x20);
        VU0_LQC2(4, q, 0);
        VU0_LQC2(5, sb, 0);
        VU0_VSUB_XYZ(4, 4, 5);
        VU0_SQC2(4, v, 0x20);
        VU0_LQC2(4, tq, 0);
        VU0_SQC2(4, v, 0x10);
        if (v != cs) {
            v[0] = v[4];
            v[1] = v[5];
            v[2] = v[6];
        }
        ang = capVu0Atan2(v[0], v[2]);
        if (capVu0MagnitudeSqXZ(*(void **)((char *)Obj0000_Get_D_00747A94_2DB6B0() + 0xF0), sb) < 64.0f) {
            ang = DoubleFloatMinusHalf_31D020() * 3.14159274f;
        }
        func_002498A8(s0, ang);
        *(char *)(s0 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        if (100.0f < dist) {
            char *p = *(char **)(s0 + 0x304);
            func_002A8578(s0, *(int *)(p + 0x3D44) + (int)p, *(int *)(p + 0x3D48) + (int)p, 0.0f, 0xA, gb, 0);
            if (*(int *)(s0 + 0x748) != 0) {
                func_00281368(*(void **)(s0 + 0x748), 1);
            }
            if (*(int *)(s0 + 0x74C) != 0) {
                func_002832A0(*(void **)(s0 + 0x74C), 1);
            }
            if (*(int *)(s0 + 0x750) != 0) {
                func_002832A0(*(void **)(s0 + 0x750), 1);
            }
            *(float *)(s0 + 0x600) = 35.0f;
        } else {
            char *p = *(char **)(s0 + 0x304);
            func_002A8578(s0, *(int *)(p + 0x3D4C) + (int)p, *(int *)(p + 0x3D50) + (int)p, 0.0f, 0xA, gb, 0);
            if (*(int *)(s0 + 0x748) != 0) {
                func_00281368(*(void **)(s0 + 0x748), 2);
            }
            if (*(int *)(s0 + 0x74C) != 0) {
                func_002832A0(*(void **)(s0 + 0x74C), 2);
            }
            if (*(int *)(s0 + 0x750) != 0) {
                func_002832A0(*(void **)(s0 + 0x750), 2);
            }
            *(float *)(s0 + 0x600) = 15.0f;
        }
        *(unsigned char *)(s0 + 0x2F6) += 1;
    }
        /* fallthrough */
    case 3:
        if (0.0f < *(float *)(s0 + 0x600)) {
            *(char *)(s0 + 0x617) = 1;
            *(float *)(s0 + 0x600) -= *(float *)(s0 + 0x5A8);
        }
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0xA1;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        func_0026DB00(s0, 6, 0);
    }
}
