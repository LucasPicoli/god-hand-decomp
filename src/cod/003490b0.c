/* cygnus-2.96: func_003490B0, per-frame server step of an mwsfd handle: stops a pending decode, kicks
 * the next one when idle, and flags the end status. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"
extern int func_00335B08(void *adxt);
extern int func_00358F68(void *sfd);
extern void func_00346158(MwsfdHn *hn);
extern int func_00359E80(void *sfd);

__attribute__((section(".text.func_003490B0")))
void func_003490B0(MwsfdHn *hn)
{
    void *sfd = hn->sfd;

    if (hn->stopReq == 1 && func_00335B08(hn->stm) == 0) {
        if (func_00358F68(sfd) != 0)
            MWSFSVM_Error(D_00459330);
        hn->stopReq = 0;
    }
    if (*(unsigned short *)&hn->busy == 0 && func_00335B08(hn->stm) == 0)
        func_00346158(hn);
    if (func_00359E80(sfd) == 6)
        hn->stat = 3;
}
