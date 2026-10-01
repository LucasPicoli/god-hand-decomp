/* cCoreSave_clearAllStageTime — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_clearAllStageTime")))
/* Zero the whole-game play time. */
void cCoreSave_clearAllStageTime(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->allStageTime = 0;
}
