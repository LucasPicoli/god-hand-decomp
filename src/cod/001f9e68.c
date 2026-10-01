/* sn-2.95.3-136 matched TU. */

extern void SetGlobalToggle_375700(int);

#include "godhand/cCoreSave.h"



/* Restore the world toggle saved in the record. */
__attribute__((section(".text.func_001F9E68")))
void func_001F9E68(cCoreSave *self)
{
    if (self->data != 0) {
        SetGlobalToggle_375700(self->data->worldToggle);
    }
}

#include "godhand/cCoreSave.h"



/* Clear the 0x30-byte block at 0x180. */
__attribute__((section(".text.func_001F9FC0")))
void func_001F9FC0(cCoreSave *self)
{
    if (self->data != 0) {
        func_003A52F0(self->data->unk180, 0, 0x30);
    }
}

#include "godhand/cCoreSave.h"



/* Clear the four fighting-ring clear masks. */
__attribute__((section(".text.func_001FC438")))
void func_001FC438(cCoreSave *self)
{
    if (self->data != 0) {
        func_003A52F0(self->data->fightingRingClear, 0, 0x10);
    }
}
