/* include/godhand/capVu0.h - the game's small VU0 vector helpers (0x1F7xxx).
 *
 * Each helper is a few VU0 macro instructions on 16-byte vectors; retail
 * calls them out of line. */
#ifndef GODHAND_CAPVU0_H
#define GODHAND_CAPVU0_H

#include "godhand/cOmBase.h"

/* Squared distance between a and b in the ground plane (x and z). */
float capVu0MagnitudeSqXZ(cVec *a, cVec *b);

/* Squared length of v (x, y and z). */
float capVu0LengthSq(void *v);

/* Angle of (x, y) from the x axis, in radians. */
float capVu0Atan2(float y, float x);
/* Sine of x, in radians. */
float capVu0Sin(float x);
/* Cosine of x, in radians. */
float capVu0Cos(float x);
/* dst = mtx applied to v (x, y and z); dst may be v. */
void capVu0ApplyMatrixXYZ(cVec *dst, float *mtx, cVec *v);
/* Arc cosine of x, in radians. */
float capVu0Acos(float x);

#endif
