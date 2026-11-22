/* cygnus-2.96: CRI stream DMA transfer kick. */
#include "godhand/criSj.h"
#include "godhand/globals.h"
typedef struct {
    signed char f0;
    signed char active;
    signed char busy;
    char pad3;
    SjObj *src;
    SjObj *dst;
    SjChunk cur0;
    SjChunk cur1;
    int dma[5];
    char pad30[8];
    int unit;
    int total;
} SjDmaXfer;

extern void func_003260C8(const char *fmt, ...);
extern void SJ_SplitChunk(SjChunk *in, int n, SjChunk *out, SjChunk *rest);
extern void SyncDCache(void *start, void *end);
extern int func_003B2148(int *dma, int ch);

__attribute__((section(".text.func_0033FDC0")))
void func_0033FDC0(SjDmaXfer *x)
{
    SjChunk b0;
    SjChunk t0;
    SjChunk b1;
    SjChunk t1;
    int n;

    if (x->active != 1)
        return;
    if (x->busy == 1) {
        x->src->vt->putChunk(x->src, 0, &x->cur0);
        x->cur0.data = 0;
        x->cur0.len = 0;
        x->dst->vt->putChunk(x->dst, 1, &x->cur1);
        x->cur1.data = 0;
        x->cur1.len = 0;
        /* Retail reads len after clearing it: total gains 0 and the check below never fires. */
        x->total += x->cur0.len;
        x->busy = 0;
        if (x->cur0.len != 0) {
            func_003260C8(D_00456A10);
            for (;;)
                ;
        }
    }
    if (x->busy != 0)
        return;
    x->src->vt->getChunk(x->src, 1, 0x7FFFFFFF, &b0);
    x->dst->vt->getChunk(x->dst, 0, 0x7FFFFFFF, &b1);
    n = b1.len;
    if (b0.len < n)
        n = b0.len;
    n = (n / x->unit) * x->unit;
    SJ_SplitChunk(&b0, n, &b0, &t0);
    x->src->vt->ungetChunk(x->src, 1, &t0);
    SJ_SplitChunk(&b1, n, &b1, &t1);
    x->dst->vt->ungetChunk(x->dst, 0, &t1);
    if (n <= 0)
        return;
    if (b0.len & 0x3F) {
        func_003260C8(D_00456A30);
        func_003260C8(D_00456A58, b0.data, b1.data, b0.len);
        for (;;)
            ;
    }
    if ((int)b0.data & 0x3F) {
        func_003260C8(D_00456A88);
        func_003260C8(D_00456A58, b0.data, b1.data, b0.len);
        for (;;)
            ;
    }
    if ((int)b1.data & 0x3F) {
        func_003260C8(D_00456AB0);
        func_003260C8(D_00456A58, b0.data, b1.data, b0.len);
        for (;;)
            ;
    }
    SyncDCache(b0.data, b0.data + b0.len - 1);
    x->dma[0] = (int)b0.data & 0x0FFFFFFF;
    x->dma[1] = (int)b1.data;
    x->dma[2] = b0.len;
    x->dma[3] = 0;
    x->dma[4] = func_003B2148(x->dma, 1);
    if (x->dma[4] == 0) {
        x->src->vt->ungetChunk(x->src, 1, &b0);
        x->dst->vt->ungetChunk(x->dst, 0, &b1);
        return;
    }
    x->cur0 = b0;
    x->cur1 = b1;
    x->busy = 1;
}
