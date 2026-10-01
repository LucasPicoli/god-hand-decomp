/* TU: cDamageUnit [battle] - recovered C++ class. */
#include "godhand/vu0.h"
#include "godhand/cDamageUnit.h"

#define DAMAGE_FLAG_ACTIVE 2
#define DAMAGE_MASK_INACTIVE 0xFFFFFFFD  /* written out: ~2 compiles to a different insn */

/* Turn the hit volume of every node on (active == 1) or off. */
__attribute__((section(".text.cDamageUnit_SetDamageCollActive")))
void cDamageUnit_SetDamageCollActive(cDamageUnit *self, int active) {
    cDamageNode *node = self->nodes;
    if (node == 0) return;
    do {
        cDamageData *data = node->data;
        if (active == 1) {
            data->flags = data->flags | DAMAGE_FLAG_ACTIVE;
        } else {
            data->flags = data->flags & DAMAGE_MASK_INACTIVE;
        }
        node = node->next;
    } while (node != 0);
}

extern int cCollisionShape_setOffsetPos(cCollisionShape *shape, void *offset);
/* Move the hit volume of every node by the given offset. */
__attribute__((section(".text.cDamageUnit_SetDamageCollOffset")))
void cDamageUnit_SetDamageCollOffset(cDamageUnit *self, void *offset) {
    cDamageNode *node = self->nodes;
    while (node) {
        cCollisionShape_setOffsetPos(node->data->shape, offset);
        node = node->next;
    }
}
