#include "godhand/cEmSetParam.h"

/* cEmSetParam_setEmData — if the enemy-set record validates (func_00294B98),
 * apply all of its parameters (cEmSetParam_setEmAll).  sn-2.95.3-136. */

extern int func_00294B98(cEmSetParam *self);
extern void cEmSetParam_setEmAll(cEmSetParam *self);

/* Creates the room's enemies when the room file checks out. */
__attribute__((section(".text.cEmSetParam_setEmData")))
void cEmSetParam_setEmData(cEmSetParam *self) {
    if (func_00294B98(self))
        cEmSetParam_setEmAll(self);
}
