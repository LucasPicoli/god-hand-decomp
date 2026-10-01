/* TU: ccoresave_gameinit [system] - recovered method extracted to its own TU
   (sn-2.95.3-136 cc1 ICEs on this body inside the full cCoreSave.c). */
/* cCoreSave_gameInit - reset the record for a new game. */
#include "godhand/cCoreSave.h"

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
