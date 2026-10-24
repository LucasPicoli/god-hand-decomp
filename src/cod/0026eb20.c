/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/vu0.h"
#include "godhand/sceVu0.h"

#define EM_MOVE_GROUNDED 0x08    /* moveFlags: standing on the ground */
#define PITCH_PROBE      0.25f   /* how far ahead and behind the ground is probed */
#define PITCH_KEEP       0.9f
#define PITCH_GAIN       0.1f
#define PITCH_MIN        0.01f   /* smaller pitches snap to 0 */

extern float Pos_probeGroundBelow(cVec *pos);
extern float capVu0MagnitudeXZ(void *a0, void *a1);
extern float capVu0Atan2(float y, float x);

/* Tilt the body to the slope of the ground under the front and the back of it. */
__attribute__((section(".text.func_0026EB20")))
void func_0026EB20(cEm00 *self)
{
    float slope;
    float p;
    float a;

    if (self->moveFlags & EM_MOVE_GROUNDED) {
        cVec front;
        cVec back;
        float dy;

        VU0_SQC2_VF0_MEM(&front, 0);
        VU0_SQC2_VF0_MEM(&back, 0);
        front.x = 0.0f;
        front.y = 0.0f;
        front.z = PITCH_PROBE;
        cVec_applyMatrix(&front, self->mtx);
        front.y = Pos_probeGroundBelow(&front);
        back.x = 0.0f;
        back.y = 0.0f;
        back.z = -PITCH_PROBE;
        cVec_applyMatrix(&back, self->mtx);
        back.y = Pos_probeGroundBelow(&back);
        dy = front.y - back.y;
        slope = -capVu0Atan2(dy, capVu0MagnitudeXZ(&front, &back));
    } else {
        slope = 0.0f;
    }
    p = self->pitch * PITCH_KEEP * (slope * PITCH_GAIN);
    self->pitch = p;
    a = p < 0.0f ? -p : p;
    if (a < PITCH_MIN) {
        self->pitch = 0.0f;
    } else {
        self->rot.x = p;
    }
}
