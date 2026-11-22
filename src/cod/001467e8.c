/* sn-2.95.3-136 matched TU. */

#include "godhand/cSceAtManager.h"
#include "godhand/cCockScroll.h"

extern int cIDBase_initialize();

/* Set up both parts (ids 0x1D and 0x1E), keep the first part's four entries and clear the queue. */
__attribute__((section(".text.func_001467E8")))
void func_001467E8(cCockScroll *self) {
    unsigned short i;
    cIDBase_initialize(self, 1, 0x1D);
    cIDBase_initialize(&self->part2, 1, 0x1E);
    i = 0;
    do {
        self->work[i] = cIDBase_getIDWork(&self->base, i);
        i = i + 1;
    } while (i < COCKSCROLL_WORK_NUM);
    self->count = 0;
    cCockScroll_reset(self);
}

/* SN ProDG ee-gcc 2.95.3. House style inherited from the matched
   src/cod/002c2138.c, which calls all three of these callees. */





__attribute__((section(".text.cSceAtManager_AtHitCheckNo")))
int cSceAtManager_AtHitCheckNo(cSceAtManager *self, float *pt, int id) {
    float pos[4];
    cArea area;
    cSceAtUnit *u;

    u = cSceAtManager_getUnit(self, id);
    pos[0] = pt[0];
    pos[1] = pt[1];
    pos[2] = pt[2];
    pos[3] = 1.0f;
    if (u == 0) return 0;
    func_002C1D68(self, &area, u);
    return cArea_HitCheck_1F83E8(&area, pos);
}
