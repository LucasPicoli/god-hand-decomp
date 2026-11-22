/* cygnus-2.96: SFD ring-buffer write and per-channel term / done checks (0x34F200..). */

#include "godhand/sftim.h"

typedef struct SfdRbSpan {
    char *ptr0;                 /* 0x00 */
    int len0;                   /* 0x04 */
    char *ptr1;                 /* 0x08 */
    int len1;                   /* 0x0C */
    int unk10;
    int tag;                    /* 0x14 */
} SfdRbSpan;

typedef struct SfdPtsReq {
    long pts;                   /* 0x00 */
    char *ptr;                  /* 0x08 */
    int len;                    /* 0x0C */
} SfdPtsReq;

typedef struct SfdUsrPts {
    long pts;                   /* 0x00 */
    int len;                    /* 0x08 */
} SfdUsrPts;

extern int func_0034C2A0(SfdWork *w, int ch, SfdRbSpan *span);
extern int func_0034C378(SfdWork *w, int ch, int len, int tag);
extern int SFPTS_IsPtsQueFull(SfdWork *w, int ch);
extern int SFPTS_WritePtsQue(SfdWork *w, int ch, SfdPtsReq *req, void *out);
extern int MEM_Copy(void *dst, const void *src, int n);
extern int (*D_003EE2FC)(void *obj, SfdUsrPts *pts);

__attribute__((section(".text.sfmps_CopyDstBuft")))
int sfmps_CopyDstBuft(SfdWork *w, int ch, char *src, int len, long pts)
{
    SfdRbSpan span;
    SfdPtsReq req;
    SfdUsrPts usr;
    char out[0x10];
    char *ptr0, *ptr1;
    int len0, tag;
    int r;

    r = func_0034C2A0(w, ch, &span);
    if (r != 0) {
        return r;
    }
    ptr0 = span.ptr0;
    len0 = span.len0;
    ptr1 = span.ptr1;
    tag = span.tag;
    if (len0 + span.len1 < len) {
        return 0;
    }
    if (ch == 1) {
        if (pts >= 0) {
            if (SFPTS_IsPtsQueFull(w, 1) != 0) {
                return 0;
            }
            req.pts = pts;
            req.ptr = ptr0;
            req.len = len;
            r = SFPTS_WritePtsQue(w, 1, &req, out);
            if (r != 0) {
                return r;
            }
        }
    } else if (ch == 2) {
        if (D_003EE2FC != 0) {
            usr.pts = pts;
            usr.len = len;
            if (D_003EE2FC((char *)w + 0x12E0, &usr) == -1) {
                return 0;
            }
        }
    }
    if (len0 >= len) {
        MEM_Copy(ptr0, src, len);
    } else {
        MEM_Copy(ptr0, src, len0);
        MEM_Copy(ptr1, src + len0, len - len0);
    }
    r = func_0034C378(w, ch, len, tag);
    return r == 0 ? 1 : r;
}

extern void SFBUF_SetTermFlg(SfdWork *w, int ch, int flag);
extern int SFBUF_GetTermFlg(SfdWork *w, int ch);
extern void SFMPVP_Flush(SfdWork *w, int a1);

__attribute__((section(".text.sfmps_SetTermDst")))
void sfmps_SetTermDst(SfdWork *w, int a1)
{
    SfdChIds *ch = &w->ch;

    if (ch->video != SFD_CH_NONE) {
        SFBUF_SetTermFlg(w, ch->video, 1);
    }
    if (ch->audio != SFD_CH_NONE) {
        SFBUF_SetTermFlg(w, ch->audio, 1);
    }
    if (ch->other != SFD_CH_NONE) {
        SFBUF_SetTermFlg(w, ch->other, 1);
    }
    SFMPVP_Flush(w, a1);
}

__attribute__((section(".text.sfmps_GetTermDst")))
int sfmps_GetTermDst(SfdWork *w)
{
    SfdChIds *ch = &w->ch;
    int done = 1;

    if (ch->video != SFD_CH_NONE) {
        done = SFBUF_GetTermFlg(w, ch->video) & 1;
    }
    if (ch->audio != SFD_CH_NONE) {
        done &= SFBUF_GetTermFlg(w, ch->audio);
    }
    if (ch->other != SFD_CH_NONE) {
        done &= SFBUF_GetTermFlg(w, ch->other);
    }
    return done;
}
