/* sn-2.95.3-136 */
#include "godhand/cGameObj.h"

/* Set the object's state bytes to phase 5, with stepArg 1 for mode 1. */
__attribute__((section(".text.func_0027DB20")))
void func_0027DB20(cGameObj *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj->mode = 0;
        obj->phase = 5;
        obj->step = 0;
        obj->stepArg = 0;
        break;
    case 1:
        obj->mode = 0;
        obj->phase = 5;
        obj->step = 0;
        obj->stepArg = 1;
        break;
    }
}
