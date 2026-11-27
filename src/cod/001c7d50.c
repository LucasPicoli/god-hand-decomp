/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136, fp_hazard_rules mtc1 */
#include "godhand/cOmSub.h"

#define COMSUB_F_VIBRATE  0x08          /* unk03 bit: the record shakes its object */

/* cOmSub with the vibration fields after the end pair (cOmSub_fields.h in the lane notes). */
typedef struct cOmSubVib {
    cOmSub base;                        /* 0x000 */
    float vibFrames;                    /* 0x140 */
    float vibPeriod;                    /* 0x144 */
    float vibX;                         /* 0x148 amplitude per axis */
    float vibY;                         /* 0x14C */
    float vibZ;                         /* 0x150 */
} cOmSubVib;

/* Start a shake: frames and period, then the amplitude on each axis. */
__attribute__((section(".text.cOmSub_setVibration")))
void cOmSub_setVibration(cOmSubVib *self, int frames, int period, float x, float y, float z)
{
    self->base.unk03 |= COMSUB_F_VIBRATE;
    /* both barriers keep retail's order: flag, frames, then the int-to-float of period; without either the stores interleave */
    do {
    } while (0);
    self->vibFrames = frames;
    do {
    } while (0);
    self->vibPeriod = period;
    self->vibX = x;
    self->vibY = y;
    self->vibZ = z;
}
