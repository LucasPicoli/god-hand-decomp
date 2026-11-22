#include "godhand/vu0.h"
#include "godhand/globals.h"

/* func_002FFDC8 — object constructor (InitObject + vtable@0xF0 + zero 0x2C0,
 * 0x2E0). */

extern void *InitObject_2FBCC8(void *);

__attribute__((section(".text.func_002FFDC8")))
void *func_002FFDC8(void *a0) {
    if (a0) {
        InitObject_2FBCC8(a0);
        *(int **)((char *)a0 + 0xF0) = &D_0044EF08;
        VU0_SQC2_VF0(a0, 0x2C0);
        VU0_SQC2_VF0(a0, 0x2E0);
    }
    return a0;
}
