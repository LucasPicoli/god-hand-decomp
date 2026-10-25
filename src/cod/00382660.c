/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"

/* Lane-local: the player handle at +0x20 of MenuSndInfo; menuCtl.h has it as padding. */
#define MENUSND_PLY(info) (*(int *)((char *)(info) + 0x20))


extern void func_0032EC78(int ply, int ch, int vol);

#define MENUSND_MUTE_VOL  -0x3C0        /* volume sent for a muted channel */

/* Sound test: on a button press flip the mute flag of the picked slot (slot 0
 * is the master and sets all four channels), then send the player either the
 * mute volume or the channel's level. Spelled through self->sndInfo in the
 * copy loop because that is the form that keeps the loop counted up. */
__attribute__((section(".text.MenuCtl_toggleSndMute")))
void MenuCtl_toggleSndMute(MenuCtl *self, MenuPad *pad)
{
    MenuSnd *snd = &self->snd;
    MenuSndInfo *info = &self->sndInfo;

    if ((pad->press & 0xA000) == 0)
        return;
    info->mute[snd->slot] ^= 1;
    if (snd->slot == 0) {
        int j;

        for (j = 0; j < 4; j++)
            self->sndInfo.mute[1 + j] = info->mute[snd->slot];
    } else if (func_003827F0(self, snd) != 0) {
        info->mute[0] = info->mute[snd->slot];
    }
    if (MENUSND_PLY(info) == 0)
        return;
    if (snd->slot != 0) {
        if (info->mute[snd->slot])
            func_0032EC78(MENUSND_PLY(info), snd->slot - 1, MENUSND_MUTE_VOL);
        else
            func_0032EC78(MENUSND_PLY(info), snd->slot - 1, snd->level[snd->slot]);
        return;
    }
    if (info->mute[snd->slot]) {
        int i;

        for (i = 0; i < info->track; i++)
            func_0032EC78(MENUSND_PLY(info), i, MENUSND_MUTE_VOL);
    } else {
        int k;

        for (k = 0; k < info->track; k++)
            func_0032EC78(MENUSND_PLY(info), k, snd->level[k + 1]);
    }
}
