/* sn-2.95.3-136 matched TU. */
#include "godhand/cObj.h"

/* Set the actor id and the actorGroup bit of the id range it falls in. */
__attribute__((section(".text.cObj_setId")))
void cObj_setId(cObj *self, int id)
{
    self->actorId = id;
    self->actorGroup = 0;
    if (cObj_idInRange(self, 0x100, 0x1FF) & 0xFF) {
        self->actorGroup = COBJ_GROUP_PLAYER;
        return;
    }
    if (cObj_idInRange(self, 0x200, 0x300) & 0xFF) {
        self->actorGroup = COBJ_GROUP_2;
        return;
    }
    if (cObj_idInRange(self, 0x300, 0x500) & 0xFF) {
        self->actorGroup = COBJ_GROUP_3;
        return;
    }
    if (cObj_idInRange(self, 0x500, 0x600) & 0xFF) {
        self->actorGroup = COBJ_GROUP_4;
        return;
    }
    if (cObj_idInRange(self, 0x600, 0x700) & 0xFF) {
        self->actorGroup = COBJ_GROUP_5;
    }
}
