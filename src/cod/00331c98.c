/* cygnus-2.96 */
#include "godhand/globals.h"

extern void func_003B1F28(void *);

__attribute__((section(".text.func_00331C98")))
void func_00331C98(int value)
{
    D_003D8480 = value;
    if (value == 1)
        func_003B1F28(D_00454098);
}
