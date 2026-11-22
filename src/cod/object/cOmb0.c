/* TU: cOmb0 [object] - recovered C++ class. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cOmb0.h"
#include "include_asm.h"

/* Raise the collision flag and register a 1.75 radius sphere at the object's position. */
__attribute__((section(".text.cOmb0_SetCollision")))
void cOmb0_SetCollision(cOmb0 *self)
{
    cVec centre;
    self->collisionOn = 1;
    centre.x = 0.0f;
    centre.y = 1.75f;
    centre.z = 0.0f;
    centre.w = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, (cGameObj *)self, (const struct cMatrix *)self->base.mtx, &centre, 1.75f);
}

