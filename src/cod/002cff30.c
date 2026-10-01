/* cBgmData_Init — accessor (symbolic decoder). */
#include "godhand/cSnd.h"
#include "godhand/cBgmData.h"

/* Constructor of a bgm data record: nothing loaded, no allocations held. */
__attribute__((section(".text.cBgmData_Init")))
cBgmData *cBgmData_Init(cBgmData *d)
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
