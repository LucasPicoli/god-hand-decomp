/* sn-2.95.3-136 matched TU. */

extern char *InitFields_1B6E90(char *a0);
extern int D_0042AA98;

/* sn-2.95.3-136 candidate. */
#include "godhand/vu0.h"
#include "godhand/cDamageUnit.h"




__attribute__((section(".text.func_001C9140")))
void *func_001C9140(void *a0)
{
    char *s0 = (char *)a0;
    char *p;
    int i;

    InitFields_1B6E90(s0);
    *(int *)(s0 + 0x214) = (int)&D_0042AA98;
    VU0_SQC2_VF0(s0, 0x610);
    VU0_SQC2_VF0(s0, 0x620);
    VU0_SQC2_VF0(s0, 0x640);
    VU0_SQC2_VF0(s0, 0x6A0);
    p = s0 + 0x6B0;
    i = 6;
    do {
        VU0_SQC2_VF0(p, 0x0);
        VU0_SQC2_VF0(p, 0x10);
        p += 0x20;
    } while (--i != -1);
    return s0;
}

/* Append a cylinder volume at ofs in mtx's space, turned by rot; its id, or -1. */
__attribute__((section(".text.cDamageUnit_AddDamageCollCylinder")))
int cDamageUnit_AddDamageCollCylinder(cDamageUnit *self, const struct cMatrix *mtx,
                                      const cVec *ofs, const cVec *rot,
                                      float height, float radius)
{
    const cDamageVtEnt *ent;
    cDamageNode *node;
    cDamageNode *p;
    int r;

    if (self->type == CDAMAGE_TYPE_SPARE) return -1;
    ent = &self->vt[CDAMAGE_UNIT_NEWNODE];
    node = ((cDamageNode *(*)(void *))ent->pfn)((char *)self + ent->delta);
    if (node == 0) return -1;
    if (func_001FD908(self) == 0) return -1;
    r = cDamageNode_attachCylinder(node, func_001FD908(self), mtx, ofs, rot, height, radius, self);
    if (r == -1) return r;
    if (self->nodes != 0) {
        p = self->nodes;
        while (p->next != 0) p = p->next;
        p->next = node;
        node->prev = p;
    } else {
        self->nodes = node;
    }
    return r;
}
