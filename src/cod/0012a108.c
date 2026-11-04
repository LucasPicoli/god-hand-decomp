/* sn-2.95.3-136 */
#include "godhand/cEm00.h"
#include "godhand/cEmManage.h"
#include "godhand/sceVu0.h"
#include "godhand/cVec.h"
#include "godhand/mtx.h"
#include "godhand/cActionButton.h"

#define BOMB_NUM        2
#define BOX_HALF_X      1.0f            /* the box, in the enemy's own frame */
#define BOX_HALF_Y      0.5f
#define BOX_NEAR_Z      (-0.8f)
#define BOX_FAR_Z       3.0f

/* If one of the two bombs is burning inside the box in front of
 * enemy self (x and y within 1 and 0.5, z from -0.8 to 3, in the enemy's
 * own frame), offer the player's action button through func_002DBB08.
 * Retail hoists all six box bounds into $f20..$f25 before the loop, which
 * takes -fmove-all-movables (without it only -1, 1 and -0.8 are hoisted). */
__attribute__((section(".text.func_0012A108")))
void func_0012A108(cEm00 *self)
{
    cVec loc;
    float inv[16];
    CVEC_TEMPS;
    unsigned int i;
    cOmbb *bomb;

    if (self->unk6A0 != 0) {
        return;
    }
    for (i = 0; i < BOMB_NUM; i++) {
        bomb = func_002948C8(&D_005864F0, i);
        if (bomb == 0) {
            continue;
        }
        if (cOmbb_ckFire(bomb) == 0) {
            continue;
        }
        CVEC_ZERO(loc);
        MtxInverse(inv, self->mtx);
        CVEC_SET_APPLY(loc, inv, func_001B8720(bomb));
        if (loc.x < -BOX_HALF_X || BOX_HALF_X < loc.x) {
            continue;
        }
        if (loc.z < BOX_NEAR_Z || BOX_FAR_Z < loc.z) {
            continue;
        }
        if (loc.y < -BOX_HALF_Y || BOX_HALF_Y < loc.y) {
            continue;
        }
        func_002DBB08();
        return;
    }
}
