/* sn-2.95.3-136: arena enemy spawn step for the six-slot wave: phase 0 defeats every enemy; phase 1 starts
 * the action of each waiting enemy entry (ids 2..7) as it becomes active, counts it and clears its slot. */
#include "godhand/cEmSetParam.h"
#include "godhand/ColiseumBattle.h"
extern void ColiseumBattle_DefeatAllEnemies(void *self);
extern void cEmSetParam_setEm(void *param, int slot);
extern void cEmWrap_StartAction(cEmWrap *act);

__attribute__((section(".text.func_001F1918")))
void func_001F1918(ColiseumBattle *self)
{
    char buf[0x10];
    switch (self->phase) {
    case 0:
        ColiseumBattle_DefeatAllEnemies(self);
        self->phase = self->phase + 1;
        break;
    case 1:
        if (self->unkC64[0] != 0 && IsEntryActive_1C2490(self->unkC64[0]) != 0) {
            buf[0] = 2;
            cEmSetParam_setEm(&D_00586AB0, 2);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[0] = 0;
        }
        if (self->unkC64[1] != 0 && IsEntryActive_1C2490(self->unkC64[1]) != 0) {
            buf[0] = 3;
            cEmSetParam_setEm(&D_00586AB0, 3);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[1] = 0;
        }
        if (self->unkC64[2] != 0 && IsEntryActive_1C2490(self->unkC64[2]) != 0) {
            buf[0] = 4;
            cEmSetParam_setEm(&D_00586AB0, 4);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[2] = 0;
        }
        if (self->unkC64[3] != 0 && IsEntryActive_1C2490(self->unkC64[3]) != 0) {
            buf[0] = 5;
            cEmSetParam_setEm(&D_00586AB0, 5);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[3] = 0;
        }
        if (self->unkC64[4] != 0 && IsEntryActive_1C2490(self->unkC64[4]) != 0) {
            buf[0] = 6;
            cEmSetParam_setEm(&D_00586AB0, 6);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[4] = 0;
        }
        if (self->unkC64[5] != 0 && IsEntryActive_1C2490(self->unkC64[5]) != 0) {
            buf[0] = 7;
            cEmSetParam_setEm(&D_00586AB0, 7);
            cEmWrap_StartAction(buf);
            self->enemyNum = self->enemyNum + 1;
            self->unkC64[5] = 0;
        }
        break;
    }
}
