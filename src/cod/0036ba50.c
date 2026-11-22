#include "godhand/globals.h"
#include "godhand/MpvHandle.h"

extern int func_003A5BD8(char *a, char *b, int n);
extern int func_003A7C48(char *s);

__attribute__((section(".text.mpvhdec_DecSeqUdsc")))
int mpvhdec_DecSeqUdsc(MpvHandle *hn, char *buf, int size)
{
    int n;
    int i;
    char *base;
    char *p;
    int v;

    n = size - 4;
    base = buf + 4;
    for (i = 0; i < n;) {
        p = base + i;
        i++;
        if (func_003A5BD8(p, D_0045A3C0, 7) == 0)
            hn->unk398 = func_003A7C48(p + 0x10) != 0 ? 3 : 0;
        if (func_003A5BD8(p, D_0045A3C8, 7) == 0) {
            hn->unk360 = func_003A7C48(p + 0x10);
            hn->unk364 = func_003A7C48(p + 0x18);
            hn->unk368 = func_003A7C48(p + 0x20);
        }
        if (MPV_CheckDelim(p) != 0)
            break;
    }
    v = hn->unk360;
    {
        int r = v == 8 ? -1 : 0;
        if (v == 9)
            r = -1;
        return r;
    }
}
