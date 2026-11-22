#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int GetField0OrZero_346828(MwsfdHn *mw);
extern void MWSFSVM_Error(const char *msg, ...);
extern int MWSFD_GetPauseBdr(void);
extern int SFD_GetCond(void *sfd, int id, int *out);
extern int mwlSfdSleepDecSvr(MwsfdHn *mw);
extern int func_00356F48(void *sfd, int sw);
extern int func_00345750(int err);
extern void func_00348550(MwsfdSlot *slot, int sw);

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
    if (func_00356F48(sfd, sw) != 0) {
        func_00345750(-0x136);
        MWSFSVM_Error(D_004580D8, sw == 1 ? D_00458100 : D_00458108);
    }
    func_00348550(&mw->slot[0], sw);
    func_00348550(&mw->slot[1], sw);
    mw->pause = sw;
}
