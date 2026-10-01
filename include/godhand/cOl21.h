/* include/godhand/cOl21.h - a scripted moving collision object (cOl21).
 *
 * cOl21 owns eight collision shapes, one per body part, kept in a handle
 * array at 0x654, plus one extra handle at 0x674. initMove sets up a straight
 * run between two points; the object's position is a pointer at 0xF0.
 *
 * Field offsets are exact: every body that uses this header builds
 * byte-identical to retail. A field nobody has named yet is unkNNN padding.
 */
#ifndef GODHAND_COL21_H
#define GODHAND_COL21_H

#define COL21_SHAPE_NUM 8

/* One collision shape as the collision manager hands it out. */
typedef struct cOl21Shape {
    char unk00[8];
    int flags;                          /* 0x08 bit 0 set while the shape is active */
} cOl21Shape;

typedef struct cOl21 {
    char unk000[0xF0];
    float *pos;                         /* 0x0F0 position (x, y, z) */
    char unkF4[0x514];
    float collRadius;                   /* 0x608 */
    char unk60C[4];
    float start[4];                     /* 0x610 where the run starts */
    float goal[4];                      /* 0x620 */
    float end[4];                       /* 0x630 */
    float dir[4];                       /* 0x640 unit direction on the ground plane, x and z used */
    char unk650[4];
    cOl21Shape *shape[COL21_SHAPE_NUM];  /* 0x654 collision shape handles, 0 when free */
    cOl21Shape *shapeExtra;             /* 0x674 */
} cOl21;

typedef char cOl21_size_check[(sizeof(cOl21) == 0x678) ? 1 : -1];

#endif
