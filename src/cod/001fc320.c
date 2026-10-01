/* func_001FC320 — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_001FC320")))
/* Clear every event flag. */
void func_001FC320(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->eventFlags = 0;
}
