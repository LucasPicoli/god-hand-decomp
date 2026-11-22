#include "godhand/cCollisionSolid.h"

__attribute__((section(".text.cCollisionSolidSphere__dtor")))
void cCollisionSolidSphere__dtor(cCollisionSolidObj *self, int flags) {
    self->vt = &D_0041D7E0;
    cCollisionSolid__dtor(self, flags);
}
