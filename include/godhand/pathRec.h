/* include/godhand/pathRec.h - a path record and the object that follows it
 * (PathHost_calcTurn and the cone factor at 0x137E70).
 *
 * Field names are ours; offsets are exact.
 */
#ifndef GODHAND_PATHREC_H
#define GODHAND_PATHREC_H

#include "godhand/cOmBase.h"

typedef struct PathRec {
    char unk00[0x34];
    float rate;                         /* 0x34 easing rate toward this record's camera pose */
    float endY;                         /* 0x38 */
    char unk3C[3];
    unsigned char kind;                 /* 0x3F PATH_KIND_* */
    char unk40[0x10];
    char dir[0xC];                      /* 0x50 direction vector, copied with ofsY as one quadword */
    float ofsY;                         /* 0x5C camera height offset for kind 2 */
    float coneAngle;                    /* 0x60 */
} PathRec;

typedef struct PathHost {
    char unk00[0x10];
    float startY;                       /* 0x10 */
    float turn;                         /* 0x14 camera turn when no record is active */
    float rate;                         /* 0x18 easing rate when no record is active */
    float ofsY;                         /* 0x1C camera height offset */
    char unk20[0x10];
    PathRec *rec;                       /* 0x30 */
} PathHost;

/* Turn angle and height toward the active record (kind 1). */
extern void PathHost_calcTurn(PathHost *self, float *turn, float *height, cVec *ref, cVec *target);

#endif /* GODHAND_PATHREC_H */
