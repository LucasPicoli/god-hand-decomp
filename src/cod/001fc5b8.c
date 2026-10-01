/* cCoreSave_clearAllKillNpcNum — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_clearAllKillNpcNum")))
/* Zero the whole-game NPC kill count. */
void cCoreSave_clearAllKillNpcNum(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->allKillNpcNum = 0;
}
