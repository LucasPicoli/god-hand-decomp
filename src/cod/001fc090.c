/* cCoreSave_clearClearStage — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_clearClearStage")))
/* Forget which stages are cleared. */
void cCoreSave_clearClearStage(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->clearStageMask = 0;
}
