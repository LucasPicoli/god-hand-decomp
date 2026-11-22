/* ee-2.9-991111 matched TU. */
#include "godhand/libpad.h"

/* ee-2.9-991111 */

__attribute__((section(".text.scePadSetActDirect")))
int scePadSetActDirect(int port, int slot, const unsigned char *data)
{
    PadData buf;
    PadCmd *p;
    int i;
    int ret;

    scePadGetDmaStr(port, slot, &buf);
    if (buf.ok != 1)
        return 0;
    p = D_0077C110[port][slot].cmd;
    for (i = 0; i < 6; i++)
        p->data[i] = data[i];
    p->unk04 = 1;
    p->len = 6;
    ret = 1;
    if (func_003978C8(port, slot) != 1)
        ret = 0;
    return ret;
}
