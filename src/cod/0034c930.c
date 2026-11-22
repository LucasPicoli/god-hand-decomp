/* cygnus-2.96 matched TU. */
#include "godhand/Sfd.h"

extern int SFTRN_CallTrtTrif(SfdHandle *self, int type, int call, int a3, int t0);

/* On a track that is not set up yet, make track-interface call
   SFD_TRIF_IDLE_CALL with arg1 and arg2; on a ready track do nothing. */
__attribute__((section(".text.SfdTrack_callIfIdle")))
int SfdTrack_callIfIdle(SfdHandle *self, int trno, int arg1, int arg2) {
    SfdTrack *table = self->track;
    SfdTrack *tr = table + trno;
    if (!__builtin_expect(tr->ready, 0))
        return SFTRN_CallTrtTrif(self, tr->type, SFD_TRIF_IDLE_CALL, arg1, arg2);
    return 0;
}
