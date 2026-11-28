/* ee-2.9-991111 matched TU. */
#include "godhand/sceDma.h"
#include "godhand/eeKernel.h"

extern void _IO_free_backup_area(int *a0);

/* MATCH via ee-2.9-991111. */


__attribute__((section(".text._IO_seekpos")))
void _IO_seekpos(int *a0, int a1, int a2)
{
    int vt;
    void (*fn)(int *, int, int);
    if (a0[9] != 0)
        _IO_free_backup_area(a0);
    vt = a0[0x14];
    fn = (void (*)(int *, int, int))((int *)vt)[0x13];
    fn(a0, a1, a2);
}

/* MATCH via ee-2.9-991111. */



__attribute__((section(".text.sceDmaSend")))
void sceDmaSend(sceDmaChan *chan, void *tag)
{
    unsigned int addr = CheckAddress((unsigned int)tag);
    WaitDma(chan);
    if ((unsigned int)chan->tadr != 0xFFFFFFFFU)
        chan->tadr = (void *)addr;
    chan->qwc = 0;
    chan->chcr = (chan->chcr & ~0xC) | 0x105;
}

/* MATCH via ee-2.9-991111. */



__attribute__((section(".text.func_003B35F8")))
int func_003B35F8(int *a0)
{
    int p;
    DIntr();
    p = a0[3];
    if (p == 0) {
        a0[1] = 0;
    } else {
        a0[3] = ((int *)p)[0xF];
        a0[1] = 1;
    }
    EIntr();
    return p;
}
