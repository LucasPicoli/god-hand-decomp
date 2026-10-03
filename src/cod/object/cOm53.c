/* TU: cOm53 [object] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cOm53.h"

/* Set how many frames the lift waits before it rises. */
__attribute__((section(".text.cOm53_setRiseWaitTime")))
void cOm53_setRiseWaitTime(cOm53 *self, int frames) {
    self->riseWaitTime = frames;
}
