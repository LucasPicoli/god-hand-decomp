/* sn-2.95.3-136 matched TU. */
#include "godhand/fpu.h"
#include "godhand/cGameObj.h"
#include "godhand/cCollisionSolid.h"
#include "godhand/sceVu0.h"

/* Box against box: when they overlap, push ua's owner away from b along the
 * line between their centers, in x and z only. Returns 1 on contact. self is
 * not read. */
__attribute__((section(".text.cCollisionSolidManage_pushBoxBox")))
int cCollisionSolidManage_pushBoxBox(cCollisionSolidManage *self, cCollisionSolidManageUnit *ua,
                                     cCollisionSolidBox *a, cCollisionSolidManageUnit *ub,
                                     cCollisionSolidBox *b)
{
    cVec push;
    float reach;
    cCollisionSolidBoxWorld *pa = &a->world;
    cCollisionSolidBoxWorld *pb = &b->world;
    float dx;
    float dy;
    float dz;
    float dist;
    float depth;
    float keep;

    if (func_00136A88(pa, pb, &reach) == 0) {
        return 0;
    }
    dx = pb->center.x - pa->center.x;
    dy = pb->center.y - pa->center.y;
    dz = pb->center.z - pa->center.z;
    FPU_SQRT_S(dist, dx * dx + dy * dy + dz * dz);
    depth = reach - dist;
    if (depth <= 0.0f) {
        return 0;
    }
    if (ua->priority == 0) {
        return 1;
    }
    sceVu0SubVector(&push, &pa->center, &pb->center);
    sceVu0Normalize(&push, &push);
    sceVu0ScaleVector(&push, &push, depth);
    if (ua->priority == ub->priority) {
        keep = ub->share;
    } else if (ub->priority < ua->priority) {
        keep = 1.0f;
    } else {
        keep = 0.0f;
    }
    ua->owner->pos->x += push.x - push.x * (1.0f - keep);
    ua->owner->pos->z += push.z - push.z * (1.0f - keep);
    return 1;
}
