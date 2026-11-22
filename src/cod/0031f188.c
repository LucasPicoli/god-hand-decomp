/* func_0031F188 — initialise an object: store a1 at 0x0, a vtable/data pointer
 * (D_00450FC0) at 0x4, a2 at 0x8, a3 at 0xC; return the object. */
#include "godhand/globals.h"

__attribute__((section(".text.func_0031F188")))
void *func_0031F188(void *a0, int a1, int a2, int a3) {
    *(int *)((char *)a0 + 0x0) = a1;
    *(int **)((char *)a0 + 0x4) = &D_00450FC0;
    *(int *)((char *)a0 + 0x8) = a2;
    *(int *)((char *)a0 + 0xC) = a3;
    return a0;
}
