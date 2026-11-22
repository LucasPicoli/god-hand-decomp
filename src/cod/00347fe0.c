#include "godhand/mwsfHn.h"

void RestartSingleLoop(MwsfHn *mw);
int func_00348098(MwsfHn *mw);

__attribute__((section(".text.RestartSingleLoop")))
void RestartSingleLoop(MwsfHn *mw)
{
    int time, tunit;
    unsigned int mode;

    func_00346968(mw, &time, &tunit);
    mode = mw->mode;
    mw->busy = 1;
    switch (mode) {
    case 1:
        mwPlyStartFnameLp(mw, mw->f1A4);
        break;
    case 2:
        mwPlyStartAfsLp(mw, mw->f2EC, mw->f2F0);
        break;
    case 3:
        mwPlyStartFnameRangeLp(mw, mw->f1A4, mw->f2F4, mw->f2F8);
        break;
    }
    mw->busy = 0;
    mw->count++;
}

