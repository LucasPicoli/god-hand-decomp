/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/globals.h"

extern void func_003A52F0(void *buf, int a1, int a2);
extern void func_003A7AE8(void *buf, void *s, void *args);
extern void Forward33B790_348C98(void *buf);

__attribute__((section(".text.MWSFSVM_Error")))
void MWSFSVM_Error(void *a0, ...) {
    func_003A52F0(D_00760C80, 0, 0x100);
    func_003A7AE8((void*)D_00760C80, a0, (char*)__builtin_next_arg(a0) - 0x38);
    Forward33B790_348C98(D_00760C80);
}
