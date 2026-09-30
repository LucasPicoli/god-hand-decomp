/* cCoreSave_setVital - set the player's current health. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_setVital")))
void cCoreSave_setVital(cCoreSave *self, int vital) {
    cCoreSaveData *data = self->data;
    if (data) data->vital = vital;
}
