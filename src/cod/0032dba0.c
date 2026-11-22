/* cygnus-2.96: func_0032DBA0, stops a movie player handle: halts decoding and the audio side, and under the
 * lock releases an owned input stream. */
#include "godhand/mwPly.h"
#include "godhand/criSj.h"
#include "godhand/globals.h"
extern void Obj33F8_Tramp_0033F130_FCB0(char *msg);
extern void func_0032EF00(MwPly *ply);
extern int func_003282D0(void *sfd);
extern void Obj33F8_Tramp_0033B658_FC70(void);
extern void func_0032F4A8(void *adx);
extern void Obj33F8_Tramp_0033B670_FC88(void);

__attribute__((section(".text.func_0032DBA0")))
void func_0032DBA0(MwPly *ply)
{
    SjObj *sj;

    if (ply == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452B20);
        return;
    }
    func_0032EF00(ply);
    if (ply->sfd != 0)
        func_003282D0(ply->sfd);
    Obj33F8_Tramp_0033B658_FC70();
    if (ply->adx != 0)
        func_0032F4A8(ply->adx);
    if (ply->ownSj == 2) {
        sj = (SjObj *)ply->sj;
        ply->sj = 0;
        if (sj != 0)
            sj->vt->destroy(sj);
    }
    ply->sj = 0;
    ply->stat = 0;
    ply->unk1AC = 0;
    Obj33F8_Tramp_0033B670_FC88();
}
