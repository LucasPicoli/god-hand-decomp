/* cygnus-2.96: Sofdec picture decode helpers (0x353928..). */

#include "godhand/sftim.h"

extern int SFMPVP_IsSceMpegUsed(SftimHn *hn);
extern int func_00356C58(SftimHn *hn);
extern int UTY_MulDiv(int a, int b, int c);
void sfmpv_CalcFrmTime(SftimHn *hn, SfdFrm *ft);
extern SfdFrm *SFMPVF_AllocFrm(SftimHn *hn);
extern void SFMPVF_EndRefFrm(SfdFrm *frm);
extern void sfmpv_CopyPicUsrInf(SfdUsrBuf *dst, SfdUsrBuf *src);
extern void *func_003A5148(void *d, const void *s, unsigned int n);    /* memcpy */
void sfmpv_PeekNextPicUd(SjObj *sj, int *type, unsigned char **ext, int *extLen);
int sfmpv_SetFrmPara(SftimHn *hn, MpvPicAtr *pic, SfdOut *out, SfdFrm **pfrm);
void SfdWork_getPicOffset(SftimHn *hn, SfdWork *work, int *x, int *y);
void sfmpv_SetStartTtu(SftimHn *hn);
void sfmpv_SetFrmTime(SftimHn *hn, SfdFrm *ft);
void sfmpv_ChangePicUd(SftimHn *hn, SfdFrm *ft, SjObj *sj);
extern int SfdHn_acceptsRequest(SftimHn *hn, int ptype);
extern int sfmpv_IsPtypeSkip(SftimHn *hn, unsigned int ptype);

__attribute__((section(".text.sfmpv_SetFrmPara")))
int sfmpv_SetFrmPara(SftimHn *hn, MpvPicAtr *pic, SfdOut *out, SfdFrm **pfrm)
{
    SfdWork *work = hn->work;
    SfdErr *err = &hn->errInf;
    SfdFrm *frm;

    if (work->hold != 0) {
        *pfrm = work->hold;
    } else {
        *pfrm = SFMPVF_AllocFrm(hn);
        if (*pfrm == 0) {
            err->err = 1;
            return -1;
        }
    }
    frm = *pfrm;
    frm->pic = *pic;
    frm->decTime = work->time;
    if (hn->mode == 3) {
        int mbw;
        int mbh;
        int yw;
        int cw;
        int yofs;
        int cofs;
        int yp;
        int cp;
        unsigned char *cur;
        unsigned char *ref;

        if ((pic->picType == 1 || pic->picType == 2) && work->hold == 0) {
            SFMPVF_EndRefFrm(work->cur);
            work->cur = work->ref;
            work->ref = *pfrm;
        }
        mbw = (pic->width + 15) / 16;
        yw = (mbw * 16 + 63) / 64;
        cw = (mbw * 8 + 63) / 64;
        mbh = (pic->height + 15) / 16;
        cur = work->cur->buf;
        ref = work->ref->buf;
        yofs = yw * mbh * 1024;
        cofs = cw * mbh * 512;
        yp = yw * 64;
        cp = cw * 64;
        out->cur.yPitch = yp;
        out->cur.cPitch = cp;
        out->cur.base = cur;
        out->cur.y = cur + yofs;
        out->cur.c = cur + yofs + cofs;
        out->ref.yPitch = yp;
        out->ref.cPitch = cp;
        out->ref.base = ref;
        out->ref.y = ref + yofs;
        out->ref.c = ref + yofs + cofs;
    } else {
        SfdPlane *plane;

        if (pic->picType == 1 || pic->picType == 2) {
            work->ref = frm;
            work->curIdx ^= 1;
            work->refIdx ^= 1;
        }
        plane = work->plane;
        out->cur = plane[work->curIdx];
        out->ref = plane[work->refIdx];
    }
    out->buf = (*pfrm)->buf;
    out->pic = &(*pfrm)->pic;
    out->f28 = 0;
    out->f2C = 0;
    err->err = 0;
    return 0;
}

/* Write the picture offset to *x, *y for picture types 2 and 3 while the
   handle is in mode 3; 0, 0 otherwise. */
__attribute__((section(".text.SfdWork_getPicOffset")))
void SfdWork_getPicOffset(SftimHn *hn, SfdWork *work, int *x, int *y)
{
    if (hn->mode == 3) {
        switch (work->pic.picType) {
        case 1:
            break;
        case 2:
            *x = work->cur->x;
            *y = work->cur->y;
            return;
        case 3:
            *x = work->cur->x + work->ref->x;
            *y = work->cur->y + work->ref->y;
            return;
        }
    }
    *x = 0;
    *y = 0;
}

__attribute__((section(".text.sfmpv_SetStartTtu")))
void sfmpv_SetStartTtu(SftimHn *hn)
{
    SftimRec *rec = &hn->tim.rec[5];
    SftimRec *start = &hn->tim.rec[0];

    if (rec->valid == 0) {
        SftimTc tc = hn->tim.rec[3].tc;
        int time;
        int unit;

        if (SfdHn_acceptsRequest(hn, 3) == 0 && sfmpv_IsPtypeSkip(hn, 3) == 0) {
            tc.frameAdd = 0;
        }
        SFTIM_Tc2Time(&tc, &time, &unit);
        rec->tc = tc;
        rec->time = time - start->time;
        rec->unit = unit;
        rec->valid = 1;
    }
}

__attribute__((section(".text.sfmpv_SetFrmTime")))
void sfmpv_SetFrmTime(SftimHn *hn, SfdFrm *ft)
{
    ft->rec = hn->tim.rec[3];
    if (SFMPVP_IsSceMpegUsed(hn) != 0) {
        ft->count = func_00356C58(hn);
    }
    sfmpv_CalcFrmTime(hn, ft);
}

__attribute__((section(".text.sfmpv_CalcFrmTime")))
void sfmpv_CalcFrmTime(SftimHn *hn, SfdFrm *ft)
{
    SftimWork *w = &hn->tim;
    SftimRec *rec = &ft->rec;

    ft->unit = rec->unit;
    ft->time = rec->time - hn->tim.rec[5].time + w->f164;
    ft->ptsTime = rec->time;
    ft->dispTime = rec->time + w->f164;
    if (SFMPVP_IsSceMpegUsed(hn) != 0) {
        ft->ptsTime = UTY_MulDiv(ft->unit, (ft->count - w->f160) * 1000, D_00459920[ft->pic.rate]);
        ft->time = ft->dispTime = ft->ptsTime + w->f164;
    }
    if (w->f284 < ft->time) {
        w->f284 = ft->time;
        w->f288 = ft->unit;
    }
}

__attribute__((section(".text.sfmpv_ChangePicUd")))
void sfmpv_ChangePicUd(SftimHn *hn, SfdFrm *ft, SjObj *sj)
{
    SfdWork *work = hn->work;
    int type;
    unsigned char *ext;
    int extLen;

    if (ft->pic.picType == 1 || ft->pic.picType == 2) {
        sfmpv_CopyPicUsrInf(&work->usr, ft->usr);
    }
    sfmpv_PeekNextPicUd(sj, &type, &ext, &extLen);
    if (type == 3) {
        func_003A5148(ft->usr->buf, ext, extLen);
        ft->usr->len = extLen;
    } else {
        sfmpv_CopyPicUsrInf(ft->usr, &work->usr);
    }
}
