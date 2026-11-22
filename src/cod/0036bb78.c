/* cygnus-2.96 matched TU. */
#include "godhand/criAix.h"
#include "godhand/MpvHandle.h"

/* cygnus-2.96 */

__attribute__((section(".text.MPV_GoNextDelimSj")))
unsigned int MPV_GoNextDelimSj(SjObj *sj)
{
    SjChunk ck;
    SjChunk ck2;
    Sint8 *p;
    unsigned int code;

    while (sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck), ck.len >= 4) {
        p = MPV_SearchDelim(ck.data, ck.len, 0xFFFFFFFF);
        if (p == 0) {
            SJ_SplitChunk(&ck, ck.len - 3, &ck, &ck2);
            sj->vt->putChunk(sj, 0, &ck);
            sj->vt->ungetChunk(sj, 1, &ck2);
        } else {
            code = MPV_CheckDelim(p);
            SJ_SplitChunk(&ck, p - ck.data, &ck, &ck2);
            sj->vt->putChunk(sj, 0, &ck);
            sj->vt->ungetChunk(sj, 1, &ck2);
            goto done;
        }
    }
    sj->vt->ungetChunk(sj, 1, &ck);
    code = 0;
done:
    return code;
}
