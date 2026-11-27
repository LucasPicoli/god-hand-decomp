#include "godhand/pl00.h"
/* SN ProDG ee-gcc 2.95.3 matched TU. */

__attribute__((section(".text.pl00_setJump")))
void pl00_setJump(pl00 *a0, float f12) {
    *(float*)((char*)a0+0x670) = f12;
    a0->base.phase = 0x33;
    a0->base.mode = 0;
    a0->base.step = 0;
    a0->base.stepArg = 0;
}
