/* ee-2.9-991111 matched TU. */
#include "godhand/eeKernel.h"

void *iAllocTimerCounter(void);

__attribute__((section(".text.func_003B7270")))
void *func_003B7270(void) {
    int a = (int)DIntr();
    void *b = iAllocTimerCounter();
    if (a != 0) {
        EIntr();
    }
    return b;
}
