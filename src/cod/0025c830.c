/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern unsigned char D_00462FC0[];
extern unsigned char D_005CB000[];
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void SetField444SignedByFlag434_158288(void *a0, float f12);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void ReleaseField6ECByTag564_26B1E8(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cHeatSys_AddHeatGage(void *a0, int a1, float f12);
extern void func_002705D8(void *a0);

extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);

__attribute__((section(".text.func_0025C830")))
void func_0025C830(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;
    float t;

    s1 = Obj0000_Get_D_00747A94_2DB6B0();
    t = *(float *)(s1 + 0x5A8);
    *(float *)(s0 + 0x5A8) = t;
    SetField444SignedByFlag434_158288(s0, t);
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w;
        ReleaseField6ECByTag564_26B1E8(s0);
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x1820) + w, *(int *)(w + 0x1824) + w,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x16EC) = 0;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        char *q = s1 + 0x550;
        char *d = *(char **)(s0 + 0xF0);
        char *p;
        *(float *)(s0 + 0x54C) = 3.0f;
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x10000;
        *(float *)(d + 4) = *(float *)(*(char **)(s1 + 0xF0) + 4);
        p = *(char **)(s0 + 0xF0);
        VU0_VADD_XYZ_IP(p, 0, q);
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
    case 2: {
        int w;
        ReleaseField6ECByTag564_26B1E8(s0);
        w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x1828) + w, *(int *)(w + 0x182C) + w,
                      0.0f, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3: {
        char *q = s1 + 0x550;
        char *d = *(char **)(s0 + 0xF0);
        char *p;
        *(float *)(s0 + 0x54C) = 3.0f;
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x10000;
        *(float *)(d + 4) = *(float *)(*(char **)(s1 + 0xF0) + 4);
        p = *(char **)(s0 + 0xF0);
        VU0_VADD_XYZ_IP(p, 0, q);
        if (moveMotion(s0)) {
            char *vt = *(char **)(s0 + 0x214);
            int off = *(short *)(vt + 0xA8);
            int (*fp)() = *(int (**)())(vt + 0xAC);
            fp(s0 + off, 8, s1, 1, 0);
            cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6);
        break;
    }
    case 4: {
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x1838) + w, *(int *)(w + 0x183C) + w,
                      0.0f, 0, 0, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(short *)(s0 + 0x56E) = 0xF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5: {
        char *d;
        *(float *)(s0 + 0x54C) = 3.0f;
        *(int *)(s0 + 0x16D0) = *(int *)(s0 + 0x16D0) | 0x10000;
        d = *(char **)(s0 + 0xF0);
        *(float *)(d + 4) = *(float *)(*(char **)(s1 + 0xF0) + 4);
        if (*(short *)(s0 + 0x56E) != 0) {
            char *p;
            char *q;
            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            p = *(char **)(s0 + 0xF0);
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0)) {
            if (*(short *)(s0 + 0x54A) <= 0) {
                func_0025FE30(s0, 0x1000000, 0);
                *(unsigned char *)(s0 + 0x2F4) = 2;
                *(unsigned char *)(s0 + 0x2F5) = 2;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                break;
            }
            func_002705D8(s0);
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                char *vt;
                int off;
                int (*fp)();
                *(int *)(s0 + 0x5F0) = 0;
                vt = *(char **)(s0 + 0x214);
                off = *(short *)(vt + 0xA8);
                fp = *(int (**)())(vt + 0xAC);
                fp(s0 + off, 0x14, s1, 1, 0);
                cHeatSys_AddHeatGage(&D_005CB000, 0, 1.0f);
            }
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 0x10) {
            if (*(short *)(s0 + 0x54A) > 0) {
                *(unsigned char *)(s1 + 0x2F6) = 6;
                *(unsigned char *)(s0 + 0x2F6) = 6;
            }
        }
        break;
    }
    case 6: {
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x1830) + w, *(int *)(w + 0x1834) + w,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0xF;
        *(float *)(s0 + 0x54C) = 15.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 7:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q = s1 + 0x550;
            char *p;
            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            p = *(char **)(s0 + 0xF0);
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        if (moveMotion(s0)) {
            if (*(short *)(s0 + 0x54A) > 0) {
                func_002705D8(s0);
            } else {
                func_0025FE30(s0, 0x1000000, 0);
                *(unsigned char *)(s0 + 0x2F4) = 2;
                *(unsigned char *)(s0 + 0x2F5) = 2;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
                break;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}
