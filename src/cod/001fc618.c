/* func_001FC618 — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_001FC618")))
/* Zero the whole-game play time. */
void func_001FC618(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->allStageTime = 0;
}
