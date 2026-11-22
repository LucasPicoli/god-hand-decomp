/* cygnus-2.96: MWSST_Reset, releases slot n of the handle's 0x20-byte slot table: when the slot was
 * active it is cleared, its stream is told to stop and the buffer goes back to the pool. */
#include "godhand/mwsfd.h"
#include "godhand/criSj.h"
extern int MWSST_IsEnable(MwsfdSlot *slot);
extern void MWSST_Stop(MwsfdSlot *slot);
extern int SFD_SetElementOutSj(void *sfd, char *buf, SjObj *sj, int a, int b);

__attribute__((section(".text.MWSST_Reset")))
void MWSST_Reset(MwsfdHn *hn, int n)
{
    MwsfdSlot *s = &hn->slot[n];
    void *sfd = hn->sfd;
    SjObj *sj = s->sj;
    char *buf = s->buf;

    if (MWSST_IsEnable(s) == 1) {
        MWSST_Stop(s);
        sj->vt->reset(sj);
        SFD_SetElementOutSj(sfd, buf + 0xC0, sj, 0, 0);
    }
}
