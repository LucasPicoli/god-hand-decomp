/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"

/* Easy-difficulty start: three usable god-item slots, game level 1. */
__attribute__((section(".text.cCoreSave_initEasyStart")))
void cCoreSave_initEasyStart(cCoreSave *self)
{
    cCoreSave_setReelItemNum(self, 3);
    cCoreSave_setGameLevel(self, 1);
}
