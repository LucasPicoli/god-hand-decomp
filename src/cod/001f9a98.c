/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"

extern void Obj0000_Set_Byte_156_If_NonNull_1FAE28(cCoreSave *, int);
extern void cCoreSave_setGameLevel(cCoreSave *, int);

/* Easy-difficulty start: three usable god-item slots, game level 1. */
__attribute__((section(".text.func_001F9A98")))
void func_001F9A98(cCoreSave *self)
{
    Obj0000_Set_Byte_156_If_NonNull_1FAE28(self, 3);
    cCoreSave_setGameLevel(self, 1);
}
