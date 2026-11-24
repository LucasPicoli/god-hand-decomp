/* include/godhand/rollObj.h - the rolling object: a cOmBase that is thrown,
 * lands and rolls to a stop. func_001B0980 starts it, func_001B0540 moves it
 * and HitPhaseObj_tickPhase runs its phases. RollObj is our name; retail's
 * class name isn't known. Only the fields func_001B0540 and
 * HitPhaseObj_tickPhase use are named; its real size is unknown, since
 * nothing in C allocates one. */
#ifndef GODHAND_ROLLOBJ_H
#define GODHAND_ROLLOBJ_H

#include "godhand/cOmBase.h"
#include "godhand/cDamageUnit.h"

typedef struct RollObj {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0x20];
    cDamageUnit *damage;                /* 0x600 damage unit, 0 if none */
    char unk604[0xC];
    cVec vel;                           /* 0x610 */
    char unk620[2];
    short smokeWait;                    /* 0x622 frames to the next dust puff */
    unsigned char falling;              /* 0x624 thrown, not yet landed */
    unsigned char rolling;              /* 0x625 */
} RollObj;

typedef char RollObj_rolling_check[((int)&((RollObj *)0)->rolling == 0x625) ? 1 : -1];
typedef char RollObj_size_check[(sizeof(RollObj) == 0x628) ? 1 : -1];

/* Move the object by its velocity until it stops rolling: friction, gravity,
 * wall and floor contact, the landing sounds, and a dust puff every 11 frames
 * while it rolls on the ground. */
void func_001B0540(RollObj *self);

#endif
