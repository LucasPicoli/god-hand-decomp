/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"

extern int SdeSystemOutModeGet(void);

/* Remember the current sound output mode in the record. */
__attribute__((section(".text.cCoreSave_saveSoundOutMode")))
void cCoreSave_saveSoundOutMode(cCoreSave *self)
{
    if (self->data != 0) {
        self->data->soundOutMode = SdeSystemOutModeGet();
    }
}
