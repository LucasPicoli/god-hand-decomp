/* sn-2.95.3-136 matched TU. */
#include "godhand/cEmWrap.h"

extern void cEmWrap_SetVital(cEmWrap *self, int vital);

#define VITAL_FRACTION  0.15f           /* each enemy starts with 15 percent of its max */

/* Sets the health of the three group enemies (entries 0 to 2) to 15 percent of
 * their maximum. */
__attribute__((section(".text.cEmWrap_setGroupVitalFraction")))
void cEmWrap_setGroupVitalFraction(void)
{
    cEmWrap em[3];               /* only the entry numbers are set */
    em[0].entryNo = 0;
    em[1].entryNo = 1;
    em[2].entryNo = 2;
    cEmWrap_SetVital(&em[0], (int)(cEmWrap_GetVitalMax(&em[0]) * VITAL_FRACTION));
    cEmWrap_SetVital(&em[1], (int)(cEmWrap_GetVitalMax(&em[1]) * VITAL_FRACTION));
    cEmWrap_SetVital(&em[2], (int)(cEmWrap_GetVitalMax(&em[2]) * VITAL_FRACTION));
}
