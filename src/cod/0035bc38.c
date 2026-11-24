/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

extern void mpvlib_InitObj(void *);
extern void UTY_MemcpyDword(void *, void *, int);
extern void mpvlib_InitPicAtr(void *);
extern int D_00766CE8;
extern void sftrn_CallTrEntry(int, int);

__attribute__((section(".text.mpvlib_InitHn")))
void *mpvlib_InitHn(MpvHandle *hn) {
    int i;
    mpvlib_InitObj(hn);
    hn->unk18C = 0;
    UTY_MemcpyDword(hn->cond, &D_00766CE8, 0x10);
    func_00369E80(&hn->err);
    mpvlib_InitPicAtr(&hn->picAtr);
    hn->unk384 = 0;
    hn->unk3A8 = hn->cond[7];
    hn->unk388 = 0;
    hn->codec = 0;
    hn->unk360 = 0;
    hn->unk364 = 0;
    hn->unk368 = 0;
    hn->unk398 = 0;
    for (i = 0; i < 4; i++)
        Obj0000_Set_Field_3BC_Triple(hn, i, 0, 0, 0);
    MPV_SetPicUsrBuf(hn, 0, 0);
    hn->stopReq = 0;
    hn->stat = MPV_HN_USED;
    return hn;
}

__attribute__((section(".text.sftrn_CallTrEntry1_35BC38")))
void sftrn_CallTrEntry1_35BC38(int a0, int a1) {
    sftrn_CallTrEntry(a0, 1);
}
