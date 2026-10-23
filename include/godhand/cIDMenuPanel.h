/* include/godhand/cIDMenuPanel.h - the three-answer menu panel built on cIDBase.
 *
 * func_001680D8 runs the fade and the marks, func_001682C8 moves the choice with
 * the pad. Field names are ours, taken from those two steps.
 */
#ifndef GODHAND_CIDMENUPANEL_H
#define GODHAND_CIDMENUPANEL_H

#include "godhand/cIDBase.h"

/* A menu panel built on cIDBase: it fades in, lets the pad pick an answer (-1, 0 or 1)
 * and fades out. */
typedef struct cIDMenuPanel {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x5A - 0x48];
    signed char state;                  /* 0x5A 0 fade in, 1 shown, 2 fade out */
    char unk5B[0x60 - 0x5B];
    int result;                         /* 0x60 7 once an answer is decided, -1 when the panel has faded out */
    unsigned char reopen;               /* 0x64 1 sends a fading panel back to fade in */
    char unk65[0x80 - 0x65];
    cIDBaseEnt *frame;                  /* 0x80 its alpha follows the fade */
    cIDBaseEnt *backMark;               /* 0x84 shown while the answer is -1 */
    cIDBaseEnt *cursor;                 /* 0x88 shown on answer 0 or 1 */
    char unk8C[0x90 - 0x8C];
    unsigned char alpha;                /* 0x90 */
    signed char choice;                 /* 0x91 -1, 0 or 1 */
} cIDMenuPanel;

#endif
