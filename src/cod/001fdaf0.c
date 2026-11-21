/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

extern int KeyFollower_attachScaled(int a0, int a1, int a2, int a3, float f, int a5);

__attribute__((section(".text.cDamageUnit_AddDamageCollSphere")))
int cDamageUnit_AddDamageCollSphere(cDamageUnit *self, const struct cMatrix *mtx,
                                    const cVec *ofs, float radius)
{
    const cDamageVtEnt *vt;
    int node;
    int *head;
    int *last;
    int result;

    if (self->type == 0) {
        return -1;
    }
    vt = self->vt;
    node = ((int (*)(char *))vt[2].pfn)((char *)self + vt[2].delta);
    if (node == 0) {
        return -1;
    }
    if (func_001FD908(self) == 0) {
        return -1;
    }
    result = KeyFollower_attachScaled(node, func_001FD908(self), (int)mtx, (int)ofs, radius, (int)self);
    if (result == -1) {
        return -1;
    }
    head = (int *)self->nodes;
    if (head != 0) {
        last = head;
        if (*(int **)((char *)last + 0x24) != 0) {
            do {
                last = *(int **)((char *)last + 0x24);
            } while (*(int **)((char *)last + 0x24) != 0);
        }
        *(int **)((char *)last + 0x24) = (int *)node;
        *(int *)(node + 0x20) = (int)last;
    } else {
        self->nodes = (cDamageNode *)node;
    }
    return result;
}
