/* sn-2.95.3-136 matched TU. */
#include "godhand/cDamageUnit.h"

__attribute__((section(".text.func_001FD9D8")))
int func_001FD9D8(cDamageUnit *self, const struct cMatrix *mtx, const cVec *ofs,
                  const cVec *rot, const cVec *size)
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
    result = KeyFollower_attach(node, func_001FD908(self), mtx, ofs, rot, size, self);
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
