/* Trivial field setter (store-rotation order). */
#include "godhand/cEvent.h"

/* Put the record back to its idle state: all counters, flags and data
 * pointers cleared. */
__attribute__((section(".text.func_00297660")))
void func_00297660(cEvent *self) {
    self->state = 0;
    self->phase = 0;
    self->unk06 = 0;
    self->unk07 = 0;
    self->flags = 0;
    self->dataNo = 0;
    self->textData = 0;
}
