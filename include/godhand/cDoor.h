/* include/godhand/cDoor.h - cDoor, the room jump a door or entrance triggers.
 *
 * A cDoor holds where the player lands after a jump (a position and a
 * heading), which jump point it came from, and a cRoomJump table cursor at
 * 0x34 that finds the point in the room's jump table. setCasinoJumpPoint
 * looks one point up and stores it; getJumpData collects the point for a
 * door of a given kind and setDoorJump starts the jump.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CDOOR_H
#define GODHAND_CDOOR_H

#define CDOOR_NO_KIND   0xFF            /* kind byte of a jump with no door */

/* Angles in the jump table are in radians when they fit -PI..PI, else in degrees. */
#define CDOOR_PI        3.1415927f
#define CDOOR_DEG2RAD   0.017453292f

/* The cursor into the room's jump table (function cRoomJump). */
typedef struct cRoomJump {
    int tbl;                            /* 0x00 table address, from D_00747A44 */
} cRoomJump;

/* Where a jump lands: a position, a heading and the jump point it came from. */
typedef struct cDoorPoint {
    float pos[3];                       /* 0x00 */
    float angle;                        /* 0x0C heading in radians */
    unsigned short id;                  /* 0x10 jump point id */
    unsigned char kind;                 /* 0x12 CDOOR_NO_KIND when unset */
    unsigned char arg;                  /* 0x13 */
    int arg2;                           /* 0x14 */
} cDoorPoint;                           /* 0x18 */

typedef struct cDoor {
    int unk00;
    cDoorPoint point[2];                /* 0x04 the door's point, 0x1C the casino point */
    cRoomJump roomJump;                 /* 0x34 */
    char unk38[2];
    unsigned char unk3A;                /* 0x3A set by getJumpData */
} cDoor;

/* One jump point record in the room data (0x14 bytes). Positions are in
 * 1/100 units and the heading in degrees. */
typedef struct cDoorRec {
    short pos[3];                       /* 0x00 */
    short angle;                        /* 0x06 */
    short id;                           /* 0x08 */
    unsigned char kind;                 /* 0x0A */
    char unk0B[9];
} cDoorRec;                             /* 0x14 */

typedef struct cDoorTbl {
    unsigned int num;                   /* 0x00 */
    cDoorRec rec[1];                    /* 0x04 */
} cDoorTbl;

/* The game state block D_007474A0, as far as the jump code reads it. */
typedef struct cDoorWorld {
    char unk000[0x5AC];
    void *pack;                         /* 0x5AC room data pack holding the jump table */
    unsigned short room;                /* 0x5B0 current room id */
} cDoorWorld;

typedef char cDoorPoint_size_check[(sizeof(cDoorPoint) == 0x18) ? 1 : -1];

extern void cRoomJump_setTblAddr(cRoomJump *self, int tbl);

#endif
