/* sn-2.95.3-136 matched TU. */

#include "godhand/seqNode.h"
__attribute__((section(".text.SeqCmd_findStartByMask")))
SeqCmd *SeqCmd_findStartByMask(unsigned char mask, int owner)
{
    SeqCmd *c;
    int i;

    for (i = 0; i < SEQCMD_NUM; i++) {
        c = &D_0076B9C0[i];
        if (c->used == 0) continue;
        if (c->flags & SEQCMD_F_STOP) continue;
        if ((c->mask & mask) == 0) continue;
        if (owner == 0) return c;
        if (c->owner == owner) return c;
    }
    return 0;
}
