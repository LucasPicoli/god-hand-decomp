/* func_001FC518 — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_001FC518")))
/* Set the bonus value. */
void func_001FC518(cCoreSave *self, int v) {
    cCoreSaveData *data = self->data;
    if (data) data->bonus = v;
}
