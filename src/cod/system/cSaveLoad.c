/* TU: cSaveLoad [system] - recovered C++ class. */
#include "godhand/cSaveLoad.h"
#include "include_asm.h"

INCLUDE_ASM("nonmatching", cSaveLoad_openSave);


extern cSaveLoadTail D_00747A84;
extern int func_002BF700(cSaveLoad *self);
extern void func_002BF170(cSaveLoad *self);
/* Start a load: reset the card, raise the busy bit and write the request bytes. */
__attribute__((section(".text.cSaveLoad_openLoad")))
int cSaveLoad_openLoad(cSaveLoad *self)
{
    if (func_002BF700(self) == 0)
        return 0;
    func_002BF170(self);
    D_00747A84.stateFlags |= SAVELOAD_FLAG_BUSY;
    self->arg3 = 0;
    self->phase = 0;
    self->arg2 = 0;
    self->mode = SAVELOAD_MODE_LOAD;
    return 1;
}

