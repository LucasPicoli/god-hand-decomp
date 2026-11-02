/* cSceAtManager_AtDataReset_2C2838 — look up the AT unit with id id; if it
 * exists, reset its data via cSceAtManager_AtDataReset.  sn-2.95.3-136. */

#include "godhand/cSceAtManager.h"

__attribute__((section(".text.cSceAtManager_AtDataReset_2C2838")))
void cSceAtManager_AtDataReset_2C2838(cSceAtManager *self, int id) {
    cSceAtUnit *unit = cSceAtManager_getUnit(self, id & 0xFFFF);
    if (unit)
        cSceAtManager_AtDataReset(self, unit);
}
