/* cCoreSave_clearPaper — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_clearPaper")))
/* Mark the paper as not found. */
void cCoreSave_clearPaper(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->paper = 0;
}
