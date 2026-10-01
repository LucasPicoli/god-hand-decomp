/* TU: ccoresave_gameinit [system] - recovered method extracted to its own TU
   (sn-2.95.3-136 cc1 ICEs on this body inside the full cCoreSave.c). */
/* cCoreSave_gameInit - reset the record for a new game. */
#include "godhand/cCoreSave.h"

extern void cCoreSave_clearGodItem(cCoreSave *);
extern void cCoreSave_setGold(cCoreSave *, int);
extern void cCoreSave_setGameLevel(cCoreSave *, int);
extern void cCoreSave_updateVitalMax(cCoreSave *);
extern int cCoreSave_getVitalMax(cCoreSave *);
extern void cCoreSave_setVital(cCoreSave *, int);
extern void cCoreSave_initCombos(cCoreSave *);
extern void cCoreSave_setCounter88(cCoreSave *, int);
extern void cCoreSave_setStat8A(cCoreSave *, int);
extern void cCoreSave_setUpgradeLv(cCoreSave *, int, int);
extern void cCoreSave_setClearNum(cCoreSave *, int);
extern void cCoreSave_clearKillEmNum(cCoreSave *);
extern void cCoreSave_clearKillNpcNum(cCoreSave *);
extern void cCoreSave_initAddGold(cCoreSave *);
extern void cCoreSave_initContinueNum(cCoreSave *);
extern void cCoreSave_clearClearStage(cCoreSave *);
extern void cCoreSave_resetCostumeNo(cCoreSave *, int);
extern void cCoreSave_clearBlock180(cCoreSave *);
extern void cCoreSave_initReelSlots(cCoreSave *);
extern void cCoreSave_clearEventFlags(cCoreSave *);
extern void cCoreSave_setReelItemNum(cCoreSave *, int);
extern void cCoreSave_clearFightingRing(cCoreSave *);
extern void cCoreSave_clearAllContinueNum(cCoreSave *);
extern void cCoreSave_clearAllKillEmNum(cCoreSave *);
extern void cCoreSave_clearAllKillNpcNum(cCoreSave *);
extern void cCoreSave_clearAllStageTime(cCoreSave *);
extern int cCoreSave_getGameDifficulty(cCoreSave *);
extern void cCoreSave_setGameLevel1_1F9AD0(cCoreSave *);
extern void cCoreSave_initEasyStart(cCoreSave *);
extern void cCoreSave_setGameLevel5_1F9AF0(cCoreSave *);
extern void cCoreSave_addGodItem(cCoreSave *, int);

__attribute__((section(".text.cCoreSave_gameInit")))
void cCoreSave_gameInit(cCoreSave *self)
{
    int v1;

    cCoreSave_clearGodItem(self);
    cCoreSave_setGold(self, 0);
    cCoreSave_setGameLevel(self, 1);
    cCoreSave_updateVitalMax(self);
    cCoreSave_setVital(self, cCoreSave_getVitalMax(self));
    cCoreSave_initCombos(self);
    cCoreSave_setCounter88(self, 0x80);
    cCoreSave_setStat8A(self, 4);
    cCoreSave_setUpgradeLv(self, 0, 0);
    cCoreSave_setUpgradeLv(self, 1, 0);
    cCoreSave_setUpgradeLv(self, 2, 0);
    cCoreSave_setUpgradeLv(self, 3, 0);
    cCoreSave_setClearNum(self, 0);
    cCoreSave_clearKillEmNum(self);
    cCoreSave_clearKillNpcNum(self);
    cCoreSave_initAddGold(self);
    cCoreSave_initContinueNum(self);
    cCoreSave_clearClearStage(self);
    cCoreSave_resetCostumeNo(self, 0);
    cCoreSave_clearBlock180(self);
    cCoreSave_initReelSlots(self);
    cCoreSave_clearEventFlags(self);
    cCoreSave_setReelItemNum(self, 2);
    cCoreSave_clearFightingRing(self);
    cCoreSave_clearAllContinueNum(self);
    cCoreSave_clearAllKillEmNum(self);
    cCoreSave_clearAllKillNpcNum(self);
    cCoreSave_clearAllStageTime(self);
    v1 = cCoreSave_getGameDifficulty(self);
    switch (v1) {
    case 1:
    default:
        cCoreSave_setGameLevel1_1F9AD0(self);
        break;
    case 0:
        cCoreSave_initEasyStart(self);
        break;
    case 2:
        cCoreSave_setGameLevel5_1F9AF0(self);
        break;
    }
    cCoreSave_addGodItem(self, 1);
    cCoreSave_addGodItem(self, 1);
    cCoreSave_addGodItem(self, 1);
}
