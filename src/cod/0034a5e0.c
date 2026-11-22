/* cygnus-2.96: step over the 0x12-byte padding records that equal the template at D_00459410, switch
 * the stream callback at the first other record, and add the skipped bytes to the totals. */
#include "godhand/sftim.h"
#include "godhand/globals.h"
typedef struct SfdStmHdr {
    char pad0[0x38];
    int total;
    void *cb;
} SfdStmHdr;

typedef struct SfdPosView {
    char pad0[0x9C8];
    long long pos;
    char pad9D0[0x2004 - 0x9D0];
    SfdStmHdr *hdr;
} SfdPosView;

extern void func_0034A400(int a0, int a1, int a2, int a3);
extern int func_003A50B4(const char *a, const char *b, int n);
extern int func_0034A6F8(SfdPosView *o, int *a, int *b);

__attribute__((section(".text.func_0034A5E0")))
void func_0034A5E0(SfdPosView *o, char *p, int len, int *out)
{
    int a, b;
    int i;
    SfdStmHdr *h;

    *out = 0;
    h = o->hdr;
    if (Obj34D8_GetTri78_Times100(o) >= 0x6C) {
        h->cb = func_0034A400;
        return;
    }
    for (i = 0; i < len - 0x12; i += 0x12) {
        int r = func_003A50B4(p, D_00459410, 0x12);
        p += 0x12;
        if (r == 0)
            continue;
        h->cb = func_0034A400;
        break;
    }
    *out = i;
    o->pos += i;
    if (func_0034A6F8(o, &a, &b) == 0)
        h->total += (i / (a * 0x12)) << 5;
}
