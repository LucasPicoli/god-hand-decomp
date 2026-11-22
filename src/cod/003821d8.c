/* sn-2.95.3-136: func_003821D8, push every channel's volume to the mixer; when func_00382850 reports
 * the list is active, muted channels are sent -960 instead. */
#include "godhand/menuCtl.h"
typedef struct MixCh {
    char unk00[4];
    short vol[0x16];            /* 0x04, 1-based */
    char unk30[0x18];           /* 0x30 start of the channel list header */
    unsigned char mute[1];      /* 0x48, 1-based */
} MixCh;

extern int func_00382850(void *self, SndTrkSet *list);
extern void AIXP_SetTrackVol(void *mixer, int ch, int vol);

__attribute__((section(".text.func_003821D8")))
void func_003821D8(void *self, MixCh *ch)
{
    SndTrkSet *list = (SndTrkSet *)ch->unk30;
    int i;

    if (func_00382850(self, list) != 0) {
        for (i = 0; i < list->count; i++) {
            if (ch->mute[i + 1])
                AIXP_SetTrackVol(list->ply, i, -0x3C0);
            else
                AIXP_SetTrackVol(list->ply, i, ch->vol[i + 1]);
        }
    } else {
        for (i = 0; i < list->count; i++)
            AIXP_SetTrackVol(list->ply, i, ch->vol[i + 1]);
    }
}
