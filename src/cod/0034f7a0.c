/* cygnus-2.96: Sofdec per-channel helpers (0x34F7A0..). */
#include "godhand/mwsfd.h"

__attribute__((section(".text.sfmps_GetPrepDst")))
int sfmps_GetPrepDst(SfdHn *hn)
{
    SfdChSet *set = &hn->ch;
    int ret = 0;

    if (set->chA != SFD_CH_NONE) {
        ret = SFBUF_GetPrepFlg(hn, set->chA);
    }
    if (set->chB != SFD_CH_NONE) {
        ret |= SFBUF_GetPrepFlg(hn, set->chB);
    }
    if (set->chC != SFD_CH_NONE) {
        ret |= SFBUF_GetPrepFlg(hn, set->chC);
    }
    return ret;
}

__attribute__((section(".text.sfmps_SetPrepDst")))
void sfmps_SetPrepDst(SfdHn *hn, int arg)
{
    SfdChSet *set = &hn->ch;

    if (set->chA != SFD_CH_NONE) {
        SFBUF_SetPrepFlg(hn, set->chA, arg);
    }
    if (set->chB != SFD_CH_NONE) {
        SFBUF_SetPrepFlg(hn, set->chB, arg);
    }
    if (set->chC != SFD_CH_NONE) {
        SFBUF_SetPrepFlg(hn, set->chC, arg);
    }
}
