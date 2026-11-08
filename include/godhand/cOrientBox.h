/* include/godhand/cOrientBox.h - an oriented box with a cached world-space
 * bounding box (0x12D xxx).
 *
 * The box is a unit cube scaled by `size`, moved by a transform built from
 * the vectors at 0x60..0x90 (or from the matrix at 0x58 when flag bit 2 is
 * set). calc writes the eight transformed corners and then the axis-aligned
 * minimum and maximum over them.
 *
 * Offsets are exact. A field nobody has named yet stays as unkNN padding.
 */
#ifndef GODHAND_CORIENTBOX_H
#define GODHAND_CORIENTBOX_H

#include "godhand/cVecType.h"

#define ORIENTBOX_CORNERS    8
#define ORIENTBOX_F_MTX      0x4        /* flags: the transform comes from the matrix at 0x58 */

typedef struct cOrientBox {
    char unk00[0x8];
    unsigned int flags;                 /* 0x08 */
    char unk0C[4];
    cVec min;                           /* 0x10 axis-aligned minimum of the corners */
    cVec max;                           /* 0x20 axis-aligned maximum */
    char unk30[0x58 - 0x30];
    float *mtx;                         /* 0x58 transform, used when ORIENTBOX_F_MTX is set */
    char unk5C[4];
    cVec trans;                         /* 0x60 */
    cVec rotAdd;                        /* 0x70 */
    cVec rot;                           /* 0x80 */
    cVec rotMtx;                        /* 0x90 */
    float size[3];                      /* 0xA0 scale of the unit cube */
    char unkAC[0x110 - 0xAC];
    cVec corner[ORIENTBOX_CORNERS];     /* 0x110 */
} cOrientBox;

#endif
