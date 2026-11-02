/* sn-2.95.3-136: func_001617C8, part visibility update: hide the four parts of both sets, show the selected one of each, show parts 12-14 or parts 4-7 depending on system flag 0x400000, then run the base move. */
#include "godhand/cIDBase.h"

typedef struct PartSetObj {
    cIDBaseObj base;                    /* 0x00 */
    char unk48[0x80 - 0x48];
    cIDBaseEnt *part[15];               /* 0x80 */
    signed char sel;                    /* 0xBC */
} PartSetObj;

/* GameWork.flags (gameWork.h declares it as an int) read as an array: retail reaches the
 * system flags word after it (D_00747A28) from this symbol, and as its own symbol the code changes. */
extern int D_00747A24[];

__attribute__((section(".text.func_001617C8")))
void func_001617C8(PartSetObj *o)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        o->part[i]->flags |= IDENT_FLAG_NO_DRAW;
        o->part[i + 8]->flags |= IDENT_FLAG_NO_DRAW;
    }
    o->part[o->sel]->flags &= ~IDENT_FLAG_NO_DRAW;
    o->part[o->sel + 8]->flags &= ~IDENT_FLAG_NO_DRAW;
    if (D_00747A24[1] & 0x400000) {
        o->part[12]->flags |= IDENT_FLAG_NO_DRAW;
        o->part[13]->flags |= IDENT_FLAG_NO_DRAW;
        o->part[14]->flags |= IDENT_FLAG_NO_DRAW;
        o->part[4]->flags &= ~IDENT_FLAG_NO_DRAW;
        o->part[5]->flags &= ~IDENT_FLAG_NO_DRAW;
        o->part[6]->flags &= ~IDENT_FLAG_NO_DRAW;
        o->part[7]->flags &= ~IDENT_FLAG_NO_DRAW;
    } else {
        o->part[12]->flags &= ~IDENT_FLAG_NO_DRAW;
        o->part[13]->flags &= ~IDENT_FLAG_NO_DRAW;
        o->part[14]->flags &= ~IDENT_FLAG_NO_DRAW;
        o->part[4]->flags |= IDENT_FLAG_NO_DRAW;
        o->part[5]->flags |= IDENT_FLAG_NO_DRAW;
        o->part[6]->flags |= IDENT_FLAG_NO_DRAW;
        o->part[7]->flags |= IDENT_FLAG_NO_DRAW;
    }
    cIDBase_move(&o->base);
}
