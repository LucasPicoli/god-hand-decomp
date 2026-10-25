/* cygnus-2.96 matched TU. */

#include "godhand/SndSlide.h"


extern void func_00328C80(void *voice, int a, int b);

/* Start the slide on the voice: from the target scaled by `rate` of the base value, or from half
 * the target when no rate is set. */
__attribute__((section(".text.SndSlide_start")))
void SndSlide_start(SndSlide *self)
{
    if (self->rate == 0.0f) {
        func_00328C80(self->voice, self->target / 2, self->target);
    } else {
        int v = (int)((float)func_0032E3A0(self) * self->rate);

        func_00328C80(self->voice, v, self->target);
    }
}
