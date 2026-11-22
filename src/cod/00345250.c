#include "godhand/mwsfViews.h"

__attribute__((section(".text.MWSFD_GetTotalFrmNum")))
int MWSFD_GetTotalFrmNum(MwRing *r)
{
    int i = r->pos % 8;

    if (r->ent[i].stat != 1)
        return 0;
    return r->ent[i].val;
}

