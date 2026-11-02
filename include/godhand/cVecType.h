/* include/godhand/cVecType.h - the four-float vector every record uses,
 * and its two plain helpers. cVec.h has the vector macros. */
#ifndef GODHAND_CVECTYPE_H
#define GODHAND_CVECTYPE_H

/* A position or direction. w is 1.0 for a point and unused for a direction. */
typedef struct cVec {
    float x, y, z, w;
} cVec;

/* Copy x, y and z and leave w alone. Skips the copy when both point at one vector. */
static __inline__ void cVec_copy3(cVec *d, cVec *s) {
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

/* Set all four components. */
static __inline__ void cVec_set4(cVec *v, float x, float y, float z, float w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

#endif
