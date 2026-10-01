/* TU: cObjSimple - recovered C++ class. */
#include "godhand/cObjSimple.h"
#include "include_asm.h"

extern void func_002DF938(void *a0, void *a1);

extern void EmClothInit(int id, cObjSimple *self, void *data, void *anchor);
/* Start the cloth pendulum `id` on this prop; copy its anchor into `a2` when given. */
__attribute__((section(".text.cObjSimple_SetPendulum")))
void cObjSimple_SetPendulum(cObjSimple *self, int id, void *a2) {
    self->pendulumId = id;
    self->pendulumOn = 1;
    EmClothInit(id, self, self->pendulumData, self->clothAnchor);
    if (a2) {
        func_002DF938(a2, self->clothAnchor);
    }
}
