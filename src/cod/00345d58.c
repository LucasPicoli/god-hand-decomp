/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern void MWSFD_SetProhibitServer(int a0);
extern void func_00345DF0(void *a0);
extern void mw_sfd_start_ex(void *a0);
extern void func_00342FF8(void *a0);
extern void Forward345D58_345D40(void *a0, int a1);
extern void MWSFPLY_ReqStartAfs(void *a0, int a1, int a2);
extern void func_0036CA38(void *a0, int a1);
extern void MWSST_SetOutVol(void *a0, int a1);

/* MATCH via cygnus-2.96. */







__attribute__((section(".text.mwply_StartSj")))
void mwply_StartSj(char *a0, int a1) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458038);
        return;
    }
    MWSFD_SetProhibitServer(1);
    func_00345DF0(a0);
    *(int *)(a0 + 0x1BC) = a1;
    *(int *)(a0 + 0x1D4) = 0;
    *(int *)(a0 + 0x1D0) = 2;
    *(int *)(a0 + 0x1D8) = 0;
    *(int *)(a0 + 0x1DC) = 0;
    mw_sfd_start_ex(a0);
    MWSFD_SetProhibitServer(0);
    func_00342FF8(a0);
}

/* MATCH via cygnus-2.96. */






__attribute__((section(".text.mwPlyStartAfs")))
void mwPlyStartAfs(int a0, int a1, int a2) {
    if (GetField0OrZero_346828((void *)a0) != 1) {
        MWSFSVM_Error(D_00458110);
        return;
    }
    Forward345D58_345D40((void *)a0, mwPlyGetInputSj((void *)a0));
    MWSFPLY_ReqStartAfs((void *)a0, a1, a2);
}

/* MATCH via cygnus-2.96. */





__attribute__((section(".text.mwPlySetOutVol")))
void mwPlySetOutVol(char *a0, int a1) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458628);
        return;
    }
    func_0036CA38(a0, a1);
    MWSST_SetOutVol(a0 + 0x284, a1);
    MWSST_SetOutVol(a0 + 0x2A4, a1);
}
