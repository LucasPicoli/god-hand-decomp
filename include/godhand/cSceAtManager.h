/* include/godhand/cSceAtManager.h - the attack/hit-box manager and its units.
 *
 * cSceAtManager keeps a list of cSceAtUnit records (one per attack hit box).
 * Its methods look a unit up by a 16-bit id, then act on the unit. The
 * dispatch table D_003C2650 holds one handler per unit type, 8 bytes per
 * entry, the function pointer first.
 *
 * Method names come from the retail symbol table. Field names are ours, taken
 * from the methods that read and write them. Offsets are exact. A field we
 * can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_CSCEATMANAGER_H
#define GODHAND_CSCEATMANAGER_H

#include "godhand/cArea.h"

#define SCEAT_ID_NONE      0xFFFFF   /* "no unit" id in getUnit */
#define SCEAT_ON_RESET     0xFF      /* argument the type handler gets */
#define SCEAT_UNIT_TYPE_MARK  1          /* type of the placed units that carry a spawn record */

typedef struct cSceAtUnit {
    unsigned int link;                  /* 0x00 tagged link to the next unit, see SCEAT_LINK_* */
    char unk04;
    unsigned char state;                /* 0x05 1 = active */
    char unk06[0xA];
    float extent;                       /* 0x10 read by FindEntityAtPosition */
    char unk14[0x20];
    unsigned char flags;                /* 0x34 bit 0: enabled */
    unsigned char type;                 /* 0x35 index into the handler table */
    unsigned short id;                  /* 0x36 */
    char unk38[2];
    char actType;                       /* 0x3A */
    unsigned char hitKind;              /* 0x3B current hit kind */
    int dataC;                          /* 0x3C */
    int data40;                         /* 0x40 */
    char data44;                        /* 0x44 */
    char unk45[9];
    unsigned char prevHitKind;          /* 0x4E hit kind before the last change */
    char unk4F;
    unsigned int frameFlags;            /* 0x50 see SCEAT_FRAME_* */
    char dmgType;                       /* 0x54 */
    char unk55[7];
    float pos[3];                       /* 0x5C world position */
    char unk68[0x11];
    unsigned char spawnIdx;             /* 0x79 index into the spawn table */
    unsigned char spawnOn;              /* 0x7A 1 = unit is placed from the table */
} cSceAtUnit;

typedef struct cSceAtTypeEnt {
    int (*handler)(cSceAtUnit *unit, int arg);    /* 0x0 result unused by callers */
    int unk4;                           /* 0x4 */
} cSceAtTypeEnt;

typedef struct cSceAtManager {
    int enabled;                        /* 0x00 0 = manager not running */
    char unk04[0x58];
    unsigned int unitList;              /* 0x5C head of the tagged unit list */
} cSceAtManager;

#define SCEAT_FLAG_ENABLED  0x1         /* cSceAtUnit.flags */

/* cSceAtUnit.frameFlags, set by func_002C1618 (still asm) as it checks the
 * player against each unit's area. Once a frame func_002C1540 copies
 * SCEAT_FRAME_NOW into SCEAT_FRAME_PREV and clears it and the three bits
 * below. */
#define SCEAT_FRAME_NOW       0x80000000  /* the player is inside the unit's area */
#define SCEAT_FRAME_PREV      0x40000000  /* the player was inside it the frame before */
#define SCEAT_FRAME_TRG       0x08000000  /* inside it when pad trigger bit 0 (trg) fired */
#define SCEAT_FRAME_HANDLED   0x02000000  /* the unit's type handler ran */
/* func_002C1618 adds 0x40 to the handler's event bits when this is set; nothing
 * found sets it, so what it means isn't known yet. */
#define SCEAT_FRAME_UNK26     0x04000000

/* A unit-list word is a tagged link: SCEAT_LIST_END ends the list, the low
 * 31 bits give the address of the next unit, and SCEAT_LINK_UNIT is set on a
 * link that points at a unit. */
#define SCEAT_LIST_END   0xFFFFFFFF
#define SCEAT_LINK_UNIT  0x80000000
#define SCEAT_LINK_ADDR  0x7FFFFFFF

/* getUnitList returns the list head as a unit: the head word sits where a
 * unit keeps its link, so getNextUnit can start from it. getNextUnit's
 * self is unused. */
cSceAtUnit *cSceAtManager_getUnitList(cSceAtManager *self);
cSceAtUnit *cSceAtManager_getNextUnit(cSceAtManager *self, cSceAtUnit *e);

/* The unit with id id, or 0. */
cSceAtUnit *cSceAtManager_getUnit(cSceAtManager *self, int id);

/* Put unit's hit kind back to the one before its last change and clear its
 * data (dataC, data44). self is unused. */
void cSceAtManager_AtDataReset(cSceAtManager *self, cSceAtUnit *unit);

/* Age every unit's frame flags (SCEAT_FRAME_*). */
void func_002C1540(cSceAtManager *self);

/* out = the area of unit e. */
void func_002C1D68(cSceAtManager *self, cArea *out, cSceAtUnit *e);

extern char D_0044C230[];               /* name of the room data's jump point table */

#endif
