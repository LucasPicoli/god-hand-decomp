/* cygnus-2.96: once audio and video analysis finish, take the stream rate and channel count from the
 * MPS header, the video info or the ADX info, store them and continue. */
#include "godhand/sftim.h"

typedef struct MpsInfo {
    int set;                    /* 0x00 */
    int rate;                   /* 0x04 */
    int ch;                     /* 0x08 */
} MpsInfo;

typedef struct MpsAud {
    int on;                     /* 0x00 */
    char pad4[8];
    int rate;                   /* 0x0C */
    char pad10[0x24];
    int scale;                  /* 0x34 */
} MpsAud;

typedef struct MpsWork {
    int done;                   /* 0x000 */
    int rate;                   /* 0x004 */
    int ch;                     /* 0x008 */
    MpsAud aud;                 /* 0x00C */
    char pad44[0x8A0 - 0x44];
    MpsInfo mps;                /* 0x8A0 */
    char pad8AC[0xAD0 - 0x8AC];
    MpsInfo vid;                /* 0xAD0 */
    char padADC[0xD0C - 0xADC];
    MpsInfo adx;                /* 0xD0C */
    char padD18[0xDC4 - 0xD18];
    int num;                    /* 0xDC4 */
} MpsWork;

typedef struct MpsHn {
    char pad0[0x36B0];
    MpsWork *work;              /* 0x36B0 */
} MpsHn;

extern int sfsee_IsAudioAnalyzing(int a0, int a1, int a2);
extern int sfsee_IsVideoAnalyzing(void *a0, int *a1, int *a2);
extern int sfsee_IsMpsStream(void *h);
extern int UTY_MulDiv(int a, int b, int c);
extern void sfsee_UpdateEByteRate(int a0);

__attribute__((section(".text.sfsee_ExecHeadAnaly")))
void sfsee_ExecHeadAnaly(MpsHn *sfd)
{
    MpsWork *w = sfd->work;
    MpsAud *aud = &w->aud;
    MpsInfo *mps = &w->mps;
    MpsInfo *vid = &w->vid;
    MpsInfo *adx = &w->adx;
    int afound;
    int vfound;
    int ch;
    int rate;

    if (w->done != 0) {
        return;
    }
    if (sfsee_IsAudioAnalyzing((int)sfd, (int)adx, (int)&afound) != 0) {
        return;
    }
    if (sfsee_IsVideoAnalyzing(sfd, (int *)vid, &vfound) != 0) {
        return;
    }
    if (sfsee_IsMpsStream(sfd) != 0) {
        mps->set = 1;
        if (aud->on == 0) {
            rate = mps->rate;
        } else if (aud->rate > 0) {
            int scale = aud->scale;
            if (w->num > 0 && scale > 0)
                rate = UTY_MulDiv(w->num, 1000, scale);
            else
                rate = aud->rate;
        } else if (Obj34D8_GetTri78_Times100(sfd) < 108) {
            rate = (mps->rate << 11) / 2018;
        } else {
            rate = mps->rate;
        }
        ch = mps->ch;
    } else if (vfound != 0) {
        rate = vid->rate;
        ch = vid->ch;
    } else if (afound != 0) {
        rate = adx->rate;
        ch = adx->ch;
    } else {
        return;
    }
    w->rate = rate;
    w->ch = ch;
    w->done = 1;
    sfsee_UpdateEByteRate((int)sfd);
}
