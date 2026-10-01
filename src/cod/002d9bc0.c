/* Reset the global tick counter. */
#include "godhand/cWorldTime.h"
__attribute__((section(".text.cWorldTime_gameInit")))
void cWorldTime_gameInit(cWorldTime *self) { self->globalTime = 0; }
