/* sn-2.95.3-136 matched TU. */

#include "godhand/cObj.h"

#define PL00_SUBSCREEN_PHASES 4   /* phases 0..3 of mode 0 are the sub-screen states */

/* Whether the player sits in one of the sub-screen states: mode 0 and phase 0..3. */
__attribute__((section(".text.pl00_CkSubScreen")))
int pl00_CkSubScreen(cObj *self)
{
    int phase;

    if (self->mode != 0) {
ng: /* every return 0 jumps back here, as retail does; the if/else forms put it last */
        return 0;
    }
    phase = self->phase;
    if (phase >= PL00_SUBSCREEN_PHASES) goto ng;
    if (phase < 0) goto ng;
    return 1;
}
