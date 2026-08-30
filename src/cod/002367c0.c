/* sn-2.95.3-136 matched TU. */

extern unsigned char D_00462FC0[];
extern unsigned char D_00569B70[];
extern char D_007474A0[];
extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f12, int a3, int t0, int t1);
extern int cCoreSave_getGameLevel(void *a0);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_002DB770(void);
extern void func_00274FE8(void *a0);

#include "godhand/vu0.h"














__attribute__((section(".text.func_002367C0")))
void func_002367C0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1;

    s1 = Obj0000_Get_D_00747A94_2DB6B0();
    Forward_001346C8_00134608_1351D8(&D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x100C) + w, *(int *)(w + 0x1010) + w,
                      0.0f, 0, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70) - 1) {
        default:
        case 0:
            *(short *)(s0 + 0x568) = 0x14;
            break;
        case 1:
            *(short *)(s0 + 0x568) = 0x1E;
            break;
        case 2:
        case 3:
            *(short *)(s0 + 0x568) = 0x28;
            break;
        case 4:
            *(short *)(s0 + 0x568) = 0x32;
            break;
        }
        *(short *)(s0 + 0x56A) = 4;
        *(short *)(s0 + 0x56E) = 0xF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 1: {
        char *g;
        char *p = *(char **)(s0 + 0xF0);
        char *q = s1 + 0x550;
        VU0_LQC2(4, p, 0);
        do { VU0_LQC2(5, q, 0); } while (0);
        VU0_VADD_XYZ(4, 4, 5);
        VU0_SQC2(4, p, 0);
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0))
            *(unsigned char *)(s0 + 0x2F6) = 2;
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        func_002DB770();
        g = D_007474A0;
        if ((*(int *)(g + 8) & 0xF0) != 0)
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
        if ((*(int *)(g + 8) & 0xF00000) != 0)
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 4;
        break;
    }
    case 2: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0xFF4) + w, *(int *)(w + 0xFF8) + w,
                      0.0f, 0, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3: {
        char *g;
        if (*(short *)(s0 + 0x56E) != 0) {
            char *p;
            char *q;
            *(short *)(s0 + 0x56E) = *(unsigned short *)(s0 + 0x56E) - 1;
            p = *(char **)(s0 + 0xF0);
            do { } while (0);
            q = s1 + 0x550;
            VU0_LQC2(4, p, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p, 0);
        }
        func_002DB770();
        g = D_007474A0;
        if ((*(int *)(g + 8) & 0xF0) != 0)
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
        if ((*(int *)(g + 8) & 0xF00000) != 0)
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 4;
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0)) {
            *(unsigned char *)(s0 + 0x2F6) = 4;
            if (*(short *)(s1 + 0x54A) > 0) {
                *(unsigned char *)(s1 + 0x2F6) = 4;
            } else {
                *(unsigned char *)(s1 + 0x2F5) = 0;
                *(unsigned char *)(s1 + 0x2F4) = 2;
                *(unsigned char *)(s1 + 0x2F6) = 0;
                *(unsigned char *)(s1 + 0x2F7) = 0;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s1 + 0x54A) > 0 && *(short *)(s0 + 0x568) <= 0) {
            *(unsigned char *)(s0 + 0x2F6) = 6;
            *(unsigned char *)(s1 + 0x2F6) = 6;
        }
        break;
    }
    case 4: {
        int w = *(int *)(s0 + 0x304);
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0x1004) + w, *(int *)(w + 0x1008) + w,
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
        *(unsigned char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(w + 0xFFC) + w, *(int *)(w + 0x1000) + w,
                      0.0f, 3, 0, 0);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 7:
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0)) {
            int hp = *(short *)(s0 + 0x54A);
            int d = 0x14;
            switch (cCoreSave_getGameLevel(&D_00569B70)) {
            default:
            case 0:
                break;
            case 4:
                d = 0x12;
                break;
            case 5:
                d = 0xF;
                break;
            }
            hp = hp - d;
            if (hp <= 0)
                hp = 0;
            if (hp >= *(short *)(s0 + 0x548))
                *(short *)(s0 + 0x54A) = *(unsigned short *)(s0 + 0x548);
            else
                *(short *)(s0 + 0x54A) = hp;
            if (hp <= 0) {
                *(unsigned char *)(s0 + 0x2F4) = 2;
                *(unsigned char *)(s0 + 0x2F5) = 1;
                *(unsigned char *)(s0 + 0x2F6) = 0;
                *(unsigned char *)(s0 + 0x2F7) = 0;
            } else {
                func_00274FE8(s0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}
