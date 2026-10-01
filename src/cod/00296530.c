/* sn-2.95.3-136 matched TU. */
#include "godhand/cEvent.h"


extern int cEvent_updateStart(cEvent *);
extern int func_00296818(cEvent *);
extern int func_00296958(cEvent *);
extern int UpdateSequenceState_296C28(cEvent *);
extern void cEvent_updateRelease(cEvent *);
extern void cEvent_movePlayStep(cEvent *);
/* Run the stage the record is in. A stage that returns nonzero hands over to
 * the next one in the same call, so the cases fall through. */
__attribute__((section(".text.func_00296530")))
void func_00296530(cEvent *self) {
    int flags;
    long t;

    flags = self->flags;
    t = flags;
    if (!(((unsigned long)t >> 3) & 1)) {
        if (flags & CEVENT_F_ACTIVE) {
            switch ((signed char)self->state) {
            case CEVENT_STATE_START:
                if (cEvent_updateStart(self) == 0) {
                    return;
                }
            case CEVENT_STATE_CLEAR:
                if (func_00296818(self) == 0) {
                    return;
                }
            case CEVENT_STATE_CREATE:
                if (func_00296958(self) == 0) {
                    return;
                }
            case CEVENT_STATE_PLAY:
                if (UpdateSequenceState_296C28(self) == 0) {
                    return;
                }
            case CEVENT_STATE_RELEASE:
                cEvent_updateRelease(self);
            }
        }
    } else {
        cEvent_movePlayStep(self);
    }
}
