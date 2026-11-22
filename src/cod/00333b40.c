/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
#include "godhand/criAix.h"
#include "godhand/MpvHandle.h"

extern long long func_003A9228(int a0, int *buf, int size);
extern void LogPrintf(char *fmt, int val);

/* prev is the start code decoded before this one; it is not read here. */
__attribute__((section(".text.mpvhdec_DecEscSj")))
int mpvhdec_DecEscSj(MpvHandle *hn, SjObj *sj, int prev) {
    SjChunk tail;
    SjChunk *ck;
    int start;
    int word;
    int bits;
    int end;

    ck = &hn->ck;
    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, ck);

    start = (int)ck->data;
    word = start & -4;
    bits = (start - word) << 3;
    end = word + (bits >> 3) + 4;
    SJ_SplitChunk(ck, end - start, ck, &tail);

    sj->vt->putChunk(sj, 0, ck);
    sj->vt->ungetChunk(sj, 1, &tail);

    MPV_GoNextDelimSj(sj);

    return 0;
}

__attribute__((section(".text.func_00333B40")))
int func_00333B40(int a0, int *a1, int *a2) {
    int buf[4];
    char *p;

    buf[0] = a0;
    *a1 = func_003A9228(a0, buf, 0x10);

    p = (char *)buf[0];
    if (*p) buf[0] = (int)(p + 1);

    if (a2) *a2 = func_003A9228(buf[0], buf, 0x10);

    LogPrintf(D_00454570, a0);
    LogPrintf(D_00454588, *a1);
    LogPrintf(D_00454598, *a2);

    return 1;
}
