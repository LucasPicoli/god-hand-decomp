/* cygnus-2.96: MPV decode one unit from the stream joint, then skip to the next delimiter (0x36B798). */
#include "godhand/criSj.h"
extern int mpvhdec_AnalyUd(char *h, unsigned char *p, int n);
extern void SJ_SplitChunk(SjChunk *ck, int n, SjChunk *a, SjChunk *b);
extern unsigned int MPV_GoNextDelimSj(SjObj *sj);

__attribute__((section(".text.mpvhdec_DecUdscSj")))
int mpvhdec_DecUdscSj(char *h, SjObj *sj)
{
    SjChunk tail;
    SjChunk *ck;
    unsigned char *p;
    int base;
    int bit;
    int ret;

    base = ~3;
    ck = (SjChunk *)(h + 0x38C);
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, ck);
    p = (unsigned char *)ck->data;
    base &= (int)p;
    bit = ((int)p - base) * 8;
    base += 8;
    ret = mpvhdec_AnalyUd(h, p, *(int *)(h + 0x390));
    base += bit >> 3;
    base -= 4;
    SJ_SplitChunk(ck, base - (int)ck->data, ck, &tail);
    sj->vt->putChunk(sj, 0, ck);
    sj->vt->ungetChunk(sj, 1, &tail);
    MPV_GoNextDelimSj(sj);
    return ret;
}
