/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"
#include "godhand/cGameObj.h"
#include "godhand/cVec.h"
#include "godhand/sceVu0.h"
#include "godhand/fpu.h"

/* Sphere a of unit ua against box b of unit ub, in the ground plane: 0 when they don't touch. Else
 * push ua's owner (ub's when swapped) out by its share of the depth, unless its priority is 0, and
 * return 1. self is not read. */
__attribute__((section(".text.func_00134E18")))
int func_00134E18(cCollisionSolidManage *self, cCollisionSolidManageUnit *ua, cCollisionSolidObj *a,
                  cCollisionSolidManageUnit *ub, cCollisionSolidBox *b, int swapped)
{
    cVec center;
    cVec near;
    cVec push;
    cCollisionSolidBoxWorld *box;
    cVec *q;
    float dx;
    float dz;
    float dist;
    float depth;
    float keep;

    CVEC_STORE(&center, a->unk60);
    box = &b->world;
    CVEC_ZERO(near);
    q = &near;
    func_00137670(&center, box, q);
    dx = center.x - q->x;
    dz = center.z - q->z;
    FPU_SQRT_S(dist, dx * dx + dz * dz);
    if (a->radius < dist)
        return 0;
    if (swapped == 0) {
        if (ua->priority == 0)
            return 1;
        depth = a->radius - dist;
        if (ua->priority == ub->priority)
            keep = ub->share;
        else if (ub->priority < ua->priority)
            keep = 1.0f;
        else
            keep = 0.0f;
        sceVu0SubVector(&push, &center, &near);
        sceVu0Normalize(&push, &push);
        sceVu0ScaleVector(&push, &push, depth);
        ua->owner->pos->x += push.x - push.x * (1.0f - keep);
        ua->owner->pos->z += push.z - push.z * (1.0f - keep);
    } else {
        if (ub->priority == 0)
            return 1;
        depth = a->radius - dist;
        if (ua->priority == ub->priority)
            keep = ua->share;
        else if (ua->priority < ub->priority)
            keep = 1.0f;
        else
            keep = 0.0f;
        sceVu0SubVector(&push, &near, &center);
        sceVu0Normalize(&push, &push);
        sceVu0ScaleVector(&push, &push, depth);
        ub->owner->pos->x += push.x - push.x * (1.0f - keep);
        ub->owner->pos->z += push.z - push.z * (1.0f - keep);
    }
    return 1;
}
