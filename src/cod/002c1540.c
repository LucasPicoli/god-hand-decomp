#include "godhand/cSceAtManager.h"

/* Age every unit's frame flags: SCEAT_FRAME_NOW moves to SCEAT_FRAME_PREV, then it,
 * SCEAT_FRAME_TRG, SCEAT_FRAME_UNK26 and SCEAT_FRAME_HANDLED clear. */
__attribute__((section(".text.func_002C1540")))
void func_002C1540(cSceAtManager *self)
{
    cSceAtUnit *u = cSceAtManager_getUnitList(self);

    while ((u = cSceAtManager_getNextUnit(self, u)) != 0) {
        u->frameFlags &= ~SCEAT_FRAME_PREV;
        if (u->frameFlags & SCEAT_FRAME_NOW) {
            u->frameFlags |= SCEAT_FRAME_PREV;
        }
        u->frameFlags &= ~SCEAT_FRAME_NOW;
        u->frameFlags &= ~SCEAT_FRAME_TRG;
        u->frameFlags &= ~SCEAT_FRAME_UNK26;
        u->frameFlags &= ~SCEAT_FRAME_HANDLED;
    }
}
