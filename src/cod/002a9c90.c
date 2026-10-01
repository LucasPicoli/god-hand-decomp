/* Trivial field setter (store-rotation order). */
#include "godhand/cHeatSys.h"

/* Set the lv 1 threshold. */
__attribute__((section(".text.func_002A9C90")))
void func_002A9C90(cHeatSys *self, float threshold) { self->threshold = threshold; }
