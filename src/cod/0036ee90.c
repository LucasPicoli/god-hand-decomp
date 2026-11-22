/* cygnus-2.96: SFD stream-joint write: copy data into the current channel's SJ (wrapping once), call
 * its callback, and on channel 3 write the header. */
#include "godhand/mwsfd.h"
#include "godhand/criSj.h"
#include "godhand/globals.h"

typedef struct {
    char pad0[0x11C];
    SfdSjCh ch[4];
    int open;
    char pad150[0x524 - 0x150];
    int hdr;
    char pad528[0x580 - 0x528];
    int cur;
} SfdSjHdrWriter;

extern void *func_003A5148(void *d, const void *s, unsigned int n);
extern void appendUd(SfdSjHdrWriter *s, char *data, int n);

__attribute__((section(".text.m2vhdec_AnalyUd")))
void m2vhdec_AnalyUd(SfdSjHdrWriter *s, char *data, int n)
{
    int cur = s->cur;
    SjObj *sj = s->ch[cur].sj;
    SjChunk ck;
    SjChunk ck2;

    if (sj != 0) {
        sj->vt->getChunk(sj, 0, n, &ck);
        func_003A5148(ck.data, data, ck.len);
        sj->vt->putChunk(sj, 1, &ck);
        if (ck.len < n) {
            sj->vt->getChunk(sj, 0, n - ck.len, &ck2);
            func_003A5148(ck2.data, data + ck.len, ck2.len);
            sj->vt->putChunk(sj, 1, &ck2);
        }
        if (s->ch[cur].cb != 0) {
            s->ch[cur].cb(s->ch[cur].arg, cur);
        }
    }
    if (cur == 3 && s->open != 0) {
        if (s->hdr != 0) {
            appendUd(s, D_0045A578, 8);
        }
        appendUd(s, data, n);
    }
}
