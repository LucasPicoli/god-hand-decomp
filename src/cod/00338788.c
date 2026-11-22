/* cygnus-2.96: stream/SFD/sound singletons. */
#include "godhand/criStm.h"

__attribute__((section(".text.PS2RNA_SetOutVol")))
void PS2RNA_SetOutVol(StmVolHn *h, int vol)
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
