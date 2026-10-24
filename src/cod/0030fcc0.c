/* sn-2.95.3-136: func_0030FCC0, register an object in the main list and in the list for its actor id (0 or any other) if both have spare capacity. Returns 1 when added, 0 when either list is full. */
#include "godhand/sideCounter.h"
#include "godhand/cOmBase.h"

static inline unsigned int vecSize(PtrVecRef *l)
{
    return l->v ? (unsigned int)(l->v->end - l->v->begin) : 0;
}

static inline unsigned int vecCap(PtrVecRef *l)
{
    PtrVec *v = l->v;
    if (v) {
        void **b = v->begin;
        void **c = v->cap;
        return c - b;
    }
    return 0;
}

static inline int vecHasRoom(PtrVecRef *l)
{
    return vecSize(l) < vecCap(l);
}

__attribute__((section(".text.func_0030FCC0")))
int func_0030FCC0(cOmBase *p)
{
    if (p->actorId == 0) {
        if (!vecHasRoom(&D_00754C30))
            return 0;
        if (!vecHasRoom(&D_00754C38.list))
            return 0;
        func_003129D0(&D_00754C30, p);
        func_003129D0(&D_00754C38.list, p);
        return 1;
    }
    if (!vecHasRoom(&D_00754C30))
        return 0;
    if (!vecHasRoom(&D_00754C58))
        return 0;
    func_003129D0(&D_00754C30, p);
    func_003129D0(&D_00754C58, p);
    return 1;
}
