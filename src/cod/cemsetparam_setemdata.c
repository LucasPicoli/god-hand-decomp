#include "godhand/cEmSetParam.h"

/* cEmSetParam_setEmData — if the enemy-set record validates (cEmSetParam_loadSetFile),
 * apply all of its parameters (cEmSetParam_setEmAll).  sn-2.95.3-136. */

extern int cEmSetParam_loadSetFile(cEmSetParam *self);
extern void cEmSetParam_setEmAll(cEmSetParam *self);

/* Creates the room's enemies when the room file checks out. */
__attribute__((section(".text.cEmSetParam_setEmData")))
void cEmSetParam_setEmData(cEmSetParam *self) {
    if (cEmSetParam_loadSetFile(self))
        cEmSetParam_setEmAll(self);
}
