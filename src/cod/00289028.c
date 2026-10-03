#include "godhand/cEma2.h"

/* func_00289028 — accessor recovered by the symbolic decoder. */

/* Sets the poison flag and returns the new flag word. */
__attribute__((section(".text.func_00289028")))
int func_00289028(cEma2 *self) {
    self->flags = self->flags | EMA2_F_POISON;
    return self->flags | EMA2_F_POISON;
}
