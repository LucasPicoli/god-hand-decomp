/* cCoreSave_clearEventFlags — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_clearEventFlags")))
/* Clear every event flag. */
void cCoreSave_clearEventFlags(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->eventFlags = 0;
}
