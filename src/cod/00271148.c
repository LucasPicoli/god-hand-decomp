/* sn-2.95.3-136 matched TU. */
#include "godhand/cEm00.h"
#include "godhand/pl00.h"
#include "godhand/player.h"
#include "godhand/cCamera.h"
#include "godhand/cActionButton.h"

/* Magnitude of x. */
static inline float absf(float x)
{
    float r;

    if (x < 0.0f) {
        r = -x;
    } else {
        r = x;
    }
    return r;
}

/* Sets the player's action button on the enemy (func_002DC5E0 for enemy
 * 0x20F, func_002DC260 otherwise) when it stands behind the player: the
 * player is not flashing from a hit, has no object at sub6A0, would turn at
 * least 100 degrees to face the enemy, the two heights differ by at most half
 * a unit, and the enemy's playerDist is under 4.0. */
__attribute__((section(".text.func_00271148")))
void func_00271148(cEm00 *self)
{
    pl00 *player = (pl00 *)Getplayer();
    cVec *from;
    float turn;
    float dy;

    if (0.0f < player->base.hitFlash) {
        return;
    }
    if (player->sub6A0 != 0) {
        return;
    }
    from = Getplayer()->pos;
    turn = Turn_dest(&from->x, Getplayer()->rot.y, &self->pos->x, 3.1415927f);
    turn = absf(turn);
    if (turn < 1.7453293f) {
        return;
    }
    dy = player->base.pos->y - self->pos->y;
    dy = absf(dy);
    if (0.5f < dy) {
        return;
    }
    if (self->playerDist < 4.0f) {
        if (self->emNo != 0x20F) {
            func_002DC260(self);
        } else {
            func_002DC5E0(self);
        }
    }
}
