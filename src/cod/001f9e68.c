/* sn-2.95.3-136 matched TU. */

extern void SetGlobalToggle_375700(int);

#include "godhand/cCoreSave.h"



/* Restore the world toggle saved in the record. */
__attribute__((section(".text.cCoreSave_loadWorldToggle")))
void cCoreSave_loadWorldToggle(cCoreSave *self)
{
    if (self->data != 0) {
        SetGlobalToggle_375700(self->data->worldToggle);
    }
}

#include "godhand/cCoreSave.h"



/* Clear the 0x30-byte block at 0x180. */
__attribute__((section(".text.cCoreSave_clearBlock180")))
void cCoreSave_clearBlock180(cCoreSave *self)
{
    if (self->data != 0) {
        func_003A52F0(self->data->unk180, 0, 0x30);
    }
}

#include "godhand/cCoreSave.h"



/* Clear the four fighting-ring clear masks. */
__attribute__((section(".text.cCoreSave_clearFightingRing")))
void cCoreSave_clearFightingRing(cCoreSave *self)
{
    if (self->data != 0) {
        func_003A52F0(self->data->fightingRingClear, 0, 0x10);
    }
}
