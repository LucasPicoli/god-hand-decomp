/* cygnus-2.96 matched TU. */
#include "godhand/Sfd.h"

extern int func_0034DD70(SfdHandle *self, int error);

/* Write the object of track trno to *out. A track that is not set up raises
   SFD_ERR_TRACK_NOT_READY and leaves *out at 0. */
__attribute__((section(".text.SfdTrack_getObj")))
int SfdTrack_getObj(SfdHandle *self, int trno, void **out) {
    SfdTrack *table = self->track;
    SfdTrack *tr = table + trno;

    *out = 0;
    if (__builtin_expect(tr->ready, 0) == 0)
        return func_0034DD70(self, SFD_ERR_TRACK_NOT_READY);
    *out = tr->buf.obj;
    return 0;
}
