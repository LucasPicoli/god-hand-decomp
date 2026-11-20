/* include/godhand/cSubScrOption.h - the options screen of the pause menu.
 *
 * cSubScrOptionT (retail class 14cSubScrOptionT, id resource
 * "idsubscroptionT") is the smaller variant of cSubScrOption: an id display
 * object (cIDObj head) with a second display (sub) at 0xC0. obj.state is
 * the panel mode: 0 picks a row, 1 fades over to the second display, 2
 * shows it, 3 fades back.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact.
 */
#ifndef GODHAND_CSUBSCROPTION_H
#define GODHAND_CSUBSCROPTION_H

#include "godhand/cIDObj.h"

#define SUBSCR_OPTIONT_ENT_NUM  0x10    /* entries of the variant's main display */

typedef struct cSubScrOptionT {
    cIDObj obj;                                     /* 0x000 */
    char unk74[0x80 - sizeof(cIDObj)];
    cIDBaseEnt *ent[SUBSCR_OPTIONT_ENT_NUM];        /* 0x080 */
    cIDBaseObj sub;                                 /* 0x0C0 second display */
    char unk108[0x110 - 0x108];
    signed char row;                                /* 0x110 row under the cursor */
} cSubScrOptionT;

typedef char cSubScrOptionT_sub_check[(int)&((cSubScrOptionT *)0)->sub == 0xC0 ? 1 : -1];
typedef char cSubScrOptionT_row_check[(int)&((cSubScrOptionT *)0)->row == 0x110 ? 1 : -1];

/* Hide every entry of the variant's main display. */
void SetFlagOnChildren_167EE8(cSubScrOptionT *self);

/* Step of cSubScrOptionT's fade to and from the second display; the byte
 * before it (D_003BD9E8) is cSubScrOption's. */
extern unsigned char D_003BD9E9;

#endif
