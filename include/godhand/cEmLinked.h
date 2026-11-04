/* include/godhand/cEmLinked.h - an enemy that can be pushed along by a linked object. */
#ifndef GODHAND_CEMLINKED_H
#define GODHAND_CEMLINKED_H

#include "godhand/cEm00.h"
#include "godhand/cGameObj.h"

#define EMLINK_MODE_FREE  0x100         /* no usable link */
#define EMLINK_MODE_HELD  0x500         /* pushed along by the link */

typedef struct cEmLinked {
    cEm00 base;                         /* 0x0000 */
    char unk1870[0x2130 - 0x1870];
    char work[0x5C];                    /* 0x2130 step work */
    int mode;                           /* 0x218C EMLINK_MODE_* */
    cVec push;                          /* 0x2190 */
    char unk21A0[0x10];
    cGameObj *link;                     /* 0x21B0 */
} cEmLinked;

/* Runs the push step: the step work and the model it moves. */
void func_00104010(void *self, void *work, void *model);

#endif
