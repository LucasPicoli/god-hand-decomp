/* ee-2.9-991111 matched TU. */

#include <godhand/sync.h>

/* PROPOSED: GH_EI() belongs beside GH_SYNC() in include/godhand/sync.h. */

#define D_STAT   (*(volatile unsigned int *)0x1000E010)
#define D4_CHCR  (*(volatile unsigned int *)0x1000B400)
#define D4_MADR  (*(volatile unsigned int *)0x1000B410)
#define D4_QWC   (*(volatile unsigned int *)0x1000B420)

typedef struct Ch4 {
    unsigned int qwc;
    unsigned int madr;
} Ch4;

__attribute__((section(".text.func_0039C140")))
int func_0039C140(int chan, Ch4 *p)
{
    D_STAT = 0x10;
    if (p->qwc == 0) {
        GH_SYNC();
        GH_EI();
        return 1;
    }
    if (p->qwc > 0xFFFF) {
        D4_MADR = p->madr;
        D4_QWC  = 0xFFFF;
        D4_CHCR = 0x101;
        p->madr = (p->madr + 0xFFFF0) & 0x0FFFFFFF;
        p->qwc  = p->qwc - 0xFFFF;
    } else {
        D4_MADR = p->madr;
        D4_QWC  = p->qwc;
        D4_CHCR = 0x101;
        p->qwc  = 0;
    }
    GH_SYNC();
    GH_EI();
    return 0;
}

#include <godhand/sync.h>


#define D_STAT   (*(volatile unsigned int *)0x1000E010)
#define D3_CHCR  (*(volatile unsigned int *)0x1000B000)
#define D3_MADR  (*(volatile unsigned int *)0x1000B010)
#define D3_QWC   (*(volatile unsigned int *)0x1000B020)
#define IPU_CMD  (*(volatile unsigned int *)0x10002000)

typedef struct Ch3 {
    volatile int n;
    int          done;
    unsigned int rem;
    unsigned int madr;
    int          total;
} Ch3;

__attribute__((section(".text._ch3dmaCSC")))
int _ch3dmaCSC(int chan, Ch3 *p)
{
    D_STAT = 0x8;
    p->n = p->n + 1;
    if (D3_QWC != 0 || (D3_CHCR & 0x100) != 0) {
        p->done = 1;
        GH_SYNC();
        GH_EI();
        return 0;
    }
    if (p->n < p->total - 1) {
        D3_MADR = p->madr;
        D3_QWC  = 0xFFC0;
        D3_CHCR = 0x100;
        IPU_CMD = 0x700003FF;
        p->madr = (p->madr + 0xFFC00) & 0x0FFFFFFF;
    } else if (p->n == p->total - 1) {
        p->rem = p->rem - p->n * 1023;
        D3_MADR = p->madr;
        D3_QWC  = p->rem << 6;
        D3_CHCR = 0x100;
        IPU_CMD = p->rem | 0x70000000;
    }
    GH_SYNC();
    GH_EI();
    return 0;
}
