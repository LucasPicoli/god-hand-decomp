/* include/godhand/CustomIDWork.h - one animated on-screen ID element.
 *
 * A CustomIDWork wraps a screen object (obj, 0x04) and animates four of its
 * properties. Each animation has a flag word and its own frame counter:
 *
 *   local position  flags 0x08, frames 0x24/0x26   obj->localPos[2]
 *   offset position flags 0x28, frames 0x44/0x46   obj->offsetPos[2]
 *   colour          flags 0x48, frames 0x58/0x5A   obj->color[4]
 *   scale           flags 0x5C, frames 0x74/0x76   obj->scale[2]
 *
 * Flag bit 0 = running, bit 1 = linear blend, bit 2 = sine blend; the offset
 * animation has two more bits (3 and 4) for the Y axis. A blend runs for
 * `total` frames and clears its flag word when the counter reaches it.
 *
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. Fields nobody has named stay as unkNN padding.
 */
#ifndef GODHAND_CUSTOMIDWORK_H
#define GODHAND_CUSTOMIDWORK_H

#define CIDW_ANIM_ON        0x01
#define CIDW_ANIM_LINEAR    0x02
#define CIDW_ANIM_SINE      0x04
#define CIDW_OFFS_LINEAR_Y  0x08    /* offset animation only: linear on Y */
#define CIDW_OFFS_SINE_Y    0x10    /* offset animation only: sine on Y */
#define CIDW_SINE_PERIOD    0xB4    /* sine phase wraps at 180 */
#define CIDW_DEG_TO_RAD     0.017453292f

#define CIDW_OBJ_HIDE_ALL    0x08000000  /* flags: element and children hidden */
#define CIDW_OBJ_HIDE_CHILD  0x00000008  /* flags: children hidden */
#define CIDW_OBJ_HIDE        0x20000000  /* flags: element hidden */

typedef struct CustomIDObj {
    char unk00[0x2B];
    unsigned char unk2B;
    unsigned int flags;         /* 0x2C CIDW_OBJ_* */
    float offsetPos[2];         /* 0x30 */
    float localPos[2];          /* 0x38 */
    float scale[2];             /* 0x40 */
    char unk48[4];
    unsigned char color[4];     /* 0x4C */
    char unk50[0x34];
    int number;                 /* 0x84 */
    char unk88[8];
    short messNo;               /* 0x90 */
} CustomIDObj;

typedef struct CustomIDWork {
    int unk00;
    CustomIDObj *obj;           /* 0x04 */
    unsigned int localFlags;    /* 0x08 */
    float restPos[2];           /* 0x0C copied from the object on Initialize */
    float localFrom[2];         /* 0x14 */
    float localTo[2];           /* 0x1C */
    unsigned short localTotal;  /* 0x24 */
    unsigned short localCount;  /* 0x26 */
    unsigned int offsFlags;     /* 0x28 */
    float offsFrom[2];          /* 0x2C */
    float offsTo[2];            /* 0x34 */
    float offsAmp[2];           /* 0x3C sine amplitude */
    unsigned short offsTotal;   /* 0x44 */
    unsigned short offsCount;   /* 0x46 */
    unsigned int colorFlags;    /* 0x48 */
    unsigned char restColor[4]; /* 0x4C */
    unsigned char colorFrom[4]; /* 0x50 */
    unsigned char colorTo[4];   /* 0x54 */
    unsigned short colorTotal;  /* 0x58 */
    unsigned short colorCount;  /* 0x5A */
    unsigned int scaleFlags;    /* 0x5C */
    float restScale;            /* 0x60 */
    float scaleX[2];            /* 0x64 from, to */
    float scaleY[2];            /* 0x6C from, to */
    unsigned short scaleTotal;  /* 0x74 */
    unsigned short scaleCount;  /* 0x76 */
    unsigned char unk78;        /* 0x78 */
} CustomIDWork;

#endif
