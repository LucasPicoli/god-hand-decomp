/* include/godhand/pathRec.h - cAreaCamManager and its area records
 * (sn code at 0x137BB8..0x1380A8).
 *
 * The class name is the game's own (SetData__15cAreaCamManagerUi). The record
 * name and the field names are ours; offsets are exact.
 */
#ifndef GODHAND_PATHREC_H
#define GODHAND_PATHREC_H

#include "godhand/cOmBase.h"
#include "godhand/cArea.h"

/* AreaCamRec.kind: how the camera eases toward the record's pose. */
#define AREACAM_KIND_FIXED         0   /* the record's turn and distance, the manager's height */
#define AREACAM_KIND_CURVE         1   /* turn and distance along the record's direction */
#define AREACAM_KIND_FIXED_HEIGHT  2   /* the record's turn, distance and height */

typedef struct AreaCamRec {
    cArea area;                         /* 0x00 the area the record covers */
    float margin;                       /* 0x30 passed to cArea::HitCheck for the active record */
    float rate;                         /* 0x34 easing rate toward this record's camera pose */
    float endDist;                      /* 0x38 camera distance (cPlCamPose.dist) at the record */
    char unk3C[2];
    unsigned char priority;             /* 0x3E where areas overlap, the lowest wins */
    unsigned char kind;                 /* 0x3F AREACAM_KIND_* */
    char unk40[0x10];
    char dir[0xC];                      /* 0x50 direction vector, copied with ofsY as one quadword */
    float ofsY;                         /* 0x5C camera height offset for AREACAM_KIND_FIXED_HEIGHT */
    float coneAngle;                    /* 0x60 also the turn target for kinds 0 and 2 */
    char unk64[0x6C - 0x64];
} AreaCamRec;                           /* 0x6C: cAreaCamManager_selectArea walks the records at a 0x6C stride */

typedef char AreaCamRec_size_check[(sizeof(AreaCamRec) == 0x6C) ? 1 : -1];

typedef struct cAreaCamManager {
    AreaCamRec *recs;                   /* 0x00 the records, 0 when there are none */
    char unk04[8];
    unsigned int recNum;                /* 0x0C */
    float startDist;                    /* 0x10 camera distance with no record active, and at a curve's start */
    float turn;                         /* 0x14 camera turn when no record is active */
    float rate;                         /* 0x18 easing rate when no record is active */
    float ofsY;                         /* 0x1C camera height offset */
    char unk20[0x10];
    AreaCamRec *rec;                    /* 0x30 the active record */
} cAreaCamManager;                      /* 0x34: the camera manager holds one at 0xFF4, before its mode at 0x1028 */

typedef char cAreaCamManager_size_check[(sizeof(cAreaCamManager) == 0x34) ? 1 : -1];

struct cPlCamera;

/* Make the record whose area holds pos the active one; where areas overlap,
 * the lowest priority wins, and the active record's own area is tested with
 * its margin at 0x30. Returns 1 with a record active. With no records it
 * returns 0 and leaves rec as it is; when no area holds pos it clears rec and
 * returns 0. */
int cAreaCamManager_selectArea(cAreaCamManager *self, cVec *pos);

/* Turn angle and camera distance toward the active record (AREACAM_KIND_CURVE). */
void cAreaCamManager_calcTurn(cAreaCamManager *self, float *turn, float *dist, cVec *ref, cVec *target);

/* How far dir lies inside the active record's cone around the turned z axis:
 * 1 on the axis, 0 at the cone edge or outside. */
float func_00137E70(cAreaCamManager *self, cVec *dir, cVec *rot);

/* Pick the path area the player is in and ease the player camera's next pose
 * toward it. */
void cAreaCamManager_easeCamera(cAreaCamManager *self, struct cPlCamera *cam);

#endif /* GODHAND_PATHREC_H */
