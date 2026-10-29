/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"

extern int SdeSystemOutModeGet(void);

/* Remember the current world toggle in the record. */
__attribute__((section(".text.cCoreSave_saveWorldToggle")))
void cCoreSave_saveWorldToggle(cCoreSave *self)
{
    if (self->data != 0) {
        self->data->worldToggle = SdeSystemOutModeGet();
    }
}
