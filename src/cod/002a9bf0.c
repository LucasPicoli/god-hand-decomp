/* sn-2.95.3-136 matched TU. */

#include "godhand/cHeatSys.h"

extern int GetField155Byte_1FAEA0(void *p);
extern void func_002A9B50(cHeatSys *self);
extern void *D_00569B70;

/* Recompute max from the player record, pull cur down to it, refresh lv. `unused` is passed in $f12 by
 * cHeatSys_Initialize and never read. */
__attribute__((section(".text.func_002A9BF0")))
void func_002A9BF0(cHeatSys *self, float unused)
{
    float max = (float)(GetField155Byte_1FAEA0(&D_00569B70) * HEATSYS_MAX_STEP + HEATSYS_MAX_BASE);
    self->max = max;
    if (max < self->cur)
        self->cur = max;
    func_002A9B50(self);
}
