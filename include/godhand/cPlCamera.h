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

#define PLCAM_STATE_LOCKON   4          /* camState value of the lock-on chase */

/* The part of the player object the camera reads. */
typedef struct cPlCameraTarget {
    char unk000[0x5D8];
    int camState;                       /* 0x5D8 */
} cPlCameraTarget;

typedef struct cPlCamera {
    char unk000[0x4F0];
    int followMode;                     /* 0x4F0 index into the follow routine table */
    char unk4F4[0x600 - 0x4F4];
} cPlCamera;

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
