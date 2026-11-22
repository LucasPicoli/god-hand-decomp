/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void NoOp_33E6A8(void);
extern void NoOp_33E6B0(void);
extern void SndVol_applyRate(void *o, float f, int a1, int a2);
extern void ADXSTM_SetEos(void *a0, void *a1);
extern void adxt_start_sj(void *a0, void *a1);
extern void MWSFD_SetReqSvrBdrHn(int a0, int a1);
extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern void mwPlySetSeamlessLp(void *a0, int a1);
extern void mwPlyReleaseSeamless(void *a0);

__attribute__((section(".text.ADXT_SetReloadTime")))
void ADXT_SetReloadTime(void *o, float f, int a1, int a2) {
    NoOp_33E6A8();
    SndVol_applyRate(o, f, a1, a2);
    NoOp_33E6B0();
}

__attribute__((section(".text.adxt_start_stm")))
void adxt_start_stm(void *o, int a1, int a2, int a3, int a4) {
    func_00328C80(*(int *)((char *)o + 8), *(short *)((char *)o + 0x3E) << 11, *(short *)((char *)o + 0x3C) << 11);
    ADXSTM_SetEos((void *)*(int *)((char *)o + 8), D_003D1404);
    ADXSTM_EntryEosFunc(*(int *)((char *)o + 8), 0, 0);
    func_003280D8(*(int *)((char *)o + 8), 0);
    ADXSTM_StopNw(*(int *)((char *)o + 8));
    ADXSTM_ReleaseFileNw(*(int *)((char *)o + 8));
    ADXSTM_BindFileNw(*(int *)((char *)o + 8), a1, a2, a3, a4);
    func_003281C8(*(int *)((char *)o + 8));
    adxt_start_sj(o, *(void **)((char *)o + 0x10));
}

__attribute__((section(".text.mwsfsvr_ExecForceSvrBdr")))
void mwsfsvr_ExecForceSvrBdr(int a0) {
    int i;
    for (i = 0; i < 10; i++) {
        MWSFD_SetReqSvrBdrHn(a0, 1);
        ADXM_WaitVsync();
        MWSFD_SetReqSvrBdrHn(a0, 0);
        if (*(int *)(a0 + 0x60) != 1) break;
    }
}

__attribute__((section(".text.mwPlyReleaseLp")))
void mwPlyReleaseLp(char *a0) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458FD8);
        return;
    }
    mwPlySetSeamlessLp(a0, 0);
    mwPlyReleaseSeamless(a0);
    *(int *)(a0 + 0x2E8) = 4;
}
