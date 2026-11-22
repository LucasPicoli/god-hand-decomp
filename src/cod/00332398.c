/* cygnus-2.96: IOP transfer pump: hand a finished receive to its callback, then fill the buffer and
 * start the next DMA to the IOP. */
#include "godhand/globals.h"

typedef struct {
    char pad0[0x3C];
    int seq;
} IopXferHdr;

typedef struct {
    unsigned int data;
    unsigned int addr;
    unsigned int size;
    unsigned int mode;
} SifDmaData;

typedef struct {
    signed char b0;
    signed char state;
    char pad2[6];
    int count;
    char *buf;
    int size;
    IopXferHdr *hdr;
    unsigned int dest;
    unsigned int dsize;
    void (*recv)(int arg, char *buf, int size);
    int recvArg;
    void (*fill)(int arg, char *buf, int size);
    int fillArg;
    SifDmaData dma;
    int id;
} IopXfer;

extern void func_003B0640(void *start, void *end);
extern void SyncDCache(void *start, void *end);
extern int func_003B2148(SifDmaData *dma, int n);

__attribute__((section(".text.func_00332398")))
void func_00332398(IopXfer *x)
{
    D_003D84B8++;
    if (x->state == 1 && x->count < x->hdr->seq) {
        func_003B0640(x->buf, x->size + x->buf - 1);
        x->recv(x->recvArg, x->buf, x->size);
        x->count = x->hdr->seq;
        x->state = 0;
    }
    if ((*(int *)x & 0xFFFF00) != 0x10000) {
        return;
    }
    if (D_003D84AC != 1) {
        return;
    }
    x->fill(x->fillArg, x->buf, x->size);
    x->count++;
    x->hdr->seq = x->count;
    SyncDCache(x->buf, x->buf + x->size - 1);
    func_003B0640(x->buf, x->buf + x->size + 0x3F);
    x->dma.data = (unsigned int)x->buf & 0x0FFFFFFF;
    x->dma.addr = x->dest;
    x->dma.size = x->dsize;
    x->dma.mode = 0;
    while ((x->id = func_003B2148(&x->dma, 1)) == 0) {
    }
    x->state = 1;
}
