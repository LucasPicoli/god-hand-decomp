/* sn-2.95.3-136 matched TU. */

#include "godhand/cSceAtManager.h"
#include "godhand/cIDManager.h"

extern void func_002C0E20(cSceAtUnit *unit);

/* func_002C2EB8: poke an active unit that is flagged for refresh. */




__attribute__((section(".text.func_002C2EB8")))
void func_002C2EB8(cSceAtManager *self, cSceAtUnit *unit) {
    if (unit->state == 1 && (unit->flags & 1)) {
        func_002C0E20(unit);
    }
}

/* func_002ACE48: take a run of n pool buffers, clear it, and queue a job that owns it. */


__attribute__((section(".text.func_002ACE48")))
void *func_002ACE48(cIDManager *self, int n, int tag, int arg) {
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
