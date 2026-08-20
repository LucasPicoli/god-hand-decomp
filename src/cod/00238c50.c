/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DCE8(char *a0);
extern int cCoreSave_getGameLevel(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002705D8(void *a0);
extern int D_00569B70;
extern char D_00462FC0[];

/* sn-2.95.3-136 matched TU. */













#include "godhand/vu0.h"

__attribute__((section(".text.func_00238C50")))
void func_00238C50(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x33CC) + p, *(int *)(p + 0x33D0) + p,
                      0.0f, 0, 0, 0);
        if (*(void **)(s0 + 0x740) != 0) {
            Obj0000_Set_Bytes_2F4_2F5_2F6_2F7_27DCE8(*(char **)(s0 + 0x740));
        }
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 1:
        *(float *)(s0 + 0x54C) = 3.0f;
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
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 2:
    {
        int p;

        *(char *)(s0 + 0x1864) = 0;
        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x33D4) + p, *(int *)(p + 0x33D8) + p,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0xF;
        *(float *)(s0 + 0x54C) = 5.0f;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        default:
        case 1: *(float *)(s0 + 0x16E4) = 180.0f; break;
        case 2: *(float *)(s0 + 0x16E4) = 150.0f; break;
        case 3: *(float *)(s0 + 0x16E4) = 120.0f; break;
        case 4: *(float *)(s0 + 0x16E4) = 120.0f; break;
        case 5: *(float *)(s0 + 0x16E4) = 90.0f; break;
        }
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
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
        if (moveMotion(s0) != 0) {
            if (cCoreSave_getGameLevel(&D_00569B70) < 3) {
                *(char *)(s0 + 0x2F4) = 0;
                *(unsigned char *)(s0 + 0x2F5) = 0x6C;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            } else {
                func_002705D8(s0);
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    }
}
