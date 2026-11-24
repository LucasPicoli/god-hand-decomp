/* include/godhand/cOm4f.h - cOm4f, a door-type map object linked to a cOmDoor2.
 *
 * cOm4f derives from cOmBase: its constructor (func_001A42E8) calls the
 * cOmBase constructor (InitFields_1B6E90) first and its initial method
 * (cOm4f_construct) calls cOmBase's (func_001B6FB8). It drives its moves
 * through the base state bytes (base.mode 1 opens, 2 closes), keeps its own
 * open/close state at 0x760..0x763 and a pointer to the partner door at 0x790
 * (set by cOm4f_connectDoor). The sync method drives the partner so both
 * stand open or both stand closed.
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_COM4F_H
#define GODHAND_COM4F_H

#include "godhand/cOmBase.h"

#define COM4F_MODE_OPEN   1             /* base.mode: opening */
#define COM4F_MODE_CLOSE  2             /* base.mode: closing */

typedef struct cOm4f {
    cOmBase base;               /* 0x000 */
    char unk5E0[0x760 - 0x5E0];
    unsigned char active;       /* 0x760 a move is in progress */
    unsigned char open;         /* 0x761 1 when the door stands open */
    unsigned char lock;         /* 0x762 1 while locked */
    unsigned char eventMode;    /* 0x763 */
    char unk764[0x790 - 0x764];
    void *door;                 /* 0x790 partner cOmDoor2, or 0 */
} cOm4f;

typedef char cOm4f_chk_active[((int)&((cOm4f *)0)->active == 0x760) ? 1 : -1];
typedef char cOm4f_chk_door[((int)&((cOm4f *)0)->door == 0x790) ? 1 : -1];

#endif
