/* TU: cDamageUnit [battle] - recovered C++ class. */
#include "godhand/vu0.h"
#include "godhand/cDamageUnit.h"


/* Turn the hit volume of every node on (active == 1) or off. */
__attribute__((section(".text.cDamageUnit_SetDamageCollActive")))
void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active) {
    cDamageNode *node = self->nodes;
    if (node == 0) return;
    do {
        cCollisionUnit *unit = node->unit;
        if (active == 1) {
            unit->flags = unit->flags | COLL_UNIT_FLAG_ACTIVE;
        } else {
            unit->flags = unit->flags & COLL_UNIT_FLAG_INACTIVE_MASK;
        }
        node = node->next;
    } while (node != 0);
}

/* Move the hit volume of every node by the given offset. */
__attribute__((section(".text.cDamageUnit_SetDamageCollOffset")))
void cDamageUnit_SetDamageCollOffset(cDamageUnit *self, const cVec *offset) {
    cDamageNode *node = self->nodes;
    while (node) {
        cCollisionShape_setOffsetPos(node->unit->shape, offset);
        node = node->next;
    }
}
