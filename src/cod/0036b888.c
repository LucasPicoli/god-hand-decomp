/* cygnus-2.96: SFD stream-joint write up to the next start code after the header, with the video
 * header hook on channel 1 and a capture copy on channel 3; -1 when no start code is found. */
#include "godhand/mwsfd.h"
#include "godhand/criSj.h"

typedef struct {
    char pad0[0x3B8];
    int cur;                    /* 0x3B8 */
    SfdSjCh ch[4];             /* 0x3BC */
    char *cap;                  /* 0x3EC */
    int capMax;                 /* 0x3F0 */
    int capLen;                 /* 0x3F4 */
} SfdSjWriter;

extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern int MPV_CheckDelim(void *p);
extern int mpvhdec_DecSeqUdsc(SfdSjWriter *s, char *data, int n);

__attribute__((section(".text.mpvhdec_AnalyUd")))
int mpvhdec_AnalyUd(SfdSjWriter *s, char *data, int n)
{
    int cur = s->cur;
    int i;
    int err;
    int r;
    SjObj *sj;
    SjChunk ck;
    SjChunk ck2;

    r = 0;
    for (i = 4; i < n - 3; i++) {
        if (MPV_CheckDelim(data + i) != 0)
            break;
    }
    err = (i == n - 3) ? -1 : 0;
    if (cur == 1)
        r = mpvhdec_DecSeqUdsc(s, data, i);
    sj = s->ch[cur].sj;
    if (sj != 0) {
        sj->vt->getChunk(sj, 0, i, &ck);
        func_003A5148(ck.data, data, ck.len);
        sj->vt->putChunk(sj, 1, &ck);
        if (ck.len < i) {
            sj->vt->getChunk(sj, 0, i - ck.len, &ck2);
            func_003A5148(ck2.data, data + ck.len, ck2.len);
            sj->vt->putChunk(sj, 1, &ck2);
        }
        if (s->ch[cur].cb != 0)
            s->ch[cur].cb(s->ch[cur].arg, cur);
    }
    if (cur == 3 && s->cap != 0) {
        s->capLen = i < s->capMax ? i : s->capMax;
        func_003A5148(s->cap, data, s->capLen);
    }
    if (r != 0)
        return r;
    return err;
}
