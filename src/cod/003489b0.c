/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"
#include "godhand/criCbTbl.h"

/* Initialize the server manager and reset the Sofdec callback registration IDs. */
__attribute__((section(".text.MWSFSVM_Init")))
void MWSFSVM_Init(void)
{
    func_0033BE80();
    D_00760D80 = 0;
    D_00760D84 = 0;
    D_00760D88 = 0;
    D_00760D8C = 0;
}
