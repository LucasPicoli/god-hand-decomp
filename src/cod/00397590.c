/* ee-2.9-991111 matched TU. */
#include "godhand/sceDma.h"
#include "godhand/eeKernel.h"

#define D_ENABLER (*(volatile unsigned int *)0x1000F520)
#define D_ENABLEW (*(volatile unsigned int *)0x1000F590)
#define D_CTRL    (*(volatile unsigned int *)0x1000E000)


__attribute__((section(".text.sceDmaPause")))
unsigned int sceDmaPause(volatile sceDmaChan *chan)
{
    int oldstat;
    unsigned int en;
    unsigned int chcr;

    oldstat = DIntr();
    en = D_ENABLER;
    if (!(en & 0x10000)) {
        D_ENABLEW = en | 0x10000;
    }
    D_CTRL;
    chcr = chan->chcr;
    chan->chcr = chcr & 0xFFFFFEFF;
    D_ENABLEW = en;
    if (oldstat) {
        EIntr();
    }
    return chcr;
}
