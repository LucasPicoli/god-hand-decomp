/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error();
extern void func_00347E58(void *a0, int a1);
extern void Forward345D58_345D40(void *a0, int a1);
extern void MWSFPLY_SetFlowLimit(void *a0);
extern void func_003358B8(int a0);
extern void func_00342FF8(void *a0);
extern void ADXSTM_ReleaseFileNw(void *a0);
extern void ADXSTM_BindFileNw(void *a0, int a1, int a2, int a3, int a4);
extern void ADXSTM_SetEos(void *a0, void *a1);
extern void SFX_SetClipping(void *a0, int a1, int a2, int a3, int a4, int a5);
extern void sfxcnv_MakeDstBufInf(void *a0, int a1, int a2, void *a3, int a4);

__attribute__((section(".text.mwPlyStartSeamless")))
void mwPlyStartSeamless(char *a0) {
    void *obj;
    void *vtable;
    void (*method)(void *);
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458F10);
        return;
    }
    func_00347E58(a0, 1);
    Forward345D58_345D40(a0, *(int *)(a0 + 0x1C0));
    MWSFPLY_SetFlowLimit(a0);
    func_003358B8(*(int *)(a0 + 0x48));
    obj = *(void **)(a0 + 0x1BC);
    if (obj != 0) {
        vtable = *(void **)obj;
        method = *(void (**)(void *))((char *)vtable + 0x14);
        method(obj);
    }
    func_00342FF8(a0);
    *(int *)(a0 + 0x2D4) = 0;
}

__attribute__((section(".text.MWSTM_SetFileRange")))
void MWSTM_SetFileRange(void *a0, int a1, int a2, int a3, void *a4) {
    ADXSTM_ReleaseFileNw(a0);
    ADXSTM_BindFileNw(a0, a1, a2, a3, (int)a4);
    ADXSTM_SetEos(a0, a4);
}

__attribute__((section(".text.SFX_Make1PlaneCftDstBuf")))
int SFX_Make1PlaneCftDstBuf(void *a0, int a1, int a2, int *a3, int a4, int a5, int a6, int a7) {
    SFX_SetClipping(a0, a1, a4, a5, a6, a7);
    sfxcnv_MakeDstBufInf(a0, a1, a2, a3, 0);
    *a3 = 1;
    return 1;
}
