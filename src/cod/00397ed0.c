/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111 */

__attribute__((section(".text.scePadGetReqState")))
int scePadGetReqState(int port, int slot)
{
    PadData *p;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    p = scePadGetDmaStr(port, slot, 0);
    return p->reqState;
}
