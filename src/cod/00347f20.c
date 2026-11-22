/* cygnus-2.96: MWSF handle playback server tick / start time (0x347F20, 0x348098). */

#include "godhand/mwsfHn.h"
#include "godhand/globals.h"

void RestartSingleLoop(MwsfHn *mw);
int func_00348098(MwsfHn *mw);

__attribute__((section(".text.mwPlyExecInfiniteLoopHandle")))
void mwPlyExecInfiniteLoopHandle(MwsfHn *mw)
{
    int st;

    if (mw->f2D8 == 0 || mw->f2DC == 0) {
        return;
    }
    if (mw->f2E8 == 1) {
        st = mwPlyGetStat(mw);
        if (st == 2) {
            if (func_00348098(mw) < 0) {
                return;
            }
            mw->f2E8 = st;
        }
    }
    if (mw->f2E8 != 2 && mw->f2E8 != 3) {
        return;
    }
    if (func_003468B8(mw) == 3) {
        RestartSingleLoop(mw);
    }
    CheckReleasLpTiming(mw);
}

__attribute__((section(".text.func_00348098")))
int func_00348098(MwsfHn *mw)
{
    int base, rate;
    int q, t;

    Obj0000_Call_0035A128_Field_3C(mw, 0x36, &base);
    SFD_GetFps(mw->sfd, &rate);
    if (rate <= 0) {
        MWSFSVM_Error(D_00459210);
        mw->f2FC = base;
        return -1;
    }
    q = Forward345250_344F18(mw) * 1000 / rate;
    t = q * 1000;
    return mw->f2FC = base - ((t * 3) >> 1);
}
