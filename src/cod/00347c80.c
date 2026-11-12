/* cygnus-2.96 matched TU. */

#include "godhand/mwsfd.h"

extern int GetField0OrZero_346828(MwsfdHn *mw);
extern void func_00335638(void *stm, int a, int b, int c, int d);
extern char D_004590D8[];

/* Forward a request to the handle's stream, or report a bad handle state. */
__attribute__((section(".text.MwsfdHn_forwardStmRequest")))
void MwsfdHn_forwardStmRequest(MwsfdHn *mw, int a1, int a2, int a3)
{
    if (GetField0OrZero_346828(mw) != 1) {
        MWSFSVM_Error(D_004590D8);
        return;
    }
    func_00335638(mw->stm, a1, 0, a2, a3);
}
