/* ee-2.9-991111 matched TU. */
#include "godhand/eeKernel.h"

void *iAllocTimerCounter(void);

__attribute__((section(".text.AllocTimerCounter")))
void *AllocTimerCounter(void) {
    int a = DIntr();
    void *b = iAllocTimerCounter();
    if (a != 0) {
        EIntr();
    }
    return b;
}
