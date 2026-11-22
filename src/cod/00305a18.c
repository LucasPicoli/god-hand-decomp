/* func_00305A18 — set the vtable pointer (D_00450080) at 0x424 and the float
 * field at 0x420 to 1.0; return the object. */
#include "godhand/globals.h"

__attribute__((section(".text.func_00305A18")))
void *func_00305A18(void *a0) {
    *(int **)((char *)a0 + 0x424) = &D_00450080;
    *(float *)((char *)a0 + 0x420) = 1.0f;
    return a0;
}
