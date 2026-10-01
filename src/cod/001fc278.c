/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void cCoreSave_setReelSlot(void *obj, int idx, int val);

typedef struct SlotObj {
    int base;
} SlotObj;

__attribute__((section(".text.cCoreSave_initReelSlots")))
/* Empty every reel slot, then fill the first six with the starting god reels. */
void cCoreSave_initReelSlots(cCoreSave *self) {
    unsigned int i;

    if (self->data != 0) {
        for (i = 0; i < 10; i++) {
            self->data->reelSlot[i] = 0x1F;
        }
        cCoreSave_setReelSlot(self, 0, 1);
        cCoreSave_setReelSlot(self, 1, 2);
        cCoreSave_setReelSlot(self, 2, 3);
        cCoreSave_setReelSlot(self, 3, 7);
        cCoreSave_setReelSlot(self, 4, 0xE);
        cCoreSave_setReelSlot(self, 5, 0x17);
    }
}
