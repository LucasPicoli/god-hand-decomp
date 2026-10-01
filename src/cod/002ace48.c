/* sn-2.95.3-136 matched TU. */

#include "godhand/cSceAtManager.h"
#include "godhand/cIDManager.h"

extern void func_002C0E20(cSceAtUnit *unit);

/* cSceAtManager_refreshUnit: poke an active unit that is flagged for refresh. */




__attribute__((section(".text.cSceAtManager_refreshUnit")))
void cSceAtManager_refreshUnit(cSceAtManager *self, cSceAtUnit *unit) {
    if (unit->state == 1 && (unit->flags & 1)) {
        func_002C0E20(unit);
    }
}

/* cIDManager_allocBufRun: take a run of n pool buffers, clear it, and queue a job that owns it. */


__attribute__((section(".text.cIDManager_allocBufRun")))
void *cIDManager_allocBufRun(cIDManager *self, int n, int tag, int arg) {
    char *buf;
    if (n == 0) return 0;
    if (CIDMGR_POOL_MAX - self->poolUsed < n) return 0;
    buf = self->pool + self->poolUsed * CIDMGR_BUF_SIZE;
    self->job[self->jobNum].active = 1;
    self->job[self->jobNum].buf = buf;
    self->job[self->jobNum].bufNum = n;
    self->job[self->jobNum].tag = tag;
    self->job[self->jobNum].arg = arg;
    self->jobNum++;
    self->poolUsed += n;
    func_003A52F0(buf, 0, n * CIDMGR_BUF_SIZE);
    return buf;
}
