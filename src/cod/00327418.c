/* cygnus-2.96: skip-and-copy step like adxsjd_discard_proc, with the pending count at 0xA0: copied chunks
 * are cleared before they go on lane 1. */
#include "godhand/criSj.h"

typedef struct AdxSjDec {
    char pad0[2];
    signed char nch;                    /* 0x02 */
    char pad3[9];
    SjObj *sj[(0xA0 - 0xC) / 4];     /* 0x0C */
    int pending;                        /* 0xA0 */
} AdxSjDec;

extern void *func_003A52F0(void *dst, int c, int n);

__attribute__((section(".text.adxsjd_insert_proc")))
void adxsjd_insert_proc(AdxSjDec *dec)
{
    SjChunk ck;
    int i;
    int n;
    int half;

    n = dec->pending * 2;
    for (i = 0; i < dec->nch; i++) {
        dec->sj[i]->vt->getChunk(dec->sj[i], 0, 0x7FFFFFFF, &ck);
        n = (n < ck.len) ? n : ck.len;
        dec->sj[i]->vt->ungetChunk(dec->sj[i], 0, &ck);
    }
    half = n / 2;
    n = half * 2;
    if (n > 0) {
        for (i = 0; i < dec->nch; i++) {
            dec->sj[i]->vt->getChunk(dec->sj[i], 0, n, &ck);
            func_003A52F0(ck.data, 0, n);
            dec->sj[i]->vt->putChunk(dec->sj[i], 1, &ck);
        }
        dec->pending -= half;
    }
}
