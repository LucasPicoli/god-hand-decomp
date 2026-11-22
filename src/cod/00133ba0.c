#include "godhand/cCollisionSolid.h"
__attribute__((section(".text.cCollisionSolidBox__dtor")))
void cCollisionSolidBox__dtor(cCollisionSolidObj *self, int flags) {
    self->vt = &D_0041D790;
    cCollisionSolid__dtor(self, flags);
}
