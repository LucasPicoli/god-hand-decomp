/* sn-2.95.3-136 matched TU. */

#include "godhand/pl00.h"
#include "godhand/cObj.h"

/* sn-2.95.3-136, cloned from pl00_CkSubScreen. */



#define PL00_FLAG_SUBSCREEN     0x400 /* unk15F4 bit: a sub-screen is forced open */
#define PL00_SUBSCREEN_PHASES   4     /* phases 0..3 of mode 0 are the sub-screen states */

/* Whether the player shows a sub-screen: the forced flag, or mode 0 with phase 0..3. */
__attribute__((section(".text.pl00_CkSubScreenOrForced")))
int pl00_CkSubScreenOrForced(pl00 *self)
{
    int phase;

    if (self->unk15F4 & PL00_FLAG_SUBSCREEN) {
        return 1;
    }
    if (self->base.mode != 0) {
ng: /* every return 0 jumps back here, as retail does */
        return 0;
    }
    phase = self->base.phase;
    if (phase >= PL00_SUBSCREEN_PHASES) goto ng;
    if (phase < 0) goto ng;
    return 1;
}

/* sn-2.95.3-136, cloned from pl00_CkSubScreen. */



/* Whether an object in mode 0 sits at step 2 or 3, or at step 6 or 7. */
__attribute__((section(".text.cObj_isStepActive")))
int cObj_isStepActive(cObj *self)
{
    int step;

    if (self->mode != 0) {
ng: /* every return 0 jumps back here, as retail does */
        return 0;
    }
    step = self->step;
    if (step < 2) goto ng;
    if (step < 4) goto ok;
    if (step >= 8) goto ng;
    if (step < 6) goto ng;
ok:
    return 1;
}
