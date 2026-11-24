/* cygnus-2.96 matched TU. */
#include "godhand/MpvDec.h"

__attribute__((section(".text.MPV_DecodePicAtr")))
int MPV_DecodePicAtr(MpvHandle *hn, MpvPicSrc *src, int *out)
{
    SjObj *sj;
    int r;

    sj = func_00338B90(src->work, src->size);
    if (sj == 0) return -1;
    r = MPV_DecodePicAtrSj(hn, sj);
    *out = src->size - sj->vt->getNumData(sj, 1);
    sj->vt->destroy(sj);
    return r;
}

__attribute__((section(".text.MWDMA_WaitEnd")))
void MWDMA_WaitEnd(int ch)
{
    void *p;

    p = sceDmaGetChan(ch);
    while (sceDmaSync(p, 1, 0x1E) != 0)
        ;
}
