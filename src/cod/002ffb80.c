#include "godhand/vu0.h"
#include "godhand/globals.h"

/* func_002FFB80 — object constructor (InitObject + vtable@0xF0 + zero 0x2F0,
 * 0x300, 0x370, 0x380, 0x390). */

extern void *InitObject_2FBCC8(void *);

__attribute__((section(".text.func_002FFB80")))
void *func_002FFB80(void *a0) {
    if (a0) {
        InitObject_2FBCC8(a0);
        *(int **)((char *)a0 + 0xF0) = &D_0044E640;
        VU0_SQC2_VF0(a0, 0x2F0);
        VU0_SQC2_VF0(a0, 0x300);
        VU0_SQC2_VF0(a0, 0x370);
        VU0_SQC2_VF0(a0, 0x380);
        VU0_SQC2_VF0(a0, 0x390);
    }
    return a0;
}
