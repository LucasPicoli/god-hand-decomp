#include "godhand/cEma2.h"

/* cEma2_SetEscPos — guarded 3-float copy from a1 to a0+0x1590. sn-2.95.3-136. */

/* Copies the escape position from a1, unless a1 is the field itself. */
__attribute__((section(".text.cEma2_SetEscPos")))
void cEma2_SetEscPos(cEma2 *self, float *pos) {
    float *d = &self->escPos.x;
    if (d != pos) {
        d[0] = pos[0];
        d[1] = pos[1];
        d[2] = pos[2];
    }
}
