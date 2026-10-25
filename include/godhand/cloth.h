/* include/godhand/cloth.h - the cloth collision spheres.
 *
 * A cloth's spheres keep it off the body: a sphere sits on the bone segment
 * from boneB to boneA at blend (1.0 is on boneA), moved by ofs. The player's
 * costumes fill four tables of them (func_00100FB8). Field names are ours;
 * offsets are exact.
 */
#ifndef GODHAND_CLOTH_H
#define GODHAND_CLOTH_H

#include "godhand/cVec.h"

typedef struct ClothSphere {
    char unk00[2];
    unsigned char boneA;                /* 0x02 */
    unsigned char boneB;                /* 0x03 */
    float blend;                        /* 0x04 */
    float radius;                       /* 0x08 */
    int unk0C;
    cVec ofs;                           /* 0x10 offset from the bone point (w is 1.0) */
    cVec unk20;                         /* 0x20 all but one table entry repeat ofs here */
} ClothSphere;

typedef char ClothSphere_chk_size[sizeof(ClothSphere) == 0x30 ? 1 : -1];

/* The sphere tables of the four costume pairs (0/1, 2/3, 4/5, 6/7). */
extern ClothSphere D_00460E00[12];
extern ClothSphere D_00461040[11];
extern ClothSphere D_00461250[7];
extern ClothSphere D_004613A0[12];

/* memset (assembly). No libc header owns it yet. */
extern void *func_003A52F0(void *dst, int c, int n);

/* The record's constructor: cleared, then the two bones, the blend, the radius,
 * ofs and unk20. A macro for the same reason as CVEC_INIT_XYZ; s is evaluated
 * more than once. */
#define CLOTH_SPHERE_SET(s, a, b, bl, r, fx, fy, fz, ux, uy, uz)  \
    {                                                           \
        func_003A52F0((s), 0, sizeof(ClothSphere));             \
        (s)->boneA = (a);                                       \
        (s)->boneB = (b);                                       \
        (s)->blend = (bl);                                      \
        (s)->radius = (r);                                      \
        CVEC_INIT_XYZ((s)->ofs, fx, fy, fz)                     \
        CVEC_INIT_XYZ((s)->unk20, ux, uy, uz)                   \
    }

#endif /* GODHAND_CLOTH_H */
