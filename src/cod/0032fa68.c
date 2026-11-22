/* cygnus-2.96: CRI AIX header parse / chunk server (0x32F988..). */

#include "godhand/criAix.h"
#include "godhand/globals.h"

extern void Obj33F8_Tramp_0033F130_FCB0(const char *msg);
extern void *func_003A5148(void *dst, const void *src, int n);

extern inline int aix_be32(const unsigned char *p)
{
    return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

extern inline int aix_be16(const unsigned char *p)
{
    return (p[0] << 8) | p[1];
}

__attribute__((section(".text.func_0032FA68")))
int func_0032FA68(unsigned char *p)
{
    switch ((p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3]) {
    case 0x41495845:
    case 0x41495846:
    case 0x41495850:
        return 1;
    }
    return 0;
}

__attribute__((section(".text.func_0032FAD8")))
void func_0032FAD8(AixDmx *d)
{
    SjObj *sj = d->sj;
    SjChunk ck, tail;
    int r;

    sj->vt->getChunk(sj, 1, 0x1800, &ck);
    r = func_0032F580((unsigned char *)ck.data, ck.len, &d->info);
    if (r == -1) {
        sj->vt->ungetChunk(sj, 1, &ck);
        return;
    }
    if (r == 0) {
        d->noHdr = 1;
    } else if (r != ck.len) {
        Obj33F8_Tramp_0033F130_FCB0(D_00453078);
        sj->vt->ungetChunk(sj, 1, &ck);
        d->stat = 4;
        return;
    } else {
        d->noHdr = 0;
        if (d->hdrCb != 0) {
            d->hdrCb(d->hdrCbArg, &d->info);
        }
    }
    SJ_SplitChunk(&ck, r, &ck, &tail);
    sj->vt->putChunk(sj, 0, &ck);
    sj->vt->ungetChunk(sj, 1, &tail);
    d->total += r;
    d->stat = 2;
}

__attribute__((section(".text.func_00330080")))
void func_00330080(AixDmx *d)
{
    SjObj *sj = d->sj;
    SjObj **out = d->out;
    SjChunk ck, tail, dst;

    sj->vt->getChunk(sj, 1, 0x7FFFFFFF, &ck);
    (*out)->vt->getChunk(*out, 0, ck.len, &dst);
    func_003A5148(dst.data, ck.data, dst.len);
    (*out)->vt->putChunk(*out, 1, &dst);
    SJ_SplitChunk(&ck, dst.len, &ck, &tail);
    sj->vt->putChunk(sj, 0, &ck);
    sj->vt->ungetChunk(sj, 1, &tail);
    d->total += dst.len;
}
