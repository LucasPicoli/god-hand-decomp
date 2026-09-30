/* cCoreSave_initAddGold - empty the recent-gold-pickup log. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_initAddGold")))
void cCoreSave_initAddGold(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->addGoldNum = 0;
}
