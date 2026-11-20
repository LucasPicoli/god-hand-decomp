/* include/godhand/DispMgr.h - DispMgr, the registry of display sub-records.
 *
 * The game's one DispMgr is at 0x464080; every reader reaches it through the
 * pointer D_003BD6E8. A DispMgr holds eleven sub-records at fixed offsets, then a table of
 * registered objects at 0x22F0 (12 bytes per slot). func_00140BF0 registers
 * a sub-record in the first free slot and DispMgr_reset (src/cod/00140c88.c)
 * walks the table to call every object's reset method.
 *
 * Field names are ours, taken from the functions that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_DISPMGR_H
#define GODHAND_DISPMGR_H

#include "godhand/cIDBase.h"
#include "godhand/cIDBaseScreen.h"
#include "godhand/cCockGetPoint.h"
#include "godhand/cCockItem.h"
#include "godhand/cCockTutorial.h"
#include "godhand/TrackSet.h"

#define DISPMGR_SLOT_NUM  0x11          /* FindFreeSlotIndex_140C58 stops at 0x11 */
#define DISPMGR_SLOT_OFS  0x22F0        /* byte offset of slot[0] */

/* A g++ 2.x vtable entry of a registered sub-record. */
typedef struct DispMgrSubMethod {
    short delta;                        /* added to the object before the call */
    short index;
    void (*pfn)(void *self);
} DispMgrSubMethod;

#define DISPMGR_SUB_HOOK   3            /* vtable entry cCockPlBar_initData calls */

/* The head every registered sub-record shares: its vtable at 0x80. */
typedef struct DispMgrSub {
    char unk00[0x80];
    DispMgrSubMethod *vt;               /* 0x80 */
} DispMgrSub;

typedef struct DispMgrSlot {
    int kind;                           /* 0x0 what the sub-record is, 0 = free is judged on obj */
    void *obj;                          /* 0x4 the registered sub-record, 0 when the slot is free */
    int unk8;
} DispMgrSlot;                          /* 0xC */

/* The player bar (cCockPlBar, registered as kind 3). */
typedef struct cCockPlBar {
    DispMgrSub head;                    /* 0x000 */
    char unk084[0x90 - sizeof(DispMgrSub)];
    unsigned int flags;                 /* 0x090 bit 24 set by cHeatSys_AddHeatGage at 120 heat */
    char unk094[0x280 - 0x94];
} cCockPlBar;                           /* 0x280 */

/* The gold display (registered as kind 17). */
typedef struct DispMgrGold {
    char unk000[0x90];
    int gold;                           /* 0x090 the gold shown */
    cIDBaseEnt *num;                    /* 0x094 the number entry that shows it, 0 before setup */
    char unk098[0x1D0 - 0x98];
} DispMgrGold;                          /* 0x1D0 */

/* The sub-record registered as kind 7 (class not yet known). */
typedef struct DispMgrKind7 {
    char unk00[0x94];
    unsigned char flags;                /* 0x94 func_001F75B0 clears bit 0 */
    char unk95[0xF0 - 0x95];
} DispMgrKind7;                         /* 0xF0 */

typedef struct DispMgr {
    char unk0000[0x3A0];
    char nowLoading[0x460 - 0x3A0];     /* 0x03A0 the loading screen record (cNowLoading_setup) */
    cCockPlBar plBar;                   /* 0x0460 registered as kind 3 */
    char unk06E0[0xEA0 - 0x6E0];
    cIDBaseScreen screen;               /* 0x0EA0 registered as kind 6; the action-button prompts */
    char unk1374[0x1380 - 0xEA0 - sizeof(cIDBaseScreen)];
    DispMgrKind7 kind7;                 /* 0x1380 registered as kind 7 */
    char unk1470[0x15C0 - 0x1470];
    cCockGetPoint getPoint;             /* 0x15C0 registered as kind 9 */
    char unk1904[0x1910 - 0x15C0 - sizeof(cCockGetPoint)];
    cCockItem item;                     /* 0x1910 registered as kind 16 */
    char unk1A18[0x1A20 - 0x1910 - sizeof(cCockItem)];
    cCockTutorial tutorial;             /* 0x1A20 */
    char unk1ADC[0x1AE0 - 0x1A20 - sizeof(cCockTutorial)];
    DispMgrGold gold;                   /* 0x1AE0 */
    char unk1CB0[0x1E90 - 0x1CB0];
    TrackSet track;                     /* 0x1E90 */
    char unk2200[DISPMGR_SLOT_OFS - 0x1E90 - sizeof(TrackSet)];
    DispMgrSlot slot[DISPMGR_SLOT_NUM]; /* 0x22F0 */
    unsigned char ready;                /* 0x23BC cleared by DispMgr_reset */
} DispMgr;                              /* 0x23C0 */

typedef char cCockPlBar_size_check[(sizeof(cCockPlBar) == 0x280) ? 1 : -1];
typedef char DispMgrGold_size_check[(sizeof(DispMgrGold) == 0x1D0) ? 1 : -1];
typedef char DispMgrKind7_size_check[(sizeof(DispMgrKind7) == 0xF0) ? 1 : -1];
typedef char DispMgr_nowLoading_check[((int)&((DispMgr *)0)->nowLoading == 0x3A0) ? 1 : -1];
typedef char DispMgr_plBar_check[((int)&((DispMgr *)0)->plBar == 0x460) ? 1 : -1];
typedef char DispMgr_screen_check[((int)&((DispMgr *)0)->screen == 0xEA0) ? 1 : -1];
typedef char DispMgr_kind7_check[((int)&((DispMgr *)0)->kind7 == 0x1380) ? 1 : -1];
typedef char DispMgr_getPoint_check[((int)&((DispMgr *)0)->getPoint == 0x15C0) ? 1 : -1];
typedef char DispMgr_item_check[((int)&((DispMgr *)0)->item == 0x1910) ? 1 : -1];
typedef char DispMgr_tutorial_check[((int)&((DispMgr *)0)->tutorial == 0x1A20) ? 1 : -1];
typedef char DispMgr_gold_check[((int)&((DispMgr *)0)->gold == 0x1AE0) ? 1 : -1];
typedef char DispMgr_track_check[((int)&((DispMgr *)0)->track == 0x1E90) ? 1 : -1];
typedef char DispMgr_slot_check[((int)&((DispMgr *)0)->slot == DISPMGR_SLOT_OFS) ? 1 : -1];
typedef char DispMgr_ready_check[((int)&((DispMgr *)0)->ready == 0x23BC) ? 1 : -1];
typedef char DispMgr_size_check[(sizeof(DispMgr) == 0x23C0) ? 1 : -1];

/* Clear the slots, register and set up the sub-records, then reset every registered object. */
void DispMgr_reset(DispMgr *self);
/* (assembly; the parameter as its callers pass it) */
void func_00140E58(DispMgr *self);
/* (assembly; the parameter as its callers pass it) */
void func_001410A8(DispMgr *self);
/* Run the player bar's hook method (vtable entry DISPMGR_SUB_HOOK). */
void cCockPlBar_initData(cCockPlBar *self);
/* Show the current gold in the gold display, then reset the gold being added. */
void func_00143A90(DispMgrGold *self);

/* Retail's Cockpit (the name the script table gives this word): a pointer to the DispMgr at 0x464080, which every reader reaches through this word. */
extern DispMgr *D_003BD6E8;

#endif
