/* include/godhand/cCamera.h - cCamera, the base camera object.
 *
 * A cCamera holds seven 4x4 matrices at 0x000..0x1BF, the eye, target and
 * rotation vectors at 0x200..0x230, two vibration channels at 0x254 and the
 * vtable at 0x35C. The constructor zeroes the vectors and calls reset;
 * reset aims the camera from its default eye at its default target and
 * clears the vibration. move runs the vtable's step, then stepVib, then
 * update. cPlCamera and the other camera classes build on this record.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCAMERA_H
#define GODHAND_CCAMERA_H

#include "godhand/cOmBase.h"

#define CAMERA_MTX_NUM   7
#define CAMERA_VIB_NUM   2

/* One screen-shake channel: it runs while count is non-zero, shrinking amp
 * by decay and advancing the phase by speed each frame. */
typedef struct cCamVib {
    float amp;                          /* 0x00 */
    float speed;                        /* 0x04 phase step per frame */
    float decay;                        /* 0x08 amp multiplier per frame */
    float phase;                        /* 0x0C angle, kept in range by Adjust_theta */
    unsigned char count;                /* 0x10 frames left */
    char unk11[3];
} cCamVib;                              /* 0x14 */

typedef struct cCamera {
    float mtx[CAMERA_MTX_NUM][16];      /* 0x000 */
    int unk1C0;                         /* 0x1C0 cleared by reset */
    char unk1C4[0x3C];
    cVec eye;                           /* 0x200 */
    cVec target;                        /* 0x210 */
    cVec rot;                           /* 0x220 angles from eye to target */
    char unk230[0x10];
    cVec up;                            /* 0x240 */
    float fov;                          /* 0x250 */
    cCamVib vib[CAMERA_VIB_NUM];        /* 0x254 */
    char unk27C[0x35C - 0x27C];
    void *vt;                           /* 0x35C */
} cCamera;

extern float Adjust_theta(float angle);

#endif
