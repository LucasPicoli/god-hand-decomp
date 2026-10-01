/* sn-2.95.3-136 matched TU. */

extern unsigned char D_005864F0[];
extern unsigned char D_00462FC0[];
extern unsigned char D_005FEE00[];
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void AddScaledDeltaToField_104_2A7498(void *a0, void *a1, float a2);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern int cOmbb_ckFire(int a0);
extern void cOmbb_setFire(int a0);
extern float SetField444SignedByFlag434_158288(void *a0, float f12);
extern float cEmManage_GetSpeedRate(void *a0);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);

#include "godhand/vu0.h"
__attribute__((section(".text.func_00244708")))
void func_00244708(void *a0)
{
    float buf[4];
    char *s0 = (char *)a0;
    int s1;

    s1 = func_002948C8(D_005864F0, *(unsigned char *)(s0 + 0x17B1));
    VU0_SQC2_VF0(buf, 0);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x10000;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s0) & 0xFFFF;
        char *v1 = *(char **)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v1 + 0x4FC) + (int)v1, *(int *)(v1 + 0x500) + (int)v1, 0.0f, 3, gb, 0);
    }
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0x64, s0, 0, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
    {
        float *p = (float *)(*(char **)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0));
        if (buf != p) {
            buf[0] = p[0];
            buf[1] = p[1];
            buf[2] = p[2];
        }
        if (s1 != 0) {
            float *q = (float *)func_001B8720(s1);
            if (buf != q) {
                buf[0] = q[0];
                buf[1] = q[1];
                buf[2] = q[2];
            }
        }
    }
        AddScaledDeltaToField_104_2A7498(s0, buf, *(float *)(s0 + 0x5A8) * 0.392699093f);
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        if (s1 != 0) {
            if (cOmbb_ckFire(s1) == 0)
                cOmbb_setFire(s1);
        }
    }
}

__attribute__((section(".text.func_001CEF28")))
void func_001CEF28(void *a0)
{
    char *s0 = (char *)a0;
    float sp;
    float one;
    float t;

    sp = cEmManage_GetSpeedRate(D_005864F0);
    *(float *)(s0 + 0x5A8) = sp;
    SetField444SignedByFlag434_158288(s0, sp);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0xC) + v0, 0, 0.0f, 0, 0, 0);
    }
        *(short *)(s0 + 0x568) = 0;
        *(float *)(s0 + 0x674) = 150.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 1:
        moveMotion(s0);
        if (capVu0MagnitudeSqXZ(*(void **)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0), *(void **)(s0 + 0xF0)) < 4.0f)
            *(short *)(s0 + 0x568) = 1;
        if (*(short *)(s0 + 0x568) != 0) {
            t = *(float *)(s0 + 0x674) - sp;
            *(float *)(s0 + 0x674) = t;
            if (t <= 0.0f)
                *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        }
        break;
    case 2:
    {
        int v0 = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(v0 + 0x10) + v0, 0, 0.0f, 0, 0, 0);
    }
        *(float *)(s0 + 0x674) = 90.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    case 3:
        one = 1.0f;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, one);
        AddScaledXfmVecToField_F0_14F928(s0, one);
        t = *(float *)(s0 + 0x674) - sp;
        *(float *)(s0 + 0x674) = t;
        if (t <= 0.0f) {
            float u = *(float *)(s0 + 0x24C) - sp * 0.1f;
            *(int *)(s0 + 0x250) = *(int *)(s0 + 0x250) | 0x10;
            *(float *)(s0 + 0x24C) = u;
            if (u < 0.0f) {
                *(float *)(s0 + 0x24C) = 0.0f;
                *(unsigned char *)(s0 + 0x2F4) = 1;
                *(unsigned char *)(s0 + 0x2F5) = 0;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
            }
        }
        break;
    }
}
