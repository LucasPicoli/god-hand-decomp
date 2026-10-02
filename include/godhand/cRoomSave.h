/* include/godhand/cRoomSave.h - the per-room save pages.
 *
 * cRoomSave remembers what the player did in each room: which enemies are
 * dead and which one-shot slots are used. One page (cRoomSaveData, 0x1650
 * bytes) holds one room. Seven pages sit in the save block D_005E9CB8. The
 * object (D_005E8658) points `data` at the page of the current room, or at
 * its own spare page when the room has none in the table D_003C26C0.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CROOMSAVE_H
#define GODHAND_CROOMSAVE_H

#define ROOMSAVE_PAGE_NUM   7
#define ROOMSAVE_EM_NUM     0x40        /* enemy records per page */
#define ROOMSAVE_SLOT_NUM   0x100       /* one-shot slots per page */
#define ROOMSAVE_FREE_NUM   0x10
#define ROOMSAVE_NO_PAGE    0xFFFF      /* table end, and "room has no page" */

/* One remembered enemy. */
typedef struct cRoomSaveEm {
    char unk00[0x13];
    unsigned char id;                   /* 0x13 */
    unsigned char dead;                 /* 0x14 */
    char unk15[3];
} cRoomSaveEm;                          /* 0x18 */

/* One one-shot slot: a 64-bit key, empty while the key is 0. */
typedef struct cRoomSaveSlot {
    long key;                           /* 0x00 */
    unsigned char used;                 /* 0x08 */
    char unk09[7];
} cRoomSaveSlot;                        /* 0x10 */

typedef struct cRoomSaveData {
    char unk00[8];
    unsigned char emNum;                /* 0x08 enemy records in use */
    char unk09[3];
    cRoomSaveEm em[ROOMSAVE_EM_NUM];    /* 0x0C */
    char unk60C[4];
    cRoomSaveSlot slot[ROOMSAVE_SLOT_NUM]; /* 0x610 */
    int freeTbl[ROOMSAVE_FREE_NUM];     /* 0x1610 */
} cRoomSaveData;                        /* 0x1650 */

/* One row of the room table D_003C26C0. */
typedef struct cRoomSaveRow {
    unsigned short room;                /* 0x00 room id, ROOMSAVE_NO_PAGE ends the table */
    unsigned short page;                /* 0x02 page index, ROOMSAVE_NO_PAGE = none */
    char unk04[0x10];
} cRoomSaveRow;                         /* 0x14 */

typedef struct cRoomSave {
    cRoomSaveData *data;                /* 0x0000 page of the current room */
    cRoomSaveData spare;                /* 0x0008 used when the room has no page */
    int page;                           /* 0x1658 page index of the current room */
} cRoomSave;

typedef char cRoomSaveData_size_check[(sizeof(cRoomSaveData) == 0x1650) ? 1 : -1];
typedef char cRoomSave_size_check[(sizeof(cRoomSave) == 0x1660) ? 1 : -1];

#endif
