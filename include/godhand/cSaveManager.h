/* include/godhand/cSaveManager.h - cSaveManager, the checkpoint save.
 *
 * A checkpoint is one 0xB0F0-byte snapshot of the live game state: the
 * cCoreSave record (0x14A0 bytes), the seven room pages (0x9C30 bytes at
 * D_005E9CB8) and a 0x20-byte tail block (D_00755880). setCheckPoint takes
 * the snapshot, getCheckPoint puts it back, restores the stage state and
 * moves the player to the saved spot.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CSAVEMANAGER_H
#define GODHAND_CSAVEMANAGER_H

#define SAVEMGR_CORE_SIZE  0x14A0
#define SAVEMGR_ROOM_SIZE  0x9C30
#define SAVEMGR_TAIL_SIZE  0x20

/* The three parts, as types so that a struct assignment copies them with
 * quadword (core), doubleword (room) and unaligned (tail) moves as retail does. */
typedef struct { int q[4]; } cSaveQ16 __attribute__((aligned(16)));
typedef struct { cSaveQ16 m[SAVEMGR_CORE_SIZE / 16]; } cSaveCore;
typedef struct __attribute__((aligned(8))) { int m[SAVEMGR_ROOM_SIZE / 4]; } cSaveRooms;
typedef struct { char m[SAVEMGR_TAIL_SIZE]; } cSaveTail;

/* Two smaller blocks the reload helpers carry across a reload: the combo
 * table (6 sets of 0x24 bytes = 0xD8) and the skill table (0x80 bytes). The
 * attribute sits on the typedef, so the size stays 0xD8 and the copy is
 * quadword moves with a 24 byte tail, as in retail. */
typedef struct { long q[27]; } cSaveComboBlock __attribute__((aligned(16)));
typedef struct { cSaveQ16 m[8]; } cSaveSkillBlock;
typedef struct { char b[8]; } cSave8;                                               /* flags word pair at 0x14 */
typedef struct { unsigned char b[10]; } cSaveReel10 __attribute__((aligned(8)));   /* reelSlot[10] */
typedef struct { short s[5]; } cSaveKills;                                          /* killEmNum[5], allKillEmNum[5] */

/* One checkpoint snapshot. */
typedef struct cSaveSlot {
    cSaveCore core;                     /* 0x0000 */
    cSaveRooms rooms;                   /* 0x14A0 */
    cSaveTail tail;                     /* 0xB0D0 */
} cSaveSlot;

typedef char cSaveSlot_size_check[(sizeof(cSaveSlot) == 0xB0F0) ? 1 : -1];

/* The part of the game state block D_007474A0 that remembers where the
 * player stands. */
typedef struct cSaveWorld {
    char unk000[0x5C0];
    float pos[3];                       /* 0x5C0 */
    char unk5CC[4];
    float angle;                        /* 0x5D0 */
} cSaveWorld;

#endif
