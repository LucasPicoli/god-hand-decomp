/* sn-2.95.3-136 matched TU. */
#include "godhand/cDataManager.h"

/* 1 unless a slot holding kind is in any state but SLOT_STATE_IDLE. */
__attribute__((section(".text.cDataManager_isUnload")))
int cDataManager_isUnload(cDataManager *self, int kind)
{
    int i = self->slotNum;

    while (--i != -1) {
        if (self->slot[i].kind == kind && self->slot[i].state != SLOT_STATE_IDLE) {
            return 0;
        }
    }
    return 1;
}
