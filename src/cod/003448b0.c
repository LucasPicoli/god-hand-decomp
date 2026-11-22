/* cygnus-2.96: set the handle's status once; a different status after that is an error. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

__attribute__((section(".text.mwsffrm_SetFrmApi")))
void mwsffrm_SetFrmApi(MwsfdHn *m, int stat)
{
    if (m->latch == 0)
        m->latch = stat;
    else if (m->latch != stat)
        MWSFSVM_Error(D_00457830);
}
