/* func_001FC138 — if the object pointer at +0x0 is non-null, write a field. */
#include "godhand/cCoreSave.h"

__attribute__((section(".text.func_001FC138")))
/* Mark the paper as not found. */
void func_001FC138(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) data->paper = 0;
}
