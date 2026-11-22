/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error();
extern void MWSFPLY_RecordFname(void *a0, int a1);
extern void func_00335950(int a0);
extern void MwsfdHn_forwardStmRequest(void *a0, int a1, int a2, int a3);
extern void mwPlySetSeamlessLp(void *a0, int a1);
extern void mwPlyStartSeamless(void *a0);
extern void mwPlyEntryFname(void *a0, int a1);
extern void func_00347AF8(void *a0, int a1, int a2);

__attribute__((section(".text.mwPlyStartFnameRangeLp")))
void mwPlyStartFnameRangeLp(char *a0, int a1, int a2, int a3) {
    int r = GetField0OrZero_346828(a0);
    if (r != 1) {
        MWSFSVM_Error(D_00459110);
        return;
    }
    MWSFPLY_RecordFname(a0, a1);
    func_00335950(*(int *)(a0 + 0x48));
    MwsfdHn_forwardStmRequest(a0, a1, a2, a3);
    mwPlySetSeamlessLp(a0, 1);
    mwPlyStartSeamless(a0);
    *(int *)(a0 + 0x2E4) = 3;
    *(int *)(a0 + 0x2F4) = a2;
    *(int *)(a0 + 0x2F8) = a3;
    *(int *)(a0 + 0x2DC) = r;
    if (*(int *)(a0 + 0x2E0) == 0) {
        *(int *)(a0 + 0x2E8) = r;
    }
}

__attribute__((section(".text.mwPlyStartFnameLp")))
void mwPlyStartFnameLp(char *a0, int a1) {
    int r = GetField0OrZero_346828(a0);
    if (r != 1) {
        MWSFSVM_Error(D_00458F78);
        return;
    }
    if (a1 == 0) {
        MWSFSVM_Error(D_00458FA8);
        return;
    }
    MWSFPLY_RecordFname(a0, a1);
    func_00335950(*(int *)(a0 + 0x48));
    mwPlyEntryFname(a0, *(int *)(a0 + 0x1A4));
    mwPlySetSeamlessLp(a0, 1);
    mwPlyStartSeamless(a0);
    *(int *)(a0 + 0x2E4) = r;
    *(int *)(a0 + 0x2DC) = r;
    if (*(int *)(a0 + 0x2E0) == 0) {
        *(int *)(a0 + 0x2E8) = r;
    }
}

__attribute__((section(".text.mwPlyStartAfsLp")))
void mwPlyStartAfsLp(char *a0, int a1, int a2) {
    int r = GetField0OrZero_346828(a0);
    if (r != 1) {
        MWSFSVM_Error(D_004590A8);
        return;
    }
    func_00335950(*(int *)(a0 + 0x48));
    func_00347AF8(a0, a1, a2);
    mwPlySetSeamlessLp(a0, 1);
    mwPlyStartSeamless(a0);
    *(int *)(a0 + 0x2E4) = 2;
    *(int *)(a0 + 0x2EC) = a1;
    *(int *)(a0 + 0x2F0) = a2;
    *(int *)(a0 + 0x2DC) = r;
    if (*(int *)(a0 + 0x2E0) == 0) {
        *(int *)(a0 + 0x2E8) = r;
    }
}
