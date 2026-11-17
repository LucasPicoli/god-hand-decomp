/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111 */

__attribute__((section(".text.scePadEnterPressMode")))
int scePadEnterPressMode(int port, int slot)
{
    if (D_0077C110[port][slot].open == 0)
        return 0;
    return scePadSetButtonInfo(port, slot, 0xFFF);
}
