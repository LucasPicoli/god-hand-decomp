/* ee-2.9-991111 matched TU. */

#include "godhand/sync.h"


__attribute__((section(".text.EIntr")))
int EIntr(void)
{
    unsigned int stat;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    GH_EI();
    return stat != 0;
}
