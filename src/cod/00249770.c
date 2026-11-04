/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cCamera.h"
#include "godhand/sceVu0.h"
#include "godhand/vu0.h"
#include "godhand/capVu0.h"
#include "godhand/mtx.h"

#define ORBIT_RADIUS     26.0f
#define ORBIT_TURN_STEP  0.012271847f
#define ORBIT_HALF_TURN  3.1415927f     /* pi: from the orbit angle to the heading that faces the anchor */

/* The frame: the rotation, the orbit point, the offset from the anchor and its work copy. */
typedef struct OrbitFrame {
    float mtx[16];
    cVec at;
    cVec diff;
    cVec work;
} OrbitFrame;

#define ORBITFRAME_OFFSET(field) ((int)&((OrbitFrame *)0)->field)

/* Moves the object around the anchor point by angle on a fixed radius and turns it
 * a step toward facing the anchor. */
__attribute__((section(".text.func_00249770")))
void func_00249770(cEm00 *self, float angle)
{
    OrbitFrame f;

    VU0_SQC2_VF0_MEM(&f.at, 0);
    VU0_ZERO_VSUB_XYZ_TO(&f.work, 0, self->pos, &D_005850B0);
    VU0_LQC2(4, &f.work, 0);
    VU0_SQC2(4, &f, ORBITFRAME_OFFSET(diff));
    f.at.x = f.diff.x;
    f.at.y = f.diff.y;
    f.at.z = f.diff.z;
    angle = Adjust_theta(capVu0Atan2(f.diff.x, f.diff.z) + angle);
    MtxInitRotY(f.mtx, angle);
    f.at.x = 0.0f;
    f.at.y = 0.0f;
    f.at.z = ORBIT_RADIUS;
    cVec_applyMatrix(&f.at, f.mtx);
    VU0_VADD_XYZ_IP(&f.at, 0, &D_005850B0);
    self->pos->x = f.at.x;
    self->pos->z = f.at.z;
    self->rot.y += Turn_dest_dir(self->rot.y, Adjust_theta(angle + ORBIT_HALF_TURN),
                                  self->speedRate * ORBIT_TURN_STEP);
    self->rot.y = Adjust_theta(self->rot.y);
}
