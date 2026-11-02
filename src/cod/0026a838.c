/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cOm60.h"
#include "godhand/capVu0.h"
#include "godhand/cVec.h"
#include "godhand/fpu.h"
#include "godhand/rand.h"

#define THROW_NEAR_DIST    3.0f         /* the forward push starts past this distance */
#define THROW_DIST_SCALE   0.02f        /* forward push per unit of distance past it */
#define THROW_FWD_MIN      0.05f
#define THROW_UP_AIM       0.3f

/* Lets go of held object no and throws it forward, faster the farther away the player is. */
__attribute__((section(".text.func_0026A838")))
void func_0026A838(cEm00 *self, int no)
{
    cVec dir;
    cOm60 *obj;
    float side;
    float up;
    float fwd;
    float dist;

    CVEC_ZERO(dir);
    obj = self->held[no];
    if (obj != 0) {
        self->held[no] = 0;
        FPU_SQRT_S(dist, self->playerDist);
        fwd = (dist - THROW_NEAR_DIST) * THROW_DIST_SCALE;
        if (fwd < THROW_FWD_MIN) {
            fwd = THROW_FWD_MIN;
        }
        side = fRand1_1() * THROW_SIDE;
        up = fRand1_1() * THROW_UP_RAND + THROW_UP_AIM;
        dir.x = side;
        dir.y = up;
        dir.z = fwd;
        capVu0ApplyMatrixXYZ(&dir, self->mtx, &dir);
        cOm60_setThrow(obj, &dir, THROW_FAST);
    }
}
