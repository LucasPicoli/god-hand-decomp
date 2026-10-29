/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"

/* 1 if every other track's mute flag equals the picked slot's, else 0.
 * self is not read. */
__attribute__((section(".text.func_003827F0")))
int func_003827F0(MenuCtl *self, MenuSnd *snd)
{
    /* the stream info follows the sound settings in MenuCtl */
    MenuSndInfo *info = (MenuSndInfo *)(snd + 1);
    int i;

    for (i = 0; i < info->track; i++) {
        if (i == snd->slot - 1)
            continue;
        if (info->mute[i + 1] != info->mute[snd->slot])
            return 0;
    }
    return 1;
}
