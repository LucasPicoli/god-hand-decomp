/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int GetField0OrZero_346828(void *a0);
extern int MWSFSVM_Error(char *a0);
extern void mwPlyExecInfiniteLoopServer(int a0);
extern int Forward349480_349468(int a0);

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.mwPlyGetSfdHn")))
int mwPlyGetSfdHn(char *a0) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458238);
        return 0;
    }
    return *(int *)(a0 + 0x3C);
}

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.mwPlyGetInputSj")))
int mwPlyGetInputSj(char *a0) {
    if (GetField0OrZero_346828(a0) != 1) {
        MWSFSVM_Error(D_00458758);
        return 0;
    }
    return *(int *)(a0 + 0x1C0);
}

/* MATCH via cygnus-2.96 +drop-freorder. */



__attribute__((section(".text.MWSFSVR_MainThrdProc")))
int MWSFSVR_MainThrdProc(int a0) {
    int r;
    int c;
    mwPlyExecInfiniteLoopServer(a0);
    c = func_003492E8();
    r = 0;
    if (c == 1) {
        r = Forward349480_349468(a0);
    }
    return r;
}
