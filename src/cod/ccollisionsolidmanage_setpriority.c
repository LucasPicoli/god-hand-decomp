/* cCollisionSolidManage_SetPriority — find owner's unit with func_001346C8 and,
 * if it has one, set its priority (cCollisionSolidManageUnit_setPriority).
 * sn-2.95.3-136. */
#include "godhand/cCollisionSolid.h"

__attribute__((section(".text.cCollisionSolidManage_SetPriority")))
void cCollisionSolidManage_SetPriority(cCollisionSolidManage *self, struct cGameObj *owner, int priority) {
    cCollisionSolidManageUnit *unit = func_001346C8(self, owner);
    if (unit)
        cCollisionSolidManageUnit_setPriority(unit, priority);
}
