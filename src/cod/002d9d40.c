/* Set the global tick counter. */
#include "godhand/cWorldTime.h"
__attribute__((section(".text.cWorldTime_setGlobalTime")))
void cWorldTime_setGlobalTime(cWorldTime *self, unsigned int ticks) { self->globalTime = ticks; }
