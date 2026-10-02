#include "godhand/vu0.h"

/* cCollisionSolid — constructor-style init: zero-fills two quadwords (0x10, 0x20),
 * sets a vtable/data pointer at 0x30, zeroes a few fields, sets flag bit 0 at
 * 0x8, returns the object. */

extern int D_0041D808;

__attribute__((section(".text.cCollisionSolid")))
void *cCollisionSolid(void *a0) {
    *(int *)((char *)a0 + 0x8) = 0;
    *(void **)((char *)a0 + 0x30) = &D_0041D808;
    VU0_SQC2_VF0(a0, 0x10);
    VU0_SQC2_VF0(a0, 0x20);
    *(int *)((char *)a0 + 0x4) = 0;
    *(int *)((char *)a0 + 0x0) = 0;
    *(int *)((char *)a0 + 0x8) |= 1;
    return a0;
}
