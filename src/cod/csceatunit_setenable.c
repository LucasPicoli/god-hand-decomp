#include "godhand/cSceAtUnit.h"
extern void func_002C0E20(void *);
/* Set the enable bit; a type 9 unit is told about it. */
__attribute__((section(".text.cSceAtUnit_SetEnable")))
void cSceAtUnit_SetEnable(cSceAtUnit *self) {
    self->flags |= SCEATUNIT_ENABLED;
    if (self->type == SCEATUNIT_TYPE_NOTIFY)
        func_002C0E20(self);
}
