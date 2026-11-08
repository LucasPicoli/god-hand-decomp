/* include/godhand/cFxBurst.h - an effect node released from its holder's frame.
 *
 * While a burst effect is held it has a countdown byte. When the countdown
 * reaches the limit the effect keeps in 0x22E, its position and velocity are
 * moved from the holder's frame into world space and the node is detached.
 *
 * Offsets are exact. A field nobody has named yet stays as unkNN padding.
 */
#ifndef GODHAND_CFXBURST_H
#define GODHAND_CFXBURST_H

#include "godhand/cNode.h"

#define FXBURST_F_WORLD     0x8000      /* flags: position and velocity are already in world space */
#define FXBURST_F_SKIP      0x100000    /* flags: nothing to convert */
#define FXBURST_F_FROZEN    0x40000000  /* flags: the node's own frame stays as it is */
#define FXBURST_VEL_ON      1           /* velFlag value: the velocity is converted too */

typedef struct cFxBurst {
    cNode base;                         /* 0x000 */
    char unkF4[0x103 - 0xF4];
    signed char count;                  /* 0x103 countdown; negative when idle */
    char unk104[0x11C - 0x104];
    int flags;                          /* 0x11C FXBURST_F_* */
    char unk120[4];
    float pos[3];                       /* 0x124 */
    char unk130[4];
    float vel[3];                       /* 0x134 */
    char unk140;
    unsigned char velFlag;              /* 0x141 */
    char unk142[0x22E - 0x142];
    short limit;                        /* 0x22E */
} cFxBurst;

#endif
