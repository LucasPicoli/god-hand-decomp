/* sn-2.95.3-136 */

#include "godhand/cGameObj.h"

/* Whether obj is an item: its actor id lies in [0x3C0, 0x400). */
__attribute__((section(".text.func_001B8030")))
long func_001B8030(cGameObj *obj)
{
    return cGameObj_idInRange(obj, 0x3C0, 0x400);
}
