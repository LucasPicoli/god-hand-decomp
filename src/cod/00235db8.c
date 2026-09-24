/* sn-2.95.3-136 matched TU. */

/* func_00235DB8, 980 B, sn-2.95.3-136. Wave 2026-08-31 V1 E + block-local base per if/else arm with the argument sums in the arms (x, y at function scope). */
/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002DB770(void);
extern void func_002705D8(void *a0);
extern int D_00569B70;
extern char D_00462FC0[];
extern char D_007474A0[];

#include "godhand/vu0.h"

__attribute__((section(".text.func_00235DB8")))
void func_00235DB8(void *a0)
{
    char *s0 = (char *)a0;
    int x;
    int y;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();

    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
    {
        int p;
        int aa;
        int bb;
        int t = *(int *)(s0 + 0x564);

        *(char *)(s0 + 0x1864) = 0;
        if (t < 0x252) {
            if (t >= 0x250) goto lo0;
        }
        {
            int pa = *(int *)(s0 + 0x304);
            x = *(int *)(pa + 0xC68) + pa;
            y = *(int *)(pa + 0xC6C) + pa;
        }
        goto lm0;
    lo0:
        {
            int pb = *(int *)(s0 + 0x304);
            x = *(int *)(pb + 0x1A64) + pb;
            y = *(int *)(pb + 0x1A68) + pb;
        }
    lm0:
        func_002A8578(s0, x, y, 0.0f, 0, 0, 0);
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(short *)(s0 + 0x568) = 0xF; break;
        case 2: *(short *)(s0 + 0x568) = 0x14; break;
        case 3: case 4: *(short *)(s0 + 0x568) = 0x19; break;
        case 5: *(short *)(s0 + 0x568) = 0x1E; break;
        }
        if (*(short *)(s1 + 0x54A) < 2) {
            *(short *)(s0 + 0x568) = 0x3C;
        }
        *(short *)(s0 + 0x56E) = 0xF;
        *(short *)(s0 + 0x56A) = 0x1E;
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
             
            q = s1 + 0x550;
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F6) = 2;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s0 + 0x56A) > 0) {
            char *g;

            (*(short *)(s0 + 0x56A))--;
            func_002DB770();
            g = D_007474A0;
            if ((*(int *)(g + 8) & 0xF0) != 0) {
                (*(short *)(s0 + 0x568))--;
            }
            if ((*(int *)(g + 8) & 0xF00000) != 0) {
                *(short *)(s0 + 0x568) -= 4;
            }
            if (*(short *)(s0 + 0x568) <= 0) {
                *(unsigned char *)(s0 + 0x2F6) = 4;
                *(unsigned char *)(s1 + 0x2F6) = 4;
            }
        }
        break;
    case 2:
    {
        int p;
        int aa;
        int bb;
        int t = *(int *)(s0 + 0x564);

        *(char *)(s0 + 0x1864) = 0;
        if (t < 0x252) {
            if (t >= 0x250) goto lo2;
        }
        {
            int pa = *(int *)(s0 + 0x304);
            x = *(int *)(pa + 0xC70) + pa;
            y = *(int *)(pa + 0xC74) + pa;
        }
        goto lm2;
    lo2:
        {
            int pb = *(int *)(s0 + 0x304);
            x = *(int *)(pb + 0x1A6C) + pb;
            y = *(int *)(pb + 0x1A70) + pb;
        }
    lm2:
        func_002A8578(s0, x, y, 0.0f, 3, 0, 0);
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 3:
        Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
        *(float *)(s0 + 0x54C) = 3.0f;
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    case 4:
    {
        int p;
        int aa;
        int bb;
        int t = *(int *)(s0 + 0x564);

        *(char *)(s0 + 0x1864) = 0;
        if (t < 0x252) {
            if (t >= 0x250) goto lo4;
        }
        {
            int pa = *(int *)(s0 + 0x304);
            x = *(int *)(pa + 0xC78) + pa;
            y = *(int *)(pa + 0xC7C) + pa;
        }
        goto lm4;
    lo4:
        {
            int pb = *(int *)(s0 + 0x304);
            x = *(int *)(pb + 0x1A74) + pb;
            y = *(int *)(pb + 0x1A78) + pb;
        }
    lm4:
        func_002A8578(s0, x, y, 0.0f, 3, 0, 0);
        *(short *)(s0 + 0x568) = 0x1E;
        (*(unsigned char *)(s0 + 0x2F6))++;
    }
        /* fallthrough */
    case 5:
        if (*(short *)(s0 + 0x568) != 0) {
            (*(short *)(s0 + 0x568))--;
            Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
            *(float *)(s0 + 0x54C) = 3.0f;
        }
        if (moveMotion(s0) != 0) {
            func_002705D8(s0);
            break;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        break;
    default:
        break;
    }
}
