/* cygnus-2.96: SFD stream-joint write up to the next start code after the header, with the video
 * header hook on channel 1 and a capture copy on channel 3; -1 when no start code is found. */
#include "godhand/MpvHandle.h"

extern void *func_003A5148(void *d, const void *s, unsigned int n);

__attribute__((section(".text.mpvhdec_AnalyUd")))
int mpvhdec_AnalyUd(MpvHandle *hn, char *data, int n)
{
    int cur = hn->cur;
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
        r = mpvhdec_DecSeqUdsc(hn, data, i);
    sj = hn->ch[cur].sj;
    if (sj != 0) {
        sj->vt->getChunk(sj, 0, i, &ck);
        func_003A5148(ck.data, data, ck.len);
        sj->vt->putChunk(sj, 1, &ck);
        if (ck.len < i) {
            sj->vt->getChunk(sj, 0, i - ck.len, &ck2);
            func_003A5148(ck2.data, data + ck.len, ck2.len);
            sj->vt->putChunk(sj, 1, &ck2);
        }
        if (hn->ch[cur].cb != 0)
            hn->ch[cur].cb(hn->ch[cur].arg, cur);
    }
    if (cur == 3 && hn->usr.buf != 0) {
        hn->usr.len = i < hn->usr.size ? i : hn->usr.size;
        func_003A5148(hn->usr.buf, data, hn->usr.len);
    }
    if (r != 0)
        return r;
    return err;
}
