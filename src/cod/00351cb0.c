/* cygnus-2.96 matched TU. */
#include "godhand/sftim.h"
#include "godhand/MpvHandle.h"

/* The picture size check (condition 0x5F) and the sequence header hook (conditions 0x4D and 0x4E). */
typedef int (*SfdPicSizeFn)(void *obj, int width, int height);
typedef void (*SfdSeqHdrFn)(void *obj, Sint8 *data, int len);

/* Decode the next picture header from the stream joint into the work area's picture info, then take its
 * user data, time stamps and timecode; the first picture also sets up the stream. */
__attribute__((section(".text.sfmpv_DecodePicAtr")))
int sfmpv_DecodePicAtr(SftimHn *hn, SjChunk *ck, SjObj *sj, unsigned int flags, int *res)
{
    SfdWork *w = hn->work;
    SfdUsrRec *usr = &w->usrRec;
    MpvPicAtr *pic = &w->pic;
    MpvHandle *mpv = w->dec;
    int t0;
    int n;
    int r;
    unsigned int f40;
    SfdSeqHdrFn fn;
    void *obj;
    Sint8 *p;
    long pts;
    long time;
    int k;
    int v;

    usr->buf.len = 0;
    MPV_SetPicUsrBuf(mpv, usr->buf.buf, usr->size);
    t0 = SJRBF_GetFlowCnt(sj, 0, 1);
    *res = MPV_DecodePicAtrSj(mpv, sj);
    n = SJRBF_GetFlowCnt(sj, 0, 1) - t0;
    r = sfmpv_ChkMpvErr(hn, *res, n, 0xFF000F04);
    sfmpv_AddRtotSj(hn, n);
    if (r != 0)
        return r;
    if (*res == -2)
        return 0;
    *res = MPV_GetPicAtr(mpv, pic);
    if (*res != 0)
        return func_0034DD70(hn, 0xFF000F05);
    f40 = flags & 0x40;
    if (f40) {
        if (hn->mv.width > 0) {
            if (hn->mv.width != pic->width || hn->mv.height != pic->height) {
                *res = -2;
                return 0;
            }
        }
        {
            SfdPicSizeFn cb = (SfdPicSizeFn)GetArrayElemA0C_35A1C8(hn, 0x5F);
            void *o = (void *)GetArrayElemA0C_35A1C8(hn, 0x5F);   /* retail reads 0x5F again for the object */

            if (cb != 0 && cb(o, pic->width, pic->height) != 0) {
                *res = -2;
                return 0;
            }
        }
    }
    k = pic->picType;
    if (k == 1) {
        w->xOfs = 0;
    } else if (hn->mode == 3) {
        SfdFrm *ref = w->ref;

        if (ref != 0) {
            v = ref->pic.ofs;
            if (k == 2) {
                if (pic->ofs < v && v < 0x200)
                    w->xOfs = 1;
            } else if (k == 3) {
                if (pic->ofs >= v)
                    w->xOfs = 1;
            }
        }
    }
    MPV_GetPicUsr(mpv, 0, &usr->buf.len);
    if (w->f10C != pic->f30) {
        w->f10C = pic->f30;
        w->f110 = 1;
    } else {
        w->f110 = 0;
    }
    if (f40) {
        fn = (SfdSeqHdrFn)GetArrayElemA0C_35A1C8(hn, 0x4D);
        obj = (void *)GetArrayElemA0C_35A1C8(hn, 0x4E);
        if (fn != 0) {
            Sint8 *q = MPV_SearchDelim(ck->data, ck->len, MPV_DLM_SLICE_NEXT);   /* bit 0: any slice */

            if (q != 0)
                fn(obj, ck->data, q - ck->data + 4);
        }
    }
    p = MPV_SearchDelim(ck->data, ck->len, MPV_DLM_PSC);
    sfmpv_ReadPtsQue(hn, pic, p, &pts, &time, w->f110);
    w->time = time;
    if (!(flags & w->f78))
        return 0;
    sfmpv_CalcRepeatField(hn, pic, w->f110);
    sfmpv_ReformTc(hn, pic, pts, w->f110);
    sfmpv_SetHeadTtu(hn, pic);
    SftimHn_recordLastFrame(hn, pic);
    return sfmpv_FirstPicAtr(hn, mpv, pic, ck);
}
