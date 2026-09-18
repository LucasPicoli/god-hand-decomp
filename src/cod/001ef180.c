/* sn-2.95.3-136 matched TU. */

#include "godhand/vu0.h"

extern int cSnd_SeCall(void *a0, int a1, short a2, int a3, int a4, int a5);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern void func_001F30B8(char *a0, int a1);
extern void func_001F33F8(char *a0, int a1, int a2);
extern void func_001F3488(char *a0, int a1);

extern void cCoreSave_SetFightingRingClearFlag(char *a0, int a1, int a2);
extern int cCoreSave_getClearNum(char *a0);
extern void cCoreSave_setGold(char *a0, int a1);
extern int GetTimerValue_1FA710(char *a0);
extern void cCoreSave_addGold(char *a0, int a1, int a2);
extern void classFADE_start(void *p, int b, int c, int d, int e, unsigned int f, int g);
extern void cScenario_beginRoomJump_2C4548(char *p, int a1, float f, void *buf, int a3, unsigned int t0, int t1);
extern void NoOp_1F0490(char *a0);
extern void func_001F28F0(char *a0);
extern void func_001F2990(char *a0);
extern char D_00569B70[];
extern char D_005FEE00[];
extern char D_00747470[];
extern int D_005CAFF0;
extern int D_00747A24[];
extern long D_00747640;
extern unsigned char D_0074748C;
extern char *D_003C2F84;

__attribute__((section(".text.func_001EF180")))
void func_001EF180(void *a0)
{
    char *s1 = (char *)a0;
    char buf[16];
    int done;
    int all;
    int i;

    switch (*(int *)(s1 + 0x8)) {
    case 0:
        cSnd_SeCall(D_005FEE00, 0, 0x35, D_005CAFF0 + 0x210, 0, 0);
        func_001F30B8(s1 + 0x60, 1);
        *(int *)(s1 + 0x10) = 0x3C;
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 1:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        if (func_001FC4D0(D_00569B70, *(short *)(s1 + 0xB60)) == 0) {
            cCoreSave_SetFightingRingClearFlag(D_00569B70, *(short *)(s1 + 0xB60), 1);
            if ((*(int *)(*(int *)D_00569B70 + 0x14) & 0x800000) == 0) {
                all = 1;
                i = 1;
                for (; i < 0x33; i++) {
                    if (func_001FC4D0(D_00569B70, i) == 0) {
                        all = 0;
                        break;
                    }
                }
                if (all != 0) {
                    *(int *)(*(int *)D_00569B70 + 0x14) = *(int *)(*(int *)D_00569B70 + 0x14) | 0x800000;
                }
            } else {
                if (func_001FC4D0(D_00569B70, 0x33) != 0) {
                    if ((*(int *)(*(int *)D_00569B70 + 0x14) & 0x400000) == 0) {
                        *(int *)(s1 + 0x54) = *(int *)(s1 + 0x54) | 0x10;
                    }
                    *(int *)(*(int *)D_00569B70 + 0x14) = *(int *)(*(int *)D_00569B70 + 0x14) | 0x400000;
                    D_00747A24[1] = D_00747A24[1] | 0x400000;
                }
            }
            cCoreSave_addGold(D_00569B70, *(int *)(s1 + 0xB70), 0);
        }
        *(int *)(s1 + 0x10) = 0x3C;
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 2:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        all = 0;
        if (cCoreSave_getClearNum(D_00569B70) == 0) {
            if ((*(int *)(*(int *)D_00569B70 + 0x14) & 0x20000) == 0) {
                i = 1;
                all = 1;
                for (; i < 0x29; i++) {
                    if (func_001FC4D0(D_00569B70, i) == 0) {
                        all = 0;
                        break;
                    }
                }
            }
        }
        if (all != 0) {
            *(int *)(s1 + 0xBA4) = 0xC350;
            *(int *)(*(int *)D_00569B70 + 0x14) = *(int *)(*(int *)D_00569B70 + 0x14) | 0x20000;
            func_001F30B8(s1 + 0x60, 0);
            *(int *)(s1 + 0x10) = 0x1E;
            *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        } else {
            *(int *)(s1 + 0x10) = 0x1E;
            *(int *)(s1 + 0x8) = 6;
        }
        break;
    case 3:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F33F8(s1 + 0x60, 1, *(int *)(s1 + 0xBA4));
        *(int *)(s1 + 0x10) = 0x1E;
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 4:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        *(int *)(s1 + 0xBA8) = *(int *)(s1 + 0xBA4) / 0x3E8;
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 5:
        if (*(int *)(s1 + 0xBA8) == 0 || (D_00747640 & 0xF00000000L) != 0) {
            cCoreSave_setGold(D_00569B70, GetTimerValue_1FA710(D_00569B70) + *(int *)(s1 + 0xBA8) * 0x3E8);
            *(int *)(s1 + 0x10) = 0x1E;
            *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
            *(int *)(s1 + 0xBA8) = 0;
        } else {
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x165, -1, -1, 0, 0);
            cCoreSave_setGold(D_00569B70, GetTimerValue_1FA710(D_00569B70) + 0x3E8);
            *(int *)(s1 + 0xBA8) = *(int *)(s1 + 0xBA8) - 1;
        }
        func_001F33F8(s1 + 0x60, 1, *(int *)(s1 + 0xBA8) * 0x3E8);
        break;
    case 6:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F33F8(s1 + 0x60, 0, 0);
        { long t = *(unsigned int *)(s1 + 0x54);
        if (((t >> 4) % 2L) != 0L) {
            func_001F30B8(s1 + 0x60, 0);
            *(int *)(s1 + 0x10) = 0x1E;
            *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        } else {
            *(int *)(s1 + 0x10) = 0x1E;
            *(int *)(s1 + 0x8) = 9;
        } }
        break;
    case 7:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F3488(s1 + 0x60, 2);
        *(int *)(s1 + 0x10) = 0x5A;
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 8:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F3488(s1 + 0x60, 0);
        *(int *)(s1 + 0x10) = 0x1E;
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 9:
        if (*(int *)(s1 + 0x10) != 0) {
            done = 0;
            *(int *)(s1 + 0x10) = *(int *)(s1 + 0x10) - 1;
        } else {
            done = 1;
        }
        if ((done & 0xFF) == 0) {
            break;
        }
        func_001F33F8(s1 + 0x60, 0, 0);
        classFADE_start(D_00747470, 0, 0xA, 0, 0, 0xFF000000u, 0xF);
        *(int *)(s1 + 0x8) = *(int *)(s1 + 0x8) + 1;
        break;
    case 10:
        if (((D_0074748C >> 2) & 1) != 0) {
            char *p = D_003C2F84;
            int h = *(unsigned short *)(p + 0x16);
            VU0_LQC2(4, p, 0x0);
            VU0_SQC2(4, buf, 0x0);
            cScenario_beginRoomJump_2C4548(p, h, *(float *)(p + 0x10), buf, 0, 0x80000000u, 1);
        }
        break;
    }
    NoOp_1F0490(s1);
    func_001F28F0(s1 + 0x60);
    func_001F2990(s1 + 0x60);
}
