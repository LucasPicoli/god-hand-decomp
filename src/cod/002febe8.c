/* sn-2.95.3-136 matched TU. */
#include "godhand/espSys.h"

/* Sets the frame the animation ends at to len frames after the current one:
 * always for mode 1, for mode 0 only when that lengthens the run. An
 * animation with no end yet takes len itself. */
__attribute__((section(".text.EspAnim_setFramesLeft")))
void EspAnim_setFramesLeft(EspAnim *self, unsigned short len, int mode)
{
    int left;

    if (self->frameEnd == 0) {
        self->frameEnd = len;
        return;
    }
    left = self->frameEnd - self->frameIdx;
    if (mode == 1 || (mode == 0 && left < len)) {
        self->frameEnd = len + self->frameIdx;
    }
}
