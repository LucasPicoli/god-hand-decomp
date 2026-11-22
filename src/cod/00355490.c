/* cygnus-2.96: stream/SFD/sound singletons. */
#include "godhand/criStm.h"

__attribute__((section(".text.SFMPVF_SearchVfrmData")))
void *SFMPVF_SearchVfrmData(StmSys *w, void *key)
{
    StmMgr *t = w->mgr;
    char *e;
    int i;

    for (i = 0, e = (char *)t->slot; i < t->num; i++, e += sizeof(StmSlot)) {
        if (e == key) {
            return w->ent[i];
        }
    }
    return 0;
}
