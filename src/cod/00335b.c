/* cygnus-2.96 matched TU — CRI libadxe, recovered from recvx-decomp (CC0). */
#include "godhand/globals.h"

typedef signed int Sint32;
typedef struct LSC_t { char _0[0x14]; Sint32 bufmin; Sint32 bsize; } LSC_t;
typedef LSC_t *LSC;
extern void func_00335D40();   /* LSC_CallErrFunc (variadic) */

__attribute__((section(".text.LSC_SetFlowLimit")))
void LSC_SetFlowLimit(LSC lsc, Sint32 min) {
    if (lsc == 0) {
        func_00335D40(D_00454F10);
        return;
    }
    if ((min < 0) || (min > lsc->bsize)) {
        func_00335D40(D_00454F40, min);
        return;
    }
    lsc->bufmin = min;
}
