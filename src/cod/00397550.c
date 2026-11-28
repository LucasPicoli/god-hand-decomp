/* ee-2.9-991111 matched TU. */

#include "godhand/sceDma.h"

/* sceDmaSync; timeout is not read. */
__attribute__((section(".text.sceDmaSync")))
int sceDmaSync(volatile sceDmaChan *chan, int mode, int timeout)
{
    if (mode == 1) {
        unsigned int chcr = chan->chcr;  /* STR, bit 8, is read with a logical shift */
        return (chcr >> 8) & 1;
    }
    WaitDma(chan);
    return 0;
}
