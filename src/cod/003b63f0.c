/* ee-2.9-991111 matched TU. */

#include "godhand/sync.h"


__attribute__((section(".text.func_003B63F0")))
int func_003B63F0(void)
{
    unsigned int stat;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    GH_EI();
    return stat != 0;
}
