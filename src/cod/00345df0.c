#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int mwlSfdSleepDecSvr(void *h);
extern int func_00358968(int);
extern int func_00345750(int);
extern void func_00348498(MwsfdSlot *slot);
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
    if (func_00358968(sfd) != 0) {
        func_00345750(-0x134);
        MWSFSVM_Error(D_00458068);
    }
    o->sfd = sfd;
    func_00348498(&o->slot[0]);
    func_00348498(&o->slot[1]);
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
