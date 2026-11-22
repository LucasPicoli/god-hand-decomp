#include "godhand/cDamageUnit.h"

extern void UpdateObjWithVtableDispatch_2BB1F0(void *);

/* Put the unit in group and store the group's kind. */
__attribute__((section(".text.func_002B8A70")))
void func_002B8A70(cCollisionUnit *self, int group)
{
    self->group = group;
    self->kind = func_002B8A30(&D_005E8040, group);
}

/* Clear unkD8 and, when the unit is live, update its shape. */
__attribute__((section(".text.func_002B8AA8")))
void func_002B8AA8(cCollisionUnit *self)
{
    int active;
    self->unkD8 = 0;
    active = (self->flags & COLL_UNIT_FLAGS_MASK) == COLL_UNIT_FLAGS_LIVE;
    if (active)
        UpdateObjWithVtableDispatch_2BB1F0(self->shape);
}
