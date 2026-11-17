/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111 */

/* scePadGetState: a stable pad whose request is still busy reads as 5 (executing a command). */
__attribute__((section(".text.scePadGetState")))
int scePadGetState(int port, int slot)
{
    PadData buf;

    if (D_0077C110[port][slot].open == 0)
        return 0x63;
    func_00397BC8(port, slot, &buf);
    if (buf.state == 6) {
        if (buf.reqState == 2)
            return 5;
    }
    return buf.state;
}
