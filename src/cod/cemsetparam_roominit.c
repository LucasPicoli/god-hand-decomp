#include "godhand/cEmSetParam.h"

/* cEmSetParam_roomInit — clear the room-set counters (0x8, 0xC) and run the
 * per-room init cEmSetParam_resetRoom.  sn-2.95.3-136. */

extern void cEmSetParam_resetRoom(cEmSetParam *self);

/* Forgets the loaded room file and runs the per-room init. */
__attribute__((section(".text.cEmSetParam_roomInit")))
void cEmSetParam_roomInit(cEmSetParam *self) {
    self->file = 0;
    self->entry = 0;
    cEmSetParam_resetRoom(self);
}
