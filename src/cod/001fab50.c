/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "include_asm.h"

extern int cCoreSave_getComboMax(cCoreSave *self, unsigned int set);
extern int func_001FC210(cCoreSave *self);
extern void SetSlotField98_1FC170(cCoreSave *self, unsigned char slot, int no);

/* Put an item in the first empty unlocked slot. 1 on success. */
__attribute__((section(".text.cCoreSave_addGodItem")))
int cCoreSave_addGodItem(cCoreSave *self, unsigned char item) {
    unsigned int i;
    for (i = 0; (i < CORESAVE_GOD_ITEM_NUM) && (i < self->data->reelItemNum); i++) {
        if (self->data->godItem[i] == 0) {
            self->data->godItem[i] = item;
            return 1;
        }
    }
    return 0;
}

/* Level of the move at `slot` of combo set `set`; 0 past the set's used length. */
__attribute__((section(".text.cCoreSave_getComboLv")))
int cCoreSave_getComboLv(cCoreSave *self, unsigned int set, unsigned int slot)
{
    if (self->data == 0) return 0;
    if (slot >= CORESAVE_COMBO_LEN) return 0;
    if (slot >= cCoreSave_getComboMax(self, set)) return 0;
    if (set >= CORESAVE_COMBO_SETS) return 0;
    return self->data->combo[set].lv[slot];
}

/* Unlock god reel `no` and put it in the first free reel slot. */
__attribute__((section(".text.cCoreSave_setGodReel")))
void cCoreSave_setGodReel(cCoreSave *self, int no) {
    cCoreSaveData *data = self->data;
    int slot;
    if (data == 0) return;
    if (no >= CORESAVE_GOD_REEL_NUM) return;
    data->godReel |= 1 << no;
    slot = func_001FC210(self);
    if (slot == -1) return;
    SetSlotField98_1FC170(self, slot, no);
}

/* 1 if god reel `no` is unlocked. The all-reels cheat (D_00747A34 & 2)
 * unlocks every reel. This C is exact except for the two nops retail's
 * assembler put before the `no` range test: the R5900 short-loop pad,
 * which our ee-as does not apply to a backward branch whose target block
 * ends in `jr $ra`. */
#ifdef NON_MATCHING
extern int D_00747A34;

__attribute__((section(".text.cCoreSave_ckGodReel")))
int cCoreSave_ckGodReel(cCoreSave *self, int no) {
    cCoreSaveData *data = self->data;
    unsigned long cheat;
    int ret;
    if (data == 0) return 0;
    if (no >= CORESAVE_GOD_REEL_NUM) return 0;
    cheat = D_00747A34;
    if (((cheat >> 1) & 1UL) == 1UL) return 1;
    ret = 1;
    if ((data->godReel & (1 << no)) == 0) ret = 0;
    return ret;
}
#else
INCLUDE_ASM("nonmatching", cCoreSave_ckGodReel);
#endif
