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
extern void func_00129718(void *a0, void *a1, int a2);
extern int D_00569B70;
extern char D_00462FC0[];
extern char D_007474A0[];

#include "godhand/vu0.h"















__attribute__((section(".text.func_00236190")))
void func_00236190(void *a0)
{
    char *s1 = (char *)a0;
    char *s2 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
    switch (*(unsigned char *)(s1 + 0x2F6)) {
    case 0:
    {
        int p;

        *(char *)(s1 + 0x1864) = 0;
        p = *(int *)(s1 + 0x304);
        func_002A8578(s1, *(int *)(p + 0x518) + p, *(int *)(p + 0x51C) + p,
                      0.0f, 0, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(short *)(s1 + 0x568) = 0x5; break;
        case 2: *(short *)(s1 + 0x568) = 0xA; break;
        case 3: case 4: *(short *)(s1 + 0x568) = 0xF; break;
        case 5: *(short *)(s1 + 0x568) = 0x14; break;
        }
        *(short *)(s1 + 0x56A) = 4;
        *(short *)(s1 + 0x56E) = 0xF;
        *(short *)(s1 + 0x56C) = 1;
        (*(unsigned char *)(s1 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        if (*(short *)(s1 + 0x56E) != 0) {
            char *q;
            int p0;

            (*(short *)(s1 + 0x56E))--;
            p0 = *(int *)(s1 + 0xF0);
            do { } while (0);
            q = s2 + 0x550;
            VU0_LQC2(4, p0, 0);
            VU0_LQC2(5, q, 0);
            VU0_VADD_XYZ(4, 4, 5);
            VU0_SQC2(4, p0, 0);
        }
        {
            char *g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0) {
                (*(short *)(s1 + 0x568))--;
            }
            if ((*(int *)(g + 8) & 0xF00000) != 0) {
                *(short *)(s1 + 0x568) -= 4;
            }
        }
        *(float *)(s1 + 0x54C) = 3.0f;
        if (moveMotion(s1) != 0) {
            func_002705D8(s1);
            return;
        }
        AddScaledVecToField_100_14F9F0(s1, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s1, 1.0f);
        if ((*(unsigned short *)(s1 + 0x3AC) & 0x10) != 0) {
            if (*(short *)(s1 + 0x568) <= 0) {
                *(char *)(s1 + 0x2F4) = 1;
                *(char *)(s1 + 0x2F6) = 0;
                *(char *)(s1 + 0x2F5) = 0x1D;
                (*(unsigned char *)(s1 + 0x2F7))++;
                Forward_001346C8_00134608_1351D8(D_00462FC0, s1, 0);
                func_00129718(s2, s1, 0x1D);
            }
            func_002DB770();
            *(short *)(s1 + 0x56C) = 0;
        } else {
            if (*(short *)(s1 + 0x56C) != 0) {
                func_002DB770();
            }
        }
        break;
    default:
        break;
    }
}
