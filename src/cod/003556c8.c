/* cygnus-2.96: SFMPVF_HoldFrm, under the lock, picks the best unattached stream entry in state 2 or 4
 * according to sfmpvf_IsChkFirst. */
#include "godhand/criStm.h"
typedef struct {
    int pad[4];
} Lock;
extern void Thunk_func_0033B658(Lock *lk);
extern void Thunk_func_0033B670(Lock *lk);
extern int sfmpvf_IsChkFirst(StmSlot *best, StmSlot *cand);

__attribute__((section(".text.SFMPVF_HoldFrm")))
StmSlot *SFMPVF_HoldFrm(StmSys *sys)
{
    Lock lk;
    StmSlot *best = 0;
    StmSlot *ent;
    StmMgr *mgr;
    int i, n;

    Thunk_func_0033B658(&lk);
    mgr = sys->mgr;
    n = mgr->num;
    ent = mgr->slot;
    for (i = 0; i < n; i++, ent++) {
        if ((ent->stat == 2 || ent->stat == 4) && ent->owner == -1) {
            if (sfmpvf_IsChkFirst(best, ent) != 0)
                best = ent;
        }
    }
    Thunk_func_0033B670(&lk);
    return best;
}
