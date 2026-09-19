/* ee-2.9-991111 matched TU. */

extern void func_003B63A0(void);
extern int EIntr(void);
extern int DisableIntc(int cause);
extern int EnableIntc(int cause);
extern int DisableDmac(int cause);

/* ee-2.9-991111; libkernl intr.o wrapper around the DisableIntc syscall stub. */

#include "godhand/sync.h"





__attribute__((section(".text.func_003B06D8")))
int func_003B06D8(int cause)
{
    unsigned int stat;
    int r;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    if (stat) {
        func_003B63A0();
    }
    r = DisableIntc(cause);
    GH_SYNC();
    if (stat) {
        EIntr();
    }
    return r;
}

/* ee-2.9-991111; libkernl intr.o wrapper around the EnableIntc syscall stub. */

#include "godhand/sync.h"





__attribute__((section(".text.func_003B0740")))
int func_003B0740(int cause)
{
    unsigned int stat;
    int r;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    if (stat) {
        func_003B63A0();
    }
    r = EnableIntc(cause);
    GH_SYNC();
    if (stat) {
        EIntr();
    }
    return r;
}

/* ee-2.9-991111; libkernl intr.o wrapper around the DisableDmac syscall stub. */

#include "godhand/sync.h"





__attribute__((section(".text.func_003B07A8")))
int func_003B07A8(int cause)
{
    unsigned int stat;
    int r;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    if (stat) {
        func_003B63A0();
    }
    r = DisableDmac(cause);
    GH_SYNC();
    if (stat) {
        EIntr();
    }
    return r;
}
