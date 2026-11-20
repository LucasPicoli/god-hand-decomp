/* sn-2.95.3-136 matched TU. */
#include "godhand/cGameObj.h"
#include "godhand/cCoreSave.h"
#include "godhand/vu0.h"
#include "godhand/DispMgr.h"

/* Pays out gold (doubled after a clear) and shows the amount at the object. */
__attribute__((section(".text.func_001C2408")))
void func_001C2408(cGameObj *self, int gold)
{
    cVec pos;

    if (gold <= 0) {
        return;
    }
    if (cCoreSave_getClearNum(&D_00569B70)) {
        gold *= 2;
    }
    cCoreSave_addGold(&D_00569B70, gold, 0);
    VU0_LQC2_SQC2_MEM(4, &pos, self->pos);
    cCockGetPoint_setData(&D_003BD6E8->getPoint, &pos, gold, self->id);
}
