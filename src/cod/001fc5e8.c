/* cCoreSave_clearAllContinueNum — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_clearAllContinueNum")))
/* Zero the whole-game continue count. */
void cCoreSave_clearAllContinueNum(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->allContinueNum = 0;
}
