/* include/godhand/cloth.h - the cloth collision spheres.
 *
 * A cloth's spheres keep it off the body: a sphere sits between boneA's point
 * (ofsA through boneA's matrix) and boneB's point (ofsB through boneB's), at
 * blend (1.0 is on boneB's point; func_00106218). The player's
 * costumes fill four tables of them (func_00100FB8). Field names are ours;
 * offsets are exact.
 */
#ifndef GODHAND_CLOTH_H
#define GODHAND_CLOTH_H

#include "godhand/cVec.h"
#include "godhand/criStm.h"          /* memset (func_003A52F0) */

typedef struct ClothSphere {
    unsigned short unk00;               /* 0x00 1: boneA's point only, no blend */
    unsigned char boneA;                /* 0x02 */
    unsigned char boneB;                /* 0x03 */
    float blend;                        /* 0x04 */
    float radius;                       /* 0x08 */
    int unk0C;
    cVec ofsA;                          /* 0x10 offset in boneA's frame (w is 1.0) */
    cVec ofsB;                          /* 0x20 offset in boneB's frame; every table entry repeats ofsA */
} ClothSphere;

typedef char ClothSphere_chk_size[sizeof(ClothSphere) == 0x30 ? 1 : -1];

/* The sphere tables of the four costume pairs (0/1, 2/3, 4/5, 6/7). */
extern ClothSphere D_00460E00[12];
extern ClothSphere D_00461040[11];
extern ClothSphere D_00461250[7];
extern ClothSphere D_004613A0[12];

/* The record's constructor: cleared, then the two bones, the blend, the radius,
 * ofsA and ofsB. A macro because as an inline function the float constants
 * load in another order; s is evaluated more than once. */
#define CLOTH_SPHERE_SET(s, a, b, bl, r, fx, fy, fz, ux, uy, uz)  \
    {                                                           \
        func_003A52F0((s), 0, sizeof(ClothSphere));             \
        (s)->boneA = (a);                                       \
        (s)->boneB = (b);                                       \
        (s)->blend = (bl);                                      \
        (s)->radius = (r);                                      \
        CVEC_INIT_XYZ((s)->ofsA, fx, fy, fz)                    \
        CVEC_INIT_XYZ((s)->ofsB, ux, uy, uz)                    \
    }

#endif /* GODHAND_CLOTH_H */
