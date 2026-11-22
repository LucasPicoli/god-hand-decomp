/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

__attribute__((section(".text.mpvhdec_GetCurDelim")))
int mpvhdec_GetCurDelim(SjObj *sj)
{
    SjChunk ck;

    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
    sj->vt->ungetChunk(sj, 1, &ck);
    if (ck.len < 4) return 0;
    return MPV_CheckDelim(ck.data);
}
