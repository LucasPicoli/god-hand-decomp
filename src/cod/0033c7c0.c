/* cygnus-2.96 matched TU. */
#include "godhand/criStm.h"

/* Forget the ADX AINF chunk: clear its data and restore the default volume and pan offsets. */
__attribute__((section(".text.adxb_ResetAinf")))
void adxb_ResetAinf(ADX_BASIC *self)
{
    self->ainfLen = 0;
    self->defOutVol = 0;
    self->defPan[0] = AINF_PAN_DEFAULT;
    self->defPan[1] = AINF_PAN_DEFAULT;
    func_003A52F0(self->ainf, 0, sizeof(self->ainf));
}
