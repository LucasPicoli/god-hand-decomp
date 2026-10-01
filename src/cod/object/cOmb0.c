/* TU: cOmb0 [object] - recovered C++ class. */
#include "godhand/cOmb0.h"
#include "include_asm.h"

extern int D_00462FC0;
void cCollisionSolidManage_CreateSphere(void *a, void *b, void *c, void *d, float e);
struct sph { int a; float b; int c; float d; };

void cCollisionSolidManage_CreateSphere(void *mgr, void *owner, void *pos, void *sphere, float radius);

/* Raise the collision flag and register a 1.75 radius sphere at the object's position. */
__attribute__((section(".text.cOmb0_SetCollision")))
void cOmb0_SetCollision(cOmb0 *self)
{
    cOmb0Sphere s;
    self->collisionOn = 1;
    s.unk00 = 0;
    s.radius = 1.75f;
    s.unk08 = 0;
    s.scale = 1.0f;
    cCollisionSolidManage_CreateSphere(&D_00462FC0, self, self->pos, &s, 1.75f);
}

