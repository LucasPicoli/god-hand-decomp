/* ee-2.9-991111 matched TU. */

#include "godhand/sync.h"
#include "godhand/eeKernel.h"
typedef unsigned int u_int;



__attribute__((section(".text.VSync")))
void VSync(void)
{
    int stat;

    stat = DIntr();
    *(volatile u_int *)0x1000F000 = 4;
    GH_SYNC();
    if (stat) {
        EIntr();
    }
    while ((*(volatile u_int *)0x1000F000 & 4) == 0) {
        ;
    }
    stat = DIntr();
    *(volatile u_int *)0x1000F000 = 4;
    GH_SYNC();
    if (stat) {
        EIntr();
    }
}
