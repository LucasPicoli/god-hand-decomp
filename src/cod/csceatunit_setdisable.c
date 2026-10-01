#include "godhand/cSceAtUnit.h"
extern void func_002C0E60(void *);
/* Clear the enable bit; a type 9 unit is told about it. */
__attribute__((section(".text.cSceAtUnit_SetDisable")))
void cSceAtUnit_SetDisable(cSceAtUnit *self) {
    self->flags &= ~SCEATUNIT_ENABLED;
    if (self->type == SCEATUNIT_TYPE_NOTIFY)
        func_002C0E60(self);
}
