/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

__attribute__((section(".text.ADXT_GetOutPan")))
int ADXT_GetOutPan(int adxt, int ch)
{
    if (adxt == 0) {
        func_0033F130(D_00452228);
        return 0;
    }
    return *(short *)(ch * 2 + adxt + 0x42);
}
