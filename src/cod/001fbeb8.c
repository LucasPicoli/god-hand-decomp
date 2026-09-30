/* cCoreSave_clearKillNpcNum - reset this stage's NPC kill count. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.cCoreSave_clearKillNpcNum")))
void cCoreSave_clearKillNpcNum(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->killNpcNum = 0;
}
