/* sn-2.95.3-136 matched TU. */

#include "godhand/cHeatSys.h"

extern int cCoreSave_getState155(void *p);
extern void cHeatSys_UpdateHeatLv(cHeatSys *self);
extern void *D_00569B70;

/* Recompute max from the player record, pull cur down to it, refresh lv. `unused` is passed in $f12 by
 * cHeatSys_Initialize and never read. */
__attribute__((section(".text.cHeatSys_UpdateHeatMax")))
void cHeatSys_UpdateHeatMax(cHeatSys *self, float unused)
{
    float max = (float)(cCoreSave_getState155(&D_00569B70) * HEATSYS_MAX_STEP + HEATSYS_MAX_BASE);
    self->max = max;
    if (max < self->cur)
        self->cur = max;
    cHeatSys_UpdateHeatLv(self);
}
