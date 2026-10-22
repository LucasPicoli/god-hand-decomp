/* include/godhand/reachObj.h - objects the player can reach, and the player's two reach slots.
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_REACHOBJ_H
#define GODHAND_REACHOBJ_H

#include "godhand/cCamera.h"
#include "godhand/cCamManager.h"

/* The reach data of an object: two volumes, the reach radius and the slot indices. */
typedef struct ReachVol {
    char pad0[0x13C];
    float a[4];                         /* 0x13C */
    float b[4];                         /* 0x14C */
    float reach;                        /* 0x15C */
    char pad160[0x18C - 0x160];
    signed char idxA;                   /* 0x18C */
    signed char idxB;                   /* 0x18D */
} ReachVol;

typedef struct ReachObj {
    char pad0[0x110];
    ReachVol *vol;                      /* 0x110 */
    char pad114[0x2B0 - 0x114];
    short idxA;                         /* 0x2B0 */
    short idxB;                         /* 0x2B2 */
    char pad2B4[4];
    float reach;                        /* 0x2B8 */
} ReachObj;

extern int ReachObj_isWithinReach(ReachObj *o);

#endif /* GODHAND_REACHOBJ_H */
