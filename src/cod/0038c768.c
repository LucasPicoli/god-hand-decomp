/* ee-2.9-991111 matched TU. */
#include "godhand/sceDma.h"

extern void _IO_free_backup_area(int *);
extern void UpdateGlobalPtrWithParam_3A7CC0(int);

__attribute__((section(".text.sceDmaRecvN")))
void sceDmaRecvN(sceDmaChan *chan, void *addr, int qwc) {
    unsigned int dst = CheckAddress((unsigned int)addr);
    int chcr;
    WaitDma(chan);
    if ((unsigned int)chan->madr != 0xFFFFFFFFU)
        chan->madr = (void *)dst;
    chan->qwc = qwc;
    chcr = chan->chcr & ~0xC;   /* normal mode */
    chan->chcr = (chcr & ~1) | 0x100; /* into memory, start */
}

__attribute__((section(".text._IO_seekoff")))
int _IO_seekoff(int *o, long a1, int a2, int a3) {
    if (o[9] != 0) {
        if (a2 == 1 && (o[0] & 0x100))
            a1 -= (o[2] - o[1]);
        _IO_free_backup_area(o);
    }
    return (*(int (**)(int *, long, int, int))(((int *)o[0x14]) + 0x11))(o, a1, a2, a3);
}

__attribute__((section(".text.func_0038C768")))
void func_0038C768(int *o, int a1, int a2, int a3) {
    int f;
    if (o[7] != 0 && (o[0] & 1) == 0)
        UpdateGlobalPtrWithParam_3A7CC0(o[7]);
    f = o[0];
    o[7] = a1;
    o[8] = a2;
    if (a3 != 0)
        o[0] = f & ~1;
    else
        o[0] = f | 1;
}
