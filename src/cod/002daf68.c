/* sn-2.95.3-136 */
#include "godhand/cVec.h"
#include "godhand/fpu.h"

/* Whether spheres of radius ra at a and rb at b overlap. On a hit the centre distance goes to
 * *dist and a to *pos, when given. The root is FPU_SQRT_S: with __builtin_sqrtf cc1 schedules
 * the radius add ahead of it, where retail takes the root first. */
__attribute__((section(".text.func_002DAF68")))
int func_002DAF68(cVec *a, cVec *b, float *dist, cVec *pos, float ra, float rb)
{
    CVEC_TEMPS;
    float len;

    CVEC_SUB(a, b);
    FPU_SQRT_S(len, ret_.x * ret_.x + ret_.y * ret_.y + ret_.z * ret_.z);
    if (len < ra + rb) {
        if (dist != 0) {
            *dist = len;
        }
        if (pos != 0) {
            cVec_copy3(pos, a);
        }
        return 1;
    }
    return 0;
}
