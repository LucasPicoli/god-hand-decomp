/* sn-2.95.3-136 matched TU. */

extern char *Obj0000_Get_D_00747A94_2DB6B0(void);
extern void cSescr_At_ck(void *a0, int a1, void *a2, float f12);
extern int cSnd_SeCall(void *a0, int a1, short a2, void *a3, int a4, int a5);
extern int cSnd_SeFadeOut(void *a0, int a1, short a2);
extern char D_005FEE00[];

#include "godhand/vu0.h"








typedef struct Blk16_2C8B68 {
    char b[0x10];
} Blk16_2C8B68;

__attribute__((section(".text.func_002C8B68")))
void func_002C8B68(char *a0)
{
    char *s0 = a0;
    char *s1 = s0 + 0x20;
    char buf[0x10];

    VU0_SQC2_VF0(buf, 0x0);
    cSescr_At_ck(s0, *(int *)(Obj0000_Get_D_00747A94_2DB6B0() + 0xF0), buf, 1.5f);
    switch (*(unsigned char *)(s0 + 0x13)) {
    case 0:
        if (*(unsigned char *)(s0 + 0xC) & 2) {
            *(unsigned char *)(s0 + 0x13) = 1;
        }
        break;
    case 1:
        if (*(unsigned short *)(s1 + 0xA) == 0) {
            int r = cSnd_SeCall(D_005FEE00, *(unsigned short *)(s1 + 0xC),
                                *(short *)(s1 + 0xE), s1 + 0x10, 0x20000, 0);

            *(int *)(s0 + 0x14) = r;
            if (r == 0) {
                *(unsigned char *)(s0 + 0xC) = 0;
                break;
            }
        }
        *(unsigned char *)(s0 + 0x13) = 2;
        break;
    case 2:
        if ((*(unsigned char *)(s0 + 0xC) & 2) == 0) {
            *(unsigned char *)(s0 + 0x13) = 3;
            break;
        }
        if (*(unsigned short *)(s1 + 0xA) == 0) {
            char *q = func_002CBF48(D_005FEE00, *(int *)(s0 + 0x14));

            if (q == 0) {
                *(unsigned char *)(s0 + 0x13) = 4;
                break;
            }
            *(Blk16_2C8B68 *)(q + 0x40) = *(Blk16_2C8B68 *)buf;
            *(short *)(q + 0x34) = (float)*(unsigned short *)(s0 + 0x10);
        }
        break;
    case 3:
        if (*(unsigned short *)(s1 + 0xA) == 0) {
            cSnd_SeFadeOut(D_005FEE00, *(int *)(s0 + 0x14), 0x1E);
        }
        *(unsigned char *)(s0 + 0x13) = 4;
        /* fall through */
    case 4:
        *(int *)(s0 + 0x14) = 0;
        *(unsigned char *)(s0 + 0x13) = 0;
        break;
    }
}
