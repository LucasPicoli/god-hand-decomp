/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"
#include "godhand/CriTrackSet.h"

/* Send the picked slot's level to the player: slot 0 is the whole stream,
 * which first copies its level and index to the four tracks and then sets
 * every unmuted track; any other slot sets its own track unless it is muted.
 * self is not read. */
__attribute__((section(".text.func_003820C0")))
void func_003820C0(MenuCtl *self, MenuSnd *snd)
{
    /* the stream info follows the sound settings in MenuCtl */
    MenuSndInfo *info = (MenuSndInfo *)(snd + 1);
    int i;

    if (snd->slot == 0) {
        int j;

        for (j = 0; j < 4; j++) {
            snd->index[1 + j] = snd->index[0];
            snd->level[1 + j] = snd->level[0];
        }
    }
    if (info->ply == 0)
        return;
    if (snd->slot != 0) {
        if (info->mute[snd->slot] == 0)
            func_0032EC78((int)info->ply, snd->slot - 1, snd->level[snd->slot]);
        return;
    }
    for (i = 0; i < info->track; i++) {
        if (info->mute[i + 1] == 0)
            func_0032EC78((int)info->ply, i, snd->level[snd->slot]);
    }
}
