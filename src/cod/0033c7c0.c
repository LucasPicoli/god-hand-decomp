/* cygnus-2.96 matched TU. */
#include "godhand/criStm.h"

/* Forget the ADX AINF chunk: clear its data and restore the default volume and pan offsets. */
__attribute__((section(".text.AsyncCall_clearAinf")))
void AsyncCall_clearAinf(AsyncCall *self)
{
    self->ainfSize = 0;
    self->volumeOffset = 0;
    self->panOffset[0] = AINF_PAN_DEFAULT;
    self->panOffset[1] = AINF_PAN_DEFAULT;
    func_003A52F0(self->ainfData, 0, sizeof(self->ainfData));
}
