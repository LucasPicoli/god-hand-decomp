/* include/godhand/cSescr.h - a positioned sound-effect script (cSescr).
 *
 * A cSescr plays one sound effect at a place in the world and keeps its
 * pan and volume in step with the listener. The object holds a small state
 * machine (state), a run flag byte, the sound parameters at 0x20 and two
 * vectors: the source position and a work vector. At_ck turns the
 * listener position into a volume/pan value for the source, using one of
 * four callee routines picked by the source kind.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_CSESCR_H
#define GODHAND_CSESCR_H

#include "godhand/cOmBase.h"

#define CSESCR_RUN_ACTIVE   0x02    /* flags: the sound is being played */

/* How the source position is turned into a listener-relative value. */
#define CSESCR_KIND_POINT   0
#define CSESCR_KIND_AREA    1
#define CSESCR_KIND_NEAR    2
#define CSESCR_KIND_FAR     3

/* The sound parameters at 0x20 of the object. */
typedef struct cSescrParam {
    char unk00[4];
    unsigned short radius;              /* 0x04 */
    unsigned short radius2;             /* 0x06 */
    char unk08[2];
    unsigned short delay;               /* 0x0A */
    unsigned short seId;                /* 0x0C */
    short seVol;                        /* 0x0E */
} cSescrParam;                          /* 0x10 */

typedef struct cSescr {
    char unk00[0xC];
    unsigned char flags;                /* 0x0C */
    unsigned char kind;                 /* 0x0D CSESCR_KIND_* */
    char unk0E[2];
    short level;                        /* 0x10 result of At_ck */
    char unk12;
    unsigned char state;                /* 0x13 */
    int handle;                         /* 0x14 playing sound handle */
    char unk18[8];
    cSescrParam param;                  /* 0x20 */
    cVec pos;                           /* 0x30 source position */
    cVec work;                          /* 0x40 work vector */
} cSescr;                               /* 0x50 */

#endif
