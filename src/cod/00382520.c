/* sn-2.95.3-136 */
#include "godhand/menuCtl.h"

/* Whether every other track has the volume of the picked one, on the right
 * channel or the left. ctx is not read. */
__attribute__((section(".text.func_00382520")))
int func_00382520(void *ctx, SndMixer *mix, unsigned char right)
{
    SndTrkSet *trk = &mix->trk;
    short *vol;
    short *sel;
    int i;

    if (right) {
        vol = mix->rvol;
        sel = &mix->rvol[mix->cur];
    } else {
        vol = mix->lvol;
        sel = &mix->lvol[mix->cur];
    }
    for (i = 0; i < trk->count; i++) {
        if (i != mix->cur - 1 && vol[i + 1] != *sel) {
            return 0;
        }
    }
    return 1;
}
