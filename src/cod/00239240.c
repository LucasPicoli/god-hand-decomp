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

__attribute__((section(".text.func_00239240")))
void func_00239240(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3BD8) + p, *(int *)(p + 0x3BDC) + p,
                      0.0f, 0, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(short *)(s0 + 0x568) = 0xF; break;
        case 2: *(short *)(s0 + 0x568) = 0x14; break;
        case 3: case 4: *(short *)(s0 + 0x568) = 0x19; break;
        case 5: *(short *)(s0 + 0x568) = 0x1E; break;
        }
        *(short *)(s0 + 0x56A) = 0x1E;
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
            p0 = *(int *)(s0 + 0xF0);
            do { } while (0);
            q = s1 + 0x550;
            VU0_LQC2(4, p0, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p0, 0);
        }
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s0 + 0x56A) > 0) {
            *(short *)(s0 + 0x56A) = *(unsigned short *)(s0 + 0x56A) - 1;
            func_002DB770();
            {
                char *g = D_007474A0;
                if ((*(int *)(g + 8) & 0xF0) != 0)
                    *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
                if ((*(int *)(g + 8) & 0xF00000) != 0)
                    *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 4;
            }
        } else if (*(short *)(s0 + 0x568) <= 0) {
            int k = 2;

            do {
                *(unsigned char *)(s0 + 0x2F6) = k;
                *(unsigned char *)(s1 + 0x2F6) = k;
            } while (0);
        }
        break;
    case 2:
    {
        int p;
        int one = 1;

        p = *(int *)(s0 + 0x304);
        *(char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(p + 0x3BE0) + p, *(int *)(p + 0x3BE4) + p,
                      0.0f, 3, 0, 0);
        *(int *)(s0 + 0x5F0) = one;
        *(float *)(s0 + 0x54C) = 15.0f;
        *(short *)(s0 + 0x568) = 0x28;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
        if (*(short *)(s0 + 0x568) != 0) {
            *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
            Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
        }
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
            break;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 0x1) != 0) {
            if (*(int *)(s0 + 0x5F0) != 0) {
                char *vt = *(char **)(s0 + 0x214);
                int (*fp)() = *(int (**)())(vt + 0xAC);

                fp(s0 + *(short *)(vt + 0xA8), 0xA, s1, 1, 0);
                if (*(short *)(s0 + 0x54A) <= 0)
                    *(short *)(s0 + 0x54A) = 1;
            }
        }
        break;
    default:
        break;
    }
}
