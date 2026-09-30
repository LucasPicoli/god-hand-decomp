/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

/* Starting levelPoint for each game level. The table holds ints; the game
 * reads the low halfword of each. */
extern unsigned short D_003BF178[];

/* Jump to game level 1..5 (clamped) and grant two level-down graces. */
__attribute__((section(".text.cCoreSave_setGameLevel")))
void cCoreSave_setGameLevel(cCoreSave *self, int level) {
    cCoreSaveData *data = self->data;
    int lvl = level;

    if (data != 0) {
        level = 2;
        lvl = lvl - 1;
        if (lvl < 0) {
            lvl = 0;
        }
        if (lvl >= CORESAVE_LEVEL_NUM) {
            lvl = CORESAVE_LEVEL_NUM - 1;
        }
        data->levelPoint = D_003BF178[lvl * 2];
        self->data->levelDownGrace = level;
    }
}
