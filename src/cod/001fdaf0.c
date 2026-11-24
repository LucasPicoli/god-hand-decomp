/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

/* Append a sphere volume at ofs in mtx's space; its id, or -1. */
__attribute__((section(".text.cDamageUnit_AddDamageCollSphere")))
int cDamageUnit_AddDamageCollSphere(cDamageUnit *self, const struct cMatrix *mtx,
                                    const cVec *ofs, float radius)
{
    const cDamageVtEnt *ent;
    cDamageNode *node;
    cDamageNode *last;
    int result;

    if (self->type == CDAMAGE_TYPE_SPARE) {
        return -1;
    }
    ent = &self->vt[CDAMAGE_UNIT_NEWNODE];
    node = ((cDamageNode *(*)(void *))ent->pfn)((char *)self + ent->delta);
    if (node == 0) {
        return -1;
    }
    if (func_001FD908(self) == 0) {
        return -1;
    }
    result = cDamageNode_attachSphere(node, func_001FD908(self), mtx, ofs, radius, self);
    if (result == -1) {
        return -1;
    }
    if (self->nodes != 0) {
        last = self->nodes;
        if (last->next != 0) {
            do {
                last = last->next;
            } while (last->next != 0);
        }
        last->next = node;
        node->prev = last;
    } else {
        self->nodes = node;
    }
    return result;
}
