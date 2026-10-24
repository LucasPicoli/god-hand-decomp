/* include/godhand/pl00.h - pl00, the player object.
 *
 * pl00 derives from cGameObj. Past the base part it keeps the objects that
 * fight beside the player: three of them sit in a row of pointers at 0x698,
 * 0x6A0 and 0x6A8, and the player forwards the state changes that concern
 * them (suspend, for one) through their method table at 0x214.
 *
 * Only the fields the methods drawn so far touch are named. Offsets are
 * exact; a span nobody has named stays unkNNN padding.
 */
#ifndef GODHAND_PL00_H
#define GODHAND_PL00_H

#include "godhand/cGameObj.h"

/* A method table entry of the objects the player forwards to: a g++ 2.x
 * this-adjust, the index, and the function. */
typedef struct pl00VtEnt {
    short delta;
    short index;
    void (*pfn)(void *self, int arg);
} pl00VtEnt;

/* Entry 12 of the table at 0x214 (offset 0x60) is setSuspend. */
#define PL00_VT_SETSUSPEND  12

typedef struct pl00 {
    cGameObj base;
    char unk5AC[0x630 - 0x5AC];
    cVec unk630;                        /* 0x630 func_0012A578 scales the player's offset from this point */
    char unk640[0x698 - 0x640];
    cGameObj *sub698;                   /* 0x698 */
    char unk69C[4];
    cGameObj *sub6A0;                   /* 0x6A0 */
    char unk6A4[4];
    cGameObj *sub6A8;                   /* 0x6A8 */
    char unk6AC[0x1615 - 0x6AC];
    signed char comboCount;             /* 0x1615 hits in the current combo */
    short comboTimer;                   /* 0x1616 frames left before the combo ends */
} pl00;

typedef char pl00_chk_sub698[((int)&((pl00 *)0)->sub698 == 0x698) ? 1 : -1];
typedef char pl00_chk_sub6A0[((int)&((pl00 *)0)->sub6A0 == 0x6A0) ? 1 : -1];
typedef char pl00_chk_sub6A8[((int)&((pl00 *)0)->sub6A8 == 0x6A8) ? 1 : -1];
typedef char pl00_chk_combo[((int)&((pl00 *)0)->comboCount == 0x1615) ? 1 : -1];
typedef char pl00_chk_timer[((int)&((pl00 *)0)->comboTimer == 0x1616) ? 1 : -1];

#endif
