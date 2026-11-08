/* include/godhand/cPushPair.h - the records of a pair push-apart test. A
 * pusher record names a game object and says how it yields: kind 0 never
 * moves, otherwise a weight (0..1) scales how far it is pushed when the other
 * record has a different kind. Offsets are exact; fields nobody has named stay
 * as unkNN padding.
 */
#ifndef GODHAND_CPUSHPAIR_H
#define GODHAND_CPUSHPAIR_H

#include "godhand/cGameObj.h"

typedef struct cPushRec {
    cGameObj *obj;                      /* 0x00 the object that moves */
    int unk04;
    int kind;                           /* 0x08 0: never pushed */
    float weight;                       /* 0x0C share of the overlap taken when the kinds are equal */
} cPushRec;

/* The round shape that is tested: a centre and a radius. */
typedef struct cPushShape {
    char unk00[0x60];
    cVec centre;                        /* 0x60 */
    float radius;                       /* 0x70 */
} cPushShape;

typedef char cPushShape_chk_radius[((int)&((cPushShape *)0)->radius == 0x70) ? 1 : -1];

#endif
