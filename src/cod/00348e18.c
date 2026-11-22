/* cygnus-2.96: once the decoder reaches state 3 and neither slot has data queued, finish the stream:
 * stop, check for concatenated play, and close both slots. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

extern int func_003484F0(MwsfdSlot *s);
extern void func_00345B38(MwsfdHn *o);
extern void func_00345F48(MwsfdHn *o, int mode);
extern void func_00348550(MwsfdSlot *s, int a);

__attribute__((section(".text.func_00348E18")))
void func_00348E18(MwsfdHn *o)
{
    MwsfdSlot *s;
    MwsfdSlot *first;
    int c;

    if (func_00359E80(o->sfd) != 3)
        return;
    s = &o->slot[0];
    first = s;
    if (s->flag == 1 && func_003484F0(s) != 2 && s->sj->vt->getNumData(s->sj, 1) != 0)
        return;
    s = &o->slot[1];
    if (s->flag == 1 && func_003484F0(s) != 2 && s->sj->vt->getNumData(s->sj, 1) != 0)
        return;
    func_00345B38(o);
    c = o->pause;
    if (c == 0)
        func_00345F48(o, 0);
    c = o->busy;
    if (c == 1 && SFD_SetConcatPlay(o->sfd) != 0)
        MWSFSVM_Error(D_004592D0);
    if (o->pause != 0)
        return;
    func_00348550(first, 0);
    func_00348550(s, 0);
}
