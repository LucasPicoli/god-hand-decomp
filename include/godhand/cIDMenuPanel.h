/* include/godhand/cIDMenuPanel.h - the three-answer menu panel built on cIDBase.
 *
 * func_001680D8 runs the fade and the marks, func_001682C8 moves the choice with
 * the pad. Field names are ours, taken from those steps and the options panels.
 */
#ifndef GODHAND_CIDMENUPANEL_H
#define GODHAND_CIDMENUPANEL_H

#include "godhand/cIDBase.h"

/* The head every menu panel on cIDBase shares: the options panels in 00166bb8.c and
 * 00167908.c and the panel in 0016ae38.c start with it too. Each panel runs its own
 * steps on state, and result is the code its owner reads (7, 10, 11, 13, -1 once closed). */
typedef struct cIDPanelHead {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x5A - 0x48];
    signed char state;                  /* 0x5A */
    char unk5B[0x60 - 0x5B];
    int result;                         /* 0x60 */
} cIDPanelHead;                         /* 0x64 */

/* A menu panel built on cIDBase: it fades in, lets the pad pick an answer (-1, 0 or 1)
 * and fades out. head.state: 0 fade in, 1 shown, 2 fade out. head.result: 7 once an
 * answer is decided, -1 when the panel has faded out. */
typedef struct cIDMenuPanel {
    cIDPanelHead head;                  /* 0x00 */
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
