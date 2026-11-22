/* cygnus-2.96: func_003490B0, per-frame server step of an mwsfd handle: stops a pending decode, kicks
 * the next one when idle, and flags the end status. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"
extern int func_00335B08(void *adxt);
extern int SFD_TermSupply(void *sfd);
extern void mwPlyChkSupply(MwsfdHn *hn);
extern int SFD_GetHnStat(void *sfd);

__attribute__((section(".text.func_003490B0")))
void func_003490B0(MwsfdHn *hn)
{
    void *sfd = hn->sfd;

    if (hn->stopReq == 1 && func_00335B08(hn->stm) == 0) {
        if (SFD_TermSupply(sfd) != 0)
            MWSFSVM_Error(D_00459330);
        hn->stopReq = 0;
    }
    if (*(unsigned short *)&hn->busy == 0 && func_00335B08(hn->stm) == 0)
        mwPlyChkSupply(hn);
    if (SFD_GetHnStat(sfd) == 6)
        hn->stat = 3;
}
