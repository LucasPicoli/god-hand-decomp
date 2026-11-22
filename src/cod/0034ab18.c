/* cygnus-2.96: sfadxt_SetAdxtHd, fills the audio info record once the ADX decoder has its header: rate,
 * channels, bits and the derived per-frame size. */
#include "godhand/mwsfd.h"
typedef struct {
    int valid; /* 0x00 */
    int size; /* 0x04 */
    int f8; /* 0x08 */
    int nch; /* 0x0C */
    int rate; /* 0x10 */
    int bits; /* 0x14 */
} AudInfo;
extern AudInfo *sfadxt_GetHd(SfdHn *hn);
extern int sfadxt_IsEndDecinfo(void *adxt);
extern int func_0032A530(void *adxt);
extern int func_0032A4A8(void *adxt);
extern int func_0032A5B8(void *adxt);

__attribute__((section(".text.sfadxt_SetAdxtHd")))
void sfadxt_SetAdxtHd(SfdHn *hn)
{
    AudInfo *inf = sfadxt_GetHd(hn);
    void *adxt;

    if (inf == 0 || inf->valid != 0)
        return;
    adxt = *hn->adxt;
    if (sfadxt_IsEndDecinfo(adxt) == 0)
        return;
    inf->rate = func_0032A530(adxt);
    inf->bits = func_0032A4A8(adxt);
    inf->nch = func_0032A5B8(adxt);
    inf->size = inf->rate * inf->nch * 9 / 16;
    inf->f8 = 1;
    inf->valid = 1;
}
