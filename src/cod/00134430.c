#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"

#define CSOLID_UNIT_MIN_OFFSET  0x20    /* cCollisionSolidManageUnit.min, for the VU0 store */
#define CSOLID_UNIT_MAX_OFFSET  0x30    /* cCollisionSolidManageUnit.max */

/* Unit constructor: set both bounds to (0, 0, 0, 1), then store the owner, the priority and
 * the share, with no solids and no next unit. */

__attribute__((section(".text.func_00134430")))
cCollisionSolidManageUnit *func_00134430(cCollisionSolidManageUnit *self, struct cGameObj *owner,
                                         int priority, float share) {
    VU0_SQC2_VF0(self, CSOLID_UNIT_MIN_OFFSET);
    VU0_SQC2_VF0(self, CSOLID_UNIT_MAX_OFFSET);
    self->owner = owner;
    self->priority = priority;
    self->share = share;
    self->first = 0;
    self->next = 0;
    return self;
}
