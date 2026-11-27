/* sn-2.95.3-136 matched TU. */

#include "godhand/cEm00.h"
#include "godhand/cVec.h"
#include "godhand/fpu.h"
#include "godhand/capVu0.h"

extern char D_005864F0[];

extern void cEm00_setGoto(void *self, void *pos, int a2, int a3, float f);

/* Pick what an idle enemy does when it is out of reach of the player and not mid-attack: certain enemy numbers
 * start the phase 0x6D motion at once, some refuse, and the rest walk to a point 10 units from the player.
 * Both arms that return 1 write their own tail; jump2 cross-jumps the common li/sb/sb run
 * into the one shared tail retail has (a goto to a shared label schedules it differently). */
__attribute__((section(".text.cEm00_startIdleApproach")))
int cEm00_startIdleApproach(cEm00 *self)
{
    cVec v;
    cVec dir;
    cVec goal;
    CVEC_TEMPS;
    cVec *g;
    float mag;
    float scale;
    cVec *pt;

    if (func_00291FD8(D_005864F0) == 0) {
        return 0;
    }
    if (0.0f < *(float *)((char *)self + 0x16C0)) {
        return 0;
    }
    g = (cVec *)(D_005864F0 + 0x520);
    CVEC_COPY(v, g);
    mag = capVu0MagnitudeSqXZ(&v, self->pos);
    if (25.0f < mag) {
        return 0;
    }
    switch (self->emNo) {
    case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E:
    case 0x218:
    case 0x245: case 0x246: case 0x247:
    case 0x24F: case 0x250: case 0x251:
    case 0x278: case 0x279:
        self->stepArg = 0;
        self->mode = 0;
        self->step = 0;
        self->phase = 0x6D;
        return 1;
    case 0x220: case 0x221: case 0x222: case 0x223:
    case 0x26A:
        return 0;
    default:
        break;
    }
    CVEC_ZERO(dir);
    CVEC_ZERO(goal);
    if (mag == 0.0f) {
        dir.x = 0.0f;
        dir.y = 0.0f;
        dir.z = 1.0f;
        mag = 1.0f;
        pt = &tmp_;
    } else {
        CVEC_SUB(self->pos, &v);
        dir.x = ret_.x;
        dir.z = ret_.z;
        dir.y = 0.0f;
        FPU_SQRT_S(mag, mag);
        pt = &tmp_;
    }
    scale = 10.0f / mag;
    dir.x = dir.x * scale;
    dir.z = dir.z * scale;
    {
        /* operator+: both operands are bound before the result is built */
        cVec *a_ = &dir;
        cVec *b_ = self->pos;

        CVEC_COPY(tmp_, a_);
        CVEC_ADD_TO(tmp_, b_);
    }
    CVEC_COPY(ret_, pt);
    goal.x = ret_.x;
    goal.y = ret_.y;
    goal.z = ret_.z;
    cEm00_setGoto(self, &goal, 7, 0, 60.0f);
    self->stepArg = 1;
    self->phase = 0x13;
    self->step = 0;
    self->mode = 0;
    return 1;
}
