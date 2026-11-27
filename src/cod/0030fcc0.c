/* sn-2.95.3-136: func_0030FCC0, register an object in the main list and in the list for its actor id (0 or any other) if both have spare capacity. Returns 1 when added, 0 when either list is full. */
#include "godhand/sideCounter.h"
#include "godhand/cObjPtrArrayWrapper.h"
#include "godhand/cOmBase.h"

__attribute__((section(".text.func_0030FCC0")))
int func_0030FCC0(cObj *p)
{
    if (p->actorId == 0) {
        if (!PtrVecRef_hasRoom(&D_00754C30))
            return 0;
        if (!PtrVecRef_hasRoom(&D_00754C38.list))
            return 0;
        cObjPtrArrayWrapper_pushBack(&D_00754C30, p);
        cObjPtrArrayWrapper_pushBack(&D_00754C38.list, p);
        return 1;
    }
    if (!PtrVecRef_hasRoom(&D_00754C30))
        return 0;
    if (!PtrVecRef_hasRoom(&D_00754C58))
        return 0;
    cObjPtrArrayWrapper_pushBack(&D_00754C30, p);
    cObjPtrArrayWrapper_pushBack(&D_00754C58, p);
    return 1;
}
