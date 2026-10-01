/* Set the unit's action type and its argument. */
#include "godhand/cSceAtUnit.h"
__attribute__((section(".text.cSceAtUnit_ActTypeSet")))
void cSceAtUnit_ActTypeSet(cSceAtUnit *self, int actType, int actArg) {
    self->actType = actType;
    self->actArg = actArg;
}
#include "include_asm.h"

INCLUDE_ASM("nonmatching", cSceAtUnit_AtInit);
