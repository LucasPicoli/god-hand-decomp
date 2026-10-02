/* include/godhand/cSpline.h - cSpline, a cubic curve through four points.
 *
 * setBasePoint turns four control points into the four coefficient vectors
 * of the cubic (the basis matrix D_003C3560 applied to each coordinate).
 * getPoint evaluates it at t with Horner's rule, three scale-and-add steps.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CSPLINE_H
#define GODHAND_CSPLINE_H

#include "godhand/cOmBase.h"

typedef struct cSpline {
    cVec coef[4];                       /* 0x00 constant, t, t*t and t*t*t terms */
} cSpline;

typedef char cSpline_size_check[(sizeof(cSpline) == 0x40) ? 1 : -1];

#endif
