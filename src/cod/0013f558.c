/* sn-2.95.3-136 matched TU. */
#include "godhand/TrackSet.h"

#define TRACK_SYS_OFF      0x20000000   /* D_00747A84 bit 29: tracking disabled */
#define TRACK_OBJ_NO_TRACK 0x1000       /* object flag word at 0x2F0 */

extern unsigned int D_00747A84;

/* Add an object to the tracked set (5 slots) unless tracking is off or the object opts out. */
__attribute__((section(".text.func_0013F558")))
void func_0013F558(TrackSet *self, TrackObj *obj)
{
    if ((D_00747A84 & TRACK_SYS_OFF) == 0 && (obj->trackFlags & TRACK_OBJ_NO_TRACK) == 0) {
        unsigned int n = self->count;
        if (n < TRACK_SLOT_NUM) {
            do {
                self->obj[n] = obj;
                self->slotPtr[n] = &self->slot[n];
                self->state[n] = 0;
                self->count++;
            } while (0);
        }
    }
}
