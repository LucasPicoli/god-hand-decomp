/* cygnus-2.96: MWSF handle status / play time (0x346848..). */

#include "godhand/mwsfHn.h"
#include "godhand/globals.h"

__attribute__((section(".text.func_00346848")))
int func_00346848(MwsfHn *mw)
{
    int st = func_003468B8(mw);

    if (mw->f2D8 == 1 && mw->f2DC == 1 && (mw->f2E8 == 2 || mw->f2E8 == 3) &&
        (st == 1 || st == 3)) {
        st = 2;
    }
    return st;
}

__attribute__((section(".text.func_003468B8")))
int func_003468B8(MwsfHn *mw)
{
    int ok;
    int r;

    ok = GetField0OrZero_346828(mw);
    if (ok != 1) {
        func_00345750(-12);
        MWSFSVM_Error(D_00458488);
        return 0;
    }
    if (mw->stat != 2) {
        return mw->stat;
    }
    r = func_00359E80(mw->sfd);
    if (r == 4 || r == 6) {
        return 2;
    }
    return r < 0 ? 4 : 1;
}

__attribute__((section(".text.func_00346968")))
void func_00346968(MwsfHn *mw, int *time, int *tunit)
{
    int ok;

    *time = 0;
    *tunit = 1;
    ok = GetField0OrZero_346828(mw);
    if (ok != 1) {
        MWSFSVM_Error(D_004585D0);
        return;
    }
    if (mw->sfd == 0) {
        return;
    }
    if (SFD_GetTime(mw->sfd, time, tunit) != 0) {
        func_00345750(-0x135);
        MWSFSVM_Error(D_00458600);
    }
    if (*time < 0) {
        *time = 0;
        *tunit = 1;
    }
}
