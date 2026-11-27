/* ee-2.9-991111 matched TU. */
#include "godhand/sceDma.h"
#include "godhand/globals.h"

__attribute__((section(".text.WaitDma")))
void WaitDma(volatile sceDmaChan *chan)
{
    int i = 0x1000000;

    while (chan->chcr & 0x100) {
        i--;
        if (i < 0) {
            func_003B1F28(D_0045DFC8);
            sceDmaPause(chan);
        }
    }
}
