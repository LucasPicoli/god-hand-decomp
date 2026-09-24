/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int cCoreSave_getGameLevel(void *a0);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float f);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float f);
extern void func_002DB770(void);
extern void func_002705D8(void *a0);
extern char D_00462FC0[];
extern char D_00569B70[];
extern char D_007474A0[];

__attribute__((section(".text.func_00237078")))
void func_00237078(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = Obj0000_Get_D_00747A94_2DB6B0();
    char *p;
    char *q;

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0: {
        int p = *(int *)(s0 + 0x304);
        int t;

        *(char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(p + 0x240C) + p, *(int *)(p + 0x2410) + p,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0x3C;
        switch (cCoreSave_getGameLevel(D_00569B70)) {
        default:
        case 1:
            t = 0xF;
            break;
        case 2:
            t = 0x14;
            break;
        case 3:
        case 4:
            t = 0x19;
            break;
        case 5:
            t = 0x1E;
            break;
        }
        *(short *)(s0 + 0x568) = t;
        if (*(short *)(s1 + 0x54A) < 2)
            *(short *)(s0 + 0x568) = 0x3C;
        *(short *)(s0 + 0x56A) = 0x14;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    
    
    case 1:
        if (*(short *)(s0 + 0x56E) == 0)
            goto join;
        (*(short *)(s0 + 0x56E))--;
        p = *(char **)(s0 + 0xF0);
    
        q = s1 + 0x550;
        VU0_VADD_XYZ_IP(p, 0, q);
    join:
        if (moveMotion(s0) != 0) {
            *(unsigned char *)(s0 + 0x2F4) = 0;
            *(unsigned char *)(s0 + 0x2F5) = 0x6C;
            *(unsigned char *)(s0 + 0x2F6) = 0;
            *(unsigned char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s0 + 0x56A) != 0) {
            (*(short *)(s0 + 0x56A))--;
        } else {
            char *g;

            func_002DB770();
            g = D_007474A0;
            if (*(int *)(g + 8) & 0xF0)
                (*(short *)(s0 + 0x568))--;
            if (*(int *)(g + 8) & 0xF00000)
                *(short *)(s0 + 0x568) -= 4;
        }
        if (*(unsigned short *)(s0 + 0x3AC) & 0x10) {
            if (*(short *)(s0 + 0x568) <= 0) {
                *(unsigned char *)(s1 + 0x2F6) = 2;
                *(unsigned char *)(s0 + 0x2F6) = 2;
            }
            *(short *)(s0 + 0x56A) = 0x3E7;
        }
        break;
    case 2: {
        int p = *(int *)(s0 + 0x304);

        *(char *)(s0 + 0x1864) = 0;
        func_002A8578(s0, *(int *)(p + 0x2420) + p, *(int *)(p + 0x2424) + p,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0xF;
        *(unsigned char *)(s0 + 0x2F6) = *(unsigned char *)(s0 + 0x2F6) + 1;
    }
    /* fallthrough */
    case 3:
        if (*(short *)(s0 + 0x56E) != 0) {
            char *q;
            int p0;

            (*(short *)(s0 + 0x56E))--;
            q = s1 + 0x550;
            p0 = *(int *)(s0 + 0xF0);
            VU0_VADD_XYZ_IP(p0, 0, q);
        }
        if (moveMotion(s0) != 0)
            func_002705D8(s0);
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(unsigned short *)(s0 + 0x3AC) & 1) {
            char *vt = *(char **)(s0 + 0x214);
            int (*fp)() = *(int (**)())(vt + 0xAC);

            fp(s0 + *(short *)(vt + 0xA8), 0x14, 0, 0, 0);
            if (*(short *)(s0 + 0x54A) <= 0)
                *(short *)(s0 + 0x54A) = 1;
        }
        break;
    default:
        break;
    }
}
