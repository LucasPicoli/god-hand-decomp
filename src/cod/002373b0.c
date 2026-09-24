/* sn-2.95.3-136 matched TU. */

/* func_002373B0, 784 B, sn-2.95.3-136. Wave 2026-08-30 VU0P parked + nested Duff do{}while(0) before case 1 (label 0x002374E0, 0 mod 8; dispatch beq slot filled from before so no beql), case 3 store order 2F4 2F5 2F6 2F7. */
/* sn-2.95.3-136 matched TU. */

extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void func_002A8578(void *a0, int a1, int a2, float a3, int a4, int a5, int a6);
extern int cCoreSave_getGameLevel(void *a0);
extern void Forward_001346C8_00134608_1351D8(void *a0, void *a1, int a2);
extern int moveMotion(void *a0);
extern void AddScaledVecToField_100_14F9F0(void *a0, float a1);
extern void AddScaledXfmVecToField_F0_14F928(void *a0, float a1);
extern void func_002DB770(void);
extern int D_00569B70;
extern char D_00462FC0[];
extern char D_007474A0[];

#include "godhand/vu0.h"

__attribute__((section(".text.func_002373B0")))
void func_002373B0(void *a0)
{
    char *s0 = (char *)a0;
    char *s1 = (char *)Obj0000_Get_D_00747A94_2DB6B0();
    char *p;
    char *q;
    int b;

    Forward_001346C8_00134608_1351D8(D_00462FC0, s0, 0);
    *(float *)(s0 + 0x54C) = 3.0f;
    switch (*(unsigned char *)(s0 + 0x2F6)) {
    case 0:
        *(char *)(s0 + 0x1864) = 0;
        b = *(int *)(s0 + 0x304);
        func_002A8578(s0, *(int *)(b + 0x20D8) + b, *(int *)(b + 0x20DC) + b,
                      0.0f, 0, 0, 0);
        *(short *)(s0 + 0x56E) = 0x3C;
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(short *)(s0 + 0x568) = 0xF; break;
        case 2: *(short *)(s0 + 0x568) = 0x14; break;
        case 3: case 4: *(short *)(s0 + 0x568) = 0x19; break;
        case 5: *(short *)(s0 + 0x568) = 0x1E; break;
        }
        if (*(short *)(s1 + 0x54A) < 2)
            *(short *)(s0 + 0x568) = 0x19;
        *(short *)(s0 + 0x56A) = 0x5A;
        (*(unsigned char *)(s0 + 0x2F6))++;
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
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if (*(short *)(s1 + 0x54A) > 0) {
            if (*(short *)(s0 + 0x56A) != 0) {
                *(short *)(s0 + 0x56A) = *(unsigned short *)(s0 + 0x56A) - 1;
            } else {
                func_002DB770();
                {
                    char *g = D_007474A0;
                    if ((*(int *)(g + 8) & 0xF0) != 0)
                        *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 1;
                    if ((*(int *)(g + 8) & 0xF00000) != 0)
                        *(short *)(s0 + 0x568) = *(unsigned short *)(s0 + 0x568) - 4;
                }
            }
            if ((*(unsigned short *)(s0 + 0x3AC) & 0x10) != 0) {
                if (*(short *)(s1 + 0x54A) > 0 && *(short *)(s0 + 0x568) <= 0) {
                    (*(unsigned char *)(s1 + 0x2F6))++;
                    (*(unsigned char *)(s0 + 0x2F6))++;
                }
                *(short *)(s0 + 0x56A) = 0x3E7;
            }
        }
        break;
    case 2:
    {
        int k = 3;
        *(unsigned char *)(s0 + 0x2F6) = k;
    }
        /* fallthrough */
    case 3:
        if (moveMotion(s0) != 0) {
            *(char *)(s0 + 0x2F4) = 0;
            *(char *)(s0 + 0x2F5) = 0x6C;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        AddScaledVecToField_100_14F9F0(s0, 1.0f);
        AddScaledXfmVecToField_F0_14F928(s0, 1.0f);
        if ((*(unsigned short *)(s0 + 0x3AC) & 0x1) != 0) {
            char *vt = *(char **)(s0 + 0x214);
            int (*fp)() = *(int (**)())(vt + 0xAC);

            fp(s0 + *(short *)(vt + 0xA8), 0x32, 0, 0, 0);
            if (*(short *)(s0 + 0x54A) <= 0)
                *(short *)(s0 + 0x54A) = 1;
            *(char *)(s0 + 0x2F4) = 1;
            *(char *)(s0 + 0x2F5) = 0x15;
            *(char *)(s0 + 0x2F6) = 0;
            *(char *)(s0 + 0x2F7) = 0;
        }
        break;
    default:
        break;
    }
}
