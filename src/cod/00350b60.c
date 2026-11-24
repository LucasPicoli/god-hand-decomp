/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

extern void sfmpv_SetTermDst(void *a0, int a1);
extern void SFSET_SetCond(void *a0, int a1, int a2);
extern void *memcpy(void *, const void *, unsigned int);

__attribute__((section(".text.sfmpv_ChkTermFlg")))
void sfmpv_ChkTermFlg(char *a0) {
    int *p = (int *)(a0 + 0x950);
    int r = SFMPVF_GetNumFrm(a0);
    if (r != -1) {
        if (sfmpv_IsFinalFrmGotten(a0, r) == 0)
            return;
    }
    sfmpv_SetTermDst(a0, 1);
    if (*p != 0)
        return;
    SFSET_SetCond(a0, 5, 0);
}

__attribute__((section(".text.MPV_SetErrFunc")))
int MPV_SetErrFunc(MpvHandle *hn, MpvErrFn fn, void *obj) {
    MpvErr *err;
    if (hn == 0) {
        err = &D_003F1AA0;
    } else {
        if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(hn))
            return func_00369F20(0, 0xFF030203);
        err = &hn->err;
    }
    err->fn = fn;
    err->obj = obj;
    return 0;
}

__attribute__((section(".text.MPV_RequestStop")))
void MPV_RequestStop(MpvHandle *hn) {
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(hn)) {
        func_00369F20(0, 0xFF030211);
        return;
    }
    hn->stopReq = 1;
    if (hn->codec == MPV_CODEC_M2V)
        MPVM2V_RequestStop(hn);
}

__attribute__((section(".text.MPV_GetVbvBufSiz")))
int MPV_GetVbvBufSiz(MpvHandle *hn, int *p1, int *p2, int *p3) {
    int a0v;
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(hn))
        return func_00369F20(0, 0xFF03020F);
    *p1 = hn->blocks << 11;
    *p2 = hn->c;
    a0v = hn->bitRate;
    if (a0v == 0x3FFFF)
        *p3 = -1;
    else
        *p3 = (hn->c * a0v) / 0x708;
    return 0;
}

__attribute__((section(".text.MPV_GetPicAtr")))
int MPV_GetPicAtr(MpvHandle *hn, MpvPicAtr *atr) {
    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(hn))
        return func_00369F20(0, 0xFF03020C);
    memcpy(atr, &hn->picAtr, sizeof(MpvPicAtr));
    return 0;
}
