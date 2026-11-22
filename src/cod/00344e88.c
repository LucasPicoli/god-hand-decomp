/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern void mwsffrm_SetFrmApi(int a0, int a1);

/* MATCH via cygnus-2.96. */






__attribute__((section(".text.mwPlyRelFrm")))
int mwPlyRelFrm(int a0, int a1) {
    if (GetField0OrZero_346828(a0) != 1) {
        return MWSFSVM_Error(D_00457918);
    }
    mwsffrm_SetFrmApi(a0, 2);
    return SFD_RelIdFrm(mwPlyGetSfdHn(a0), a1);
}
