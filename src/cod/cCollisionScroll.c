/* TU: cCollisionScroll - recovered C++ class. */
#include "include_asm.h"

extern void cCollisionScroll_SetCollEnableByName(void *a0, long acc, int a2);

__attribute__((section(".text.cCollisionScroll_SetCollEnable")))
void cCollisionScroll_SetCollEnable(void *a0, signed char *a1, int a2) {
    long acc = 0;
    int i = 0;
    if (*a1 != 0) {
        do {
            acc |= (long)*a1 << (i * 8);
            i++;
            a1++;
            if (i >= 8) break;
        } while (*a1 != 0);
    }
    cCollisionScroll_SetCollEnableByName(a0, acc, a2);
}
