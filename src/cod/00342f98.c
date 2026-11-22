/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void MWSFSVM_Error(char *s);



__attribute__((section(".text.mwPlyCalcWorkCprmSfd")))
int mwPlyCalcWorkCprmSfd(void *p)
{
    if (p == 0) {
        MWSFSVM_Error(D_004571D8);
        return 0;
    }
    return mwPlyCalcWorkSfd() + mwPlyCalcWorkCompo(p);
}
