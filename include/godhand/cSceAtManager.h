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

#define SCEAT_ID_NONE      0xFFFFF   /* "no unit" id in getUnit */
#define SCEAT_ON_RESET     0xFF      /* argument the type handler gets */
#define SCEAT_UNIT_TYPE_MARK  1          /* type of the placed units that carry a spawn record */

typedef struct cSceAtUnit {
    char unk00[5];
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
    char unk4F[5];
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

#endif
