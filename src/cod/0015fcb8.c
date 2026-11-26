/* sn-2.95.3-136 matched TU. */

#include "godhand/SubSlotTable.h"
#include "godhand/HitNode.h"

/* Registers sub of the given kind in the first free slot. 1 if there was
 * one, 0 if the table is full. */
__attribute__((section(".text.SubSlotTable_register")))
int SubSlotTable_register(SubSlotTable *tbl, void *sub, int kind)
{
    int no = func_0015FD68(tbl);
    if (no < 0) {
        return 0;
    }
    tbl->slot[no].obj = sub;
    tbl->slot[no].kind = kind;
    return 1;
}

/* 1 when pt lies inside the node's height band and inside its XZ quad: the
 * point must sit on the inner side of all four edges, tested from corner 0
 * (edges to corners 1 and 3) and from corner 2 (edges to corners 1 and 3). */
__attribute__((section(".text.HitNode_containsQuadPoint")))
int HitNode_containsQuadPoint(HitNode *node, float *pt)
{
    float ox, oz, px, pz, bx, bz, dx, dz, cx, cz;

    if (pt[1] < node->yLo) {
    out: /* one shared return 0: the || form puts it last and does not match */
        return 0;
    }
    if (node->yHi < pt[1])
        goto out;
    ox = node->corner[0].x;
    oz = node->corner[0].z;
    px = pt[0] - ox;
    pz = pt[2] - oz;
    bx = node->corner[1].x - ox;
    bz = node->corner[1].z - oz;
    dx = node->corner[3].x - ox;
    dz = node->corner[3].z - oz;
    if (bz * px < bx * pz || dx * pz < dz * px)
        goto out;
    cx = node->corner[2].x - ox;
    cz = node->corner[2].z - oz;
    px -= cx;
    pz -= cz;
    bx -= cx;
    bz -= cz;
    dx -= cx;
    dz -= cz;
    if (bx * pz < bz * px || dx * pz > dz * px)
        goto out;
    return 1;
}
