/* sn-2.95.3-136 matched TU. */

#include "godhand/cEma2.h"

extern cGameObj *Getplayer(void);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, void *a3, int a4, int a5, int a6, int a7);
extern char D_005FEE00[];
extern unsigned short D_00747A50;
extern float capVu0MagnitudeSqXZ(cVec *a, cVec *b);
extern float Turn_dest(cVec *from, cVec *to, float rot, float limit);

/* 65/73 words exact (89.0%), sn-2.95.3-136 with fp_hazard_rules mtc1, insn delta +3. Shape aligned; retail cross-jumps the mode/phase/step tail of the two no-flag arms (mode constant set in the branch delay slot), this body keeps them apart. A local mode variable made it worse (54/73). */







#define EMA2_HIT_SE        0x96         /* sound played on a hit */
#define EMA2_GAME_MODE     0x501        /* D_00747A50 value in which a hit scales with the player */
#define PLAYER_POWER(p)    (*(float *)((char *)(p) + 0x600))   /* the player record is not typed yet */
#define EMA2_POWER_SCALE   10.0f
#define EMA2_STATE_HIT     1            /* mode while it is alive */
#define EMA2_STATE_DYING   2            /* mode once its hp has run out */

/* Takes one hit: plays the hit sound, lowers hp by 1 (or by the player's
 * power times 10 in game mode 0x501) and sets the state bytes: mode 1 while
 * alive, mode 2 when hp has run out. Phase 1 when the self-hit flag or the
 * motion flag 2 is set, else phase 0. Does nothing once hp is 0 or less. */
__attribute__((section(".text.cEma2_setDamage")))
void cEma2_setDamage(cEma2 *self)
{
    cGameObj *player = Getplayer();

    if (self->base.hp <= 0)
        return;
    cSnd_SeCall_2CBA48(D_005FEE00, 0, EMA2_HIT_SE, self, 0, 0, 0, 0);
    if (D_00747A50 == EMA2_GAME_MODE)
        self->base.hp -= (int)(PLAYER_POWER(player) * EMA2_POWER_SCALE);
    else
        self->base.hp -= 1;
    if (self->base.hp <= 0) {
        if ((self->flags & EMA2_F_SELF_HIT) || (self->base.motionFlags & GAMEOBJ_MOTION_LOOP)) {
            self->base.mode = EMA2_STATE_DYING;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 0;
        } else {
            self->base.mode = EMA2_STATE_DYING;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
    } else {
        if ((self->flags & EMA2_F_SELF_HIT) || (self->base.motionFlags & GAMEOBJ_MOTION_LOOP)) {
            self->base.mode = EMA2_STATE_HIT;
            self->base.phase = 1;
            self->base.step = 0;
            self->base.stepArg = 1;
        } else {
            self->base.mode = EMA2_STATE_HIT;
            self->base.phase = 0;
            self->base.step = 0;
            self->base.stepArg = 0;
        }
    }
}

#define EM_TURN_NEAR_SQ   (1.8f * 1.8f) /* nearer than this (squared): nothing is set */
#define EM_TURN_FAR_SQ    25.0f         /* farther than this: nothing is set */
#define EM_TURN_SIDE      0.7853982f    /* a quarter turn: below it the target is ahead */
#define EM_TURN_BEHIND    2.3561945f    /* three quarters: above it the target is behind */
#define EM_TURN_FLAG      2

/* Notes where pos lies around the player's heading. Between 1.8 and 5 units
 * away, it sets turnBehind when pos is more than 135 degrees off the heading,
 * and turnPlus or turnMinus for a side more than 45 degrees off. */
__attribute__((section(".text.func_00292F70")))
void func_00292F70(cEmManage *self, cVec *pos)
{
    cVec *playerPos;
    float dist;
    float turn;
    float amount;
    float side;
    float *sideCopy;

    dist = capVu0MagnitudeSqXZ(Getplayer()->pos, pos);
    if (dist < EM_TURN_NEAR_SQ)
        return;
    if (EM_TURN_FAR_SQ < dist)
        return;
    playerPos = Getplayer()->pos;
    turn = Turn_dest(playerPos, pos, Getplayer()->rot[1], 3.1415927f);
    sideCopy = &side;   /* a second name for side keeps the two float copies in retail order */
    amount = turn;
    side = turn;
    if (turn < 0.0f)
        amount = -turn;
    if (amount < EM_TURN_SIDE)
        return;
    if (EM_TURN_BEHIND < amount) {
        self->turnBehind = EM_TURN_FLAG;
        return;
    }
    if (0.0f < *sideCopy)
        self->turnPlus = EM_TURN_FLAG;
    else
        self->turnMinus = EM_TURN_FLAG;
}
