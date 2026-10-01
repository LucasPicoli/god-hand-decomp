/* TU: cIDManager [id] - recovered C++ class. */
#include "godhand/cIDManager.h"

/* cIDManager_setIDData: look one resource up twice and keep both results in its slot. */

__attribute__((section(".text.cIDManager_setIDData")))
void cIDManager_setIDData(cIDManager *self, int slot, void *name) {
    self->pair[slot].data = SearchData(name, D_0044AF70, 0);
    self->pair[slot].tex = SearchData(name, D_0044AF70, 1);
}
