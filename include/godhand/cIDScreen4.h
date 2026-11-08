/* include/godhand/cIDScreen4.h - a screen made of four cIDBase displays: the
 * main one at 0x000 and three more at 0xE0, 0x190 and 0x210. Setup builds one
 * pointer table of display entries for each of the first three (18, 19 and 12
 * entries), restarts the animation of the main display and of the last one,
 * and stores the game level. Offsets are exact; fields nobody has named stay
 * as unkNN padding. The vtable is D_0041E620 and its setup entry is
 * func_00141B18.
 */
#ifndef GODHAND_CIDSCREEN4_H
#define GODHAND_CIDSCREEN4_H

#include "godhand/cIDBase.h"

#define IDSCREEN4_MAIN_ENT_NUM  0x12    /* entries of the main display */
#define IDSCREEN4_A_ENT_NUM     0x13    /* entries of the display at 0xE0 */
#define IDSCREEN4_B_ENT_NUM     0x0C    /* entries of the display at 0x190 */
#define IDSCREEN4_ENT_F_PULSE   0x400   /* cIDBaseEnt.flags bit set on four main entries at setup */

typedef struct cIDScreen4 {
    cIDBaseObj base;                    /* 0x000 main display */
    char unk48[0x98 - 0x48];
    cIDBaseEnt *mainEnt[IDSCREEN4_MAIN_ENT_NUM];    /* 0x098 */
    cIDBaseObj partA;                   /* 0x0E0 */
    char unk128[0x130 - 0x128];
    cIDBaseEnt *aEnt[IDSCREEN4_A_ENT_NUM];          /* 0x130 */
    short level;                        /* 0x17C game level, from cCoreSave_getGameLevel */
    char unk17E[0x190 - 0x17E];
    cIDBaseObj partB;                   /* 0x190 */
    char unk1D8[0x1E0 - 0x1D8];
    cIDBaseEnt *bEnt[IDSCREEN4_B_ENT_NUM];          /* 0x1E0 */
    cIDBaseObj partC;                   /* 0x210 */
    char unk258[0x26C - 0x258];
    unsigned char unk26C;               /* 0x26C cleared at setup */
    unsigned char unk26D;               /* 0x26D set to 1 at setup */
} cIDScreen4;

#define IDSCREEN4_OFFSET(field) ((int)&((cIDScreen4 *)0)->field)
typedef char cIDScreen4_chk_main[IDSCREEN4_OFFSET(mainEnt) == 0x98 ? 1 : -1];
typedef char cIDScreen4_chk_partA[IDSCREEN4_OFFSET(partA) == 0xE0 ? 1 : -1];
typedef char cIDScreen4_chk_aEnt[IDSCREEN4_OFFSET(aEnt) == 0x130 ? 1 : -1];
typedef char cIDScreen4_chk_level[IDSCREEN4_OFFSET(level) == 0x17C ? 1 : -1];
typedef char cIDScreen4_chk_partB[IDSCREEN4_OFFSET(partB) == 0x190 ? 1 : -1];
typedef char cIDScreen4_chk_bEnt[IDSCREEN4_OFFSET(bEnt) == 0x1E0 ? 1 : -1];
typedef char cIDScreen4_chk_partC[IDSCREEN4_OFFSET(partC) == 0x210 ? 1 : -1];
typedef char cIDScreen4_chk_26C[IDSCREEN4_OFFSET(unk26C) == 0x26C ? 1 : -1];

#endif
