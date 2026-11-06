/* ee-2.9-991111 matched TU. */
#include "godhand/eeKernel.h"

extern int func_003B1E40();
extern void _sceSnprintf();

/* printf through func_003B1E40's output, with interrupts disabled while it formats. */
__attribute__((section(".text.func_003B1F28")))
void func_003B1F28(char *fmt, ...) {
    int ctx;
    int intr;
    ctx = 0;
    intr = DIntr();
    _sceSnprintf(func_003B1E40, &ctx, 0xFFFFFFFFU, fmt, (char *)__builtin_next_arg(fmt) - 0x38);
    if (intr) {
        EIntr();
    }
}
