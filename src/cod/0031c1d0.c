#include "godhand/globals.h"
extern int func_003A50B4(void *, void *, int);
extern void func_0031C238(void *, void *, void *);

__attribute__((section(".text.func_0031C1D0")))
void func_0031C1D0(void *dest, char *src)
{
    if (src == 0)
        return;
    if (func_003A50B4(src, D_00450E88, 4) != 0)
        return;
    func_0031C238(dest, src + 4, src + 0x20);
}
