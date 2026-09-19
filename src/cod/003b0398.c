/* ee-2.9-991111 matched TU. */

#include "godhand/sync.h"

typedef unsigned int u_int;

extern char *D_003FAE44;
extern void *EndOfHeap(void);
extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);

__attribute__((section(".text.sbrk")))
void *sbrk(int incr)
{
    u_int stat;
    char *old;
    char *end;

    GH_MFC0_STATUS(stat);
    stat &= 0x10000;
    if (stat) {
        u_int s;
        do {
            GH_DI();
            GH_SYNC_P();
            GH_MFC0_STATUS(s);
        } while (s & 0x10000);
    }
    end = D_003FAE44 + incr;
    if ((char *)EndOfHeap() < end) {
        *Obj0000_Get_D_003FA62C_3A4FB8() = 12;
        if (stat) GH_EI();
        return (void *)0xFFFFFFFF;
    }
    old = D_003FAE44;
    D_003FAE44 = end;
    if (stat) GH_EI();
    return old;
}
