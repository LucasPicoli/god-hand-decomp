/* TU: cCoreSave [system] - recovered C++ class. */
#include "godhand/cCoreSave.h"
#include "include_asm.h"

extern unsigned short D_00747A50;   /* current stage id */
extern int D_0061A990[];
extern int D_003BF160[];            /* levelPoint thresholds, one per game level */
extern int D_00747A34;              /* cheat flags */
extern int D_00747A38;              /* cheat flags */

extern void func_002D9D48(int *a0, int a1);

/* Game level 1..5 from the level points. Level 4 is never reported: a
 * player past the third threshold is shown as level 5. */
__attribute__((section(".text.cCoreSave_getGameLevel")))
int cCoreSave_getGameLevel(cCoreSave *self)
{
    int i;
    int r;
    if (self->data == 0) return 0;
    for (i = 0; i < CORESAVE_LEVEL_NUM; i++) {
        if (self->data->levelPoint < D_003BF160[i]) break;
    }
    r = i;
    if (i >= 3) r = 4;
    return r + 1;
}

__attribute__((section(".text.cCoreSave_setClearNum")))
void cCoreSave_setClearNum(cCoreSave *self, unsigned short num) {
    if (self->data != 0) {
        self->data->clearNum = num;
        if (self->data->clearNum > CORESAVE_CLEAR_MAX) {
            self->data->clearNum = CORESAVE_CLEAR_MAX;
        }
    }
}

/* Add gold and log the pickup. clearLog == 1 empties the log afterwards. */
__attribute__((section(".text.cCoreSave_addGold")))
void cCoreSave_addGold(cCoreSave *self, int amount, int clearLog) {
    cCoreSaveData *data;
    int n;

    data = self->data;
    if (data == 0)
        return;
    n = data->addGoldNum;
    if (n < CORESAVE_ADD_GOLD_LOG) {
        data->addGold[n] = amount;
        self->data->addGoldNum += 1;
    }
    if (clearLog == 1)
        cCoreSave_initAddGold(self);
    self->data->gold += amount;
    if (self->data->gold > CORESAVE_GOLD_MAX)
        self->data->gold = CORESAVE_GOLD_MAX;
    if (self->data->gold < 0)
        self->data->gold = 0;
    if (D_00747A34 & 0x2000000)
        self->data->gold = CORESAVE_GOLD_MAX;
}

__attribute__((section(".text.cCoreSave_getKeyCardNum")))
int cCoreSave_getKeyCardNum(cCoreSave *self)
{
    cCoreSaveData *data = self->data;
    if (data == 0) return 0;
    return data->keyCardNum;
}

__attribute__((section(".text.cCoreSave_getKeyNum")))
int cCoreSave_getKeyNum(cCoreSave *self)
{
    cCoreSaveData *data = self->data;
    if (data == 0) return 0;
    return data->keyNum;
}

/* The all-items cheat (D_00747A38 & 0x8000000) unlocks every reel slot. */
__attribute__((section(".text.cCoreSave_getReelItem")))
int cCoreSave_getReelItem(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data == 0) {
        return 0;
    }
    if (D_00747A38 & 0x8000000) {
        data->reelItemNum = CORESAVE_GOD_ITEM_NUM;
    }
    return self->data->reelItemNum;
}

__attribute__((section(".text.cCoreSave_setSkill")))
void cCoreSave_setSkill(cCoreSave *self, int id, int lv)
{
    char v = (char)lv;
    if (self->data) {
        if (id < 0x80) {
            if (id < CORESAVE_SKILL_NUM) {
                self->data->skill[id] = v;
            }
        }
    }
}

/* -1 for an invalid id. The all-skills cheat (D_00747A34 & 0x800000)
 * reports 0 for every skill. */
__attribute__((section(".text.cCoreSave_getSkill")))
int cCoreSave_getSkill(cCoreSave *self, int id)
{
    cCoreSaveData *data;
    data = self->data;
    if (data == 0 || id >= 0x80 || id >= CORESAVE_SKILL_NUM) {
        return -1;
    }
    if (D_00747A34 & 0x800000) {
        return 0;
    }
    return data->skill[id];
}

/* level is 1-based, like cCoreSave_getGameLevel. */
__attribute__((section(".text.cCoreSave_getKillEmNum")))
short cCoreSave_getKillEmNum(cCoreSave *self, int level) {
    cCoreSaveData *data = self->data;
    if (data == 0) return 0;
    if (--level < 0) return 0;
    if (level >= CORESAVE_LEVEL_NUM) return 0;
    return data->killEmNum[level];
}

__attribute__((section(".text.cCoreSave_getKillNpcNum")))
short cCoreSave_getKillNpcNum(cCoreSave *self)
{
    cCoreSaveData *data = self->data;
    if (data == 0) return 0;
    return data->killNpcNum;
}

__attribute__((section(".text.cCoreSave_addKillNpcNum")))
void cCoreSave_addKillNpcNum(cCoreSave *self) {
    cCoreSaveData *data = self->data;
    if (data) {
        data->killNpcNum += 1;
        self->data->allKillNpcNum += 1;
    }
}

__attribute__((section(".text.cCoreSave_getCostumeNo")))
unsigned char cCoreSave_getCostumeNo(cCoreSave *self)
{
    cCoreSaveData *data = self->data;
    if (!data) return 0;
    return data->costumeNo;
}

/* Remembers the outgoing costume in prevCostumeNo. */
__attribute__((section(".text.cCoreSave_setCostumeNo")))
void cCoreSave_setCostumeNo(cCoreSave *self, unsigned int no) {
    cCoreSaveData *data;
    data = self->data;
    no = no & 0xFF;
    if (data == 0) {
        return;
    }
    data->prevCostumeNo = data->costumeNo;
    self->data->costumeNo = (unsigned char)no;
}

__attribute__((section(".text.cCoreSave_ckPaper")))
int cCoreSave_ckPaper(cCoreSave *self)
{
    cCoreSaveData *data = self->data;
    return data ? (data->paper != 0) : 0;
}

__attribute__((section(".text.cCoreSave_addAllStageTime")))
void cCoreSave_addAllStageTime(cCoreSave *self, int ticks)
{
    cCoreSaveData *data = self->data;
    if (data) {
        data->allStageTime = data->allStageTime + ticks;
    }
}

/* Reset the per-stage counters. Health refills to max except on stage 0x20. */
__attribute__((section(".text.cCoreSave_stageInit")))
void cCoreSave_stageInit(cCoreSave *self) {
    cCoreSave_clearKillEmNum(self);
    cCoreSave_clearKillNpcNum(self);
    cCoreSave_initContinueNum(self);
    cCoreSave_initItem(self);
    func_002D9D48(D_0061A990, 0);
    if (D_00747A50 != 0x20) {
        cCoreSave_setVital(self, cCoreSave_getVitalMax(self));
    }
}

/* Move id at `slot` of combo set `set`; 0 past the set's used length. */
__attribute__((section(".text.cCoreSave_getCombo")))
int cCoreSave_getCombo(cCoreSave *self, unsigned int set, unsigned int slot)
{
    unsigned int n;
    if (self->data == 0) return 0;
    if (slot >= CORESAVE_COMBO_LEN) return 0;
    n = cCoreSave_getComboMax(self, set);
    if (slot >= n) return 0;
    if (set >= CORESAVE_COMBO_SETS) return 0;
    return self->data->combo[set].id[slot];
}
