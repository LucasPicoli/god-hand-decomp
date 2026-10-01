/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern int D_00747A84;

/* Step up one game level (3 goes straight to 5) and refill the graces. */
__attribute__((section(".text.cCoreSave_GameLevelUp")))
void cCoreSave_GameLevelUp(cCoreSave *self)
{
    if (self->data == 0) {
        return;
    }
    if ((D_00747A84 & 0x400000) != 0) {
        return;
    }
    switch (cCoreSave_getGameLevel(self) - 1) {
    default:
    case 0:
        cCoreSave_setGameLevel(self, 2);
        break;
    case 1:
        cCoreSave_setGameLevel(self, 3);
        break;
    case 2:
        cCoreSave_setGameLevel(self, 5);
        break;
    case 3:
        cCoreSave_setGameLevel(self, 5);
        break;
    case 4:
        return;
    }
    self->data->levelDownGrace = 2;
}
