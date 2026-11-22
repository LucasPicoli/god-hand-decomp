#include "godhand/cSnd.h"

extern int cSnd_SeIsLoaded(void *, int);
extern void func_002B45C8(void *);

__attribute__((section(".text.func_002B3158")))
void func_002B3158(char *self)
{
    *(int *)(self + 0x10) = 0;
    *(int *)(self + 0x14) |= 8;
    *(int *)(self + 0x98) = 0;
    *(int *)(self + 0x9C) = 0;
    *(int *)(self + 0xA0) = 0;
    func_002B45C8(self);
}

__attribute__((section(".text.func_002B31F8")))
int func_002B31F8(int *p)
{
    if (p[7] != 0)
        return cSnd_SeIsLoaded(&D_005FEE00, p[8]);
    return 1;
}
