/* include/godhand/cArea.h - a 3D hit region on the ground plane.
 *
 * cArea is a prism: a height band [y, y + height] over a 2D shape in the
 * XZ plane. `type` picks the shape:
 *   1  quad: four XZ corners, listed in order around the quad
 *   2  circle: centre in corner[0], `radius` is the radius
 * For type 1 the field at 0xC holds the half-width the quad was built from.
 * The class dispatcher cArea_HitCheck_1F83E8 picks the type 1 or type 2 test.
 *
 * Field names are ours, read off func_001F88A8 (the setter) and the hit
 * tests. Offsets are exact. The point tested is a plain float[3] (x, y, z).
 */
#ifndef GODHAND_CAREA_H
#define GODHAND_CAREA_H

#define CAREA_TYPE_QUAD    1
#define CAREA_TYPE_CIRCLE  2

typedef struct cAreaPoint {
    float x;
    float z;
} cAreaPoint;                   /* 0x8 */

typedef struct cArea {
    unsigned char used;         /* 0x00 set to 1 by the setter */
    unsigned char type;         /* 0x01 CAREA_TYPE_* */
    short pad02;                /* 0x02 cleared by the setter */
    float y;                    /* 0x04 bottom of the height band */
    float height;               /* 0x08 band height above y */
    float radius;               /* 0x0C circle radius (type 2); quad half-width (type 1) */
    cAreaPoint corner[4];       /* 0x10 XZ corners; type 2 uses corner[0] as the centre */
} cArea;                        /* 0x30 */

typedef char cArea_size_check[sizeof(cArea) == 0x30 ? 1 : -1];

/* A 4-float vector as VU0 sees it: the hit test passes corners as float[4]. */
typedef struct cAreaVec4 {
    float x, y, z, w;
} cAreaVec4;

#endif
