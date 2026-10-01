/* include/godhand/cOmb0.h - cOmb0, a map object with one collision sphere.
 *
 * cOmb0_SetCollision turns the collision flag on and registers a sphere with
 * the solid collision manager (D_00462FC0); cOmb0_ReleaseCollision turns it
 * off and releases the unit. Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_COMB0_H
#define GODHAND_COMB0_H

/* Sphere description handed to cCollisionSolidManage_CreateSphere. */
typedef struct cOmb0Sphere {
    int unk00;
    float radius;               /* 0x04 */
    int unk08;
    float scale;                /* 0x0C */
} cOmb0Sphere;

typedef struct cOmb0 {
    char unk000[0x80];
    float pos[4];               /* 0x80 centre of the sphere */
    char unk090[0x62C - 0x90];
    char collisionOn;           /* 0x62C 1 while the sphere is registered */
} cOmb0;

#endif
