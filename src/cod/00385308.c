/* sn-2.95.3-136: func_00385308, debug-menu stepper for one of two per-channel offsets (-15..15, with
 * -0x80 as off, wrapping through off); pad bit 0x8000 steps down, 0x2000 up, and the voice is updated. */
#include "godhand/menuCtl.h"
extern void func_0032A6D0(void *adxt, int which, int val);

#define VOICE_OFS_OFF (-0x80)

__attribute__((section(".text.func_00385308")))
void func_00385308(unsigned char *p, MenuPad *pad, unsigned char which)
{
    SndVoiceRef *snd = (SndVoiceRef *)(p + 0x484);
    short *v;
    int idx;

    if (which) {
        v = (short *)(p + 0x47A);
        idx = 1;
    } else {
        v = (short *)(p + 0x478);
        idx = 0;
    }
    if (pad->trg & 0x8000) {
        if (*v == VOICE_OFS_OFF)
            *v = 15;
        else if (*v >= -14)
            *v = *v - 1;
        else
            *v = VOICE_OFS_OFF;
        if (snd->voice != 0)
            func_0032A6D0(snd->voice, idx, *v);
    }
    if (pad->trg & 0x2000) {
        if (*v == VOICE_OFS_OFF)
            *v = -15;
        else if (*v < 15)
            *v = *v + 1;
        else
            *v = VOICE_OFS_OFF;
        if (snd->voice != 0)
            func_0032A6D0(snd->voice, idx, *v);
    }
}
