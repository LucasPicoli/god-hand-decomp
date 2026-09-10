/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */
#include <godhand/sync.h>

typedef unsigned long long unsigned long long;



extern void SetVSyncFlag(volatile int *p, volatile unsigned long long *t);

__attribute__((section(".text.VSync2")))
unsigned long long VSync2(void)
{
    volatile int flag;
    volatile unsigned long long t;
    int di;

    flag = 0;
    SetVSyncFlag(&flag, &t);
    di = func_003B63A0();
    *(volatile int *)0x1000F000 = 4;
    GH_SYNC();
    if (di)
        func_003B63F0();
    while (((*(volatile int *)0x1000F000) & 4) == 0 && flag == 0)
        ;
    di = func_003B63A0();
    *(volatile int *)0x1000F000 = 4;
    GH_SYNC();
    if (di)
        func_003B63F0();
    return t;
}
