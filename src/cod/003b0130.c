/* ee-2.9-991111 matched TU. */

#include "godhand/sync.h"
typedef unsigned int u_int;


extern void func_003B63F0(void);

__attribute__((section(".text.VSync")))
void VSync(void)
{
    int stat;

    stat = func_003B63A0();
    *(volatile u_int *)0x1000F000 = 4;
    GH_SYNC();
    if (stat) {
        func_003B63F0();
    }
    while ((*(volatile u_int *)0x1000F000 & 4) == 0) {
        ;
    }
    stat = func_003B63A0();
    *(volatile u_int *)0x1000F000 = 4;
    GH_SYNC();
    if (stat) {
        func_003B63F0();
    }
}
