/* cygnus-2.96: adxsjd_discard_proc, skips the bytes all channel stream joints have available (rounded to an
 * even count) and subtracts the per-channel amount from the pending total. */
#include "godhand/criSj.h"

typedef struct AdxChDec {
    char pad0[2];
    signed char nch;                    /* 0x02 */
    char pad3[9];
    SjObj *sj[(0xA4 - 0xC) / 4];     /* 0x0C */
    int pending;                        /* 0xA4 */
} AdxChDec;

__attribute__((section(".text.adxsjd_discard_proc")))
void adxsjd_discard_proc(AdxChDec *dec)
{
    SjChunk ck;
    int i;
    int n;
    int half;

    n = dec->pending * 2;
    for (i = 0; i < dec->nch; i++) {
        dec->sj[i]->vt->getChunk(dec->sj[i], 1, 0x7FFFFFFF, &ck);
        n = (n < ck.len) ? n : ck.len;
        dec->sj[i]->vt->ungetChunk(dec->sj[i], 1, &ck);
    }
    half = n / 2;
    n = half * 2;
    if (n > 0) {
        for (i = 0; i < dec->nch; i++) {
            dec->sj[i]->vt->getChunk(dec->sj[i], 1, n, &ck);
            dec->sj[i]->vt->putChunk(dec->sj[i], 0, &ck);
        }
        dec->pending -= half;
    }
}
