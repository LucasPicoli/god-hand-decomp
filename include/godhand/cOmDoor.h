/* include/godhand/cOmDoor.h - cOmDoor, a hinged door map object.
 *
 * cOmDoor builds on the cGameObj record (0x5AC bytes). Its own flag word
 * at 0x620 holds bit 0 (open or opening), bit 1 (locked); the door keeps
 * the heading it was closed at (0x638) and the heading it swings to
 * (0x640), and a collision object at 0x644 while it is solid.
 * setOpen swings the door open in the direction `kind` names, setClose
 * back, setLock locks it.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_COMDOOR_H
#define GODHAND_COMDOOR_H

#include "godhand/cGameObj.h"

#define DOOR_FLAG_OPEN    0x1           /* flags620 */
#define DOOR_FLAG_LOCKED  0x2

/* eDoorOpenKind: which way a door swings. */
#define DOOR_OPEN_NEAR     0
#define DOOR_OPEN_FAR      1

/* Actor ids of the doors that open 90 degrees; every other door opens 100. */
#define DOOR_ACTOR_A   0x314
#define DOOR_ACTOR_B   0x354
#define DOOR_ACTOR_C   0x420
#define DOOR_ANGLE_90  1.5707964f
#define DOOR_ANGLE_100 1.7453293f

typedef struct cOmDoor {
    cGameObj base;                      /* 0x000 */
    char unk5AC[0x620 - 0x5AC];
    unsigned int flags620;              /* 0x620 */
    char unk624[0x638 - 0x624];
    float closedHeading;                /* 0x638 heading while closed */
    char unk63C[4];
    float openHeading;                  /* 0x640 heading when swung open */
    void *collision;                    /* 0x644 solid collision object, 0 once released */
} cOmDoor;

#endif
