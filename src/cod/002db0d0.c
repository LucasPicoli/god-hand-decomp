/* sn-2.95.3-136: func_002DB0D0, find a live enemy with the given id in the enemy list. Without a position, the
 * first one; with a position, the nearest one within range (a negative range means unlimited). */
#include "godhand/cEmWrap.h"
#include "godhand/ptrVec.h"

#define EMACTOR_GONE  0xE0000000        /* objFlags: EMACTOR_FLAG_DEAD and the two bits below it */


extern float capVu0LengthAB(void *a, void *b);

__attribute__((section(".text.func_002DB0D0")))
cEmActor *func_002DB0D0(int id, void *pos, float range)
{
    cEmActor **it;
    float best;
    float d;

    if (pos == 0) {
        for (it = (cEmActor **)D_00754C30.v->begin; it != (cEmActor **)D_00754C30.v->end; it++) {
            cEmActor *e = *it;

            if (e->actorId == id && !(e->objFlags & EMACTOR_GONE))
                return e;
        }
        return 0;
    }
    if (0.0f <= range) {
        cEmActor *found = 0;

        best = range;
        for (it = (cEmActor **)D_00754C30.v->begin; it != (cEmActor **)D_00754C30.v->end; it++) {
            cEmActor *e = *it;

            if (e->actorId == id && !(e->objFlags & EMACTOR_GONE)) {
                d = capVu0LengthAB(pos, e->pos);
                if (d < best) {
                    found = *it;
                    best = d;
                }
            }
        }
        return found;
    }
    best = -1.0f;
    {
        cEmActor *found = 0;

        for (it = (cEmActor **)D_00754C30.v->begin; it != (cEmActor **)D_00754C30.v->end; it++) {
            cEmActor *e = *it;

            if (e->actorId == id && !(e->objFlags & EMACTOR_GONE)) {
                d = capVu0LengthAB(pos, e->pos);
                if (best < 0.0f || d < best) {
                    found = *it;
                    best = d;
                }
            }
        }
        return found;
    }
}
