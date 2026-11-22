/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"
#include "godhand/cCamera.h"

extern cGameObj *Getplayer(void);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);

#define NEAR_SQ   0.5f        /* closer than this (squared): counts as in front */
#define FAR_SQ    2.0f        /* farther than this: not in front */
#define FRONT_ARC 0.5235988f  /* heading difference below this counts as in front */

/* Nonzero when the player faces self: closer than NEAR_SQ (squared distance),
 * or within FAR_SQ and turned less than 30 degrees away from self. */
__attribute__((section(".text.cGameObj_isFacedByPlayer")))
int cGameObj_isFacedByPlayer(cGameObj *self)
{
    cGameObj *player = Getplayer();
    float dist = capVu0MagnitudeSqXZ(player->pos, self->pos);
    float a;
    float t;

    if (dist < NEAR_SQ) {
        return 1;
    }
    if (FAR_SQ < dist) {
        return 0;
    }
    a = Turn_dest(&player->pos->x, player->rot.y, &self->pos->x, 3.1415927f);
    if (a < 0.0f) {
        t = -a;
    } else {
        t = a;
    }
    a = t;
    return a < FRONT_ARC;
}
