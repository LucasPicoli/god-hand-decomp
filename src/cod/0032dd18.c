/* cygnus-2.96 matched TU. */
#include "godhand/globals.h"

extern int Obj33F8_Tramp_0033F130_FCB0(char *p);

__attribute__((section(".text.func_0032DD18")))
int func_0032DD18(char *a0, int a1) {
    int small = a1 < 0x21;
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452B98);
        return 0;
    }
    if (!small) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452BC0);
        return 0;
    }
    return *(int *)(a0 + (a1 << 2) + 0xC);
}

__attribute__((section(".text.func_0032E228")))
int func_0032E228(unsigned char *a0) {
    unsigned int t;
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452DB0);
        return -1;
    }
    t = (unsigned int)a0[1] - 1;
    if (t < 3) {
        return func_0032F4C8(*(int *)(a0 + 4));
    }
    return 0;
}

__attribute__((section(".text.func_0032E2B8")))
int func_0032E2B8(unsigned char *a0) {
    unsigned int t;
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452DE8);
        return -1;
    }
    t = (unsigned int)a0[1] - 1;
    if (t < 3) {
        return func_0032F4F0(*(int *)(a0 + 4));
    }
    return 0;
}

__attribute__((section(".text.func_0032E348")))
int func_0032E348(unsigned char *a0) {
    unsigned int t;
    if (a0 == 0) {
        Obj33F8_Tramp_0033F130_FCB0(D_00452E20);
        return -1;
    }
    t = (unsigned int)a0[1] - 1;
    if (t < 3) {
        return func_0032F528(*(int *)(a0 + 4));
    }
    return 0;
}

__attribute__((section(".text.SRD_SceClose")))
int SRD_SceClose(int a0) {
    int s0;
    func_00331D40(a0);
    s0 = func_003B44B0(a0);
    if (s0 < 0) {
        func_003B1F28(D_00454150, s0);
    }
    func_00331D78();
    return s0;
}
