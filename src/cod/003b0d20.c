/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */
#include "godhand/sync.h"

extern int iSignalSema(int semid);

__attribute__((section(".text.func_003B0D20")))
int func_003B0D20(int a0, int a1, int a2, int semid)
{
    iSignalSema(semid);
    GH_SYNC();
    GH_EI();
    return 0;
}
