/* cygnus-2.96: stream/SFD/sound singletons. */
#include "godhand/criStm.h"

__attribute__((section(".text.func_00338788")))
void func_00338788(StmVolHn *h, int vol)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0) {
        return;
    }
    if (vol > 0) {
        vol = 0;
    }
    if (vol < -999) {
        vol = -999;
    }
    h->vol = vol;
}
