/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void SetField444SignedByFlag434_158288(void *a0, float f);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int moveMotion(void *a0);
extern void func_002705D8(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float a2);
extern float DoubleFloatMinusHalf_31D020(void);
extern float fRand0_1(void);
extern void sceVu0ApplyMatrix(void *a0, void *a1, void *a2);
extern void SetEffectPos(int a0, int a1, int a2, void *a3, int a4, float a5);
extern char D_00462FC0[];
extern int D_005CB000;

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"












__attribute__((section(".text.func_0025D678")))
void func_0025D678(void *a0)
{
    float f[8] __attribute__((aligned(16)));
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    float t;

    t = *(float *)(s1 + 0x5A8);
    *(float *)(s0 + 0x5A8) = t;
    SetField444SignedByFlag434_158288(s0, t);
    *(float *)(s0 + 0x54C) = 3.0f;
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x31E4) + p, *(int *)(p + 0x31E8) + p,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x16EC) = 0;
        *(short *)(s0 + 0x56A) = 0;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
    {
        char *q;
        int p0;

        q = s1 + 0x550;
        p0 = *(int *)(s0 + 0xF0);
        VU0_LQC2(4, p0, 0);
        VU0_LQC2(5, q, 0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p0, 0);
    }
        if (moveMotion(s0) != 0) {
            (*(unsigned char *)(s0 + 0x2F6))++;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x31EC) + p, *(int *)(p + 0x31F0) + p,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x5F0) = 1;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
    {
        char *q;
        int p0;

        p0 = *(int *)(s0 + 0xF0);
        q = s1 + 0x550;
        VU0_VADD_XYZ_PTR(p0, p0, q);
    }
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                char *vt;
                short off;
                void (*fp)();

                *(int *)(s0 + 0x5F0) = 0;
                vt = *(char **)(s0 + 0x214);
                off = *(short *)(vt + 0xA8);
                fp = *(void (**)())(vt + 0xAC);
                fp(s0 + off, 0xA, s1, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 0.5f);
            }
        } else {
            *(int *)(s0 + 0x5F0) = 1;
        }
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6);
        break;
    case 4:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x31F4) + p, *(int *)(p + 0x31F8) + p,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 5:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q;
            int p0;

            (*(short *)(s0 + 0x56E))--;
            p0 = *(int *)(s0 + 0xF0);
            q = s1 + 0x550;
            VU0_VADD_XYZ_PTR(p0, p0, q);
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 2) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                char *vt;
                short off;
                void (*fp)();

                *(int *)(s0 + 0x5F0) = 0;
                vt = *(char **)(s0 + 0x214);
                off = *(short *)(vt + 0xA8);
                fp = *(void (**)())(vt + 0xAC);
                fp(s0 + off, 0x1E, s1, 0, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
                if (*(short *)(s0 + 0x54A) < 2) {
                    *(short *)(s0 + 0x54A) = 1;
                }
            }
        }
        if (moveMotion(s0) != 0) {
            if (*(short *)(s0 + 0x54A) < 2) {
                *(short *)(s0 + 0x54A) = 1;
            }
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6:
    {
        int p;

        ReleaseField6ECByTag564_26B1E8(s0);
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x31FC) + p, *(int *)(p + 0x3200) + p,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 7:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q;
            int p0;

            (*(short *)(s0 + 0x56E))--;
            q = s1 + 0x550;
            p0 = *(int *)(s0 + 0xF0);
            VU0_LQC2(4, p0, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p0, 0);
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 2) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                *(int *)(s0 + 0x5F0) = 0;
                *(short *)(s0 + 0x54A) = 0;
            }
        }
        if (moveMotion(s0) != 0) {
            *(short *)(s0 + 0x54A) = 0;
            *(signed char *)(s0 + 0x2F4) = 2;
            *(signed char *)(s0 + 0x2F5) = 2;
            *(signed char *)(s0 + 0x2F6) = 0;
            *(signed char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }

    if (*(unsigned short *)(s0 + 0x3AC) & 3) {
        if (*(short *)(s0 + 0x56A) != 0) {
            int n;
            int ok;
            int idx = 4;

            ok = ((*(int *)f = n = *(unsigned char *)(s0 + 0x2B4)), (idx < n));
            if (ok) {
                s1 = *(char **)(*(int *)(s0 + 0x278) + 0x10);
            } else {
                s1 = 0;
            }
            if (s1 != 0) {
                VU0_SQC2_VF0(f, 0x10);
                f[4] = DoubleFloatMinusHalf_31D020() * 0.1f;
                f[5] = DoubleFloatMinusHalf_31D020() * 0.1f + 0.1f;
                f[6] = fRand0_1() * 0.1f + 0.2f;
                { float *e = &f[4]; sceVu0ApplyMatrix(e, s1 + 0x80, e); e = 0; }
                SetEffectPos(0, 0x4F, 0, &f[4], -1, 1.0f);
            }
        }
        *(short *)(s0 + 0x56A) = 0;
    } else {
        *(short *)(s0 + 0x56A) = 1;
    }
}
