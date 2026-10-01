/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"

extern int Obj0000_Get_D_0076A7A4_3756F0(void);

/* Remember the current world toggle in the record. */
__attribute__((section(".text.func_001F9E28")))
void func_001F9E28(cCoreSave *self)
{
    if (self->data != 0) {
        self->data->worldToggle = Obj0000_Get_D_0076A7A4_3756F0();
    }
}
