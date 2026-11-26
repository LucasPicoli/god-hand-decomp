/* cygnus-2.96 matched TU. */

#include "godhand/sfxalp.h"

/* volatile on both objects: it keeps the in-use count's lui out of the beqz
 * slot and its store out of the jr slot, which is retail's schedule. */
extern volatile SfxAlpWork D_003F1EC8;

/* Release a handle: mark it free and drop the pool's in-use count. */
__attribute__((section(".text.func_0036CB98")))
void func_0036CB98(volatile SfxAlpHn *hn)
{
    if (hn != 0) {
        hn->used = 0;
        D_003F1EC8.nUsed = D_003F1EC8.nUsed - 1;
    }
}
