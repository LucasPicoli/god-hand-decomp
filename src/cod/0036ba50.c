#include "godhand/globals.h"
typedef struct MpvSeqHn {
    char pad0[0x360];
    int w360;
    int w364;
    int w368;
    char pad36C[0x398 - 0x36C];
    int w398;
} MpvSeqHn;

extern int func_003A5BD8(char *a, char *b, int n);
extern int func_003A7C48(char *s);
extern int MPV_CheckDelim(char *p);

__attribute__((section(".text.func_0036BA50")))
int func_0036BA50(MpvSeqHn *m, char *buf, int size)
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
            m->w398 = func_003A7C48(p + 0x10) != 0 ? 3 : 0;
        if (func_003A5BD8(p, D_0045A3C8, 7) == 0) {
            m->w360 = func_003A7C48(p + 0x10);
            m->w364 = func_003A7C48(p + 0x18);
            m->w368 = func_003A7C48(p + 0x20);
        }
        if (MPV_CheckDelim(p) != 0)
            break;
    }
    v = m->w360;
    {
        int r = v == 8 ? -1 : 0;
        if (v == 9)
            r = -1;
        return r;
    }
}
