/* cygnus-2.96: Sofdec picture skip, steps the stream joint past one picture and counts it as skipped (0x3537C0). */
#include "godhand/sftim.h"
#include "godhand/MpvHandle.h"

__attribute__((section(".text.sfmpv_SkipFrm")))
int sfmpv_SkipFrm(SftimHn *hn, SjObj *sj)
{
    SfdWork *w;
    MpvHandle *mpv;
    MpvPicAtr *pic;
    int start;
    int r;
    int dt;
    int ret;

    w = hn->work;
    mpv = w->dec;
    sfmpv_SetSkipTtu(hn);
    start = SJRBF_GetFlowCnt(sj, 0, 1);
    pic = &w->pic;
    r = func_00369FB8(mpv, sj);
    dt = SJRBF_GetFlowCnt(sj, 0, 1) - start;
    ret = sfmpv_ChkMpvErr(hn, r, dt, 0xFF000F07);
    sfmpv_AddRtotSj(hn, dt);
    if (ret == 0) {
        if ((signed char)pic->picStruct == 0) {
            w->f16C = 1;
        }
        SFPLY_AddSkipPic(hn, 1, pic->picType);
        return 0;
    }
    return ret;
}
