#include "godhand/cDamageGive.h"

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned int D_00747B10;

__attribute__((section(".text.Rnd")))
int Rnd(void)
{
    unsigned int v0 = (unsigned short)D_00747B10 * 5;
    v0 = ((v0 & 0xFF) << 8) + ((v0 & 0xFF00) >> 8);
    D_00747B10 = v0;
    return (unsigned char)D_00747B10;
}

/* Take x, y and z of the vector as the push direction. */
__attribute__((section(".text.cDamageGive_SetDmgGiveHitVec")))
void cDamageGive_SetDmgGiveHitVec(cDamageGive *self, cVec *dir)
{
    cVec_copy3(&self->hitVec, dir);
}
