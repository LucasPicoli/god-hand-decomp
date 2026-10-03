#include "godhand/cRoomSave.h"

/* cRoomSave_getFree — returns a pointer into the free-room table: for slot
 * a1<0x10, into the block at a0->0x0 (offset 0x1610 + a1*4); otherwise into a0
 * itself (offset 0x1618 + a1*4). Compiled with ee-2.9-991111. */

/* The free-list cell for slot n: the first 16 live in the current page, the
 * rest continue past the spare page's table. */
__attribute__((section(".text.cRoomSave_getFree")))
int *cRoomSave_getFree(cRoomSave *self, int n) {
    if ((unsigned)n < ROOMSAVE_FREE_NUM) return &self->data->freeTbl[n];
    return &self->spare.freeTbl[n];
}
