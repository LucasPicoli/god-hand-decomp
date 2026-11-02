/* sn-2.95.3-136 */
#include "godhand/sndRamp.h"

/* Step ramp no of self: clear its active bit once it has reached its target,
 * otherwise move it and mark self changed. */
__attribute__((section(".text.func_00377688")))
void func_00377688(SndRampOwner *self, int no)
{
    int bit = 1 << no;

    if (bit & self->active) {
        if (self->ramp[no].cur == self->ramp[no].target) {
            self->active &= ~bit;
            return;
        }
        func_00378070(&self->ramp[no]);
        self->flags |= 1;
    }
}
