/* TU: cEmSetParam [enemy] - recovered C++ class. */
#include "include_asm.h"
#include "godhand/cEmSetParam.h"

INCLUDE_ASM("nonmatching", cEmSetParam_setEmAll);

extern cEmSetEntry *cRoomSave_findEm();
extern cEmActor *func_002951B0(cEmSetParam *self, cEmSetEntry *entry);

/* Creates the enemy of entry no, unless the table is not loaded, the entry
 * is missing or done, or an enemy with its entry number is already listed.
 * Returns the new enemy, or 0. */
__attribute__((section(".text.cEmSetParam_setEm")))
cEmActor *cEmSetParam_setEm(cEmSetParam *self, unsigned char no)
{
    cEmSetEntry *entry;

    if ((D_005E8658.block->flags & EMSET_LOADED) == 0)
        return 0;
    entry = cRoomSave_findEm(&D_005E8658, no);
    if (entry == 0)
        return 0;
    if ((entry->done ^ EMSET_ENTRY_DONE) == 0)
        return 0;
    if (cEmManage_GetEm(&D_005864F0, entry->entryNo) != 0)
        return 0;
    if (entry->flags & EMSET_LOADED)
        entry->flags &= ~EMSET_LOADED;
    return func_002951B0(self, entry);
}

/* Stores the heading f (radians) in the current entry, in room-file units. */
__attribute__((section(".text.cEmSetParam_updateSetDataRot")))
void cEmSetParam_updateSetDataRot(float f) {
    cEmSetEntry *entry = cRoomSave_findEm(&D_005E8658);
    if (entry != 0) {
        entry->rot = (short)(int)(f * EMSET_ROT_PER_RAD);
    }
}


/* Stores how the current entry's enemy appears. */
__attribute__((section(".text.cEmSetParam_updateSetDataAppPattern")))
void cEmSetParam_updateSetDataAppPattern(int a, int b, unsigned char c) {
    cEmSetEntry *entry = cRoomSave_findEm(&D_005E8658);
    c = c & 0xFF;
    if (entry != 0) {
        entry->appPattern = c;
    }
}


INCLUDE_ASM("nonmatching", cEmSetParam_getSetDataPos);
