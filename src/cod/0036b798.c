/* cygnus-2.96: MPV decode one unit from the stream joint, then skip to the next delimiter (0x36B798). */
#include "godhand/criAix.h"
#include "godhand/MpvHandle.h"

/* prev is the start code decoded before this one; it is not read here. */
__attribute__((section(".text.mpvhdec_DecUdscSj")))
int mpvhdec_DecUdscSj(MpvHandle *hn, SjObj *sj, int prev)
{
    SjChunk tail;
    SjChunk *ck;
    char *p;
    int base;
    int bit;
    int ret;

    base = ~3;
    ck = &hn->ck;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, ck);
    p = ck->data;
    base &= (int)p;
    bit = ((int)p - base) * 8;
    base += 8;
    ret = mpvhdec_AnalyUd(hn, p, hn->ck.len);
    base += bit >> 3;
    base -= 4;
    SJ_SplitChunk(ck, base - (int)ck->data, ck, &tail);
    sj->vt->putChunk(sj, 0, ck);
    sj->vt->ungetChunk(sj, 1, &tail);
    MPV_GoNextDelimSj(sj);
    return ret;
}
