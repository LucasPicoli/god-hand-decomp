#include "godhand/cCollisionSolid.h"

__attribute__((section(".text.cCollisionSolid__dtor")))
void cCollisionSolid__dtor(cCollisionSolidObj *self, int flags) {
    self->vt = &D_0041D808;
    if (flags & 1) {
        __builtin_delete(self);
    }
}
