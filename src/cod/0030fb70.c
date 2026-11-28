/* sn-2.95.3-136 matched TU. */
#include "godhand/sideCounter.h"
#include "godhand/objFactory.h"

/* 1 when an object of actor id `id` can be registered: the main list and the list for that
 * actor id (0 or any other) both have spare capacity. dataId is not read. */
__attribute__((section(".text.func_0030FB70")))
int func_0030FB70(int id, int dataId)
{
    if (id == 0) {
        if (PtrVecRef_hasRoom(&D_00754C30) && PtrVecRef_hasRoom(&D_00754C38.list))
            return 1;
        return 0;
    }
    if (PtrVecRef_hasRoom(&D_00754C30) && PtrVecRef_hasRoom(&D_00754C58))
        return 1;
    return 0;
}
