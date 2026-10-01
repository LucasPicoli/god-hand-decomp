/* func_001FC090 — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_001FC090")))
/* Forget which stages are cleared. */
void func_001FC090(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->clearStageMask = 0;
}
