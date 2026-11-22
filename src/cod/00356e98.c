#include "godhand/mwsfViews.h"

extern int SFMPVP_IsSceMpegUsed(SfdWkT *w);

__attribute__((section(".text.SFMPVP_IsPscEnough")))
int SFMPVP_IsPscEnough(SfdWkT *w)
{
    SfdStView *st;

    if (SFMPVP_IsSceMpegUsed(w) == 0) {
        return 1;
    }
    st = &w->tbl->st;
    if (st->f20 == 1) {
        return 1;
    }
    if (st->fC < 3) {
        return 0;
    }
    return 1;
}

