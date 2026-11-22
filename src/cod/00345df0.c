#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int mwlSfdSleepDecSvr(void *h);
extern int SFD_Stop(int);
extern int MWSFLIB_SetErrCode(int);
extern void MWSST_Stop(MwsfdSlot *slot);
extern void func_00349B60(int);
extern int func_00335950(int);

__attribute__((section(".text.func_00345DF0")))
void func_00345DF0(MwsfdHn *o)
{
    int sfd = (int)o->sfd;

    if (sfd == 0) {
        return;
    }
    mwlSfdSleepDecSvr(o);
    o->stat = 0;
    o->sfd = 0;
    if (SFD_Stop(sfd) != 0) {
        MWSFLIB_SetErrCode(-0x134);
        MWSFSVM_Error(D_00458068);
    }
    o->sfd = sfd;
    MWSST_Stop(&o->slot[0]);
    MWSST_Stop(&o->slot[1]);
    o->unk2CC = 0;
    if (o->unk40 != 0) {
        func_00349B60(o->unk40);
    }
    if (o->stm != 0) {
        func_00335950(o->stm);
    }
    if (o->unk2E0 == 0) {
        o->unk2E4 = 0;
        o->unk2FC = -1;
        o->unk2DC = 0;
        o->unk300 = 0;
        o->unk2E8 = 0;
        return;
    }
    o->unk2E8 = 2;
}
