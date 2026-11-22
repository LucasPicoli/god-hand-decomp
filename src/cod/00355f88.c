/* cygnus-2.96: IPU FIFO DMA restart. */

/* EE registers: IPU command and control, DMA channel 3 (from IPU), channel 4 (to IPU). */
#define IPU_CMD     (*(volatile unsigned int *)0x10002000)
#define IPU_CTRL    (*(volatile int *)0x10002010)
#define D3_MADR     (*(volatile unsigned int *)0x1000B010)
#define D3_QWC      (*(volatile unsigned int *)0x1000B020)
#define D4_MADR     (*(volatile unsigned int *)0x1000B410)
#define D4_QWC      (*(volatile unsigned int *)0x1000B420)
#define D4_TADR     (*(volatile unsigned int *)0x1000B430)
typedef struct {
    unsigned int base;
    unsigned int phys;
    int n;
    int idx;
    int count;
    char pad14[8];
    unsigned int cur;
    unsigned int f20;
    unsigned int f24;
    unsigned int tag;
    unsigned int f2C;
    unsigned int f30;
    unsigned int f34;
    unsigned int ctrl;
    unsigned int f3C;
    int sema;
    int f44;
} IpuFifo;

extern void WaitSema(int s);
extern void SignalSema(int s);
extern int getFIFOindex(IpuFifo *f, unsigned int p);
extern void setD3_CHCR(unsigned int v);
extern void func_00355880(unsigned int tag);

__attribute__((section(".text.viBufRestartDMA")))
int viBufRestartDMA(IpuFifo *f)
{
    unsigned int ctrl;
    unsigned int cur;
    unsigned int base;
    unsigned int madr;
    unsigned int qwc;
    unsigned int addr;
    unsigned int tag;
    unsigned int bp;
    int k;
    int ifc;
    int fp;
    int n;
    int sz;
    int id;
    int i0;
    int i1;

    WaitSema(f->sema);
    ctrl = f->ctrl;
    cur = f->cur;
    ifc = (ctrl >> 8) & 0xF;
    fp = (ctrl >> 16) & 3;
    k = fp + ifc;
    madr = cur - k * 16;
    qwc = f->f24 + k;
    bp = ctrl & 0x7F;
    addr = f->f20;
    tag = f->tag | 0x100;
    if (madr < f->base) {
        sz = f->n << 11;
        addr = f->phys & 0x0FFFFFFF;
        qwc = (f->base - madr) >> 4;
        madr += sz;
        if (cur == f->base || cur == f->base + sz)
            id = 0;
        else
            id = 3;
        tag = (f->tag & 0x0FFFFFFF) | (id << 28) | 0x100;
        if ((f->n - f->idx) % f->n < 0 || (f->n - f->idx) % f->n >= f->count) {
            f->idx = f->n - 1;
            f->count = f->count + 1;
        }
    } else {
        i0 = getFIFOindex(f, cur);
        i1 = getFIFOindex(f, madr);
        if (i0 != i1) {
            unsigned int a;
            int id2;
            unsigned int b;
            n = f->n;
            base = f->base;
            a = base + (f->cur - base) % (unsigned int)(n << 11);
            b = base + (((f->idx + f->count) % n) << 11);
            qwc = (base + (i0 << 11) - madr) >> 4;
            addr = ((i0 << 4) + f->phys) & 0x0FFFFFFF;
            id2 = 3;
            if (a == b)
                id2 = 0;
            tag = (f->tag & 0x0FFFFFFF) | (id2 << 28) | 0x100;
            if ((i1 + n - f->idx) % n < 0 || (i1 + n - f->idx) % n >= f->count) {
                f->idx = i1;
                f->count = f->count + 1;
            }
        }
    }
    if (f->f2C != 0 && f->f30 != 0) {
        D3_MADR = f->f2C;
        D3_QWC = f->f30;
        setD3_CHCR(f->f34 | 0x100);
    }
    while (IPU_CTRL < 0)
        ;
    IPU_CMD = bp;
    while (IPU_CTRL < 0)
        ;
    D4_MADR = madr;
    D4_TADR = addr;
    D4_QWC = qwc;
    if (f->count != 0)
        func_00355880(tag);
    IPU_CTRL = f->f3C;
    f->f44 = 1;
    SignalSema(f->sema);
    return 1;
}
