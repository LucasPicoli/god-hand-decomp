/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cDataManager.h"

extern int D_007861A8;
extern int D_00460D48;
extern char D_0042C4F8[];
extern char D_0042C508[];
extern int D_007861B8;
extern char D_0042C518[];
extern int D_00583F20;

__attribute__((section(".text.GetSlotInstance_1FE530")))
void *GetSlotInstance_1FE530(void) {
    if (D_007861A8 == 0) {
        if (D_00460D48 == 0) {
            func_0031EEC8(&D_00460D48, D_0042C4F8);
        }
        SetField_0_4_8_31EEA8(&D_007861A8, D_0042C508, &D_00460D48);
    }
    return &D_007861A8;
}

__attribute__((section(".text.GetSlotInstanceB_1FE5E0")))
void *GetSlotInstanceB_1FE5E0(void) {
    if (D_007861B8 == 0) {
        if (D_00460D48 == 0) {
            func_0031EEC8(&D_00460D48, D_0042C4F8);
        }
        SetField_0_4_8_31EEA8(&D_007861B8, D_0042C518, &D_00460D48);
    }
    return &D_007861B8;
}

extern void cDataHolder_systemInit(cDataSlot *slot);
extern void func_001FF448(cDataSlot *slot);
extern void func_001FF470(cDataSlot *slot, int kind, void *buf);
extern int cDataManager_freeKind(cDataManager *self, int kind);
/* Re-init every slot, then set the state word. */
__attribute__((section(".text.ResetSlotArray_1FE6C8")))
void ResetSlotArray_1FE6C8(cDataManager *self, int state) {
    int i = self->slotNum;
    while (--i != -1) cDataHolder_systemInit(&self->slot[i]);
    self->unk00 = state;
}

/* 1 if the slot holding kind has finished loading. */
__attribute__((section(".text.cDataManager_isLoaded")))
int cDataManager_isLoaded(cDataManager *self, int kind) {
    int i = cDataManager_findKind(self, kind);
    if (i >= 0)
        return UpdateStateReady_1FF238(&self->slot[i]);
    return 0;
}

/* Free the slot holding kind. */
__attribute__((section(".text.cDataManager_freeKind")))
int cDataManager_freeKind(cDataManager *self, int kind) {
    int i = cDataManager_findKind(self, kind);
    if (i < 0) return 0;
    cDataHolder_systemInit(&self->slot[i]);
    return 1;
}

/* Replace the slot holding kind with a fresh load, pinned. */
__attribute__((section(".text.cDataManager_addPinnedData")))
int cDataManager_addPinnedData(cDataManager *self, int kind, void *buf) {
    int i = cDataManager_findKind(self, kind);
    if (i >= 0)
        cDataManager_freeKind(self, kind);
    i = cDataManager_findFreeSlot(self);
    if (i < 0) return 0;
    func_001FF470(&self->slot[i], kind, buf);
    self->slot[i].useCount = CDATA_USE_PINNED;
    return 1;
}

__attribute__((section(".text.UpdateStateReady_1FF238")))
int UpdateStateReady_1FF238(cDataSlot *a0) {
    int v1;
    int ret;
    if ((*(int*)((char*)a0+8) & 1) == 0) goto common;
    ret = cDvd_Check(&D_00583F20, *(int*)((char*)a0+0x1C));
    if (ret == 1) return 0;
    if (ret == 0) goto zero;
    if (ret == 2) return 0;
    v1 = *(int*)((char*)a0+0x20);
    goto check;
zero:
    *(int*)((char*)a0+8) &= -2;
common:
    v1 = *(int*)((char*)a0+0x20);
check:
    if (v1 != 0xFFFF) {
        if (IsSlotArrayValid_1FF540(a0) == 0) return 0;
    }
    v1 = 2;
    *(int*)((char*)a0+0) = v1;
    return 1;
}
