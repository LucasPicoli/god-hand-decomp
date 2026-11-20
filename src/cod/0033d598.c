/* cygnus-2.96 matched TU. */
#include "godhand/adxbSte.h"

/* After a decode pass: count the samples the blocks produced (the last block
 * only up to the end of the data), and when the write position runs past the
 * output ring, copy the overhang back to its start. */
__attribute__((section(".text.func_0033D598")))
void func_0033D598(AdxbSte *adx)
{
    AdxbSteWork *work;
    int frameLen;
    int nblk;
    int rest;
    int ringDist;
    int ringLen;
    short *obuf;
    int perFrame;
    int wpos;
    int ndec;
    int nch;
    int last;
    int len;
    int pad;

    work = &adx->work;
    frameLen = work->frameLen;
    last = work->total + frameLen - 1;
    ringLen = adx->ringLen;
    nblk = last / frameLen;
    rest = last % frameLen;
    pad = frameLen - rest - 1;
    obuf = work->obuf;
    ringDist = adx->ringDist;
    perFrame = work->perFrame;
    wpos = work->wpos;
    ndec = Obj33F8_GetWord_10_FB60(adx->xpd);
    nch = work->nch;
    len = ndec * frameLen / nch;
    adx->outGain = ndec * perFrame;
    if (ndec >= nblk * nch) {
        len -= pad;
    }
    adx->outLen = len;
    wpos += len;
    if (wpos >= ringLen) {
        wpos -= ringLen;
        if (work->nch == 2 || adx->unkE8 != 0) {
            ADXB_CopyExtraBufSte(obuf, ringLen, ringDist, wpos);
        } else {
            Forward33D4D8_33D578(obuf, ringLen, ringDist, wpos);
        }
    }
}
