/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void SetField444SignedByFlag434_158288(void *a0, float a1);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_0027DC50(void *a0, int a1);
extern char D_00462FC0[];

#include "godhand/vu0.h"

__attribute__((section(".text.func_0025DB70")))
void func_0025DB70(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    float v = *(float *)(s1 + 0x5A8);

    *(float *)(s0 + 0x5A8) = v;
    SetField444SignedByFlag434_158288(s0, v);
    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x33EC) + p, *(int *)(p + 0x33F0) + p,
                      0.0f, 0, 0, 0);
        if (*(void **)(s0 + 0x740) != 0)
            func_0027DC50(*(void **)(s0 + 0x740), 0);
        *(int *)(s0 + 0x16EC) = 0;
        *(short *)(s0 + 0x56A) = 0;
        (*(unsigned char *)(s0 + 0x2F6))++;
        goto tail13;
    }
    case 2:
        if (*(void **)(s0 + 0x740) != 0)
            func_0027DC50(*(void **)(s0 + 0x740), 1);
        (*(unsigned char *)(s0 + 0x2F6))++;
        /* fallthrough */
    case 1:
    case 3:
    tail13:
    {
        char *q = s1 + 0x550;
        char *p = *(char **)(s0 + 0xF0);

        *(float *)(s0 + 0x54C) = 3.0f;
        VU0_VADD_XYZ_IP(p, 0, q);
    }
        moveMotion(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s1 + 0x2F6);
        break;
    case 4:
        if (*(void **)(s0 + 0x740) != 0)
            func_0027DC50(*(void **)(s0 + 0x740), 2);
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
        /* fallthrough */
    case 5:
        *(float *)(s0 + 0x54C) = 3.0f;
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q;
            char *p;

            (*(short *)(s0 + 0x56E))--;
            p = *(char **)(s0 + 0xF0);
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p, 0, q);
        }
        moveMotion(s0);
        if (*(unsigned char *)(s0 + 0x2F6) != *(unsigned char *)(s1 + 0x2F6)) {
            if (*(short *)(s0 + 0x54A) > 0) {
                *(unsigned char *)(s0 + 0x2F6) = 6;
            } else {
                int k = 2;

                *(short *)(s0 + 0x54A) = 0;
                *(char *)(s0 + 0x2F4) = k;
                *(char *)(s0 + 0x2F5) = k;
                *(char *)(s0 + 0x2F6) = 0;
                *(char *)(s0 + 0x2F7) = 0;
            }
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 6:
    {
        int p;

        p = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(p + 0x3390) + p, *(int *)(p + 0x3394) + p,
                      0.0f, 3, 0, 0);
        if (*(void **)(s0 + 0x740) != 0)
            func_0027DC50(*(void **)(s0 + 0x740), 3);
        *(short *)(s0 + 0x56E) = 0xF;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 7:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q;
            char *p;

            q = s1 + 0x550;
            (*(short *)(s0 + 0x56E))--;
            p = *(char **)(s0 + 0xF0);
            do {
                VU0_VADD_XYZ_IP(p, 0, q);
            } while (0);
            *(float *)(s0 + 0x54C) = 3.0f;
        }
        if (moveMotion(s0) != 0)
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}
