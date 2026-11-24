#include "godhand/cDamageUnit.h"

/* The deleting destructor of cCollisionShape: put the base vtable back and,
 * when flags bit 0 asks for it, free the shape. */
__attribute__((section(".text.func_002BAFE0")))
void func_002BAFE0(cCollisionShape *self, int flags)
{
    self->vt = D_0044BED0;
    if (flags & 1)
        func_002BB018(self, sizeof(cCollisionShape));
}
