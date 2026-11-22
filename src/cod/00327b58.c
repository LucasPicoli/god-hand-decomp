/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

/* cygnus-2.96 matched TU. */

extern char D_003D04D0[];
extern void ADXSTMF_SetupHandleMember(char *e, int a0, int a1, int a2, int a3);

__attribute__((section(".text.ADXSTMF_CreateCvfsRt")))
int ADXSTMF_CreateCvfsRt(int a0, int a1, int a2, int a3) {
    int i;
    char *e = 0;
    for (i = 0; i < D_003D04B8; i++) {
        e = &D_003D04D0[(D_003D04B4 + i) * 0x60];
        if (e[0] == 0) break;
    }
    if (i == D_003D04B8) return 0;
    ADXSTMF_SetupHandleMember(e, a0, a1, a2, a3);
    e[3] = 1;
    return (int)e;
}
