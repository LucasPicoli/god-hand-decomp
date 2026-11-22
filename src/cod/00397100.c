/* ee-2.9-991111 matched TU. */
#include "godhand/globals.h"

/* ee-2.9-991111 */


__attribute__((section(".text.sceDmaGetChan")))
int sceDmaGetChan(unsigned int i)
{
    if (i < 0xA) {
        return *(int *)(i * 4 + (int)&D_003F8580[4]);
    }
    return 0;
}
