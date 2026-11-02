/* include/godhand/mtx.h - 4x4 matrix helpers.
 *
 * A matrix is 16 floats, row-major: rows 0 to 2 are the scaled axes, row 3
 * the translation. */
#ifndef GODHAND_MTX_H
#define GODHAND_MTX_H

/* mtx = a rotation by angle about y, no translation. */
void MtxInitRotY(float *mtx, float angle);

#endif /* GODHAND_MTX_H */
