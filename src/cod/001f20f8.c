/* sn-2.95.3-136: func_001F20F8, coliseum wave step: defeat every enemy, then whenever the ring
 * is clear, spawn the next of four waves 45 frames apart while unkB88 is below ring.unk0A. */
#include "godhand/ColiseumBattle.h"
#include "godhand/cEmSetParam.h"
extern void ColiseumBattle_DefeatAllEnemies(void *self);
extern int ColiseumBattle_CountLiveEnemies(void *a0);
extern int cRoomSave_clearEmDeadFlag(void *a0, int a1);
extern void cEmSetParam_setEm(void *a0, int a1);
extern void cEmWrap_StartAction(cEmWrap *a0);
extern int D_00568240;

/* Step 0 advances the phase through its address: as a field store, gcc schedules it
 * apart from the D_00568240 update and the code changes. */
#define COLISEUM_PHASE(self)  (*(int *)((char *)(self) + 0xB94))

static inline void spawnEm(ColiseumBattle *self, char *buf, int id)
{
    buf[0] = id;
    cEmSetParam_setEm(&D_00586AB0, id);
    cEmWrap_StartAction(buf);
    self->enemyNum = self->enemyNum + 1;
}

__attribute__((section(".text.func_001F20F8")))
void func_001F20F8(ColiseumBattle *self)
{
    int st;
    char bA[0x10];
    char bB[0x10];
    char bC[0x10];
    char bD[0x10];
    char bE[0x10];
    char bF[0x10];

    st = self->phase;
    switch (st) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        D_00568240 |= 6;
        self->phaseTimer = 45;
        COLISEUM_PHASE(self) += 1;
        break;
    case 1:
        if (self->unkB88 >= self->ring.unk0A)
            break;
        if (ColiseumBattle_CountLiveEnemies(self) != 0)
            break;
        if (self->phaseTimer == 0) {
            self->phaseTimer = 45;
            self->unkB90 = self->unkB90 + 1;
            if (self->unkB90 >= 4)
                self->unkB90 = 0;
            switch (self->unkB90) {
            case 0:
                cRoomSave_clearEmDeadFlag(&D_005E8658, 10);
                cRoomSave_clearEmDeadFlag(&D_005E8658, 11);
                cRoomSave_clearEmDeadFlag(&D_005E8658, 12);
                spawnEm(self, bA, 10);
                spawnEm(self, bB, 11);
                spawnEm(self, bC, 12);
                break;
            case 1:
                cRoomSave_clearEmDeadFlag(&D_005E8658, 3);
                cRoomSave_clearEmDeadFlag(&D_005E8658, 4);
                cRoomSave_clearEmDeadFlag(&D_005E8658, 5);
                spawnEm(self, bA, 3);
                spawnEm(self, bD, 4);
                spawnEm(self, bE, 5);
                break;
            case 2:
                cRoomSave_clearEmDeadFlag(&D_005E8658, 6);
                cRoomSave_clearEmDeadFlag(&D_005E8658, 7);
                cRoomSave_clearEmDeadFlag(&D_005E8658, 8);
                spawnEm(self, bA, 6);
                spawnEm(self, bB, 7);
                spawnEm(self, bF, 8);
                break;
            case 3:
                cRoomSave_clearEmDeadFlag(&D_005E8658, 9);
                spawnEm(self, bA, 9);
                break;
            }
        } else {
            self->phaseTimer = self->phaseTimer - 1;
        }
        break;
    }
}
