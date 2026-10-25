/* include/godhand/cFxTrail.h - cFxTrail, an effect node that draws a ribbon behind a moving point (sn code at 0x2EBF98).
 *
 * A trail keeps one point per segment (up to 0x78, 16 by default) and two
 * arrays of 0x40-byte segment records that carry the ribbon's width and
 * end weights. The setup fills every segment with the start point and a
 * width that fades along the trail, and picks the ribbon's two end weights
 * from the direction flags.
 *
 * Field names are ours; offsets are exact. The object size is not known.
 */
#ifndef GODHAND_CFXTRAIL_H
#define GODHAND_CFXTRAIL_H

#include "godhand/cNode.h"

#define FXTRAIL_SEG_MAX      0x78
#define FXTRAIL_SEG_DEF      0x10
#define FXTRAIL_FLIP_A       0x10000000   /* flags: first end weight is -1 */
#define FXTRAIL_FLIP_B       0x08000000   /* flags: second end weight is +1 */
#define FXTRAIL_LIFE_SET     0x2          /* flags2: the trail has a fixed life */

/* The shared trail parameters, seen from the trail node. */
typedef struct FxTrailParam {
    char unk00[0x18C];
    unsigned char life;                 /* 0x18C */
    unsigned char segNum;               /* 0x18D */
    signed char fixedLife;              /* 0x18E */
} FxTrailParam;

/* One segment record. */
typedef struct FxTrailSeg {
    char unk00[0x60];
    long k60;                           /* 0x60 */
    long k68;                           /* 0x68 */
    char unk70[0x30];
    int a0;                             /* 0xA0 */
    float fade;                         /* 0xA4 width fade of this segment */
    long k0A8;                          /* 0xA8 */
    char unkB0[0x10];
    float end0;                           /* 0xC0 end weight */
    float end1;                           /* 0xC4 */
    long kC8;                           /* 0xC8 */
    char unkD0[0x10];
} FxTrailSeg;                           /* 0x40 apart, see segStride */

typedef struct cFxTrail {
    cNode base;                         /* 0x000 */
    char unkF4[0x1C];
    FxTrailParam *param;                /* 0x110 */
    char unk114[8];
    unsigned int flags;                 /* 0x11C */
    char unk120[0x129];
    signed char segNum;                 /* 0x249 */
    char unk24A[0x72];
    cVec *pts;                          /* 0x2BC one point per segment */
    char unk2C0[4];
    char *segA;                         /* 0x2C4 first segment array, 0x40 apart */
    char *segB;                         /* 0x2C8 second segment array */
    char unk2CC[8];
    float width;                        /* 0x2D4 */
    char unk2D8[8];
    unsigned int flags2;                /* 0x2E0 */
    int life;                           /* 0x2E4 */
} cFxTrail;

typedef char cFxTrail_chk_pts[((int)&((cFxTrail *)0)->pts == 0x2BC) ? 1 : -1];
typedef char cFxTrail_chk_flags[((int)&((cFxTrail *)0)->flags == 0x11C) ? 1 : -1];

#endif
