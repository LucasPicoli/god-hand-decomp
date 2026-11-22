/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern void NoOp_33E6A8(void);
extern void NoOp_33E6B0(void);

__attribute__((section(".text.func_0032A4A8")))
void *func_0032A4A8(void *a0) {
    void *ret;
    NoOp_33E6A8();
    ret = func_0032A4E0(a0);
    NoOp_33E6B0();
    return ret;
}

__attribute__((section(".text.func_00334008")))
void func_00334008(void *a0, void *a1) {
    void (*fn)(void *, void *, void *) = (void *)(long)D_003D9F6C;
    if (fn != 0) {
        fn((void *)(long)D_003D9F70, a1, a0);
    }
}
