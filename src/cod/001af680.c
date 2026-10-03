#include "godhand/cEm00.h"

/* sn-2.95.3-136 matched TU. */

extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int t0, int t1);
extern int moveMotion(void *a0);
extern void cOmSub_initMove1_pos(void *a0, void *a1, int a2, int a3, void *t0, float f12, float f13);
extern void cOmSub_setVibration(void *a0, int a1, int a2, float f12, float f13, float f14);
extern int cOmSub_move(void *a0);
extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned int t1);
extern int cSnd_SeCall_2CBA48(void *a, int b, int c, void *d, int e, int f, int g, int h);
extern void cSnd_SeStop(void *a0, int a1);
extern void cDamageUnit_SetDamageCollActive(int a0, int a1);
extern char D_005FEE00[];
/* Phase machine on the step byte, 3 case labels. Calls cOmSub_initMove1_pos, cOmSub_setVibration,
 * func_002A8578, SetEffect, cSnd_SeCall_2CBA48, moveMotion and 3 more. */
__attribute__((section(".text.func_001AF680"))) void func_001AF680(cEm00 *self)
{
    char *s1 = (char *)self;
    float fr[4];
    switch (*(unsigned char *)(s1 + 0x2F6)) {
        case 0: {
            char *self = s1 + 0x990;
            float z;
            int v0;
            *(int *)&fr[0] = 0;
            fr[1] = -2.4f;
            *(int *)&fr[2] = 0;
            fr[3] = 1.0f;
            z = fr[0];
            cOmSub_initMove1_pos(self, s1, 0, 0xD2, fr, 0.2f, z);
            cOmSub_setVibration(self, 5, 0, 4.0f, 2.0f, z);
            v0 = *(int *)(s1 + 0x304);
            *(unsigned char *)(s1 + 0x2F6) = 1;
            *(unsigned char *)(s1 + 0x2F7) = 0;
            func_002A8578(s1, EM_RES_REC(v0, 0x10), 0, z, 0, 0, 0);
            SetEffect(0, 0x50, s1, 0, -1, 0xFFFFFFFFU);
            *(int *)(s1 + 0xAF4) = cSnd_SeCall_2CBA48(D_005FEE00, 0, 0x107, s1, 0, 0, 0, 0);
            break;
        }
        case 1: {
            int v0;
            if (moveMotion(s1) != 0) {
                v0 = *(int *)(s1 + 0x304);
                func_002A8578(s1, EM_RES_REC(v0, 0x10), 0, 0.0f, 0, 0, 0);
            }
            if (cOmSub_move(s1 + 0x990) != 0)
                break;
            *(unsigned char *)(s1 + 0xAF0) = 0;
            if (*(int *)(s1 + 0x600) != 0)
                cDamageUnit_SetDamageCollActive(*(int *)(s1 + 0x600), 0);
            *(int *)(s1 + 0x250) = *(int *)(s1 + 0x250) | 2;
            *(int *)(s1 + 0x5B8) = *(int *)(s1 + 0x5B8) | 0x2000;
            if (*(int *)(s1 + 0xAF4) != 0) {
                cSnd_SeStop(D_005FEE00, *(int *)(s1 + 0xAF4));
                *(int *)(s1 + 0xAF4) = 0;
            }
            *(unsigned char *)(s1 + 0x2F7) = 0;
            *(unsigned char *)(s1 + 0x2F6) = 2;
            break;
        }
        case 2:
            break;
    }
}
