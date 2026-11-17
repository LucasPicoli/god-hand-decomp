/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111 */

__attribute__((section(".text.scePadSetButtonInfo")))
int scePadSetButtonInfo(int port, int slot, int mask)
{
    int r;

    D_0077C300.cmd  = 10;
    D_0077C300.port = port;
    D_0077C300.slot = slot;
    D_0077C300.a    = mask;
    if (func_003B3128(D_0077C0C0, 1, 0, &D_0077C300, 128, &D_0077C300, 128, 0, 0) < 0)
        return 0;
    r = D_0077C300.b;
    if (r == 1) {
        scePadSetReqState(port, slot, 2);
        r = D_0077C300.b;
    }
    return r;
}
