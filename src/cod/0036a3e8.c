/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

/* Decode the picture header from the stream joint: step through the start codes (sequence, group, picture,
 * extension, user data) up to the next picture data or sequence end; MPEG-2 streams go to the M2V side. */
__attribute__((section(".text.MPV_DecodePicAtrSj")))
int MPV_DecodePicAtrSj(MpvHandle *hn, SjObj *sj)
{
    SjChunk ck;
    SjChunk ck2;
    int d;
    int prev;
    int r;

    if (Obj0000_Set_D_00766D44_Check_Field_188_NE_2(hn) != 0)
        return func_00369F20(0, 0xFF03020C);
    hn->usr.len = 0;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
    sj->vt->ungetChunk(sj, 1, &ck);
    ck2.data = ck.data;
    ck2.len = ck.len;
    if (mpvhdec_GetCodec(hn, &ck2) == MPV_CODEC_M2V)
        return MPVM2V_DecodePicAtr(hn, sj);
    prev = 0;
    for (;;) {
        r = mpvhdec_RecoverSj(hn, -1, sj);
        if (r != 0)
            return func_00369F20(hn, r);
        d = mpvhdec_GetCurDelim(sj);
        if (d == 0)
            break;
        if (d & MPV_DLM_SLICE)
            break;
        if (d & MPV_DLM_SEC) {
            r = -2;
            break;
        }
        switch (d) {
        case MPV_DLM_SHC:
            prev = MPV_DLM_SHC;
            mpvhdec_DecShcSj(hn, sj);
            break;
        case MPV_DLM_GSC:
            prev = MPV_DLM_GSC;
            mpvhdec_DecGscSj(hn, sj);
            break;
        case MPV_DLM_PSC:
            prev = MPV_DLM_PSC;
            mpvhdec_DecPscSj(hn, sj);
            break;
        case MPV_DLM_ESC:
            mpvhdec_DecEscSj(hn, sj, prev);
            break;
        case MPV_DLM_UDSC:
            mpvhdec_DecUdscSj(hn, sj, prev);
            break;
        }
    }
    return r;
}
