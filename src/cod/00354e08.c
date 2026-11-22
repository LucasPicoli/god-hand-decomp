/* cygnus-2.96: SFMPV_GetRead, takes a free stream entry, opens it into *out and records its
 * buffer range; in mode 2 also assigns it an owner id. */
#include "godhand/criStm.h"
extern void *SFMPVF_HoldFrm(StmSys *sys);
extern void sfmpv_SetFrmInf(StmSys *sys, StmSlot *ent, StmBuf **out);
extern void *SFTIM_IsGetFrmTime(StmSys *sys, StmBuf *buf);
extern int SFMPVF_IssueFrmId(StmSys *sys);

__attribute__((section(".text.SFMPV_GetRead")))
int SFMPV_GetRead(StmSys *sys, StmBuf **out, int *owner)
{
    StmRange *range = &sys->range;
    StmSlot *ent;
    StmBuf *buf;
    void *p;

    ent = SFMPVF_HoldFrm(sys);
    if (ent == 0) {
        *out = 0;
        return (int)ent;
    }
    sfmpv_SetFrmInf(sys, ent, out);
    buf = *out;
    range->start = buf->start;
    range->size = buf->size;
    p = SFTIM_IsGetFrmTime(sys, buf);
    if (p == 0) {
        *out = 0;
        return (int)p;
    }
    if (sys->mode == 2) {
        int id = SFMPVF_IssueFrmId(sys);
        ent->owner = id;
        *owner = id;
    }
    return 0;
}
