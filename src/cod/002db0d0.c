/* sn-2.95.3-136: func_002DB0D0, find a live enemy with the given id in the enemy list. Without a position, the
 * first one; with a position, the nearest one within range (a negative range means unlimited). */
#include "godhand/cEmWrap.h"

#define EMACTOR_GONE  0xE0000000        /* objFlags: EMACTOR_FLAG_DEAD and the two bits below it */

/* The list of live enemy actors. */
typedef struct {
    int unk00;
    cEmActor **begin;                   /* 0x04 */
    cEmActor **end;                     /* 0x08 */
} EmPtrList;

extern EmPtrList *D_00754C30;
extern float capVu0LengthAB(void *a, void *b);

__attribute__((section(".text.func_002DB0D0")))
cEmActor *func_002DB0D0(int id, void *pos, float range)
{
    cEmActor **it;
    float best;
    float d;

    if (pos == 0) {
        for (it = D_00754C30->begin; it != D_00754C30->end; it++) {
            cEmActor *e = *it;

            if (e->actorId == id && !(e->objFlags & EMACTOR_GONE))
                return e;
        }
        return 0;
    }
    if (0.0f <= range) {
        cEmActor *found = 0;

        best = range;
        for (it = D_00754C30->begin; it != D_00754C30->end; it++) {
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

        for (it = D_00754C30->begin; it != D_00754C30->end; it++) {
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
