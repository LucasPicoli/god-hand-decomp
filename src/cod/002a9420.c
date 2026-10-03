#include "godhand/cGameObj.h"

/* cGameObj_setRot — copies 3 rotation floats from a1 to a0+0x100 unless a1
 * already points there. Compiled with sn-2.95.3-136 (cygnus schedules the
 * stores differently). */

/* Copies the three rotation floats from rot into the object, unless rot is the
 * object's own array. */
__attribute__((section(".text.cGameObj_setRot")))
void cGameObj_setRot(cGameObj *self, float *rot) {
    float *dst = self->rot;
    if (dst != rot) {
        dst[0] = rot[0];
        dst[1] = rot[1];
        dst[2] = rot[2];
    }
}
