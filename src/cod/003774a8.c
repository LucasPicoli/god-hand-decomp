/* sn-2.95.3-136: SdeStrControl, run the per-kind update for both active task slots. */
#include "godhand/seqNode.h"
extern void (*D_003F21A8[])(SndCh *e);

__attribute__((section(".text.SdeStrControl")))
void SdeStrControl(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (D_0076E910[i].flags)
            D_003F21A8[D_0076E910[i].kind](&D_0076E910[i]);
    }
}
