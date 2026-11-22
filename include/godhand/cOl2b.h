/* include/godhand/cOl2b.h - the cOl2b scripted collision object.
 *
 * cOl2b derives from cOmBase: its constructor (func_0017FB48) calls the
 * cOmBase constructor (InitFields_1B6E90) first, and the factory allocates
 * 0xA30 bytes for it (AllocInitObj17FB48_317960). Like the other cOl
 * objects it keeps the flag words, the part table and the four state bytes
 * of the base record. The object moves three parts between fixed rotations
 * (setInitFix, setOpenFix, setCloseFix write state 0, 1 and 2 and copy a
 * table entry into each part's rot). Only the fields the methods drawn so
 * far touch are named. Offsets are exact; a span nobody has named stays
 * unkNNN padding.
 */
#ifndef GODHAND_COL2B_H
#define GODHAND_COL2B_H

#include "godhand/cOmBase.h"

#define COL2B_OBJ_OPEN       0x10000    /* base.objFlags: the door is open */
#define COL2B_FLAG2_FIXED    0x8        /* base.flags2: position is fixed */
#define COL2B_STATE_INIT     0          /* state at 0xA24 */
#define COL2B_STATE_OPEN     1
#define COL2B_STATE_OPENING  2
#define COL2B_STATE_CLOSE    2
#define COL2B_PART_NUM       3          /* parts the fix routines place */

typedef struct cOl2b {
    cOmBase base;                       /* 0x000 */
    char unk5E0[0xA24 - 0x5E0];
    int state;                          /* 0xA24 */
    unsigned char stateA28;             /* 0xA28 */
    unsigned char stateA29;             /* 0xA29 */
} cOl2b;

typedef char cOl2b_chk_state[((int)&((cOl2b *)0)->state == 0xA24) ? 1 : -1];
typedef char cOl2b_chk_size[(sizeof(cOl2b) == 0xA30) ? 1 : -1];

#endif
