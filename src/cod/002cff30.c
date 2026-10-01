/* func_002CFF30 — accessor (symbolic decoder). */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

/* Constructor of a bgm data record: nothing loaded, no allocations held. */
__attribute__((section(".text.func_002CFF30")))
cBgmData *func_002CFF30(cBgmData *d)
{
    d->loadMode = 0;
    d->f01 = 0;
    d->state = 0;
    d->head = 0;
    d->tbl = 0;
    d->f14 = 0;
    d->f18 = -1;
    d->f20 = -1;
    return d;
}
