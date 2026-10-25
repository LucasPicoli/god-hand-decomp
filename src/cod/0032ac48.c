/* cygnus-2.96 matched TU. */

#include "godhand/SndVol.h"

extern char D_00452348[];
extern void func_0033F130(char *msg);
extern void func_00328C80(void *voice, int a, int b);

/* Scale the volume limit by `rate` over `frames` steps of `a1`: the limit follows the scaled value
 * down but never rises above the current volume. A null object reports an error. */
__attribute__((section(".text.SndVol_applyRate")))
void SndVol_applyRate(SndVol *self, int a1, int frames, float rate)
{
    int step;
    int lim;
    void *voice;

    if (self == 0) {
        func_0033F130(D_00452348);
        return;
    }
    voice = self->voice;
    lim = self->vol;
    step = (int)(rate * (float)frames);
    step = step / 32 * a1 * 18 / 2048;
    if (step < lim) {
        lim = step;
    }
    self->volLimit = lim;
    if (voice != 0) {
        func_00328C80(voice, self->volLimit << SNDVOL_SHIFT, self->vol << SNDVOL_SHIFT);
    }
}
