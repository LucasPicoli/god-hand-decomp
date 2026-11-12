/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"

extern cGameObj *Getplayer(void);
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
/* Turn_dest is (from, to, cur, max) in src/cod/002da038.c. Declared with the floats
 * first, as src/cod/002dcd50.c does: the registers are the same and only this
 * order puts the f12 load ahead of the a1 load, as retail has it. */
extern float Turn_dest(cVec *from, float rot, float limit, cVec *to);

#define NEAR_SQ   0.5f        /* closer than this (squared): counts as in front */
#define FAR_SQ    2.0f        /* farther than this: not in front */
#define FRONT_ARC 0.5235988f  /* heading difference below this counts as in front */

/* Nonzero when the player faces self: closer than NEAR_SQ (squared distance),
 * or within FAR_SQ and turned less than 30 degrees away from self. */
__attribute__((section(".text.func_001C26B8")))
int func_001C26B8(cGameObj *self)
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
    a = Turn_dest(player->pos, player->rot.y, 3.1415927f, self->pos);
    if (a < 0.0f) {
        t = -a;
    } else {
        t = a;
    }
    a = t;
    return a < FRONT_ARC;
}
