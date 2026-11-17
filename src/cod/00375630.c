/* sn-2.95.3-136 matched TU. */
#include "godhand/sndTiming.h"

/* Sets the system volumes and works out each sub-volume's level, scaled by its master. */
__attribute__((section(".text.SdeSystemVolSet")))
void SdeSystemVolSet(SndSystemVol *vol)
{
    D_0076A790.vol = *vol;
    D_0076A790.level[0] = 0;
    D_0076A790.level[1] = (D_0076A790.vol.master[1] << 8) * D_0076A790.vol.sub[0] / 127;
    D_0076A790.level[2] = (D_0076A790.vol.master[0] << 8) * D_0076A790.vol.sub[1] / 127;
    D_0076A790.level[3] = (D_0076A790.vol.master[1] << 8) * D_0076A790.vol.sub[2] / 127;
    D_0076A790.level[4] = (D_0076A790.vol.master[0] << 8) * D_0076A790.vol.sub[3] / 127;
    D_0076A790.level[5] = (D_0076A790.vol.master[1] << 8) * D_0076A790.vol.sub[4] / 127;
}
