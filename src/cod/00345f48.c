#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int GetField0OrZero_346828(MwsfdHn *mw);
extern void MWSFSVM_Error(const char *msg, ...);
extern int MWSFD_GetPauseBdr(void);
extern int SFD_GetCond(void *sfd, int id, int *out);
extern int mwlSfdSleepDecSvr(MwsfdHn *mw);
extern int SFD_Pause(void *sfd, int sw);
extern int MWSFLIB_SetErrCode(int err);
extern void MWSST_Pause(MwsfdSlot *slot, int sw);

__attribute__((section(".text.func_00345F48")))
void func_00345F48(MwsfdHn *mw, int sw)
{
    int ok;
    void *sfd;
    int cond;
    int pb, st;

    ok = GetField0OrZero_346828(mw);
    if (ok != 1) {
        MWSFSVM_Error(D_004580B0);
        return;
    }
    sfd = mw->sfd;
    if (mw->pause == 0 && sw == 0)
        return;
    pb = MWSFD_GetPauseBdr();
    if (pb == 1) {
        st = mw->unk08;
        if (st == pb) {
            if (SFD_GetCond(sfd, 6, &cond) == 0) {
                if (cond == st)
                    mwlSfdSleepDecSvr(mw);
            } else {
                mwlSfdSleepDecSvr(mw);
            }
        }
    }
    if (SFD_Pause(sfd, sw) != 0) {
        MWSFLIB_SetErrCode(-0x136);
        MWSFSVM_Error(D_004580D8, sw == 1 ? D_00458100 : D_00458108);
    }
    MWSST_Pause(&mw->slot[0], sw);
    MWSST_Pause(&mw->slot[1], sw);
    mw->pause = sw;
}
