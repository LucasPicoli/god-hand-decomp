/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void MWSFLIB_SetErrCode(int e);
extern void MWSFSVM_Error(char *s);

__attribute__((section(".text.MWSFCRE_DestroySfd")))
void MWSFCRE_DestroySfd(void)
{
    if (SFD_Destroy() == 0) return;
    MWSFLIB_SetErrCode(-0x132);
    MWSFSVM_Error(D_004573B8);
}
