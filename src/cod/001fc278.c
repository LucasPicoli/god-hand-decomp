/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern void SetSlotField98_1FC170(void *obj, int idx, int val);

typedef struct SlotObj {
    int base;
} SlotObj;

__attribute__((section(".text.func_001FC278")))
/* Empty every reel slot, then fill the first six with the starting god reels. */
void func_001FC278(cCoreSave *self) {
    unsigned int i;

    if (self->data != 0) {
        for (i = 0; i < 10; i++) {
            self->data->reelSlot[i] = 0x1F;
        }
        SetSlotField98_1FC170(self, 0, 1);
        SetSlotField98_1FC170(self, 1, 2);
        SetSlotField98_1FC170(self, 2, 3);
        SetSlotField98_1FC170(self, 3, 7);
        SetSlotField98_1FC170(self, 4, 0xE);
        SetSlotField98_1FC170(self, 5, 0x17);
    }
}
