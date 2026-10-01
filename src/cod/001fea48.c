/* sn-2.95.3-136 matched TU. */

#include "godhand/cDataManager.h"

/* cDataManager_resetKind: reset every slot that holds the given kind. */


__attribute__((section(".text.cDataManager_resetKind")))
void cDataManager_resetKind(cDataManager *self, int kind, int arg) {
    int i;
    for (i = 0; i < self->slotNum; i++) {
        if (self->slot[i].kind == kind) {
            ResetSlotState_1FF2E0(&self->slot[i], arg);
        }
    }
}

/* cDataManager_findFreeSlot: index of the first slot that is empty and not reserved, or -1. */


__attribute__((section(".text.cDataManager_findFreeSlot")))
int cDataManager_findFreeSlot(cDataManager *self) {
    int i;
    unsigned long t;
    for (i = 0; i < self->slotNum; i++) {
        if (func_001FF0D8(&self->slot[i]) == 0) {
            t = self->slot[i].flags;
            if (((t >> 2) & 1) == 0) return i;
        }
    }
    return -1;
}

/* cDataManager_useDataAddress: find the slot of a kind, count one more use and return its load address. */


__attribute__((section(".text.cDataManager_useDataAddress")))
int cDataManager_useDataAddress(cDataManager *self, int kind) {
    int i = cDataManager_findKind(self, kind);
    if (i >= 0) {
        func_001FF090(&self->slot[i]);
        return self->slot[i].data;
    }
    return 0;
}

/* cDataManager_findKind: index of the last slot that holds the given kind, or -1. */


__attribute__((section(".text.cDataManager_findKind")))
int cDataManager_findKind(cDataManager *self, int kind) {
    int i = self->slotNum;
    i--;
    while (i != -1) {
        if (func_001FF0D8(&self->slot[i]) != 0) {
            if (self->slot[i].kind == kind) return i;
        }
        i--;
    }
    return -1;
}
