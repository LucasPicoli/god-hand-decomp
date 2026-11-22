/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int MWSFSVM_Error(char *a0);
extern void Forward3443E0_3443C8(void *a0);

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.sfmps_RingAddRead")))
int sfmps_RingAddRead(int a0, int a1) {
    int r = SFBUF_RingAddRead(a0, *(int *)((char *)a0 + 0x1F84), a1);
    if (r == 0) {
        *(int *)((char *)a0 + 0x37A8) += a1;
    }
    return r;
}

/* MATCH via cygnus-2.96 +drop-freorder. */





__attribute__((section(".text.MWSFTAG_CreateAinfSj")))
int MWSFTAG_CreateAinfSj(char *a0) {
    int y;
    if (MWSFTAG_IsUseAinfSj(a0 + 8) != 1)
        return 0;
    y = func_003395A0(*(int *)(a0 + 0x180), *(int *)(a0 + 0x184), 0);
    if (y != 0)
        return y;
    MWSFSVM_Error(D_00458C68);
    Forward3443E0_3443C8(a0);
    return 0;
}

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.MWSST_Pause")))
void MWSST_Pause(char *a0, int a1) {
    void *obj, *arg;
    void (*f)(void *, int);
    if (MWSST_IsEnable(a0) != 1) return;
    obj = *(void **)(a0 + 0x8);
    arg = *(void **)(a0 + 0x1C);
    if (obj == 0) return;
    f = *(void (**)(void *, int))((char *)obj + 0x24);
    if (f == 0) return;
    f(arg, a1);
}

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.MWSST_SetOutVol")))
void MWSST_SetOutVol(char *a0, int a1) {
    void *obj, *arg;
    void (*f)(void *, int);
    if (MWSST_IsEnable(a0) != 1) return;
    obj = *(void **)(a0 + 0x8);
    arg = *(void **)(a0 + 0x1C);
    if (obj == 0) return;
    f = *(void (**)(void *, int))((char *)obj + 0x28);
    if (f == 0) return;
    f(arg, a1);
}

/* MATCH via cygnus-2.96 +drop-freorder. */

__attribute__((section(".text.MWSST_SetLnkSw")))
void MWSST_SetLnkSw(char *a0, int a1) {
    void *obj, *arg;
    void (*f)(void *, int);
    if (MWSST_IsEnable(a0) != 1) return;
    obj = *(void **)(a0 + 0x8);
    arg = *(void **)(a0 + 0x1C);
    if (obj == 0) return;
    f = *(void (**)(void *, int))((char *)obj + 0x30);
    if (f == 0) return;
    f(arg, a1);
}
