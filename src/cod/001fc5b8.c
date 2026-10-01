/* func_001FC5B8 — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_001FC5B8")))
/* Zero the whole-game NPC kill count. */
void func_001FC5B8(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->allKillNpcNum = 0;
}
