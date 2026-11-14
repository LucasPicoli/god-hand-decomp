/* ee-2.9-991111 matched TU. */

#include "godhand/libpad.h"

/* ee-2.9-991111 */

__attribute__((section(".text.scePadSetActAlign")))
int scePadSetActAlign(int port, int slot, const unsigned char *align)
{
    PadSifAlign *p = (PadSifAlign *)&D_0077C300;
    int i;
    int r;

    p->cmd  = 8;
    p->port = port;
    p->slot = slot;
    for (i = 0; i < 6; i++)
        p->align[i] = align[i];
    if (func_003B3128(D_0077C0C0, 1, 0, p, 128, p, 128, 0, 0) < 0)
        return 0;
    r = p->result;
    if (r == 1) {
        scePadSetReqState(port, slot, 2);
        r = p->result;
    }
    return r;
}
