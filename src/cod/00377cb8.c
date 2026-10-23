/* sn-2.95.3-136 */
#include "godhand/seqNode.h"

/* Resets both SPU2 cores' state: full volume, effect areas at the top of
 * sound RAM (core 0 just below core 1). */
__attribute__((section(".text.func_00377CB8")))
void func_00377CB8(void)
{
    int i;

    for (i = 0; i < 2; i++) {
        D_0076A7D4[i].effEnd = 0x1FFFFF - i * 0x20000;
        D_0076A7D4[i].used = 1;
        D_0076A7D4[i].volL = 0x80;
        D_0076A7D4[i].volR = 0x80;
        D_0076A7D4[i].unk08 = 0;
        D_0076A7D4[i].unk0A = 0;
        D_0076A7D4[i].handle = func_00374AE0(1);
        D_0076A7D4[i].core = i;
    }
}
