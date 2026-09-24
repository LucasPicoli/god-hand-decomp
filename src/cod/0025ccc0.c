/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void SetField444SignedByFlag434_158288(void *a0, float f12);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float heat);
extern char D_00462FC0[];
extern char D_005CB000[];

#include "godhand/vu0.h"

__attribute__((section(".text.func_0025CCC0")))
void func_0025CCC0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    float v;
    float t;

    s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    v = *(float *)(s1 + 0x5A8);
    *(float *)(s0 + 0x5A8) = v;
    SetField444SignedByFlag434_158288(s0, v);
    *(float *)(s0 + 0x54C) = 3.0f;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);

    t = *(float *)(s0 + 0x770);
    if (t > 0.0f) {
        if (t < 10.0f) {
            *(float *)(s0 + 0x770) = 10.0f;
        }
    }

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x14C0) + p, *(int *)(p + 0x14C4) + p,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x16EC) = 0;
        *(int *)(s0 + 0x5F0) = 1;
        (*(unsigned char *)(s0 + 0x2F6))++;
        *(int *)(s0 + 0x5F4) = 1;
    }
        /* fallthrough */
    case 1:
    {
        char *q;
        char *pa;
        char *pb;
        int p0;

        *(int *)(s0 + 0x16D0) |= 0x10000;
        q = s1 + 0x550;
        pa = *(char **)(s1 + 0xF0);
        pb = *(char **)(s0 + 0xF0);
        *(float *)(pb + 4) = *(float *)(pa + 4)
                           - (*(float *)(s0 + 0x114) - 1.0f) * 0.1f;
        p0 = *(int *)(s0 + 0xF0);
        VU0_VADD_XYZ_IP(p0, 0, q);
        if (moveMotion(s0) != 0) {
            (*(unsigned char *)(s0 + 0x2F6))++;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    case 2:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x14C8) + p, *(int *)(p + 0x14CC) + p,
                      0.0f, 0, 0, 0);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
    {
        char *q;
        char *pa;
        char *pb;
        int p0;

        *(int *)(s0 + 0x16D0) |= 0x10000;
        q = s1 + 0x550;
        pa = *(char **)(s1 + 0xF0);
        pb = *(char **)(s0 + 0xF0);
        *(float *)(pb + 4) = *(float *)(pa + 4)
                           - (*(float *)(s0 + 0x114) - 1.0f) * 0.1f;
        p0 = *(int *)(s0 + 0xF0);
        VU0_VADD_XYZ_IP(p0, 0, q);
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6);
        break;
    }
    case 4:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x14D0) + p, *(int *)(p + 0x14D4) + p,
                      0.0f, 0, 0, 0);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 5:
    {
        char *pa;
        char *pb;

        *(int *)(s0 + 0x16D0) |= 0x10000;
        pa = *(char **)(s1 + 0xF0);
        pb = *(char **)(s0 + 0xF0);
        *(float *)(pb + 4) = *(float *)(pa + 4)
                           - (*(float *)(s0 + 0x114) - 1.0f) * 0.1f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 1;
            *(unsigned char *)(s0 + 0x2F5) = 0x23;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
            return;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    default:
        break;
    }

    if (*(unsigned short *)(s0 + 0x3AC) & 1) {
        if (*(int *)(s0 + 0x5F0) != 0) {
            int vt;
            short off;
            int (*fp)();
            *(int *)(s0 + 0x5F0) = 0;
            vt = *(int *)(s0 + 0x214);
            off = *(short *)(vt + 0xA8);
            fp = *(int (**)())(vt + 0xAC);
            fp(s0 + off, 6, s1, 1, 0);
            cHeatSys_AddHeatGage(D_005CB000, 0, 0.5f);
        }
    } else {
        *(int *)(s0 + 0x5F0) = 1;
    }

    if ((*(unsigned short *)(s0 + 0x3AC) & 2) && *(int *)(s0 + 0x5F4) != 0) {
        int vt;
        short off;
        int (*fp)();
        *(int *)(s0 + 0x5F4) = 0;
        vt = *(int *)(s0 + 0x214);
        off = *(short *)(vt + 0xA8);
        fp = *(int (**)())(vt + 0xAC);
        fp(s0 + off, 0x14, s1, 1, 0);
        cHeatSys_AddHeatGage(D_005CB000, 0, 1.0f);
    } else {
        *(int *)(s0 + 0x5F4) = 1;
    }
}
