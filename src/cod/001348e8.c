/* sn-2.95.3-136 matched TU. */
#include "godhand/cCollisionSolid.h"

#define CSOLID_BOUND        10000.0f

/* Refresh the bounds of obj's unit, test each of its active solids against
 * the active solids of every other unit, flag the touching pairs, list up to
 * CSOLID_HIT_MAX owners hit and return 1 on any hit. */
__attribute__((section(".text.cCollisionSolidManage_ChkHit")))
int cCollisionSolidManage_ChkHit(cCollisionSolidManage *self, struct cGameObj *obj)
{
    cVec min;
    cVec max;
    cCollisionSolidManageUnit *unit;
    cCollisionSolidManageUnit *other;
    cCollisionSolidObj *a;
    cCollisionSolidObj *b;
    unsigned int i;
    int ret;
    int hit;
    long scr = (unsigned int)obj->scrFlags;
    long noScrColl = scr >> 2 & 1;      /* GAMEOBJ_SCR_NOSCRCOLL */
    long suspended;                     /* GAMEOBJ_SCR_SUSPEND */

    if (noScrColl != 0)
        return 0;
    suspended = scr >> 3 & 1;
    if (suspended != 0)
        return 0;
    ret = 0;
    for (i = 0; i < CSOLID_HIT_MAX; i++)
        self->hits[i] = 0;
    self->hitNum = 0;
    unit = func_001346C8(self, obj);
    if (unit == 0)
        return 0;
    cVec_set4(&min, CSOLID_BOUND, CSOLID_BOUND, CSOLID_BOUND, 1.0f);
    cVec_set4(&max, -CSOLID_BOUND, -CSOLID_BOUND, -CSOLID_BOUND, 1.0f);
    for (b = unit->first; b != 0; b = b->next) {
        b->vt->updateBounds((char *)b + b->vt->updateBoundsDelta);
        if (min.x > b->min.x) min.x = b->min.x;
        if (min.y > b->min.y) min.y = b->min.y;
        if (min.z > b->min.z) min.z = b->min.z;
        if (max.x < b->max.x) max.x = b->max.x;
        if (max.y < b->max.y) max.y = b->max.y;
        if (max.z < b->max.z) max.z = b->max.z;
    }
    cVec_copy3(&unit->min, &min);
    cVec_copy3(&unit->max, &max);
    for (a = unit->first; a != 0; a = a->next) {
        long active = a->flags;

        if ((active & CSOLID_FLAG_ACTIVE) == 0)
            continue;
        for (other = self->first; other != 0; other = other->next) {
            long oscr;
            long osuspended;            /* GAMEOBJ_SCR_SUSPEND */

            if (unit == other)
                continue;
            oscr = (unsigned int)other->owner->scrFlags;
            osuspended = oscr >> 3 & 1;
            if (osuspended != 0)
                continue;
            if (func_00135250(self, &unit->min.x, &unit->max.x, &other->min.x, &other->max.x) == 0)
                continue;
            for (b = other->first; b != 0; b = b->next) {
                long bactive = b->flags;

                if ((bactive & CSOLID_FLAG_ACTIVE) == 0)
                    continue;
                hit = 0;
                if (a->state == CSOLID_STATE_SPHERE) {
                    if (b->state == CSOLID_STATE_SPHERE) {
                        if (func_00134CB0(self, unit, a, other, b) != 0)
                            hit = 1;
                    } else if (b->state == CSOLID_STATE_BOX) {
                        if (func_00134E18(self, unit, a, other, (cCollisionSolidBox *)b, 0) != 0)
                            hit = 1;
                    }
                } else if (a->state == CSOLID_STATE_BOX) {
                    if (b->state == CSOLID_STATE_SPHERE) {
                        if (func_00134E18(self, other, b, unit, (cCollisionSolidBox *)a, 1) != 0)
                            hit = 1;
                    } else if (b->state == CSOLID_STATE_BOX) {
                        if (cCollisionSolidManage_pushBoxBox(self, unit, (cCollisionSolidBox *)a, other,
                                                         (cCollisionSolidBox *)b) != 0)
                            hit = 1;
                    }
                }
                if (hit == 0)
                    continue;
                if (other->owner != 0 && self->hitNum < CSOLID_HIT_MAX) {
                    self->hits[self->hitNum] = other->owner;
                    self->hitNum++;
                }
                ret = 1;
                a->flags |= CSOLID_FLAG_HIT;
                b->flags |= CSOLID_FLAG_HIT;
            }
        }
    }
    return ret;
}
