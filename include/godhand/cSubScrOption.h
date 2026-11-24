/* include/godhand/cSubScrOption.h - the options screen of the pause menu
 * (retail class 13cSubScrOption, id resource "idsubscroption").
 *
 * An id display object (cIDObj head) with a second display (sub) that row 0
 * opens over the panel. obj.state is the panel mode: 0 picks a row, 1 fades
 * over to the second display, 2 shows it, 3 fades back, 4 asks yes/no.
 * cSubScrOptionT (retail class 14cSubScrOptionT, id resource
 * "idsubscroptionT") is the smaller variant, with its second display at 0xC0.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact.
 */
#ifndef GODHAND_CSUBSCROPTION_H
#define GODHAND_CSUBSCROPTION_H

#include "godhand/cIDObj.h"

#define SUBSCR_OPTION_ENT_NUM   0x18    /* entries of the main display */
#define SUBSCR_OPTION_ROW_NUM   8       /* rows of the main display */

typedef struct cSubScrOption {
    cIDObj obj;                                     /* 0x000 */
    char unk74[0x80 - sizeof(cIDObj)];
    cIDBaseEnt *ent[SUBSCR_OPTION_ENT_NUM];         /* 0x080 */
    cIDBaseObj sub;                                 /* 0x0E0 second display */
    char unk128[0x130 - 0x128];
    signed char row;                                /* 0x130 row under the cursor */
    signed char answer;                             /* 0x131 0 = yes, 1 = no */
    char unk132[0x140 - 0x132];
} cSubScrOption;                                    /* 0x140 */

typedef char cSubScrOption_sub_check[(int)&((cSubScrOption *)0)->sub == 0xE0 ? 1 : -1];
typedef char cSubScrOption_row_check[(int)&((cSubScrOption *)0)->row == 0x130 ? 1 : -1];
typedef char cSubScrOption_size_check[sizeof(cSubScrOption) == 0x140 ? 1 : -1];

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

/* Step of cSubScrOption's fade to and from the second display. */
extern unsigned char D_003BD9E8;
/* Step of cSubScrOptionT's fade, the variant's own byte after cSubScrOption's. */
extern unsigned char D_003BD9E9;
/* Cursor y of each row of cSubScrOption's main display. */
extern float D_0041FB70[SUBSCR_OPTION_ROW_NUM];

/* Hide every entry of the main display. */
void func_00167328(cSubScrOption *self);

#endif
