/* ee-2.9-991111 matched TU. */
#include "godhand/eeKernel.h"

extern int D_003FAE50;
extern int SifSetDma(int, int);

/* SifSetDma(a, b), or func_003B2080(a, b, 0) while D_003FAE50 is set; interrupts are
 * disabled until just before either call. */
__attribute__((section(".text.func_003B2148")))
int func_003B2148(int a, int b) {
    int res = DIntr();
    if (D_003FAE50 != 0) {
        if (res != 0) {
            EIntr();
        }
        return func_003B2080(a, b, 0);
    }
    if (res != 0) {
        EIntr();
    }
    return SifSetDma(a, b);
}
