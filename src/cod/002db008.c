/* sn-2.95.3-136 matched TU. */
#include "godhand/cVec.h"
#include "godhand/fpu.h"

/* Whether a cylinder of radius ra at a overlaps one of radius rb at b: their heights differ
 * by at most h + rb and their ground-plane distance is under ra + rb. On a hit the
 * ground-plane distance goes to *dist and a to *pos, when given. */
__attribute__((section(".text.func_002DB008")))
int func_002DB008(cVec *a, cVec *b, float *dist, cVec *pos, float ra, float h, float rb)
{
    CVEC_TEMPS;
    float len;

    CVEC_SUB(a, b);
    if (ret_.y < -(h + rb))
        return 0;
    if (h + rb < ret_.y)
        return 0;
    FPU_SQRT_S(len, ret_.x * ret_.x + ret_.z * ret_.z);
    if (len < ra + rb) {
        if (dist != 0)
            *dist = len;
        if (pos != 0)
            cVec_copy3(pos, a);
        return 1;
    }
    return 0;
}
