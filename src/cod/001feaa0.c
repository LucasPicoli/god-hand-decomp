/* sn-2.95.3-136 matched TU. */
#include "godhand/cDataManager.h"

extern void func_002D5250(int a0);
extern unsigned short D_00747A50;

/* sn-2.95.3-136 matched TU. */







extern void AddQueueEntry_1FF4D0(cDataSlot *slot, int id);
/* Queue the load of data id on the slot of kind (plus its companions) and wait until it is ready.
   Bit 0 of flags picks the alternate id of a few ids. */
__attribute__((section(".text.cDataManager_loadSeWait")))
void cDataManager_loadSeWait(cDataManager *self, int kind, int id, int flags) {
    int v0;

    v0 = cDataManager_findKind(self, kind);
    if (v0 < 0) {
        return;
    }
    if ((flags & 1) != 0) {
        switch (id) {
        case 0x200:
            id = 0x227;
            break;
        case 0x203:
            id = 0x22A;
            break;
        case 0x204:
            id = 0x22B;
            break;
        case 0x21A:
            id = 0x22C;
            break;
        case 0x21D:
            id = 0x22E;
            break;
        case 0x21E:
            id = 0x22F;
            break;
        case 0x21B:
            id = 0x22D;
            break;
        case 0x225:
            id = 0x24D;
            break;
        case 0x240:
            id = 0x24A;
            break;
        case 0x242:
            id = 0x243;
            break;
        case 0x249:
            id = 0x24E;
            break;
        }
    }
    if (D_00747A50 == 0x504) {
        if ((unsigned int)(id - 0x250) < 2) {
            return;
        }
    }
    AddQueueEntry_1FF4D0(&self->slot[v0], id);
    switch (kind) {
    case 0x264:
        AddQueueEntry_1FF4D0(&self->slot[v0], 0x263);
        break;
    case 0x278:
        AddQueueEntry_1FF4D0(&self->slot[v0], 0x20F);
        break;
    case 0x211:
        AddQueueEntry_1FF4D0(&self->slot[v0], 0x200);
        AddQueueEntry_1FF4D0(&self->slot[v0], 0x203);
        AddQueueEntry_1FF4D0(&self->slot[v0], 0x227);
        AddQueueEntry_1FF4D0(&self->slot[v0], 0x22A);
        break;
    }
    while (UpdateStateReady_1FF238(&self->slot[v0]) == 0) {
        func_002D5250(1);
    }
}
