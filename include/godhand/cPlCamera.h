/* include/godhand/cPlCamera.h - cPlCamera, the camera that follows the player.
 *
 * cPlCamera extends cCamera (its constructor runs the cCamera one, then
 * lays its own vtable over 0x35C). The update picks one of two follow
 * routines from the player's camera state word: the normal chase for every
 * state except 4, the lock-on chase for state 4.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CPLCAMERA_H
#define GODHAND_CPLCAMERA_H

#include "godhand/cCamera.h"
#include "godhand/cGameObj.h"

#define PLCAM_STATE_LOCKON   4          /* camState value of the lock-on chase */

/* The part of the player object the camera reads. */
typedef struct cPlCameraTarget {
    char unk000[0x5D8];
    int camState;                       /* 0x5D8 */
} cPlCameraTarget;

/* A camera pose: the object it looks at, an offset in that object's frame,
 * angle offsets and a distance. */
typedef struct cPlCamPose {
    cGameObj *obj;                      /* 0x00 */
    char unk04[0xC];
    cVec ofs;                           /* 0x10 offset in the object's frame */
    cVec rotOfs;                        /* 0x20 x and y are added to the object's rotation */
    float dist;                         /* 0x30 how far behind the eye the target sits */
    char unk34[0xC];
} cPlCamPose;                           /* 0x40 */

struct cPlCamera {
    struct cCamera base;                /* 0x000 */
    char unk360[0x3D0 - sizeof(struct cCamera)];
    cVec up;                            /* 0x3D0 up vector, set to (0, 1, 0) by the follow step */
    char unk3E0[0x3F0 - 0x3E0];
    cPlCamPose pose;                    /* 0x3F0 the pose the set-up reads */
    cPlCamPose nextPose;                /* 0x430 the pose the zoom-out mode switches to */
    cGameObj *target;                   /* 0x470 the object followed */
    char unk474[0x480 - 0x474];
    cVec offset;                        /* 0x480 camera offset in the target's frame */
    cVec rotOfs;                        /* 0x490 x and y added to the target's rotation */
    float swing;                        /* 0x4A0 phase of the bob while the player flies */
    char unk4A4[0x4F0 - 0x4A4];
    int followMode;                     /* 0x4F0 index into the follow routine table */
    char unk4F4[0x500 - 0x4F4];
    cVec goal;                          /* 0x500 position of the target last frame */
    int unk510;                         /* 0x510 cleared by the constructor */
    int unk514;                         /* 0x514 */
    char unk518[4];
    int unk51C;                         /* 0x51C cleared by setCamUpdate */
    int unk520;                         /* 0x520 */
    int unk524;                         /* 0x524 */
    int flags528;                       /* 0x528 */
    int wait;                           /* 0x52C frames to wait before the follow ends */
    char unk530[0x600 - 0x530];
};

/* The type is only ever written `struct cPlCamera`: the constructor function has the same name. */

/* A g++ 2.x pointer to member function: `delta` adjusts `this`; a
 * non-negative `index` selects a virtual table slot (1 based, 8 bytes each,
 * read through the table pointer at this + vo), a negative one holds the
 * function address directly. */
typedef struct cPlCamVtEnt {
    short delta;
    short index;
    void *pfn;
} cPlCamVtEnt;

typedef struct cPlCamPmf {
    short delta;
    short index;
    union {
        void *fn;                       /* index < 0 */
        short vo;                       /* index >= 0: offset of the table pointer */
    } u;
} cPlCamPmf;

#endif
