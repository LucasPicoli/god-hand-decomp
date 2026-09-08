/* ee-2.9-991111 matched TU. */

typedef unsigned int u_int;

typedef struct {
    u_int madr3;   /* 0x00  D3_MADR   0x1000B410 */
    u_int tadr3;   /* 0x04  D3_TADR   0x1000B430 */
    u_int qwc3;    /* 0x08  D3_QWC    0x1000B420 */
    u_int chcr3;   /* 0x0C  D3_CHCR   0x1000B400 */
    u_int madr4;   /* 0x10  D4_MADR   0x1000B010 */
    u_int qwc4;    /* 0x14  D4_QWC    0x1000B020 */
    u_int chcr4;   /* 0x18  D4_CHCR   0x1000B000 */
    u_int bp;      /* 0x1C  IPU_BP    0x10002020 */
    u_int ctrl;    /* 0x20  IPU_CTRL  0x10002010 */
} sceIpuDMA;

extern void func_003BA9F0(u_int chcr);
extern void setD4_CHCR(u_int v);

__attribute__((section(".text.sceIpuRestartDMA")))
void sceIpuRestartDMA(sceIpuDMA *d)
{
    u_int c;
    u_int bp;
    u_int n;
    u_int madr;
    u_int qwc;

    c = d->bp;
    bp = c & 0x7F;
    n = ((c >> 16) & 0x3) + ((c >> 8) & 0xF);
    madr = d->madr3 - (n << 4);
    qwc  = d->qwc3 + n;
    if (d->madr4 != 0 && d->qwc4 != 0) {
        *(volatile u_int *)0x1000B010 = d->madr4;
        *(volatile u_int *)0x1000B020 = d->qwc4;
        setD4_CHCR(d->chcr4 | 0x100);
    }
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    *(volatile u_int *)0x10002000 = bp;
    while (*(volatile int *)0x10002010 < 0) {
        ;
    }
    if (madr != 0 && qwc != 0) {
        *(volatile u_int *)0x1000B410 = madr;
        *(volatile u_int *)0x1000B430 = d->tadr3;
        *(volatile u_int *)0x1000B420 = qwc;
        func_003BA9F0(d->chcr3 | 0x100);
    }
}
