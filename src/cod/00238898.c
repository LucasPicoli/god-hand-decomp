/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_002DB770(void);
extern int D_00569B70;
extern char D_00462FC0[];
extern char D_007474A0[];

/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"














__attribute__((section(".text.func_00238898")))
void func_00238898(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3224) + p, *(int *)(p + 0x3228) + p,
                      0.0f, 0, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(short *)(s0 + 0x568) = 0x1E; break;
        case 2: *(short *)(s0 + 0x568) = 0x23; break;
        case 3: case 4: *(short *)(s0 + 0x568) = 0x28; break;
        case 5: *(short *)(s0 + 0x568) = 0x2D; break;
        }
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
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
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2:
    {
        int p;

        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x322C) + p, *(int *)(p + 0x3230) + p,
                      0.0f, 0, 0, 0);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
        Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s1 + 0x2F6) = 4;
            *(unsigned char *)(s0 + 0x2F6) = 4;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s1 + 0x54A) > 0) {
            char *g;

            func_002DB770();
            g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0) {
                (*(short *)(s0 + 0x568))--;
            }
            if ((*(int *)(g + 8) & 0xF00000) != 0) {
                *(short *)(s0 + 0x568) -= 4;
            }
            if (*(short *)(s0 + 0x568) <= 0) {
                *(unsigned char *)(s0 + 0x2F6) = 6;
                *(unsigned char *)(s1 + 0x2F6) = 6;
            }
        }
        break;
    case 4:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3234) + p, *(int *)(p + 0x3238) + p,
                      0.0f, 3, 0, 0);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 5:
        Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
        *(short *)(s0 + 0x434) |= 8;
        *(float *)(s0 + 0x54C) = 3.0f;
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x323C) + p, *(int *)(p + 0x3240) + p,
                      0.0f, 3, 0, 0);
        *(short *)(s0 + 0x568) = 0x1E;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 7:
        if (*(short *)(s0 + 0x568) != 0) {
            (*(short *)(s0 + 0x568))--;
            Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
            *(float *)(s0 + 0x54C) = 3.0f;
        }
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
            return;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}
