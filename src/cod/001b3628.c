/* sn-2.95.3-136 matched TU. */

#include "godhand/cOmb0.h"
#include "godhand/cWorldTime.h"

extern int D_00462FC0[];
extern void cCollisionSolidManage_ReleaseUnit(void *mgr, void *unit);
extern void func_002D9D50(cWorldTime *self, unsigned int ticks, unsigned int *h, unsigned int *m, unsigned int *s);

/* Clear the collision flag and give the sphere back to the manager. */
__attribute__((section(".text.cOmb0_ReleaseCollision")))
void cOmb0_ReleaseCollision(cOmb0 *self)
{
    self->collisionOn = 0;
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, self);
}

/* Split the global tick counter into hours, minutes and seconds. */
__attribute__((section(".text.cWorldTime_getGlobalHMS")))
void cWorldTime_getGlobalHMS(cWorldTime *self, unsigned int *h, unsigned int *m, unsigned int *s)
{
    func_002D9D50(self, self->globalTime, h, m, s);
}
