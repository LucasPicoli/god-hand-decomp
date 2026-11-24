/* include/godhand/cOmb0.h - cOmb0, a map object with one collision sphere.
 *
 * cOmb0_SetCollision turns the collision flag on and registers a sphere, centred
 * 1.75 above the origin of its world matrix, with the solid collision manager
 * (D_00462FC0); cOmb0_ReleaseCollision turns it off and releases the unit.
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_COMB0_H
#define GODHAND_COMB0_H

#include "godhand/cOmBase.h"

/* Its type info names cOmBase as the base class. */
typedef struct cOmb0 {
    cOmBase base;               /* 0x000 */
    char unk5E0[0x62C - 0x5E0];
    char collisionOn;           /* 0x62C 1 while the sphere is registered */
} cOmb0;

#endif
