/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_D_00747A94_2DB6B0(void);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int cCoreSave_getGameLevel(void *a0);
extern int moveMotion(void *a0);
extern void func_002DB770(void);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_002705D8(void *a0);
extern char D_00462FC0[];
extern char D_00569B70[];
extern char D_007474A0[];

#include "godhand/vu0.h"














__attribute__((section(".text.func_002397C0")))
void func_002397C0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x3C44) + w, *(int *)(w + 0x3C48) + w,
                      0.0f, 0, 0, 0);
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            *(short *)(s0 + 0x568) = 0xF;
            break;
        case 2:
            *(short *)(s0 + 0x568) = 0x14;
            break;
        case 3:
        case 4:
            *(short *)(s0 + 0x568) = 0x19;
            break;
        case 5:
            *(short *)(s0 + 0x568) = 0x1E;
            break;
        }
        *(short *)(s0 + 0x56A) = 4;
        *(short *)(s0 + 0x56E) = 0xF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q = s1 + 0x550;
            char *p;
            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            p = *(char **)(s0 + 0xF0);
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x3C4C) + w, *(int *)(w + 0x3C50) + w,
                      0.0f, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
    {
        char *g;
        func_002DB770();
        g = D_007474A0;
        if (*(int *)(g + 8) & 0xF0)
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
        if (*(int *)(g + 8) & 0xF00000)
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 4;
    }
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0)) {
            int v;
            if (*(short *)(s0 + 0x568) <= 0) {
                *(unsigned char *)(s0 + 0x2F6) = 6;
                *(unsigned char *)(s1 + 0x2F6) = 6;
            }
            v = *(unsigned short *)(s0 + 0x56A) - 1;
            *(short *)(s0 + 0x56A) = v;
            if ((short)v <= 0) {
                *(unsigned char *)(s0 + 0x2F6) = 4;
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
            if (*(short *)(s1 + 0x54A) <= 0) {
                *(unsigned char *)(s0 + 0x2F6) = 4;
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 4: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x3C54) + w, *(int *)(w + 0x3C58) + w,
                      0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 5:
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0)) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6: {
        int w = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(w + 0x3C5C) + w, *(int *)(w + 0x3C60) + w,
                      0.0f, 3, 0, 0);
        *(int *)(s0 + 0x5F0) = 1;
        *(float *)(s0 + 0x54C) = 5.0f;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 7:
        if (moveMotion(s0))
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                int vt = *(int *)(s0 + 0x214);
                short off;
                int (*fp)();
                *(int *)(s0 + 0x5F0) = 0;
                off = *(short *)(vt + 0xA8);
                fp = *(int (**)())(vt + 0xAC);
                fp(s0 + off, 0xA, s1, 1, 0);
                if (*(short *)(s0 + 0x54A) <= 0)
                    *(short *)(s0 + 0x54A) = 1;
            }
        }
        break;
    default:
        break;
    }
}
