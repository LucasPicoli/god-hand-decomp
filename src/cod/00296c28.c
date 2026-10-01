/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cEvent.h"


extern void cEvent_movePlayInit(cEvent *self);
extern void cEvent_movePlayQuit(cEvent *self);
extern int func_00296DD8(cEvent *self);
/* PLAY stage: start the move scene on phase 0, then step it until it ends
 * and fall back to the release stage. */
__attribute__((section(".text.UpdateSequenceState_296C28")))
int UpdateSequenceState_296C28(cEvent *self) {
    switch ((signed char)self->phase) {
    case 0:
        cEvent_movePlayInit(self);
        self->phase = self->phase + 1;
    case 1:
        if (func_00296DD8(self)) {
            cEvent_movePlayQuit(self);
            self->unk07 = 0;
            self->phase = 0;
            self->unk06 = 0;
            self->state = CEVENT_STATE_RELEASE;
            return 1;
        }
        return 0;
    }
    return 0;
}
