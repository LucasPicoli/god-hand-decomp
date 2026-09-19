/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 — SCE libmpeg 3.0.2, mpc.o :: dmaRefImage */
#include <godhand/sync.h>


extern void EIntr(void);
extern unsigned long long D_0077C680[];   /* _sprtagdata, 0x240 B */

#define D9_CHCR (*(volatile unsigned int *)0x1000D400)
#define D9_QWC  (*(volatile unsigned int *)0x1000D420)
#define D9_TADR (*(volatile unsigned int *)0x1000D430)
#define D9_SADR (*(volatile unsigned int *)0x1000D480)

#define DMATAG(addr, id, qwc) \
    (((unsigned long long)((unsigned int)(addr) & 0x0FFFFFFF) << 32) | ((unsigned long long)(id) << 28) | (unsigned long long)(qwc))

typedef struct MbRow {
    int madr;           /* 0x000 */
    int f4;
    int src[4];         /* 0x008 */
    int dst[4];         /* 0x018 */
    int pad[0x41];      /* 0x028 .. 0x12C */
    int n;              /* 0x12C */
    int pad2[4];        /* 0x130 .. 0x140 */
} MbRow;

typedef struct Ctx {
    char pad0[0x5A0];
    MbRow rows[1];      /* 0x5A0, stride 0x140 */
} Ctx;

__attribute__((section(".text.dmaRefImage")))
void dmaRefImage(Ctx *c)
{
    int i, n, mb, mb2, oldstat;
    int d;
    int id0, id1;
    unsigned long long *tag;

    if (*(int *)((char *)c + 0x87C) != 0)
        return;
    mb = *(int *)((char *)c + 0x820);
    n = c->rows[mb].n;
    tag = (unsigned long long *)(((unsigned int)D_0077C680 & 0x0FFFFFFF) | 0x20000000);
    for (i = 0; i < n; i++) {
        id0 = 3;
        tag[0] = DMATAG(c->rows[mb].src[i], id0, 0x30);
        d = c->rows[mb].dst[i];
        if (i == n - 1) id1 = 0; else id1 = 3;
        tag[2] = DMATAG(d, id1, 0x30);
        tag += 4;
    }
    oldstat = func_003B63A0();
    GH_SYNC();
    mb2 = *(int *)((char *)c + 0x820);
    D9_SADR = c->rows[mb2].madr;
    D9_TADR = (unsigned int)D_0077C680;
    D9_QWC  = 0;
    D9_CHCR = 0x105;
    if (oldstat == 0)
        return;
    EIntr();
}
