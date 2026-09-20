/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */
#include "godhand/sync.h"
#include "godhand/gp.h"

typedef struct { void (*fn)(void *); void *arg; } PoffCb;

extern void *D_00781780;

__attribute__((section(".text._sceFs_Poff_Intr")))
void _sceFs_Poff_Intr(int a0, PoffCb *cb)
{
    void *oldgp;

    if (cb->fn != 0) {
        GH_SWAPGP_MEM(oldgp, D_00781780);
        cb->fn(cb->arg);
        GH_PUTGP(oldgp);
    }
    GH_SYNC();
    GH_EI();
}
