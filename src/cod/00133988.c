#include "godhand/cCollisionSolid.h"
#include "godhand/vu0.h"

#define CSOLID_MIN_OFFSET  0x10         /* cCollisionSolidObj.min, for the VU0 store */
#define CSOLID_MAX_OFFSET  0x20         /* cCollisionSolidObj.max */

/* cCollisionSolid — base constructor: both bounds set to (0, 0, 0, 1), the
 * base method table, no next solid, state 0, CSOLID_FLAG_ACTIVE set. */

__attribute__((section(".text.cCollisionSolid")))
cCollisionSolidObj *cCollisionSolid(cCollisionSolidObj *self) {
    self->flags = 0;
    self->vt = &D_0041D808;
    VU0_SQC2_VF0(self, CSOLID_MIN_OFFSET);
    VU0_SQC2_VF0(self, CSOLID_MAX_OFFSET);
    self->state = 0;
    self->next = 0;
    self->flags |= CSOLID_FLAG_ACTIVE;
    return self;
}
