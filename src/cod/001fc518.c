/* cCoreSave_setBonus — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_setBonus")))
/* Set the fighting ring enemy list number. */
void cCoreSave_setBonus(cCoreSave *self, int v) {
    cCoreSaveData *data = self->data;
    if (data) data->fightingRingEmListNo = v;
}
