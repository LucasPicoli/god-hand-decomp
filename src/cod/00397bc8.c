/* ee-2.9-991111 matched TU. */
#include "godhand/eeKernel.h"
#include "godhand/libpad.h"

/* ee-2.9-991111 */

extern void SyncDCache(void *start, void *end);

__attribute__((section(".text.func_00397BC8")))
PadData *func_00397BC8(int port, int slot, PadData *buf)
{
    int oldstat;
    PadData *pd;
    int n;

    oldstat = DIntr();
    pd = D_0077C110[port][slot].buf;
    SyncDCache(pd, &pd[1].unk73[sizeof(pd[1].unk73) - 1]); /* both frames */
    n = pd[0].frame < pd[1].frame;
    if (buf != 0)
        *buf = pd[n];
    if (oldstat == 1)
        EIntr();
    return &pd[n];
}
