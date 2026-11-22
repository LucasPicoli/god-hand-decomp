/* cygnus-2.96 */
#include "godhand/globals.h"

extern void func_003B9DE0(void *);

__attribute__((section(".text.func_003BA088")))
void func_003BA088(char *self)
{
    if (self == 0) {
        func_003B9DE0(D_00460928);
        return;
    }
    *(int *)(self + 0x24) = 1;
}
