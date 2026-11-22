/* cygnus-2.96: stream/SFD/sound singletons. */
#include "godhand/criStm.h"

__attribute__((section(".text.PS2RNA_SetSpu2CoreNo")))
void PS2RNA_SetSpu2CoreNo(StmVolHn *h, unsigned int mode)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return;
    }
    if (mode < 2 && h->mode != mode) {
        h->stat = h->mode;
        h->mode = mode;
    }
}
