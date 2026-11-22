#include "godhand/vu0.h"
#include "godhand/globals.h"

/* func_001B8108 — object constructor: InitFields_1B6E90 base, set vtable at 0x214,
 * zero 0 quadword(s), return the object.  sn-2.95.3-136. */

extern void InitFields_1B6E90(void *);

__attribute__((section(".text.func_001B8108")))
void *func_001B8108(void *a0) {
    InitFields_1B6E90(a0);
    *(int **)((char *)a0 + 0x214) = &D_00428B58;
    return a0;
}
