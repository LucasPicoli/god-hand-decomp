/* cygnus-2.96 matched TU. */
#include "godhand/sftim.h"
#include "godhand/MpvHandle.h"

extern int SFBUF_GetRingBufSiz(void *hn, int f);                           /* SFBUF_GetRingBufSiz */
extern void sfmpv_SetMpvHd(void *hn, int rate, void *para);           /* sfmpv_SetMpvHd */

__attribute__((section(".text.sfmpv_FirstPicAtr")))
int sfmpv_FirstPicAtr(SftimHn *hn, MpvHandle *mpv, MpvPicAtr *pic, SjChunk *ck)
{
    unsigned int rate;
    int vbv;
    int b;
    int c;
    SfdMvInf *mv = &hn->mv;
    SfdWork *w;
    int sz;

    w = hn->work;
    if (mv->bitRate != 0)
        return 0;
    if (MPV_GetBitRate(mpv, &rate) != 0)
        return func_0034DD70(hn, 0xFF000F16);
    MPV_GetVbvBufSiz(mpv, &vbv, &b, &c);
    if (GetArrayElemA0C_35A1C8(hn, 0x3C) == 0) {
        w->f114 = 0;
    } else {
        sz = SFBUF_GetRingBufSiz(hn, 1);
        if (c == -1)
            c = vbv;
        w->f114 = c < sz ? c : sz;
    }
    sfmpv_SetMpvHd(hn, rate, ck);
    sfmpv_SetMvInf(mv, rate, pic, vbv);
    return sfmpv_ChkBufSiz(hn, mv);
}
