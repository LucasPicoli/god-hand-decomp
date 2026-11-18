/* include/godhand/cOl40.h - the breakable six-sided object.
 *
 * AllocInitObj183848_317CE0 allocates and clears 0x1CC0 bytes and constructs
 * them with func_00183848, which clears twenty 0x60-byte blocks from 0x670 up
 * to 0xDF0 and the two shake vectors. A hit shakes the object: func_00186598 sets the shake amplitudes from the
 * hit strength, func_00186398 applies them to part 5 and lets them decay.
 * Names are ours. Offsets are exact.
 */
#ifndef GODHAND_COL40_H
#define GODHAND_COL40_H

#include "godhand/cOmBase.h"

typedef struct cOl40 {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0xDF0 - 0x5E0];
    cVec shakePos;                      /* 0xDF0 rest position of the shaken part */
    cVec shakeRot;                      /* 0xE00 rest rotation of the shaken part */
    float shakeY;                       /* 0xE10 height amplitude */
    float shakeRotX;                    /* 0xE14 x rotation amplitude */
    float shakeRotZ;                    /* 0xE18 z rotation amplitude */
    float shakePhase;                   /* 0xE1C 0 or pi at the hit, steps by pi/4 */
    char unkE20[0x1CC0 - 0xE20];
} cOl40;

typedef char cOl40_size_check[(sizeof(cOl40) == 0x1CC0) ? 1 : -1];

/* The part the shake moves. */
#define OL40_SHAKE_PART 5

/* Shake part 5 and let the amplitudes decay. */
void func_00186398(cOl40 *self);

#endif /* GODHAND_COL40_H */
