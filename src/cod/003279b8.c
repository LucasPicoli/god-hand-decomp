/* cygnus-2.96 */
#include "godhand/globals.h"

extern char D_003D04D0[];
extern void *func_003A52F0(void *, int, int);

__attribute__((section(".text.func_003279B8")))
int func_003279B8(void)
{
    int count;
    count = D_003D04B0 + 1;
    D_003D04B0 = count;
    if (count == 1)
        func_003A52F0(D_003D04D0, 0, 0xF00);
    return 1;
}
