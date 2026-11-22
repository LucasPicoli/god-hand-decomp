/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern unsigned char D_003EB710[];
extern unsigned short D_003EB810[];

__attribute__((section(".text.adxf_SetCmdHstry")))
void adxf_SetCmdHstry(int a, int b, int c, int d, int e) {
    int i;
    unsigned char *slot;

    i = D_003EB830;
    i = i % 16;
    slot = &D_003EB710[i * 16];
    D_003EB830 = i;
    if (b == 0) {
        D_003EB810[a] = D_003EB810[a] + 1;
    }
    *(int *)(slot + 0xC) = e;
    slot[0] = a;
    slot[1] = b;
    *(int *)(slot + 4) = c;
    *(int *)(slot + 8) = d;
    D_003EB830 = D_003EB830 + 1;
    *(short *)(slot + 2) = D_003EB810[a];
}
