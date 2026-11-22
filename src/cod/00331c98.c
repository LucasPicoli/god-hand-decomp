/* cygnus-2.96 */
#include "godhand/globals.h"

extern void func_003B1F28(void *);

__attribute__((section(".text.SRD_SetFilesystem64")))
void SRD_SetFilesystem64(int value)
{
    D_003D8480 = value;
    if (value == 1)
        func_003B1F28(D_00454098);
}
