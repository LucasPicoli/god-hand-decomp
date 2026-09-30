/* cCoreSave_initContinueNum - reset this stage's continue count. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_initContinueNum")))
void cCoreSave_initContinueNum(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->continueNum = 0;
}
