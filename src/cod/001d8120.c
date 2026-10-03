/* sn-2.95.3-136 matched TU. */

/* Bet-adjust screen of a casino game, second variant: step 0 sets up, step 1 reads the pad (confirm, cancel, leave, raise the bet by 100 and pay it in) and refreshes the eight payout numbers. */
#include "godhand/cCoreSave.h"

extern void func_001DD770(void *a0, int a1);
extern void func_001DD840(void *a0, int a1);
extern void func_001DD910(void *a0, int a1);
extern void func_001DD9E0(void *a0, int a1);
extern void func_001DD5A0(void *a0, int a1);
extern void SetBlendField630_1DDD08(void *a0, int a1);
extern void CustomIDWork_SetNumber_1DD218(char *a0, int a1);
extern void SetCustomIDNumberIndexed_1DD648(char *a0, int a1, int a2);
extern int cSnd_SeCall_2CB8A0(void *a0, int a1, int a2, int a3, int t0, int t1, int t2);
extern int D_007474A0;
extern unsigned char D_005FEE00[];

__attribute__((section(".text.func_001D8120")))
void func_001D8120(void *a0) {
    char *o = (char *)a0;
    char *g;

    switch (*(unsigned char *)(o + 0x3025)) {
    case 0:
        func_001DD9E0(o, 0);
        SetBlendField630_1DDD08(o, 1);
        *(unsigned char *)(o + 0x3025) = *(unsigned char *)(o + 0x3025) + 1;
        /* fallthrough */
    case 1:
        g = (char *)&D_007474A0;
        if (*(long *)(g + 0x1B0) & 0xCC0000C000000L) {
            if (*(int *)(o + 0x3034) < *(int *)(o + 0x3030)) {
                func_001DD9E0(o, 1);
                SetBlendField630_1DDD08(o, 0);
                *(unsigned char *)(o + 0x3025) = 0;
                *(unsigned char *)(o + 0x3024) = 2;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1B0) & 0x3300003000000L) {
            func_001DD9E0(o, 1);
            SetBlendField630_1DDD08(o, 0);
            if (*(int *)(o + 0x3034) != 0) {
                *(unsigned char *)(o + 0x3025) = 0;
                *(unsigned char *)(o + 0x3024) = 3;
            } else {
                *(unsigned char *)(o + 0x3025) = 0;
                *(unsigned char *)(o + 0x3024) = 1;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15F, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1A0) & 0x10000000) {
            cCoreSave_addGold(&D_00569B70, *(int *)(o + 0x3034), 0);
            *(int *)(o + 0x3034) = 0;
            CustomIDWork_SetNumber_1DD218(o, 0);
            *(unsigned char *)(o + 0x3025) = 0;
            *(unsigned char *)(o + 0x3024) = 0x15;
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x15E, -1, -1, 0, 0);
        } else if (*(long *)(g + 0x1A0) & 0x20000000) {
            if (*(int *)(o + 0x3034) > 0) {
                cCoreSave_addGold(&D_00569B70, 0x64, 0);
                *(int *)(o + 0x3034) = *(int *)(o + 0x3034) - 0x64;
                CustomIDWork_SetNumber_1DD218(o, *(int *)(o + 0x3034));
                func_001DD770(o, 1);
                func_001DD840(o, 1);
                if (*(int *)(o + 0x3034) == 0) {
                    func_001DD910(o, 2);
                    func_001DD5A0(o, 1);
                }
            } else {
                *(unsigned char *)(o + 0x3025) = 0;
                *(unsigned char *)(o + 0x3024) = 0x15;
            }
            cSnd_SeCall_2CB8A0(D_005FEE00, 0, 0x161, -1, -1, 0, 0);
        }
        break;
    }
    SetCustomIDNumberIndexed_1DD648(o, 0, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0x32 : 0x32);
    SetCustomIDNumberIndexed_1DD648(o, 1, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0x14 : 0x14);
    SetCustomIDNumberIndexed_1DD648(o, 2, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0xF : 0xF);
    SetCustomIDNumberIndexed_1DD648(o, 3, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 0xA : 0xA);
    SetCustomIDNumberIndexed_1DD648(o, 4, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(o, 5, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 8 : 8);
    SetCustomIDNumberIndexed_1DD648(o, 6, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 3 : 3);
    SetCustomIDNumberIndexed_1DD648(o, 7, *(int *)(o + 0x3034) ? *(int *)(o + 0x3034) * 2 : 2);
}
