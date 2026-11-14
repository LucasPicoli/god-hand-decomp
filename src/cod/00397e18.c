/* ee-2.9-991111 matched TU. */
#include "godhand/eeKernel.h"
#include "godhand/libpad.h"

/* ee-2.9-991111 */

extern void SyncDCache(void *start, void *end);

__attribute__((section(".text.scePadSetReqState")))
int scePadSetReqState(int port, int slot, int state)
{
    int oldstat;
    PadData *p;

    if (D_0077C110[port][slot].open == 0)
        return 0;
    oldstat = DIntr();
    p = func_00397BC8(port, slot, 0);
    p->reqState = state;
    SyncDCache(p, &p->unk73[sizeof(p->unk73) - 1]); /* the frame's last byte */
    if (oldstat == 1)
        EIntr();
    return 1;
}
