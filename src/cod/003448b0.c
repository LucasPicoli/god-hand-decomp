/* cygnus-2.96: set the handle's status once; a different status after that is an error. */
#include "godhand/mwsfd.h"
#include "godhand/globals.h"

__attribute__((section(".text.func_003448B0")))
void func_003448B0(MwsfdHn *m, int stat)
{
    if (m->latch == 0)
        m->latch = stat;
    else if (m->latch != stat)
        MWSFSVM_Error(D_00457830);
}
