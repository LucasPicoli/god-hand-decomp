/* TU: cDataManager [system] - recovered C++ class. */
#include "godhand/cDataManager.h"

extern void cDataHolder_systemInit(cDataSlot *slot);
extern void func_001FF448(cDataSlot *slot);
extern void func_001FF470(cDataSlot *slot, int kind, void *buf);
extern int cDataManager_freeKind(cDataManager *self, int kind);
/* Load address of the slot holding kind, or 0. */
__attribute__((section(".text.cDataManager_seeDataAddress")))
int cDataManager_seeDataAddress(cDataManager *self, int kind) {
    int i = cDataManager_findKind(self, kind);
    if (i >= 0)
        return self->slot[i].data;
    return 0;
}

/* Drop every slot, last to first. */
__attribute__((section(".text.cDataManager_clear")))
void cDataManager_clear(cDataManager *self) {
    int i = self->slotNum;
    i--;
    while (i != -1) {
        func_001FF448(&self->slot[i]);
        i--;
    }
}

/* cDataManager_loadWait: return the load address of a kind, loading it into a free slot if needed. */

__attribute__((section(".text.cDataManager_loadWait")))
int cDataManager_loadWait(cDataManager *self, int kind, void *buf, int keep) {
    int i = cDataManager_findKind(self, kind);
    int data;
    if (i >= 0) {
        func_001FF090(&self->slot[i]);
        return self->slot[i].data;
    }
    i = cDataManager_findFreeSlot(self);
    if (i < 0) return 0;
    data = func_001FF180(&self->slot[i], kind, buf);
    while (UpdateStateReady_1FF238(&self->slot[i]) == 0) {
        func_002D5250(1);
    }
    if (keep != 0) {
        func_001FF090(&self->slot[i]);
    } else {
        self->slot[i].useCount = CDATA_USE_PINNED;
    }
    return data;
}
