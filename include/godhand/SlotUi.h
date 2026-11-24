/* include/godhand/SlotUi.h - SlotUi, the slot machine's on-screen panel.
 *
 * SlotUi is a cIDBase whose display entries are CustomIDWork records
 * (0x7C bytes each): ten at 0x50 (the reel and line marks) and two at 0x580
 * (the bet marks). A second cIDBase sits at 0x530. The panel owns a heap node
 * at 0x678. Slot1 and Slot2 call func_001E73C0 to build it and
 * func_001E7368 to release it.
 *
 * Field names are ours, taken from the functions that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SLOTUI_H
#define GODHAND_SLOTUI_H

#include "godhand/cIDBase.h"
#include "godhand/CustomIDWork.h"

#define SLOTUI_MARK_NUM      10         /* entries in mark */
#define SLOTUI_BET_NUM       2          /* entries in bet */
#define SLOTUI_ENTRY_SIZE    0x7C       /* sizeof(CustomIDWork) */

/* The global record at **D_003C2384; only the two words cleared at release are named. */
typedef struct SlotUiHost {
    char unk00[0x88];
    int pickA;                          /* 0x88 */
    int pickB;                          /* 0x8C */
} SlotUiHost;

typedef struct SlotUi {
    cIDBaseObj id;                      /* 0x000 the marks' display */
    char unk048[0x50 - sizeof(cIDBaseObj)];
    CustomIDWork mark[SLOTUI_MARK_NUM]; /* 0x050 the reel and line marks */
    char unk528[0x530 - 0x528];
    cIDBaseObj id2;                     /* 0x530 the bet marks' display */
    char unk578[0x580 - 0x530 - sizeof(cIDBaseObj)];
    CustomIDWork bet[SLOTUI_BET_NUM];   /* 0x580 the bet marks */
    int *node;                          /* 0x678 heap node, 0 when none; word -8 is its heap */
} SlotUi;                               /* 0x67C */

typedef char SlotUi_node_check[((int)&((SlotUi *)0)->node == 0x678) ? 1 : -1];

#endif
