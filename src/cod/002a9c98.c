/* sn-2.95.3-136 matched TU. */

#include "godhand/cHeatSys.h"

/* cur / max, or 0 when max is 0. */
__attribute__((section(".text.func_002A9C98")))
float func_002A9C98(cHeatSys *self)
{
    float ratio = 0.0f;
    if (self->max != 0.0f)
        ratio = self->cur / self->max;
    return ratio;
}
