/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void func_003B9DE0(void *a0);
extern int *Obj0000_Get_D_00459FA8_35F8A8(void);
extern void sfx_InitLibWork(void);
extern void func_0035FE60(void);
extern void SFXZ_Init(void);
extern void SFXA_Init(void);
extern int SFH_IsExistStmId(void *h, unsigned char id, int *out);

__attribute__((section(".text.func_003BA4F8")))
int func_003BA4F8(char *a0, unsigned char *a1) {
    unsigned int b;
    a1 += (*(int *)(a0 + 0x28) == 1);
    b = *a1;
    if ((b >> 3) >= 9) {
        func_003B9DE0(D_00460A00);
        return -1;
    }
    *(int *)(a0 + 0x38) = b & 7;
    return 0;
}

__attribute__((section(".text.sfmpv_IsPrepFrmEnough")))
int sfmpv_IsPrepFrmEnough(void *a0) {
    char *h = (char *)a0;
    int lim = *(int *)(h + 0xA68);
    int e = *(int *)(h + 0x2C);
    int pos;
    if (lim == -1) {
        lim = e;
    }
    if (e < lim) {
        lim = e;
    }
    pos = SFMPVF_GetNumFrm(a0);
    if (*(int *)(h + 0x58) == 2) {
        pos = pos + *(int *)(h + 0x968);
    }
    if (pos < lim) {
        return 0;
    }
    return 1;
}

__attribute__((section(".text.SFX_Init")))
void SFX_Init(void) {
    if (D_003EE330 <= 0) {
        D_00766CA0 = Obj0000_Get_D_00459FA8_35F8A8();
        sfx_InitLibWork();
        func_0035FE60();
        SFXZ_Init();
        SFXA_Init();
        D_003EE334 = 0;
        D_003EE330 = D_003EE330 + 1;
    }
}

__attribute__((section(".text.mwsffrm_AnalyColAdj")))
int mwsffrm_AnalyColAdj(void *a0) {
    int x;
    int y;
    int r;
    int xv;
    r = SFH_IsExistStmId(a0, 0xE0, &x);
    if (r != 1) {
        return 0;
    }
    xv = x;
    if (xv != r) {
        return 0;
    }
    if (SFH_AnlyFtrColType(a0, 0xE0, &y) != xv) {
        return 0;
    }
    return y == 3;
}
