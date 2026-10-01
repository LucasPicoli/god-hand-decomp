/* sn-2.95.3-136 matched TU. */

#include "godhand/cEvent.h"

extern int D_00747A2C;
extern int D_00586B34;
extern unsigned char D_0074748C;

/* Nonzero when a cutscene is blocked by a screen flag. Needs the call-loop
 * pad: retail's assembler padded the short backward branch. */
__attribute__((section(".text.func_002967B0")))
int func_002967B0(cEvent *self)
{
    unsigned long f;

    if (D_00747A2C < 0) {
        return 0;
    }
    f = D_00586B34;
    if (((f >> 1) & 1) == 1) return 1;
    if (((f >> 2) & 1) == 1) return 1;
    if (((f >> 3) & 1) == 1) return 1;
    return (D_0074748C >> 2) & 1;
}
