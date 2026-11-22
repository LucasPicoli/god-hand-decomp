/* cygnus-2.96: MWSFD handle setters. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"


extern int GetField0OrZero_346828(MwsfdHn *mw);
extern void func_00335C68(void *p, int v);

__attribute__((section(".text.mwPlySetSeamlessLp")))
void mwPlySetSeamlessLp(MwsfdHn *mw, int v)
{
    if (GetField0OrZero_346828(mw) != 1) {
        MWSFSVM_Error(D_00458F48);
        return;
    }
    func_00335C68(mw->stm, v);
}
