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
    char unk5B0[0x5E0 - 0x5B0];
    unsigned short comboSlot;           /* 0x5E0 slot of the combo being run */
    unsigned short comboSet;            /* 0x5E2 combo set */
    unsigned short comboTicks;          /* 0x5E4 cleared when a combo starts */
    unsigned short comboStage;          /* 0x5E6 cleared when a combo starts */
    char unk5E8[0x5F2 - 0x5E8];
    unsigned short unk5F2;              /* 0x5F2 style: func_001269E0 picks each motion's records by it */
    char unk5F4[0x630 - 0x5F4];
    cVec unk630;                        /* 0x630 func_0012A578 scales the player's offset from this point */
    char unk640[0x698 - 0x640];
    cGameObj *sub698;                   /* 0x698 */
    char unk69C[4];
    cGameObj *sub6A0;                   /* 0x6A0 */
    char unk6A4[4];
    cGameObj *sub6A8;                   /* 0x6A8 */
    char unk6AC[0x1603 - 0x6AC];
    char unk1603;                       /* 0x1603 */
    char unk1604[0x1615 - 0x1604];
    signed char comboCount;             /* 0x1615 hits in the current combo */
    short comboTimer;                   /* 0x1616 frames left before the combo ends */
    short unk1618;                      /* 0x1618 */
    char unk161A[0x1660 - 0x161A];
    int unk1660[2];                     /* 0x1660 [0] blend record 0, [1] blend record 1 */
    int moveA;                          /* 0x1668 the move being run (blend record 0) */
    int moveB;                          /* 0x166C blend record 1 */
    int unk1670[2];                     /* 0x1670 */
    int unk1678[2];                     /* 0x1678 */
    short unk1680[2];                   /* 0x1680 */
    char unk1684;                       /* 0x1684 cleared when a motion starts */
} pl00;

typedef char pl00_chk_sub698[((int)&((pl00 *)0)->sub698 == 0x698) ? 1 : -1];
typedef char pl00_chk_sub6A0[((int)&((pl00 *)0)->sub6A0 == 0x6A0) ? 1 : -1];
typedef char pl00_chk_sub6A8[((int)&((pl00 *)0)->sub6A8 == 0x6A8) ? 1 : -1];
typedef char pl00_chk_combo[((int)&((pl00 *)0)->comboCount == 0x1615) ? 1 : -1];
typedef char pl00_chk_timer[((int)&((pl00 *)0)->comboTimer == 0x1616) ? 1 : -1];
typedef char pl00_chk_comboSlot[((int)&((pl00 *)0)->comboSlot == 0x5E0) ? 1 : -1];
typedef char pl00_chk_1684[((int)&((pl00 *)0)->unk1684 == 0x1684) ? 1 : -1];

/* Set blend record 0: moveA and the [0] words of 0x1660, 0x1670, 0x1678, 0x1680. */
void Obj0000_Set_Fields_1668_1660_1670_1678_1680_10A408(pl00 *self, int move, int a2, int a3, int a4, short a5);
/* Set blend record 1: moveB and the [1] words of 0x1660, 0x1670, 0x1678, 0x1680. */
void Obj0000_Set_Fields_166C_1664_1674_167C_Short_1682_10A420(pl00 *self, int move, int a2, int a3, int a4, short a5);
/* Start player motion `motion` for the current style (style 1, no blend, when `now` is set). */
void func_001269E0(pl00 *self, int motion, int now);
/* Start the next combo of the current set (wrapping to set 0, slot 0 past the
 * set's size) and advance the slot; returns the combo id. */
int ComboObj_startNext(pl00 *self);
/* Whether combo set `set` is used up: it is the current set and the slot has
 * reached the set's size. */
int func_0012C000(pl00 *self, unsigned int set);

#endif
