/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void PushGlobalD8478History_331C78(int a0);
extern char D_003DED70[];

__attribute__((section(".text.check_cd_status")))
void check_cd_status(void) {
    D_003D8490 = 1;
    PushGlobalD8478History_331C78(0x2600);
    D_003D848C = func_00399A68();
    PushGlobalD8478History_331C78(0x2601);
    D_003D8490 = 0;
}

__attribute__((section(".text.mfCiExecServer")))
void mfCiExecServer(void) {
    char *p = D_003DED70;
    int i;
    for (i = 0x27; i >= 0; i--) {
        if (*p != 0) {
            func_00336498(p);
        }
        p += 0x38;
    }
}

__attribute__((section(".text.func_001507B8")))
void func_001507B8(float *a0, float *a1, float *a2)
{
    a0[0] = a1[0] * a2[0];
    a0[1] = a1[1] * a2[1];
    a0[2] = a1[2] * a2[2];
    a0[3] = 1.0f;
}
